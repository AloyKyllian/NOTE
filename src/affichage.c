#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void affichage(int numeroSemestre)
{
    float moy_gene;
    float moy_EU1;
    float moy_EU2;
    float moy_EU3;
    int id;
    char choix;
    int etat = 0;
    switch(etat)
    {
        case 0 : 
        printf("Quel est votre ID ? \n");
        fgets(id,8,stdin);
        if(sizeof(id)!=8)
        {
            printf("Mauvais ID, Veuillez Recommencer \n");
            etat =0;
        }
        else
        {
            etat = 1;
        }

        case 1:  
        //appel des fonctions pour récup les moyennes  
        printf("Voici le récapitulatif de vos notes du Semestre %d : \n\n",numeroSemestre);
        printf("\t Moyenne EU1 : %f \n",moy_EU1);
        printf("\t Moyenne EU2 : %f \n",moy_EU3);
        printf("\t Moyenne EU3 : %f \n\n",moy_EU2);
        printf("\t Moyenne Générale : %f", moy_gene);
        printf("Voulez-vous plus de détails sur vos notes ? (Y/N) ou revenir à la sélection d'ID (R) ? \n");
        fgetc(choix,1,stdin);
        if (choix!='Y' && choix != 'y' && choix != 'N' && choix != 'n' && choix != 'R' && choix != 'r')
        {
            printf("Mauvais choix, Veuillez Recommencer \n");
            etat = 1;
        }
        else if(choix == 'R' || choix == 'r')
        {
            printf("Retour à la sélection d'ID \n");
            etat = 0;
        }
        else if(choix=='Y' || choix == 'y' )
        {
            etat = 2;
        }
        else if(choix=='N' || choix == 'n')
        {
            printf("Vous quittez le programme");
            exit(1);
        }

        case 2:

        //Appel fonction récup notes

        // Afficher toutes les notes ou demander l'UE que l'on veut afficher


    }
   /* do
    {
        
    } while (sizeof(id)!=8);*/


    



}