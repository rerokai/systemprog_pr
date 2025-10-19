#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[50];
    char author[50];
    int year;
} Book;

typedef struct DynamicBook {
    Book* book_ptr;
    struct DynamicBook* next;
} DynamicBook;

int main() {
    DynamicBook* db1 = (DynamicBook*)malloc(sizeof(DynamicBook));
    DynamicBook* db2 = (DynamicBook*)malloc(sizeof(DynamicBook));

    Book* b1 = (Book*)malloc(sizeof(Book));
    Book* b2 = (Book*)malloc(sizeof(Book));

    *b1 = (Book){"Код да Винчи", "Дэн Браун", 2003};
    *b2 = (Book){"Мартин Иден", "Джек Лондон", 1909};

    db1->book_ptr = b1;
    db1->next = db2;

    db2->book_ptr = b2;
    db2->next = NULL;

    printf("Книга 1: %s, %s, %d\n", db1->book_ptr->title, db1->book_ptr->author, db1->book_ptr->year);
    printf("Книга 2: %s, %s, %d\n", db1->next->book_ptr->title, db1->next->book_ptr->author, db1->next->book_ptr->year);

    free(b1);
    free(b2);
    free(db1);
    free(db2);

    return 0;
}