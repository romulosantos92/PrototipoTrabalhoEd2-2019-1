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
        Classe contendo várias funções para impressão, ordenação, etc.

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
            @brief Retorna o número de testes a serem executados.

            @return Valor de TESTES.
        */
        const int getTestes();

        /**
            Efetua a leitura do arquivo de entrada (entrada.txt) que contém os tamanhos
            dos conjuntos a serem gerados para ordenação e retorna um vetor com esses dados.

            @brief Lê o arquivo de entrada.

            @param v - ponteiro para o vetor de entradas.

            @return Ponteiro para o vetor de entradas.
        */
        int *leArquivoEntrada(int *v);

        /**
            @brief Cria um arquivo de saída com os resultados do desempenho da ordenação.

            @param tam - Tamanho do conjunto lido.
            @param comparacoes - Numero de comparações efetuadas.
            @param copias - Numero de cópias efetuadas.
            @param tempo - Tempo decorrido durante o processo.
        */
        void criaArquivoDeSaida(int tam, int comparacoes, int trocas, double tempo);

        /**
            @brief Processa o arquivo de saída, calculando as médias de desempenho.

            @param conj - Número de conjuntos processados.
        */
        void processaArquivoDeSaida(int conj);

        /**
            Faz a leitura do arquivo de registros de um índice até o outro.

            @brief Lê um intervalo de registros.

            @param a - Indice inicial.
            @param b - Indice final.

            @return Ponteiro para o conjunto de registros.
        */
        Registro* leArquivoRegistro(int a, int b);

        /**
            Faz a leitura do arquivo de registros de um índice até o outro, retornando um conjunto de duplas.

            @brief Lê um conjunto de duplas.

            @param a - Indice inicial.
            @param b - Indice final.

            @return Ponteiro para o conjunto de duplas.
        */
        Dupla* leArquivoDupla(int a, int b);

        /**
            Gera um conjunto de registros de tamanho m.

            @brief Lê um conjunto aleatório de registros.

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
            Imprime um conjunto de registros de um índice até o outro.

            @brief Imprime parcialmente um conjunto de registros.

            @param vet - Vetor de registros.
            @param tam - Tamanho do vetor.
            @param a - Índice inicial.
            @param b - Índice final.
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
            Preenche o vetor com valores aleatórios entre limInf e limSup.

            @brief Preenche um vetor de ints com valores aleatórios.

            @param vet - Vetor de ints.
            @param tam - Tamanho do vetor.
            @param limInf - Limite inferior.
            @param limSup - Limite superior.
        */
        void preencheVetorAleatorio(int vet[], int tam, int limInf, int limSup);

        /**
            Calcula o tempo de cpu decorrido entre t1 e o chamado da função.

            @brief Calcula o tempo de execução de um determinado processo.

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
            Seleciona v elementos aleatórios, dos quais a mediana será escolhida como pivô.
            @brief Ordena um vetor de Registros por meio de quickSort.

            @param vet - Vetor de ints.
            @param tam - Tamanho do vetor.
            @param v - Numero de elementos aleatórios.
        */
        void quickSortMediana(int vet[], int inicio, int fim, int v);

        /**
            Aplica recursivamente o quicksort, até que atinja uma partição de tamanho
            menor ou igual a v, então aplica insertionSort nesta partição.
            @brief Ordena um vetor de Registros por meio de quickSort.

            @param vet - Vetor de ints.
            @param tam - Tamanho do vetor.
            @param v - Tamanho da partição a ser aplicado o insertionSort.
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
            Os índices são gerados pela função: ((chave mod tam)+i)mod tam, com i variando de 0 a tam. \\n
            A forma geral deste tipo de endereçamento é Hi = (F(x)+i).

            @brief Gera um índice para tabela hash por hashing linear.

            @param vet - Vetor de duplas representando a tabela.
            @param tam - Tamanho da tabela.
            @param chave - chave a ser inserida na função hash.

            @return Índice gerado para a chave.
        */
        int enderecamentoHashingLinear(Dupla vet[], int tam, int chave);

        /**
            @brief Recupera o índice de uma chave inserida na tabela por hashing linear.

            @param vet - Vetor de duplas representando a tabela.
            @param tam - Tamanho da tabela.
            @param chave - chave cujo índice será recuperado.

            @return Índice da chave.
        */
        int buscaHashingLinear(Dupla vet[], int tam, int chave);

        /**
            Os índices são gerados pela função: ((chave mod tam)+i^2)mod tam, com i variando de 0 a tam. \\n
            A forma geral deste tipo de endereçamento é Hi = (F(x)+i^2).

            @brief Gera um índice para tabela hash por hashing quadrático.

            @param vet - Vetor de duplas representando a tabela.
            @param tam - Tamanho da tabela.
            @param chave - chave a ser inserida na função hash.

            @return Índice gerado para a chave.
        */
        int enderecamentoHashingQuadratico(Dupla vet[], int tam, int chave);

        /**
            @brief Recupera o índice de uma chave inserida na tabela por hashing quadrático.

            @param vet - Vetor de duplas representando a tabela.
            @param tam - Tamanho da tabela.
            @param chave - chave cujo índice será recuperado.

            @return Índice da chave.
        */
        int buscaHashingQuadratico(Dupla vet[], int tam, int chave);

        /**
            Os índices são gerados pela função: ((chave mod tam)+i(2*chave mod (tam/3)))mod tam, com i variando de 0 a tam. \\n
            A forma geral deste tipo de endereçamento é Hi = (F1(x)+i(F2(x))).

            @brief Gera um índice para tabela hash por duplo hashing.

            @param vet - Vetor de duplas representando a tabela.
            @param tam - Tamanho da tabela.
            @param chave - chave a ser inserida na função hash.

            @return Índice gerado para a chave.
        */
        int enderecamentoDuploHashing(Dupla vet[], int tam, int chave);

        /**
            @brief Recupera o índice de uma chave inserida na tabela por duplo hashing.

            @param vet - Vetor de duplas representando a tabela.
            @param tam - Tamanho da tabela.
            @param chave - chave cujo índice será recuperado.

            @return Índice da chave.
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
