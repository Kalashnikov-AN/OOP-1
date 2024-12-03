// Автор: Калашников А.Н.
#include <iostream>
#include "tel_sub.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "ru-RU.UTF-8");
    // Тестирование методов класса
    Test_Classes();

    // Статическое создание объекта с помощью конструктора по умолчанию
    CorporateTS sub;
    cout << sub.to_string(); // Вывод полей объекта
    // Статическое создание объекта с помощью конструктора c параметрами
    CorporateTS SubP("+8(800)924-32-71", "000002", "Medium", "John Light", 120, "Yandex", "Worker", 320);
    cout << SubP.to_string(); // Вывод полей объекта

    // Статический массив из объектов
    PremiumTS subs[10];
    subs[0].set_tariff("Based");
    subs[0].set_name("Jack Hopkins");
    subs[0].set_pn("+8(800)555-35-35");
    subs[0].set_an("000003");
    subs[0].replenish_balance(400);
    cout << subs[0].to_string(); // Вывод всех полей объекта на экран

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

    // Демонстрация динамического полиморфизма
    cout << endl << "Dynamic polymorphism:" << endl;

    CorporateTS subDP; // создаём объект производного класса для корпоративных абонентов с помощью конструктора по умолчанию
    cout << subDP.to_string(); // вызов варианта метода из производного класса

    // Динамически создаём объект производного класса PremiumTS
    TelSub* subObj = new PremiumTS();
    cout << subObj->to_string(); // вызов переопределённого метода из производного класса

    //subObj->set_level("Super-Premium"); // ошибка: set_level нет в базовом классе TelSub
 
    // преобразовываем указатель на объект базового класса к указателю на объект производного класса и вызываем метод из прозв. класса
    dynamic_cast<PremiumTS*>(subObj)->set_level("Super-Premium"); 
    
}
