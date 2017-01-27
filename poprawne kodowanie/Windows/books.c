#include "books.h"
#include <stdio.h>
#include <stdlib.h>

int count_list=0; /*!< zmienna licz�ca ilo�� element�w listy ksi��ek */

/*!
 *   @brief funkcja uzupe�nia dane w konkretnym elemencie listy ksi��ek utworzonym przez funkcj� add_new_client
 *
 *   @param Library *(*new_node) podw�jny wska�nik na nowy element listy ksi��ek
 */
void new_book_fill(Library *(*new_node)) {

    char buffer[100]; /// grab strings
    int numbers; /// grab numbers
    gets(buffer); /// flush enter
    printf(" Podaj dane dotycz�ce ksi��ki, kolejno:\n\n");
    printf(" Tytu�: ");
    gets(buffer);
    strcpy((*new_node)->title, buffer);
    printf("\n Autor: ");
    gets(buffer);
    strcpy((*new_node)->author, buffer);
    printf("\n Rok wydania: ");
    scanf(" %d",&numbers);
    gets(buffer);
    (*new_node)->year = numbers;
    printf("\n Gatunek ksi��ki: ");
    gets(buffer);
    strcpy((*new_node)->genre, buffer);
    printf("\n Liczba kopii dost�pnych na stanie: ");
    scanf(" %d",&numbers);
    while(numbers<0){
        printf("\n Nie mo�na posiada� ujemnej ilo�ci ksi��ek na stanie, spr�buj ponownie: ");
        scanf(" %d",&numbers);
    }
    (*new_node)->copies = numbers;
    printf("\n Liczba wypo�yczonych obecnie kopii: ");
    scanf(" %d",&numbers);
    while(numbers<0){
        printf("\n Nie mo�na wypo�yczy� ujemnej ilo�ci ksi��ek, spr�buj ponownie: ");
        scanf(" %d",&numbers);
    }
    (*new_node)->borrowed = numbers;
}


/*!
 *   @brief funkcja tworzy element listy ksi��ek a nast�pnie wywo�uje funkcj� new_book_fill kt�ra uzupe�nia pola danych elementu
 *
 *   @param Library **base_pointer podw�jny wska�nik na list� ksi��ek
 *   @param int id numer id ksi��ki
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
 *   @brief funkcja usuwa ca�� baz� ksi��ek
 *
 *   @param Library **base_pointer podw�jny wska�nik na list� ksi��ek
 */
void delete_base(Library **base_pointer) {
    while(*base_pointer!=NULL) {
        Library *next = (*base_pointer)->next;
        free(*base_pointer);
        *base_pointer=next;
    }
}


/*!
 *   @brief funkcja szuka ksi��ki w li�cie ksia�ek po polu id
 *
 *   @param Library *base_pointer wska�nik na list� ksi��ek
 */
void search_for_book(Library *base_pointer)
{
    int id_to_search;
    char title[100];
    char author[100];
    char genre[100];

    int choice=0;

    Library *temporary_pointer = base_pointer;

    printf("\n Wybierz po jakim polu chcesz wyszuka� ksi��k�, oto opcje:\n");
    printf("\n 1. Po numerze id");
    printf("\n 2. Po tytule ksi��ki");
    printf("\n 3. Po autorze ksi��ki");
    printf("\n 4. Po gatunku ksi��ki");
    printf("\n\n Tw�j wyb�r: ");
    scanf(" %d",&choice);

    switch(choice){
        case 1:
                printf("\n Wpisz id ksi��ki jak� chcesz znale��: ");
                scanf(" %d",&id_to_search);
				while(id_to_search<1){
					printf("\n Nie istnieje ksi��ka o ujemnym id, spr�buj ponownie: ");
					scanf(" %d",&id_to_search);
				}
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
                        printf(" Brak ksi��ek spee�niaj�cych kryteria\n");
                break;
        case 2:
                printf("\n Wpisz tytu� ksi��ki jak� chcesz znale��: ");
                gets(title);
                while((strcmp(temporary_pointer->title, title)!=0)&&(temporary_pointer!=NULL))
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
                        printf(" Brak ksi��ek spee�niaj�cych kryteria\n");
                break;
        case 3:
                printf("\n Wpisz autora ksi��ki jak� chcesz znale��: ");
                gets(author);
                gets(author);
                while((temporary_pointer!=NULL)&&(strcmp(temporary_pointer->author, author)!=0))
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
                        printf(" Brak ksi��ek spee�niaj�cych kryteria\n");
                break;
        case 4:
                printf("\n Wpisz gatunek ksi��ki jak� chcesz znale��: ");
                gets(genre);
                gets(genre);
                while((temporary_pointer!=NULL)&&(strcmp(temporary_pointer->genre, genre)!=0))
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
                        printf(" Brak ksi��ek spee�niaj�cych kryteria\n");
                break;
        default:
                printf("\n Dokonano nieprawid�owego wyboru w funkcji szukaj�cej");
    }
}


/*!
 *   @brief funkcja usuwa pojedy�cz� ksi��k� z bazy ksi��ek
 *
 *   @param Library **base_pointer podw�jny wska�nik na list� ksi��ek
 */
void delete_book(Library **base_pointer){
    int id;
    printf(" Wpisz id ksi��ki, kt�r� chcesz usun�� z bazy: ");
    scanf(" %d",&id);
    Library *tmp_pointer=*base_pointer;

    if((*base_pointer)->id==id){
        *base_pointer=(*base_pointer)->next;
        free(tmp_pointer);
        printf("\n Usuni�cie ksi��ki zako�czone sukcesem.\n");
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
 *   @brief funkcja wypisuje na ekran ca�� list� ksi��ek
 *
 *   @param Library *base_pointer wska�nik na list� ksi��ek
 */
void cout_base(Library *base_pointer) {

    if (base_pointer!=NULL)
    {
        cout_base(base_pointer->next);
        printf("ID: %d ",base_pointer->id);
        printf("tytu�: %-10s ",base_pointer->title);
        printf("rok: %4d ",base_pointer->year);
        printf("autor: %-10s ",base_pointer->author);
        printf("Gatunek: %-10s ",base_pointer->genre);
        printf("Dost�pne kopie: %d ",base_pointer->copies);
        printf("Wypo�yczonych: %d \n",base_pointer->borrowed);
    }
}

/*!
 *   @brief funkcja zapisuje ca�� list� ksi��ek do pliku books.txt
 *
 *   @param Library *base_pointer wska�nik na list� ksi��ek
 */
void write_to_file(Library *base_pointer)
{
    FILE *file1;
    file1=fopen("books.txt", "w");
    file1=fopen("books.txt", "a");
        if(file1==NULL)
                printf(" Wyst�pi� b��d z plikiem books.txt\n");
        else
        {
            if(base_pointer!=NULL)
            {
                write_to_file(base_pointer->next);
                fprintf(file1,"ID: %d",base_pointer->id);
                fprintf(file1," tytu�: %s",base_pointer->title);
                fprintf(file1," autor: %s",base_pointer->author);
                fprintf(file1," rok: %d",base_pointer->year);
                fprintf(file1," Gatunek: %s",base_pointer->genre);
                fprintf(file1," Dost�pne kopie: %d",base_pointer->copies);
                fprintf(file1," Wypo�yczonych: %d\n",base_pointer->borrowed);
            }
        }
    fclose(file1);
}


/*!
 *   @brief funkcja czyta plik books.txt z list� ksi��ek i wy�wietla j� na ekranie
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
 *   @brief funkcja pozwala na edycj� pojedy�czej ksi��ki, nale�y poda� jej id
 *
 *   @param Library *base_pointer wska�nik na list� ksi��ek
 */
void edit_book(Library *base_pointer) {
    char buffer[100];
    int numbers;
    char check[100];
    check[0]='.';

    printf("Wpisz nazw� ksi��ki, kt�r� chcesz edytowa�: ");
    gets(buffer);
    gets(buffer);

    Library *temporary_pointer = base_pointer;

    while((strcmp((temporary_pointer)->title,buffer)!=0)&&(temporary_pointer!=NULL))
        {
            temporary_pointer=temporary_pointer->next;
        }
    if(temporary_pointer!=NULL)
        {
            printf(" UWAGA edycja danych o ksi��ce:\n\n");

            printf(" Tytu�: ");
            printf("\n%-10s",temporary_pointer->title);
            printf(" Czy chcesz go zmieni�? Kropka pomija podpunkt\n");
            gets(buffer);
            if(strcmp(buffer, check)!=0)
            strcpy(temporary_pointer->title, buffer);

            printf("\n Autor: ");
            printf("\n%-10s",temporary_pointer->author);
            printf(" Czy chcesz go zmieni�? Kropka pomija podpunkt\n");
            gets(buffer);
            if(strcmp(buffer, check)!=0)
            strcpy(temporary_pointer->author, buffer);

            printf("\n Rok wydania: ");
            printf("\n%4d",temporary_pointer->year);
            printf(" Czy chcesz go zmieni�? Warto�� mniejsza lub r�wna zero pomija podpunkt\n");
            scanf(" %d",&numbers);
            gets(buffer);
            if(numbers>0)
            temporary_pointer->year = numbers;

            printf("\n Gatunek ksi��ki: ");
            printf("\n%-10s",temporary_pointer->genre);
            printf(" Czy chcesz go zmieni�? Kropka pomija podpunkt\n");
            gets(buffer);
            if(strcmp(buffer, check)!=0)
            strcpy(temporary_pointer->genre, buffer);

            printf("\n Liczba kopii dost�pnych na stanie: ");
            printf("%d\n",temporary_pointer->copies);
            printf(" Czy chcesz go zmieni�? Warto�� mniejsza lub r�wna zero pomija podpunkt\n");
            scanf(" %d",&numbers);
            gets(buffer);
            if(numbers>0)
            temporary_pointer->copies = numbers;

            printf("\n Liczba wypo�yczonych obecnie kopii: ");
            printf("%d\n",temporary_pointer->borrowed);
            printf(" Czy chcesz go zmieni�? Warto�� mniejsza lub r�wna zero pomija podpunkt\n");
            scanf(" %d",&numbers);
            if(numbers>0)
            temporary_pointer->borrowed = numbers;
        }
        else
            printf("\n Nie znaleziono takiej ksi��ki");
}


/*!
 *   @brief funkcja sortuje ksi��ki na li�cie wed�ug wskazanego przez u�ytkownika wyboru a nast�pnie wywo�uje wypisanie listy ksi��ek na ekran
 *
 *   @param Library *base_pointer wska�nik na list� klient�w
 */
void sort_book_list(Library *base_pointer){


int choice_one=0;
int choice_two=0;

printf(" Wybierz po jakim polu chcesz sortowa� ksi��ki? Oto opcje:\n");
printf(" 1. Tytu�\n");
printf(" 2. Autor\n");
printf(" 3. Rok wydania\n");
printf(" 4. Gatunek ksi��ki\n");
printf(" 5. Liczba kopii dost�pnych na stanie\n");
printf(" 6. Liczba wypo�yczonych obecnie kopii\n");
printf(" 7. Po numerze ID\n");
printf("    Tw�j wyb�r: ");

scanf(" %d",&choice_one);
while((choice_one<1)||(choice_one>7)){
    printf("\n Nie wybrano poprawnie, spr�buj ponownie: ");
    scanf(" %d",&choice_one);
}

printf("\n Wybierz kolejno�� sortowania: ");
printf("\n 1. Malej�co");
printf("\n 2. Rosn�co\n");
scanf(" %d",&choice_two);
while((choice_two<1)||(choice_two>2)){
    printf("\n Nie wybrano poprawnie kolejno�ci, spr�buj ponownie: ");
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
                printf("\n Wybrano sortowanie po tytule malej�co, wykonuj�...");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po tytule rosn�co, wykonuj�...\n");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            break;
    case 2:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po autorze malej�co, wykonuj�...");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po autorze rosn�co, wykonuj�...\n");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            break;
    case 3:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po roku malej�co, wykonuj�...");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po roku rosn�co, wykonuj�...\n");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            break;
    case 4:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po gatunku malej�co, wykonuj�...");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po tytule rosn�co, wykonuj�...\n");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            break;
    case 5:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po liczbie kopii dost�pnych malej�co, wykonuj�...");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po liczbie kopii dost�pnych rosn�co, wykonuj�...\n");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            break;
    case 6:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po liczbie obecnie wypo�yczonych malej�co, wykonuj�...");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po liczbie obecnie wypo�yczonych rosn�co, wykonuj�...\n");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            break;
    case 7:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po numerze ID malej�co, wykonuj�...");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po numerze ID rosn�co, wykonuj�...\n");
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
                printf("\n Sortowanie wykonano pomy�lnie!\n");
            }
            break;
    }
    cout_base(base_pointer);
}



