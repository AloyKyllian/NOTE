#include <stdlib.h>
#include <stdio.h>  
#include <string.h>

#define NB_MATIERE 20

typedef char *String ;

typedef struct
{
    int ID;
    float note;
}eleve_typ;

typedef char controle_typ[9];

typedef char nom_typ[20];

typedef struct
{
    int ID_etu;
    float note_etu[NB_MATIERE];
    controle_typ controle_etu[NB_MATIERE];
    nom_typ nom_etu[NB_MATIERE];
}etudiant_typ;

typedef struct
{
    eleve_typ *eleve;
    controle_typ controle;
    nom_typ nom;
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


    for(int cot=0;strcmp(mot_lu,"22212673")!=0;fscanf(fichier,"%s",mot_lu))
    {

        if(strncmp(mot_lu,"ELU",3)==0)
        {
        strcpy(matiere.nom,mot_lu);
        }        
        else if(strncmp(mot_lu,"CC",2)==0)
        {

         strcpy(matiere.controle,mot_lu);
         }    

    }


    fscanf(fichier,"%s",note_lu);


    virgule_vers_point(note_lu);

    matiere.eleve[nb_eleve].ID=atoi("22212673");
    matiere.eleve[nb_eleve].note=atof(note_lu);


    for(nb_eleve=1;strcmp(ID_lu,"MOYENNE")!=0;fscanf(fichier,"%s",ID_lu))
    
    {
        if(strlen(ID_lu)==8)
        {
        fscanf(fichier,"%s",note_lu);


        virgule_vers_point(note_lu);

        matiere.eleve[nb_eleve].ID=atoi(ID_lu);
        matiere.eleve[nb_eleve].note=atof(note_lu);

        if(strcmp(note_lu,"Validé")==0  || strcmp(note_lu,"DISPENSE")==0 )
        {
            fscanf(fichier,"%*s");
            matiere.eleve[nb_eleve].note=-1;
        }

        nb_eleve++;
        }
    }

    fclose(fichier);//fermeture du fichier



return(matiere);
}


void recup_chemin(){

char commande[500];

    strcpy(commande, "ls -ltu ");
    strcat(commande, "../semstre_5");
    strcat(commande, " | grep \".txt\" > fic_temp");
    system(commande);

}


void lire_tout_fichier()
{
etudiant_typ etudiant[40];

recup_chemin();
char chemin_fichier[100]="fic_temp";
char chemin_complet[100]="";
matiere_typ matiere;
int nb_matiere=0;
    FILE* fichier = NULL;//pointeur de fichier pour utiliser les fonction associé


    fichier = fopen("fic_temp", "r");//ouvre le fichier ne mode read
    if(fichier==NULL){    
        printf("erreur ouverture pdf");
    }

    fscanf(fichier,"%*s %*s %*s %*s %*s %*s %*s %*s %s",chemin_fichier);

    do
    {
        strcpy(chemin_complet,"../semstre_5/");
        strcat(chemin_complet,chemin_fichier);
        //printf("nom fichier : %s",chemin_complet);
        matiere=lire_fichier(chemin_complet);
        printf("nom : %s, controle : %s\n",matiere.nom,matiere.controle);

        for(int i=0;i<40;i++)
        {
        etudiant[i].ID_etu=matiere.eleve[i].ID;
        etudiant[i].note_etu[nb_matiere]=matiere.eleve[i].note;
        strcpy(etudiant[i].nom_etu[nb_matiere],matiere.nom);
        strcpy(etudiant[i].controle_etu[nb_matiere],matiere.controle);

        //printf("%d %f\n", matiere.eleve[i].ID, matiere.eleve[i].note);
        }

        printf("%d %f\n", matiere.eleve[0].ID, matiere.eleve[0].note);

        free(matiere.eleve);

        printf("\n");
        nb_matiere++;

    } while (fscanf(fichier,"%*s %*s %*s %*s %*s %*s %*s %*s %s",chemin_fichier)!=EOF);

printf("youss : \nID : %d \n",etudiant[0].ID_etu);

        for(int i=0;i<nb_matiere;i++)
        {
            printf("matiere : %s \n controle : %s\n note : %f\n ",etudiant[0].nom_etu[nb_matiere],etudiant[0].controle_etu[nb_matiere],etudiant[0].note_etu[nb_matiere]);
        }



fclose(fichier);
}

















void main (){

    lire_tout_fichier();

/*
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



matiere=lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELURO5C4_PROG._ORIENTEE_OBJET_CC1_M.-C.LAGASQUIE_Etudiants.txt");
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
matiere=lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELURO5C4_PROG._ORIENTEE_OBJET_CC1_M.-C.LAGASQUIE_Etudiants.txt");
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
matiere=lire_fichier("../semstre_5/1A_SRI_2022_23__NOTES_ELURO5C4_PROG._ORIENTEE_OBJET_CC1_M.-C.LAGASQUIE_Etudiants.txt");
printf("nom : %s, controle : %s\n",matiere.nom,matiere.controle);
for(int i=0;i<40;i++)
{
 printf("%d %f\n", matiere.eleve[i].ID, matiere.eleve[i].note);
}
free(matiere.eleve);
*/

}