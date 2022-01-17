#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cstring>
#include <windows.h>
using namespace std;

#define MAX_JUG 10

// ESTRUCTURAS
typedef struct {
    string nombre;
    char dado6;
    char dado5;
    char dado4;
    int carga;
    int cantTiradas;
    int puntaje;
    int cantUltimaRonda;
} ST_PLAYER;

typedef struct {
    string nombre;
    int puntaje;
} ST_MAX;

enum Color{
cNEGRO=0,
cAZUL=1,
cVERDE=2,
cCIAN=3,
cROJO=4,
cMAGENTA=5,
cMARRON=6,
cGRIS_CLARO=7,
cGRIS=8,
cAZUL_CLARO=9,
cVERDE_CLARO=10,
cCIAN_CLARO=11,
cROJO_CLARO=12,
cMAGENTA_CLARO=13,
cAMARILLO=14,
cBLANCO=15
};

// DECLARACION DE FUNCIONES Y PROCEDIIENTOS
void clrscr(void); // LIMPIAR PANTALLA
void pause(void); // PAUSA SIN MENSAJE
void gotoxy(short x, short y);// COLOCA CURSOR EN DET. LUGAR
void textcolor(short colorTexto, short colorFondo);//DEFINE COLORES
void dado(short iniX, short iniY, short ancho, short alto, short colorLinea, short colorFondo);//IMPRIME CUBO
void cinInt (string mensaje, int &dato); // CIN INT
void cargarAleatorio(int v[], int tam, int limite);//CARGA VECTOR CON NUMEROS RANDOM DEL 1 AL 6
void imprimirVec(int v[], int tam); //IMPRIME VECTOR
void algorOrdBurbujeo(int arr[], int n);//ORDENA DE MAYOR A MENOR
int busqBinaria (int vDados[],int cantidadDadosDeTirada, int valorBusq); //BUSQUEDA BINARIA
void actializarDatos (int vDados[], ST_PLAYER jug[], int jugador, int &cantidadDadosDeTirada, int nroTirada, bool &pararTiradas);//ACTUALIZA DATOS DE TIRADA EN JUGADORES
void cuentaPuntaje (ST_PLAYER jug[], int jugador);//CUENTA PUNTOS
int resultado (ST_PLAYER jug2[]);// DEVUELVE POSICION DEL GANADOR
void impMsjEntreJugadas(int ronda, ST_PLAYER jug2[], int jugAct);//IMPRIME MENSAJE ENTRE RONDAS
void impMsjHeader(int ronda, ST_PLAYER jug2[], int jugAct, int tirada);//IMPRIME MENSAJE HEADER
void impMsjObjetivos (ST_PLAYER jug2[], int jugAct);//IMPRIME MENSAJE OBJETIVOS
void impResultado (ST_PLAYER jug2[], int iPosGan);// IMPRIME RESULTADO
void impMsjMenu(int dato);//IMPRIME MENSAJE BIENVENIDA
void cargarManual(int v[], int tam);//CARGA VECTOR MANUAL
void evaluarPuntajeMax(ST_PLAYER jugadores[MAX_JUG],ST_PLAYER max, int iAux);//EVALUA PUNTAJE MAX
void impPuntuacionMax(ST_PLAYER max);//IMPRIME MAX

//DESARROLLO DE FUNCIONES Y PROCEDIMIENTOS

void clrscr(void){
    system("cls");
}

void pause(void){
    system("pause >nul");
}

// COLOCA CURSOR EN DET. LUGAR
void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

//DEFINE COLORES
void textcolor(short colorTexto, short colorFondo){
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

//IMPRIME CUBO
void dado(short iniX, short iniY, short ancho, short alto, short colorLinea, short colorFondo){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 218;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 191;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 192;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 217;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 196;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 179;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

// CIN INT
void cinInt (string mensaje, int &dato) {
    cout<<mensaje<<endl;
    cin>>dato;

    return;
}

// CIN STRING
void cinString (string mensaje, string dato) {
    cout<<mensaje<<endl;
    cin>>dato;

    return;
}

//IMPRIME MENSAJE BIENVENIDA
void impMsjMenu(){
    cout<<" ____________________________________________________________"<<endl;
    cout<<"\n\n\n\tBIENVENIDOS A SEIS, CINCO, CUATRO\n\n\n";
    cout<<" ____________________________________________________________\n"<<endl;
    cout<<"Ingrese:\n\t1-Juego nuevo entre dos participantes\n\t2-Juego nuevo entre X participantes\n\t3-Juego contra la maquina\n\t4-Modo simulado, ingresa la tirada manualmente\n\t5-Mostrar puntuacion mas alta\n\t6-Salir\n";
    cout<<"Entrada: ";

    return;
}

//CARGA VECTOR CON NUMEROS RANDOM DEL 1 AL 6
void cargarAleatorio(int v[], int tam, int limite){

    int i;
    srand(time(NULL));

    for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
    }

    return;
}

//IMPRIME VECTOR *DADO*
void imprimirVec(int v[], int tam){
    int x=0;

    for (int i=0; i<tam; i++) {

        dado(6+x,10,8,4,cBLANCO, cMAGENTA);
        x+=9;
    }

    x=0;

    for (int i=0; i<tam; i++) {

        SetConsoleOutputCP(65001);

        if (v[i]==6) {
            gotoxy(8+x,11);printf("●\n");gotoxy(12+x,11);printf("●\n");
            gotoxy(8+x,12);printf("●\n");gotoxy(12+x,12);printf("●\n");
            gotoxy(8+x,13);printf("●\n");gotoxy(12+x,13);printf("●\n");
        }

        if (v[i]==5) {
            gotoxy(8+x,11);printf("●\n");gotoxy(12+x,11);printf("●\n");
            gotoxy(10+x,12);printf("●\n");
            gotoxy(8+x,13);printf("●\n");gotoxy(12+x,13);printf("●\n");
        }

        if (v[i]==4) {
            gotoxy(8+x,11);printf("●\n");gotoxy(12+x,11);printf("●\n");
            gotoxy(8+x,13);printf("●\n");gotoxy(12+x,13);printf("●\n");
        }

        if (v[i]==3) {
            gotoxy(8+x,11);printf("●\n");
            gotoxy(10+x,12);printf("●\n");
            gotoxy(12+x,13);printf("●\n");
        }

        if (v[i]==2) {
            gotoxy(8+x,11);printf("●\n");
            gotoxy(12+x,13);printf("●\n");
        }

        if (v[i]==1) {
            gotoxy(10+x,12);printf("●\n");
        }

        x+=9;
    }

    SetConsoleOutputCP(850);
    cout<<"\n\n\n";

    return;
}

//ORDENA DE MAYOR A MENOR
void algorOrdBurbujeo(int arr[], int n){
    int aux;
    int i=0;
    bool ordenado = false;

    while (i < n && !ordenado){

        ordenado= true;

        for (int j = 0; j < n-i-1 ; j++){

            if (arr[j]<arr[j+1]){
                aux = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=aux;
                ordenado = false;
            }
        }

        i++;
    }

}

//BUSQUEDA BINARIA
int busqBinaria (int vDados[],int cantidadDadosDeTirada, int valorBusq) {
    int inicio=0;
    int fin = cantidadDadosDeTirada -1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        //si el elemento es el del medio, devolvemos la posicion
        if (vDados[mitad]==valorBusq){
            return mitad;
        }

         //si el elemento es mayor entonces solo puede estar en la primera mitad
         if ( vDados[mitad]<valorBusq){
             fin=mitad - 1; //Cambio el limite superior
         }else{
             inicio=mitad+1; //Cambio el limite inferior
         }
    }

    return -1;
}

//ACTUALIZA DATOS DE TIRADA EN JUGADORES
void actializarDatos (int vDados[], ST_PLAYER jug[], int jugador, int &cantidadDadosDeTirada, int nroTirada, bool &pararTiradas) {
    int sum=0;
    int cantProxTir;
    int iDeCopiado6=-1;
    int iDeCopiado5=-1;
    int iDeCopiado4=-1;
    char resp=0;

    //copio cant en otra variable para que no me modifique la dimension actual del vec
    cantProxTir=cantidadDadosDeTirada;

    if (jug[jugador].dado6!='x') {
        iDeCopiado6=busqBinaria(vDados, cantidadDadosDeTirada,6);
        if (iDeCopiado6!=-1) {
            jug[jugador].dado6='x';
            cantProxTir--;
        }
    }//busca el 6 y actualiza datos si lo encuantra

    if (jug[jugador].dado5!='x' && jug[jugador].dado6=='x') {
        iDeCopiado5=busqBinaria(vDados, cantidadDadosDeTirada,5);
        if (iDeCopiado5!=-1) {
            jug[jugador].dado5='x';
            cantProxTir--;
        }
    }//busca el 5, si el 6 ya está, y actualiza datos si lo encuantra

    if (jug[jugador].dado4!='x' && jug[jugador].dado6=='x'&& jug[jugador].dado5=='x') {
        iDeCopiado4=busqBinaria(vDados, cantidadDadosDeTirada,4);
        if (iDeCopiado4!=-1) {
            jug[jugador].dado4='x';
            cantProxTir--;
        }
    }//busca el 4, si el 5 y 6 ya están, y actualiza datos si lo encuantra

    // PARA LA CARGA -que no es ultima tirada //
    if (nroTirada!=2 && jug[jugador].dado4=='x' &&  jug[jugador].dado5=='x' && jug[jugador].dado6=='x'){

        cout<<"Desea tirar una vez mas para mejorar puntaje de la carga? (S para si y N para no)"<<endl;
        cin>>resp;

        if (resp=='N'||resp=='n') {
            pararTiradas=true;

            for (int j=0; j<cantidadDadosDeTirada; j++) {
                if (iDeCopiado4!=j && iDeCopiado5!=j && iDeCopiado6!=j) {
                    sum+=vDados[j];
                }
            }
        }
    }//Pregunta por la carga y actualiza según respuesta

    // PARA LA CARGA -que es ultima tirada //
    if (nroTirada==2 && jug[jugador].dado4=='x' &&  jug[jugador].dado5=='x' && jug[jugador].dado6=='x'){

        for (int j=0; j<cantidadDadosDeTirada; j++) {
            if (iDeCopiado4!=j && iDeCopiado5!=j && iDeCopiado6!=j) {
                sum+=vDados[j];
            }
        }
    }//si es ultima tirada y tiene 4,5 y 6 sumo carga

    cantidadDadosDeTirada=cantProxTir;

    jug[jugador].carga=sum;

    return;
}

//QUIEN GANA RONDA
void cuentaPuntaje (ST_PLAYER jug[], int jugadores) {

    if (jug[1].carga>jug[0].carga || (jug[1].carga==jug[0].carga && jug[1].cantUltimaRonda<jug[0].cantUltimaRonda)) {
        jug[1].puntaje++;
        cout<<"\n\tEl jugador "<<jug[1].nombre<<" gana la ronda\n";

    } else if (jug[0].carga>jug[1].carga || (jug[0].carga==jug[1].carga && jug[0].cantUltimaRonda<jug[1].cantUltimaRonda)) {
        jug[0].puntaje++;
        cout<<"\n\tEl jugador "<<jug[0].nombre<<" gana la ronda\n";
    } else {
        cout<<"\n\tHubo un empate, nadie se lleva puntos!!!\n";
    }

    return;
}

// DEVUELVE POSICION DEL GANADOR
int resultado (ST_PLAYER jug2[]) {

    if (jug2[1].puntaje>jug2[0].puntaje || (jug2[1].puntaje==jug2[0].puntaje && jug2[1].cantTiradas>jug2[0].cantTiradas)) {
        return 1;

    } else if (jug2[0].puntaje>jug2[1].puntaje || (jug2[0].puntaje==jug2[1].puntaje && jug2[0].cantTiradas>jug2[1].cantTiradas)) {
        return 0;

    }else{
        return -1;
    }
}

//DIBUJA RECUADRO
void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea, short colorFondo){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 218;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 191;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 192;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 217;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 45;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 221;
            }

            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

//IMPRIME MENSAJE ENTRE RONDAS
void impMsjEntreJugadas(int ronda, ST_PLAYER jug2[], int jugAct) {

    recuadro(24, 6, 50, 14, cBLANCO, cMAGENTA);

    gotoxy(43,8);cout<<"RONDA Nro "<<ronda+1<<endl;
    gotoxy(38,10);cout<<"PROXIMO TURNO: "<<jug2[jugAct].nombre<<endl;
    gotoxy(26,13);cout<<"-----------------------------------------------"<<endl;
    gotoxy(40,15);cout<<"PUNTAJE "<<jug2[jugAct].nombre<<": "<<jug2[jugAct].puntaje<<" PUNTOS"<<endl;
    gotoxy(37,17);cout<<"CANTIDAD DE TIRADAS: "<<jug2[jugAct].cantTiradas<<endl;


    return;
}

// MENSAJE HEADER
void impMsjHeader(int ronda, ST_PLAYER jug2[], int jugAct, int tirada) {

    cout<<"\n----------------------------------------------------------------------------------\n"<<endl;
    cout<<" TURNO DE "<<jug2[jugAct].nombre<<" | ";
    cout<<"RONDA Nro "<<ronda+1<<" | ";
    cout<<"PUNTAJE ACUMULADO: "<<jug2[jugAct].puntaje<<" puntos";
    cout<<"\n----------------------------------------------------------------------------------\n"<<endl;
    cout<<" TIRADA Nro "<<tirada+1;
    cout<<"\n----------------------------------------------------------------------------------\n"<<endl;

    return;
}

// MENSAJE OBJETIVOS
void impMsjObjetivos (ST_PLAYER jug2[], int jugAct) {

    cout<<"\n\n *******************\n";
    cout<<"|    Objetivos      |\n";
    cout<<"-------------------\n";
    cout<<"| Barco:       | "<<jug2[jugAct].dado6<<" |\n";
    cout<<"| Capitan:     | "<<jug2[jugAct].dado5<<" |\n";
    cout<<"| Tripulacion: | "<<jug2[jugAct].dado4<<" |\n";
    cout<<" *******************\n";

    return;
}

// IMPRIME RESULTADO
void impResultado (ST_PLAYER jug2[], int iPosGan) {

    if (iPosGan>-1) {
        cout<<"**************************************\n";
        cout<<"|             GANADOR                |\n";
        cout<<"--------------------------------------\n";
        cout<<"| Jugador:         | "<<jug2[iPosGan].nombre<<endl;
        cout<<"| Puntaje :        | "<<jug2[iPosGan].puntaje<<endl;
        cout<<"| Tiradas:         | "<<jug2[iPosGan].cantTiradas<<endl;
        cout<<"**************************************\n";
        gotoxy(37,3);cout<<"|";
        gotoxy(37,4);cout<<"|";
        gotoxy(37,5);cout<<"|";
    }


    if (iPosGan==-1) {
        cout<<"**************************************\n";
        cout<<"|         ES UN EMPATE !!!!!         |\n";
        cout<<"**************************************\n";
    }

    return;
}

// LIMPIAR ESTRUCTURA
void limpiarEstructura(ST_PLAYER jug2[MAX_JUG]){

    jug2[0]={"",'-','-','-',0,0,0,0};
    jug2[1]={"",'-','-','-',0,0,0,0};
    jug2[2]={"",'-','-','-',0,0,0,0};
    jug2[3]={"",'-','-','-',0,0,0,0};
    jug2[4]={"",'-','-','-',0,0,0,0};
    jug2[5]={"",'-','-','-',0,0,0,0};
    jug2[6]={"",'-','-','-',0,0,0,0};
    jug2[7]={"",'-','-','-',0,0,0,0};
    jug2[8]={"",'-','-','-',0,0,0,0};
    jug2[9]={"",'-','-','-',0,0,0,0};
}

//CARGA VECTOR MANUAL
void cargarManual(int v[], int tam){
    int aux;
    int cantPos=0;

    while (cantPos<tam) {
        cout<<"Ingrese el valor del dado"<<endl;
        cin>>aux;

        if (0<aux && aux<7) {
            v[cantPos]=aux;
            cantPos++;
        } else {
            cout<<"Valor incorrecto, vuelva a intentarlo"<<endl;
        }
    }

    return;
}

//ACTUALIZA DATOS DE TIRADA EN PC
void actializarDatosPC (int vDados[], ST_PLAYER jug[], int jugador, int &cantidadDadosDeTirada, int nroTirada, bool &pararTiradas) {
    int sum=0;
    int cantProxTir;
    int iDeCopiado6=-1;
    int iDeCopiado5=-1;
    int iDeCopiado4=-1;
    char resp=0;

    //copio cant en otra variable para que no me modifique la dimension actual del vec
    cantProxTir=cantidadDadosDeTirada;

    if (jug[jugador].dado6!='x') {
        iDeCopiado6=busqBinaria(vDados, cantidadDadosDeTirada,6);
        if (iDeCopiado6!=-1) {
            jug[jugador].dado6='x';
            cantProxTir--;
        }
    }//busca el 6 y actualiza datos si lo encuantra

    if (jug[jugador].dado5!='x' && jug[jugador].dado6=='x') {
        iDeCopiado5=busqBinaria(vDados, cantidadDadosDeTirada,5);
        if (iDeCopiado5!=-1) {
            jug[jugador].dado5='x';
            cantProxTir--;
        }
    }//busca el 5, si el 6 ya está, y actualiza datos si lo encuantra

    if (jug[jugador].dado4!='x' && jug[jugador].dado6=='x'&& jug[jugador].dado5=='x') {
        iDeCopiado4=busqBinaria(vDados, cantidadDadosDeTirada,4);
        if (iDeCopiado4!=-1) {
            jug[jugador].dado4='x';
            cantProxTir--;
        }
    }//busca el 4, si el 5 y 6 ya están, y actualiza datos si lo encuantra

    // PARA LA CARGA -//juega hasta cargar más de 6 o hasta que no le queden tiradas//
    if (nroTirada<2 && jug[jugador].dado4=='x' &&  jug[jugador].dado5=='x' && jug[jugador].dado6=='x'){

        for (int j=0; j<cantidadDadosDeTirada; j++) {
            if (iDeCopiado4!=j && iDeCopiado5!=j && iDeCopiado6!=j) {
                sum+=vDados[j];
            }
        }
        if (sum>=6) {
            pararTiradas=true;
        }

    }

    cantidadDadosDeTirada=cantProxTir;

    jug[jugador].carga=sum;

    return;
}

void evaluarPuntajeMax(ST_PLAYER jugadores[MAX_JUG], int &max, int iAux, string &nombre){

    if (iAux>-1 && jugadores[iAux].puntaje>max) {

        max=jugadores[iAux].puntaje;
        nombre=jugadores[iAux].nombre;
    }

    return;
}

void impPuntuacionMax(ST_MAX max){

    if (max.puntaje != -1) {
        cout<<"**************************************\n";
        cout<<"|El puntaje MAXIMO es: "<<max.puntaje<<endl;
        cout<<"|Jugador: "<<max.nombre<<endl;
        cout<<"**************************************\n";
        gotoxy(37,2);cout<<"|";
        gotoxy(37,3);cout<<"|";
    } else{
        cout<<"**************************************\n";
        cout<<"|                                    |\n";
        cout<<"|Aun no hay puntaje MAXIMO disponible|"<<endl;
        cout<<"|                                    |\n";
        cout<<"**************************************\n";
    }

    return;
}

///////------JUEGOS-------////////

int juegoEntre2 (ST_PLAYER jug2[MAX_JUG]) {

    int cantTiradas=3;
    int vDados[5]={0};
    int cantDados=5;
    int rondas;
    bool pararTiradas=false;
    int i=0;
    int posGanador;

    limpiarEstructura(jug2);

    cinInt("Ingrese la cantidad de rondas que desea jugar", rondas);
    cout<<"Ingrese el nombre del primer jugador"<<endl;
    cin>>jug2[0].nombre;

    cout<<"Ingrese el nombre del segundo jugador"<<endl;
    cin>>jug2[1].nombre;

    clrscr();

    for (int k=0; k<rondas; k++) {

        for (int j=0; j<2; j++) {

            // MENSAJE ENTRE RONDAS
            impMsjEntreJugadas(k,jug2,j);
            pause();
            clrscr();

            while (i<3 && pararTiradas==false){

                // MENSAJE HEADER
                impMsjHeader(k,jug2,j,i);

                cargarAleatorio(vDados,cantDados,6);

                // IMP DADOS
                imprimirVec(vDados,cantDados);
                pause();

                algorOrdBurbujeo(vDados,cantDados);

                actializarDatos(vDados,jug2,j,cantDados, i, pararTiradas);

                // IMP OBJETIVOS
                impMsjObjetivos(jug2, j);
                cout<<"\n\t~ CARGA = "<<jug2[j].carga<<" ~\n";

                jug2[j].cantTiradas++;
                i++;

                pause();
                clrscr();
            }
            jug2[j].cantUltimaRonda=i;

            //BLANQUEO DE VARIABLES PARA PROXIMO TURNO DE JUGADOR
            jug2[j].dado6='-';
            jug2[j].dado5='-';
            jug2[j].dado4='-';

            pararTiradas=false;
            i=0;
            cantDados=5;
        }

        cuentaPuntaje(jug2,2);
        pause();
        clrscr();
    }

    posGanador=resultado(jug2);
    impResultado(jug2, posGanador);

    pause();
    return posGanador;
}

int juegoSimulado (ST_PLAYER jug2[MAX_JUG]) {
    int cantTiradas=3;
    int vDados[5]={0};
    int cantDados=5;
    int rondas;
    bool pararTiradas=false;
    int i=0;
    int posGanador;

    limpiarEstructura(jug2);

    cinInt("Ingrese la cantidad de rondas que desea jugar", rondas);

    cout<<"Ingrese el nombre del primer jugador"<<endl;
    cin>>jug2[0].nombre;

    cout<<"Ingrese el nombre del segundo jugador"<<endl;
    cin>>jug2[1].nombre;

    clrscr();

    for (int k=0; k<rondas; k++) {

        for (int j=0; j<2; j++) {

            // MENSAJE ENTRE RONDAS
            impMsjEntreJugadas(k,jug2,j);
            pause();
            system("cls");

            while (i<3 && pararTiradas==false){

                // MENSAJE HEADER
                impMsjHeader(k,jug2,j,i);

                cargarManual(vDados,cantDados);
                system("cls");
                impMsjHeader(k,jug2,j,i);

                // IMP DADOS
                imprimirVec(vDados,cantDados);
                cout<<endl;
                pause();

                algorOrdBurbujeo(vDados,cantDados);

                actializarDatos(vDados,jug2,j,cantDados, i, pararTiradas);

                // IMP OBJETIVOS
                impMsjObjetivos(jug2, j);
                cout<<"\n\t~ CARGA = "<<jug2[j].carga<<" ~\n";

                jug2[j].cantTiradas++;
                i++;

                pause();
                system("cls");
            }

            jug2[j].cantUltimaRonda=i;

            //BLANQUEO DE VARIABLES PARA PROXIMO TURNO DE JUGADOR
            jug2[j].dado6='-';
            jug2[j].dado5='-';
            jug2[j].dado4='-';

            //BLANQUEO DE VARIABLES PARA CAMBIAR DE JUGADOR
            pararTiradas=false;
            i=0;
            cantDados=5;
        }
        cuentaPuntaje(jug2,2);
        pause();
        clrscr();
    }

    posGanador=resultado(jug2);
    impResultado(jug2, posGanador);

    pause();
    return posGanador;
}

int juegoContraPC (ST_PLAYER jug2[MAX_JUG]) {
    int cantTiradas=3;
    int vDados[5]={0};
    int dado;
    int cantDados=5;
    int rondas;
    bool pararTiradas=false;
    int i=0;
    int posGanador;

    limpiarEstructura(jug2);

    cinInt("Ingrese la cantidad de rondas que desea jugar", rondas);

    jug2[0].nombre="MAQUINA-BOB";
    cout<<"Ingrese el nombre del segundo jugador"<<endl;
    cin>>jug2[1].nombre;

    clrscr();

    for (int k=0; k<rondas; k++) {

        for (int j=0; j<2; j++) {

            // MENSAJE ENTRE RONDAS
            impMsjEntreJugadas(k,jug2,j);
            pause();
            system("cls");

            while (i<3 && pararTiradas==false){

                // MENSAJE HEADER
                impMsjHeader(k,jug2,j,i);

                cargarAleatorio(vDados,cantDados,6);

                // IMP DADOS
                imprimirVec(vDados,cantDados);
                pause();

                algorOrdBurbujeo(vDados,cantDados);

                if (j==1) {
                    actializarDatos(vDados,jug2,j,cantDados, i, pararTiradas);
                } else if (j==0) {
                    actializarDatosPC(vDados,jug2,j,cantDados, i, pararTiradas);
                }

                // IMP OBJETIVOS
                impMsjObjetivos(jug2, j);
                cout<<"\n\t~ CARGA = "<<jug2[j].carga<<" ~\n";

                jug2[j].cantTiradas++;
                i++;

                pause();
                system("cls");
            }
            jug2[j].cantUltimaRonda=i;

            //BLANQUEO DE VARIABLES PARA PROXIMO TURNO DE JUGADOR
            jug2[j].dado6='-';
            jug2[j].dado5='-';
            jug2[j].dado4='-';

            //BLANQUEO DE VARIABLES PARA CAMBIAR DE JUGADOR
            pararTiradas=false;
            i=0;
            cantDados=5;
        }
        cuentaPuntaje(jug2,2);
        pause();
        clrscr();
    }

    posGanador=resultado(jug2);
    impResultado(jug2, posGanador);

    pause();
    return posGanador;
}

#endif