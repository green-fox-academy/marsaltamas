/*
 * Create a structure representing the data of a book:
 *    * Title
 *    * Author
 *    * Year of publication
 *
 * Create functions for:
 *    * Changing or setting the Title
 *    * Creating a new book.
 *    * Changing or setting the Author
 *    * Changing or setting the Year of publication
 *    * Getting each of these separately by a single function each.
 *
 * IMPORTANT: The first parameter of each function should be a "Book", a variable of the type of this structure.
 *
 * Create a main where You demonstrate that each of these works and print out the necessary info.
 * IMPORTANT: You should only print from the main function. All other functions should return the info needed.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Book {
    char title[30];
    char author[50];
    int publication;
} t_book;

// takes a book and prints its members
void book_printer(t_book book)
{
    printf("title: %s\n", book.title);
    printf("author: %s\n", book.author);
    printf("publication year: %d\n", book.publication);
    printf("-----------------------\n");
}

// takes character arrays and an int to upload it to corresponding book members
// returns a book with the passed in parameters
t_book create_new_book(char title[], char author[], int publication)
{
    t_book new_book;

    strcpy(new_book.title, title);
    strcpy(new_book.author, author);
    new_book.publication = publication;

    return new_book;
}

// sets, resets the title of the passed in book
void title_set(t_book *book, char new_title[])
{
    strcpy((*book).title, new_title);
}

// sets, resets the author of the passed in book
void author_set(t_book *book, char new_author[])
{
    strcpy(book->author, new_author);
}

// sets, resets the publication year of the passed in book
void publication_set(t_book *book, int new_publ_year)
{
    (*book).publication = new_publ_year;
}
int main()
{

    t_book c_programming = create_new_book("c Programming for dummies", "c. richie", 1991);
    book_printer(c_programming);

    title_set(&c_programming, "c programming at green fox");
    book_printer(c_programming);

    author_set(&c_programming, "Dani, Zsolti, Levi, Sami, Bence, Zoli");
    book_printer(c_programming);

    publication_set(&c_programming, 2017);
    book_printer(c_programming);

    return 0;
}
