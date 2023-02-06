#ifndef note_H_INCLUS    
#define note_H_INCLUS   

#define NB_MATIERE 20

typedef char *String ;

typedef struct
{
    int ID;
    float note;
}eleve_typ;

typedef char controle_typ[9];

typedef char nom_typ[20];

typedef struct
{
    int ID_etu;
    float note_etu[NB_MATIERE];
    controle_typ controle_etu[NB_MATIERE];
    nom_typ nom_etu[NB_MATIERE];
}etudiant_typ;

typedef struct
{
    eleve_typ *eleve;
    controle_typ controle;
    nom_typ nom;
}matiere_typ;



void virgule_vers_point(String note_lu);
matiere_typ lire_fichier (char* chemin_fichier);
void recup_chemin();
etudiant_typ lire_tout_fichier();




#endif