#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string mensaje;
    int valor;

    cout<<"Ingrese el numero a convertir: ";getline(cin,mensaje);
    stringstream ss{mensaje};
    ss >> dec >> valor;
    cout<<"En int: "<<valor;
    cout<<"\nPrueba numero +20:"<<valor+20;
    cout<<"\n Fin del programa";
}