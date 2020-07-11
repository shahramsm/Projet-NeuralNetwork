#include <algorithm>
#include "NN.h"

NN1::NN1(int Input_Size , int NbrPerceptron, Fonction_activation *fonc){
    this->NbrPerceptron=NbrPerceptron;
    for(int i=0; i< NbrPerceptron; i++){
        char label='0' + i;
        NeuralNetwork.push_back(Perceptron(Input_Size, fonc ,label));
    }
}

char NN1::evaluation(Input & in){
    std::vector<double> PerceptronValue;
    for (int i=0; i<NbrPerceptron;i++){
        PerceptronValue.push_back(NeuralNetwork.at(i).forward(in));
    }
    int maxElementIndex = std::max_element(PerceptronValue.begin(),PerceptronValue.end()) - PerceptronValue.begin();
    char l='0' + maxElementIndex;
    return l;
}

void NN1::apprentissage(Input & in, double gradiant){
    for (int i=0; i < NeuralNetwork.size();i++){
        NeuralNetwork.at(i).calcul_delta(in);
        NeuralNetwork.at(i).backprop(in, gradiant);
    }
}


NN2::NN2(int Input_Size , int NbrOutputPerceptron,int NbrHiddenPerceptron, Fonction_activation *fonc){
    this->NbrOutputPerceptron=NbrOutputPerceptron;
    this->NbrHiddenPerceptron=NbrHiddenPerceptron;
    for(int i=0; i< NbrOutputPerceptron; i++){
        char label='0' + i;
        Perceptron *p=new Perceptron(NbrHiddenPerceptron, fonc ,label);
        Output_Layer.push_back(p);
    }
    for(int i=0; i<NbrHiddenPerceptron ; i++){
        char label='0';
        Hidden_Layer.push_back(Perceptron_cachee(Input_Size, fonc, label, Output_Layer));
    }
}

char NN2::evaluation(Input & in){
    std::vector<double> PerceptronValue;
    Input_intermediaire  inter(in.get_label());
    for (int i=0; i<NbrHiddenPerceptron;i++){
        inter.add(Hidden_Layer.at(i).forward(in));
    }
    for (int i=0; i<NbrOutputPerceptron;i++){
        PerceptronValue.push_back(Output_Layer.at(i)->forward(inter));
    }
    int maxElementIndex = max_element(PerceptronValue.begin(),PerceptronValue.end()) - PerceptronValue.begin();
    char l='0' + maxElementIndex;
    return l;
}

void NN2::apprentissage(Input &in, double gradiant) {
    Input_intermediaire inter(in.get_label());
    for (int i = 0; i < NbrHiddenPerceptron; i++) {
        inter.add(Hidden_Layer.at(i).forward(in));
    }
    for (int i = 0; i < NbrOutputPerceptron; i++) {
        Output_Layer.at(i)->calcul_delta(inter);
    }
    for (int i = 0; i < NbrHiddenPerceptron; i++) {
        Hidden_Layer.at(i).calcul_delta(in);

    }
    for (int i = 0; i < NbrHiddenPerceptron; i++) {
        Hidden_Layer.at(i).backprop(in, gradiant);
    }
    for (int i = 0; i < NbrOutputPerceptron; i++) {
        Output_Layer.at(i)->backprop(inter, gradiant);
    }
}