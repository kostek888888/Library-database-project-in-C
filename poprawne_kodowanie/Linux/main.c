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
    int client_id_to_search=0;
    long long int pesel;
    char title[100];
    char author[100];
    int amount_to_borrow=0;

    Library *temporary_pointer = base_pointer;
    Client *client_temporary_pointer = client_base_pointer;

    printf("\n Wpisz id klienta wypożyczającego książkę: ");
    scanf(" %d",&client_id_to_search);
    while(client_id_to_search<1){
        printf("\n Wprowadzono błędny numer id klienta, spróbuj ponownie: ");
        scanf(" %d",&client_id_to_search);
    }

    if(client_temporary_pointer!=NULL&&temporary_pointer!=NULL){
        while((client_temporary_pointer->client_id!=client_id_to_search)&&(client_temporary_pointer!=NULL)){
            client_temporary_pointer=client_temporary_pointer->next;
        }
        if(client_temporary_pointer!=NULL){

            if(client_base_pointer->id_book3==0){
            printf("\n Wpisz nazwę książki do wypożyczenia: ");
            gets(title);
            printf("\n Wpisz autora książki do wypożyczenia: ");
            gets(author);

            while((strcmp(temporary_pointer->title,title)!=0)&&(strcmp(temporary_pointer->author, author)!=0)&&(temporary_pointer!=NULL))
                {
                    temporary_pointer=temporary_pointer->next;
                }
            if(temporary_pointer!=NULL)
                {
                    borrow_id++;

                    if(temporary_pointer->copies>0)
                    printf("\n Na stanie jest %4d książek, ile sztuk chcesz wypożyczyć?\n",temporary_pointer->copies);
                    scanf(" %d",&amount_to_borrow);
                    while((amount_to_borrow<1)||(temporary_pointer->copies-amount_to_borrow<0)){
                        printf("\n Spróbowano wypożyczyć nieprawidłową ilość książek, spróbuj ponownie: ");
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
                    printf(" Napotkano błąd, nie można wypożyczyć książki\n");
            }
        }
    }
    else
        printf(" Napotkano błąd, nie można wypożyczyć książki\n");
}




/*!
 *   @brief główna funkcja programu w której użytkownik wybiera operacje do wykonania, po wyjściu z pętli switch funkcja zapisuje wszystkie listy do plików i kasuje je z pamięci podręcznej
 *
 *   @return 0
 */
int main(void)
{
    int menu_choice=0;

    while(menu_choice!=99) {
        printf("\n Biblioteka: Wybierz jedną z podanych niżej opcji\n");
        printf(" 1.  Dodaj książkę\n");
        printf(" 2.  Usuń książkę\n");
        printf(" 3.  Edytuj ksisiążki\n");
        printf(" 4.  Wyświetl książki\n");
        printf(" 5.  Posortuj książki\n");
        printf(" 6.  Wyszukaj książki\n");
        printf(" 7.  Zapisz książki do pliku\n");
        printf(" 8.  Odczytaj książki z pliku\n\n");

        printf(" 9.  Dodaj klienta\n");
        printf(" 10. Usuń klienta\n");
        printf(" 11. Edytuj klienta\n");
        printf(" 12. Wyświetl klientów\n");
        printf(" 13. Posortuj klientów\n");
        printf(" 14. Wyszukaj klienta po jego ID\n");
        printf(" 15. Zapisz klientów do pliku\n");
        printf(" 16. Odczytaj klientów z pliku\n\n");

        printf(" 17. Wykonaj operację wypożycz książkę\n");
        printf(" 18. Wykonaj operację oddaj książkę\n");
        printf(" 19. Pokaż wszystkie wykonane operacje\n");
        printf(" 20. Usuń bazę wypożyczeń\n");

        printf("\n 99. Zakończenie programu i zwolnienie pamięci podręcznej\n\n");
        printf( "       Twój wybór: ");
        scanf("%i", &menu_choice);
        system(CLEAR);

        switch(menu_choice) {
            case 1:
                    id++;
                    add_new_book(&base_pointer, id);
                    system(CLEAR);
                    printf("\n !!! Książka została pomyślnie dodana do bazy !!!\n");
                    break;

            case 2:
                    delete_book(&base_pointer);
                    system(CLEAR);
                    printf(" Książkę pomyślnie usunięto z bazy\n");
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
                    printf(" Pomyślnie zapisano książki do pliku\n");
                    break;

            case 8:
                    read_file1();
                    break;
            case 9:
                    id++;
                    add_new_client(&client_base_pointer, client_id);
                    system(CLEAR);
                    printf("\n !!! Pomyślnie dodano klienta do bazy !!!\n");
                    break;

            case 10:
                    delete_client(&client_base_pointer);
                    system(CLEAR);
                    printf(" Pomyślnie usunięto klienta z bazy\n");
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
                    printf(" Pomyślnie zapisano klientów do pliku\n");
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
    printf(" Zapisuję dane do plików, prosze nie wyłączać aplikacji lub komputera...\n\n");
    write_to_file(base_pointer); ///store lists in file before exit
    clients_write_to_file(client_base_pointer);
    write_borrow_to_file(borrow_base_pointer);

    delete_base(&base_pointer); ///remove book base from ram
    delete_client_base(&client_base_pointer);
    delete_borrow_base(&borrow_base_pointer);

    system(CLEAR);
    printf(" Zapisano! Działanie aplikacji zostało zakończone, można teraz zamknąć to okno\n");

    return 0;
}
