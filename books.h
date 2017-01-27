#ifndef BOOKS_H_INCLUDED
#define BOOKS_H_INCLUDED

#define Library struct book_base


/*!
 *   @brief Struktura zawieraj¹ca pola listy ksi¹¿ek, z której bedzie tworzona baza ksi¹¿ek
 *
 *   @param Library::id id ksi¹¿ki
 *   @param Library::char title[100] tytu³ ksia¿ki
 *   @param Library::int year rok wydania ksia¿ki
 *   @param Library::char author[100] autor ksi¹¿ki
 *   @param Library::char genre[100] gatunek ksi¹¿ki
 *   @param Library::int copies iloœæ kopii dostêpnych
 *   @param Library::int borrowed iloœæ wypo¿yczonych kopii
 */
Library {
int id; /// id of book, not unsigned to check if it's not below zero
char title[100]; /// book title
int year; /// book can be written before new age so it can't be unsigned
char author[100];
char genre[100]; /// in PL:gatunek
int copies; /// how many copies of book are available
int borrowed; /// how many copies are borrowed by people
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
