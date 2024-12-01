// Автор: Калашников А.Н.
#include <iostream>
#include "tel_sub.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "ru-RU.UTF-8");
    // Тестирование методов класса
    Test_TelSub();

    // Статическое создание объекта с помощью конструктора по умолчанию
    TelSub sub;
    cout << sub.to_string(); // Вывод полей объекта
    // Статическое создание объекта с помощью конструктора c параметрами
    TelSub SubP("+8(800)924-32-71", "000002", "Medium", "John Light", 120);
    cout << SubP.to_string(); // Вывод полей объекта

    // Статический массив из объектов
    TelSub subs[10];
    subs[0].set_tariff("Based");
    subs[0].set_name("Jack Hopkins");
    subs[0].set_pn("+8(800)555-35-35");
    subs[0].set_an("000003");
    subs[0].replenish_balance(400);
    cout << subs[0].to_string(); // Вывод всех полей объекта на экран

    // Запись состояния объекта в файл, загрузка состояния объекта из файла
    string fname = "text.txt";
    subs[0].save_sub(fname);
    subs[1].load_sub(fname);
    cout << subs[1].to_string();


    // Динамическое создание объекта
    TelSub* SubDin = new TelSub;
    (*SubDin).set_an("000004"); // работа с его методами первым способом
    SubDin->set_name("Ryan Dark");  // работа с его методами вторым способом
    cout << SubDin->to_string();
    delete SubDin; // удаление динамического объекта
    // Статический массив из указателей на объекты
    TelSub* SubPtr[10]; // 0 объектов создано

    for (int i = 0; i < 10; i++) {
        SubPtr[i] = new TelSub();
        cout << SubPtr[i]->to_string();
    }
    // Освобождение памяти
    for (int i = 0; i < 10; i++) {
        delete SubPtr[i];
    }
    //todo: загружать с гита через файл - клонировать репозиторий

}
