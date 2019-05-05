#include <iostream>
#include <fstream>
#include "Registro.h"
#include "SupportLib.h"

using namespace std;

///<<<<<<<<<<<<<<<<< Contabilizar n. comparações de chaves, n. copia de registros, tempo de cpu;
    ///<<<<<<<<<<<<<<<<<  mergesort, heapsort, meusort
    ///Cada elemento do vetor deve ser constituído de uma dupla ( USERID, MOVIEID)
    ///Endereçamento – Sondagem Linear
    ///Endereçamento – Sondagem Quadrática
    ///Endereçamento – Duplo Hash
    ///Encadeamento Separado
    ///Encadeamento Coalescido (sem porão)

void cenario01()
{
    SupportLib support;
    int tamanhoEntradas, comparacoes=0, copias=0;
    int *entradas=support.leArquivoEntrada(&tamanhoEntradas);
    double tempo;
    Registro *conjunto;
    ///int *conj;
    fstream saida("saida.txt", ios::out);
    //saida << "Tamanho Comparações Trocas Tempo" << endl;
    saida.close();

    for(int i=0; i<tamanhoEntradas; i++)/// A variável i itera através do vetor com os tamanhos dos conjuntos de entradas.
    {
        for(int j=0; j<support.getTestes(); j++)/// A variável j itera pelos 5 conjuntos que devem ser criados.
        {
            conjunto=new Registro[entradas[i]];
            conjunto=support.leArquivoRegistro(1, entradas[i]+1);
            //support.imprimeConjunto(conjunto, entradas[i]);
            time_t t1=clock();
            support.quickSortRecursivo(conjunto, 0, entradas[i], &comparacoes, &copias);
            tempo=support.calculaTempo(t1);
            support.criaArquivoDeSaida(entradas[i], comparacoes, copias, tempo);
            comparacoes=0;
            copias=0;
            tempo=0;
        }
    }
    support.processaArquivoDeSaida(tamanhoEntradas);
}

void cenario02()
{

}

void cenario03()
{

}

void cenario04()
{
    SupportLib support;
    int tamanhoEntradas, comparacoes=0, copias=0;
    int *entradas=support.leArquivoEntrada(&tamanhoEntradas);
    double tempo;
    Dupla *conjuntoDuplas;
    for(int i=0; i<tamanhoEntradas; i++)/// A variável i itera através do vetor com os tamanhos dos conjuntos de entradas.
    {
        for(int j=0; j<support.getTestes(); j++)/// A variável j itera pelos 5 conjuntos que devem ser criados.
        {

        }
    }
}

int main()
{
    //cenario01();
    SupportLib support;
    int tam=101;
    Dupla *v=new Dupla[tam];
    Dupla *aux=support.leArquivoDupla(1, tam+1);

    for(int i=0; i<tam; i++)
    {
        v[i]=Dupla(-1, -1);
    }

    for(int i=0; i<tam; i++)
    {
        v[support.enderecamentoDuploHashing(v,tam,aux[i].getUserId())]=aux[i];
    }

    for(int i=0; i<tam; i++)
    {
        cout << endl << "[" << i << "]\t" << v[i].getUserId() << "\t" << v[i].getMovieId();
    }

    int ans;
    do
    {
        cout << endl << "Digite uma chave: ";
        cin >> ans;
        cout << endl << "A chave esta na posicao " << support.buscaDuploHashing(v, tam, ans);

    }while(ans!=-1);

    return 0;
}
