#include <stdlib.h>
#include <stdio.h>  
#include <string.h>

typedef struct
{
    int ID;
    float note;
}eleve_typ;
    
typedef char *String ;

void virgule_vers_point(String note_lu)
{
      char* ptr; 
        if(strchr(note_lu,',')!=0)
    {
        ptr=strchr(note_lu,',');
        char Chaine[100];
        strcpy(Chaine,".");
        strcat(Chaine,(ptr+1));
        strcpy(&note_lu[strlen(note_lu)-strlen(ptr)],Chaine);         //Ici on remplace les , par des .
    }

}

    
void lire_fichier (char* chemin_fichier){
    
    eleve_typ *eleve;
    eleve = (eleve_typ*)malloc(40 * sizeof(*eleve));

    int dfsid;
    int cpt;
    // cpt=0;
    //while(cpt<40)
    //{
        // printf("i: %d ",cpt);
        // fflush(stdout);
        // eleve[cpt].ID=0;
        // eleve[cpt].note=0;
        // cpt++;
    //}

     // for(int cpt=0;cpt<40;cpt++)
    //{
        //printf("i: %d ",y);
        //fflush(stdout);
        //eleve[y].ID=0;
        //eleve[y].note=0;
    //}
    

    FILE* fichier = NULL;//pointeur de fichier pour utiliser les fonction associé
    char mot_lu[700]="";
    char ID_lu[700]="";
    String note_lu;
    int nb_eleve=0;


    fichier = fopen(chemin_fichier, "r");//ouvre le fichier ne mode read
    if(fichier==NULL){    
        printf("erreur ouverture pdf");
    }


    for(;strcmp(mot_lu,"22212673")!=0;fscanf(fichier,"%s",&mot_lu))
    {
        

        //printf("%s  ",mot_lu);
        //fflush(stdout);
    }
    char jsp[100];
                printf("la");
        fflush(stdout);
    fscanf(fichier,"%s",&jsp);
                printf("la");
        fflush(stdout);
        virgule_vers_point(jsp);
    eleve[nb_eleve].ID=atoi("22212673");
    eleve[nb_eleve].note=atof(jsp);
                printf("la");
        fflush(stdout);


    //printf("taille test: %s",note_lu);


printf("\nlecture fichier\n");

//printf("%d %f\n", eleve[nb_eleve].ID, eleve[nb_eleve].note);

    for(nb_eleve=1;strcmp(ID_lu,"MOYENNE")!=0;fscanf(fichier,"%s",&ID_lu))
    
    {
        if(strlen(ID_lu)==8)
        {
        fscanf(fichier,"%s",note_lu);


        virgule_vers_point(note_lu);

        eleve[nb_eleve].ID=atoi(ID_lu);
        eleve[nb_eleve].note=atof(note_lu);

        if(strcmp(note_lu,"Validé")==0  || strcmp(note_lu,"DISPENSE")==0 )
        {
            fscanf(fichier,"%*s",note_lu);
            eleve[nb_eleve].note=-1;
        }
         //printf("%d %f\n", eleve[nb_eleve].ID, eleve[nb_eleve].note);

        nb_eleve++;
        }
    }

/*
        for(nb_eleve=1;strcmp(ID_lu,"MOYENNE")!=0;fscanf(fichier,"%s %s\n",&ID_lu,&note_lu))
    {
        printf("%s %s\n",ID_lu,note_lu);

        eleve[nb_eleve].ID=atoi(ID_lu);
        eleve[nb_eleve].note=atof(note_lu);

        if(strcmp(note_lu,"Validé")==0)
        {
            fscanf(fichier,"%*s",note_lu);
            eleve[nb_eleve].note=-1;
        }
        

        nb_eleve++;
 
        fflush(stdout);
    }
    */

    fclose(fichier);//fermeture du fichier

 printf("\n");

for(int i=0;i<nb_eleve;i++)
{
 printf("%d %f\n", eleve[i].ID, eleve[i].note);

}

free(eleve);
}

void main (){

/*lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELUMC5A2_EPS_Etudiants.txt");
lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELUMC5A3_SHS_CC1_E.BABOURAM_Etudiants.txt");
lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELURO5C3_OMI_GRAPHES_CC1_F.BANNAY_M.-C.LAGASQUIE_V1_Etudiants_.txt");
lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELURO5C3_OMI_GRAPHES_CC2_F.BANNAY_M.-C.LAGASQUIE_V1_Etudiants_.txt");*/
lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELURO5C3_OMI_UML_CC1_C.CHAUDET_V1_Etudiants.txt");
lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELURO5C4_PROG._ORIENTEE_OBJET_CC1_M.-C.LAGASQUIE_Etudiants.txt");

}