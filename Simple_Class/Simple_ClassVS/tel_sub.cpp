// Автор: Калашников А.Н.
#include "tel_sub.h"
#include <regex>
#include <string>
#include <stdexcept> // Заголовочный файл, используемый для сообщений об исключениях
#include <vector> // Заголовочный файл для работы с вектором. Вектор представляет контейнер,
//который содержит коллекцию объектов одного типа.
// Контейнеры - шаблоны классов
#include <algorithm>
#include <cctype>
#include <iostream>
#include <cassert>
using namespace std;
vector <string> tariffs{"Based", "Medium", "Advanced", "Pro", "Budget", "Super-Tariff", "Mega-Tariff"};
/// Конструктор по умолчанию
TelSub::TelSub() {
balance = 0;
phone_number = "+8(924)000-00-00";
account_number = "000001";
tariff = "Based";
name = "Name Surname";
}
/// Конструктор с параметрами: pn - номер телефона, an - номер лицевого счёта, tariff1 - тариф, name1 - имя, balance1 - баланс
TelSub::TelSub(string pn, string an, string tariff1, string name1, double balance1) {
        set_pn(pn);
        set_an(an);
        set_tariff(tariff1);
        set_name(name1);
        balance = balance1;
    }
/// Изменяет поле номера телефона на номер телефона pn
void TelSub::set_pn(string pn){
        regex rx("\\+([0-9]{1})(\\([0-9]{1,3}\\))([0-9\\-]{9})"); // маска номера телефона
        if(regex_match(pn, rx)){ // если введенный номер телефона совпадает по маске с р.в
                phone_number = pn;
        }
        else{
                phone_number = "+8(924)000-00-00";
                throw invalid_argument("Ошибка: неверно введён номер телефона. Придерживайтесь формата +.(...)...-..-..");

        }
}

/// Изменяет поле лицевого счёта абонента на лицевой счёт an
void TelSub::set_an(const string& an){
         static const regex rx(R"([0-9]{6})"); // регулярное выражение, любое шестизначное число
         if(regex_match(an, rx)){ // если введенный лицевой счёт совпадает по маске с р.в.
                account_number = an;
        }
        else{
                account_number = "000001";
                throw invalid_argument("Ошибка: неверно введён лицевой счёт. Придерживайтесь  шестизначного числового формата ");

        }    
}
/// Изменяет поле тарифа на тариф tariff1
void TelSub::set_tariff(string tariff1){
        // если введённый тариф присутствует в списке тарифов
        if (count(tariffs.begin(), tariffs.end(), tariff1) > 0){ 
                tariff = tariff1;
        }
        else{
                tariff = "Базовый";
                throw invalid_argument("Ошибка: неверно введён тариф. Выберите тариф из списка тарифов");

        }
}

/// Изменяет поле имени абонента на имя name1
void TelSub::set_name(string name1){
        bool isNameValid = all_of(name1.begin(), name1.end(), [](char c) { // Подходит, если состоит только
return isalpha(c) || isspace(c); // из букв и пробелов
});
        if(isNameValid){
                name = name1;
        }
        // если не подходит
        else{
                name = "Фамилия Имя Отчество";
                throw invalid_argument("Ошибка: неверно введено ФИО");

        }
}

/// Возвращает номер телефона абонента
string TelSub::get_pn() const{
        return phone_number;
}
/// Возвращает номер лицевого счёта абонента
string TelSub::get_an() const{
        return account_number;
}
/// Возвращает тариф абонента
string TelSub::get_tariff() const{
        return tariff;
}
/// Возвращает имя абонента
string TelSub::get_name() const{
        return name;
}
/// Пополнение баланса абонента на величину balance1
void TelSub::replenish_balance(double balance1){
        if (balance1 > 0){
                balance += balance1;
        }
        else{
                throw invalid_argument("Ошибка: неверно введена сумма пополнения баланса");

        }
}
/// Возвращает строку из всех полей класса TelSub
string TelSub::to_string() const{
        string s;
        s = phone_number + ' ' + account_number + ' ' + tariff + ' ' + name + ' ' + std::to_string(balance) + '\n';
        return s; 
}
/// Тестирование методов класса
void Test_TelSub() {
    // Проверка конструктора с параметрами, проверка геттеров
    TelSub TestSub("+8(800)123-45-67", "000007", "Super-Tariff", "Test Test", 100);
    assert(TestSub.get_pn() == "+8(800)123-45-67");
    assert(TestSub.get_an() == "000007");
    assert(TestSub.get_tariff() == "Super-Tariff");
    assert(TestSub.get_name() == "Test Test");
    assert(TestSub.balance == 100);
    // Проверка сеттеров
    TelSub TestSet;
    TestSet.set_name("Billy Johnson");
    assert(TestSet.get_name() == "Billy Johnson");
    TestSet.set_pn("+8(800)123-45-67");
    assert(TestSet.get_pn() == "+8(800)123-45-67");
    TestSet.set_an("000010");
    assert(TestSet.get_an() == "000010");
    TestSet.set_tariff("Based");
    assert(TestSet.get_tariff() == "Based");
    TestSet.replenish_balance(150);
    assert(TestSet.balance == 150);
}
