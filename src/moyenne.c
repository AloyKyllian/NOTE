#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "moyenne.h"


void Calcul_Moyenne_matiere(char chemin_dossier_coef[100], etudiant_typ etudiant[40], int numero_etu,moyenne_matiere tab_moyenne[])
{
    FILE *fichier;
    char chaine[100];
    int coef;
    float moyenne = 0;
    char commande[100];
    char nom_fichier[100];
    int j = 0;

    for (int i = 0; i < NB_MATIERE; i++)
    {
        system("touch tmp.txt");
        system("chmod 777 tmp.txt");
        strcpy(commande, "grep -l ");
        strcat(commande, etudiant[numero_etu].nom_etu[i]);
        strcpy(tab_moyenne[j].elum, etudiant[numero_etu].nom_etu[i]);
        strcpy(commande, " ");
        strcat(commande, chemin_dossier_coef);
        strcat(commande, " > tmp.txt");
        system(commande);
        fichier = fopen("tmp.txt", "r");
        if (strcmp(etudiant[numero_etu].controle_etu[i], "rien") != 0)
        {
            while (fscanf(fichier, "%d", &coef) != EOF)
            {
                moyenne = etudiant[numero_etu].note_etu[i] * coef;
                tab_moyenne[j].moyenne_elum = moyenne;
                j++;
            }
        }

        else
        {
            while (fscanf(fichier, "%c", chaine) != EOF)
            {   
                if(strcmp(etudiant[numero_etu].controle_etu[i],chaine)){
                    fscanf(fichier, "%d", &coef);
                    moyenne = moyenne+etudiant[numero_etu].note_etu[i] * coef;
                }
               
            }tab_moyenne[j].moyenne_elum = moyenne; j++;
        }
        // system("rm tmp.txt");
    }

}

moyenne calcul_moyenne(moyenne_matiere tab_moyenne[]){
    float moyenneGeneral=0;
    float moyenneUE1=0;
    float moyenneUE2=0;
    float moyenneUE3=0;
    moyenne resultat;
    for(int i=0;i<NB_MATIERE;i++){
        if(strstr(tab_moyenne[i].elum,"ELUMC5A")!=NULL){
            moyenneUE1=moyenneUE1+tab_moyenne[i].moyenne_elum;
        }
        if(strstr(tab_moyenne[i].elum,"ELUMC5B")!=NULL){
            moyenneUE2=moyenneUE2+tab_moyenne[i].moyenne_elum;
        }
        if(strstr(tab_moyenne[i].elum,"ELUMC5C")!=NULL){
            moyenneUE3=moyenneUE3+tab_moyenne[i].moyenne_elum;
        }
    }
    resultat.UE1=moyenneUE1;
    resultat.UE2=moyenneUE2;
    resultat.UE3=moyenneUE3;
    resultat.General=moyenneUE1*0,3+moyenneUE2*0,3+moyenneUE3*0,4;
}
