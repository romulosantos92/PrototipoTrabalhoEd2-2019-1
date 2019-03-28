#include <iostream>
#include "ListaRegistros.h"
#include"NoListaRegistros.h"
#include "SupportLib.h"

using namespace std;

int main()
{
    ListaRegistros l;
    SupportLib support;

    //l.leArquivo(1, 10000);
    //support.bubbleSort(&l);
    l.leArquivo(5);
    //support.selectSort(&l);

    return 0;
}
