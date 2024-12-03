// Автор: Калашников А.Н.

#include "tel_sub.h"
#include <regex>
#include <string>
#include <vector> // Заголовочный файл для работы с вектором. Вектор представляет контейнер,
//который содержит коллекцию объектов одного типа.
// Контейнеры - шаблоны классов
#include <algorithm>
#include <cctype>
#include <iostream>
#include <cassert>
#include <fstream>


using namespace std;
//todo: style
const vector <string> CORP_TARIFFS{ "Partner", "Union", "Best Friends"};
const vector <string> TARIFFS{"Based", "Medium", "Advanced", "Pro", "Budget", "Super-Tariff", "Mega-Tariff"};
const vector <string> LEVELS{"Great Guy", "Friend", "Super-Premium"};


/// Конструктор по умолчанию
TelSub::TelSub() {
balance = 0;
phone_number = "+8(924)000-00-00";
account_number = "000001";
tariff = "Based";
name = "Name Surname";
}



/// Конструктор с параметрами: pn - номер телефона, an - номер лицевого счёта, tariff1 - тариф, name1 - имя, balance1 - баланс
TelSub::TelSub(const string& pn, const string& an, const string& tariff1, const string& name1, const double& balance1) {
        set_pn(pn);
        set_an(an);
        set_tariff(tariff1);
        set_name(name1);
        balance = balance1;
    }


/// Изменяет поле номера телефона на номер телефона pn
void TelSub::set_pn(const string& pn){
        /*создаём объект rx типа regex(регулярное выражение) из стандартной библиотеки C++ <regex>.
        Этот объект будет использоваться для поиска или сопоставления строк с заданным шаблоном маски телефона.
        Соответствует строкам, представляющим телефонные номера, начинающиеся с плюса и одной цифры,
        за которой следует код, окруженный скобками(от одной до трёх цифр), и номер длиной в девять символов,
        состоящих из цифр или дефисов */
        regex rx("\\+([0-9]{1})(\\([0-9]{1,3}\\))([0-9\\-]{9})"); // маска номера телефона
        if(regex_match(pn, rx)){ // если введенный номер телефона совпадает с шаблоном
                phone_number = pn;
        }
        else{
                phone_number = "+8(924)000-00-00";
                cerr << ("Ошибка: неверно введён номер телефона. Придерживайтесь формата +.(...)...-..-..") << endl;

        }
}

/// Изменяет поле лицевого счёта абонента на лицевой счёт an
void TelSub::set_an(const string& an){
        /*создаём объект rx типа regex(регулярное выражение) из стандартной библиотеки C++ <regex>.
        Этот объект будет использоваться для поиска или сопоставления строк с заданным шаблоном маски номера
        лицевого счёта.
        Соответствует строкам, представляющим любые шестизначные числа */
         static const regex rx(R"([0-9]{6})"); // регулярное выражение, любое шестизначное число
         if(regex_match(an, rx)){ // если введенный лицевой счёт совпадает с шаблоном
                account_number = an;
        }
        else{
                account_number = "000001";
                cerr << ("Ошибка: неверно введён лицевой счёт. Придерживайтесь  шестизначного числового формата ") << endl;

        }    
}

/// Изменяет поле тарифа на тариф tariff1
void TelSub::set_tariff(const string& tariff1){
        // если введённый тариф присутствует в списке тарифов
        if (count(TARIFFS.begin(), TARIFFS.end(), tariff1) > 0){ 
                tariff = tariff1;
        }
        else{
                tariff = "Based";
                cerr << ("Ошибка: неверно введён тариф. Выберите тариф из списка тарифов") << endl;

        }
}

/// Изменяет поле имени абонента на имя name1
void TelSub::set_name(const string& name1){
        bool isNameValid = all_of(name1.begin(), name1.end(), [](char c) { // Подходит, если состоит только
return isalpha(c) || isspace(c); // из букв и пробелов
});
        if(isNameValid){
                name = name1;
        }
        // если не подходит
        else{
                name = "Name Surname";
                cerr << ("Ошибка: неверно введено ФИО") << endl;

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
void TelSub::replenish_balance(const double& balance1){
        if (balance1 > 0){
                balance += balance1;
        }
        else{
            // std::cerr используется для вывода ошибок в стандартный поток ошибок (stderr)
            cerr << ("Ошибка: неверно введена сумма пополнения баланса") << endl; 

        }
}

/// Возвращает строку из всех полей объекта класса TelSub
string TelSub::to_string() const {
        string s;
        s = phone_number + ' ' + account_number + ' ' + tariff + ' ' + name + ' ' + std::to_string(balance) + '\n';
        return s; 
}

/// Конструктор по умолчанию, задаёт стандартные значения для аккаунта корпоративного клиента
CorporateTS::CorporateTS() {
    company_name = "Компания";
    employee_status = "Работник";
    company_balance = 0;
}

/// Конструктор с параметрами: pn - номер телефона, an - номер лицевого счёта, tariff1 - тариф, name1 - имя, balance1 - баланс, comp_name - название компании, employee - должность сотрудника, comp_balance - корпоративный баланс
CorporateTS::CorporateTS(const string& pn, const string& an, const string& tariff1, const string& name1, const double& balance1,
    const string& comp_name, const string& employee, const double& comp_balance): TelSub(pn, an, tariff1, name1, balance1){
    company_name = comp_name;
    employee_status = employee;
    company_balance = comp_balance;
}

/// Изменяет поле тарифа объекта класса CorporateTS на тариф tariff1
void CorporateTS::set_tariff(const string& tariff1) {
    // если введённый тариф присутствует в списке корпоративных тарифов
    if (count(CORP_TARIFFS.begin(), CORP_TARIFFS.end(), tariff1) > 0) {
        tariff = tariff1;
    }
    else {
        tariff = "Partner";
        cerr << ("Ошибка: неверно введён тариф. Выберите тариф из списка тарифов") << endl;

    }
}

/// Возвращает строку из всех полей объекта класса CorporateTS
string CorporateTS::to_string() const {
    return TelSub::to_string() + company_name + " " + employee_status + " " + ::to_string(company_balance) + "\n";
}

/// Конструктор по умолчанию, задаёт стандартные значения полей для аккаунта премиум-клиента
PremiumTS::PremiumTS() {
    premium_duration = 30;
    premium_level = "Great Guy";
    reward_points = 0;
}

/// Конструктор с параметрами: pn - номер телефона, an - номер лицевого счёта, tariff1 - тариф, name1 - имя, balance1 - баланс, duration - количество оставшихся дней премиума, premium - уровень премиума, points - бонусные баллы
PremiumTS::PremiumTS(const string& pn, const string& an, const string& tariff1, const string& name1, const double& balance1,
    const int& duration, const string& premium, const int& points): TelSub(pn, an, tariff1, name1, balance1) {
    premium_duration = duration;
    premium_level = premium;
    reward_points = points;
}

/// Установить уровень премиума level
void PremiumTS::set_level(string level) {
    // если введённый уровень премиума присутствует в списке премиумов 
    if (count(LEVELS.begin(), LEVELS.end(), level) > 0) {
        premium_level = level;
        cout << "Уровень премиума изменён на " << level << endl;
    }
    else {
        premium_level = "Friend";
        cerr << ("Ошибка: неверно введён уровень премиума. Выберите уровень премиума из списка премиумов") << endl;

    }
}

/// Возвращает уровень премиума абонента
string PremiumTS::get_level() const {
    return premium_level;
}

/// Установить количество бонусных баллов points
void PremiumTS::set_rp(int points) {
    // если задаваемое кол-во баллов не меньше нуля
    if (points >= 0) {
        reward_points = points;
    }
    else {
        reward_points = 0;
        cerr << ("Ошибка: неверно введена сумма бонусных баллов.") << endl;

    }
}

/// Возвращает сумму бонусных баллов абонента
int PremiumTS::get_rp() const {
    return reward_points;
}

/// Возвращает строку из всех полей объекта класса PremiumTS
string PremiumTS::to_string() const {
    return TelSub::to_string() + ::to_string(premium_duration) + " дней " + premium_level + " " + ::to_string(reward_points) + "\n";
}

/// Тестирование методов класса
void Test_TelSub() {
    // Проверка конструктора с параметрами, проверка геттеров
    TelSub TestSub("+8(800)123-45-67", "000007", "Super-Tariff", "Test Test", 100);
    assert(TestSub.get_pn() == "+8(800)123-45-67");
    assert(TestSub.get_an () == "000007");
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

    // Тест проверки введённых данных
    TestSet.set_name("123");
    assert(TestSet.get_name() == "Name Surname");
    TestSet.set_pn("123");
    assert(TestSet.get_pn() == "+8(924)000-00-00");
    TestSet.set_an("123");
    assert(TestSet.get_an() == "000001");
    TestSet.set_tariff("123");
    assert(TestSet.get_tariff() == "Based");
    TestSet.replenish_balance(-20);
    assert(TestSet.balance == 150);

}
