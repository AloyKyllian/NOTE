/**
 * Fait par Hugo Lestrade et Kyllian Aloy
 * 
 * Le 18/02/2023
*/
#include "affichage.h"

void affichage(int numeroSemestre, etudiant_typ etudiant[])
{
    float moy_gene;
    float moy_EU1;
    float moy_EU2;
    float moy_EU3;
    int trouver = 0;
    static int indice_etu = -1;
    int id;
    char choix;
    static int etat = 0;
    switch (etat)
    {
    case 0:
        printf("Quel est votre ID ? \n");
        scanf("%d", &id);
        char str[10];
        snprintf(str, 10, "%d", id);
        int len = strlen(str);

        for (int i = 0; i < 40; i++)
        {
            //printf("%d %d", etudiant[i].ID_etu, id);
            if (etudiant[i].ID_etu == id)
            {
                indice_etu = i;
            }
        }

        if (strlen(str) != 8)
        {
            printf("Mauvais ID, Veuillez Recommencer \n");
            etat = 0;
        }
        else if (indice_etu != -1)
        {
            etat = 1;
        }
        else
        {
            printf("ID inexistant dans la base de donnée \n");
        }
        break;

    case 1:
        if(1){};
        // TRIE DES NOTES ^^

        char commande[100];
        FILE *fichier = NULL; // pointeur de fichier pour utiliser les fonction associé

        fichier = fopen("note.txt", "w"); // ouvre le fichier ne mode read
        if (fichier == NULL)
        {
            printf("erreur ouverture");
        }
        for (int i = 0; i < NB_CONTROLE; i++)
        {
            fprintf(fichier, "%8s %3s %f\n", etudiant[indice_etu].nom_etu[i], etudiant[indice_etu].controle_etu[i], etudiant[indice_etu].note_etu[i]);
        }
        fclose(fichier);

        strcpy(commande, "sort note.txt > note_sort.txt");
        system(commande);

        fichier = fopen("note_sort.txt", "r"); // ouvre le fichier ne mode read
        if (fichier == NULL)
        {
            printf("erreur ouverture pdf");
        }
        for (int i = 0; i < NB_CONTROLE; i++)
        {
            fscanf(fichier, "%8s %3s %f\n", etudiant[indice_etu].nom_etu[i], etudiant[indice_etu].controle_etu[i], &etudiant[indice_etu].note_etu[i]);
        }
        fclose(fichier);

        // AFFICHAGE DES NOTES

        printf("\nID : %d \n", etudiant[indice_etu].ID_etu);

        for (int i = 0; i < NB_CONTROLE; i++)
        {
            printf("matiere : %s   controle : %3s   note : %f\n", etudiant[indice_etu].nom_etu[i], etudiant[indice_etu].controle_etu[i], etudiant[indice_etu].note_etu[i]);
        }

        Calcul_note_coef(etudiant);
        /*
            // appel des fonctions pour récup les moyennes

            printf("Voici le récapitulatif de vos notes du Semestre %d : \n\n", numeroSemestre);
            printf("\t Moyenne EU1 : %f \n", moy_EU1);
            printf("\t Moyenne EU2 : %f \n", moy_EU3);
            printf("\t Moyenne EU3 : %f \n\n", moy_EU2);
            printf("\t Moyenne Générale : %f\n", moy_gene);
            printf("Voulez-vous plus de détails sur vos notes ? (Y/N) ou revenir à la sélection d'ID (R) ? \n");*/
        scanf("%s", &choix);
        if (choix != 'Y' && choix != 'y' && choix != 'N' && choix != 'n' && choix != 'R' && choix != 'r')
        {
            printf("Mauvais choix, Veuillez Recommencer \n");
            etat = 1;
        }
        else if (choix == 'R' || choix == 'r')
        {
            printf("Retour à la sélection d'ID \n");
            etat = 0;
        }
        else if (choix == 'Y' || choix == 'y')
        {
            etat = 2;
        }
        else if (choix == 'N' || choix == 'n')
        {
            printf("Vous quittez le programme\n");
            #ifdef WINDOWS
            system("del fic_temp");
            system("del note.txt");
            system("del note_sort.txt");
            system("del sort.txt");
            #endif
            exit(1);
        }
        break;

    case 2:

        // Appel fonction récup notes

        /* do
         {

         } while (sizeof(id)!=8);*/
        break;
    }
}

/*
void main(){
    affichage(5);
}
*/