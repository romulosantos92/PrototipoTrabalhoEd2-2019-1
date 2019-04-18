#ifndef DUPLA_H
#define DUPLA_H

#include <iostream>
using namespace std;

class Dupla
{
    public:
        Dupla();
        Dupla(int userId, int mpovieId);
        virtual ~Dupla();

        int getUserId();
        void setUserId(int v);
        int getMovieId();
        void setMovieId(int v);

        void imprime();

    protected:

    private:
        int userId;
        int movieId;
};

#endif // DUPLA_H
