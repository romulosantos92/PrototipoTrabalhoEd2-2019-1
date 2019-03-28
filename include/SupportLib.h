#ifndef SUPPORTLIB_H
#define SUPPORTLIB_H

#include <iostream>
#include <ctime>
#include "ListaRegistros.h"
#include "NoListaRegistros.h"

using namespace std;


class SupportLib
{
    public:
        SupportLib();
        virtual ~SupportLib();

        void bubbleSort(ListaRegistros *lista);
        void selectSort(ListaRegistros *lista);

    protected:

    private:
};

#endif // SUPPORTLIB_H
