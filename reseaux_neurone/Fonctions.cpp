
#include "Fonctions.h"



double Tanh::operator()(double x){
    return (exp(x)-exp(-x))/(exp(x)+exp(-x)) ;
}

double Tanh::prim(double x){
    return 1-(pow(this->operator ()(x),2.0));
}

double Sigmoide::operator()(double x){
    return (1/(1+exp(-x))) ;
}

double Sigmoide::prim(double x){
    return (this->operator ()(x))*(1-this->operator ()(x));
}
