#include <iostream>

using namespace std;

int resto(int a, int n){
    int q,r; // Las dos salidas a entregar en la division: q (cociente) y r (resto)
    if (a<0){//en caso a sea negativo
        q=a/n; //resolvemos q
        r=a-((q-1)*n); //realizamos la operacion original del resto pero se le aumenta 1 al cociente para exceder y obtener el resto positivo.
    }else{// En caso a sea positivo
        q=a/n; 
        r=a-(q*n);// simplemente la diferencia entre a y la multiplicacion
    }
    return r;
}

string cifrar(string textoclaro, int clave){
  string alfabeto="abcdefghijklmnopqrstuvwxyz";
  int aux, largo=textoclaro.length(),aux2, largo_alfabeto=alfabeto.length();
  string textocifrado; // nuevo string para almacenar el cifrado

  for (int i=0; i<largo; i++){//Evalua cada letra
    for (int j = 0; j < largo_alfabeto; j++)//El largo del alfabeto
      {
        if (textoclaro[i]==alfabeto[j])
          {
            aux2=j+clave;
            if (aux2>largo_alfabeto-1)
            {
            aux=resto(aux2,largo_alfabeto);//Si se pasa se calcula el resto pureba con largo_alfabeto-1
            textocifrado+=alfabeto[aux];
            }else{
              textocifrado+=alfabeto[aux2];
            }                                                
          }
        }
    }
    return textocifrado;
}

void criptoanalisis(string mensaje){ //Usa descifrado
    string prueba, alfabeto="abcdefghijklmnopqrstuvwxyz";
    int aux, largo=mensaje.length(),aux2,key=0, confirmacion=0, largo_alfabeto=alfabeto.length();
    while (key<largo_alfabeto)
    {
        for (int i=0; i<largo; i++){
            for (int j = 0; j < largo_alfabeto; j++)
            {
                if (mensaje[i]==alfabeto[j])
                {
                    aux2=j-key;
                    if (aux2<0)
                    {
                        aux=resto(aux2,largo_alfabeto-1);
                        prueba+=alfabeto[aux];
                    }else{
                        prueba+=alfabeto[aux2];
                    }         
                }
            }
        }
        cout<<endl<<"("<<prueba<<")"<<endl; //Verifica si es el mensaje si no sigue
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
    cout<<prueba;
}

int main() {
  string mensaje, cifrado;
  int clave;
  cout<<"Ingrese el mensaje: ", getline(cin,mensaje);
  cout<<"Ingrese la clave: ",cin>>clave;
  cifrado=cifrar(mensaje, clave);
  cout<<"Mensaje cifrado:"<<cifrado;
  criptoanalisis(cifrado);
}