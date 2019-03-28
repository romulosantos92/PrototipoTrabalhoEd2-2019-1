#ifndef LISTAREGISTROS_H
#define LISTAREGISTROS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <sstream>
#include "NoListaRegistros.h"

using namespace std;

class ListaRegistros
{
    public:
        ListaRegistros();
        virtual ~ListaRegistros();

        NoListaRegistros* getPrimeiro();
        void setPrimeiro(NoListaRegistros* p);
        NoListaRegistros* getUltimo();
        void setUltimo(NoListaRegistros *p);
        int getTam();
        void setTam(int v);
        void adicionaRegistro(NoListaRegistros* p);
        void leArquivo();
        void leArquivo(int a, int b);
        void leArquivo(int tam);

        void imprime();
        void imprime(int a, int b);
        bool vazia();
        void troca(NoListaRegistros *a, NoListaRegistros *b);

    protected:

    private:
        NoListaRegistros *primeiro;
        NoListaRegistros *ultimo;
        int tam;
};

#endif // LISTAREGISTROS_H
