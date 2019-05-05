#include "SupportLib.h"

//@author, @version, @


SupportLib::SupportLib()
{
    //ctor
}

SupportLib::~SupportLib()
{
    //dtor
}

const int SupportLib::getTestes()
{
    return this->TESTES;
}

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
        infile.close();
        return vet;
    }
    else
        cout << endl << "ERRO!";
}

void SupportLib::criaArquivoDeSaida(int tam, int comparacoes, int trocas, double tempo)
{
    fstream saida("saida.txt", ios::app);
    if(saida.is_open())
    {
        saida << tam << " " << comparacoes << " " << trocas << " " << tempo << endl;
        saida.close();
    }
    else
        cout << endl << "ERRO!";
}

void SupportLib::processaArquivoDeSaida(int conj)
{
    int tam=0, comparacoes=0, copias=0, a, b, c;
    double tempo=0, d;
    fstream file("saida.txt");
    if(file.is_open())
    {
        for(int i=0; i<conj; i++)
        {
            for(int j=0; j<this->TESTES; j++)
            {
                file >> a >> b >> c >> d;
                tam=a;
                comparacoes+=b;
                copias+=c;
                tempo+=d;
            }
            cout << endl << endl << "Medias de desempenho:" << endl << endl <<
            "Tamanho: " << tam << endl <<
            "comparacoes: " << comparacoes/this->getTestes() << endl <<
            "copias: " << copias/this->getTestes() << endl <<
            "Tempo: " << tempo/this->getTestes() << endl << "==============================";
            comparacoes=0;
            copias=0;
            tempo=0;
        }

        file.close();
    }
    else
        cout << endl << "ERRO!";
}

Registro* SupportLib::leArquivoRegistro(int a, int b)
{
    Registro *vet=new Registro[b-a];
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
        //cout << endl << "Efetuando a leitura do arquivo, aguarde...";

        while((getline(Myfile, line))&&(counter<b))
        {
            stringstream ss(line);
            getline(ss, userId, ',');
            getline(ss, movieId, ',');
            getline(ss, rating, ',');
            getline(ss, timestamp, ',');

            if((counter<a)||(counter==0))
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
                vet[i]=*p;
                delete p;
                i++;
            }
            //if(counter==1)
                //cout << endl << "Efetuando contagem de registros.\nAguarde..." << endl;
            counter ++;
        }
        //cout << "\n\nLeitura efetuada com sucesso.\nExistem " << counter << " registros no arquivo.";
        return vet;
    }
}

Dupla* SupportLib::leArquivoDupla(int a, int b)
{
    Dupla *vet=new Dupla[b-a];
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
        list<int> chaves;
        list<int>::iterator iter;
        bool estaNaLista;

        int counter=0;
        Dupla *p;
        //cout << endl << "Efetuando a leitura do arquivo, aguarde...";

        while((getline(Myfile, line))&&(counter<b))
        {
            estaNaLista=false;

            stringstream ss(line);
            getline(ss, userId, ',');
            getline(ss, movieId, ',');
            getline(ss, rating, ',');
            getline(ss, timestamp, ',');

            if((counter<a)||(counter==0))
            {
                counter++;
                continue;
            }
            else
            {
                int1=atoi(userId.c_str());
                int2=atoi(movieId.c_str());

                for(iter=chaves.begin(); iter!=chaves.end(); iter++)
                {
                    if(int1==*iter)
                        estaNaLista=true;
                }

                if(estaNaLista)
                {
                    continue;
                }
                else
                {
                    chaves.push_back(int1);
                    p=new Dupla(int1, int2);
                    vet[i]=*p;
                    delete p;
                    i++;
                }

            }
            //if(counter==1)
                //cout << endl << "Efetuando contagem de registros.\nAguarde..." << endl;
            counter ++;
        }
        //cout << "\n\nLeitura efetuada com sucesso.\nExistem " << counter << " registros no arquivo.";
        return vet;
    }
}


Registro* SupportLib::leArquivo(int tam)
{
    //this->preencheVetorAleatorio(v, tam, 0, 26024290);

}

void SupportLib::imprimeConjunto(Registro vet[], int tam)
{
    cout << endl << endl << "UserId\tMovieId\tRating\tTimestamp" << endl <<
    "=============================================" << endl;
    for(int i=0; i<tam; i++)
    {
        cout << endl;
        vet[i].imprime();
    }
    cout << endl;
}

void SupportLib::imprimeConjunto(Registro vet[], int tam, int a, int b)
{
    cout << endl << endl << "UserId\tMovieId\tRating\tTimestamp" << endl <<
    "=============================================" << endl;
    for(int i=a; i<b; i++)
    {
        cout << endl;
        vet[i].imprime();
    }
    cout << endl;
}

void SupportLib::imprimeVetor(int vet[], int tam)
{
    cout << endl;
    for(int i=0; i<tam; i++)
        cout << vet[i] << "  ";
}

void SupportLib::imprimeVetor(float vet[], int tam)
{
    cout << endl;
    for(int i=0; i<tam; i++)
        cout << vet[i] << "  ";
}

void SupportLib::troca(Registro *a, Registro *b)
{
    Registro *aux=new Registro;
    this->copia(a, aux);
    this->copia(b, a);
    this->copia(aux, b);
    delete aux;
}

void SupportLib::troca(Dupla *a, Dupla *b)
{
    Dupla *aux=new Dupla;
    this->copia(a, aux);
    this->copia(b, a);
    this->copia(aux, b);
    delete aux;
}

void SupportLib::copia(Registro *a, Registro *b)
{
    b->setUserId(a->getUserId());
    b->setMovieId(a->getMovieId());
    b->setRating(a->getRating());
    b->setTimestamp(a->getTimestamp());
}

void SupportLib::copia(Dupla *a, Dupla *b)
{
    b->setUserId(a->getUserId());
    b->setMovieId(a->getMovieId());
}

void SupportLib::preencheVetorAleatorio(int vet[], int tam, int limInf, int limSup)
{
    srand(time(NULL)*clock());
    for(int i=0; i<tam; i++)
    {
        vet[i]=(int)rand()%((limSup-limInf)+1);
    }
}

double SupportLib::calculaTempo(time_t t1)
{
    time_t t2=clock();
    return (float)(t2-t1)/CLOCKS_PER_SEC;
}

void SupportLib::quickSortRecursivo(int vet[], int inicio, int fim, int *comparacoes, int *copias)
{
	int i, j, pivo, aux;
	i = inicio;
	j = fim-1;
	pivo = vet[(inicio + fim) / 2];
	while(i <= j)
	{
		while(vet[i] < pivo && i < fim)
		{
			*comparacoes+=1;
			i++;
		}
		while(vet[j] > pivo && j > inicio)
		{
			*comparacoes+=1;
			j--;
		}
		if(i <= j)
		{
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			*copias+=1;
			i++;
			j--;
		}
	}
	if(j > inicio)
		quickSortRecursivo(vet, inicio, j+1, comparacoes, copias);
	if(i < fim)
		quickSortRecursivo(vet, i, fim, comparacoes, copias);
}

void SupportLib::quickSortRecursivo(Registro vet[], int inicio, int fim, int *comparacoes, int *copias)
{
	int i, j, pivo;
	Registro aux;
	i = inicio;
	j = fim-1;
	pivo = vet[(inicio + fim) / 2].getUserId();
	while(i <= j)
	{
		while(vet[i].getUserId() < pivo && i < fim)
		{
			*comparacoes+=1;
			i++;
		}
		while(vet[j].getUserId() > pivo && j > inicio)
		{
			*comparacoes+=1;
			j--;
		}
		if(i <= j)
		{
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			*copias+=1;
			i++;
			j--;
		}
	}
	if(j > inicio)
		quickSortRecursivo(vet, inicio, j+1, comparacoes, copias);
	if(i < fim)
		quickSortRecursivo(vet, i, fim, comparacoes, copias);
}

void SupportLib::quickSortMediana(int vet[], int inicio, int fim, int v)
{
    srand(time(NULL));
    int i, j, pivo, aux;
	i = inicio;
	j = fim-1;

	int *mediana=new int[v];
	for(int i=0; i<v; i++)
    {
        mediana[i]=vet[(int)(rand()%(fim-inicio))+inicio];
    }
    insertionSort(mediana, v);
	pivo = mediana[v/2];
	delete mediana;
	while(i <= j)
	{
		while(vet[i] < pivo && i < fim)
		{
			i++;
		}
		while(vet[j] > pivo && j > inicio)
		{
			j--;
		}
		if(i <= j)
		{
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			i++;
			j--;
		}
	}
	if(j > inicio)
		quickSortMediana(vet, inicio, j+1, v);
	if(i < fim)
		quickSortMediana(vet, i, fim, v);
}

void SupportLib::quickSortInsercao(int vet[], int inicio, int fim, int v)
{
    if(fim-inicio>=v)
    {

        int i, j, pivo, aux;
        i = inicio;
        j = fim-1;
        pivo = vet[(inicio + fim) / 2];
        while(i <= j)
        {
            while(vet[i] < pivo && i < fim)
            {
                i++;
            }
            while(vet[j] > pivo && j > inicio)
            {
                j--;
            }
            if(i <= j)
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                i++;
                j--;
            }
        }
        if(j > inicio)
            quickSortInsercao(vet, inicio, j+1, v);
        if(i < fim)
            quickSortInsercao(vet, i, fim, v);
    }
    else
        this->insertionSort(vet, inicio, fim);
}

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

void SupportLib::insertionSort(int vet[], int inicio, int fim)
{
    int pivot, j;
    for(int i=inicio+1; i<fim; i++)
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

void SupportLib::mergeSort(int vet[], int tam)
{
    //Ainda não implementado.
}

void SupportLib::heapSort(int vet[], int tam)
{
    //Ainda não implementado.
}

void SupportLib::outroSort(int vet[], int tam)
{
    //Ainda não implementado.
}

int SupportLib::enderecamentoHashingLinear(Dupla vet[], int tam, int chave)
{
    //hj=(h(x)+j)mod m --- 1<=j<=m-1
    for(int i=0; i<tam; i++)
    {
        if(vet[((chave%tam)+i)%tam].getUserId()==-1)
            return ((chave%tam)+i)%tam;
    }
    cout << endl << "Nao foi possivel inserir a chave " << chave << " na tabela.";
}

int SupportLib::buscaHashingLinear(Dupla vet[], int tam, int chave)
{
    for(int i=0; i<tam; i++)
    {
        if(vet[((chave%tam)+i)%tam].getUserId()==chave)
            return ((chave%tam)+i)%tam;
    }
    cout << endl << "Nao foi possivel recuperar a chave " << chave << " na tabela.";
}

int SupportLib::enderecamentoHashingQuadratico(Dupla vet[], int tam, int chave)
{
    //hj=(h(x)+j^2)mod m --- 1<=j<=m-1
    for(int i=0; i<tam; i++)
    {
        if(vet[((chave%tam)+(i*i))%tam].getUserId()==-1)
            return ((chave%tam)+(i*i))%tam;
    }
    cout << endl << "Nao foi possivel inserir a chave " << chave << " na tabela.";
}

int SupportLib::buscaHashingQuadratico(Dupla vet[], int tam, int chave)
{
    for(int i=0; i<tam; i++)
    {
        if(vet[((chave%tam)+(i*i))%tam].getUserId()==chave)
            return ((chave%tam)+(i*i))%tam;
    }
    cout << endl << "Nao foi possivel recuperar a chave " << chave << " na tabela.";
}

int SupportLib::enderecamentoDuploHashing(Dupla vet[], int tam, int chave)
{
    //h1 + j * h2
    for(int i=0; i<tam; i++)
    {
        if(vet[((chave%tam)+(i*(2*chave%(tam/3))))%tam].getUserId()==-1)
            return ((chave%tam)+(i*(2*chave%(tam/3))))%tam;
    }
    cout << endl << "Nao foi possivel inserir a chave " << chave << " na tabela.";
}

int SupportLib::buscaDuploHashing(Dupla vet[], int tam, int chave)
{
    for(int i=0; i<tam; i++)
    {
        if(vet[((chave%tam)+(i*(2*chave%(tam/3))))%tam].getUserId()==chave)
            return ((chave%tam)+(i*(2*chave%(tam/3))))%tam;
    }
    cout << endl << "Nao foi possivel recuperar a chave " << chave << " na tabela.";
}

int SupportLib::enderecamentoEncadeamentoSeparado()
{

}

int SupportLib::buscaEncadeamentoSeparado()
{

}

int SupportLib::enderecamentoEncadeamentoCoalescido()
{

}

int SupportLib::buscaEncadeamentoCoalescido()
{

}

