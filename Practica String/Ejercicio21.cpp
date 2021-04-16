//Escriba un programa que introduzca una línea de texto, reemplace todos los signos de puntuación con espacios y utilice
//la función strtok de la biblioteca de cadenas estilo C para dividir el objeto string en palabras individuales (tokens).
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int main(){
    string mensaje, tokens;

    cout<<"Cual es el mensaje: "; getline(cin,mensaje); //recibe mensaje

    int posicion = mensaje.find( "." ); // busca los puntos

    while ( posicion != string::npos ) //cambia los puntos por espacios
    {
    mensaje.replace( posicion, 2, " " );
    posicion = mensaje.find( ".", posicion + 1 );
    } 

    istringstream iss(mensaje);// recibe mensaje por estringstream

    while ( getline(iss, tokens, ' ') ) //los separa.
    {
    cout << tokens << '\n';
    } 

    cout<<"Fin del programa";
}