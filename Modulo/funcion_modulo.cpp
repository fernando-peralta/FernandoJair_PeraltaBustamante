#include <iostream>

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

int main(){
    int a,n,q,r; // todos los enteros que se necesitan

    cout<<"Ingrese el numero a: "; cin>>a;cout<<endl;
    cout<<"Ingrese el numero n (Siempre tiene que ser positivo): "; cin>>n;cout<<endl;
    while (n<0) //restriccion en la que n siempre es positivo
    {
        cout<<"Ingrese un numero correcto\n";
        cout<<"Ingrese el numero n (Siempre tiene que ser positivo)"; cin>>n;cout<<endl;
    }
    
    cout<<resto(a,n);  // llamamos a la función
    cout<<"\nPrograma terminado";
}