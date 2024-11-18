// Автор: Калашников А.Н.
#include <iostream> // заголовочный файл с классами, функциями
//и переменными для организации ввода-вывода
/* Заголовочный файл - файл, содержимое которого автоматически добавляется препроцессором
в исходный текст в том месте, где располагается директива #include */
#include "triangle_area.h" // заголовочный файл с функциями модуля
#include <cassert> //Заголовочный файл cassert определяет функцию assert,
//которая обычно используется в качестве стандартного инструмента отладки.
using namespace std; // Позволяет использовать все имена из стандартного
//пространства имен (std) без необходимости добавления префикса std::
/*Пространство имен — это декларативная область, в рамках которой
определяются различные идентификаторы (имена типов, функций, переменных, и т. д.).
Пространства имен используются для организации кода в виде логических групп
и с целью избежания конфликтов имен, которые могут возникнуть, особенно
в таких случаях, когда база кода включает несколько библиотек.*/
/// основная функция программы
int main(){
	// проверяем результат функции calculate для стороны 5
	assert(abs(calculate(5) - 10.8253) < 0.01);
	// проверяем результат функции calculate для стороны 0
	assert(calculate(0) == 0);
	// проверяем результат функции calculate для стороны 5000
	assert(abs(calculate(5000) - 10825317.547) < 0.01);
	// устанавливаем языковой стандарт для корректного отображения русского языка в консоли
	setlocale(LC_ALL, "ru-RU.UTF-8"); 
	double side = 0; //инициализируем side
	cout << "Введите длину стороны равностороннего треугольника";
	cin >> side;
	cout << "Площадь равностороннего треугольника равна " << calculate(side);
	return 0; 
}