#ifndef BOOKS_H_INCLUDED
#define BOOKS_H_INCLUDED

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define Library struct book_base


/*!
 *   @brief Struktura zawierająca pola listy książek, z której bedzie tworzona baza książek
 *
 *   @param Library::id id książki
 *   @param Library::char title[100] tytuł ksiażki
 *   @param Library::int year rok wydania ksiażki
 *   @param Library::char author[100] autor książki
 *   @param Library::char genre[100] gatunek książki
 *   @param Library::int copies ilość kopii dostępnych
 *   @param Library::int borrowed ilość wypożyczonych kopii
 */
Library {
int id;
char title[100];
int year;
char author[100];
char genre[100];
int copies;
int borrowed;
Library *next;
};

int count_list;

void new_book_fill(Library *(*new_node));

void add_new_book(Library **base_pointer, int id);

void delete_base(Library **base_pointer);

void search_for_book(Library *base_pointer);

void delete_book(Library **base_pointer);

void cout_base(Library *base_pointer);

void cout_base(Library *base_pointer);

void read_file1();

void edit_book(Library *base_pointer);

void sort_book_list(Library *base_pointer);


#endif // BOOKS_H_INCLUDED
