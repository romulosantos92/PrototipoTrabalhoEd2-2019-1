#include "NoListaRegistros.h"

/**
    Construtor da classe.
    Inicia atributos com valores nulos.
**/
NoListaRegistros::NoListaRegistros()
{
    //ctor
    this->prox=NULL;
    this->userId=0;
    this->movieId=0;
    this->rating=0;
    this->timestamp=0;
}

/**
    Construtor da classe.
    Inicia atributos com valores passados por parametro.
**/
NoListaRegistros::NoListaRegistros(int userId, int movieId, double rating, int timestamp)
{
    //ctor
    this->prox=NULL;
    this->userId=userId;
    this->movieId=movieId;
    this->rating=rating;
    this->timestamp=timestamp;
}

NoListaRegistros::~NoListaRegistros()
{
    //dtor
}

/**
    Retorna User Id(int).
**/
int NoListaRegistros::getUserId()
{
    return this->userId;
}

/**
    Seta User Id com o valor de  v(int).
**/
void NoListaRegistros::setUserId(int v)
{
    this->userId=v;
}

/**
    Retorna o valor de Movie Id(int).
**/
int NoListaRegistros::getMovieId()
{
    return this->movieId;
}

/**
    Seta Movie Id com o valor de  v(int).
**/
void NoListaRegistros::setMovieId(int v)
{
    this->movieId=v;
}

/**
    retorna o valor de rating(double).
**/
double NoListaRegistros::getRating()
{
    return this->rating;
}

/**
    Seta Rating com o valor de v(double).
**/
void NoListaRegistros::setRating(double v)
{
    this->rating=v;
}

/**
    Retorna o valor de Timestamp(int).
**/
int NoListaRegistros::getTimestamp()
{
    return this->timestamp;
}

/**
    Seta Timestamp com o valor de v(int).
**/
void NoListaRegistros::setTimeStamp(int v)
{
    this->timestamp=v;
}

/**
    Retorna um ponteiro para o próximo nó.
**/
NoListaRegistros* NoListaRegistros::getProx()
{
    return this->prox;
}

/**
    seta o ponteiro para o próximo nó.
**/
void NoListaRegistros::setProx(NoListaRegistros* p)
{
    this->prox=p;
}

/**
    Imprime informações contidas no nó.
**/
void NoListaRegistros::imprime()
{
    cout << this->getUserId() << "\t" << this->getMovieId() << "\t" <<
    this->getRating() << "\t" << this->getTimestamp() << endl;
}

