
#include "Perceptron.h"
using namespace std;

Perceptron::Perceptron(int taille, Fonction_activation * fonc, char label){
    this->f=fonc;
    this->PerceptronLabel=label;
    this->delta=0;
    int max=1;
    int min=-1;
    srand(time(NULL));
    for(int i=0;i<=taille;i++){
        int rd= rand()%(max-min+1) + min;
        double d=(double)rd;
        poids.push_back(d);
    }

}

Fonction_activation * Perceptron::getF(){
    return f;
}

void Perceptron::setDelta(double delta) {
    this->delta = delta;
}

double Perceptron::get_poids(int i){
    return poids.at(i);
}

void Perceptron::insertPoid(double p, int i) {
    this->poids.at(i) = p;
}

int Perceptron::get_size(){
    return poids.size();
}


double Perceptron::forward(Input & in){
    double d=get_poids(0);
    for(int i=1; i<poids.size();i++){
        d = d + (get_poids(i)* in[i-1] );
    }
    return f->operator ()(d);

}

void Perceptron::calcul_delta(Input &in) {
    double d = get_poids(0);
    double y;
    for (int i = 1; i < poids.size(); i++) {
        d = d + (get_poids(i) * in[i - 1]);
    }
    if (in.get_label() == PerceptronLabel) {
        y = 1;
    } else {
        y = 0;
    }
    delta = (f->prim(d)) * (forward(in) - y);
//	return delta;
}

double Perceptron::get_delta(){
    return delta;
}

void Perceptron::backprop(Input & in, double learning_rate){
    for (int i=0 ;i<poids.size();i++){
        if(i==0){
            poids.at(i) = get_poids(i) - (learning_rate * get_delta());
        }
        else {
            poids.at(i) = get_poids(i) - (learning_rate * in[i-1] * get_delta());
        }
    }
}


Perceptron_cachee::Perceptron_cachee(int taille, Fonction_activation * fonc, char label, vector<Perceptron *> &pr): Perceptron(taille,fonc,label) {
    percept = pr ;
}

void Perceptron_cachee::calcul_delta(Input &in) {
    double d = get_poids(0);
    double s;
    for (int i = 1; i < get_size(); i++) {
        d = d + (get_poids(i) * in[i - 1]);
    }
    for(int i=0; i < percept.size() ; i++){
        s = (percept.at(i)->get_delta()) * (percept.at(i)->get_poids(i+1))  ;
    }
    double delta = (getF()->prim(d)) * s ;
    setDelta(delta);

}

void Perceptron_cachee::backprop(Input & in, double learning_rate){
    for (int i=0 ;i<get_size();i++){
        double p;
        if(i==0){
            p = get_poids(i) - (learning_rate * get_delta());
        }
        else {
            p = get_poids(i) - (learning_rate * in[i-1] * get_delta());
        }
        insertPoid(p, i);
    }
}
