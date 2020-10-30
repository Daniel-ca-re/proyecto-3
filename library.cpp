#include <iostream>
#include <math.h>
#include <fstream>
void binaryzador(int num,char * bin,int tam)
/*convierte una lista char de tamanho 8 a el numero el numero binario correspondiente al numero incertado*/
//se le ingresa un int positivo, gracias
{
    for (int x=0;x!=tam;x++)
    {
        if(pow(2,tam-1-x)<=num)
        {
            num= num % (int (pow(2,tam-1-x)));
            bin[x]='1';

        }
        else
        {
            bin[x]='0';
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------------
int decimalizador(char* bin,int tam)
/* una lista char correspondiente a un numero binario es traducida a su correspondiente numero decimnal*/
//el numero decimal maximo a representar debe estar dentro del rango de los positivos que puede reprensentar un int
{
    int val=0;
    for(int x=0;x<tam;x++)
    {
        val+= (int(*(bin+x)-'0'))*(int(pow(2,tam-1-x)));
    }
    return val;
}
//-------------------------------------------------------------------------------------------------------------------------
void encriptacion1(int n,char*arreg,int tam_arreg)
//encripta numeros binarios segun se pide en en la practica 3 encriptacion 1
{
    int contador (int, char*);
    int lim_inf=0;
    //cuenta la cantidad de 1
    int cont=0;
    for(int x=lim_inf;(x<lim_inf+n)&&(x<tam_arreg);x++)
    {
        if(*(arreg+x)=='0')
        {
            *(arreg+x)='1';
            cont++;

        }
        else
        {
            *(arreg+x)='0';
        }




    }
    lim_inf+=n;
    while(lim_inf<tam_arreg)
    {
        int salt;
        float y=float(n)/2;
        if(y<cont)
        {
            salt=3;
        }
        else if(y>cont)
        {
            salt=2;
        }
        else
        {
            salt=1;
        }
        for(int x=lim_inf+salt-1;(x<lim_inf+n)&&(x<tam_arreg);x+=salt)
        {
            if(*(arreg+x)=='0')
            {
                *(arreg+x)='1';

            }
            else
            {
                *(arreg+x)='0';
            }

        }
        cont=contador(n,(arreg+lim_inf));
        lim_inf+=n;
    }

}
//-----------------------------------------------------------------------------------------------------------------------
int contador (int n, char* lista)
//cuenta la cantidad de 1s que se encuentren en una lista de tamanho n
{
    int c=0;
    for(int x=0;x<n;x++)
    {
        if (*(lista+x)=='1')
        {
            c++;
        }
    }
    return c;
}
//--------------------------------------------------------------------------------------------------------------------------
void encriptacion2(int n,char*arreg,int tam_arreg)
//encripta numeros binarios segun se pide en en la practica 3 encriptacion 2
{
    int lim_inf=0;
    //cuenta la cantidad de 1
    int lim_sup=lim_inf+n;
    while(lim_inf<tam_arreg)
    {
        if(lim_sup>tam_arreg)
        {
            lim_sup=tam_arreg;
        }
        int g;
        int g2=arreg[lim_inf];
        for(int x=lim_inf;x<lim_sup;x++)
        {
            g=g2;
            g2=arreg[x+1];
            arreg[lim_inf+int(((x+1)%(n))%(lim_sup-lim_inf))]=g;



        }
        lim_inf+=n;
        lim_sup+=n;
    }

}
//-------------------------------------------------------------------------------------------------------------------------
void desencriptacion2(int n,char*arreg,int tam_arreg)
{
    int lim_inf;
    int lim_sup;
    if(int(tam_arreg/n)*n==tam_arreg)
    {
        lim_sup=tam_arreg;
        lim_inf=lim_sup-n;
    }
    else
    {
        lim_inf=int(tam_arreg/n)*n;
        lim_sup=tam_arreg;

    }
    while(lim_inf>=0)
    {
        char g;
        char g2=arreg[lim_inf];
        for(int x=lim_sup-1;x>=lim_inf;x--)
        {
            g=g2;
            g2=arreg[lim_inf+int(((x)%(n))%(lim_sup-lim_inf))];
            arreg[x]=g;



        }
        lim_sup=lim_inf;
        lim_inf-=n;
    }

}
//-------------------------------------------------------------------------------------------------------------------------
void desencriptacion1(int n,char*arreg,int tam_arreg)
//encripta numeros binarios segun se pide en en la practica 3 encriptacion 1
{
    int lim_inf;
    int cont;
    if(int(tam_arreg/n)*n==tam_arreg)
    {
        lim_inf=tam_arreg-n;
    }
    else
    {
        lim_inf=int(tam_arreg/n)*n;

    }

    while(lim_inf!=0)
    {
        cont=contador(n,(arreg+lim_inf-n));
        int salt;
        float y=float(n)/2;
        if(y<cont)
        {
            salt=3;
        }
        else if(y>cont)
        {
            salt=2;
        }
        else
        {
            salt=1;
        }

        for(int x=lim_inf+salt-1;(x<lim_inf+n)&&(x<tam_arreg);x+=salt)
        {
            if(*(arreg+x)=='0')
            {
                *(arreg+x)='1';

            }
            else
            {
                *(arreg+x)='0';
            }

        }
        lim_inf-=n;
    }
    for(int x=lim_inf;(x<lim_inf+n)&&(x<tam_arreg);x++)
    {
        if(*(arreg+x)=='0')
        {
            *(arreg+x)='1';
            cont++;

        }
        else
        {
            *(arreg+x)='0';
        }
    }

}
//-------------------------------------------------------------------------------------------------------------------------
char comparar_2cadenas_de_caracteres(char* L,char* l,int tam)
{
    for(int x=0;x<tam;x++)
    {
        if(L[x]!=l[x])
        {
            return '0';
        }
    }
    return '1';
}
//-------------------------------------------------------------------------------------------------------------------------
int lenarreg(char* L)
{
    int c=0;
    for(int x=0;L[x]!='\0';x++)
    {
        c++;
    }
    return c;
}
//-------------------------------------------------------------------------------------------------------------------------
void encriptcontra_de_contrasenhas(char* cont,char* encrip)
{
    for(int x=0;x<4;x++)
    {
        binaryzador(int(cont[x]),(encrip+(x*8)),8);
    }
}
//-------------------------------------------------------------------------------------------------------------------------
int chart_to_int(char* charnum,int tam)
{
    int sum=0;
    for(int x=tam-1;x>=0;x--)
    {
        sum+=int((charnum[x]-'0'))*(pow(10,tam-1-x));
    }
    return sum;
}
//-------------------------------------------------------------------------------------------------------------------------
void rellenado(char* arreg,char val,int tam)
{
    for(int x=0;x<tam;x++)
    {
        arreg[x]=val;
    }
}
//------------------------------------------------------------------------------------------------------------------------
void sobre_escritura(char* arrai1,char* arrai2,int tam2)
{
    for(int x=0;x<tam2;x++)
    {
        arrai1[x]=arrai2[x];
    }
}
//------------------------------------------------------------------------------------------------------------------------
int esta_en(char* arreg,int cedula,int tam)
{
    char ced[20];
    rellenado(ced,'\0',20);
    char v='0';
    int posicion=0;
    int c=0;
    for (int x=0;x<tam;x++)
    {
        if(v=='0'&& arreg[x]!=',')
        {
            ced[c]=arreg[x];
            c++;
        }
        if(arreg[x]==',')
        {
            v='1';
            if(chart_to_int(ced,lenarreg(ced))==cedula)
            {
                return posicion;
            }
        }
        else if (arreg[x]=='.')
        {
            v='0';
            rellenado(ced,'\0',20);
            posicion=x+1;
            c=0;
        }


    }
    return 2;
}
//-------------------------------------------------------------------------------------------------------------------------
void datos_necesarios(char* datos,int& saldo,char* cont)
{
    char arrsaldo[33];
    rellenado(arrsaldo,'\0',32);
    int c=0;
    int y=0;
    for(int x=0;datos[x]!='.' && datos[x]!='\0';x++)
    {
        if(datos[x]==',')
        {
            y=0;
            c++;
        }
        if(c==1 && datos[x]!=',')
        {
            cont[y]=datos[x];
            y++;
        }
        else if (c==2 && datos[x]!=',')
        {
            arrsaldo[y]=datos[x];
            y++;
        }
    }
    desencriptacion1(4,arrsaldo,32);
    desencriptacion2(4,cont,32);
    saldo=decimalizador(arrsaldo,32);

}
