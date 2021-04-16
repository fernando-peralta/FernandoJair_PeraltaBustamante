#include <iostream>
#include <string>
using namespace std;

int main(){
    string nombre, apellido, concatenado;
    cout<<"Ingrese solo el nombre: ";getline(cin,nombre); //Ingresa nombre
    cout<<"Ingrese solo el apellido: ";getline(cin,apellido); //Ingresa apellido
    concatenado+=nombre+" "+apellido; //se concatenan
    cout<<"Concatenado: "<<concatenado;
    cout<<"\nFin del programa";
}