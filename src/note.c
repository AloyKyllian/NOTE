#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "note.h"

void virgule_vers_point(String note_lu)
{
    char *ptr;
    if (strchr(note_lu, ',') != 0)
    {
        ptr = strchr(note_lu, ',');
        char Chaine[100];
        strcpy(Chaine, ".");
        strcat(Chaine, (ptr + 1));
        strcpy(&note_lu[strlen(note_lu) - strlen(ptr)], Chaine); // Ici on remplace les , par des .
    }
}

matiere_typ lire_fichier(char *chemin_fichier)
{
    matiere_typ matiere;
    strcpy(matiere.controle, "rien");
    // eleve_typ *eleve;
    matiere.eleve = (eleve_typ *)malloc(40 * sizeof(eleve_typ));

    FILE *fichier = NULL; // pointeur de fichier pour utiliser les fonction associé
    char mot_lu[700] = "";
    char ID_lu[700] = "";
    char note_lu[100] = "";
    int nb_eleve = 0;

    fichier = fopen(chemin_fichier, "r"); // ouvre le fichier ne mode read
    if (fichier == NULL)
    {
        printf("erreur ouverture pdf");
    }

    for (int cot = 0; strcmp(mot_lu, "22212673") != 0; fscanf(fichier, "%s", mot_lu))
    {
        
    }

    fscanf(fichier, "%s", note_lu);

    virgule_vers_point(note_lu);

    matiere.eleve[nb_eleve].ID = atoi("22212673");
    matiere.eleve[nb_eleve].note = atof(note_lu);

    for (nb_eleve = 1; strcmp(ID_lu, "MOYENNE") != 0; fscanf(fichier, "%s", ID_lu))

    {
        if (strlen(ID_lu) == 8)
        {
            fscanf(fichier, "%s", note_lu);

            virgule_vers_point(note_lu);

            matiere.eleve[nb_eleve].ID = atoi(ID_lu);
            matiere.eleve[nb_eleve].note = atof(note_lu);

            if (strcmp(note_lu, "Validé") == 0 || strcmp(note_lu, "DISPENSE") == 0)
            {
                fscanf(fichier, "%*s");
                matiere.eleve[nb_eleve].note = -1;
            }

            nb_eleve++;
        }
    }

    fclose(fichier); // fermeture du fichier

    return (matiere);
}

void recup_chemin()
{

    char commande[500];

    strcpy(commande, "ls -ltu ");
    strcat(commande, "../semstre_5");
    strcat(commande, " | grep \".txt\" > fic_temp");
    system(commande);
}

etudiant_typ lire_tout_fichier()
{
    etudiant_typ etudiant[40];
    recup_chemin();
    char chemin_fichier[100] = "fic_temp";
    char chemin_complet[100] = "";
    char nom_matiere[100] = "";
    char controle[100] = "";
    char Chaine[] = {'\0'};
    char* ptr;        
    matiere_typ matiere;
    int nb_matiere = 0;
    FILE *fichier = NULL; // pointeur de fichier pour utiliser les fonction associé

    fichier = fopen("fic_temp", "r"); // ouvre le fichier ne mode read
    if (fichier == NULL)
    {
        printf("erreur ouverture pdf");
    }

    fscanf(fichier, "%*s %*s %*s %*s %*s %*s %*s %*s %s", chemin_fichier);

    do
    {
            strcpy(controle, "");
            strcpy(nom_matiere, &chemin_fichier[22]);
            strcpy(&nom_matiere[8], Chaine);
            

            ptr=strstr(chemin_fichier,"CC");
            if(ptr != NULL)
            {
                strcpy(controle, ptr);
                strcpy(&controle[3], Chaine);
            }
            ptr=strstr(chemin_fichier,"UML");
            if(ptr != NULL)
            {
                strcpy(controle, ptr);
                strcpy(&controle[3], Chaine);
            }
            //printf("  controle matiere : %s", controle);
            ptr=strstr(chemin_fichier,"TP");
            if(ptr != NULL)
            {
                strcpy(controle, "TP");
            }
            if(strlen(controle)==0)
            {
                strcpy(controle, "CC1");
                
            }

        strcpy(chemin_complet, "../semstre_5/");
        strcat(chemin_complet, chemin_fichier);
        matiere = lire_fichier(chemin_complet);

        printf("nom matiere : %s", nom_matiere);
        printf("   controle matiere : %s\n", controle);

        for (int i = 0; i < 40; i++)
        {
            strcpy(etudiant[i].nom_etu[nb_matiere], nom_matiere);
            strcpy(etudiant[i].controle_etu[nb_matiere], controle);


            etudiant[i].ID_etu = matiere.eleve[i].ID;
            etudiant[i].note_etu[nb_matiere] = matiere.eleve[i].note;
        }
        nb_matiere++;
    } while (fscanf(fichier, "%*s %*s %*s %*s %*s %*s %*s %*s %s", chemin_fichier) != EOF);

    // printf("youss : \nID : %d \n",etudiant[2].ID_etu);

    for(int i=0;i<nb_matiere;i++)
    {
        printf("matiere : %s   controle : %s\nnote : %f\n",etudiant[2].nom_etu[i],etudiant[2].controle_etu[i],etudiant[2].note_etu[i]);
    }

    fclose(fichier);

    free(matiere.eleve);
    return etudiant[2];
}

// void main (){

//     lire_tout_fichier();

// }