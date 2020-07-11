cmake_minimum_required(VERSION 3.15)
project(reseaux_neurone)

set(CMAKE_CXX_STANDARD 14)

add_executable(reseaux_neurone main.cpp Input.cpp Input.h Iris.cpp Iris.h Image.cpp Image.h Fonctions.cpp Fonctions.h Perceptron.cpp Perceptron.h NN.cpp NN.h Apprentissage.h)