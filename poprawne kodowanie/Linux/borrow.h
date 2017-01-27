#ifndef BORROW_H_INCLUDED
#define BORROW_H_INCLUDED

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define Borrow struct borrow_base


/*!
 *   @brief Struktura zawierająca pola listy wypożyczeń, z której bedzie tworzona baza wypożyczeń
 *
 *   @param Borrow::int borrow_id id wypożyczenia
 *   @param Borrow::int borrow_client_id; id klienta wypożyczającego
 *   @param Borrow::int book_id; id wypożyczanej ksiażki
 *   @param Borrow::int d_of_borrow; dzień wypożyczenia
 *   @param Borrow::int m_of_borrow; miesiąc wypożyczenia
 *   @param Borrow::int y_of_borrow; rok wypożyczenia
 *   @param Borrow::int d_of_give_back; dzień terminu oddania
 *   @param Borrow::int m_of_give_back; miesiąc terminu oddania
 *   @param Borrow::int y_of_give_back; rok terminu oddania
 *   @param Borrow::int amount_to_borrow; ilość książek jakie chce wypożyczyć klient
 *   @param Borrow::char gave_back[6]; zmienna przechowująca wartość czy książki zostały oddane
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
