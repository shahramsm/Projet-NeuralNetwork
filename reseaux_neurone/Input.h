
#ifndef RESEAUX_NEURONE_INPUT_H
#define RESEAUX_NEURONE_INPUT_H


#include <vector>


// class qui nous permets de charger les données dans le réseaux neurones
class Input{
private:
    char Label{};
public:
    virtual double operator[](int)=0;
    char get_label();
    void set_label(char);
};

// cette class permets de representer les valeurs à la sortie des perceptrons de la couche cachée.
class Input_intermediaire : public Input{
private:
    std::vector<double> a;
public:
    Input_intermediaire(char);
    void add (double);
    double operator[](int);
};


#endif //RESEAUX_NEURONE_INPUT_H
