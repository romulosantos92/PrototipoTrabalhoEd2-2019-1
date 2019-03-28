#ifndef NOLISTAREGISTROS_H
#define NOLISTAREGISTROS_H

#include <iostream>

using namespace std;


class NoListaRegistros
{
    public:
        NoListaRegistros();
        NoListaRegistros(int userId, int movieId, double rating, int timestamp);
        virtual ~NoListaRegistros();
        int getUserId();
        void setUserId(int v);
        int getMovieId();
        void setMovieId(int v);
        int getTimestamp();
        void setTimeStamp(int v);
        double getRating();
        void setRating(double v);
        NoListaRegistros* getProx();
        void setProx(NoListaRegistros* p);
        void imprime();

    protected:

    private:
        int userId, movieId, timestamp;
        double rating;
        NoListaRegistros *prox;
};

#endif // NOLISTAREGISTROS_H
