#include "borrow.h"
#include <stdio.h>
#include <stdlib.h>

int count_borrow_list=0; /*!< zmienna licz�ca ilo�� element�w listy wypo�ycze� */


/*!
 *   @brief funkcja uzupe�nia dane w konkretnym elemencie listy wypo�ycze� utworzonym przez funkcj� add_new_borrow
 *
 *   @param Borrow *(*new_borrow_node) podw�jny wska�nik na nowy element listy wypo�ycze�
 *   @param int client_id numer id klienta
 *   @param int book_id numer id ksi��ki
 *   @param int amount_to_borrow ilo�� ksi��ek jak� klient chce wypo�yczy�
 */
void new_borrow_fill(Borrow *(*new_borrow_node), int client_id, int book_id, int amount_to_borrow) {

    int d_of_borrow;
    int m_of_borrow;
    int y_of_borrow;

    int d_of_give_back;
    int m_of_give_back;
    int y_of_give_back;


    (*new_borrow_node)->borrow_client_id=client_id;
    (*new_borrow_node)->book_id=book_id;
    (*new_borrow_node)->amount_to_borrow=amount_to_borrow;

    printf("\n Wpisz dzie� wypo�yczenia: ");
    scanf(" %d",&d_of_borrow);
    while(d_of_borrow<0||d_of_borrow>31){
        printf("\n Dzie� miesi�ca nie mo�e przyj�� takiej warto�ci, spr�buj ponownie: ");
        scanf(" %d",&d_of_borrow);
    }
    (*new_borrow_node)->d_of_borrow = d_of_borrow;



    printf("\n Wpisz miesi�c wypo�yczenia: ");
    scanf(" %d",&m_of_borrow);
    while(m_of_borrow<0||m_of_borrow>12){
        printf("\n Miesi�c nie mo�e przyj�� takiej warto�ci, spr�buj ponownie: ");
        scanf(" %d",&m_of_borrow);
    }
    (*new_borrow_node)->m_of_borrow = m_of_borrow;



    printf("\n Wpisz rok wypo�yczenia: ");
    scanf(" %d",&y_of_borrow);
    while(y_of_borrow<1950||y_of_borrow>2016){
        printf("\n Rok wypo�yczenia nie mo�e przyj�� takiej warto�ci, spr�buj ponownie: ");
        scanf(" %d",&y_of_borrow);
    }
    (*new_borrow_node)->y_of_borrow = y_of_borrow;


    printf("\n Wpisz dzie� oddania: ");
    scanf(" %d",&d_of_give_back);
    while(d_of_give_back<0||d_of_give_back>31){
        printf("\n Dzie� miesi�ca nie mo�e przyj�� takiej warto�ci, spr�buj ponownie: ");
        scanf(" %d",&d_of_give_back);
    }
    (*new_borrow_node)->d_of_give_back = d_of_give_back;



    printf("\n Wpisz miesi�c oddania: ");
    scanf(" %d",&m_of_give_back);
    while(m_of_give_back<7||m_of_give_back>12){
        printf("\n Miesi�c nie mo�e przyj�� takiej warto�ci, spr�buj ponownie: ");
        scanf(" %d",&m_of_give_back);
    }
    (*new_borrow_node)->m_of_give_back = m_of_give_back;



    printf("\n Wpisz rok oddania: ");
    scanf(" %d",&y_of_give_back);
    while(y_of_give_back<2016){
        printf("\n Rok wypo�yczenia nie mo�e przyj�� takiej warto�ci, spr�buj ponownie: ");
        scanf(" %d",&y_of_give_back);
    }
    (*new_borrow_node)->y_of_give_back = y_of_give_back;
}


/*!
 *   @brief funkcja tworzy element listy wypo�ycze� a nast�pnie wywo�uje funkcj� new_borrow_fill kt�ra uzupe�nia pola danych elementu
 *
 *   @param Borrow **borrow_base_pointer podw�jny wska�nik na list� ksi��ek
 *   @param int borrow_id id wypo�yczenia
 *   @param int client_id id klienta
 *   @param int book_id id ksi��ki
 *   @param int amount_to_borrow ilo�� ksi��ek jak� klient chce wypo�yczy�
 */
void add_new_borrow(Borrow **borrow_base_pointer, int borrow_id, int client_id, int book_id, int amount_to_borrow) {

    Borrow *new_borrow = (Borrow*)malloc(sizeof(Borrow));

    if(new_borrow!=NULL)
    {
        count_borrow_list++;

        new_borrow->next = *borrow_base_pointer;
        *borrow_base_pointer = new_borrow;
        new_borrow->borrow_id = borrow_id;
        new_borrow_fill(&new_borrow, client_id, book_id, amount_to_borrow);
    }
}

/*!
 *   @brief funkcja usuwa ca�� baz� wypo�ycze�, aby zachowa� histori� ci�gle w programie nie jest ona kasowalna przez uzytkownika mo�na j� skasowa� tylko wy��czaj�c program
 *
 *   @param Borrow **borrow_base_base_pointer
 */
void delete_borrow_base(Borrow **borrow_base_base_pointer) {
    while(*borrow_base_base_pointer!=NULL) {
        Borrow *next = (*borrow_base_base_pointer)->next;
        free(*borrow_base_base_pointer);
        *borrow_base_base_pointer=next;
    }
}



/*!
 *   @brief funkcja pozwala klientowi odda� ksia�k�, musi on poda� sw�j id i id wypo�yczonej ksi��ki. Oddanie jest sygnalizowane przez dopisanie s�owa oddane w danej char give_back[6]
 *
 *   @param Library *base_pointer wska�nik na list� wypo�ycze�
 */
void give_back_book(Borrow *borrow_base_pointer){
    int borrow_client_id;
    int book_id;

    char gave_back[6]="oddane";

    Borrow *borrow_temporary_pointer = borrow_base_pointer;

    printf("\n Wpisz numer id ksi��ki do oddania: ");
    scanf(" %d",&book_id);
    printf("\n Wpisz numer id klienta posiadaj�cego t� ksi��k�: ");
    scanf(" %d",&borrow_client_id);

    while(borrow_temporary_pointer->borrow_client_id!=borrow_client_id&&borrow_base_pointer->book_id!=book_id&&borrow_temporary_pointer!=NULL){

        borrow_temporary_pointer=borrow_temporary_pointer->next;
    }
    if(borrow_temporary_pointer!=NULL){
        strcmp(borrow_temporary_pointer->gave_back, gave_back);
    }
}


/*!
 *   @brief funkcja wypisuje na ekran ca�� list� wypo�ycze�
 *
 *   @param Borrow *borrow_base_pointer wska�nik na list� wypo�ycze�
 */
void cout_borrow_base(Borrow *borrow_base_pointer) {

    if (borrow_base_pointer!=NULL)
    {
        cout_base(borrow_base_pointer->next);
        printf(" ID klienta: %d ",borrow_base_pointer->borrow_client_id);
        printf("ID ksi��ki: %d ",borrow_base_pointer->book_id);
        printf("data po�yczenia: %d ",borrow_base_pointer->d_of_borrow);
        printf("/%d",borrow_base_pointer->m_of_borrow);
        printf("/%d ",borrow_base_pointer->y_of_borrow);
        printf("po�yczona do: %d ",borrow_base_pointer->d_of_give_back);
        printf("/%d",borrow_base_pointer->m_of_give_back);
        printf("/%d ",borrow_base_pointer->y_of_give_back);
        printf("%s",borrow_base_pointer->gave_back);
    }
}


/*!
 *   @brief funkcja zapisuje ca�� list� wypo�ycze� do pliku borrow.txt
 *
 *   @param Borrow *borrow_base_pointer wska�nik na list� wypo�ycze�
 */
void write_borrow_to_file(Borrow *borrow_base_pointer)
{
    FILE *file3;
    file3=fopen("borrow.txt", "w");
    file3=fopen("borrow.txt", "a");
    char buffer[6]="oddane";
        if(file3==NULL)
                printf(" Wyst�pi� b��d z plikiem books.txt\n");
        else
        {
            if(borrow_base_pointer!=NULL)
            {
                write_borrow_to_file(borrow_base_pointer->next);
                fprintf(file3,"ID klienta: %d",borrow_base_pointer->borrow_client_id);
                fprintf(file3," ID ksi��ki: %d",borrow_base_pointer->book_id);
                fprintf(file3," data po�yczenia: %d",borrow_base_pointer->d_of_borrow);
                fprintf(file3,"/%d",borrow_base_pointer->m_of_borrow);
                fprintf(file3,"/%d",borrow_base_pointer->y_of_borrow);
                fprintf(file3,"po�yczona do: %d",borrow_base_pointer->d_of_give_back);
                fprintf(file3,"/%d",borrow_base_pointer->m_of_give_back);
                fprintf(file3,"/%d ",borrow_base_pointer->y_of_give_back);
                if(borrow_base_pointer->gave_back!=buffer)
                    fprintf(file3," %s\n",borrow_base_pointer->gave_back);
                else
                    fprintf(file3,"\n");
            }
        }
    fclose(file3);
}




