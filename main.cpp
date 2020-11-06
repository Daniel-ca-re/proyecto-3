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
    //administrador
    if (elec==1)
    {
        char admcont[]="abcd";
        cout <<"ingrese la contrasenha"<<endl;
        char cont[5];
        scanf("%s", cont);
        //verificacion
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
            encriptcontra_de_contrasenhas(contrasenha,arrcont);
            encriptacion1(key,arrsal,32);
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

    //ususario
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
           //se crea un arreglo char que contiene toda la informacion sobre usuarios
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
           //se verifica que la cedula se a parte de los usuarios
           int posicion=esta_en(data,cedula,lenarreg(data));
           if (posicion!=2)
           {
               int saldo;
               char vcont[33];
               char pcont[33];
               rellenado(vcont,'\0',33);
               rellenado(pcont,'\0',33);
               datos_necesarios(data+posicion,saldo,vcont);
               cout<<"ingrese su contrasenha: "<<endl;
               char contrasenha[5];
               rellenado(contrasenha,'\0',5);
               scanf("%s", contrasenha);
               encriptcontra_de_contrasenhas(contrasenha,pcont);
               //se compara la contrasenha del usuario con la dada
               if (comparar_2cadenas_de_caracteres(pcont,vcont,32)=='1')
               {
                   elec=3;
                   //se elije la accion que desea hacer el usuario y se ejecuta la accion
                   while (elec!=0 && elec!=1 && elec!=2)
                   {
                       cout <<"elija:\n 1. retirar dinero \n2. consulta de saldo  \n 0. salir"<<endl;
                       cin >> elec;

                   }
                   if(elec==1)
                   {
                       int retiro;
                       cout <<"valor que desea retirar: "<<endl;
                       cin >> retiro;
                       saldo-=retiro;
                   }
                   else if(elec==2)
                   {
                       int retiro=1000;
                       saldo-=retiro;
                       cout <<saldo<<endl;
                   }
                   //se traduce el saldo a binario y se encripta
                   binaryzador(saldo,vcont,32);
                   encriptacion1(key,vcont,32);
                   int c=0;
                   //se cambia el nuevo valor por el anterir dentro del arreglo data
                   for(int x=0;c<2;x++)
                   {
                       if (data[posicion+x]==',')
                       {
                           c++;
                       }
                       if (c==2)
                       {
                           sobre_escritura(data+posicion+x+1,vcont,32);
                           break;
                       }
                   }
                   //se copia la nueva informacion en el archivo.txt
                      ofstream outfile;

                      outfile.open("../proyecto_3/BD/sudo.txt");

                      if (!outfile.is_open())
                      {
                        cout << "Error abriendo el archivo" << endl;
                        exit(1);
                      }
                      for(int x=0;x<lenarreg(data);x++)
                      {
                          if(data[x]=='.')
                          {
                              outfile << '\n';
                          }
                          else
                          {
                              outfile << data[x];
                          }
                      }




                      // Se cierra el archivo
                      outfile.close();

               }
               else
               {
                   cout <<"contrasenha incorrecta"<<endl;
               }

           }
           else
           {
               cout<<"usuario inexistente"<<endl;
           }


    }
    return 0;
}
