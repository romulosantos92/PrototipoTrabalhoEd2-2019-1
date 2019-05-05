#include "Dupla.h"

Dupla::Dupla()
{
    //ctor
    this->setUserId(0);
    this->setMovieId(0);
    this->setCoalescido(-2);
    this->setProx(NULL);
}

Dupla::Dupla(int userId, int movieId)
{
    this->setUserId(userId);
    this->setMovieId(movieId);
    this->setCoalescido(-2);
    this->setProx(NULL);
}

Dupla::~Dupla()
{
    //dtor
}

int Dupla::getUserId()
{
    return this->userId;
}

void Dupla::setUserId(int v)
{
    this->userId=v;
}

int Dupla::getMovieId()
{
    return this->movieId;
}

void Dupla::setMovieId(int v)
{
    this->movieId=v;
}

void Dupla::imprime()
{
    cout << this->getUserId() << "\t" << this->getMovieId();
}

int Dupla::getCoalescido()
{
    return this->coalescido;
}

void Dupla::setCoalescido(int v)
{
    this->coalescido=v;
}

Dupla* Dupla::getProx()
{
    return this->prox;
}

void Dupla::setProx(Dupla *p)
{
    this->prox=p;
}
