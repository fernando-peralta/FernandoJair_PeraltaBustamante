#include <iostream>
#include <string>
using namespace std;

int main(){
    string mensaje;
    int mitad;
    cout<<"Ingresa un mensaje: "; getline(cin,mensaje);//obtiene mensaje
    cout<<"Original: "<<mensaje; //muestra el original
    mitad=mensaje.length()/2; //calcula la mitad
    mensaje.insert(mitad, "******"); //ingresa los asteriscos
    cout<<"\nCon ****** en la mitad: "<<mensaje; //bota mensaje
    cout<<"\nFin del programa";
}