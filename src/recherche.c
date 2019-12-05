#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recherche.h"

int tableau_salle_Reserver(Vol tab[50])
{
int i, n=0;
FILE* f=fopen("/home/seif/Projects/project2/src/volsReserve.txt","r");
if(f!=NULL)
{
  while(fscanf(f,"%d %d %d %s %s %s %s",&tab[n].dt_res.jour,&tab[n].dt_res.mois,&tab[n].dt_res.annee,tab[n].dep,tab[n].dest,tab[n].comp,tab[n].classe)!=EOF)
{
n++;
}
fclose(f);

}
printf("affichage fil fonction one\n");
for(i=0;i<n;i++)
{
printf("%d %d %d %s %s %s %s\n",tab[i].dt_res.jour,tab[i].dt_res.mois,tab[i].dt_res.annee,tab[i].dep,tab[i].dest,tab[i].comp,tab[i].classe);
}

return n;
}
int verifier_resrever(Vol vo)
{
Vol a;
int v=0; // salle non reserver
FILE* f=fopen("/home/seif/Projects/project2/src/volsReserve.txt","r");
if(f!=NULL)
{
	while(!v && fscanf(f,"%d %d %d %s %s %s %s",&a.dt_res.jour,&a.dt_res.mois,&a.dt_res.annee,a.dep,a.dest,a.comp,a.classe)!=EOF)
	{


		if(strcmp(a.dep,vo.dep)==0 ) 
		{
			if ((a.dt_res.jour==vo.dt_res.jour) && (a.dt_res.mois==vo.dt_res.mois) && (a.dt_res.annee==vo.dt_res.annee) && (strcmp(a.dest,vo.dest)==0 ) && (strcmp(a.comp,vo.comp)==0 ) && (strcmp(a.classe,vo.classe)==0 ) )
					{
						v=1;
					}	
	}

}

fclose(f);
}
return v;
}



int tableau_salle_disponible(char salle[100][50] , Date dt_resr , char dep[20] , char dest[20] , char comp[20] , char classe[20])
{
int a,b,c,i,nS=0;
char x[20];
char y[20];
char z[20];
char t[20];
FILE* f=fopen("/home/seif/Projects/project2/src/vol.txt","r");
Vol v;
a=dt_resr.jour;
b=dt_resr.mois;
c=dt_resr.annee;
strcpy(x,dep);
strcpy(y,dest);
strcpy(z,comp);
strcpy(t,classe);
if(f!=NULL)
{FILE *l;
l = fopen("/home/seif/Projects/project2/src/resultat.txt","w");
if(l!=NULL){
	while(fscanf(f,"%d %d %d %s %s %s %s",&v.dt_res.jour,&v.dt_res.mois,&v.dt_res.annee,v.dep,v.dest,v.comp,v.classe)!=EOF)
	{

		if((strcmp(v.dep,x)==0) && (strcmp(v.dest,y)==0) && (strcmp(v.comp,z)==0) && (strcmp(v.classe,t)==0) && (v.dt_res.jour==a) && (v.dt_res.mois==b) && (v.dt_res.annee==c) )
		{
		    if  ( verifier_resrever(v)==0)
				{
	
		
		fprintf(l,"%d %d %d %s %s %s %s\n",v.dt_res.jour,v.dt_res.mois,v.dt_res.annee,v.dep,v.dest,v.comp,v.classe);
		
	

					strcpy(salle[nS],v.dep);
					nS++;
				}
		}
	}
}
fclose(l);
fclose(f);
}
//affichage/
printf("affichage fil fonction two\n");
for(i=0;i<nS;i++)
{
printf("%s\n",salle[i]);
}
return nS;
}

