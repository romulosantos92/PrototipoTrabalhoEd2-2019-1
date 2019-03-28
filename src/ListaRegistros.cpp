#include "ListaRegistros.h"


ListaRegistros::ListaRegistros()
{
    //ctor
    this->primeiro=NULL;
    this->ultimo=NULL;
    this->tam=0;
}

ListaRegistros::~ListaRegistros()
{
    //dtor
}

/**
    retorna um ponteiro para o primeiro elemento da lista.
**/
NoListaRegistros* ListaRegistros::getPrimeiro()
{
    return this->primeiro;
}

/**
    seta o primeiro elemento da lista.
**/
void ListaRegistros::setPrimeiro(NoListaRegistros* p)
{
    this->primeiro=p;
}

/**
    Retorna o ultimo elemento da lista.
**/
NoListaRegistros* ListaRegistros::getUltimo()
{
    return this->ultimo;
}

/**
    Seta o ultimo elemento da lista.
**/
void ListaRegistros::setUltimo(NoListaRegistros* p)
{
    this->ultimo=p;
}

/**
    retorna o tamanho(int) da lista.
**/
int ListaRegistros::getTam()
{
    return this->tam;
}

/**
    seta o tamanho da lista com o valor de v.
**/
void ListaRegistros::setTam(int v)
{
    this->tam=v;
}

/**
    Adiciona um registro na lista.
**/
void ListaRegistros::adicionaRegistro(NoListaRegistros* p)
{
    if(vazia())
    {
        this->setPrimeiro(p);
        this->setUltimo(p);
    }
    else
    {
        this->getUltimo()->setProx(p);
        this->setUltimo(this->getUltimo()->getProx());

    }
    this->setTam(this->getTam()+1);
}

/**
    Le dados de um arquivo inteiro.
**/
void ListaRegistros::leArquivo()
{
    char fileName[50];
    cout << "\nDigite o nome do arquivo:\n";
    string str;
    //scanf("%s", fileName);
    gets(fileName);

    ifstream Myfile(fileName);
    if(!Myfile.is_open())
    {
        cout << "\nERROR!\n";
    }
    else
    {
        string userId, movieId, rating, timestamp;
        double doubleNumber;
        int int1, int2, int3;
        string line, myStr;

        int counter=0;
        NoListaRegistros *p;

        while(getline(Myfile, line))
        {
            stringstream ss(line);
            getline(ss, userId, ',');
            getline(ss, movieId, ',');
            getline(ss, rating, ',');
            getline(ss, timestamp, ',');

            if(counter==0)
            {
                counter++;
                continue;
                //cout << "\n" << userId << "\t" << movieId << "\t" << rating <<
                //"\t" << timestamp << "\n====================================\n";
            }

            else
            {
                int1=atoi(userId.c_str());
                int2=atoi(movieId.c_str());
                doubleNumber=atof(rating.c_str());
                int3=atoi(timestamp.c_str());



                p=new NoListaRegistros(int1, int2, doubleNumber, int3);
                this->adicionaRegistro(p);
            }
            if(counter==1)
                cout << endl << "Efetuando contagem de registros.\nAguarde..." << endl;
            counter ++;
        }
        cout << "\n\nLeitura efetuada com sucesso.\nExistem " << counter << " registros no arquivo.";
        this->setTam(counter);
    }
}

/**
    Le dados de um arquivo do indice a ate o indice b.
**/
void ListaRegistros::leArquivo(int a, int b)
{
    char fileName[50];
    //cout << "\nDigite o nome do arquivo:\n";
    string str;
    //gets(fileName);

    ifstream Myfile("ratings.csv");
    if(!Myfile.is_open())
    {
        cout << "\nERROR!\n";
    }
    else
    {
        string userId, movieId, rating, timestamp;
        double doubleNumber;
        int int1, int2, int3;
        string line, myStr;

        int counter=0;
        NoListaRegistros *p;

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
                //cout << "\n" << userId << "\t" << movieId << "\t" << rating <<
                //"\t" << timestamp << "\n====================================\n";
            }

            else
            {
                int1=atoi(userId.c_str());
                int2=atoi(movieId.c_str());
                doubleNumber=atof(rating.c_str());
                int3=atoi(timestamp.c_str());



                p=new NoListaRegistros(int1, int2, doubleNumber, int3);
                this->adicionaRegistro(p);
            }
            if(counter==1)
                cout << endl << "Efetuando contagem de registros.\nAguarde..." << endl;
            counter ++;
        }
        cout << "\n\nLeitura efetuada com sucesso.\nExistem " << counter << " registros no arquivo.";
        this->setTam(counter);
    }

}

/**
    Le (tam) dados aleatoriamente de um arquivo.
**/
void ListaRegistros::leArquivo(int tam)
{
    char fileName[50];
    //cout << "\nDigite o nome do arquivo:\n";
    string str;
    //gets(fileName);

    ifstream Myfile("ratings.csv");
    if(!Myfile.is_open())
    {
        cout << "\nERROR!\n";
    }
    else
    {
        string userId, movieId, rating, timestamp;
        double doubleNumber;
        int int1, int2, int3, index;
        srand(time(NULL));
        int counter=0;
        NoListaRegistros *p;
        char line[31];

        cout << endl << "Efetuando contagem de registros.\nAguarde..." << endl;
        while(counter<tam)
        {
            Myfile.seekg(rand(), ios::beg);

            Myfile.read(line,100);
            cout << line << endl << "===============" << endl;
            counter++;
        }
        /**
        rgargagaerrggg
        rgrawggawgawgg
        wrgawgwgwhgwgw
        wgwgwgwgqgqgqh
        qgq4hq4hq4gq34
        q4gq4hq34hq3hq
        q3hq34hq3hq34h
        **/
    }

}

/**
    Imprime os valores da lista.
**/
void ListaRegistros::imprime()
{
    cout << endl << "UserId\tMovieId\tRating\tTimestamp" << endl <<
    "====================================" << endl;
    NoListaRegistros *p=this->getPrimeiro();
    while(p!=NULL)
    {
        p->imprime();
        p=p->getProx();
    }
    cout << endl << endl;
}

/**
    Imprime lista do indice a ate o indice b.
**/
void ListaRegistros::imprime(int a, int b)
{
    if(b>this->getTam())
    {
        cout << endl << "ERROR!" << endl;
    }
    else
    {
        cout << endl << "UserId\tMovieId\tRating\tTimestamp" << endl <<
        "====================================" << endl;
        int index=0;
        NoListaRegistros* p=this->getPrimeiro();
        while(index!=a)
        {
            p=p->getProx();
            index++;
        }
        for(int i=a; i<b; i++)
        {
            p->imprime();
            p=p->getProx();
        }
    }
    cout << endl << endl;
}

/**
    Verifica se a lista está vazia.
**/
bool ListaRegistros::vazia()
{
    return this->primeiro==NULL;
}

/**
    Troca o elemento a de posição com o elemento b.
**/
void ListaRegistros::troca(NoListaRegistros *a, NoListaRegistros *b)
{
    int int1, int2, int4;
    double dbl;

    int1=a->getUserId();
    int2=a->getMovieId();
    int4=a->getTimestamp();
    dbl=a->getRating();

    a->setUserId(b->getUserId());
    a->setMovieId(b->getMovieId());
    a->setTimeStamp(b->getTimestamp());
    a->setRating(b->getRating());

    b->setUserId(int1);
    b->setMovieId(int2);
    b->setTimeStamp(int4);
    b->setRating(dbl);
}

