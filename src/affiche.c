#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affiche.h"
#include <gtk/gtk.h>
enum { ENTRY1,
       ENTRY2,
       ENTRY3,
       ENTRY4,
       ENTRY5,
       ENTRY6,
       ENTRY7,
       COLUMNS
      };
void afficher(GtkWidget *liste)
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

	int entry1;
	int entry2;
	int entry3;
	char entry4[20];
	char entry5[20];
	char entry6[20];
	char entry7[20];
   store=NULL;

   FILE *h;
   store = gtk_tree_view_get_model(liste);
   if (store==NULL)


	renderer = gtk_cell_renderer_text_new ();  
	column = gtk_tree_view_column_new_with_attributes(" jour", renderer, "text",ENTRY1, NULL); 
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" mois", renderer, "text",ENTRY2, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column); 

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" annee", renderer, "text",ENTRY3, NULL); 
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" depart", renderer, "text",ENTRY4, NULL); 
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" destination", renderer, "text",ENTRY5, NULL); 
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" compagnie", renderer, "text",ENTRY6, NULL); 
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
        renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" classe", renderer, "text",ENTRY7, NULL); 
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


store=gtk_list_store_new (COLUMNS, G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);

  h = fopen("/home/seif/Projects/project2/src/resultat.txt", "r"); 

  if(h==NULL)
  {
    return;
  }
  else

  { h = fopen("/home/seif/Projects/project2/src/resultat.txt", "a+");
  while((fscanf(h,"%d %d %d %s %s %s %s\n",&entry1,&entry2,&entry3,entry4,entry5,entry6,entry7)!= EOF))
    {
  gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter, ENTRY1, entry1, ENTRY2, entry2, ENTRY3, entry3,ENTRY4, entry4,ENTRY5, entry5,ENTRY6, entry6,ENTRY7, entry7,  -1);
    }
    fclose(h);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }


}

