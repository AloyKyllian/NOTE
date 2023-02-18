/**
 * Fait par Kyllian Aloy
 * 
 * Le 18/02/2023
*/
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
            matiere.eleve[nb_eleve].ID = atoi(ID_lu);
            fscanf(fichier, "%s", note_lu);
            if ( strcmp(note_lu, "DISPENSE") == 0)
            {  
                fflush(stdout);
                matiere.eleve[nb_eleve].note = -2;
            }
            else{
            if (strlen(note_lu) == 8)
            {
                matiere.eleve[nb_eleve].note = -1;
                fseek(fichier,-8, SEEK_CUR);
            }
            else{
            virgule_vers_point(note_lu);

            matiere.eleve[nb_eleve].ID = atoi(ID_lu);
            matiere.eleve[nb_eleve].note = atof(note_lu);

            if (strcmp(note_lu, "Validé") == 0)
            {
                fscanf(fichier, "%*s");
                matiere.eleve[nb_eleve].note = -1;
            }
            }
            
        }
        nb_eleve++;
        }
    }
    fclose(fichier); // fermeture du fichier

    if(nb_eleve != 40)
    {
        printf("il y un pb avec la lecture de ceux fichier (il manque des eleve ! ) %d",nb_eleve);
    }

    return (matiere);
}

void recup_chemin()
{

    char commande[500];

    //strcpy(commande, "ls -ltu ");
    //strcat(commande, "../semstre_5");
    //strcat(commande, " | grep \".txt\" > fic_temp");
    //system(commande);

    //#ifdef WINDOWS
    strcpy(commande, "dir /b ..\\semstre_5 > fic_temp");
    system(commande);
    //#endif
}

void lire_tout_fichier(etudiant_typ etudiant[])
{
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

    #ifdef LINUX
    fscanf(fichier, "%*s %*s %*s %*s %*s %*s %*s %*s %s", chemin_fichier);
    #endif

    #ifdef WINDOWS
    fscanf(fichier, "%s",chemin_fichier);
    #endif


    do
    {

        #ifdef LINUX
        strcpy(chemin_complet, "../semstre_5/");
        #endif

        #ifdef WINDOWS
        strcpy(chemin_complet,"..\\semstre_5\\");
        #endif

            strcat(chemin_complet, chemin_fichier);
            matiere = lire_fichier(chemin_complet);

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
                strcpy(controle, "CF");
                
            }



   //printf("%s",nom_matiere);
        //printf("nom matiere : %s", nom_matiere);
        //printf("   controle matiere : %s\n", controle);

        //printf("matiere : %s   controle : %s\n",nom_matiere,controle);

        for (int i = 0; i < 40; i++)
        {

            etudiant[i].ID_etu = matiere.eleve[i].ID;
            etudiant[i].note_etu[nb_matiere] = matiere.eleve[i].note;

            strcpy(etudiant[i].nom_etu[nb_matiere], nom_matiere);
            strcpy(etudiant[i].controle_etu[nb_matiere], controle);
            //printf("ID : %d  note : %f\n",etudiant[i].ID_etu,etudiant[i].note_etu[nb_matiere]);
        }
        nb_matiere++;
    } while (
    #ifdef LINUX
                fscanf(fichier, "%*s %*s %*s %*s %*s %*s %*s %*s %s", chemin_fichier) != EOF);
    #endif
    #ifdef WINDOWS
        fscanf(fichier, "%s", chemin_fichier) != EOF);
    #endif
    


    // printf("youss : \nID : %d \n",etudiant[28].ID_etu);

    // for(int i=0;i<nb_matiere;i++)
    // {
    //     printf("matiere : %s   controle : %s\nnote : %f\n",etudiant[15].nom_etu[i],etudiant[15].controle_etu[i],etudiant[15].note_etu[i]);
    // }

    fclose(fichier);

    free(matiere.eleve);
    //return etudiant;
}

// void main (){

//     lire_tout_fichier();

// }