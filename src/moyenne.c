/**
 * Fait par Youssera Achachera et Kyllian Aloy
 * 
 * Le 18/02/2023
*/

#include "moyenne.h"

void lecture_coef(char chemin_dossier_coef[], coef_note_typ *tab_note_coef, coef_matiere_typ *tab_mat_coef)
{

    FILE *fichier;
    char chaine[100];
    char elum[100];
    char nom[100];

    char commande[100];
    char nom_fichier[100];
    int j = 0;
    int i = 0;
    int fin_ligne = 0;
    float coef;

    fichier = fopen("CoefCC.txt", "r");
    while (fscanf(fichier, "%s %s", elum, nom) != EOF)
    {
        fin_ligne = 0;
        do
        {
            fscanf(fichier, "%s %f", chaine, &coef);

            if (strcmp(chaine, "UE") == 0)
            {
                strcpy(tab_mat_coef->elum[j], elum);
                strcpy(tab_mat_coef->nom[j], nom);
                tab_mat_coef->coef[j] = coef;
                fin_ligne = 10;
                // printf("%s %s  %.2f \n", tab_mat_coef->elum[j], tab_mat_coef->nom[j], tab_mat_coef->coef[j]);
                j++;
            }
            else
            {
                // printf("CC : %3s coef : %1->2f\n", chaine, coef);
                strcpy(tab_note_coef->elum[i], elum);
                strcpy(tab_note_coef->nom[i], nom);
                tab_note_coef->coef_cc[0] = 1; // pb avac anglais je sais pas pq
                tab_note_coef->coef_cc[i] = coef;
                strcpy(tab_note_coef->controle[i], chaine);
                // printf("%s %4s %s %.2f %d\n", tab_note_coef->elum[i], tab_note_coef->nom[i], tab_note_coef->controle[i], tab_note_coef->coef_cc[i],i);
                i++;
                // printf(" anglais %.2f ",tab_note_coef->coef_cc[0]);
            }

        } while (fin_ligne != 10);
    }
    fclose(fichier);

    //         for (int j = 0; j < NB_MATIERE; j++)
    // {
    //     printf("%s %s  %.2f \n", tab_mat_coef->elum[j], tab_mat_coef->nom[j], tab_mat_coef->coef[j]);
    // }

    /*
        for (int j = 0; j < NB_CONTROLE_TOT; j++)
        {
            printf("%s %4s %s %.2f \n", tab_note_coef->elum[j], tab_note_coef->nom[j], tab_note_coef->controle[j], tab_note_coef->coef_cc[j]);
        }
        */
}

void lecture_note(etudiant_typ *etu, char nom_fichier[])
{

    FILE *fichier;
    int i = 0;

    fichier = fopen(nom_fichier, "r");
    while (fscanf(fichier, "%s %s %f", &etu->nom_etu[i], &etu->controle_etu[i], &etu->note_etu[i]) != EOF)
    {
        i++;
    }
    fclose(fichier);

    // for(int j=0;j<i;j++)
    // {
    //     printf(" %s %s %f\n", etu->nom_etu[j], etu->controle_etu[j],etu->note_etu[j]);
    // }
}

void lecture_note2(note_typ *note, char nom_fichier[])
{

    FILE *fichier;
    int i = 0;

    fichier = fopen(nom_fichier, "r");
    while (fscanf(fichier, "%s %s %s %f", &note->elum[i], &note->nom_matiere[i], &note->controle_etu[i], &note->note_etu[i]) != EOF)
    {
        i++;
    }
    fclose(fichier);

    // for(int j=0;j<i;j++)
    // {
    //     printf(" %s %s %f\n", etu->nom_etu[j], etu->controle_etu[j],etu->note_etu[j]);
    // }
}

void Calcul_note_coef(etudiant_typ etudiant[])
{
    FILE *fichier = NULL; // pointeur de fichier pour utiliser les fonction associé
    coef_note_typ tab_note_coef;
    coef_matiere_typ tab_mat_coef;
    etudiant_typ etu;
    note_typ note;
    moyenne_typ matiere;
    UE_typ moyenne;
    char elum[20];
    int num_note = 0;
    int trouve = 0;
    lecture_coef("CoefCC.txt", &tab_note_coef, &tab_mat_coef);

    // for (int j = 0; j < NB_CONTROLE_TOT; j++)
    // {
    //     printf("%s %4s %s %.2f \n", tab_note_coef.elum[j], tab_note_coef.nom[j], tab_note_coef.controle[j], tab_note_coef.coef_cc[j]);
    // }

    // for (int j = 0; j < NB_MATIERE; j++)
    // {
    //     printf("%s %s  %.2f \n", tab_mat_coef.elum[j], tab_mat_coef.nom[j], tab_mat_coef.coef[j]);
    // }

    for (int j = 0; j < NB_CONTROLE_TOT; j++)
    {
        etu.note_etu[j] = 10;
        strcpy(etu.controle_etu[j], "INC");
        strcpy(etu.nom_etu[j], "INC");
        // printf(" %s %s %f\n", etu.nom_etu[j], etu.controle_etu[j], etu.note_etu[j]);
    }

    lecture_note(&etu, "note_sort.txt");

    // for (int j = 0; j < NB_CONTROLE_TOT; j++)
    // {
    //     printf(" %s %s %f\n", etu.nom_etu[j], etu.controle_etu[j], etu.note_etu[j]);
    // }
    //     printf("\n");
    //     for (int j = 0; j < NB_CONTROLE_TOT; j++)
    // {
    //     printf(" %s %s %s %f\n", tab_note_coef.nom[j],tab_note_coef.controle[j], tab_note_coef.elum[j], tab_note_coef.coef_cc[j]);
    // }
    // printf("\n");

    num_note = 0;
    do
    {
        trouve = 0;
        for (int i = 0; i < NB_CONTROLE_TOT; i++)
        {
            if (strcmp(tab_note_coef.elum[num_note], etu.nom_etu[i]) == 0 && strcmp(tab_note_coef.controle[num_note], etu.controle_etu[i]) == 0)
            {
                // printf("%s %s %s %s \n",tab_note_coef.elum[num_note], etu.nom_etu[i], tab_note_coef.controle[num_note], etu.controle_etu[i]);
                trouve = 1;
            }
        }

        if (trouve == 0)
        {
            // printf("%s %s\n", tab_note_coef.elum[num_note], tab_note_coef.controle[num_note]);
            for (int i = 0; i < NB_CONTROLE_TOT; i++)
            {
                if (strcmp(etu.nom_etu[i], "INC") == 0)
                {
                    strcpy(etu.nom_etu[i], tab_note_coef.elum[num_note]);
                    strcpy(etu.controle_etu[i], tab_note_coef.controle[num_note]);
                    i = NB_CONTROLE_TOT;
                    // break;
                }
                // break;
            }
        }
        num_note++;
    } while (num_note < NB_CONTROLE_TOT);

    fichier = fopen("note.txt", "w"); // ouvre le fichier ne mode read
    if (fichier == NULL)
    {
        printf("erreur ouverture pdf");
    }
    for (int i = 0; i < NB_CONTROLE_TOT; i++)
    {
        fprintf(fichier, "%8s %3s %f\n", etu.nom_etu[i], etu.controle_etu[i], etu.note_etu[i]);
    }
    fclose(fichier);

    system("sort note.txt > sort.txt");

    lecture_note(&etu, "sort.txt");

    // printf("\nTOUTES LES NOTES  \n");

    // for (int j = 0; j < NB_CONTROLE_TOT; j++)
    // {
    //     printf("%s %s %f\n", etu.nom_etu[j], etu.controle_etu[j], etu.note_etu[j]);
    // }

    // printf("\nCOEFFICIENT  \n");

    // for (int j = 0; j < NB_CONTROLE_TOT; j++)
    // {
    //     printf("%s %s %f\n", tab_note_coef.elum[j], tab_note_coef.controle[j], tab_note_coef.coef_cc[j]);
    // }

    for (int j = 0; j < NB_CONTROLE_TOT; j++)
    {
        strcpy(note.controle_etu[j], etu.controle_etu[j]);
        strcpy(note.nom_matiere[j], tab_note_coef.nom[j]);
        strcpy(note.elum[j], tab_note_coef.elum[j]);
        note.note_etu[j] = etu.note_etu[j] * tab_note_coef.coef_cc[j];
    }

    // printf("\nNOTE * COEFFICIENT   \n");

    // for (int j = 0; j < NB_CONTROLE_TOT; j++)
    // {
    //     printf("%s %s %s %f\n", note.elum[j], note.nom_matiere[j], note.controle_etu[j], note.note_etu[j]);
    // }

    // printf("\n");
    for (int i = 0; i < NB_MATIERE; i++)
        matiere.note_etu[i] = 0;

    num_note = 0;
    strcpy(elum, note.elum[0]);
    strcpy(matiere.nom_matiere[num_note], note.nom_matiere[0]);
    strcpy(matiere.elum[num_note], note.elum[0]);
    matiere.note_etu[num_note] += note.note_etu[0];
    do
    {
        for (int j = 1; j < NB_CONTROLE_TOT; j++)
        {
            // printf("%s %s \n", note.elum[j], elum);
            if (strcmp(note.elum[j], elum) != 0)
            {
                num_note++;
                strcpy(matiere.nom_matiere[num_note], note.nom_matiere[j]);
                strcpy(matiere.elum[num_note], note.elum[j]);
                strcpy(elum, note.elum[j]);
            }
            else
            {
            }

            matiere.note_etu[num_note] += note.note_etu[j];
            // printf("%s %f %f %d\n", note.nom_matiere[j], matiere.note_etu[num_note], note.note_etu[j], num_note);
        }
        num_note++;
    } while (num_note < NB_MATIERE);
    printf("\nMOYENNE DE CHAQUE MATIERE \n");
    for (int j = 0; j < NB_MATIERE; j++)
    {
        printf("%s %s %f\n", matiere.elum[j], matiere.nom_matiere[j], matiere.note_etu[j]);
    }
    // printf("\n COEFICIENT DE CHAQUE MATIERE \n");
    // for (int j = 0; j < NB_MATIERE; j++)
    // {
    //     printf("%s %s  %.2f \n", tab_mat_coef.elum[j], tab_mat_coef.nom[j], tab_mat_coef.coef[j]);
    // }


    moyenne.UE1=0;
    moyenne.UE2=0;
    moyenne.UE3=0;
    moyenne.gene=0;
    for (int i = 0; i < 4; i++)
    {
        //printf("%f",moyenne.UE1);
        moyenne.UE1 += matiere.note_etu[i] * tab_mat_coef.coef[i];
    }

    for (int i = 4; i < 8; i++)
    {
        moyenne.UE2 += matiere.note_etu[i] * tab_mat_coef.coef[i];
    }

    for (int i = 8; i < 12; i++)
    {
        moyenne.UE3 += matiere.note_etu[i] * tab_mat_coef.coef[i];
    }

    moyenne.gene = (moyenne.UE1 + moyenne.UE2 + moyenne.UE3) / 3;

    printf("\nMOYENNE UE1 : %f  MOYENNE UE2 : %f  MOYENNE UE3 : %f  MOYENNE GENE : %f", moyenne.UE1, moyenne.UE2, moyenne.UE3, moyenne.gene);
}
