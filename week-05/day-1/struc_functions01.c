/*
 * Take exercise structures_functions_00.
 * Create an additional structure: Author. This should store Given name and Surname of the author.
 * Rewrite the previous exercise to work with this new structure.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// additional struct to be used as a nested struct
typedef struct Author {
    char firstname[20];
    char lastname[20];
} t_author;

typedef struct Book {
    char title[30];
    t_author author;
    int publication;
} t_book;

void book_printer(t_book book)
{
    printf("title: %s\n", book.title);
    printf("author first name: %s\n", book.author.firstname);
    printf("author last name: %s\n", book.author.lastname);
    printf("publication year: %d\n", book.publication);
    printf("-----------------------\n");
}

t_book create_new_book(char title[], char firstnname[], char lastname[], int publication)
{
    t_book new_book;

    strcpy(new_book.title, title);
    strcpy(new_book.author.firstname, firstnname);
    strcpy(new_book.author.lastname, lastname);
    new_book.publication = publication;

    return new_book;
}

void title_set(t_book *book, char new_title[])
{
    strcpy((*book).title, new_title);
}

void author_set(t_book *book, char new_firstname[], char new_lastname[])
{
    strcpy(book->author.firstname, new_firstname);
    strcpy(book->author.lastname, new_lastname);
}

void publication_set(t_book *book, int new_publ_year)
{
    (*book).publication = new_publ_year;
}
int main()
{

    t_book c_programming = create_new_book("c Programming for dummies", "carnige", "richie", 1991);
    book_printer(c_programming);

    title_set(&c_programming, "c adventures");
    book_printer(c_programming);

    author_set(&c_programming, "t", "marsal");
    book_printer(c_programming);

    publication_set(&c_programming, 2017);
    book_printer(c_programming);

    return 0;
}
