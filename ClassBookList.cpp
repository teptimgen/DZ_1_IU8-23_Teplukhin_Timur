#include "Headers.h"
#include "ClassBookList.h" 

/* Конструкторы */
cl_BookList::cl_BookList() // Пустой конструктор
{
	countCheckedOut = maxNum = 0;
	name = new char[1]; // Выделение для указателя name строки длиной в 1 символ
	type = new char[1]; // Выделение для указателя type строки длиной в 1 символ
	*name = NULL; // В name записан NULL (конец строки)
	*type = NULL; // В type записан NULL (конец строки)
}; 

cl_BookList::cl_BookList(char* Name, char* Type) // Конструктор с параметрами
{
	countCheckedOut = maxNum = 0;
	name = new char[strlen(Name)+1]; // Выделение памяти под название библиотеки (длина строки name + 1 элемент для NULL)
	type = new char[strlen(Type)+1]; // Выделение памяти под тип библиотеки (длина строки type + 1 элемент для NULL)
	strcpy(name, Name); // Копирование строки name в выделенную область памяти
	strcpy(type, Type); // Копирование строки type в выделенную область памяти
}; 

/* Деструктор */
cl_BookList::~cl_BookList()
{
	delete[] name;
	delete[] type;
}

/* Методы */
void cl_BookList::fn_add_book(cl_Book& B) // Добавление книги в список
{
	cl_Book* Bnew = new cl_Book(B);
	Bnew->fn_set_num(++maxNum);
	this->emplace_back(Bnew);
}

void cl_BookList::fn_del_book(int Num) // Удаление книги из библиотеки
{
	cl_Book* tmp;
	tmp = fn_find_book_with_num(Num);
	if(tmp != NULL) // Если найдена книга с необходимым номером, ...
	{
		list<cl_Book>::iterator it = this->begin();  // ..., то записываем в итератор значение первого элемента списка до тех пор, ...
		for (; it != this->end(); ++it)                      // ..., пока не достигли указателя на последнего автора
			if ( ((&(it)._Ptr->_Myval)->fn_get_num() )== Num)
			{   
				list<cl_Book>::iterator _it = it++;
				this->erase( _it ); // Удаление книгу
			}
	}
	else cout << "Книга с заданным номером не найдена" << endl;
}

cl_Book* cl_BookList::fn_find_book_with_num(int Num) // Поиск книги по номеру
{
	list<cl_Book>::const_iterator it = this->begin(); // Запись в итератор значения первого элемента списка
	for (; it != this->end(); ++it) // Пока не достигли указателя на последнего автора, выполняем поиск
		if (((&(it)._Ptr->_Myval)->fn_get_num()) == Num) return &(it)._Ptr->_Myval; 
	return NULL;
}

void cl_BookList::fn_change_check_out(int Num, bool f) // Выдача книги читателю по номеру
{
	cl_Book* tmp;
	tmp = fn_find_book_with_num(Num);
	if(tmp != NULL) // Если найдена книга с необходимым номером, ...
	{
		if(tmp->fn_set_check_out(f)) // ..., то пробуем: сдать - f=false, выдать - f=true
		{
			countCheckedOut += (f) ? +1 : -1; // В зависимости от флага уменьшаем/увеличиваем количество сданных книг
			cout << ((f) ? "Книга выдана" : "Книга сдана") << endl;
		}
		else cout << "Невозможно "<< ((f) ? "выдать": "сдать") <<" книгу" << endl;
	}
	else cout << "Книга не найдена" << endl;
}

ostream& operator<<(ostream& os, cl_BookList& BL) // Перегруженный оператор <<. Вывод данных обо всех книгах в поток ostream
{
	os << "Наименование библиотеки: " << BL.name << endl; // Вывод наименования библиотеки
	os << "Тип библиотеки: " << BL.type << endl; // Вывод типа библиотеки
	os << "Количество выданных читателю книг: " << BL.countCheckedOut << endl;  // Вывод количества выданных читателю книг

	list<cl_Book>::const_iterator it = BL.begin(); // Запись в итератор значение первого элемента списка
	for (; it != BL.end(); ++it) // Пока не достигли указателя на последнего автора, выводим список книг 
	{   
		cl_Book* tmp = &(it)._Ptr->_Myval;
		os  << endl << (cl_Book&) *tmp << endl;
	}
	return os;
}

cl_BookList& operator+=(cl_BookList& BL, cl_Book& B) // Перегруженный оператор +=. Добавление книги в библиотеку
{
	BL.fn_add_book(B); // Добавление книги в библиотеку при попощи метода класса
	return BL; // Возврат адреса библиотеки
}
