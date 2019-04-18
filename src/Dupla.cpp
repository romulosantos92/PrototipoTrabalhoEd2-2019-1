#include "Dupla.h"

/**
    Construtor padr�o da classe.
    N�o recebe par�metros.
    seta todos os atributos para 0.
**/
Dupla::Dupla()
{
    //ctor
    this->setUserId(0);
    this->setMovieId(0);
}

/**
    Construtor da classe.
    Recebe como par�metros:
        *(int)userId - Id do usu�rio.
        *(int)movieId - Id do filme.
**/
Dupla::Dupla(int userId, int movieId)
{
    this->setUserId(userId);
    this->setMovieId(movieId);
}

/**
    Destrutor da classe.
**/
Dupla::~Dupla()
{
    //dtor
}

/**
    Retorna:
        *(int) Id do usu�rio.
    N�o recebe par�metros.
**/
int Dupla::getUserId()
{
    return this->userId;
}

/**
    Seta o id do usu�rio.
    N�o possui retorno.
    Recebe como par�metro:
        *(int) v - Novo id de usu�rio.
**/
void Dupla::setUserId(int v)
{
    this->userId=v;
}

/**
    Retorna:
        *(int) Id do filme.
    N�o recebe par�metros.
**/
int Dupla::getMovieId()
{
    return this->movieId;
}

/**
    Seta o id do filme.
    N�o possui retorno.
    Recebe como par�metro:
        *(int) v - Novo id do filme.
**/
void Dupla::setMovieId(int v)
{
    this->movieId=v;
}

/**
    Imprime os valores de uma dupla em uma linha na seguinte ordem:
        *UserId
        *MovieId
**/
void Dupla::imprime()
{
    cout << this->getUserId() << "\t" << this->getMovieId();
}
