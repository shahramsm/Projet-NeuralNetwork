
#include <iostream>
#include "Input.h"
#include "Image.h"
#include "Iris.h"

#include "Fonctions.h"
#include "NN.h"

#include "Apprentissage.h"

using namespace std;



int main() {
/*
	Iris ir(22);
	cout<<ir[3]<<endl;
	cout<<ir.get_label()<<endl;

	Image im(49);
	cout<<im[467]<<endl;
	cout<<im.get_label()<<endl;
*/

    Sigmoide s;
    Tanh  t;

	NN1 n1(4,3,&s);
	Apprentissage<Iris,150> ap1(&n1);
	ap1.apprendre_base(15000,0.1);
    cout<<"test de réseaux de neurones sans couche cachée pour des fleurs Iris :"<<endl;
	cout<<"le nombre de fleurs bien classifier parmis 150 fleurs "<<ap1.evaluer()<<endl;
    cout<<endl;

	NN1 n2(784,10,&s);
	Apprentissage<Image,60000> ap2(&n2);
	ap2.apprendre_base(100000,1);
    cout<<"test de réseaux de neurones sans couche cachée pour des images :"<<endl;
	cout<<"le nombre d'image bien classifier parmis 60 000 images : "<<ap2.evaluer()<<endl;
    cout<<endl;


	NN2 n3(4,3,3,&s);
	Apprentissage2<Iris,NN2,150> ap3(&n3);
	ap3.apprendre_base(10000,0.01);
    cout<<"test de réseaux de neurones avec une couche cachée (contenant 3 noeuds) pour des fleurs Iris :"<<endl;
	cout<<"le nombre de fleurs bien classifier parmis 150 fleurs :"<<ap3.evaluer()<<endl;
    cout<<endl;


// attention !!! le nombre de perceptrons de la couche caché doit être supérieur à celui de la couche sortie
    NN2 n4(784,10,20,&s);
    Apprentissage2<Image,NN2,60000>  ap4(&n4);
    ap4.apprendre_base(100000,0.1);
    cout<<"test de réseaux de neurones avec une couche cachée (contenant 20 noeuds) pour des images :"<<endl;
    cout<<"le nombre d'image bien classifier parmis 60 000 images : "<<ap4.evaluer()<<endl;
  
}
