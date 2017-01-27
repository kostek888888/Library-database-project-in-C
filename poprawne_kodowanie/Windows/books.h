#ifndef BOOKS_H_INCLUDED
#define BOOKS_H_INCLUDED

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define Library struct book_base


/*!
 *   @brief Struktura zawieraj�ca pola listy ksi��ek, z kt�rej bedzie tworzona baza ksi��ek
 *
 *   @param Library::id id ksi��ki
 *   @param Library::char title[100] tytu� ksia�ki
 *   @param Library::int year rok wydania ksia�ki
 *   @param Library::char author[100] autor ksi��ki
 *   @param Library::char genre[100] gatunek ksi��ki
 *   @param Library::int copies ilo�� kopii dost�pnych
 *   @param Library::int borrowed ilo�� wypo�yczonych kopii
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
