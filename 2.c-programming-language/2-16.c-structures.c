#include <stdio.h>
#include <string.h>

struct Books
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
} book = {"C语言", "RUNOOB", "编程语言", 123456};

void print_book(struct Books book);
void print_book_by_pointer(struct Books * book);

int main()
{
	printf("------1.结构体初体验------\n");
	printf("title: %s\n", book.title);
	printf("author: %s\n", book.author);
	printf("subject: %s\n", book.subject);
	printf("book_id: %d\n", book.book_id);


	printf("------2.访问结构体成员------\n");
	struct Books book1;
	strcpy(book1.title, "The C Programming Language");
	strcpy(book1.author, "K&R");
	strcpy(book1.subject, "C Programming Tutorial");
	book1.book_id = 1;
	printf("Book 1 title: \t%s\n", book1.title);
	printf("Book 1 author: \t%s\n", book1.author);
	printf("Book 1 subject: \t%s\n", book1.subject);
	printf("Book 1 book_id: \t%d\n", book1.book_id);

	struct Books book2;
	strcpy(book2.title, "The Art of Computer Programming");
	strcpy(book2.author, "Donald Knuth");
	strcpy(book2.subject, "Programming");
	book2.book_id = 2;
	printf("Book 2 title: \t%s\n", book2.title);
	printf("Book 2 author: \t%s\n", book2.author);
	printf("Book 2 subject: \t%s\n", book2.subject);
	printf("Book 2 book_id: \t%d\n", book2.book_id);


	printf("------3.结构体作为函数参数------\n");
	print_book(book1);
	print_book(book2);


	printf("------4.指向结构体的指针------\n");
	print_book_by_pointer(&book1);
	print_book_by_pointer(&book2);
}


void print_book(struct Books book)
{
	printf("Book title: \t%s\n", book.title);
	printf("Book author: \t%s\n", book.author);
	printf("Book subject: \t%s\n", book.subject);
	printf("Book book_id: \t%d\n", book.book_id);
}

void print_book_by_pointer(struct Books * book)
{
	printf("Book title: \t%s\n", book->title);
	printf("Book author: \t%s\n", book->author);
	printf("Book subject: \t%s\n", book->subject);
	printf("Book book_id: \t%d\n", book->book_id);
}