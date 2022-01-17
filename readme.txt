# GAME 654 o "Barco, capital, tripulación"

#Estructura del Programa

-main.cpp
contiene la estructura principal del juego.

-funciones.h (headers)
El funciones.h contiene en un principio el indice de funciones y procedimientos usados, a continuación su desarrollo y en último lugar, las opciones de juego que figuran en el menú.
Menú:
    ~Juego nuevo entre dos participantes: esta opción permite a dos personas realizar una partida completa de SeisCincoCuatro. Antes de comenzar a jugar, se deberá solicitar el nombre de las personas que van a jugar.

    ~Juego nuevo entre x participantes(multijugador): esta opción permite que entre 3 y 10 participantes puedan realizar una partida completa de SeisCincoCuatro. Antes de comenzar a jugar se deberá solicitar el nombre de quienes participen.

    ~Juego nuevo contra la máquina: esta opción permite realizar una partida completa de SeisCincoCuatro entre una persona y la máquina. Antes de comenzar a jugar se deberá solicitar el nombre de la persona. El nombre de la máquina puede ser ingresado por el usuario o predefinido por quien programe el juego.

    ~Modo Simulado: al utilizar este modo, el programa deberá iniciar una partida entre dos personas pero en vez de realizar el lanzamiento de forma automática, podrán ingresar manualmente los valores de cada dado en cada lanzamiento.

    ~Mostrar puntuación más alta
    Esta opción debe mostrar el nombre del participante que haya finalizado el juego con la mayor puntuación y la cantidad de tiradas que realizó.
        Nota: Cabe aclarar que el sistema no tendrá la capacidad de guardar la puntuación en un archivo. Por lo que al salir del juego, se borrarán todos los datos de puntuación.

    ~Salir: terminará la ejecición del juego.


#Reglamento del juego

SeisCincoCuatro es un juego que utiliza 5 dados de 6 caras y necesita por lo menos de 2 participantes. El objetivo del juego es conseguir en órden nuestro Barco (6), nuestro Capitán (5) y la Tripulación (4), para luego sumarizar los dados restantes que representan la carga, número que será el puntaje obtenido en la ronda.
Para lograrlo tenemos un total de 3 tiradas.
Debemos obtener primero el barco, para luego poder contratar al capitán, y tanto el barco como el capitán van a ser necesarios para que podamos acceder a la tripulación.
Las rondas finalizan cuando:
-	pasaron las tres tiradas y quien está jugando no pudo anotar puntaje.
-	quien está jugando obtiene puntaje de carga y decide no realizar más tiradas.
-	quien está jugando obtiene puntaje de carga y es su última tirada.
Una vez finalizada la ronda el jugador que haya obtenido mejor carga anotará 1 punto. En caso de empate de carga o puntaje final, ganará quien haya logrado el puntaje en menor cantidad de tiros.