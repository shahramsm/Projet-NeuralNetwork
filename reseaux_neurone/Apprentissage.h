#ifndef RESEAUX_NEURONE_APPRENTISSAGE_H
#define RESEAUX_NEURONE_APPRENTISSAGE_H

#include <time.h>
#include "NN.h"

template<class T, int s>class Apprentissage {
private:
    NN1 *n;

public:
    Apprentissage(NN1 *);
    void apprendre_base(int, double);  // foction qui permets d'apprendre sur les données
    int evaluer(); // fonction qui permets de déterminer le nbr des données bien classifier parmi toutes les données
};


template <class T,class U, int s> class Apprentissage2{
private:
    U *n;
public:
    Apprentissage2(U *n);
    void apprendre_base(int, double);
    int evaluer();
};


#include "Apprentissage.cpp"   

#endif //RESEAUX_NEURONE_APPRENTISSAGE_H
