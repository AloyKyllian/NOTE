#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "moyenne.h"
#include "note.h"
#include "affichage.h"

int main()
{
    etudiant_typ etudiant[40];
    etudiant_typ *test;
    //moyenne resultat;
    int identifiant;
    char chemin_dossier_coef[100] = "../Coef_matiere";
    system("chmod 777 ../Coef_matiere");
    //moyenne_matiere tab_moyenne[100];
    // printf("\nEntrer votre identifiant\n");
    // scanf("%d", &identifiant);
    // fonction pour trouver le numero etudiant a partir de l'identifiant

    // recuperation des notes
    lire_tout_fichier(etudiant);

    /*printf("youss : \nID : %d \n",etudiant[28].ID_etu);

    for(int i=0;i<NB_MATIERE;i++)
    {
        printf("matiere : %s   controle : %s\nnote : %f\n",etudiant[28].nom_etu[i],etudiant[28].controle_etu[i],etudiant[28].note_etu[i]);
    }*/
    // Calcul des moyennes
    
    printf("teste avant calcul moyenne\n");
    //Calcul_Moyenne_matiere(chemin_dossier_coef, etudiant, 2, tab_moyenne);
    Calcul_note_coef(etudiant);
  /*  resultat = calcul_moyenne(tab_moyenne);
    printf("moyenne generale%f\nmoyenne UE1 %f\nmoyenne UE2 %f\nmoyenne UE3 %f\n", resultat.General, resultat.UE1, resultat.UE2, resultat.UE3);

    
   while(1){
    affichage(5,etudiant);
   }
*/

}