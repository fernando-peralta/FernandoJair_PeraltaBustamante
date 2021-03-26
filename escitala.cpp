#include <iostream>
#include <string>

using namespace std;

class contacto{
    private:
        int columnas,filas;
        string nombre;
    public:
        contacto(string,int,int);//constructor
        ~contacto();//Destructor
        string cifrar(string,string);
        string descifrar(string, string);
};

contacto::contacto(string _nombre, int _columnas, int _filas){
    nombre=_nombre;
    columnas=_columnas;
    filas=_filas;
}

contacto::~contacto(){}

string contacto::cifrar(string textoclaro,string textocifrado){
    int aux, aux2=0;
    for (int i=0; i<columnas;i++){
        for (int j = 0; j < filas; j++)
        {
            aux=columnas*j;
            textocifrado[aux2]=textoclaro[i+aux];
            aux2++;
        }
    }

    //cout<<endl<<textocifrado<<endl;
    return textocifrado;
};

string contacto::descifrar(string textocifrado,string textodescifrado){
    int aux, aux2=0;
    for (int i=0; i<filas;i++){
        for (int j = 0; j < columnas; j++)
        {
        aux=filas*j;
        textodescifrado[aux2]=textocifrado[i+aux];
        aux2++;
        }
    }

    //cout<<endl<<textodescifrado<<endl;
    return textodescifrado;
};


int main(){
    string mensaje, cifrado, desencriptado,envio, recibo;
    int columnas, filas, largo, maximo,opcion;
    
    cout << "Ingrese su mensaje: ";
    getline(cin,mensaje);
    largo=mensaje.length();
    cout<<"ingrese las columnas: ";cin>>columnas; cout<<"\n";
    cout<<"ingrese las filas: ";cin>>filas; cout<<"\n";
    maximo=filas*columnas;
    
    while (largo>maximo)
    {
        cout<<"El mensaje no se cifrara por completo ingrese una cantidad mayor de filas o columnas\n";
        cout<<"ingrese las columnas: ";cin>>columnas; cout<<"\n";
        cout<<"ingrese las filas: ";cin>>filas; cout<<"\n";
        maximo=filas*columnas;
    }

    for (int i=largo; i<maximo;i++){
        mensaje.insert(i," ");
    }
    for (int i=0; i<maximo;i++){
        cifrado.insert(i," ");
    }

    for (int i=0; i<maximo;i++){
            desencriptado.insert(i," ");
    }

    contacto contacto1("Fernando",columnas,filas);
    cout<<"Seleccione una opcion a realzar:";
    cout<<"\n1.Enviar mensaje";
    cout<<"\n2.Descifrar mensaje";
    cout<<"\nopcion: ";cin>>opcion;
    
    switch (opcion){
        case 1:
            envio=contacto1.cifrar(mensaje,cifrado);
            cout<<envio;
            break;
        
        case 2:
            recibo=contacto1.descifrar(mensaje,desencriptado);
            cout<<recibo;
            break;
            
        default:
            break;
    }

    cout<<"\nFin del programa";

}