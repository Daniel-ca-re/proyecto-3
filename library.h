#ifndef LIBRARY_H
#define LIBRARY_H

void binaryzador(int,char*,int);
int decimalizador(char*,int);
void encriptacion1(int,char*,int);
void encriptacion2(int,char*,int);
void desencriptacion2(int,char*,int);
void desencriptacion1(int,char*,int);
char comparar_2cadenas_de_caracteres(char*,char*,int);
int lenarreg(char*);
void encriptcontra_de_contrasenhas(char*,char*);
int chart_to_int(char*,int);
void rellenado(char*,char,int);
void sobre_escritura(char*,char*,int);
int esta_en(char*,int,int);
void datos_necesarios(char* datos,int& saldo,char* cont);

#endif // LIBRARY_H
