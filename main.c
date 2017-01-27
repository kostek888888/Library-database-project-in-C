/// TITLE:
/// Library Project for Basics of Programming 2 Michael Kostecki 13A
/// Projekt biblioteki na Podstawy Programowania 2 Michaˆ Kostecki 13A

/// ¥ † © ä ¢ ˆ ¾ «

/// ¥ † © ä ¢ ˆ ¾ «



#include <stdio.h>          /// default libraries headers
#include <stdlib.h>

#include "clients.h"        /// .c with clients list
#include "books.h"          /// .c with books list
#include "borrow.h"         /// .c with borrow list

#ifdef _WIN32               /// clear console compatibility definition
#define CLEAR "cls"         /// windows
#else
#define CLEAR "clear"       /// linux
#endif

    Library *base_pointer=NULL; /*!< wskaźnik na bazę z książkami */
    Client *client_base_pointer=NULL; /*!< wskaźnik na bazę z klientami */
    Borrow *borrow_base_pointer=NULL; /*!< wskaźnik na bazę wypożyczeń */


    int id=0; /*!< zmienna definiująca id książki w liście */
    int client_id=0; /*!< zmienna definiująca id klienta w liście */
    int borrow_id=0; /*!< zmienna definiująca id wypożyczenia w liście */

/*!
 *   @brief funkcja służy do zarejestrowania wypożyczenia książki, sprawdza czy klient istnieje w bazie klientów oraz czy ksiażka jest dostępna do wypożyczenia w bazie książek jeśli tak wypożycza i rejestruje to na liście wypożyczeń
 *
 *   @param Library *base_pointer wskaźnik na bazę z książkami
 *   @param Client *client_base_pointer wskaźnik na bazę z klientami
 */
void get_book(Library *base_pointer, Client *client_base_pointer){
    char name[100];
    char surname[100];
    long long int pesel;
    char title[100];
    char author[100];
    int amount_to_borrow=0;

    Library *temporary_pointer = base_pointer;
    Client *client_temporary_pointer = client_base_pointer;

    printf("\n Wpisz imi© klienta wypo¾yczaj¥cego ksi¥¾k©: ");
    gets(name);
    gets(name);
    printf("\n Wpisz nazwisko klienta wypo¾yczaj¥cego ksi¥¾k©: ");
    gets(surname);
    printf("\n Wpisz numer PESEL klienta wypo¾yczaj¥cego ksi¥¾k©: ");
    scanf(" %I64d",&pesel);
    if(client_temporary_pointer!=NULL&&temporary_pointer!=NULL){
        while((strcmp(client_temporary_pointer->name,name)!=0)||(strcmp(client_temporary_pointer->surname,surname)!=0)||(client_temporary_pointer->pesel!=pesel)||(client_temporary_pointer!=NULL)){
            client_temporary_pointer=client_temporary_pointer->next;
        }
        if(client_temporary_pointer!=NULL){

            if(client_base_pointer->id_book3==0){
            printf("\n Wpisz nazw© ksi¥¾ki do wypo¾yczenia: ");
            gets(title);
            printf("\n Wpisz autora ksi¥¾ki do wypo¾yczenia: ");
            gets(author);

            while((strcmp(temporary_pointer->title,title)!=0)&&(strcmp(temporary_pointer->author, author)!=0)&&(temporary_pointer!=NULL))
                {
                    temporary_pointer=temporary_pointer->next;
                }
            if(temporary_pointer!=NULL)
                {
                    borrow_id++;

                    if(temporary_pointer->copies>0)
                    printf("\n Na stanie jest %4d. ksi¥¾ek, ile sztuk chcesz wypo¾yczy†?\n",temporary_pointer->copies);
                    scanf(" %d",&amount_to_borrow);
                    while((amount_to_borrow<1)||(temporary_pointer->copies-amount_to_borrow<0)){
                        printf("\n Spr¢bowano wypo¾yczy† nieprawidˆow¥ ilo˜† ksi¥¾ek, spr¢buj ponownie: ");
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
                    printf(" Napotkano bˆ¥d, nie mo¾na wypo¾yczy† ksi¥¾ki\n");
            }
        }
    }
    else
        printf(" Napotkano bˆ¥d, nie mo¾na wypo¾yczy† ksi¥¾ki\n");
}




/*!
 *   @brief główna funkcja programu w której użytkownik wybiera operacje do wykonania, po wyjściu z pętli switch funkcja zapisuje wszystkie listy do plików i kasuje je z pamięci podręcznej
 *
 *   @return 0
 */
int main(void)
{
    int menu_choice=0; /// for switching

    while(menu_choice!=99) {
        printf("\n Biblioteka: Wybierz jedn¥ z podanych ni¾ej opcji\n");
        printf(" 1.  Dodaj ksi¥¾k©\n");
        printf(" 2.  Usuä ksi¥¾k©\n");
        printf(" 3.  Edytuj ksisi¥¾ki\n");
        printf(" 4.  WyÓ˜wietl ksi¥¾ki\n");
        printf(" 5.  Posortuj ksi¥¾ki\n");
        printf(" 6.  Wyszukaj ksi¥¾ki po ID\n");
        printf(" 7.  Zapisz ksi¥¾ki do pliku\n");
        printf(" 8.  Odczytaj ksi¥¾ki z pliku\n\n");

        printf(" 9.  Dodaj klienta\n");
        printf(" 10. Usuä klienta\n");
        printf(" 11. Edytuj klienta\n");
        printf(" 12. Wy˜wietl klient¢w\n");
        printf(" 13. Posortuj klient¢w\n");
        printf(" 14. Wyszukaj klienta po jego ID\n");
        printf(" 15. Zapisz klient¢w do pliku\n");
        printf(" 16. Odczytaj klient¢w z pliku\n\n");

        printf(" 17. Wykonaj operacj© wypo¾ycz ksi¥¾k©\n");
        printf(" 18. Wykonaj operacj© oddaj ksi¥¾k©\n");
        printf(" 19. Poka¾ wszystkie wykonane operacje\n");
        printf(" 20. Usuä baz© wypo¾yczeä\n");

        printf("\n 99. Zakoäczenie programu i zwolnienie pami©ci podr©cznej\n\n");
        printf( "       Tw¢j wyb¢r: ");
        scanf("%i", &menu_choice);
        system(CLEAR);

        switch(menu_choice) {
            case 1:
                    id++;
                    add_new_book(&base_pointer, id);
                    system(CLEAR);
                    printf("\n !!! Ksi¥¾ka zostaˆa pomy˜lnie dodana do bazy !!!\n");
                    break;

            case 2:
                    delete_book(&base_pointer);
                    system(CLEAR);
                    printf(" Ksi¥¾k© pomy˜lnie usuni©to z bazy\n");
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
                    printf(" Pomy˜lnie zapisano ksi¥¾ki do pliku\n");
                    break;

            case 8:
                    read_file1();
                    break;
            case 9:
                    id++;
                    add_new_client(&client_base_pointer, client_id);
                    system(CLEAR);
                    printf("\n !!! Pomy˜lnie dodano klienta do bazy !!!\n");
                    break;

            case 10:
                    delete_client(&client_base_pointer);
                    system(CLEAR);
                    printf(" Pomy˜lnie usuni©to klienta z bazy\n");
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
                    printf(" Pomy˜lnie zapisano klient¢w do pliku\n");
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
    printf(" Zapisuj© dane do plik¢w, prosze nie wyˆ¥cza† aplikacji lub komputera...\n\n");
    write_to_file(base_pointer); ///store lists in file before exit
    clients_write_to_file(client_base_pointer);
    write_borrow_to_file(borrow_base_pointer);

    delete_base(&base_pointer); ///remove book base from ram
    delete_client_base(&client_base_pointer);
    delete_borrow_base(&borrow_base_pointer);

    system(CLEAR);
    printf(" Zapisano! Dziaˆanie aplikacji zostaˆo zakoäczone, mo¾na teraz zamkn¥† to okno\n");

    return 0;
}
