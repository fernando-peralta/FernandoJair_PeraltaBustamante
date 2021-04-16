//Ahorcado
#include <iostream>
#include <string>
using namespace std;

int main(){
    string palabra("contrasenia"), letra, palabraoculta;//Define la palabra
    int largo=palabra.length(), aux, aux2,aux3=0;

    for (int i = 0; i < largo; i++) //cambia las letras por X
    {
        palabraoculta+="X";
    }
    
    while (aux3!=8)
    {
        cout<<"\nAdivine la palabra: "<<palabraoculta;
        cout<<"\nIngrese una letra: "; getline(cin,letra); 
        aux=letra.length();
        while (aux>1)
        {
            cout<<"\nIngrese una letra: "; getline(cin,letra);//Se asegura de recibir solo una letra
        }

        aux2=palabra.find(letra); //Busca la letra en la palabra
        if (aux2>0)
        {
            palabraoculta.replace(aux2,1,palabra,aux2,1); //Las cambia para ver un progreso
            cout<<"\nCorrecto";
        }else{
            aux3+=1; //aumenta el contador de fallas
        }

        for (int i = 0; i < aux3; i++)//saca el muñeco de ahorcado
        {
            if (i==1)
            {
                cout<<" \n o";
            }else if (i==2)
            {
                cout<<"\n/";
            }else if (i==3)
            {
                cout<<"|";
            }else if (i==4)
            {
                cout<<"\\ ";
            }else if (i==5)
            {
                cout<<"\n"<<" |";
            }else if (i==6)
            {
                cout<<"\n/";
            }else if (i==7)
            {
                cout<<" \\";
            }
        }
    }
    cout<<"\nFin del programa: GG";
}