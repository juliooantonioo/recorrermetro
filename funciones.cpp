#include <cstdlib>
#include "funciones.h"
#include <fstream>
#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stack>

int indiceinicial,lineainicial,indicefinal,lineafinal;
estacion linea1[30],linea2[22],linea4[23],linea4a[6],linea5[30],linea6[10];
stack <estacionrecorrida>pilarecorrido;
stack <estacionrecorrida>pilamejor;
combinacion l1[5],l2[4],l4[3],l4a[2],l5[5],l6[3];

void ordenardatos(){    
    string estacioninicial="LA", estacionfinal="VMA";
    int cont=0, cont2=1;
    ifstream ficherometro;
    ficherometro.open("estaciones.txt");
    while (cont!=118){
        if (cont<27){
            getline(ficherometro,linea1[cont2-1].nombre);
            if ((coincide(linea1[cont2-1],estacioninicial))){
                indiceinicial=cont2-1;
                lineainicial=1;}
            if (coincide(linea1[cont2-1],estacionfinal)){
                indicefinal=cont2-1;
                lineafinal=1; 
            }
            if (cont==26){
                cont2=0;
            }
        }
        if (cont>=27 and cont<49){
            getline(ficherometro,linea2[cont2-1].nombre);
            if (coincide(linea2[cont2-1],estacioninicial)){
                indiceinicial=cont2-1;
                lineainicial=2;}
            if (coincide(linea2[cont2-1],estacionfinal)){
                indicefinal=cont2-1;
                lineafinal=2; 
            }
            if (cont==48){
                cont2=0;
            }
        }
        if (cont>=49 and cont<72){
            getline(ficherometro,linea4[cont2-1].nombre);
            if (coincide(linea4[cont2-1],estacioninicial)){
                indiceinicial=cont2-1;
                lineainicial=4;}
            if (coincide(linea4[cont2-1],estacionfinal)){
                indicefinal=cont2-1;
                lineafinal=4; 
            } 
            if (cont==71){
                cont2=0;
            }
        }
        if (cont>=72 and cont<78){
            getline(ficherometro,linea4a[cont2-1].nombre);
            if (coincide(linea4a[cont2-1],estacioninicial)){
                indiceinicial=cont2-1;
                lineainicial=44;}
            if (coincide(linea4a[cont2-1],estacionfinal)){
                indicefinal=cont2-1;
                lineafinal=44; 
            }
            if (cont==77){
                cont2=0;
            }
        }
        if (cont>=78 and cont<108){
            getline(ficherometro,linea5[cont2-1].nombre);
            if (coincide(linea5[cont2-1],estacioninicial)){
                indiceinicial=cont2-1;
                lineainicial=5;}
            if (coincide(linea5[cont2-1],estacionfinal)){
                indicefinal=cont2-1;
                lineafinal=5; 
            }
            if (cont==107){
                cont2=0;
            }
        }
        if (cont>=108 and cont<118){
            getline(ficherometro,linea6[cont2-1].nombre);
            if (coincide(linea6[cont2-1],estacioninicial)){
                indiceinicial=cont2-1;
                lineainicial=6;}
            if (coincide(linea6[cont2-1],estacionfinal)){
                indicefinal=cont2-1;
                lineafinal=6; 
            } 
            }
        
        cont=cont+1;
        cont2=cont2+1;
        }
    cout<<"Estacion inicial "<<indiceinicial<<endl;
    cout<<"Linea inicial "<<lineainicial<<endl;
    cout<<"Estacion final "<<indicefinal<<endl;
    cout<<"Linea final "<<lineafinal<<endl;
    ficherometro.close();
}

bool coincide(estacion actual,string estacioningresada){
    if (actual.nombre.find(estacioningresada+" ")==0){
        return true;
    }
    else{
        return false;
    }
    
}
void combinacionesposibles(){
    l1[0].indice=0,l1[0].lineaorigen=1,l1[0].indicedes=8,l1[0].lineades=5;
    l1[1].indice=10,l1[1].lineaorigen=1,l1[1].indicedes=12,l1[1].lineades=2;
    l1[2].indice=15,l1[2].lineaorigen=1,l1[2].indicedes=17,l1[2].lineades=5;
    l1[3].indice=19,l1[3].lineaorigen=1,l1[3].indicedes=9,l1[3].lineades=6;
    l1[4].indice=20,l1[4].lineaorigen=1,l1[4].indicedes=0,l1[4].lineades=4;
    l2[0].indice=0,l2[0].lineaorigen=2,l2[0].indicedes=5,l2[0].lineades=44;
    l2[1].indice=8,l2[1].lineaorigen=2,l2[1].indicedes=3,l2[1].lineades=6;
    l2[2].indice=12,l2[2].lineaorigen=2,l2[2].indicedes=10,l2[2].lineades=1;
    l2[3].indice=13,l2[3].lineaorigen=2,l2[3].indicedes=14,l2[3].lineades=5;
    l4[0].indice=0,l4[0].lineaorigen=4,l4[0].indicedes=20,l4[0].lineades=1;
    l4[1].indice=12,l4[1].lineaorigen=4,l4[1].indicedes=0,l4[1].lineades=44;
    l4[2].indice=13,l4[2].lineaorigen=4,l4[2].indicedes=29,l4[2].lineades=5;
    l4a[0].indice=0,l4a[0].lineaorigen=44,l4a[0].indicedes=12,l4a[0].lineades=4;
    l4a[1].indice=5,l4a[1].lineaorigen=44,l4a[1].indicedes=21,l4a[1].lineades=2;
    l5[0].indice=8,l5[0].lineaorigen=5,l5[0].indicedes=0,l5[0].lineades=1;
    l5[1].indice=14,l5[1].lineaorigen=5,l5[1].indicedes=13,l5[1].lineades=2;
    l5[2].indice=17,l5[2].lineaorigen=5,l5[2].indicedes=15,l5[2].lineades=1;
    l5[3].indice=21,l5[3].lineaorigen=5,l5[3].indicedes=5,l5[3].lineades=6;
    l5[4].indice=29,l5[4].lineaorigen=5,l5[4].indicedes=13,l5[0].lineades=4;
    l6[0].indice=3,l6[0].lineaorigen=6,l6[0].indicedes=8,l6[0].lineades=2;
    l6[1].indice=5,l6[1].lineaorigen=6,l6[1].indicedes=21,l6[1].lineades=5;
    l6[2].indice=9,l6[2].lineaorigen=6,l6[2].indicedes=19,l6[2].lineades=1;
}
int recorrer(int indiceactual, int lineaactual){
    int combis;
    combis=numcombinaciones(lineaactual);
    for (int i=0;i<combis;i++){
        if ((lineaactual)==1){
        }
        if (lineaactual==lineafinal)
        {
            return abs(indiceactual-indicefinal);
        }
        else{ 
        }
    }
}

void cambiarlinea(){
}

int numcombinaciones(int lineaactual){
    if (lineaactual==1){
        combinacionesactuales=l1;
        return 5;
    }
    if (lineaactual==2){
        return 4;
    }if (lineaactual==4){
        return 3;
    }if (lineaactual==44){
        return 2;
    }if (lineaactual==5){
        return 5;
    }if (lineaactual==6){
        return 3;
    }
}






