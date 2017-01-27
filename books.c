
/// ¥ † © ä ¢ ˆ ¾ «
/// ¥ † © ä ¢ ˆ ¾ «

#include "books.h"
#include <stdio.h>
#include <stdlib.h>

int count_list=0; /*!< zmienna licząca ilość elementów listy książek */

/*!
 *   @brief funkcja uzupełnia dane w konkretnym elemencie listy książek utworzonym przez funkcję add_new_client
 *
 *   @param Library *(*new_node) podwójny wskaźnik na nowy element listy książek
 */
void new_book_fill(Library *(*new_node)) {

    char buffer[100]; /// grab strings
    int numbers; /// grab numbers
    gets(buffer); /// flush enter
    printf(" Podaj dane dotycz¥ce ksi¥¾ki, kolejno:\n\n");
    printf(" Tytuˆ: ");
    gets(buffer);
    strcpy((*new_node)->title, buffer);
    printf("\n Autor: ");
    gets(buffer);
    strcpy((*new_node)->author, buffer);
    printf("\n Rok wydania: ");
    scanf(" %d",&numbers);
    gets(buffer);
    (*new_node)->year = numbers;
    printf("\n Gatunek ksi¥¾ki: ");
    gets(buffer);
    strcpy((*new_node)->genre, buffer);
    printf("\n Liczba kopii dost©pnych na stanie: ");
    scanf(" %d",&numbers);
    while(numbers<0){
        printf("\n Nie mo¾na posiada† ujemnej ilo˜ci ksi¥¾ek na stanie, spr¢buj ponownie: ");
        scanf(" %d",&numbers);
    }
    (*new_node)->copies = numbers;
    printf("\n Liczba wypo¾yczonych obecnie kopii: ");
    scanf(" %d",&numbers);
    while(numbers<0){
        printf("\n Nie mo¾na wypo¾yczy† ujemnej ilo˜ci ksi¥¾ek, spr¢buj ponownie: ");
        scanf(" %d",&numbers);
    }
    (*new_node)->borrowed = numbers;
}


/*!
 *   @brief funkcja tworzy element listy książek a następnie wywołuje funkcję new_book_fill która uzupełnia pola danych elementu
 *
 *   @param Library **base_pointer podwójny wskaźnik na listę książek
 *   @param int id numer id książki
 */
void add_new_book(Library **base_pointer, int id) {

    Library *new_book = (Library*)malloc(sizeof(Library));

    if(new_book!=NULL)
    {
        count_list++;

        new_book->next = *base_pointer;
        *base_pointer = new_book;
        new_book->id = id;
        new_book_fill(&new_book);
    }
}


/*!
 *   @brief funkcja usuwa całą bazę książek
 *
 *   @param Library **base_pointer podwójny wskaźnik na listę książek
 */
void delete_base(Library **base_pointer) {
    while(*base_pointer!=NULL) {
        Library *next = (*base_pointer)->next;
        free(*base_pointer);
        *base_pointer=next;
    }
}


/*!
 *   @brief funkcja szuka książki w liście ksiażek po polu id
 *
 *   @param Library *base_pointer wskaźnik na listę książek
 */
void search_for_book(Library *base_pointer)
{
    int id_to_search;
    printf("\n Wpisz id ksi¥¾ki jak¥ chcesz znale«†: ");
    scanf(" %d",&id_to_search);
    Library *temporary_pointer = base_pointer;
    while(((temporary_pointer)->id!=id_to_search)&&(temporary_pointer!=NULL))
        {
            temporary_pointer=temporary_pointer->next;
        }
    if(temporary_pointer!=NULL)
        {
            printf(" %3d ",temporary_pointer->id);
            printf(" %-10s ",temporary_pointer->title);
            printf(" %4d ",temporary_pointer->year);
            printf(" %-10s ",temporary_pointer->author);
            printf(" %-10s ",temporary_pointer->genre);
            printf(" %4d ",temporary_pointer->copies);
            printf(" %4d ",temporary_pointer->borrowed);
        }
        else
            printf(" Brak ksi¥¾ek speeˆniaj¥cych kryteria\n");
}


/*!
 *   @brief funkcja usuwa pojedyńczą książkę z bazy książek
 *
 *   @param Library **base_pointer podwójny wskaźnik na listę książek
 */
void delete_book(Library **base_pointer){
    int id;
    printf(" Wpisz id ksi¥¾ki, kt¢r¥ chcesz usun¥† z bazy: ");
    scanf(" %d",&id);
    Library *tmp_pointer=*base_pointer;

    if((*base_pointer)->id==id){
        *base_pointer=(*base_pointer)->next;
        free(tmp_pointer);
        printf("\n Usuni©cie ksi¥¾ki zakoäczone sukcesem.\n");
    } else {
        Library *one_book_before;

        while((tmp_pointer!=NULL)&&(tmp_pointer->id!=id)){
            one_book_before=tmp_pointer;
            tmp_pointer=tmp_pointer->next;
        }

        Library *tmp_pointer_2=one_book_before->next;

        if(one_book_before!=NULL) {
            one_book_before->next=tmp_pointer_2->next;
            free(tmp_pointer_2);
        }
    }
}

/*!
 *   @brief funkcja wypisuje na ekran całą listę książek
 *
 *   @param Library *base_pointer wskaźnik na listę książek
 */
void cout_base(Library *base_pointer) {

    if (base_pointer!=NULL)
    {
        cout_base(base_pointer->next);
        printf("ID: %d ",base_pointer->id);
        printf("tytuˆÅ: %-10s ",base_pointer->title);
        printf("rok: %4d ",base_pointer->year);
        printf("autor: %-10s ",base_pointer->author);
        printf("Gatunek: %-10s ",base_pointer->genre);
        printf("Dost©pne kopie: %d ",base_pointer->copies);
        printf("Wypo¾yczonych: %d \n",base_pointer->borrowed);
    }
}

/*!
 *   @brief funkcja zapisuje całą listę książek do pliku books.txt
 *
 *   @param Library *base_pointer wskaźnik na listę książek
 */
void write_to_file(Library *base_pointer)
{
    FILE *file1;
    file1=fopen("books.txt", "w");
    file1=fopen("books.txt", "a");
        if(file1==NULL)
                printf(" Wyst¥piˆ bˆ¥d z plikiem books.txt\n");
        else
        {
            if(base_pointer!=NULL)
            {
                write_to_file(base_pointer->next);
                fprintf(file1,"ID: %d",base_pointer->id);
                fprintf(file1," tytuˆ: %s",base_pointer->title);
                fprintf(file1," autor: %s",base_pointer->author);
                fprintf(file1," rok: %d",base_pointer->year);
                fprintf(file1," Gatunek: %s",base_pointer->genre);
                fprintf(file1," Dost©pne kopie: %d",base_pointer->copies);
                fprintf(file1," Wypo¾yczonych: %d\n",base_pointer->borrowed);
            }
        }
    fclose(file1);
}


/*!
 *   @brief funkcja czyta plik books.txt z listą książek i wyświetla ją na ekranie
 */
void read_file1()
{
    char letter;
    FILE *file1;

    file1=fopen("books.txt", "r");
    while((letter=fgetc(file1))!=EOF)
    {
        printf("%c",letter);
    }
    fclose(file1);
}


/*!
 *   @brief funkcja pozwala na edycję pojedyńczej książki, należy podać jej id
 *
 *   @param Library *base_pointer wskaźnik na listę książek
 */
void edit_book(Library *base_pointer) {
    char buffer[100];
    int numbers;
    char check[100];
    check[0]='.';

    printf("Wpisz nazw© ksi¥¾ki, kt¢r¥ chcesz edytowa†: ");
    gets(buffer);
    gets(buffer);

    Library *temporary_pointer = base_pointer;

    while((strcmp((temporary_pointer)->title,buffer)!=0)&&(temporary_pointer!=NULL))
        {
            temporary_pointer=temporary_pointer->next;
        }
    if(temporary_pointer!=NULL)
        {
            printf(" UWAGA edycja danych o ksi¥¾ce:\n\n");

            printf(" Tytuˆ: ");
            printf("\n%-10s",temporary_pointer->title);
            printf(" Czy chcesz go zmieni†? Kropka pomija podpunkt\n");
            gets(buffer);
            if(strcmp(buffer, check)!=0)
            strcpy(temporary_pointer->title, buffer);

            printf("\n Autor: ");
            printf("\n%-10s",temporary_pointer->author);
            printf(" Czy chcesz go zmieni†? Kropka pomija podpunkt\n");
            gets(buffer);
            if(strcmp(buffer, check)!=0)
            strcpy(temporary_pointer->author, buffer);

            printf("\n Rok wydania: ");
            printf("\n%4d",temporary_pointer->year);
            printf(" Czy chcesz go zmieni†? Warto˜† mniejsza lub r¢wna zero pomija podpunkt\n");
            scanf(" %d",&numbers);
            gets(buffer);
            if(numbers>0)
            temporary_pointer->year = numbers;

            printf("\n Gatunek ksi¥¾ki: ");
            printf("\n%-10s",temporary_pointer->genre);
            printf(" Czy chcesz go zmieni†? Kropka pomija podpunkt\n");
            gets(buffer);
            if(strcmp(buffer, check)!=0)
            strcpy(temporary_pointer->genre, buffer);

            printf("\n Liczba kopii dost¶cpnych na stanie: ");
            printf("%d\n",temporary_pointer->copies);
            printf(" Czy chcesz go zmieni†? Warto˜† mniejsza lub r¢wna zero pomija podpunkt\n");
            scanf(" %d",&numbers);
            gets(buffer);
            if(numbers>0)
            temporary_pointer->copies = numbers;

            printf("\n Liczba wypo¾yczonych obecnie kopii: ");
            printf("%d\n",temporary_pointer->borrowed);
            printf(" Czy chcesz go zmieni†? Warto˜† mniejsza lub r¢wna zero pomija podpunkt\n");
            scanf(" %d",&numbers);
            if(numbers>0)
            temporary_pointer->borrowed = numbers;
        }
        else
            printf("Nie znaleziono takiej ksia¾ki");
}


/*!
 *   @brief funkcja sortuje książki na liście według wskazanego przez użytkownika wyboru a następnie wywołuje wypisanie listy książek na ekran
 *
 *   @param Library *base_pointer wskaźnik na listę klientów
 */
void sort_book_list(Library *base_pointer){


int choice_one=0;
int choice_two=0;

printf(" Wybierz po jakim polu chcesz sortowa† ksi¥¾ki? Oto opcje:\n");
printf(" 1. Tytuˆ\n");
printf(" 2. Autor\n");
printf(" 3. Rok wydania\n");
printf(" 4. Gatunek ksi¥¾ki\n");
printf(" 5. Liczba kopii dost©pnych na stanie\n");
printf(" 6. Liczba wypo¾yczonych obecnie kopii\n");
printf(" 7. Po numerze ID\n");
printf("    Tw¢j wyb¢r: ");

scanf(" %d",&choice_one);
while((choice_one<1)||(choice_one>7)){
    printf("\n Nie wybrano poprawnie, spr¢buj ponownie: ");
    scanf(" %d",&choice_one);
}

printf("\n Wybierz kolejno˜† sortowania: ");
printf("\n 1. Malej¥co");
printf("\n 2. Rosn¥co\n");
scanf(" %d",&choice_two);
while((choice_two<1)||(choice_two>2)){
    printf("\n Nie wybrano poprawnie kolejno˜ci, spr¢buj ponownie: ");
    scanf(" %d",&choice_two);
}

Library *wsk=base_pointer;
int i;
int j;

int id;
char title[100];
int year;
char author[100];
char genre[100];
int copies;
int borrowed;

switch(choice_one) {
    case 1:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po tytule malej¥co, wykonuj©...");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(strcmp(wsk->title, wsk->next->title)>0) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po tytule rosn¥co, wykonuj©...\n");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(strcmp(wsk->title, wsk->next->title)<0) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            break;
    case 2:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po autorze malej¥co, wykonuj©...");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(strcmp(wsk->author, wsk->next->author)>0) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po autorze rosn¥co, wykonuj©...\n");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(strcmp(wsk->author, wsk->next->author)<0) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            break;
    case 3:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po roku malej¥co, wykonuj©...");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(wsk->year>wsk->next->year) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po roku rosn¥co, wykonuj©...\n");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(wsk->year<wsk->next->year) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            break;
    case 4:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po gatunku malej¥co, wykonuj©...");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(strcmp(wsk->genre, wsk->next->genre)>0) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po tytule rosn¥co, wykonuj©...\n");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(strcmp(wsk->genre, wsk->next->genre)<0) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            break;
    case 5:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po liczbie kopii dost©pnych malej¥co, wykonuj©...");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(wsk->copies>wsk->next->copies) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po liczbie kopii dost©pnych rosn¥co, wykonuj©...\n");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(wsk->copies<wsk->next->copies) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            break;
    case 6:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po liczbie obecnie wypo¾yczonych malej¥co, wykonuj©...");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(wsk->borrowed>wsk->next->borrowed) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po liczbie obecnie wypo¾yczonych rosn¥co, wykonuj©...\n");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(wsk->borrowed<wsk->next->borrowed) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            break;
    case 7:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po numerze ID malej¥co, wykonuj©...");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(wsk->id>wsk->next->id) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po numerze ID rosn¥co, wykonuj©...\n");
                for(i=0;i<count_list;++i) {
                    wsk=base_pointer;
                    for(j=0;j<count_list-1;++j) {
                        if(wsk->id<wsk->next->id) {
                            id=wsk->id;
                            strcpy(title, wsk->title);
                            year=wsk->year;
                            strcpy(author, wsk->author);
                            strcpy(genre, wsk->genre);
                            copies=wsk->copies;
                            borrowed=wsk->borrowed;

                            wsk->id=wsk->next->id;
                            strcpy(wsk->title, wsk->next->title);
                            wsk->year=wsk->next->year;
                            strcpy(wsk->author, wsk->next->author);
                            strcpy(wsk->genre, wsk->next->genre);
                            wsk->copies=wsk->next->copies;
                            wsk->borrowed=wsk->next->borrowed;

                            wsk->next->id=id;
                            strcpy(wsk->next->title, title);
                            wsk->next->year=year;
                            strcpy(wsk->next->author, author);
                            strcpy(wsk->next->genre, genre);
                            wsk->next->copies=copies;
                            wsk->next->borrowed=borrowed;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            break;
    }
    cout_base(base_pointer);
}



