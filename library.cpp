#include <iostream>
#include <math.h>
void binaryzador(int num,char* bin)
/*convierte una lista char de tamanho 8 a el numero el numero binario correspondiente al numero incertado*/
//se le ingresa un int positivo, gracias
{
    for (int x=0;x!=8;x++)
    {
        if(pow(2,7-x)<=num)
        {
            num= num % (int (pow(2,7-x)));
            bin[x]='1';

        }
        else
        {
            bin[x]='0';
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------------
int decimalizador(char* bin)
/* una lista char correspondiente a un numero binario es traducida a su correspondiente numero decimnal*/
//el numero decimal maximo a representar debe estar dentro del rango de los positivos que puede reprensentar un int
{
    int val=0;
    for(int x=0;x<8;x++)
    {
        val+= (int(*(bin+x)-'0'))*(int(pow(2,7-x)));
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
