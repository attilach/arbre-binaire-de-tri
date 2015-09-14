/************************************************
 * Nom : Estalella
 * Kevin : Kevin
 * Date: 22.05.2015
 * Version: 1.0
 * Titre: Les arbres
 * Description: Générer des entiers aléatoires et
                construire un arbre binaire de tri.
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *Enfant_Gauche;
    Element *Enfant_Droite;
};

int main()
{
    //On crée un pointeur sur racine
    Element *racine = malloc(sizeof(Element));

    printf("\n\nChoisissez le nombre de valeurs aleatoires a generer: ");

    int taille;
    scanf("%d", &taille);

    int tableauValeur[taille];

    remplirTableau(taille, tableauValeur);

    racine->nombre = tableauValeur[0];
    racine->Enfant_Gauche = NULL;
    racine->Enfant_Droite = NULL;

    int i;
    for(i=1; i<taille; i++)
    {
        insererDansArbre(racine, tableauValeur[i]);
    }

    afficherArbre(racine, 0);

    return 0;
}

/*
 * Titre: afficherArbre
 *
 * Description: Fonction récursive pour afficher un arbre
 *
 * Paramètres: Prend la racine  comme premier paramètre
 *
 * Retour: Aucun
 */
void afficherArbre(Element *element, int niveau)
{
    if (element != NULL)
    {
        afficherArbre(element->Enfant_Gauche, niveau + 1);
        printf("nombre: %d -> niveau: %d\n", element->nombre, niveau);
        afficherArbre(element->Enfant_Droite, niveau + 1);
    }
}


/*
 * Titre: insererArbre
 *
 * Description: Fonction récursive pour insérer une valeure dans un arbre
 *
 * Retour: Aucun
 */
void insererDansArbre(Element *element, int valeur)
{
    if (element->nombre <= valeur)
    {
        if (element->Enfant_Gauche != NULL)
        {
            insererDansArbre(element->Enfant_Gauche, valeur);
        }
        else
        {
            Element *nouveau_element = malloc(sizeof(Element));
            nouveau_element->nombre = valeur;
            nouveau_element->Enfant_Gauche = NULL;
            nouveau_element->Enfant_Droite = NULL;
            element->Enfant_Gauche = nouveau_element;
        }
    }
    else
    {
        if (element->Enfant_Droite != NULL)
        {
            insererDansArbre(element->Enfant_Droite, valeur);
        }
        else
        {
            Element *nouveau_element = malloc(sizeof(Element));
            nouveau_element->nombre = valeur;
            nouveau_element->Enfant_Gauche = NULL;
            nouveau_element->Enfant_Droite = NULL;
            element->Enfant_Droite = nouveau_element;
        }
    }
}

/*
 * Titre: remplirTableau
 *
 * Description: Rempli un tableau avec des valeurs aléatoire de 1 à 100
 *
 * Retour: Aucun
 */
void remplirTableau(int taille, int tableauValeur[taille])
{
    srand(time(NULL));
    int i=0;
    for(i=0;i<taille;i++)
        tableauValeur[i] = (rand() % 100) + 1;
}
