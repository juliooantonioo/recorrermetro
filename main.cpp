#include <cstdlib>
#include "funciones.h"
#include <iostream>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    estacion infoinicio,infofin;
    int ruta[13];
    int combinaciones[13][13]={
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,6,10,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,6,-1,1,3,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,10,1,-1,5,-1,-1,-1,4,-1,-1,-1,-1},
    {-1,-1,3,5,-1,4,-1,4,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,4,-1,1,4,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,1,-1,-1,-1,-1,12,-1,-1},
    {-1,-1,-1,-1,4,4,-1,-1,2,-1,-1,8,-1},
    {-1,-1,-1,4,-1,-1,-1,2,-1,8,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,8,-1,5,-1,-1},
    {-1,-1,-1,-1,-1,-1,12,-1,-1,5,-1,1,-1},
    {-1,-1,-1,-1,-1,-1,-1,8,-1,-1,1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};
    estacion listacombinaciones[13],entreorigen,entredestino;
    string nombresredmetro[6][30];
    infocombis(listacombinaciones);
    int izqi=-1,izqf=-1,deri=-1,derf=-1;
    if (argv[1][0]=='-' and argv[1][1]=='f'){
        iniciofinlineas(argv[3],argv[2], nombresredmetro, infoinicio , infofin);
        listacombinaciones[0]=infoinicio;
        listacombinaciones[12]=infofin;
        inicioentrenodos(listacombinaciones,entreorigen,izqi,deri);
        finentrenodos(listacombinaciones,entredestino,izqf,derf);
        agregarnodoinicio(combinaciones,entreorigen,izqi,deri,infoinicio);
        agregarnodofin(combinaciones,entredestino,izqf,derf,infofin);
        caminomascorto(combinaciones,ruta);
        obtenerruta(ruta,listacombinaciones,nombresredmetro);
    }
    if (argv[1][0]=='-' and argv[1][1]=='v'){
        cout<<"Julio Vallejos Apablaza"<<endl;
        cout<<"Antonio Rodriguez Mejias"<<endl;
    }
    return 0;
}

