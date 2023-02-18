#include <stdlib.h>
#include <stdio.h>_coef
#include <string.h>
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
    while (fscanf(fichier, "%s %s %s %f", &note->elum[i],&note->nom_matiere[i], &note->controle_etu[i], &note->note_etu[i]) != EOF)
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
    printf("\n");

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
            printf("%s %s\n", tab_note_coef.elum[num_note], tab_note_coef.controle[num_note]);
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

    for (int j = 0; j < NB_CONTROLE_TOT; j++)
    {
        printf(" %s %s %f\n", etu.nom_etu[j], etu.controle_etu[j], etu.note_etu[j]);
    }

    printf("\n\nSUITE   \n");

    num_note = 0;

    do
    {
        for (int j = 0; j < NB_CONTROLE_TOT; j++)
        {
            if (strcmp(etu.nom_etu[num_note], tab_note_coef.elum[j]) == 0)
            {
                if (strcmp(etu.controle_etu[num_note], tab_note_coef.controle[j]) == 0)
                {
                    // printf("%s %s %s %s \n",tab_note_coef.elum[j], etu.nom_etu[num_note], tab_note_coef.controle[j], etu.controle_etu[num_note]);
                    strcpy(note.controle_etu[num_note], etu.controle_etu[num_note]);
                    strcpy(note.nom_matiere[num_note], tab_note_coef.nom[j]);
                    strcpy(note.elum[num_note], tab_note_coef.elum[j]);
                    note.note_etu[num_note] = etu.note_etu[num_note] * tab_note_coef.coef_cc[j];
                    // printf(" %s %s %f %d\n", etu.nom_etu[num_note], tab_note_coef.elum[j], num_note);
                }
            }
        }
        num_note++;
    } while (num_note < NB_CONTROLE_TOT);

    for (int j = 0; j < NB_CONTROLE_TOT; j++)
    {
        printf(" %s %s %s %f\n", note.elum[j], note.nom_matiere[j], note.controle_etu[j], note.note_etu[j]);
    }

    printf("\n");

    FILE *fichier = NULL; // pointeur de fichier pour utiliser les fonction associé

    fichier = fopen("note2.txt", "w"); // ouvre le fichier ne mode read
    if (fichier == NULL)
    {
        printf("erreur ouverture pdf");
    }
    for (int i = 0; i < NB_CONTROLE_TOT; i++)
    {
        fprintf(fichier, "%8s %4s %3s %f\n", note.elum[i],note.nom_matiere[i], note.controle_etu[i], note.note_etu[i]);
    }
    fclose(fichier);

    system("ls");
    system("sort note2.txt");

    lecture_note2(&note, "sort2.txt");

    for (int j = 0; j < NB_CONTROLE_TOT; j++)
    {
        printf(" %s %s %s %f\n", note.elum[j], note.nom_matiere[j], note.controle_etu[j], note.note_etu[j]);
    }

    printf("\n");
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
            //printf("%s %s \n", note.elum[j], elum);
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
            //printf("%s %f %f %d\n", note.nom_matiere[j], matiere.note_etu[num_note], note.note_etu[j], num_note);
        }
        num_note++;
    } while (num_note < NB_MATIERE);
    printf("\n MOYENNE DE CHAQUE MATIERE \n");
    for (int j = 0; j < NB_MATIERE; j++)
    {
        printf(" %s %s %f\n", matiere.elum[j], matiere.nom_matiere[j], matiere.note_etu[j]);
    }


    for (int j = 0; j < NB_MATIERE; j++)
    {
        printf("%s %s  %.2f \n", tab_mat_coef.elum[j], tab_mat_coef.nom[j], tab_mat_coef.coef[j]);
    }

    for(int i = 0;i<4;i++)
    {
        //printf("%s")
        moyenne.UE1 += matiere.note_etu[i]*tab_mat_coef.coef[i];
    }

    for(int i = 4;i<8;i++)
    {
        moyenne.UE2 += matiere.note_etu[i]*tab_mat_coef.coef[i];
    }

        for(int i = 8;i<12;i++)
    {
        moyenne.UE3 += matiere.note_etu[i]*tab_mat_coef.coef[i];
    }

    moyenne.gene=(moyenne.UE1+moyenne.UE2+moyenne.UE3)/3;

    printf("%f %f %f %f",moyenne.UE1,moyenne.UE2,moyenne.UE3,moyenne.gene);


}
// void Calcul_Moyenne_matiere(char chemin_dossier_coef[100], etudiant_typ etudiant[], int numero_etu, moyenne_matiere tab_moyenne[])
// {
//     matiere mat[NB_MATIERE];
//     FILE *fichier;
//     char chaine[100];
//     float moyenne = 0;
//     char commande[100];
//     char nom_fichier[100];
//     int j = 0;
//     int i = 0;
//     int fin_ligne = 0;
//     float coef;

//     for (int i = 0; i < NB_MATIERE; i++)
//     {
//         /* strcpy(commande, "grep -l ");
//          strcat(commande, etudiant[numero_etu].nom_etu[i]);
//          strcat(commande, " ");
//          strcat(commande, chemin_dossier_coef);
//          system(commande);
//  */
//         fichier = fopen("CoefCC.txt", "r");
//         while (fscanf(fichier, "%s %s", mat[i].elum, mat[i].nom) != EOF)
//         {
//             fin_ligne = 0;
//             do
//             {
//                 fscanf(fichier, "%s %f", chaine, &coef);

//                 if (strcmp(chaine, "UE") == 0)
//                 {
//                     mat[i].coef_UE = coef;
//                     fin_ligne = 10;
//                 }
//                 else
//                 {
//                     printf("CC : %3s coef : %1.2f finligne : %d\n", chaine, coef, fin_ligne);
//                     mat[i].coef_CC[fin_ligne].coef = coef;
//                     strcpy(mat[i].coef_CC[fin_ligne].CC, chaine);
//                     fin_ligne++;
//                 }
//             } while (fin_ligne != 10);

//             // strcpy(nom_fichier, chaine);
//             // printf("\nchaine = %s et nom fichier = %s\n", chaine, nom_fichier);
//             i++;
//         }
//         fclose(fichier);

//         for (int j = 0; j < NB_MATIERE; j++)
//         {
//             printf("%s %4s %s %.2f %.2f\n", mat[j].elum, mat[j].nom, mat[j].coef_CC[0].CC, mat[j].coef_CC[0].coef, mat[j].coef_UE);
//         }

//         printf("\n");

//         int indice_mat = 0;
//         int indice_etu = 0;
//         for (int i = 0; i < NB_MATIERE; i++)
//         {
//             printf("mat %s etu %s\n", mat[i].elum, etudiant[numero_etu].nom_etu[i]);

//             if (strcmp(mat[i].elum,"ELUMC5A1") == 0)
//             {
//                 indice_mat = i;
//                 /*
//                 for(int j=0;j<NB_MATIERE;j++)
//                 {
//                     if(strcmp(mat[i].coef_CC[j].CC,etudiant[numero_etu].controle_etu[j]))
//                     {
//                         mat[i].coef_CC[j].coef=mat[i].coef_CC[j].coef*etudiant[numero_etu].note_etu[j];
//                     }
//                 }
//                 */
//             }

//             if (strcmp(etudiant[numero_etu].nom_etu[0],"ELUMC5A1") == 0)
//             {
//                 indice_etu = i;
//             }

//         }

//         printf("%d %d",indice_etu,indice_mat);

//         for (int j = 0; j < NB_MATIERE; j++)
//         {
//             printf("%s %4s %s %.2f %.2f\n", mat[j].elum, mat[j].nom, mat[j].coef_CC[0].CC, mat[j].coef_CC[0].coef, mat[j].coef_UE);
//         }

//         // mat[0].coef_CC[0]*etudiant->note_etu

//         // fichier = fopen(nom_fichier, "r");
//         /*
//         system("touch tmp.txt");
//         system("chmod 777 tmp.txt");
//         strcpy(commande, "grep -l ");
//         strcat(commande, etudiant[numero_etu].nom_etu[i]);
//         strcpy(tab_moyenne[j].elum, etudiant[numero_etu].nom_etu[i]);
//         strcat(commande, " ");
//         strcat(commande, chemin_dossier_coef);
//         strcat(commande, "/*.txt");
//         strcat(commande, " > tmp.txt");
//         //printf("command : %s \n", commande);
//         fflush(stdout);
//         system(commande);
//         fichier = fopen("tmp.txt", "r");
//         while (fscanf(fichier, "%s", chaine) != EOF)
//         {
//             strcpy(nom_fichier, chaine);
//             //printf("\nchaine = %s et nom fichier = %s\n", chaine, nom_fichier);
//         }
//         fclose(fichier);
//         fichier = fopen(nom_fichier, "r");
//         //printf("\netudiant[numero_etu].controle_etu[i]=%s\n", etudiant[numero_etu].controle_etu[i]);

//         if (strcmp(etudiant[numero_etu].controle_etu[i], "CF") == 0 || strcmp(etudiant[numero_etu].controle_etu[i], "UML") == 0)
//         {
//             //printf("\n dans le if de CF ET UML : etudiant[numero_etu].controle_etu[i]=%s\n", etudiant[numero_etu].controle_etu[i]);

//             while (fscanf(fichier, "%s", chaine) != EOF)
//             {
//                 if (strcmp(chaine, "CF") == 0 || strcmp(chaine, "UML") == 0)
//                 {
//                     fscanf(fichier, "%d", &coef) != EOF;
//                     printf("etudiant[numero_etu].controle_etu[i] = %s , coef = %d\n", etudiant[numero_etu].controle_etu[i], coef);
//                     moyenne = etudiant[numero_etu].note_etu[i] * coef;
//                     tab_moyenne[j].moyenne_elum = moyenne;
//                     j++;
//                 }

//             }
//         }

//         else
//         {
//             while (fscanf(fichier, "%s", chaine) != EOF)
//             {
//                 if (strcmp(etudiant[numero_etu].controle_etu[i], chaine))
//                 {
//                     fscanf(fichier, "%d", &coef);
//                     moyenne = moyenne + etudiant[numero_etu].note_etu[i] * coef;j++;
//                     printf("etudiant[numero_etu].controle_etu[i] = %s , coef = %d\n", etudiant[numero_etu].controle_etu[i], coef);
//                 }
//             }
//             tab_moyenne[j].moyenne_elum = moyenne;

//         }

//         // system("rm tmp.txt");
//         */
//     }
// }

// /**/
// moyenne calcul_moyenne(moyenne_matiere tab_moyenne[])
// {
//     float moyenneGeneral = 0;
//     float moyenneUE1 = 0;
//     float moyenneUE2 = 0;
//     float moyenneUE3 = 0;
//     moyenne resultat;
//     for (int i = 0; i < NB_MATIERE; i++)
//     {
//         if (strstr(tab_moyenne[i].elum, "ELUMC5A") != NULL)
//         {
//             moyenneUE1 = moyenneUE1 + tab_moyenne[i].moyenne_elum;
//         }
//         if (strstr(tab_moyenne[i].elum, "ELUMC5B") != NULL)
//         {
//             moyenneUE2 = moyenneUE2 + tab_moyenne[i].moyenne_elum;
//         }
//         if (strstr(tab_moyenne[i].elum, "ELUMC5C") != NULL)
//         {
//             moyenneUE3 = moyenneUE3 + tab_moyenne[i].moyenne_elum;
//         }
//     }
//     resultat.UE1 = moyenneUE1 / 4;
//     resultat.UE2 = moyenneUE2 / 4;
//     resultat.UE3 = moyenneUE3 / 4;
//     resultat.General = moyenneUE1 * 0, 3 + moyenneUE2 * 0, 3 + moyenneUE3 * 0, 4;
// }
