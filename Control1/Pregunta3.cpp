#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    ostringstream mensaje;
    int valor;

    cout<<"Ingrese el numero a convertir: ";cin>>valor;
    mensaje<<valor;
    cout<<"En string: "<<mensaje.str();
    cout<<"\nFin del programa";
}