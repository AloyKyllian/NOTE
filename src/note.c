#include <stdlib.h>
#include <stdio.h>  
#include <string.h>

typedef char *String ;

typedef struct
{
    int ID;
    float note;
}eleve_typ;
    

typedef struct
{
    eleve_typ *eleve;
    char controle[9];
    char nom[20];
}matiere_typ;



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

    
matiere_typ lire_fichier (char* chemin_fichier){
    matiere_typ matiere;
    strcpy(matiere.controle,"rien");
    //eleve_typ *eleve;
    matiere.eleve = (eleve_typ*)malloc(40 * sizeof(eleve_typ));

    FILE* fichier = NULL;//pointeur de fichier pour utiliser les fonction associé
    char mot_lu[700]="";
    char ID_lu[700]="";
    char note_lu[100]="";
    int nb_eleve=0;


    fichier = fopen(chemin_fichier, "r");//ouvre le fichier ne mode read
    if(fichier==NULL){    
        printf("erreur ouverture pdf");
    }


    for(int cot=0;strcmp(mot_lu,"22212673")!=0;fscanf(fichier,"%s",&mot_lu))
    {

        if(strncmp(mot_lu,"ELU",3)==0)
        {
        strcpy(matiere.nom,mot_lu);
        }        
        else if(strncmp(mot_lu,"CC",2)==0)
        {

        //fflush(stdout);
         strcpy(matiere.controle,mot_lu);
         }    
        // printf("mot : %s\n",mot_lu);
        // fflush(stdout);

    }


    fscanf(fichier,"%s",note_lu);


    virgule_vers_point(note_lu);

    matiere.eleve[nb_eleve].ID=atoi("22212673");
    matiere.eleve[nb_eleve].note=atof(note_lu);


printf("\nlecture fichier\n");

    for(nb_eleve=1;strcmp(ID_lu,"MOYENNE")!=0;fscanf(fichier,"%s",&ID_lu))
    
    {
        if(strlen(ID_lu)==8)
        {
        fscanf(fichier,"%s",note_lu);


        virgule_vers_point(note_lu);

        matiere.eleve[nb_eleve].ID=atoi(ID_lu);
        matiere.eleve[nb_eleve].note=atof(note_lu);

        if(strcmp(note_lu,"Validé")==0  || strcmp(note_lu,"DISPENSE")==0 )
        {
            fscanf(fichier,"%*s",note_lu);
            matiere.eleve[nb_eleve].note=-1;
        }

        nb_eleve++;
        }
    }

    fclose(fichier);//fermeture du fichier

 printf("\n");



return(matiere);
}


void recup_chemin(){

char commande[500];

    strcpy(commande, "ls -ltu ");
    strcat(commande, "../semstre_5");
    strcat(commande, " | grep \".txt\" > fic_temp");
    system(commande);

}



































void main (){

recup_chemin();

matiere_typ matiere;
matiere=lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELUMC5A2_EPS_Etudiants.txt");
printf("nom : %s, controle : %s\n",matiere.nom,matiere.controle);
for(int i=0;i<40;i++)
{
 printf("%d %f\n", matiere.eleve[i].ID, matiere.eleve[i].note);
}
free(matiere.eleve);
matiere=lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELUMC5A3_SHS_CC1_E.BABOURAM_Etudiants.txt");
printf("nom : %s, controle : %s\n",matiere.nom,matiere.controle);
for(int i=0;i<40;i++)
{
 printf("%d %f\n", matiere.eleve[i].ID, matiere.eleve[i].note);
}
free(matiere.eleve);
matiere=lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELURO5C3_OMI_GRAPHES_CC1_F.BANNAY_M.-C.LAGASQUIE_V1_Etudiants_.txt");
printf("nom : %s, controle : %s\n",matiere.nom,matiere.controle);
for(int i=0;i<40;i++)
{
 printf("%d %f\n", matiere.eleve[i].ID, matiere.eleve[i].note);
}
free(matiere.eleve);
matiere=lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELURO5C3_OMI_GRAPHES_CC2_F.BANNAY_M.-C.LAGASQUIE_V1_Etudiants_.txt");
printf("nom : %s, controle : %s\n",matiere.nom,matiere.controle);
for(int i=0;i<40;i++)
{
 printf("%d %f\n", matiere.eleve[i].ID, matiere.eleve[i].note);
}
free(matiere.eleve);
matiere=lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELURO5C3_OMI_UML_CC1_C.CHAUDET_V1_Etudiants.txt");
printf("nom : %s, controle : %s\n",matiere.nom,matiere.controle);
for(int i=0;i<40;i++)
{
 printf("%d %f\n", matiere.eleve[i].ID, matiere.eleve[i].note);
}
free(matiere.eleve);
matiere=lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELURO5C4_PROG._ORIENTEE_OBJET_CC1_M.-C.LAGASQUIE_Etudiants.txt");
printf("nom : %s, controle : %s\n",matiere.nom,matiere.controle);
for(int i=0;i<40;i++)
{
 printf("%d %f\n", matiere.eleve[i].ID, matiere.eleve[i].note);
}
free(matiere.eleve);
}