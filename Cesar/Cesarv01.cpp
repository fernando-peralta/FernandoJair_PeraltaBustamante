#include <iostream>
#include <string>

using namespace std;





int resto(int a, int n){
    int q,r; // Las dos salidas a entregar en la division: q (cociente) y r (resto)
    if (a<0){//en caso a sea negativo
        q=a/n; //resolvemos q
        r=a-((q-1)*n); //realizamos la operacion original del resto pero se le aumenta 1 al cociente para exceder y obtener el resto positivo.
         //basicamente es siguiendo la logica de Galo
    }else{// En caso a sea positivo
        q=a/n; 
        r=a-(q*n);// simplemente la diferencia entre a y la multiplicacion
    }

    return r;
}


class emisor{
    private:
        int clave;
        string alfabeto=" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public:
        emisor(int);
        ~emisor();
        string cifrar(string);
};

emisor::emisor(int _clave){
    clave=_clave;
}

emisor::~emisor(){}



string emisor::cifrar(string textoclaro){
    int aux, largo=textoclaro.length(),aux2;
    string textocifrado; // nuevo string para almacenar el cifrado

    for (int i=0; i<largo; i++){//Evalua cada letra
        for (int j = 0; j < 53; j++)//El largo del alfabeto
        {
            if (textoclaro[i]==alfabeto[j])
            {
                aux2=j+clave;
                if (aux2>52)
                {
                    aux=resto(aux2,52)-1;//Si se pasa se calcula el resto
                    
                    if (aux==0)
                    {
                        textocifrado+=" ";
                    }else{
                        textocifrado+=alfabeto[aux];
                    }
                }else{
                    if (aux2==0)
                    {
                        textocifrado+=" ";
                    }else{
                        textocifrado+=alfabeto[aux2];
                    }
                }
                
                
                
                
            }
        }
    }
    return textocifrado;
};


class receptor{
    private:
        int clave;
        string alfabeto=" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public:
        receptor(int);
        ~receptor();
        string descifrar(string);
};

receptor::receptor(int _clave){
    clave=_clave;
}

receptor::~receptor(){}



string receptor::descifrar(string textoclaro){
    int aux, largo=textoclaro.length(),aux2;
    string textodescifrado; // nuevo string para almacenar el cifrado

    for (int i=0; i<largo; i++){//Evalua la cantidad de letras
        for (int j = 0; j < 53; j++)//cada una se compara con todo el alfabeto
        {
            if (textoclaro[i]==alfabeto[j])
            {
                aux2=j-clave;
                if (aux2<0)//Si se pasa se calcula el resto
                {
                    aux=resto(aux2,53);
                    
                    if (aux==0)
                    {
                        textodescifrado+=" ";
                    }else{
                        textodescifrado+=alfabeto[aux];
                    }
                }else{
                    if (aux2==0)
                    {
                        textodescifrado+=" ";
                    }else{
                        textodescifrado+=alfabeto[aux2];
                    }
                }               
            }
        }
    }
    return textodescifrado;
};

string criptoanalisis(string mensaje){ //Usa descifrado
    int aux, largo=mensaje.length(),aux2,key=1, confirmacion=0;
    string prueba, alfabeto=" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (key<53)
    {
        for (int i=0; i<largo; i++){
            for (int j = 0; j < 53; j++)
            {
                if (mensaje[i]==alfabeto[j])
                {
                    aux2=j-key;
                    if (aux2<0)
                    {
                        aux=resto(aux2,53);
                        
                        if (aux==0)
                        {
                            prueba+=" ";
                        }else{
                            prueba+=alfabeto[aux];
                        }
                    }else{
                        if (aux2==0)
                        {
                            prueba+=" ";
                        }else{
                            prueba+=alfabeto[aux2];
                        }
                    }               
                }
            }
        }

        cout<<endl<<prueba<<endl; //Verifica si es el mensaje si no sigue
        cout<<"Este es el mensaje? (1 si es correcto): "; cin>>confirmacion; cout<<endl;
        if (confirmacion==1)
        {
            prueba+=" Key: ";
            prueba+=to_string(key);
            break;
        }else{
            prueba="";
            key++;
        }
        
        
    }
    return prueba;
}


int main(){
    string mensaje, nombre;
    int key, opcion;
    cout<<"Ingrese el mensaje: ", getline(cin,mensaje);
    cout<<"Ingrese la clave: ", cin>>key;
    

    cout<<"Seleccione una opcion a realzar:";
    cout<<"\n1.Emisor (encriptar)";
    cout<<"\n2.Receptor (descencriptar)";
    cout<<"\n3.Criptoanalisis (descencriptar)";
    cout<<"\nopcion: ";cin>>opcion;
    emisor fernando (key);
    receptor amigo (key);
    
    switch (opcion){ //menu para cifrar o descifrar
        case 1:
            cout<<"|"<<fernando.cifrar(mensaje)<<"|"<<endl;
            break;

        case 2:
            cout<<"|"<<amigo.descifrar(mensaje)<<"|"<<endl;
            break;
            
        default:
            cout<<criptoanalisis(mensaje);

            break;
    }

    cout<<"\nFin del programa";
}