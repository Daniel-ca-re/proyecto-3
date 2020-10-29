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
            arrsal[32]='\0';
            arrcont[32]='\0';
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

}

