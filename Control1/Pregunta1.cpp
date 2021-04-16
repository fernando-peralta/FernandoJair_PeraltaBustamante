#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    string mensaje,mensajeguardado,mensajeguardado1;
    int tamanio, aux=0, aux2;
    vector<string>cadenavector;

    cout<<"1a )Ingrese el mensaje a dividir: ";getline(cin,mensaje);    
    cout<<"\n1b) Ingresa el tamanio de los bloques: ";cin>>tamanio;

    string::const_iterator iterador1 = mensaje.begin();

    aux2=tamanio-(mensaje.length()%tamanio);

    if (aux2!=0){
        for (int i = 0; i < aux2; i++)
        {
            mensaje.append("X"); //Si no esta completo llena las x
        }
        
    }

    while ( iterador1 != mensaje.end()+1 ) 
    {
        cout << *iterador1; //Presenta las letras
        mensajeguardado+=*iterador1; //añade a la cadena con*
        mensajeguardado1+=*iterador1; //añade a la cadena para vector

        iterador1++;
        aux++;

        if (aux==tamanio){ //Si llega a la cantidad a dividir
            cout<<endl; //salta de espacio
            aux=0;
            mensajeguardado+="*"; //añade los "*" cada cantidad a dividir
            cadenavector.push_back(mensajeguardado1); //Los guarda en el vector
            mensajeguardado1.erase(); // borra para almacenar denuevo
        }

    }

    

    cout<<"\n"<<mensajeguardado;
    //cout<<"\n"<<cadenavector[0];
    cout<<"\nFin del programa";
}