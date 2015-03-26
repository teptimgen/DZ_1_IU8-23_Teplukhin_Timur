#if !defined( __ClassBookList_H ) 
#define __ClassBookList_H

#include "ClassBook.h"

class cl_BookList : protected list <cl_Book> // Класс BookList наследуется от класса std::list
{
protected:
	/* Поля */
	char* name; // Название библиотеки
	char* type; // Тип библиотеки
	int countCheckedOut; // Количество выданных читателю книг
	int maxNum; // Максимальный уникальный номер книги, использующийся в библиотеке

public:
	/* Конструкторы */
	cl_BookList(); // Пустой конструктор
	cl_BookList(char* Name, char* Type); // Конструктор с параметрами

	/* Деструктор */
	~cl_BookList();

	/* Методы */
	void fn_add_book(cl_Book& B); // Добавить книгу в библиотеку
	void fn_del_book(int Num); // Удалить книгу из библиотеки
	cl_Book* fn_find_book_with_num(int Num); // Поиск книги по номеру
	void fn_change_check_out(int Num, bool f); // Выдача книги читателю по номеру

	friend ostream& operator<<(ostream& os, cl_BookList& BL); // Перегруженный оператор <<. Вывод данных обо всех книгах в поток ostream
	friend cl_BookList& operator+=(cl_BookList& BL, cl_Book& B); // Перегруженный оператор +. Добавляет книгу в библиотеку
};
#endif 
