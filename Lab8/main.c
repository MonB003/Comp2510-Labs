#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define TEN 10

struct info {
    int an;
    char authorName[MAX_LENGTH];
    char bookTitle[MAX_LENGTH];
};

void display(struct info *book);


// Add books to an array of struct info books
void add_books(struct info *book) {
    book[0].an = 0;
    strcpy(book[0].authorName, "authorA");
    strcpy(book[0].bookTitle, "titleA");

    book[1].an = 1;
    strcpy(book[1].authorName, "authorB");
    strcpy(book[1].bookTitle, "titleB");

    book[2].an = 2;
    strcpy(book[2].authorName, "authorC");
    strcpy(book[2].bookTitle, "titleC");

    book[3].an = 3;
    strcpy(book[3].authorName, "authorD");
    strcpy(book[3].bookTitle, "titleD");

    book[4].an = 4;
    strcpy(book[4].authorName, "authorE");
    strcpy(book[4].bookTitle, "titleE");

    book[5].an = 5;
    strcpy(book[5].authorName, "authorF");
    strcpy(book[5].bookTitle, "titleF");

    book[6].an = 6;
    strcpy(book[6].authorName, "authorG");
    strcpy(book[6].bookTitle, "titleG");

    book[7].an = 7;
    strcpy(book[7].authorName, "authorH");
    strcpy(book[7].bookTitle, "titleH");

    book[8].an = 8;
    strcpy(book[8].authorName, "authorH");
    strcpy(book[8].bookTitle, "titleI");

    book[9].an = 9;
    strcpy(book[9].authorName, "authorH");
    strcpy(book[9].bookTitle, "titleJ");
}


// Search for one of more books by author
void book_by_author(struct info *book, char * author) {
    int found = 0;

    for (int index = 0; index < TEN; index++) {
        if (strcmp(book[index].authorName, author) == 0) {
            found = 1;
            printf("Book with author '%s' found:\n", author);
            display(&book[index]);
        }
    }

    // If book is not found
    if (found == 0) {
        printf("Book with author '%s' was not found.\n", author);
    }
}


// Search for a book by title
void book_by_title(struct info *book, char * title) {
    int found = 0;

    for (int index = 0; index < TEN; index++) {
        if (strcmp(book[index].bookTitle, title) == 0) {
            found = 1;
            printf("Book with title '%s' found:\n", title);
            display(&book[index]);
        }
    }

    // If book is not found
    if (found == 0) {
        printf("Book with title '%s' was not found.\n", title);
    }
}


// Search for a book by an
void book_by_an(struct info *book, int an) {
    int found = 0;

    for (int index = 0; index < TEN; index++) {
        if (book[index].an == an) {
            found = 1;
            printf("Book with an '%d' found:\n", an);
            display(&book[index]);
        }
    }

    // If book is not found
    if (found == 0) {
        printf("Book with an '%d' was not found.\n", an);
    }
}


// Displays a book
void display(struct info *book) {
    printf("AN: %d\n", book->an);
    printf("Author name: %s\n", book->authorName);
    printf("Book title: %s\n\n", book->bookTitle);
}


int main() {
    struct info *books = (struct info *) malloc(TEN * sizeof(struct info));

    if (books == NULL) {
        printf("Memory allocation failed.\n");

    } else {
        add_books(books);

        // Test cases where books are found
        book_by_author(books, "authorH");
        book_by_title(books, "titleG");
        book_by_an(books, 3);

        // Test cases where books are not found
        book_by_author(books, "auth");
        book_by_title(books, "noTitle");
        book_by_an(books, 123);
    }

    free(books);

    return 0;
}
