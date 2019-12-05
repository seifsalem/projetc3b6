#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include "recherche.h"
#include "affiche.h"

void
on_button1l_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int x;	
	GtkWidget *a ,*b,*c ,*window_commun,*window_admin,*window_agent,*window_client;
	char login[20],password[20];
	
	window_commun= lookup_widget(objet_graphique,"window_commun");
	a=lookup_widget(objet_graphique,"entry1l");
	b=lookup_widget(objet_graphique,"entry2l");
	c=lookup_widget(objet_graphique,"label1l");
	strcpy(login,gtk_entry_get_text(GTK_ENTRY(a)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(b)));
	x =verifier(login,password);



	if(x==1){ 
                    window_admin=create_window_admin();
 		    gtk_widget_show (window_admin);
		    gtk_widget_hide(window_commun);
		}	
	
	if(x==2){ 
                    window_agent=create_window_agent();
 		    gtk_widget_show (window_agent);
		    gtk_widget_hide(window_commun);
		}
	if(x==3){ 
                    window_client=create_window_client();
 		    gtk_widget_show (window_client);
		    gtk_widget_hide(window_commun);
		}
	else 
	{ gtk_label_set_text(GTK_LABEL(c),"authentification non validée");}


}


void
on_button2l_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button1r_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_commun,*window_client;
window_commun=create_window_commun();
gtk_widget_show (window_commun);
window_client= lookup_widget(objet_graphique,"window_client");
gtk_widget_hide(window_client);

}


void
on_button2r_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_commun,*window_agent;
window_commun=create_window_commun();
gtk_widget_show (window_commun);
window_agent= lookup_widget(objet_graphique,"window_agent");
gtk_widget_hide(window_agent);


}


void
on_button3r_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_commun,*window_admin;
window_commun=create_window_commun();
gtk_widget_show (window_commun);
window_admin= lookup_widget(objet_graphique,"window_admin");
gtk_widget_hide(window_admin);


}


void
on_buttonc1_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *combobox1;
GtkWidget *combobox2;
GtkWidget *combobox3;
GtkWidget *combobox4;

char dep[20];
char dest[20];
char comp[20];
char classe[20];
char Bloc[50];
char nom_salle[100][50];
Vol tab[50];
Vol vo;
Date dt_resr;
int i,x,p,n,m;
char stringNum[20];
int num=100;

// associé les objets avec des variables
jour=lookup_widget(objet_graphique, "spinbutton1");
mois=lookup_widget(objet_graphique, "spinbutton2");
annee=lookup_widget(objet_graphique, "spinbutton3");

combobox1=lookup_widget(objet_graphique, "combobox1");
combobox2=lookup_widget(objet_graphique, "combobox2");
combobox3=lookup_widget(objet_graphique, "combobox3");
combobox4=lookup_widget(objet_graphique, "combobox4");



// récuperer les valeurs 
dt_resr.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
dt_resr.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
dt_resr.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));


strcpy(dep,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(dest,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
strcpy(comp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));
strcpy(classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));

 m=tableau_salle_Reserver(tab);
 x=verifier_resrever(vo);
 n=tableau_salle_disponible( nom_salle , dt_resr , dep , dest , comp , classe);


//treeview
GtkWidget *window_commun ;
GtkWidget *recherche_vol1 ;
GtkWidget *treeviewvol1;

window_commun=lookup_widget(objet_graphique,"window_commun");
gtk_widget_destroy(window_commun);
recherche_vol1=lookup_widget(objet_graphique,"recherche_vol1");
recherche_vol1=create_recherche_vol1();
gtk_widget_show(recherche_vol1);
treeviewvol1=lookup_widget(recherche_vol1,"treeviewvol1");
afficher(treeviewvol1);


}


void
on_buttonc2_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();

}


void
on_buttonvr1_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_commun,*recherche_vol1;
window_commun=create_window_commun();
gtk_widget_show (window_commun);
recherche_vol1= lookup_widget(objet_graphique,"recherche_vol1");
gtk_widget_hide(recherche_vol1);
}


