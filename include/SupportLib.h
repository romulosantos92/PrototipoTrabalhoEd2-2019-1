#ifndef SUPPORTLIB_H
#define SUPPORTLIB_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Registro.h"
#include "Dupla.h"
using namespace std;

class SupportLib
{
    ///<<<<<<<<<<<<<<<<< Contabilizar n. comparações de chaves, n. copia de registros, tempo de cpu;
    ///<<<<<<<<<<<<<<<<<  mergesort, heapsort, meusort
    ///Cada elemento do vetor deve ser constituído de uma dupla ( USERID, MOVIEID)
    ///Endereçamento – Sondagem Linear
    ///Endereçamento – Sondagem Quadrática
    ///Endereçamento – Duplo Hash
    ///Encadeamento Separado
    ///Encadeamento Coalescido (sem porão)
    public:
        SupportLib();
        virtual ~SupportLib();
        int *leArquivoEntrada(int *v);
        void criaArquivoDeSaida();///<<<<<<<<<<<<<<<<<<<<<<<<<<
        void leArquivo();///<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        Registro** leArquivo(int a, int b);
        void leArquivo(int tam);///<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        void imprimeConjunto(Registro *vet[], int tam);
        void imprimeConjunto(Registro *vet[], int tam, int a, int b);

        void troca(Registro *a, Registro *b);
        void troca(Dupla *a, Dupla *b);
        void copia(Registro *a, Registro *b);
        void copia(Dupla *a, Dupla *b);

        void insertionSort(int vet[], int tam);
        void mergeSort(int vet[], int tam);///<<<<<<<<<<<<<<<<<<<<<<<
        void heapSort(int vet[], int tam);///<<<<<<<<<<<<<<<<<<<<<<<<
        void outroSort(int vet[], int tam);///<<<<<<<<<<<<<<<<<<<<<<<
        void quickSortRecursivo(int vet[], int tam, int v);///<<<<<<<<<<<<<<<<<<<<<
        void quickSortMediana(int vet[], int tam, int v);///<<<<<<<<<<<<<<<<<<<<<<<
        void quickSortInsercao(int vet[], int tam, int v);///<<<<<<<<<<<<<<<<<<<<<<

        void hashingEnderecamentoLinear();///<<<<<<<<<<<<<<<<<<<<<<
        void hashingBuscaLinear();///<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        void hashingEnderecamentoQuadratico();///<<<<<<<<<<<<<<<<<<
        void hashingBuscaQuadratica();///<<<<<<<<<<<<<<<<<<<<<<<<<<
        void hashingEnderecamentoDuplo();///<<<<<<<<<<<<<<<<<<<<<<<
        void hashingBuscaDupla();///<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


    protected:

    private:
};

#endif // SUPPORTLIB_H
