#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "moyenne.h"
#include "note.h"

int main(){
    int identifiant;
    char *cheminDossierCoef="../Coef_matiere";
    printf("\nEntrer votre identifiant\n");
    scanf("%d",&identifiant);
    //fonction pour trouver le numero etudiant a partir de l'identifiant

    //recuperation des notes
    lire_tout_fichier();

    //Calcul des moyennes


}