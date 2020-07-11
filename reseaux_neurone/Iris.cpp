#include <iostream>
#include <fstream>
#include "Iris.h"

Iris::Iris(int indice){
    std::string s = std::to_string(indice);
    std::ifstream fichier("/Users/plu/Desktop/C++/iris_training/iris"+s);
    double m1,m2,m3,m4;
    char comma;
    std::string FlowerLabel;
    if(fichier){
        fichier>>m1>>comma>>m2>>comma>>m3>>comma>>m4>>comma>>FlowerLabel;
        if(FlowerLabel=="Iris-virginica"){
            set_label('1');
        }
        if(FlowerLabel=="Iris-versicolor"){
            set_label('2');
        }
        else {
            set_label('0');
        }
        FlowerDescription[0]=m1;
        FlowerDescription[1]=m2;
        FlowerDescription[2]=m3;
        FlowerDescription[3]=m4;
    }
    else{
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
    }
    fichier.close();
}

double Iris::operator[](int i){
    return FlowerDescription[i];
}