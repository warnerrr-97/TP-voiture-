/******************************************************************************
 * Nom du fichier : voiture.h
 * Rôle          : Déclaration de la classe Cvoiture
 * Auteur        : BTS CIEL
 * Version       : 2.0
 * Compilation   : g++ -Wall -pedantic -std=c++11
 ******************************************************************************/

#ifndef VOITURE_H
#define VOITURE_H

#include <string>
#include "roue.h"
#include "moteur.h"

class CVoiture
{
private:
    std::string marque;     // Marque de la voiture
    std::string modele;     // Modèle de la voiture
    int vitesse;            // Vitesse actuelle (km/h)

    CMoteur *moteur;        // Agrégation : moteur monté
    CRoue *roues[4];        // Agrégation : roues montées

public:
    CVoiture(std::string ma, std::string mo);
    ~CVoiture();

    void demarrer();
    void arreter();
    void accelerer(int v);
    void ralentir(int v);
    void afficher() const;
    void afficherRoues() const;

    void monterMoteur(CMoteur *m);            // Agrégation : monter le moteur
    void demonterMoteur();                    // Agrégation : démonter le moteur
    void monterRoue(CRoue *r, int position);  // Agrégation : monter une roue (0 à 3)
    void demonterRoue(int position);          // Agrégation : démonter une roue (0 à 3)
};

#endif