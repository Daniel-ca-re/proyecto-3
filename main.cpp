#include <iostream>
#include <math.h>
#include "library.h"
int key=4;
using namespace std;

int main()
{
for (int x=0;x<=255;x++)
{
    char arreg[8];
    binaryzador(x,arreg);
    encriptacion1(key,arreg,8);
    desencriptacion1(key,arreg,8);
    int y=decimalizador(arreg);
    if (y!=x)
    {
        char arreg2[8];
        binaryzador(x,arreg2);
        cout << x << endl;
    }

}
}

