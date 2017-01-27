#ifndef BORROW_H_INCLUDED
#define BORROW_H_INCLUDED

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define Borrow struct borrow_base


/*!
 *   @brief Struktura zawieraj¥ca pola listy wypo¾yczeä, z kt¢rej bedzie tworzona baza wypo¾yczeä
 *
 *   @param Borrow::int borrow_id id wypo¾yczenia
 *   @param Borrow::int borrow_client_id; id klienta wypo¾yczaj¥cego
 *   @param Borrow::int book_id; id wypo¾yczanej ksia¾ki
 *   @param Borrow::int d_of_borrow; dzieä wypo¾yczenia
 *   @param Borrow::int m_of_borrow; miesi¥c wypo¾yczenia
 *   @param Borrow::int y_of_borrow; rok wypo¾yczenia
 *   @param Borrow::int d_of_give_back; dzieä terminu oddania
 *   @param Borrow::int m_of_give_back; miesi¥c terminu oddania
 *   @param Borrow::int y_of_give_back; rok terminu oddania
 *   @param Borrow::int amount_to_borrow; ilo˜† ksi¥¾ek jakie chce wypo¾yczy† klient
 *   @param Borrow::char gave_back[6]; zmienna przechowuj¥ca warto˜† czy ksi¥¾ki zostaˆy oddane
 */
Borrow {
int borrow_id;
int borrow_client_id;
int book_id;
int d_of_borrow;
int m_of_borrow;
int y_of_borrow;

int d_of_give_back;
int m_of_give_back;
int y_of_give_back;

int amount_to_borrow;

char gave_back[6];
Borrow *next;
};


void new_borrow_fill(Borrow *(*new_borrow_node), int client_id, int book_id, int amount_to_borrow);

void add_new_borrow(Borrow **borrow_base_pointer, int borrow_id, int client_id, int book_id, int amount_to_borrow);

void delete_borrow_base(Borrow **borrow_base_base_pointer);

void give_back_book(Borrow *borrow_base_pointer);

void cout_borrow_base(Borrow *borrow_base_pointer);

void write_borrow_to_file(Borrow *borrow_base_pointer);

#endif // BORROW_H_INCLUDED
