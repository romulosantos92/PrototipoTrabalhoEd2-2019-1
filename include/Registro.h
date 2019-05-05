#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
using namespace std;

/**
    @brief Registro Constituído pelos campos userId e movieId.
*/

class Registro
{
    public:

        /**
            @brief Construtor padrâo da classe.
        */
        Registro();

        /**
            Seta os dados do registro de acordo com os parâmetros.

            @brief Construtor da classe.

            @param userId - Novo id de usuário.
            @param movieId - Novo id do filme.
            @param rating - Novo rating do filme.
            @param timestamp - Novo timestamp.
        */
        Registro(int userId, int movieId, float rating, int timestamp);

        /**
            @brief Destrutor da classe.
        */
        virtual ~Registro();

        /**
            @brief Retorna id de usuário.

            @return Id do usuário.
        */
        int getUserId();

        /**
            @brief Seta o id de usuário.

            @param v - Novo id de usuário.
        */
        void setUserId(int v);

        /**
            @brief Retorna o id do filme.

            @return Id do filme.
        */
        int getMovieId();

        /**
            @brief Seta o id do filme.

            @param v - Novo id do filme.
        */
        void setMovieId(int v);

        /**
            @brief Retorna o rating do filme.

            @return Rating do filme.
        */
        float getRating();

        /**
            @brief Seta o rating do filme.

            @param v - Novo rating.
        */
        void setRating(float v);

        /**
            @brief Retorna o timestamp.

            @return Timestamp.
        */
        int getTimestamp();

        /**
            @brief Seta o timestamp.

            @param v - Novo timestamp.
        */
        void setTimestamp(int v);

        /**
            @brief Imprime os dados do registro.
        */
        void imprime();


    protected:

    private:
        ///Valor int representando o id do usuário.
        int userId;
        ///Valor int representando o id do filme.
        int movieId;
        ///Valor float representando o rating do filme.
        float rating;
        ///Valor int representando o timestamp.
        int timestamp;
};

#endif // REGISTRO_H
