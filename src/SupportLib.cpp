#include "SupportLib.h"

/**
    Construtor padr�o da classe.
    N�o recebe par�metros.
**/
SupportLib::SupportLib()
{
    //ctor
}

/**
    Destrutor da classe.
    N�o recebe par�metros.
**/
SupportLib::~SupportLib()
{
    //dtor
}

/**
    L� o arquivo dos conjuntos de entrada.
    retorna um ponteiro para um vetor de ints.
    recebe como parametro:
        *(int*) v - Ponteiro para um int que receber� o tamanho do vetor de entradas.
**/
int* SupportLib::leArquivoEntrada(int *v)
{
    ifstream infile("entrada.txt");
    int tam, val, *vet, i=0;
    if(infile.is_open())
    {
        infile >> tam;
        *v=tam;
        vet=new int[tam];
        while(!infile.eof())
        {
            infile >> val;
            vet[i]=val;
            i++;
        }
        return vet;
    }
    else
        cout << endl << "ERRO!";
}

/**
    L� completamente o arquivo "ratings.csv";
    N�o possui retorno.
    N�o recebe par�metros.
**/
void SupportLib::leArquivo()
{
    //Ainda n�o implementado.
}

/**
    L� parte do arquivo "ratings.csv".
    N�o possui retorno.
    recebe como par�metros:
        *(int) a - �ndice inicial do conjunto.
        *(int) b - �ndice final do conjunto.
**/
Registro** SupportLib::leArquivo(int a, int b)
{
    Registro** vet=new Registro*[b-a];
    ifstream Myfile("ratings.csv");
    if(!Myfile.is_open())
    {
        cout << "\nERRO!\n";
    }
    else
    {
        string userId, movieId, rating, timestamp;
        double doubleNumber;
        int int1, int2, int3, i=0;
        string line, myStr;

        int counter=0;
        Registro *p;
        cout << endl << "Efetuando a leitura do arquivo, aguarde...";

        while((getline(Myfile, line))&&(counter<b))
        {
            stringstream ss(line);
            getline(ss, userId, ',');
            getline(ss, movieId, ',');
            getline(ss, rating, ',');
            getline(ss, timestamp, ',');

            if(counter<a)
            {
                counter++;
                continue;
            }

            else
            {
                int1=atoi(userId.c_str());
                int2=atoi(movieId.c_str());
                doubleNumber=atof(rating.c_str());
                int3=atoi(timestamp.c_str());

                p=new Registro(int1, int2, doubleNumber, int3);
                vet[i]=p;
                i++;
            }
            if(counter==1)
                cout << endl << "Efetuando contagem de registros.\nAguarde..." << endl;
            counter ++;
        }
        cout << "\n\nLeitura efetuada com sucesso.\nExistem " << counter << " registros no arquivo.";
        return vet;
    }
}

/**
    L� um conjunto aleat�rio de dados do arquivo "ratings.csv".
    N�o possui retorno.
    recebe como par�metro:
        *(int) tam - tamanho do conjunto de registros.
**/
void SupportLib::leArquivo(int tam)
{
    //Ainda n�o implementado.
}

/**
    Imprime completamente um conjunto.
    N�o possui retorno.
    Recebe como par�metro:
        *(Registro*) vet - Conjunto de registros.
        *(int) tam - Tamanho do conjunto.
**/
void SupportLib::imprimeConjunto(Registro *vet[], int tam)
{
    cout << endl << endl << "UserId\tMovieId\tRating\tTimestamp" << endl <<
    "=============================================" << endl;
    for(int i=0; i<tam; i++)
    {
        cout << endl;
        vet[i]->imprime();
    }
    cout << endl;
}

/**
    Imprime parcialmente um conjunto.
    N�o possui retorno.
    Recebe como par�metro:
        *(Registro*) vet - Conjunto de registros.
        *(int) tam - Tamanho do conjunto.
        *(int) a - �ndice inicial do conjunto.
        *(int) a - �ndice final do conjunto.
**/
void SupportLib::imprimeConjunto(Registro *vet[], int tam, int a, int b)
{
    cout << endl << endl << "UserId\tMovieId\tRating\tTimestamp" << endl <<
    "=============================================" << endl;
    for(int i=a; i<b; i++)
    {
        cout << endl;
        vet[i]->imprime();
    }
    cout << endl;
}

/**
    Troca os valores de 2 registros.
    N�o possui retorno.
    Recebe como par�metro:
        *(Registro*) a - Registro 1.
        *(Registro*) b - Registro 2.
**/
void SupportLib::troca(Registro *a, Registro *b)
{
    Registro *aux=new Registro;
    this->copia(a, aux);
    this->copia(b, a);
    this->copia(aux, b);
    delete aux;
}

/**
    Troca os valores de 2 Duplas.
    N�o possui retorno.
    Recebe como par�metro:
        *(Dupla*) a - Dupla 1.
        *(Dupla*) b - Dupla 2.
**/
void SupportLib::troca(Dupla *a, Dupla *b)
{
    Dupla *aux=new Dupla;
    this->copia(a, aux);
    this->copia(b, a);
    this->copia(aux, b);
    delete aux;
}

/**
    Copia os valores de um registro para outro.
    N�o possui retorno.
    Recebe como par�metro:
        *(Registro*) a - Registro de origem.
        *(Registro*) b - Registro de destino.
**/
void SupportLib::copia(Registro *a, Registro *b)
{
    b->setUserId(a->getUserId());
    b->setMovieId(a->getMovieId());
    b->setRating(a->getRating());
    b->setTimestamp(a->getTimestamp());
}

/**
    Copia os valores de uma Dupla para outra.
    N�o possui retorno.
    Recebe como par�metro:
        *(Dupla*) a - Dupla de origem.
        *(Dupla*) b - Dupla de destino.
**/
void SupportLib::copia(Dupla *a, Dupla *b)
{
    b->setUserId(a->getUserId());
    b->setMovieId(a->getMovieId());
}

/**
    Ordena um vetor de ints por meio de insertion sort.
    N�o possui retorno.
    Recebe como par�metro:
        *(int) vet[] - Vetor de valores inteiros.
        *(int) tam - Tamanho do vetor.
**/
void SupportLib::insertionSort(int vet[], int tam)
{
    int pivot, j;
    for(int i=1; i<tam; i++)
    {
        pivot=vet[i];
        j=i-1;
        while((j>=0)&&(vet[j]>pivot))
        {
            vet[j+1]=vet[j];
            j--;
        }
        vet[j+1]=pivot;
    }
}

/**
    Ordena um vetor de ints por meio de mergesort.
    N�o possui retorno.
    Recebe como par�metro:
        *(int) vet[] - Vetor de valores inteiros.
        *(int) tam - Tamanho do vetor.
**/
void SupportLib::mergeSort(int vet[], int tam)
{
    //Ainda n�o implementado.
}

/**
    Ordena um vetor de ints por meio de heapsort.
    N�o possui retorno.
    Recebe como par�metro:
        *(int) vet[] - Vetor de valores inteiros.
        *(int) tam - Tamanho do vetor.
**/
void SupportLib::heapSort(int vet[], int tam)
{
    //Ainda n�o implementado.
}

/**
    Ordena um vetor de ints por meio de outrosort.
    N�o possui retorno.
    Recebe como par�metro:
        *(int) vet[] - Vetor de valores inteiros.
        *(int) tam - Tamanho do vetor.
**/
void SupportLib::outroSort(int vet[], int tam)
{
    //Ainda n�o implementado.
}

/**
    Ordena um vetor de ints por meio de quicksort recursivo.
    N�o possui retorno.
**/
void SupportLib::quickSortRecursivo(int vet[], int tam, int v)
{
    //Ainda n�o implementado.
}

/**
    Ordena um vetor de ints por meio de quicksort mediana.
    N�o possui retorno.
**/
void SupportLib::quickSortMediana(int vet[], int tam, int v)
{
    //Ainda n�o implementado.
}

/**
    Ordena um vetor de ints por meio de quicksort inser��o.
    N�o possui retorno.
**/
void SupportLib::quickSortInsercao(int vet[], int tam, int v)
{
    //Ainda n�o implementado.
}


