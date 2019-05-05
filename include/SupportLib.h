#ifndef SUPPORTLIB_H
#define SUPPORTLIB_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Registro.h"
#include "Dupla.h"
using namespace std;

    /**
        Classe contendo v�rias fun��es para impress�o, ordena��o, etc.

        @brief Classe de suporte.
    */
class SupportLib
{

    public:
        /**
            @brief Construtor da classe.
        */
        SupportLib();

        /**
            @brief Destrutor da classe.
        */
        virtual ~SupportLib();

        /**
            @brief Retorna o n�mero de testes a serem executados.

            @return Valor de TESTES.
        */
        const int getTestes();

        /**
            Efetua a leitura do arquivo de entrada (entrada.txt) que cont�m os tamanhos
            dos conjuntos a serem gerados para ordena��o e retorna um vetor com esses dados.

            @brief L� o arquivo de entrada.

            @param v - ponteiro para o vetor de entradas.

            @return Ponteiro para o vetor de entradas.
        */
        int *leArquivoEntrada(int *v);

        /**
            @brief Cria um arquivo de sa�da com os resultados do desempenho da ordena��o.

            @param tam - Tamanho do conjunto lido.
            @param comparacoes - Numero de compara��es efetuadas.
            @param copias - Numero de c�pias efetuadas.
            @param tempo - Tempo decorrido durante o processo.
        */
        void criaArquivoDeSaida(int tam, int comparacoes, int trocas, double tempo);

        /**
            @brief Processa o arquivo de sa�da, calculando as m�dias de desempenho.

            @param conj - N�mero de conjuntos processados.
        */
        void processaArquivoDeSaida(int conj);

        /**
            Faz a leitura do arquivo de registros de um �ndice at� o outro.

            @brief L� um intervalo de registros.

            @param a - Indice inicial.
            @param b - Indice final.

            @return Ponteiro para o conjunto de registros.
        */
        Registro* leArquivoRegistro(int a, int b);

        /**
            Faz a leitura do arquivo de registros de um �ndice at� o outro, retornando um conjunto de duplas.

            @brief L� um conjunto de duplas.

            @param a - Indice inicial.
            @param b - Indice final.

            @return Ponteiro para o conjunto de duplas.
        */
        Dupla* leArquivoDupla(int a, int b);

        /**
            Gera um conjunto de registros de tamanho m.

            @brief L� um conjunto aleat�rio de registros.

            @param tam - Tamanho do conjunto.

            @return Ponteiro para o conjunto de registros.
        */
        Registro* leArquivo(int tam);

        /**
            @brief Imprime completamente um conjunto de registros.

            @param vet - Vetor de registros.
            @param tam - Tamanho do vetor.
        */
        void imprimeConjunto(Registro vet[], int tam);

        /**
            Imprime um conjunto de registros de um �ndice at� o outro.

            @brief Imprime parcialmente um conjunto de registros.

            @param vet - Vetor de registros.
            @param tam - Tamanho do vetor.
            @param a - �ndice inicial.
            @param b - �ndice final.
        */
        void imprimeConjunto(Registro vet[], int tam, int a, int b);

        /**
            @brief Imprime um vetor de ints.

            @param vet - Vetor de ints.
            @param tam - Tamanho do vetor.
        */
        void imprimeVetor(int vet[], int tam);

        /**
            @brief Imprime um vetor de floats.

            @param vet - Vetor de floats.
            @param tam - Tamanho do vetor.
        */
        void imprimeVetor(float vet[], int tam);

        /**
            @brief Troca os valores de dois registros.

            @param a - ponteiro para um registro.
            @param b - ponteiro para um registro.
        */
        void troca(Registro *a, Registro *b);

        /**
            @brief Troca os valores de duas duplas.

            @param a - ponteiro para uma dupla.
            @param b - ponteiro para uma dupla.
        */
        void troca(Dupla *a, Dupla *b);

        /**
            @brief Copia os valores de um registro para outro.

            @param a - ponteiro para o registro de origem.
            @param b - ponteiro para o registro de destino.
        */
        void copia(Registro *a, Registro *b);

        /**
            @brief Copia os valores de uma dupla para outra.

            @param a - ponteiro para a dupla de origem.
            @param b - ponteiro para a dupla de destino.
        */
        void copia(Dupla *a, Dupla *b);

        /**
            Preenche o vetor com valores aleat�rios entre limInf e limSup.

            @brief Preenche um vetor de ints com valores aleat�rios.

            @param vet - Vetor de ints.
            @param tam - Tamanho do vetor.
            @param limInf - Limite inferior.
            @param limSup - Limite superior.
        */
        void preencheVetorAleatorio(int vet[], int tam, int limInf, int limSup);

        /**
            Calcula o tempo de cpu decorrido entre t1 e o chamado da fun��o.

            @brief Calcula o tempo de execu��o de um determinado processo.

            @param t1 - Tempo inicial.
        */
        double calculaTempo(time_t t1);

        /**
            @brief Ordena um vetor de ints por meio de quickSort.

            @param vet - Vetor de ints.
            @param tam - Tamanho do vetor.
        */
        void quickSortRecursivo(int vet[], int inicio, int fim, int *comparacoes, int *copias);

        /**
            @brief Ordena um vetor de Registros por meio de quickSort.

            @param vet - Vetor de Registros.
            @param tam - Tamanho do vetor.
        */
        void quickSortRecursivo(Registro vet[], int inicio, int fim, int *comparacoes, int *copias);

        /**
            Seleciona v elementos aleat�rios, dos quais a mediana ser� escolhida como piv�.
            @brief Ordena um vetor de Registros por meio de quickSort.

            @param vet - Vetor de ints.
            @param tam - Tamanho do vetor.
            @param v - Numero de elementos aleat�rios.
        */
        void quickSortMediana(int vet[], int inicio, int fim, int v);

        /**
            Aplica recursivamente o quicksort, at� que atinja uma parti��o de tamanho
            menor ou igual a v, ent�o aplica insertionSort nesta parti��o.
            @brief Ordena um vetor de Registros por meio de quickSort.

            @param vet - Vetor de ints.
            @param tam - Tamanho do vetor.
            @param v - Tamanho da parti��o a ser aplicado o insertionSort.
        */
        void quickSortInsercao(int vet[], int inicio, int fim, int v);

        /**
            @brief Ordena um vetor de ints por meio de InsertionSort.

            @param vet - Vetor de ints.
            @param tam - Tamanho do vetor.
        */
        void insertionSort(int vet[], int tam);

        /**
            @brief Ordena parte de um vetor de ints por meio de InsertionSort.

            @param vet - Vetor de ints.
            @param inicio - Indice do inicio do sub vetor.
            @param fim - Indice do fim do sub vetor.
        */
        void insertionSort(int vet[], int inicio, int fim);

        /**
            @brief Ordena um vetor de ints por meio de MergeSort.

            @param vet - Vetor de ints.
            @param tam - Tamanho do vetor.
        */
        void mergeSort(int vet[], int tam);

        /**
            @brief Ordena um vetor de ints por meio de HeapSort.

            @param vet - Vetor de ints.
            @param tam - Tamanho do vetor.
        */
        void heapSort(int vet[], int tam);

        /**
            @brief Ordena um vetor de ints por meio de OutroSort.

            @param vet - Vetor de ints.
            @param tam - Tamanho do vetor.
        */
        void outroSort(int vet[], int tam);

        /**
            Os �ndices s�o gerados pela fun��o: ((chave mod tam)+i)mod tam, com i variando de 0 a tam. \\n
            A forma geral deste tipo de endere�amento � Hi = (F(x)+i).

            @brief Gera um �ndice para tabela hash por hashing linear.

            @param vet - Vetor de duplas representando a tabela.
            @param tam - Tamanho da tabela.
            @param chave - chave a ser inserida na fun��o hash.

            @return �ndice gerado para a chave.
        */
        int enderecamentoHashingLinear(Dupla vet[], int tam, int chave);

        /**
            @brief Recupera o �ndice de uma chave inserida na tabela por hashing linear.

            @param vet - Vetor de duplas representando a tabela.
            @param tam - Tamanho da tabela.
            @param chave - chave cujo �ndice ser� recuperado.

            @return �ndice da chave.
        */
        int buscaHashingLinear(Dupla vet[], int tam, int chave);

        /**
            Os �ndices s�o gerados pela fun��o: ((chave mod tam)+i^2)mod tam, com i variando de 0 a tam. \\n
            A forma geral deste tipo de endere�amento � Hi = (F(x)+i^2).

            @brief Gera um �ndice para tabela hash por hashing quadr�tico.

            @param vet - Vetor de duplas representando a tabela.
            @param tam - Tamanho da tabela.
            @param chave - chave a ser inserida na fun��o hash.

            @return �ndice gerado para a chave.
        */
        int enderecamentoHashingQuadratico(Dupla vet[], int tam, int chave);

        /**
            @brief Recupera o �ndice de uma chave inserida na tabela por hashing quadr�tico.

            @param vet - Vetor de duplas representando a tabela.
            @param tam - Tamanho da tabela.
            @param chave - chave cujo �ndice ser� recuperado.

            @return �ndice da chave.
        */
        int buscaHashingQuadratico(Dupla vet[], int tam, int chave);

        /**
            Os �ndices s�o gerados pela fun��o: ((chave mod tam)+i(2*chave mod (tam/3)))mod tam, com i variando de 0 a tam. \\n
            A forma geral deste tipo de endere�amento � Hi = (F1(x)+i(F2(x))).

            @brief Gera um �ndice para tabela hash por duplo hashing.

            @param vet - Vetor de duplas representando a tabela.
            @param tam - Tamanho da tabela.
            @param chave - chave a ser inserida na fun��o hash.

            @return �ndice gerado para a chave.
        */
        int enderecamentoDuploHashing(Dupla vet[], int tam, int chave);

        /**
            @brief Recupera o �ndice de uma chave inserida na tabela por duplo hashing.

            @param vet - Vetor de duplas representando a tabela.
            @param tam - Tamanho da tabela.
            @param chave - chave cujo �ndice ser� recuperado.

            @return �ndice da chave.
        */
        int buscaDuploHashing(Dupla vet[], int tam, int chave);

        int enderecamentoEncadeamentoSeparado();
        int buscaEncadeamentoSeparado();
        int enderecamentoEncadeamentoCoalescido();
        int buscaEncadeamentoCoalescido();


    protected:

    private:
        ///Numero de testes a serem executados
        const int TESTES=5;
};

#endif // SUPPORTLIB_H
