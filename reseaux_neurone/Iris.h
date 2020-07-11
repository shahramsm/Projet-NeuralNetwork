
#ifndef RESEAUX_NEURONE_IRIS_H
#define RESEAUX_NEURONE_IRIS_H


#include "Input.h"

// class Iris permets de presenter les fleur d'iris
class Iris: public Input{
private:
    double FlowerDescription[4];
public:
    Iris(int); // int c'est l'indice de la fleur entre 0 et 149
    double operator[](int);  // iris[i]=double
};


#endif //RESEAUX_NEURONE_IRIS_H
