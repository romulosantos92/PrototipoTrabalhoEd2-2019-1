#include "Registro.h"
/**
    Construtor padrão da classe.
    Não recebe parâmetros.
    seta todos os atributos para 0.
**/
Registro::Registro()
{
    //ctor
    this->setUserId(0);
    this->setMovieId(0);
    this->setRating(0);
    this->setTimestamp(0);
}

/**
    Construtor da classe.
    Recebe como parâmetros:
        *(int)userId - Id do usuário.
        *(int)movieId - Id do filme.
        *(float)rating - Avaliação do filme.
        *(int)timestamp - Quando a avaliação foi feita.
**/
Registro::Registro(int userId, int movieId, float rating, int timestamp)
{
    this->setUserId(userId);
    this->setMovieId(movieId);
    this->setRating(rating);
    this->setTimestamp(timestamp);
}

/**
    Destrutor da classe.
**/
Registro::~Registro()
{
    //dtor
}

/**
    Retorna:
        *(int) Id do usuário.
    Não recebe parâmetros.
**/
int Registro::getUserId()
{
    return this->userId;
}

/**
    Seta o id do usuário.
    Não possui retorno.
    Recebe como parâmetro:
        *(int) v - Novo id de usuário.
**/
void Registro::setUserId(int v)
{
    this->userId=v;
}

/**
    Retorna:
        *(int) Id do filme.
    Não recebe parâmetros.
**/
int Registro::getMovieId()
{
    return this->movieId;
}

/**
    Seta o id do filme.
    Não possui retorno.
    Recebe como parâmetro:
        *(int) v - Novo id do filme.
**/
void Registro::setMovieId(int v)
{
    this->movieId=v;
}

/**
    Retorna:
        *(float) Avaliação do filme.
    Não recebe parâmetros.
**/
float Registro::getRating()
{
    return this->rating;
}

/**
    Seta a avaliação do filme.
    Não possui retorno.
    Recebe como parâmetro:
        *(int) v - Nova avaliação do filme.
**/
void Registro::setRating(float v)
{
    this->rating=v;
}

/**
    Retorna:
        *(int) Quando a avaliação foi feita.
    Não recebe parâmetros.
**/
int Registro::getTimestamp()
{
    return this->timestamp;
}

/**
    Seta o timestamp.
    Não possui retorno.
    Recebe como parâmetro:
        *(int) v - Novo timestamp.
**/
void Registro::setTimestamp(int v)
{
    this->timestamp=v;
}

/**
    Imprime os valores de um registro em uma linha na seguinte ordem:
        *UserId
        *MovieId
        *Rating
        *Timestamp
**/
void Registro::imprime()
{
    cout << this->getUserId() << "\t" << this->getMovieId() << "\t" << this->getRating() << "\t" << this->getTimestamp();
}
