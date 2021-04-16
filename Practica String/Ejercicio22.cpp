//Escriba un programa que introduzca una línea de texto y la imprima al revés. Use iteradores en su solución.
#include <iostream>
#include <string>
using namespace std;

int main(){
    string mensaje;
    cout<<"Ingrese el mensaje: ";getline(cin,mensaje);//recibe mensaje

    string::const_iterator iterador1 = mensaje.end(); //define el iterador para que comience en el final

    while ( iterador1 != mensaje.begin()-1 ) //hasta que no llegue al inicio
    {
    cout << *iterador1; //escribe la palabra al reves
    iterador1--; 
    }


    cout<<"\nFin del programa";
}