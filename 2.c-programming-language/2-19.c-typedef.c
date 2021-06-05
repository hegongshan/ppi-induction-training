#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct Book {
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
} Book;

int main()
{
	printf("--------1.typedef关键字--------\n");
	// typedef只能为数据类型定义别名
	Book book;
	strcpy(book.title, "C程序设计语言");
	strcpy(book.author, "K&R");
	strcpy(book.subject, "编程语言");
	book.book_id = 12345;

	printf("书籍名称：%s\n", book.title);
	printf("书籍作者：%s\n", book.author);
	printf("书籍类别：%s\n", book.subject);
	printf("书籍ID：%d\n", book.book_id);


	printf("--------2.#define指令--------\n");
	// 除了为数据类型定义别名外，#define可以为数值定义别名
	printf("TURE的值为：%d\n", TRUE);
	printf("FALSE的值为：%d\n", FALSE);
	return 0;
}