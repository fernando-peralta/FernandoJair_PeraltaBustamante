#include <iostream>
#include <string>
using namespace std;

string root13(int opcion, string mensaje){
    string alfabeto(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVMXYZ"), cifrado; //Se declara el alfabeto
    int aux=mensaje.length(), aux2;
    if (opcion==1){//Cifrado
        for (int i = 0; i < aux; i++)
        {
            aux2=alfabeto.find(mensaje[i]);//cuando encuentra una letra en la posicion deseada
            cifrado+=alfabeto[aux2+13];//se le añade 13 a la posicion y se agrega al cifrado
        }
    }if (opcion==2){//Descifrado
        for (int i = 0; i < aux; i++)
        {
            aux2=alfabeto.find(mensaje[i]);//cuando encuentra una letra en la posicion deseada
            cifrado+=alfabeto[aux2-13];//se le quita 13 a la posicion y se agrega al cifrado para obtener el descifrado
        }
    }

    return cifrado;

}

int main(){
    string mensaje1;
    int opcion1;

    cout<<"Ingrese el mensaje a cifrar: "; getline(cin,mensaje1);
    cout<<"\nDesea: \n1.Cifrar \n2.Descifrar\nOpcion: "; cin>>opcion1;
    cout<<"\nMensaje cifrado: "<<root13(opcion1,mensaje1)<<endl;

     
    cout<<"Fin del programa";
}