#include <iostream>
#include <fstream>
#include "Registro.h"
#include "SupportLib.h"

using namespace std;

int main()
{
    SupportLib support;
    int tamanhoEntrada;
    int *v=support.leArquivoEntrada(&tamanhoEntrada);
    for(int i=0; i<tamanhoEntrada; i++)
        cout << endl << v[i];


    return 0;
}
