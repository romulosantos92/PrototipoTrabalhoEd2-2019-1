#include "Dupla.h"

/**
    Construtor padrão da classe.
    Não recebe parâmetros.
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
    Recebe como parâmetros:
        *(int)userId - Id do usuário.
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
        *(int) Id do usuário.
    Não recebe parâmetros.
**/
int Dupla::getUserId()
{
    return this->userId;
}

/**
    Seta o id do usuário.
    Não possui retorno.
    Recebe como parâmetro:
        *(int) v - Novo id de usuário.
**/
void Dupla::setUserId(int v)
{
    this->userId=v;
}

/**
    Retorna:
        *(int) Id do filme.
    Não recebe parâmetros.
**/
int Dupla::getMovieId()
{
    return this->movieId;
}

/**
    Seta o id do filme.
    Não possui retorno.
    Recebe como parâmetro:
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
