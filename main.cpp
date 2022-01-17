#include<iostream>
using namespace std;
#include "funciones.h"

int main () {
    system ("color 57");
    ST_PLAYER jugadores[MAX_JUG];
    int menu;
    bool entrada=true;
    ST_MAX max={"",-1};
    int iAux=-1;

    while (entrada==true) {

        impMsjMenu();
        cin>>menu;
        clrscr();

        switch (menu){

            case 1:
                iAux=juegoEntre2(jugadores);
                evaluarPuntajeMax(jugadores,max.puntaje,iAux,max.nombre);
                pause();
                clrscr();
                break;

            case 2:
                cout<<"En contruccion..."<<endl;
                pause();
                clrscr();
                break;

            case 3:
                iAux=juegoContraPC(jugadores);
                evaluarPuntajeMax(jugadores,max.puntaje,iAux,max.nombre);
                pause();
                clrscr();
                break;

            case 4:
                iAux=juegoSimulado(jugadores);
                evaluarPuntajeMax(jugadores,max.puntaje,iAux,max.nombre);
                pause();
                clrscr();
                break;

            case 5:
                impPuntuacionMax(max);
                pause();
                clrscr();
                break;

            case 6:
                cout<<"\n\tADIOS!!!"<<endl;
                entrada=false;
                break;

            default:
                cout<<"\n\tOpcion incorrecta, vuelva a intentarlo"<<endl;
                pause();
                clrscr();
                break;
        }
    }


    pause();
    return 0;
}