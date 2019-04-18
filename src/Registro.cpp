#include "Registro.h"
/**
    Construtor padr�o da classe.
    N�o recebe par�metros.
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
    Recebe como par�metros:
        *(int)userId - Id do usu�rio.
        *(int)movieId - Id do filme.
        *(float)rating - Avalia��o do filme.
        *(int)timestamp - Quando a avalia��o foi feita.
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
        *(int) Id do usu�rio.
    N�o recebe par�metros.
**/
int Registro::getUserId()
{
    return this->userId;
}

/**
    Seta o id do usu�rio.
    N�o possui retorno.
    Recebe como par�metro:
        *(int) v - Novo id de usu�rio.
**/
void Registro::setUserId(int v)
{
    this->userId=v;
}

/**
    Retorna:
        *(int) Id do filme.
    N�o recebe par�metros.
**/
int Registro::getMovieId()
{
    return this->movieId;
}

/**
    Seta o id do filme.
    N�o possui retorno.
    Recebe como par�metro:
        *(int) v - Novo id do filme.
**/
void Registro::setMovieId(int v)
{
    this->movieId=v;
}

/**
    Retorna:
        *(float) Avalia��o do filme.
    N�o recebe par�metros.
**/
float Registro::getRating()
{
    return this->rating;
}

/**
    Seta a avalia��o do filme.
    N�o possui retorno.
    Recebe como par�metro:
        *(int) v - Nova avalia��o do filme.
**/
void Registro::setRating(float v)
{
    this->rating=v;
}

/**
    Retorna:
        *(int) Quando a avalia��o foi feita.
    N�o recebe par�metros.
**/
int Registro::getTimestamp()
{
    return this->timestamp;
}

/**
    Seta o timestamp.
    N�o possui retorno.
    Recebe como par�metro:
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
