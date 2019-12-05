#ifndef recherche_H_INCLUDED	
#define recherche_H_INCLUDED
#include "recherche.h"
typedef struct
{
int jour;
int mois;
int annee;
}Date;
typedef struct
{
Date dt_res;
char dep[20];
char dest[20];
char comp[20];
char classe[20];
}Vol;

int tableau_salle_Reserver(Vol tab[50]);
int verifier_resrever(Vol vo);
int tableau_salle_disponible(char salle[100][50] , Date dt_resr , char dep[20] , char dest[20] , char comp[20] , char classe[20]);

#endif
