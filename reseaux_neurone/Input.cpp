#include "Input.h"

char Input::get_label(){
    return Label;
}
void Input::set_label(char c) {
    Label = c;
}

Input_intermediaire::Input_intermediaire(char c){
    set_label(c);
}

void Input_intermediaire::add(double d){
    a.push_back(d);
}

double Input_intermediaire::operator[](int i){
    return a.at(i);
}
