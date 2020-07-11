#ifndef RESEAUX_NEURONE_NN_H
#define RESEAUX_NEURONE_NN_H

#include "Perceptron.h"

// cette class permets de presenter un réseaux de neurones. elle construit un réseaux de neurones sans couche avec des classieurs (Perceptrons) pour apprendre sur les données.
class NN1{
private:
    std::vector<Perceptron> NeuralNetwork; // list de n classifeurs  n = 10 ou des images et 3 pour des iris
    int NbrPerceptron;  // nbr de classifieur
public:
    NN1(int,int,Fonction_activation *);
    char evaluation(Input &);
    void apprentissage(Input &, double);
};

// cette class permets de presenter un réseaux de neurones. elle construit un réseaux de neurones avec une couche cachée contenant des classieurs (Perceptrons cachée) pour apprendre sur les données.
class NN2{
private:
    std::vector<Perceptron *> Output_Layer; // list de n perceptrons (classifieurs finale)
    std::vector<Perceptron_cachee> Hidden_Layer;  // list de m perceptrons caché ( noeuds de la couche caché)
    int NbrOutputPerceptron;  // n
    int NbrHiddenPerceptron ;  //m

public:
    NN2(int,int,int,Fonction_activation *);
    char evaluation(Input &);
    void apprentissage(Input &, double);

};
#endif //RESEAUX_NEURONE_NN_H
