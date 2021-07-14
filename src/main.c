#include <gtk/gtk.h>

typedef struct {
	GtkTreeRowReference *row;
	gint err;
	GPid pid;
	guint timeout;
	int output_trimmed;
	int output_done;
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

int process_stderr(spawn_data *data, char *output){
	char ignore[1024];
	int input, counter = 0, skiplines = 6, countlines = 0, backspacefound = 0;
	FILE *ferr=NULL;

	ferr = fdopen(data->err, "r");

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
	
	fclose(ferr);
	if(counter < 5)
		return 0;
	else
		return 1;
}

gboolean callback_child_500ms(spawn_data *data){
	GtkTreeModel *treemodel = gtk_tree_row_reference_get_model(data->row);
	GtkTreePath *treepath = gtk_tree_row_reference_get_path (data->row);
	GtkTreeIter iter;
	char buff[255] = {0};

	if(process_stderr(data, buff)){
		gtk_tree_model_get_iter(treemodel,&iter,treepath);
		gtk_list_store_set(GTK_LIST_STORE(treemodel),&iter,1,buff,-1);
	}else{
		buff[0] =  (rand() % 20)+66;
		buff[1] =  (rand() % 20)+66;
		buff[2] =  (rand() % 20)+66;
		gtk_tree_model_get_iter(treemodel,&iter,treepath);
		gtk_list_store_set(GTK_LIST_STORE(treemodel),&iter,1,buff,-1);
	}
	
	return G_SOURCE_CONTINUE;
}

void callback_child_exit( GPid  pid, gint status, spawn_data *data ){
	GtkTreeModel *treemodel = gtk_tree_row_reference_get_model(data->row);
	GtkTreePath *treepath = gtk_tree_row_reference_get_path (data->row);
	GtkTreeIter iter;
	char buff[255] = {0};

	if(process_stderr(data, buff)){
		gtk_tree_model_get_iter(treemodel,&iter,treepath);
		gtk_list_store_set(GTK_LIST_STORE(treemodel),&iter,1,buff,-1);
	}

    g_source_remove(data->timeout);
    /* Close pid */
    g_spawn_close_pid( pid );
}

void spawn_process(spawn_data *data, gchar *command, gchar *mode){
	GtkTreeModel *treemodel = gtk_tree_row_reference_get_model(data->row);
	GtkTreePath *treepath = gtk_tree_row_reference_get_path (data->row);
	GtkTreeIter iter;
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
								   NULL, &data->pid, NULL, NULL, &data->err, NULL )){
				gtk_list_store_set(GTK_LIST_STORE(treemodel),&iter,1,"Fail",-1);
			}else{
				gtk_list_store_set(GTK_LIST_STORE(treemodel),&iter,1,"Started",-1);
				g_child_watch_add(data->pid, (GChildWatchFunc)callback_child_exit, data );
				data->timeout = g_timeout_add(1000,(GSourceFunc)callback_child_500ms, data);
			}
		}
	}else{
		abort();
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
