#include "tel_sub.h"
#include <regex>
#include <string>
#include <stdexcept> // Заголовочный файл, используемый для сообщений об исключениях
#include <vector> // Заголовочный файл для работы с вектором. Вектор представляет контейнер,
//который содержит коллекцию объектов одного типа.
// Контейнеры - шаблоны классов
#include <algorithm>
#include <cctype>
using namespace std;
vector <string> tariffs{"Базовый", "Медиум", "Продвинутый", "Про", "Бюджетный", "Супер-Тариф", "Мега-Тариф"};
TelSub::TelSub() {
balance = 0;
set_pn("+8(924)000-00-00");
set_an("000001");
set_tariff("Базовый");
set_name("Фамилия Имя Отчество");
}

TelSub::TelSub(string pn, string an, string tariff1, string name1, double balance1) {
        set_pn(pn);
        set_an(an);
        set_tariff(tariff1);
        set_name(name1);
        balance = 0;
    }

void TelSub::set_pn(string pn){
        regex rx("\\+([0-9]{1,3})(\\([0-9]{1,3}\\))([0-9\\-]{9})");
        if(regex_match(pn, rx)){
                phone_number = pn;
        }
        else{
                phone_number = "+8(924)000-00-00";
                throw invalid_argument("Ошибка: неверно введён номер телефона. Придерживайтесь формата +.(...)...-..-..");

        }
}

///
void TelSub::set_an(string an){
        regex rx("([0-9]{6})");
        if(regex_match(an, rx)){
                account_number = an;
        }
        else{
                account_number = "000001";
                throw invalid_argument("Ошибка: неверно введён лицевой счёт. Придерживайтесь  шестизначного числового формата ");

        }
}
///
void TelSub::set_tariff(string tariff1){
        if (count(tariffs.begin(), tariffs.end(), tariff1) > 0){
                tariff = tariff1;
        }
        else{
                tariff = "Базовый";
                throw invalid_argument("Ошибка: неверно введён тариф. Выберите тариф из списка тарифов");

        }
}

///
void TelSub::set_name(string name1){
        bool isNameValid = all_of(name1.begin(), name1.end(), [](char c) {
return isalpha(c) || isspace(c);
});
        if(isNameValid){
                name = name1;
        }
        else{
                name = "Фамилия Имя Отчество";
                throw invalid_argument("Ошибка: неверно введено ФИО");

        }
}

///
string TelSub::get_pn() const{
        return phone_number;
}
///
string TelSub::get_an() const{
        return account_number;
}
///
string TelSub::get_tariff() const{
        return tariff;
}
///
string TelSub::get_name() const{
        return name;
}
void TelSub::replenish_balance(double balance1){
        if (balance1 > 0){
                balance += balance1;
        }
        else{
                throw invalid_argument("Ошибка: неверно введена сумма пополнения баланса");

        }
}
string TelSub::to_string() const{
        string s;
        s = phone_number + ' ' + account_number + ' ' + tariff + ' ' + name + ' ' + std::to_string(balance);
        return s; 
}
