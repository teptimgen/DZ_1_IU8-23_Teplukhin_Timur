#include "Headers.h"
#include "ClassBook.h" 

/* Конструкторы */
cl_Book::cl_Book() // Создание пустой книги
{
	checkOut = false;
	ISBN = num = numberOfPages = year = 0;
	authors = new list <char *>;
	name = new char[1]; // Создание строки name длиной в 1 символ
	strcpy(name, ""); // Запись значения NULL (конец строки) в строку name
}

cl_Book::cl_Book(cl_Book* B) // Создание книги копированием
{
	num = B->num; // Уникальный номер книги
	ISBN = B->ISBN; // Номер книжного издания
	year = B->year; // Год издания
	numberOfPages = B->numberOfPages; // Количество страниц
	checkOut = B->checkOut; // true - книга выдана на руки клиенту

	if (B->name != NULL) // Название книги
	{
		name = new char[strlen(B->name)+1]; // Выделение памяти под название книги (длина строки name + 1 элемент для NULL)
		strcpy(name, B->name); // Копирование строки name в выделенную область памяти
	}                    
	
	if (B->authors != NULL) // Список авторов
	{
		authors = new list <char*>; // Создание списка имен авторов
		list<char*>::const_iterator it = B->authors->begin(); // Запись в итератор значения первого элемента списка
		for (; it != B->authors->end(); ++it) fn_add_author(*it); // Добавление нового автора к списку авторов    
	}
}

cl_Book::cl_Book(__int64 _ISBN, int Year, int NumberOfPages, const char* Name, const char* Author) // Cоздание книги с заполненными параметрами
{
	name = NULL;
	authors = NULL;
	checkOut = false;

	fn_set_all_params(_ISBN, Year, NumberOfPages, Name); // Заполнение параметров при помощи метода класса

	authors = new list <char *>; // Создание списка имен авторов
	fn_add_author(Author); // Добавление нового автора в список при помощи метода класса
}

/* Деструктор */
cl_Book::~cl_Book()
{
	delete [] name; // Удаление памяти, выделенной под наименование книги
	fn_clear_authors(); // Удаление авторов из списка при помощи метода класса
	delete authors; // Удаление списка
}

/* Методы */
char* cl_Book::fn_return_authors() // Возврат ссылки на строку, содержащую всех авторов 
{
	char* tmp = new char[250]; // Массив с именами всех авторов
	*tmp = NULL; // Запись значения NULL в первый символ выделенной строки

	list<char*>::const_iterator it = authors->begin(); // Записываем в итератор значение первого элемента списка
	for (; it != authors->end(); ++it) // Пока не достигли указателя на последнего автора удаляем память, ...
	{
		strncat(tmp, (char *) *it, strlen(*it)); //... копируем в tmp авторов из списка
		strncat(tmp, ", ", 2);
	}
	return tmp;
}

void cl_Book::fn_add_author(const char* Author) // Добавление нового автора к списку авторов
{
	char* tmp = new char[strlen(Author)+1]; // Выделение памяти под имя автора (длина строки Author + 1 элемент для NULL)
	strcpy(tmp, Author); // Копирование строки Author в выделенную область памяти
	authors->emplace_back(tmp); // Добавление нового автора в список
}

void cl_Book::fn_clear_authors() // Удаление списка авторов 
{
	list<char*>::const_iterator it = authors->begin(); // Записываем в итератор значение первого элемента списка
	for (; it != authors->end(); ++it) delete[]* it; // Пока не достигли указателя на последнего автора, удаляем память, зарезервированную под имя   
}

void cl_Book::fn_set_num(const int Num) { num = Num; } // Присвоение значения номеру книги

int cl_Book::fn_get_num() { return num; } // Возврат значения номера книги

bool cl_Book::fn_set_check_out(bool f) // Присвоение значения свойству "Книга выдана"
{
	if ( checkOut == f ) return false; // "Книга в библиотеке"
	else
	{
		checkOut = f; // Изменение значения свойства "Книга выдана"
		return true; // "Книга у читателя"
	}
}

int cl_Book::fn_get_check_out() { return checkOut; } // Возврат значения свойства "Книга выдана"

void cl_Book::fn_set_all_params(__int64 _ISBN,  int _Year, int _NumberOfPages, const char* _Name) // Заполнение полей
{
	num  = 0;
	ISBN = _ISBN;
	year = _Year;
	numberOfPages = _NumberOfPages; 

	if (name != NULL) delete [] name; // Удаление памяти, выделенной под имя ранее
	name = new char[strlen(_Name)+1]; // Выделение памяти под название книги (длина строки _Name + 1 элемент для NULL)
	strcpy(name, _Name); // Копирование строки _Name в выделенную область памяти
}

ostream& operator<<(ostream& os, cl_Book& B) // Перегруженный оператор <<. Вывод данных в поток ostream
{
	os << "Num " << B.num << endl; // Вывод уникального номера книги
	os << "ISBN " << B.ISBN << endl; // Вывод ISBN
	os << "Number of pages " << B.numberOfPages << endl; // Вывод количества страниц
	os << B.year << " yy." << endl; // Вывод года издания книги
	os <<  B.fn_return_authors() << "  " << B.name << endl; // Вывод списка авторов книги

	return os;
}

bool operator==(const cl_Book& b1, const cl_Book& b2) { return b1.num == b2.num; } // Перегруженный оператор ==.
