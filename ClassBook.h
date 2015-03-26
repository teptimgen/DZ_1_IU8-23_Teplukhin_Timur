#if !defined( __ClassBook_H ) 
#define __ClassBook_H

class cl_Book
{
protected:
	/* Поля */
	int num; // Уникальный номер книги
	__int64   ISBN; // Номер книжного издания
	char* name; // Название книги
	int   year; // Год издания
	int   numberOfPages; // Количество страниц
	list <char*> *authors; // Список авторов
	bool checkOut; // true - книга выдана на руки клиенту

public:
	/* Конструкторы */
	cl_Book(); // Создание пустой книги
	cl_Book(cl_Book* B); // Создание книги копированием
	cl_Book(__int64 _ISBN,  int Year, int NumberOfPages, const char* Name, const char* Author = ""); // Создание книги с заполненными параметрами

	/* Деструктор */
	~cl_Book();

	/* Методы */
	char* fn_return_authors(); // Возврат ссылки на строку, содержащую всех авторов
	void fn_add_author(const char* Author); // Добавление нового автора к списку авторов
	void fn_clear_authors(); // Удаление списка авторов
	void fn_set_num(const int Num); // Присвоение значения номеру книги
	int fn_get_num(); // Возврат значения номера книги
	bool fn_set_check_out(bool f); // Присвоение значения свойству "Книга выдана"
	int fn_get_check_out(); // Возврат значения свойства "Книга выдана"
	void fn_set_all_params(__int64 _ISBN,  int _Year, int _NumberOfPages, const char* _Name); // Установка всех параметров книги

	friend ostream& operator<<(ostream& os, cl_Book& B); // Перегруженный оператор <<. Вывод данных о книге в поток ostream 
	friend bool operator==(const cl_Book& b1, const cl_Book& b2); // Перегруженный оператор ==.
}; 
#endif
