#include <iostream>

using namespace std;

string rail_fance_cifrado(string mensaje, int clave){//funcion de Cifrado
    string mensajecifrado;
    int aux=0, aux2=0;
    for(int i=0; i<(mensaje.length())/clave; i++){//recorre el texto la cantidad de largo entre clave simulando las filas
        for (int j = 0; j < clave; j++)
        {
            aux=clave*j; //añadira las letras que se encuentran enlas posiciones entre claves
            mensajecifrado+=mensaje[i+aux]; //los añade al string
            aux++;
        }
        aux2++;
    }

    return mensajecifrado;
}

string rail_fance_descifrado(string mensaje, int clave){ //funcion de descifrado realiza lo mismo que el cifrado
    string mensajedescifrado;
    int aux=0, aux2=0;
    for(int i=0; i<(mensaje.length())/clave; i++){
        for (int j = 0; j < clave; j++)
        {
            aux=clave*j;
            mensajedescifrado+=mensaje[i+aux];
            aux++;
        }
        aux2++;
    }

    return mensajedescifrado;
}



int main(){
    int filas,opcion;
    string mensaje;

    cout<<"\nIngrese el mensaje: "; getline(cin,mensaje);
    cout<<"\nIngrese el numero de filas: "; cin>>filas;


    cout<<"\nQue opcion desea realizar";
    cout<<"\n1. Cifrado.";
    cout<<"\n2. Descifrado.";
    cout<<"\nopcion: ";cin>>opcion;

    switch (opcion)
    {
    case 1:
        cout<<rail_fance_cifrado(mensaje, filas);
        break;
    
    case 2:
        cout<<rail_fance_descifrado(mensaje, filas);
        break;
    }

    cout<<"Fin del programa";
}