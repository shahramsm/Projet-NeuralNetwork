//#include "Apprentissage.h"

template <class T, int s> Apprentissage<T,s>::Apprentissage(NN1 *n){
    this->n=n;
}

template<class T, int s> void Apprentissage<T, s>::apprendre_base(int k, double learning_rate) {
    int min=s-s;
    int max = s-1;
    srand(time(NULL));

    for (int i = 0; i < k; i++) {
        int rd= rand()%(max-min+1) + min;
        //	cout<<rd<<endl;
        T in(rd);
        n->apprentissage(in,learning_rate) ;
    }
}

template<class T, int s> int Apprentissage<T, s>::evaluer() {
    int cmpt = 0;
//	T input;
    for (int i = 0; i < s; i++) {
        T input(i);
        char c= input.get_label();
        if(n->evaluation(input)==c){
            cmpt++;
        }
    }
    return cmpt;
}



template <class T,class U, int s> Apprentissage2<T,U,s>::Apprentissage2(U *n){
    this->n=n;
}

template<class T, class U, int s> void Apprentissage2<T,U, s>::apprendre_base(int k, double learning_rate) {
    int min=s-s;
    int max = s-1;
    srand(time(NULL));

    for (int i = 0; i < k; i++) {
        int rd= rand()%(max-min+1) + min;
        T in(rd);
        n->apprentissage(in,learning_rate) ;
    }
}

template<class T,class U, int s> int Apprentissage2<T,U, s>::evaluer() {
    int cmpt = 0;
//  T input;
    for (int i = 0; i < s; i++) {
        T input(i);
        char c= input.get_label();
        if(n->evaluation(input)==c){
            cmpt++;
        }
    }
    return cmpt;
}

