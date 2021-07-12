#include <gtk/gtk.h>

typedef struct {
    GtkWidget *w_dlg_files;             // Pointer to file chooser dialog box
    GtkTreeView *treeview_files;        // Pointer to treeview object
    GtkListStore *liststore_files;	    // Pointer to liststore
    GtkWidget *w_scl_compression_level;
    GtkTreeIter iter;
    gchar *stderr1;
    gchar *stderr2;
    gchar *stderr3;
    gchar *stderr4;
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

void on_btn_add_files_clicked(GtkButton *button, app_widgets *widgets)
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

void on_btn_clear_files_clicked(GtkButton *button, app_widgets *widgets)
{
	gtk_list_store_clear(widgets->liststore_files);
}

void on_btn_remove_files_clicked(GtkButton *button, app_widgets *widgets)
{
	GtkTreeIter iter1, iter2;
	
	gtk_tree_model_get_iter_first(widgets->liststore_files, widgets->iter);
	if(gtk_tree_selection_get_selected_rows)
}

void on_btn_encode_clicked()
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

void on_btn_test_clicked()
{
//	gboolean result;
    gchar *standard_out;
    gint exit_state;
    GError *err;
    
    g_spawn_async(
                           "flac",
                           &standard_out,
                           &widgets->stderr1,
                           &exit_state,
                           &err);
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
