/******************************************************************************
 * Nom du fichier : voiture.cpp
 * Rôle          : Implémentation des méthodes de la classe Cvoiture
 * Auteur        : BTS CIEL
 * Version       : 2.0
 * Compilation   : g++ -Wall -pedantic -std=c++11
 ******************************************************************************/

##include <iostream>
#include "voiture.h"
using namespace std;

// Constructeur
CVoiture::CVoiture(string ma, string mo)
{
    marque = ma;
    modele = mo;
    vitesse = 0;
    moteur = NULL;          // pas de moteur au départ
    for (int i = 0; i < 4; i++)
    {
        roues[i] = NULL;    // pas de roues au départ
    }
}

// Destructeur (pas de delete : agrégation)
CVoiture::~CVoiture()
{
    cout << "Destruction de la voiture " << marque << " " << modele << endl;
}

void CVoiture::demarrer()
{
    if (moteur != NULL)
    {
        moteur->demarrer();
    }
    else
    {
        cout << "Aucun moteur monte" << endl;
    }
}

void CVoiture::arreter()
{
    vitesse = 0;
    if (moteur != NULL)
    {
        moteur->arreter();
    }
}

void CVoiture::accelerer(int v)
{
    if (moteur != NULL && v > 0)
    {
        vitesse = vitesse + v;
        moteur->accelerer(v * 40);
        cout << "Vitesse : " << vitesse << " km/h" << endl;
    }
}

void CVoiture::ralentir(int v)
{
    if (v > 0)
    {
        vitesse = vitesse - v;
        if (vitesse < 0)
        {
            vitesse = 0;
        }
        cout << "Vitesse : " << vitesse << " km/h" << endl;
    }
}

void CVoiture::afficher() const
{
    cout << "Voiture : " << marque << " " << modele << endl;
    cout << "Vitesse : " << vitesse << " km/h" << endl;
    if (moteur != NULL)
    {
        moteur->afficher();
    }
    else
    {
        cout << "Aucun moteur monte" << endl;
    }
    afficherRoues();
}

void CVoiture::afficherRoues() const
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Roue " << i << " : ";
        if (roues[i] != NULL)
        {
            roues[i]->afficher();
        }
        else
        {
            cout << "non montee" << endl;
        }
    }
}

void CVoiture::monterMoteur(CMoteur *m)
{
    if (moteur == NULL)
    {
        moteur = m;
    }
}

void CVoiture::demonterMoteur()
{
    if (vitesse == 0)
    {
        moteur = NULL;
    }
}

void CVoiture::monterRoue(CRoue *r, int position)
{
    if (position >= 0 && position < 4 && roues[position] == NULL)
    {
        roues[position] = r;
    }
}

void CVoiture::demonterRoue(int position)
{
    if (position >= 0 && position < 4 && vitesse == 0)
    {
        roues[position] = NULL;
    }
}