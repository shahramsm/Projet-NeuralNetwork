#ifndef RESEAUX_NEURONE_IMAGE_H
#define RESEAUX_NEURONE_IMAGE_H

#include "Input.h"

// class Image permets de présenter les images manuscrit entre 0 et 10
class Image: public Input{
private:
    double pixel [784];
public:
    Image(int); // int c'est l'indice de l'image entre 0 et 59999
    double operator[](int);  // Image[i]=double
};

#endif //RESEAUX_NEURONE_IMAGE_H
