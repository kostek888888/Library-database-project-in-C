#ifndef CLIENTS_H_INCLUDED
#define CLIENTS_H_INCLUDED

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define Client struct client_base

/*!
 *   @brief Struktura zawierająca pola listy klientów, z której bedzie tworzona baza klientów
 *
 *   @param Client::client_id id klienta
 *   @param Client::name[100] imię klienta
 *   @param Client::char surname[100] nazwisko klienta
 *   @param Client::int d_of_b_day dzień urodzenia klienta
 *   @param Client::int m_of_b_day miesiąc urodzenia klienta
 *   @param Client::int y_of_b_day rok urodzenia klienta
 *   @param Client::long long int pesel pesel klienta
 *   @param Client::int id_book1 id pierwszej wypożyczonej książki
 *   @param Client::int id_book2 id drugiej wypożyczonej książki
 *   @param Client::id_book3 id trzeciej wypożyczonej książki
 */
Client {
int client_id;
char name[100];
char surname[100];
int d_of_b_day;
int m_of_b_day;
int y_of_b_day;
long long int pesel;
int id_book1;
int id_book2;
int id_book3;
Client *next;
};

void fill_client(Client *(*new_client_node));

void add_new_client(Client **client_base_pointer, int client_id);

void delete_client_base(Client **client_base_pointer);

void seek_for_client(Client *clients_base_pointer);

void delete_client(Client **client_base_pointer);

void cout_client_base(Client *client_base_pointer);

void clients_write_to_file(Client *client_base_pointer);

void read_file2();

void edit_client(Client *client_base_pointer);

void sort_client_list(Client *client_base_pointer);



#endif // CLIENTS_H_INCLUDED
