#ifndef DUPLA_H
#define DUPLA_H

#include <iostream>
using namespace std;

/**
    Duplas s�o egistros Constitu�dos pelos campos userId e movieId.
    @brief Classe representando uma dupla.
*/

class Dupla
{
    public:
        /**
            Seta todos os atributos para 0.

            @brief Construtor Padr�o da classe
        */
        Dupla();

        /**
            Seta os atributos de acordo com os par�metros.

            @brief Construtor da classe.

            @param userId - Novo id de usu�rio.
            @param movieId - Novo id do filme.
        */
        Dupla(int userId, int movieId);

        /**
            @brief Destrutor da classe.
        */
        virtual ~Dupla();

        /**
            @brief Retorna o id do usu�rio.
        */
        int getUserId();

        /**
            @brief Seta o id do usu�rio.

            @param v - Novo id de usu�rio.
        */
        void setUserId(int v);

        /**
            @brief Retorna o id do filme.
        */
        int getMovieId();

        /**
            @brief Seta o id do filme.

            @param v - Novo id do filme.

            @return Id do filme.
        */
        void setMovieId(int v);

        /**
            @brief Imprime os dados da dupla.
        */
        void imprime();

        /**
            @brief Retorna o �ndice do pr�ximo item do encadeamento coalescido.

            @return �ndice do pr�ximo item.
        */
        int getCoalescido();

        /**
            @brief Seta o �ndice do pr�ximo item do encadeamento coalescido.

            @param v - Novo item.
        */
        void setCoalescido(int v);

        /**
            @brief Retorna um ponteiro para o pr�ximo item do encadeamento separado.

            @return Ponteiro para o pr�ximo item.
        */
        Dupla *getProx();

        /**
            @brief Seta o ponteiro para o pr�ximo item do encadeamento separado.

            @param p - Ponteiro para o item a ser adicionado.
        */
        void setProx(Dupla *p);


    protected:

    private:
        ///Representa o id do usu�rio.
        int userId;

        ///Representa o id do filme.
        int movieId;

        ///Representa o indice do pr�ximo item no encadeamento coalescido. \\n -2 para posi��es livres e -1 para fim de cadeia.
        int coalescido;

        ///Ponteiro para o pr�ximo item do encadeamento separado.
        Dupla *prox;


};

#endif // DUPLA_H
