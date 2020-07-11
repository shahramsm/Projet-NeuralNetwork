
#include <fstream>
#include <iostream>
#include "Image.h"
using namespace std;

Image::Image(int indice){
    unsigned char buffer[784], c;
    int label;
    ifstream f("/Users/plu/Desktop/C++/train-labels-idx1-ubyte",
               ios::in | ios::binary);
    ifstream fichier2(
            "/Users/plu/Desktop/C++/MNIST_training/training"
            + to_string(indice), ios::in | ios::binary);
    if (!f.is_open())
        cout << "Impossible d'ouvrir le fichier label  !" << endl;
    else {
        f.seekg(8 + indice, f.cur);
        f.read((char*) &c, sizeof(char));
        label = (int) c;
    }
    f.close();
    c= '0' + 1;
    char lab = '0' + label;
    set_label(lab);

    if (!fichier2.is_open()) {
        cout << "ERREUR: Impossible d'ouvrir le fichier de l'image " << indice
             << endl;
    } else {
        fichier2.seekg(1078, fichier2.cur);
        for (int i = 0; i < 784; i++) {
            fichier2.read((char*) &buffer[i], sizeof(char));
            pixel[i] = (double) buffer[i];
        }
        fichier2.close();
    }
}

double Image::operator[](int j){
    return pixel[j];
}
