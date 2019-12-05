#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <gtk/gtk.h>
//login
int verifier(char login[],char password[])
{
	FILE *f;
	f=fopen("/home/seif/Projects/project2/src/users.txt","r");
	char login1[20],password1[20];
	int r ;
	while(fscanf(f,"%s %s %d", login1, password1 ,&r)!=EOF){
		if (strcmp(login1,login)==0 && strcmp(password1,password)==0)
		{
			fclose(f);			return r;
		}
	}
	fclose(f);
	return(0);
}

