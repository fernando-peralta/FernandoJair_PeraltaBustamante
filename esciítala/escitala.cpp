#include <iostream>

using namespace std;

class contacto{ //clase contacto para el formato de agenda y almacenar clave por los nombres
    private:
        int columnas,filas;
        string nombre;
    public:
        contacto(string,int,int);//constructor
        ~contacto();//Destructor
        string cifrar(string);
        string descifrar(string);
};

contacto::contacto(string _nombre, int _columnas, int _filas){ //constructor
    nombre=_nombre;
    columnas=_columnas;
    filas=_filas;
}

contacto::~contacto(){} //destructor

string contacto::cifrar(string textoclaro){ //funcion para cifrar
    int aux;
    string textocifrado; // nuevo string para almacenar el cifrado
    for (int i=0; i<columnas;i++){
        for (int j = 0; j < filas; j++)
        {
            aux=columnas*j;
            textocifrado+=textoclaro[i+aux]; //va añadiendo la letra respecto a la cantidad de columnas, base del cifrado
        }
    }
    return textocifrado;
};

string contacto::descifrar(string textocifrado){ //funcion para cifrar
    int aux; 
    string textodescifrado; // nuevo string para almacenar el descifrado
    for (int i=0; i<filas;i++){
        for (int j = 0; j < columnas; j++)
        {
        aux=filas*j;
        textodescifrado+=textocifrado[i+aux]; //va añadiendo la letra respecto a la cantidad de filas, base del descifrado
        }
    }

    return textodescifrado;
};


int main(){
    string mensaje; //mensaje para cifrar o descifrar
    int columnas, filas, largo,opcion; 
    
    cout << "Ingrese su mensaje: ";
    getline(cin,mensaje);
    largo=mensaje.length(); // Que tan largo es el mensaje
    cout<<"ingrese las columnas: ";cin>>columnas; cout<<"\n";
    cout<<"ingrese las filas: ";cin>>filas; cout<<"\n";
    
    while (largo>(filas*columnas)) //comprobar que la clave es mas grande que el largo y no da error
    {
        cout<<"El mensaje no se cifrara por completo ingrese una cantidad mayor de filas o columnas\n";
        cout<<"ingrese las columnas: ";cin>>columnas; cout<<"\n";
        cout<<"ingrese las filas: ";cin>>filas; cout<<"\n";
    }

    for (int i=largo; i<(filas*columnas);i++){ //Para que no de un error al ser el largo mas grande que el mensaje y
        mensaje.insert(i," "); //entregue caracteres random
    }

    contacto contacto1("Fernando",columnas,filas); // Defino al objeto
    cout<<"Seleccione una opcion a realzar:";
    cout<<"\n1.Enviar mensaje";
    cout<<"\n2.Descifrar mensaje";
    cout<<"\nopcion: ";cin>>opcion;
    
    switch (opcion){ //menu para cifrar o descifrar
        case 1:
            cout<<contacto1.cifrar(mensaje);
            break;
        
        case 2:
            cout<<contacto1.descifrar(mensaje);
            break;
            
        default:
            break;
    }

    cout<<"\nFin del programa";

}