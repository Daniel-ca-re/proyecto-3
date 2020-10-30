#include <iostream>
#include <math.h>
#include <fstream>
#include "library.h"

#define key 4
using namespace std;

int main()
{
    int elec=3;

    while (elec!=0 && elec!=1 && elec!=2)
    {
        cout <<"elija:\n 1. administrador\n 2. usuario\n 0. salir\n";
        cin >> elec;

    }
    if (elec==1)
    {
        char admcont[]="abcd";
        cout <<"ingrese la contrasenha"<<endl;
        char cont[5];
        scanf("%s", cont);
        if (comparar_2cadenas_de_caracteres(cont,admcont,4)=='1')
        {
            int cedula;
            char arrsal[33];
            char contrasenha[5];
            char arrcont[33];
            rellenado(arrsal,'\0',33);
            rellenado(arrcont,'\0',33);

            int saldo;
            cout<<"se le pedira la informacion requeriada para ingresar un ususario"<<endl;
            cout<<"Cedula del usuario "<<endl;
            cin >>cedula;
            cout<<"contrasenha del usuario(4 letras)"<<endl;
            scanf("%s", contrasenha);
            cout<<"saldo del usuario(en pesos)"<<endl;
            cin>> saldo;
            binaryzador(saldo,arrsal,32);
            encriptacion2(key,arrsal,lenarreg(arrsal));
            encriptcontra_de_contrasenhas(contrasenha,arrcont);
            encriptacion2(key,arrcont,32);

            ofstream archivo;

            archivo.open("../proyecto_3/BD/sudo.txt",ios::app);
            archivo << cedula <<','<<arrcont<<','<<arrsal<<endl;
            archivo.close();
        }

        else
        {
            cout<<"contrasenha incorrecta"<<endl;
        }

    }

    else if (elec==2)
    {
           ifstream infile;
           char data[1000];
           rellenado(data,'\0',1000);
           infile.open("../proyecto_3/BD/sudo.txt");
           if (!infile.is_open())
           {
             cout << "Error abriendo el archivo" << endl;
             exit(1);
           }
           char copy1[100];
           rellenado(copy1,'\0',100);
           char copy2[100];
           rellenado(copy2,'\0',100);
           infile >> copy1;
           sobre_escritura(data,copy1,100);
           while(comparar_2cadenas_de_caracteres(copy1,copy2,100)=='0')
           {

               sobre_escritura(copy2,copy1,100);
               rellenado(copy1,'\0',100);
               infile >> copy1;
               if (copy1[0]=='\0')
               {
                   break;
               }

               data[lenarreg(data)]='.';
               sobre_escritura(data+lenarreg(data),copy1,100);





           }
           infile.close();
           int cedula;
           cout<<"ingrese su cedula: "<<endl;
           cin >>cedula;
           int posicion=esta_en(data,cedula,lenarreg(data));
           if (posicion!=2)
           {
               cout<<"ingrese su contrasenha: "<<endl;
               char contrasenha[5];
               rellenado(contrasenha,'\0',5);
               scanf("%s", contrasenha);

           }
           else
           {
               cout<<"usuario inexistente"<<endl;
           }


    }
    return 0;
}
