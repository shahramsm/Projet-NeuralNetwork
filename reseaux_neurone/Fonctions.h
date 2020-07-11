
#ifndef RESEAUX_NEURONE_FONCTIONS_H
#define RESEAUX_NEURONE_FONCTIONS_H
#include <math.h>

// c'est une fonction mathématique va être appliquer sur les données
class Fonction_activation {
public:
    virtual double operator()(double)=0;
    virtual double prim(double)=0;
};

class Tanh : public Fonction_activation{
public:
    double operator()(double);
    double prim(double);
};

class Sigmoide : public Fonction_activation{
public:
    double operator()(double);
    double prim(double);
};


#endif //RESEAUX_NEURONE_FONCTIONS_H
