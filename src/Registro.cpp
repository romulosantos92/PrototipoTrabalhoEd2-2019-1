#include "Registro.h"

Registro::Registro()
{
    //ctor
    this->setUserId(0);
    this->setMovieId(0);
    this->setRating(0);
    this->setTimestamp(0);
}

Registro::Registro(int userId, int movieId, float rating, int timestamp)
{
    this->setUserId(userId);
    this->setMovieId(movieId);
    this->setRating(rating);
    this->setTimestamp(timestamp);
}

Registro::~Registro()
{
    //dtor
}

int Registro::getUserId()
{
    return this->userId;
}

void Registro::setUserId(int v)
{
    this->userId=v;
}

int Registro::getMovieId()
{
    return this->movieId;
}

void Registro::setMovieId(int v)
{
    this->movieId=v;
}

float Registro::getRating()
{
    return this->rating;
}

void Registro::setRating(float v)
{
    this->rating=v;
}

int Registro::getTimestamp()
{
    return this->timestamp;
}

void Registro::setTimestamp(int v)
{
    this->timestamp=v;
}

void Registro::imprime()
{
    cout << this->getUserId() << "\t" << this->getMovieId() << "\t" << this->getRating() << "\t" << this->getTimestamp();
}
