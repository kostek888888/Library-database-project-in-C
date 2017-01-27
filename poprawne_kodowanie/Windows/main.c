#include <stdio.h>
#include <stdlib.h>

#include "clients.h"
#include "books.h"
#include "borrow.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

    Library *base_pointer=NULL; /*!< wska�nik na baz� z ksi��kami */
    Client *client_base_pointer=NULL; /*!< wska�nik na baz� z klientami */
    Borrow *borrow_base_pointer=NULL; /*!< wska�nik na baz� wypo�ycze� */


    int id=0; /*!< zmienna definiuj�ca id ksi��ki w li�cie */
    int client_id=0; /*!< zmienna definiuj�ca id klienta w li�cie */
    int borrow_id=0; /*!< zmienna definiuj�ca id wypo�yczenia w li�cie */

/*!
 *   @brief funkcja s�u�y do zarejestrowania wypo�yczenia ksi��ki, sprawdza czy klient istnieje w bazie klient�w oraz czy ksia�ka jest dost�pna do wypo�yczenia w bazie ksi��ek je�li tak wypo�ycza i rejestruje to na li�cie wypo�ycze�
 *
 *   @param Library *base_pointer wska�nik na baz� z ksi��kami
 *   @param Client *client_base_pointer wska�nik na baz� z klientami
 */
void get_book(Library *base_pointer, Client *client_base_pointer){
    int client_id_to_search=0;
    long long int pesel;
    char title[100];
    char author[100];
    int amount_to_borrow=0;

    Library *temporary_pointer = base_pointer;
    Client *client_temporary_pointer = client_base_pointer;

    printf("\n Wpisz id klienta wypo�yczaj�cego ksi��k�: ");
    scanf(" %d",&client_id_to_search);
    while(client_id_to_search<1){
        printf("\n Wprowadzono b��dny numer id klienta, spr�buj ponownie: ");
        scanf(" %d",&client_id_to_search);
    }

    if(client_temporary_pointer!=NULL&&temporary_pointer!=NULL){
        while((client_temporary_pointer->client_id!=client_id_to_search)&&(client_temporary_pointer!=NULL)){
            client_temporary_pointer=client_temporary_pointer->next;
        }
        if(client_temporary_pointer!=NULL){

            if(client_base_pointer->id_book3==0){
            printf("\n Wpisz nazw� ksi��ki do wypo�yczenia: ");
            gets(title);
            printf("\n Wpisz autora ksi��ki do wypo�yczenia: ");
            gets(author);

            while((strcmp(temporary_pointer->title,title)!=0)&&(strcmp(temporary_pointer->author, author)!=0)&&(temporary_pointer!=NULL))
                {
                    temporary_pointer=temporary_pointer->next;
                }
            if(temporary_pointer!=NULL)
                {
                    borrow_id++;

                    if(temporary_pointer->copies>0)
                    printf("\n Na stanie jest %4d ksi��ek, ile sztuk chcesz wypo�yczy�?\n",temporary_pointer->copies);
                    scanf(" %d",&amount_to_borrow);
                    while((amount_to_borrow<1)||(temporary_pointer->copies-amount_to_borrow<0)){
                        printf("\n Spr�bowano wypo�yczy� nieprawid�ow� ilo�� ksi��ek, spr�buj ponownie: ");
                        scanf(" %d",&amount_to_borrow);
                    }

                    add_new_borrow(&borrow_base_pointer, borrow_id, client_temporary_pointer->client_id, temporary_pointer->id,  amount_to_borrow);

                    temporary_pointer->copies-=amount_to_borrow;
                    temporary_pointer->borrowed+=amount_to_borrow;

                    if(client_base_pointer->id_book1==0)
                    client_temporary_pointer->id_book1=temporary_pointer->id;
                    else if(client_base_pointer->id_book2==0)
                        client_temporary_pointer->id_book2=temporary_pointer->id;
                    else if(client_base_pointer->id_book3==0)
                        client_temporary_pointer->id_book3=temporary_pointer->id;
                }
                else
                    printf(" Napotkano b��d, nie mo�na wypo�yczy� ksi��ki\n");
            }
        }
    }
    else
        printf(" Napotkano b��d, nie mo�na wypo�yczy� ksi��ki\n");
}




/*!
 *   @brief g��wna funkcja programu w kt�rej u�ytkownik wybiera operacje do wykonania, po wyj�ciu z p�tli switch funkcja zapisuje wszystkie listy do plik�w i kasuje je z pami�ci podr�cznej
 *
 *   @return 0
 */
int main(void)
{
    int menu_choice=0;

    while(menu_choice!=99) {
        printf("\n Biblioteka: Wybierz jedn� z podanych ni�ej opcji\n");
        printf(" 1.  Dodaj ksi��k�\n");
        printf(" 2.  Usu� ksi��k�\n");
        printf(" 3.  Edytuj ksisi��ki\n");
        printf(" 4.  Wy�wietl ksi��ki\n");
        printf(" 5.  Posortuj ksi��ki\n");
        printf(" 6.  Wyszukaj ksi��ki\n");
        printf(" 7.  Zapisz ksi��ki do pliku\n");
        printf(" 8.  Odczytaj ksi��ki z pliku\n\n");

        printf(" 9.  Dodaj klienta\n");
        printf(" 10. Usu� klienta\n");
        printf(" 11. Edytuj klienta\n");
        printf(" 12. Wy�wietl klient�w\n");
        printf(" 13. Posortuj klient�w\n");
        printf(" 14. Wyszukaj klienta po jego ID\n");
        printf(" 15. Zapisz klient�w do pliku\n");
        printf(" 16. Odczytaj klient�w z pliku\n\n");

        printf(" 17. Wykonaj operacj� wypo�ycz ksi��k�\n");
        printf(" 18. Wykonaj operacj� oddaj ksi��k�\n");
        printf(" 19. Poka� wszystkie wykonane operacje\n");
        printf(" 20. Usu� baz� wypo�ycze�\n");

        printf("\n 99. Zako�czenie programu i zwolnienie pami�ci podr�cznej\n\n");
        printf( "       Tw�j wyb�r: ");
        scanf("%i", &menu_choice);
        system(CLEAR);

        switch(menu_choice) {
            case 1:
                    id++;
                    add_new_book(&base_pointer, id);
                    system(CLEAR);
                    printf("\n !!! Ksi��ka zosta�a pomy�lnie dodana do bazy !!!\n");
                    break;

            case 2:
                    delete_book(&base_pointer);
                    system(CLEAR);
                    printf(" Ksi��k� pomy�lnie usuni�to z bazy\n");
                    break;

            case 3:
                    system(CLEAR);
                    edit_book(base_pointer);
                    break;

            case 4:
                    cout_base(base_pointer);
                    break;

            case 5:
                    system(CLEAR);
                    sort_book_list(base_pointer);
                    break;

            case 6:
                    search_for_book(base_pointer);
                    break;

            case 7:
                    write_to_file(base_pointer);
                    system(CLEAR);
                    printf(" Pomy�lnie zapisano ksi��ki do pliku\n");
                    break;

            case 8:
                    read_file1();
                    break;
            case 9:
                    id++;
                    add_new_client(&client_base_pointer, client_id);
                    system(CLEAR);
                    printf("\n !!! Pomy�lnie dodano klienta do bazy !!!\n");
                    break;

            case 10:
                    delete_client(&client_base_pointer);
                    system(CLEAR);
                    printf(" Pomy�lnie usuni�to klienta z bazy\n");
                    break;
            case 11:
                    system(CLEAR);
                    edit_client(client_base_pointer);
                    break;

            case 12:
                    cout_client_base(client_base_pointer);
                    break;

            case 13:
                    system(CLEAR);
                    sort_client_list(client_base_pointer);
                    break;

            case 14:
                    seek_for_client(client_base_pointer);
                    break;

            case 15:
                    clients_write_to_file(client_base_pointer);
                    system(CLEAR);
                    printf(" Pomy�lnie zapisano klient�w do pliku\n");
                    break;

            case 16:
                    read_file2();
                    break;
            case 17:
                    get_book(base_pointer, client_base_pointer);
                    break;
            case 18:
                    give_back_book(&borrow_base_pointer);
                    system(CLEAR);
                    cout_borrow_base(borrow_base_pointer);
                    break;
            case 19:
                    cout_borrow_base(borrow_base_pointer);
                    break;
            case 20:
                    delete_borrow_base(&borrow_base_pointer);
                    break;
        }
    }

    system(CLEAR);
    printf(" Zapisuj� dane do plik�w, prosze nie wy��cza� aplikacji lub komputera...\n\n");
    write_to_file(base_pointer); ///store lists in file before exit
    clients_write_to_file(client_base_pointer);
    write_borrow_to_file(borrow_base_pointer);

    delete_base(&base_pointer); ///remove book base from ram
    delete_client_base(&client_base_pointer);
    delete_borrow_base(&borrow_base_pointer);

    system(CLEAR);
    printf(" Zapisano! Dzia�anie aplikacji zosta�o zako�czone, mo�na teraz zamkn�� to okno\n");

    return 0;
}
