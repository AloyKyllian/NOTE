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
    do
    {
        printf("Quel est votre ID ? \n");
        fgets(id,8,stdin);
        if(sizeof(id)!=8)
        {
            printf("Mauvais ID, Veuillez Recommencer \n");
        }
    } while (sizeof(id)!=8);
    
    //appel des fonctions pour récup les moyennes

    printf("Voici le récapitulatif de vos notes du Semestre %d : \n\n",numeroSemestre);
    printf("\t Moyenne EU1 : %f \n",moy_EU1);
    printf("\t Moyenne EU2 : %f \n",moy_EU3);
    printf("\t Moyenne EU3 : %f \n\n",moy_EU2);
    printf("\t Moyenne Générale : %f", moy_gene);

do
{
   printf("Voulez-vous plus de détails sur vos notes ? (y/n) \n");
   fgetc(choix,1,stdin);
   if (choix!='y' || choix != 'n')
   {
    printf("Mauvais choic, Veuillez Recommencer \n");
   }
   
} while (choix!='y' || choix != 'n');
if (choix == 'n')
{
    printf("Vous quittez le programme \n");
}
else if (choix == 'y')
{
   // printf("")

}


    



}