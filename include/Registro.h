#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
using namespace std;


class Registro
{
    public:
        Registro();
        Registro(int userId, int movieId, float rating, int timestamp);
        virtual ~Registro();

        int getUserId();
        void setUserId(int v);
        int getMovieId();
        void setMovieId(int v);
        float getRating();
        void setRating(float v);
        int getTimestamp();
        void setTimestamp(int v);

        void imprime();


    protected:

    private:
        int userId;
        int movieId;
        float rating;
        int timestamp;
};

#endif // REGISTRO_H
