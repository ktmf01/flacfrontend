#include <gtk/gtk.h>

typedef struct {
	GtkTreeRowReference *row;
	FILE *fstderr;
	GPid pid;
	guint timeout;
	int output_trimmed;
	int output_done;
	gunichar output_buffer[64];
	char output_buffer_utf8[64];
	int output_buffer_pointer;
	GString output_buffer_string;
} spawn_data;

typedef struct {
	GtkWidget *w_dlg_files;             // Pointer to file chooser dialog box
	GtkTreeView *treeview_files;        // Pointer to treeview object
	GtkListStore *liststore_files;	    // Pointer to liststore
	GtkWidget *w_scl_compression_level;
	GtkTreeIter iter;
	spawn_data process[4];
} app_widgets;

int main(int argc, char *argv[])
{
	GtkBuilder      *builder;
	GtkWidget       *window;
	app_widgets     *widgets = g_slice_new(app_widgets);

	gtk_init(&argc, &argv);

	builder = gtk_builder_new_from_file ("glade/flacfrontend.glade");
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
	// Get pointers to widgets
	widgets->w_dlg_files = GTK_WIDGET(gtk_builder_get_object(builder, "dlg_files"));
	widgets->treeview_files = GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeview_files"));
	widgets->liststore_files = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_STRING);
	gtk_tree_view_set_model(widgets->treeview_files, GTK_TREE_MODEL(widgets->liststore_files));
	
	widgets->w_scl_compression_level = GTK_WIDGET(gtk_builder_get_object(builder, "scl_compression_level"));
	
	
	//renderer = gtk_cell_renderer_text_new();
	//gtk_tree_view_insert_column_with_attributes(widgets->treeview_files, 0, "File",
						    //renderer, NULL);

	//renderer = gtk_cell_renderer_text_new();
	//gtk_tree_view_insert_column_with_attributes(widgets->treeview_files, 1, "Progress",
						    //renderer, NULL);
	
	//widgets->liststore_files = GTK_LIST_STORE(gtk_builder_get_object(builder, "liststore_files"));
	
	//gtk_list_store_append(widgets->liststore_files, &widgets->iter);
	//gtk_list_store_set(widgets->liststore_files, &widgets->iter, 0, "test de lange", 1, "2%", -1);
	//gtk_list_store_append(widgets->liststore_files, &widgets->iter);
	//gtk_list_store_set(widgets->liststore_files, &widgets->iter, 0, "hoi",  1, "3%", -1);

	gtk_builder_connect_signals(builder, widgets);

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();
	g_slice_free(app_widgets, widgets);

	return 0;
}

G_MODULE_EXPORT void on_btn_add_files_clicked(GtkButton *button, app_widgets *widgets)
{
	GSList *filenames;
	
	gtk_widget_show(widgets->w_dlg_files);
	if (gtk_dialog_run(GTK_DIALOG (widgets->w_dlg_files)) == GTK_RESPONSE_OK) {
		filenames = gtk_file_chooser_get_filenames(GTK_FILE_CHOOSER(widgets->w_dlg_files));
		for (; filenames; filenames = filenames->next){
			gtk_list_store_append(widgets->liststore_files, &widgets->iter);
			gtk_list_store_set(widgets->liststore_files, &widgets->iter, 0, filenames->data, -1);
		}
	  g_slist_free (filenames);
	  }
	gtk_widget_hide(widgets->w_dlg_files);
}

G_MODULE_EXPORT void on_btn_clear_files_clicked(GtkButton *button, app_widgets *widgets)
{
	gtk_list_store_clear(widgets->liststore_files);
}

G_MODULE_EXPORT void on_btn_remove_files_clicked(GtkButton *button, app_widgets *widgets)
{
//	GtkTreeIter iter1, iter2;
	
//	gtk_tree_model_get_iter_first(widgets->liststore_files, widgets->iter);
//	if(gtk_tree_selection_get_selected_rows)
}

G_MODULE_EXPORT void on_btn_encode_clicked(GtkButton *button, app_widgets *widgets)
{
//	gboolean result;
	gchar *standard_out;
	gchar *standard_err;
	gint exit_state;
	GError *err;

	g_spawn_command_line_sync(
						   "flac",
						   &standard_out,
						   &standard_err,
						   &exit_state,
						   &err);
}
/*
int process_stderr_old(spawn_data *data, char *output){
	char ignore[1024];
	int input, counter = 0, skiplines = 6, countlines = 0, backspacefound = 0;
	FILE *ferr=NULL;

//	ferr = fdopen(data->err, "r");

	if(!data->output_trimmed){
		for(countlines = 0; countlines < skiplines; countlines++)
			fgets(ignore, sizeof(ignore), ferr);

		while((input = fgetc(ferr)) > 0 && counter < 254){
			if(input == '\n'){
				data->output_done = 1;
				break;
			}else if(input == '\b')
				if(backspacefound){
					if(counter > 0)
						counter--;
				}else{
					// Emtpy buffer up until this point
					backspacefound = 1;
					for(int i = 0; i < 255; i++)
						output[i] = 0;
					counter = 0;
				}
					
			else{
				output[counter] = input;
				counter++;
			}
		}

		// If we haven't found a backspace up until this point, 
		// strip the filename
		if(!backspacefound){
			int i,j;
			for(i = 255; i > -1; i--)
				if(output[i] == ':')
					break;
			
			// Found a :, now remove front part
			for(j = 0; j < i; j++)
				output[j] = output[i+j];
			for(; j < 255; j++)
				output[j] = 0;
		}
		data->output_trimmed = 1;
	}else if(!data->output_done){
		while((input = fgetc(ferr)) > 0 && counter < 254){
			if(input == '\n'){
				data->output_done = 1;
				break;
			}else if(input == '\b'){
				if(counter > 0)
					counter--;		
			}else{
				output[counter] = input;
				counter++;
			}
		}		
	}
	
	if(counter < 5)
		return 0;
	else
		return 1;
}

void process_stderr(spawn_data *data){
	char c;
	char temp[64]; 
	int i = 0;

	while((c = fgetc(data->fstderr)) != EOF && i < 2000){
		if(c == '\b'){
			data->output_buffer_pointer--;
		}else if(c > 32 && c < 128){
			data->output_buffer[data->output_buffer_pointer] = c;
			data->output_buffer_pointer++;
		}	
		if(data->output_buffer_pointer < 0)
			data->output_buffer_pointer += 64;
		else if(data->output_buffer_pointer > 63)
			data->output_buffer_pointer -= 64;
		i++;
	}
	
	// Copy data up until pointer to temp
	for(i = 0; i < data->output_buffer_pointer; i++)
		temp[i] = data->output_buffer[i];
	for(i = 0; i < 64 - data->output_buffer_pointer; i++)
		data->output_buffer[i] = data->output_buffer[i+data->output_buffer_pointer];
	for(; i < 64; i++)	
		data->output_buffer[i] = temp[64-i+data->output_buffer_pointer];
	data->output_buffer_pointer = 0;
}*/

void write_progress_to_treeview(spawn_data *data){
	GtkTreeModel *treemodel = gtk_tree_row_reference_get_model(data->row);
	GtkTreePath *treepath = gtk_tree_row_reference_get_path (data->row);
	GtkTreeIter iter;

	gtk_tree_model_get_iter(treemodel,&iter,treepath);
	gtk_list_store_set(GTK_LIST_STORE(treemodel),&iter,1,data->output_buffer_string.str,-1);
	fprintf(stderr,"OUTPUT: %s\n",data->output_buffer_string.str);
}

gboolean cb_err_watch_old(GIOChannel *channel, GIOCondition  cond, spawn_data *data ){
	gunichar c;
	gunichar temp[64]; 
	int i = 0, j;
    if( cond != G_IO_IN )
    {
        g_io_channel_unref( channel );
        return FALSE;
    }

	while(g_io_channel_read_unichar(channel, &c, NULL) == G_IO_STATUS_NORMAL && i < 200){
		if(c == '\b'){
			data->output_buffer_pointer--;
		}else if(c > 32 && c < 128){
			data->output_buffer[data->output_buffer_pointer] = c;
			data->output_buffer_pointer++;
		}	
		if(data->output_buffer_pointer < 0)
			data->output_buffer_pointer += 64;
		else if(data->output_buffer_pointer > 63)
			data->output_buffer_pointer -= 64;
		i++;
	}
	
	// Reorder data so last recorded gunichar is at data->output_buffer[63]
	for(i = 0; i < data->output_buffer_pointer; i++)
		temp[i] = data->output_buffer[i];
	for(i = 0; i < 64 - data->output_buffer_pointer; i++)
		data->output_buffer[i] = data->output_buffer[i+data->output_buffer_pointer];
	for(; i < 64; i++)	
		data->output_buffer[i] = temp[64-i+data->output_buffer_pointer];
	data->output_buffer_pointer = 0;
	
	
	// Reset first 8 characters of data->output_buffer_utf8
	for(i=0; i <8; i++)
		data->output_buffer_utf8[i] = ' ';
	
	// Convert data to UTF-8
	for(i=63, j=64; i >= 0; i--){
		j -= g_unichar_to_utf8(data->output_buffer[i],NULL);
		if(j < 0)
			break;
		g_unichar_to_utf8(data->output_buffer[i], data->output_buffer_utf8+j);
	}
	
	write_progress_to_treeview(data);
	
	return TRUE;
}

gboolean cb_err_watch_old2(GIOChannel *channel, GIOCondition  cond, spawn_data *data ){

    if( cond != G_IO_IN )
    {
        g_io_channel_unref( channel );
        return FALSE;
    }
	g_io_channel_seek_position(channel, 0, G_SEEK_END, NULL);
	g_io_channel_seek_position(channel, -30, G_SEEK_END, NULL);
	g_io_channel_read_chars(channel, data->output_buffer_utf8,64,NULL,NULL);
	
	write_progress_to_treeview(data);
	
	return TRUE;
}

gboolean cb_err_watch(GIOChannel *channel, GIOCondition  cond, spawn_data *data ){
	gunichar c;
    if( cond != G_IO_IN )
    {
        g_io_channel_unref( channel );
        return FALSE;
    }

	while(g_io_channel_read_unichar(channel, &c, NULL) == G_IO_STATUS_NORMAL){
		if(c == '\b'){			
			g_string_truncate(&data->output_buffer_string,0);
		}else
			g_string_append_unichar(&data->output_buffer_string, c);
	}
	
	// Leave last 48 characters
	//g_string_erase(&data->output_buffer_string,0,data->output_buffer_string.len-48);
	// Check for halfway cut UTF-8
	//if((data->output_buffer_string.str[0] & 0b11000000) == 0b10000000)
	//	g_string_erase(&data->output_buffer_string,0,1);

	
	write_progress_to_treeview(data);
	
	return TRUE;
}

void callback_child_exit( GPid  pid, gint status, spawn_data *data ){
	write_progress_to_treeview(data);


//    g_source_remove(data->timeout);
//    fclose(data->fstderr);
    /* Close pid */
    g_spawn_close_pid( pid );
}

void spawn_process(spawn_data *data, gchar *command, gchar *mode){
	GtkTreeModel *treemodel = gtk_tree_row_reference_get_model(data->row);
	GtkTreePath *treepath = gtk_tree_row_reference_get_path (data->row);
	GtkTreeIter iter;
	gint fd_stderr;
	GIOChannel *err_ch;
	GValue value = G_VALUE_INIT;

	if(gtk_tree_model_get_iter(treemodel,&iter,treepath)){
		gtk_tree_model_get_value(treemodel,&iter,0,&value);

		// Find the current row


		{
			gchar *launch[] = {command, mode, g_value_dup_string(&value), NULL};

			if(!g_spawn_async_with_pipes(NULL,
								   launch,
								   NULL,
								   G_SPAWN_DO_NOT_REAP_CHILD, NULL,
								   NULL, &data->pid, NULL, NULL, &fd_stderr, NULL )){
				gtk_list_store_set(GTK_LIST_STORE(treemodel),&iter,1,"Fail",-1);
			}else{
				//data->fstderr = fdopen(fd_stderr,"r");
				gtk_list_store_set(GTK_LIST_STORE(treemodel),&iter,1,"Started",-1);
				g_child_watch_add(data->pid, (GChildWatchFunc)callback_child_exit, data );
				//data->timeout = g_timeout_add(500,(GSourceFunc)callback_child_500ms, data);
				#ifdef G_OS_WIN32
					err_ch = g_io_channel_win32_new_fd( fd_stderr );
				#else
					err_ch = g_io_channel_unix_new( fd_stderr );
				#endif
				g_io_add_watch( err_ch, G_IO_IN | G_IO_HUP, (GIOFunc)cb_err_watch, data );
			}
		}
	}
}

G_MODULE_EXPORT void on_btn_test_clicked(GtkButton *button, app_widgets *widgets)
{
//	gboolean result;
	GtkTreePath *path;
	GtkTreeRowReference *rowreference;


	path = gtk_tree_path_new_first();
	rowreference = gtk_tree_row_reference_new(GTK_TREE_MODEL(widgets->liststore_files),path);
	if(rowreference != NULL){
		widgets->process[0].row = rowreference;
		widgets->process[0].output_trimmed = 0;
		widgets->process[0].output_done = 0;
		spawn_process(&widgets->process[0],"flac","-t");
		
	}
}


// called when window is closed
G_MODULE_EXPORT void on_window_main_destroy()
{
	gtk_main_quit();
}
