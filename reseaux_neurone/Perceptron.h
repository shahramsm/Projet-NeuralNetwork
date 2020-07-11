#ifndef RESEAUX_NEURONE_PERCEPTRON_H
#define RESEAUX_NEURONE_PERCEPTRON_H

#include "Fonctions.h"
#include "Input.h"

#include <vector>

// la class perceptron permets de claasifier les données en modfiant les poids des inputs en permanant
class Perceptron{
private:
    std::vector<double> poids; // la taille du vecteur est n+1       n:nbr de pixel 784 ou nbr de caractéristique 4
    Fonction_activation *f;
    double delta;  // variable qui nous permets d'apprendre sur les données
    char PerceptronLabel;
public:
    Perceptron(int,Fonction_activation *,char);  //constructeur
    double get_poids(int);
    double forward(Input &);
    void calcul_delta(Input &);
    double get_delta();
    void backprop(Input &, double); // fonction qui mets à jour les poids de perceptron
    int get_size();
    Fonction_activation * getF();
    void setDelta(double);
    void insertPoid(double,int);

};

//Perceptron multicouche avec couche cachée
class Perceptron_cachee : public Perceptron{
private:
    std::vector<Perceptron *> percept;

public:
    Perceptron_cachee(int,Fonction_activation *,char, std::vector<Perceptron *> &);
    void calcul_delta(Input &);
    void backprop(Input &, double);
};


#endif //RESEAUX_NEURONE_PERCEPTRON_H
