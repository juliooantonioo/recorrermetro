/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: juliooantonioo
 *
 * Created on 20 de agosto de 2018, 21:38
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>

using namespace std;

struct estacion{
    string nombre;    
};

struct combinacion{
    int indice;
    int lineaorigen;
    int indicedes;
    int lineades;
};

struct estacionrecorrida{
    int linea;
    int indice;
};



void ordenardatos();
bool coincide(estacion,string);
int recorrer(int,int);
void combinacionesposibles();
int numcombinaciones(int);
#endif /* FUNCIONES_H */
