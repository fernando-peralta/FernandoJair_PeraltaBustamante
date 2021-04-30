#include <iostream>
#include <time.h>
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

int gen_clave(int n){//largo del alfabeto
    int clave, aux;
    srand(time(NULL));//Inicializamos los numeros random
    aux=n-1;//maximo del alfabeto
    clave=1+resto(rand(),aux);//calculamos la clave entre 1 y el largo del alfabeto
}


int main(){
    cout<<"Fin del programa";
} 