#include "clients.h"
#include <stdio.h>
#include <stdlib.h>

int count_client_list=0; /*!< zmienna licz¥ca ilo˜† element¢w na li˜cie klient¢w */

/*!
 *   @brief funkcja uzupeˆnia dane w konkretnym elemencie listy klient¢w utworzonym przez funkcj© add_new_client
 *
 *   @param Client *(*new_client_node) podw¢jny wska«nik na nowy element listy klient¢w
 */
void fill_client(Client *(*new_client_node)) {

    char buffer[100];
    int numbers;
    long long int pesel;
    system(CLEAR);
    gets(buffer);
    printf(" Wpisz imi© klienta: ");
    gets(buffer);
    strcpy((*new_client_node)->name, buffer);
    printf("\n Wpisz nazwisko klienta: ");
    gets(buffer);
    strcpy((*new_client_node)->surname, buffer);
    printf("\n Wpisz numerycznie dzieä urodzenia klienta: ");
    scanf(" %d",&numbers);
    (*new_client_node)->d_of_b_day = numbers;
    printf("\n Wpisz numerycznie miesi¥c urodzenia klienta: ");
    scanf(" %d",&numbers);
    (*new_client_node)->m_of_b_day = numbers;
    printf("\n Wpisz numerycznie rok urodzenia klienta: ");
    scanf(" %d",&numbers);
    (*new_client_node)->y_of_b_day = numbers;
    printf("\n Wpisz numerycznie numer PESEL klienta: ");
    scanf("%I64d",&pesel);
    gets(buffer);
    (*new_client_node)->pesel = pesel;
    numbers=0;
    printf("\n Klient maksymalnie mo¾e wypo¾yczy† ksi¥¾ki o 3 r¢¾nych tytuˆach");
    printf("\n Wpisz id 1 ksi¥¾ki jak¥ wypo¾yczyˆ klient, warto˜ci < lub = 0 to brak ksi¥¾ki\n");
    scanf(" %d",&numbers);
    if(numbers>0)
    {
       (*new_client_node)->id_book1 = numbers;
       printf("\n Wpisz id 2 ksi¥¾ki jak¥ wypo¾yczyˆ klient, warto˜ci < lub =0 to brak ksi¥¾ki\n");
       scanf(" %d",&numbers);
       if(numbers>0)
       {
           (*new_client_node)->id_book2 = numbers;
           printf("\n Wpisz id 3 ksi¥«ki jak¥ wypo«yczyˆ klient, warto˜ci < lub = 0 to brak ksi¥¾ki\n");
           scanf(" %d",&numbers);
           if(numbers>0)
           {
               (*new_client_node)->id_book3 = numbers;
           }
            else
                (*new_client_node)->id_book3 = -1;
       }
        else
            (*new_client_node)->id_book2 = -1;
    }
    else
        (*new_client_node)->id_book1 = -1;
}


/*!
 *   @brief funkcja tworzy element listy klient¢w a nast©pnie wywoˆuje funkcj© fill_client kt¢ra uzupeˆnia pola danych elementu
 *
 *   @param Client **client_base_pointer podw¢jny wska«nik na list© klient¢w
 *   @param int client_id numer id klienta
 */
void add_new_client(Client **client_base_pointer, int client_id) {

    Client *new_client = (Client*)malloc(sizeof(Client));

    if(new_client!=NULL)
    {
        count_client_list++;
        client_id++;

        new_client->next = *client_base_pointer;
        *client_base_pointer = new_client;
        new_client->client_id = client_id;
        fill_client(&new_client);
    }
}


/*!
 *   @brief funkcja usuwa caˆ¥ baz© klient¢w
 *
 *   @param Client **client_base_pointer podw¢jny wska«nik na list© klient¢w
 */
void delete_client_base(Client **client_base_pointer) {
    while(*client_base_pointer!=NULL) {
        Client *next = (*client_base_pointer)->next;
        free(*client_base_pointer);
        *client_base_pointer=next;
    }
}


/*!
 *   @brief funkcja szuka klienta w li˜cie klient¢w po polu id
 *
 *   @param Client *client_base_pointer wska«nik na list© klient¢w
 */
void seek_for_client(Client *client_base_pointer)
{
    int id_to_search;
    printf("\n Wpisz id klienta kt¢rego chcesz znale«†: ");
    scanf(" %d",&id_to_search);
    Client *temporary_pointer = client_base_pointer;
    while(((temporary_pointer)->client_id!=id_to_search)&&(temporary_pointer!=NULL))
        {
            temporary_pointer=temporary_pointer->next;
        }
    if(temporary_pointer!=NULL)
        {
            printf(" %3d. ",temporary_pointer->client_id);
            printf(" %-15s ",temporary_pointer->name);
            printf(" %-15s ",temporary_pointer->surname);
            printf(" %2d ",temporary_pointer->d_of_b_day);
            printf(" %2d ",temporary_pointer->m_of_b_day);
            printf(" %4d ",temporary_pointer->y_of_b_day);
            printf(" %I64d ",temporary_pointer->pesel);
        }
        else
            printf(" Nie znaleziono klienta o danym id\n");
}

/*!
 *   @brief funkcja usuwa pojedyäczego klienta z bazy klient¢w
 *
 *   @param Client **client_base_pointer podw¢jny wska«nik na list© klient¢w
 */
void delete_client(Client **client_base_pointer){
    int id;
    printf(" Wpisz id klienta, kt¢rego chcesz usun¥† z bazy: ");
    scanf(" %d",&id);
    Client *tmp_pointer=*client_base_pointer;

    if((*client_base_pointer)->client_id==id){
        *client_base_pointer=(*client_base_pointer)->next;
        free(tmp_pointer);
        printf("\n Usuni©cie klienta zakoäczone sukcesem.\n");
    } else {
        Client *one_client_before;

        while((tmp_pointer!=NULL)&&(tmp_pointer->client_id!=id)){
            one_client_before=tmp_pointer;
            tmp_pointer=tmp_pointer->next;
        }

        Client *tmp_pointer_2=one_client_before->next;

        if(one_client_before!=NULL) {
            one_client_before->next=tmp_pointer_2->next;
            free(tmp_pointer_2);
        }
    }
}
/*!
 *   @brief funkcja wypisuje na ekran caˆ¥ list© klient¢w
 *
 *   @param Client *client_base_pointer wska«nik na list© klient¢w
 */
void cout_client_base(Client *client_base_pointer) {

    if (client_base_pointer!=NULL)
    {
        cout_client_base(client_base_pointer->next);
        printf(" %3d ",client_base_pointer->client_id);
        printf(" %-15s ",client_base_pointer->name);
        printf(" %-15s ",client_base_pointer->surname);
        printf(" %2d/",client_base_pointer->d_of_b_day);
        printf("%2d/",client_base_pointer->m_of_b_day);
        printf("%4d ",client_base_pointer->y_of_b_day);
        printf(" %I64d \n",client_base_pointer->pesel);
        if(client_base_pointer->id_book1>0)
        {
            printf(" ksi¥¾ka 1: %3d ",client_base_pointer->id_book1);
            if(client_base_pointer->id_book2>0)
            {
                printf(" ksi¥¾ka 2: %3d ",client_base_pointer->id_book2);
                if(client_base_pointer->id_book3>0)
                {
                    printf(" ksi¥¾ka 3: %3d ",client_base_pointer->id_book3);
                }
            }
        }
    }
}

/*!
 *   @brief funkcja zapisuje caˆ¥ list© klient¢w do pliku clients.txt
 *
 *   @param Client *client_base_pointer wska«nik na list© klient¢w
 */
void clients_write_to_file(Client *client_base_pointer)
{
    FILE *file2;
    file2=fopen("clients.txt", "w");
    file2=fopen("clients.txt", "a");
        if(file2==NULL)
                printf(" Wyst¥piˆ bˆ¥d z plikiem clients.txt\n");
        else
        {
            if(client_base_pointer!=NULL)
            {
                write_to_file(client_base_pointer->next);
                fprintf(file2,"%d",client_base_pointer->client_id);
                fprintf(file2," %d",client_base_pointer->d_of_b_day);
                fprintf(file2," %d",client_base_pointer->m_of_b_day);
                fprintf(file2," %d",client_base_pointer->y_of_b_day);
                fprintf(file2," %I64d",client_base_pointer->pesel);
                if(client_base_pointer->id_book1>0)
                {
                    fprintf(file2," %3d",client_base_pointer->id_book1);
                    if(client_base_pointer->id_book2>0)
                    {
                        fprintf(file2," %3d",client_base_pointer->id_book2);
                        if(client_base_pointer->id_book3>0)
                        {
                            fprintf(file2," %3d\n",client_base_pointer->id_book3);
                        }
                        else
                            fprintf(file2," 0\n");
                    }
                    else
                        fprintf(file2," 0 0\n");
                }
                else
                    fprintf(file2," 0 0 0\n");
                fprintf(file2," %s",client_base_pointer->name);
                fprintf(file2,"#");
                fprintf(file2," %s",client_base_pointer->surname);
            }
        }
    fclose(file2);
}


/*!
 *   @brief funkcja czyta plik clients.txt z list¥ klient¢w i wy˜wietla j¥ na ekranie
 */
void read_file2()
{
    FILE *file2;
    char letter;

    file2=fopen("clients.txt", "r");
    while((letter=fgetc(file2))!=EOF)
    {
        printf("%c",letter);
    }
    fclose(file2);
}

/*!
 *   @brief funkcja pozwala na edycj© pojedyäczego klienta, nale¾y poda† jego id
 *
 *   @param Client *client_base_pointer wska«nik na list© klient¢w
 */
void edit_client(Client *client_base_pointer) {
    char buffer[100];
    int numbers;
    long long int pesel_buffer;
    char check[100];
    check[0]='.';

    printf("Wpisz ID klienta, kt¢rego chcesz edytowa†: ");
    scanf(" %d",&numbers);

    Client *temporary_pointer = client_base_pointer;

    while((temporary_pointer!=NULL)&&(temporary_pointer->client_id!=numbers))
        {
            temporary_pointer=temporary_pointer->next;
        }
    if(temporary_pointer!=NULL)
        {
            printf(" UWAGA edycja danych o kliencie nr ID %d:\n\n",numbers);

            printf(" Imi©: ");
            printf("\n%-10s",temporary_pointer->name);
            printf(" Czy chcesz go zmieni†? Kropka pomija podpunkt\n");
            gets(buffer);
            if(strcmp(buffer, check)!=0)
            strcpy(temporary_pointer->name, buffer);

            printf("\n Nazwisko: ");
            printf("\n%-10s",temporary_pointer->surname);
            printf(" Czy chcesz go zmieni†? Kropka pomija podpunkt\n");
            gets(buffer);
            if(strcmp(buffer, check)!=0)
            strcpy(temporary_pointer->surname, buffer);

            printf("\n Dzieä urodzenia: ");
            printf("\n%4d",temporary_pointer->d_of_b_day);
            printf(" Czy chcesz go zmieni†? Warto˜† mniejsza lub r¢wna zero pomija podpunkt\n");
            scanf(" %d",&numbers);
            gets(buffer);
            if(numbers>0)
            temporary_pointer->d_of_b_day = numbers;

            printf("\n Miesi¥c urodzenia: ");
            printf("\n%4d",temporary_pointer->m_of_b_day);
            printf(" Czy chcesz go zmieni†? Warto˜† mniejsza lub r¢wna zero pomija podpunkt\n");
            scanf(" %d",&numbers);
            gets(buffer);
            if(numbers>0)
            temporary_pointer->m_of_b_day = numbers;

            printf("\n Rok urodzenia: ");
            printf("\n%4d",temporary_pointer->y_of_b_day);
            printf(" Czy chcesz go zmieni†? Warto˜† mniejsza lub r¢wna zero pomija podpunkt\n");
            scanf(" %d",&numbers);
            gets(buffer);
            if(numbers>0)
            temporary_pointer->y_of_b_day = numbers;

            printf("\n Numer PESEL: ");
            printf("\n%11lld",temporary_pointer->pesel);
            printf(" Czy chcesz go zmieni†? Warto˜† r¢wna 0 pomija podpunkt\n");
            scanf(" %lld",&pesel_buffer);
            gets(buffer);
            if(pesel_buffer==0)
            temporary_pointer->pesel = pesel_buffer;

            printf("\n ID wypo¾yczonej ksi¥¾ki nr 1: ");
            printf("\n%4d",temporary_pointer->id_book1);
            printf(" Czy chcesz go zmieni†? Warto˜† mniejsza lub r¢wna zero pomija podpunkt\n");
            scanf(" %d",&numbers);
            gets(buffer);
            if(numbers>0)
            temporary_pointer->id_book1 = numbers;

            if(temporary_pointer->id_book1>0){
                printf("\n ID wypo¾yczonej ksi¥¾ki nr 2: ");
                printf("\n%4d",temporary_pointer->id_book2);
                printf(" Czy chcesz go zmieni†? Warto˜† mniejsza lub r¢wna zero pomija podpunkt\n");
                scanf(" %d",&numbers);
                gets(buffer);
                if(numbers>0)
                temporary_pointer->id_book2 = numbers;

                if(temporary_pointer->id_book2>0){
                    printf("\n ID wypo¾yczonej ksi¥¾ki nr 3: ");
                    printf("\n%4d",temporary_pointer->id_book3);
                    printf(" Czy chcesz go zmieni†? Warto˜† mniejsza lub r¢wna zero pomija podpunkt\n");
                    scanf(" %d",&numbers);
                    gets(buffer);
                    if(numbers>0)
                    temporary_pointer->id_book3 = numbers;
                }
            }
        }
        else
            printf("\n Nie znaleziono takiego klienta w bazie");
}


/*!
 *   @brief funkcja sortuje klient¢w na li˜cie wedˆug wskazanego przez u¾ytkownika wyboru a nast©pnie wywoˆuje wypisanie listy klient¢w na ekran
 *
 *   @param Client *client_base_pointer wska«nik na list© klient¢w
 */
void sort_client_list(Client *client_base_pointer){


int choice_one=0;
int choice_two=0;

printf(" Wybierz po jakim polu chcesz sortowa† klient¢w? Oto opcje:\n");
printf(" 1. Imi©\n");
printf(" 2. Nazwisko\n");
printf(" 3. Dzieä urodzenia\n");
printf(" 4. Miesi¥c urodzenia");
printf(" 5. Rok urodzenia\n");
printf(" 6. PESEL\n");
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

Client *wsk=client_base_pointer;
int i;
int j;

int client_id;
char name[100];
char surname[100];
int d_of_b_day;
int m_of_b_day;
int y_of_b_day;
long long int pesel;

switch(choice_one) {
    case 1:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po imieniu malej¥co, wykonuj©...");
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(strcmp(wsk->name, wsk->next->name)>0) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po imieniu malej¥co, wykonuj©...");
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(strcmp(wsk->name, wsk->next->name)<0) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            break;
    case 2:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po nazwisku malej¥co, wykonuj©...");
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(strcmp(wsk->surname, wsk->next->surname)>0) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po nazwisku malej¥co, wykonuj©...");
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(strcmp(wsk->name, wsk->next->name)<0) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            break;
    case 3:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po dniu urodzenia malej¥co, wykonuj©...");
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(wsk->d_of_b_day>wsk->next->d_of_b_day) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po dniu urodzenia malej¥co, wykonuj©...");
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(wsk->d_of_b_day<wsk->next->d_of_b_day) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            break;
    case 4:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po miesi¥cu urodzenia malej¥co, wykonuj©...");
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(wsk->m_of_b_day>wsk->next->m_of_b_day) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po miesi¥cu urodzenia malej¥co, wykonuj©...");
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(wsk->m_of_b_day<wsk->next->m_of_b_day) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            break;
    case 5:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po roku urodzenia malej¥co, wykonuj©...");
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(wsk->y_of_b_day>wsk->next->y_of_b_day) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po roku urodzenia malej¥co, wykonuj©...");
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(wsk->y_of_b_day<wsk->next->y_of_b_day) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            break;
    case 6:
            if(choice_two==1) {
                printf("\n Wybrano sortowanie po numerze PESEL malej¥co, wykonuj©...");
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(wsk->pesel>wsk->next->pesel) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po numerze PESEL malej¥co, wykonuj©...");
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(wsk->pesel<wsk->next->pesel) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
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
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(wsk->client_id>wsk->next->client_id) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            if(choice_two==2) {
                printf("\n Wybrano sortowanie po numerze ID malej¥co, wykonuj©...");
                for(i=0;i<count_client_list;++i) {
                    wsk=client_base_pointer;
                    for(j=0;j<count_client_list-1;++j) {
                        if(wsk->client_id<wsk->next->client_id) {
                            client_id=wsk->client_id;
                            strcpy(name, wsk->name);
                            strcpy(surname, wsk->surname);
                            d_of_b_day=wsk->d_of_b_day;
                            m_of_b_day=wsk->m_of_b_day;
                            y_of_b_day=wsk->y_of_b_day;
                            pesel=wsk->pesel;

                            wsk->client_id=wsk->next->client_id;
                            strcpy(wsk->name, wsk->next->name);
                            strcpy(wsk->surname, wsk->next->surname);
                            wsk->d_of_b_day=wsk->next->d_of_b_day;
                            wsk->m_of_b_day=wsk->next->m_of_b_day;
                            wsk->y_of_b_day=wsk->next->y_of_b_day;
                            wsk->pesel=wsk->next->pesel;

                            wsk->next->client_id=client_id;
                            strcpy(wsk->next->name, name);
                            strcpy(wsk->next->surname, surname);
                            wsk->next->d_of_b_day=d_of_b_day;
                            wsk->next->m_of_b_day=m_of_b_day;
                            wsk->next->y_of_b_day=y_of_b_day;
                            wsk->next->pesel=pesel;
                        }
                        wsk = wsk->next;
                    }
                }
                printf("\n Sortowanie wykonano pomy˜lnie!\n");
            }
            break;
    }
    cout_client_base(client_base_pointer);
}


