#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "moyenne.h"
#include "note.h"

int main()
{
    etudiant_typ etudiant[40];
    moyenne resultat;
    int identifiant;
    char chemin_dossier_coef[100] = "../Coef_matiere";
    system("chmod 777 ../Coef_matiere");
    moyenne_matiere tab_moyenne[100];
    // printf("\nEntrer votre identifiant\n");
    // scanf("%d", &identifiant);
    // fonction pour trouver le numero etudiant a partir de l'identifiant

    // recuperation des notes
    etudiant[2] = lire_tout_fichier();
     printf("youss : \nID : %d \n",etudiant[2].ID_etu);

    for(int i=0;i<NB_MATIERE;i++)
    {
        printf("matiere : %s   controle : %s\nnote : %f\n",etudiant[2].nom_etu[i],etudiant[2].controle_etu[i],etudiant[2].note_etu[i]);
    }
    // Calcul des moyennes
    printf("teste avant calcul moyenne\n");
    Calcul_Moyenne_matiere(chemin_dossier_coef, etudiant, 2, tab_moyenne);
    
    resultat = calcul_moyenne(tab_moyenne);
    printf("moyenne generale%f\nmoyenne UE1 %f\nmoyenne UE2 %f\nmoyenne UE3 %f\n", resultat.General, resultat.UE1, resultat.UE2, resultat.UE3);
    
}