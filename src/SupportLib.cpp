#include "SupportLib.h"

SupportLib::SupportLib()
{
    //ctor
}

SupportLib::~SupportLib()
{
    //dtor
}

/**
    Ordena uma lista por meio do algoritmo BubbleSort.
    Recebe como parâmetro um ponteiro para uma lista.
**/
void SupportLib::bubbleSort(ListaRegistros *lista)
{
    cout << "\nBubbleSort\n=======================================" << endl <<
    "1-UserId\n2-MovieId\n3-Rating\n4-Timestamp" << endl <<
    "=======================================\nEscolha uma opcao:\n";
    int ans;
    cin >> ans;
    bool ordenada;
    NoListaRegistros* p;
    p=lista->getPrimeiro();
    cout << endl << "=======================================";
    if(ans==1)
        cout << "\nOrdenando por UserId.";
    else if(ans==2)
        cout << "\nOrdenando por MovieId.";
    else if(ans==3)
        cout << "\nOrdenando por Ratings.";
    else if(ans==4)
        cout << "\nOrdenando por TimeStamp.";
    cout << endl << "Ordenando valores, aguarde...\n====================================";
    unsigned long int counter=0;
    clock_t c1=clock();
    while(true)
    {
        ordenada=true;
        while(p->getProx()!=NULL)
        {
            if((ans==1)&&(p->getUserId()>p->getProx()->getUserId()))
            {
                ordenada=false;
                lista->troca(p, p->getProx());
                counter++;
            }
            else if((ans==2)&&(p->getMovieId()>p->getProx()->getMovieId()))
            {
                ordenada=false;
                lista->troca(p, p->getProx());
                counter++;
            }
            else if((ans==3)&&(p->getRating()>p->getProx()->getRating()))
            {
                ordenada=false;
                lista->troca(p, p->getProx());
                counter++;
            }
            else if((ans==4)&&(p->getTimestamp()>p->getProx()->getTimestamp()))
            {
                ordenada=false;
                lista->troca(p, p->getProx());
                counter++;
            }
            p=p->getProx();
        }
        if(ordenada)
            break;
        else
            p=lista->getPrimeiro();
    }
    clock_t c2=clock();
    double tempoExecucao=(c2-c1)*1000/(CLOCKS_PER_SEC);
    cout << endl << "Foram realizadas " << counter << " operacoes de troca nos " << lista->getTam() << " registros." << endl <<
    "Tempo de execucao: " << tempoExecucao/1000 << " segundos.";
}

/**
    Ordena uma lista por meio do algoritmo SelectSort.
    Recebe como parâmetro um ponteiro para uma lista.
**/
void SupportLib::selectSort(ListaRegistros *lista)
{
    cout << "\nSelectSort\n=======================================" << endl <<
    "1-UserId\n2-MovieId\n3-Rating\n4-Timestamp" << endl <<
    "=======================================\nEscolha uma opcao:\n";
    int ans, horas=0, minutos=0;
    double tempoExecucao=0, segundos=0, seg=0;
    cin >> ans;
    NoListaRegistros* p;
    p=lista->getPrimeiro();
    cout << endl << "=======================================";
    if(ans==1)
        cout << "\nOrdenando por UserId.";
    else if(ans==2)
        cout << "\nOrdenando por MovieId.";
    else if(ans==3)
        cout << "\nOrdenando por Ratings.";
    else if(ans==4)
        cout << "\nOrdenando por TimeStamp.";
    cout << endl << "Ordenando valores, aguarde...\n=======================================";
    unsigned long int counter=0;
    NoListaRegistros *limiteInf=lista->getPrimeiro();
    NoListaRegistros *menor;
    clock_t c1=clock();
    while(limiteInf->getProx()!=NULL)
    {
        menor=limiteInf;
        p=limiteInf;
        while(p->getProx()!=NULL)
        {
            if((ans==1)&&(p->getUserId()<menor->getUserId()))
            {
                menor=p;
            }
            else if((ans==2)&&(p->getMovieId()<menor->getMovieId()))
            {
                menor=p;
            }
            else if((ans==3)&&(p->getRating()<menor->getRating()))
            {
                menor=p;
            }
            else if((ans==4)&&(p->getTimestamp()<menor->getTimestamp()))
            {
                menor=p;
            }
            p=p->getProx();
        }
        lista->troca(limiteInf, menor);

        tempoExecucao=((clock()-c1)*1000)/CLOCKS_PER_SEC;

        seg=tempoExecucao/1000; //(tempoExecucao-(horas*3600000)-(minutos*60000))/1000;

        horas=((int)seg/3600);
        minutos=(int)(seg-(horas*3600))/60;
        segundos=seg-(horas*3600)-(minutos*60);//((int)seg%3600)%60;

        //cout << endl << horas << ":" << minutos << ":" << segundos << "\t" << seg;

        if((counter%(int)(lista->getTam()/10)==0)&&(tempoExecucao<1000))
            cout << endl << (counter/(int)(lista->getTam()/10))*10 << "% dos valores ordenados em " <<
            segundos*1000<< " milisegundos.";
        else if((counter%(int)(lista->getTam()/10)==0)&&(tempoExecucao<60000))
            cout << endl << (counter/(int)(lista->getTam()/10))*10 << "% dos valores ordenados em " <<
            segundos << " segundo(s).";
        else if((counter%(int)(lista->getTam()/10)==0)&&(tempoExecucao<3600000))
            cout << endl << (counter/(int)(lista->getTam()/10))*10 << "% dos valores ordenados em " <<
            minutos << " minuto(s) " << segundos << " segundo(s).";
        else if((counter%(int)(lista->getTam()/10)==0)&&(tempoExecucao>=3600000))
            cout << endl << (counter/(int)(lista->getTam()/10))*10 << "% dos valores ordenados em " <<
            horas << " hora(s) " << minutos << " minuto(s) " << segundos << " segundo(s).";
        counter++;
        limiteInf=limiteInf->getProx();
    }
    cout << endl << "100% dos valores ordenados.";
    cout << endl << "=======================================";
    clock_t c2=clock();
    tempoExecucao=(c2-c1)*1000/(CLOCKS_PER_SEC);
    cout << endl << "Foram realizadas " << counter << " operacoes de troca nos " << lista->getTam() << " registros." << endl <<
    "Tempo de execucao: " << horas << "h " << minutos << "m " << segundos
    << "s.\n=======================================";
}

/**
    Ordena uma lista por meio do algoritmo InsertionSort.
    Recebe como parâmetro um ponteiro para uma lista.
**/
void insertionSort(ListaRegistros * lista)
{

}

/**
    Ordena uma lista por meio do algoritmo MergeSort.
    Recebe como parâmetro um ponteiro para uma lista.
**/
void mergeSort(ListaRegistros *lista, int tam)
{

}
