#include <iostream>
#include <string.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int resto(int a, int n){ //funcion resto recibe a (dividendo) y n )(divisor)
    int q,r; // Las dos salidas a entregar en la division: q (cociente) y r (resto)
    if (a<0){//en caso a sea negativo
        q=a/n; //resolvemos q
        r=a-((q-1)*n); //realizamos la operacion original del resto pero se le aumenta 1 al cociente para exceder y obtener el resto positivo.
        return r; //basicamente es siguiendo la logica de Galo
    }else{// En caso a sea positivo
        q=a/n; 
        r=a-(q*n);// simplemente la diferencia entre a y la multiplicacion
        return r;
    }
}   


int Euclides(int a, int b){//Implementando recursividad para Euclides
    if(resto(a,b)==0){// Caso base resto = 0
        return b;
    }else{
        int aux=b;//Variable para almacenar el divisor anterior
        b=resto(a,b);//lo reemplazamos por el valor que daria el restp de la division
        a=aux;//a pasa a ser el divisor anterior
        Euclides(a,b);//Repetimos con el divisor anterior y el resto
    }
}

//ax+by=d (devolder x,y) a,b son entrada d no se conoce
/*void Euclides_extendido(int a, int b, int *q1, int *q2, int *q3){
    int d,x,y,x1,x2,y1,y2,q,r;

    if (b==0){
        d=a;
        x=1;
        y=0;
        //return d;
    }

    x1=0;
    x2=1;
    y1=1;
    y2=0;
    while (b>0){
        q=a/b;
        r=a-(q*b);
        x=x2-(q*x1);
        y=y2-(q*y1);
        a=b;
        b=r;
        x2=x1;
        x1=x;
        y2=y1;
        y1=y;
    }
    d=a;
    x=x2;
    y=y2;
    *q1=d;
    *q2=x;
    *q3=y;
}*/

int inversa(int a, int n){
    int invA = 0;

    for (int i = 1; i < n; i++){
        invA = (a * i) % n; 
        if(invA == 1) {
            invA = i;
            return invA;
        }
    }
}


class afin
{
public:
    string alfabeto ="abcdefghijklmnopqrstuvwxyz,.-_ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789()";
    int largo_alfabeto=alfabeto.length(),a=0,b=0;
    afin();

    string cifrado(string);
    string descifrado(string,int,int);
    void generar_claves();
    int aleatorio();

};

afin::afin(){
    generar_claves();
}

int afin::aleatorio(){
    return resto(rand(),largo_alfabeto+1);
}

void afin::generar_claves(){
    int aux = 0;
    do{
        a = aleatorio();
        aux = Euclides(a, largo_alfabeto);
    }while(aux != 1);
        b = aleatorio();
}

string afin::cifrado(string mensaje){
    int n=mensaje.length();
    string mensajeCifrado;

    mensajeCifrado+="|";
    
    for (int i = 0; i < n; i++){

        int pos = alfabeto.find(mensaje[i]);
        if (pos != string::npos){
            // operacion de cifrado si se encontro una coincidencia con el alfabeto
            pos = resto((a * pos + b), largo_alfabeto);
            mensajeCifrado += alfabeto[pos];
        }   
        else{
            mensajeCifrado += mensaje[i];
        }
    }
    cout<<"clave a: "<<a<<" clave b: "<<b<<endl;
    mensajeCifrado+="|";
    return mensajeCifrado;
}


string afin::descifrado(string mensajeCifrado,int a,int b){
	string mensajeDescifrado;
    int n=mensajeCifrado.length(),invA=inversa(a,largo_alfabeto);
    
    for (int i = 0; i < n; i++){

        int pos = alfabeto.find(mensajeCifrado[i]);
        if(pos != string::npos){
            // operacion de cifrado si se encontro una coincidencia con el alfabeto
            pos = resto(invA * (pos - b), largo_alfabeto);
            mensajeDescifrado += alfabeto[pos];
        }
        else{
            // si no se encuentra en el alfabeto, añadirlo a la salida
            mensajeDescifrado += mensajeCifrado[i];
        }
    }
    
    return mensajeDescifrado;
}

int main(){
    int opcion,a,b;
    string mensaje;
    srand(time(NULL));
    cout<<endl<<"Ingrese el mensaje: ";getline(cin,mensaje);
    afin mensajero;
    cout<<endl<<"1.Cifrar";
    cout<<endl<<"2.Descifrar";
    cout<<"\nopcion: ";cin>>opcion;
    switch (opcion)
    {
        case 1:
            cout<<mensajero.cifrado(mensaje);
            break;
        
        case 2:
            cout<<"clave a: ";cin>>a;
            cout<<"clave b: ";cin>>b;
            cout<<mensajero.descifrado(mensaje,a,b);
            break;
    
        default:
            break;
    }
    cout<<"\nFin del programa";
    

} 