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


vector <string> tariffs{"Based", "Medium", "Advanced", "Pro", "Budget", "Super-Tariff", "Mega-Tariff"};


/// Конструктор по умолчанию
TelSub::TelSub() {
balance = 0;
phone_number = "+8(924)000-00-00";
account_number = "000001";
tariff = "Based";
name = "Name Surname";
}

CorporateTS::CorporateTS(){
    company_name = "123";
    employee_status = "321";
    company_balance = 546;
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
        if (count(tariffs.begin(), tariffs.end(), tariff1) > 0){ 
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
string TelSub::to_string() const{
        string s;
        s = phone_number + ' ' + account_number + ' ' + tariff + ' ' + name + ' ' + std::to_string(balance) + '\n';
        return s; 
}

/// Записывает поля объекта класса TelSub в файл fname
void TelSub::save_sub(const string& fname) const {
    ofstream f(fname); // Открываем файл на запись
    if (f.is_open()) { // Если файл открыт
        string temp = account_number;
        f << temp << endl;
        temp = name;
        f << temp << endl;
        temp = phone_number;
        f << temp << endl;
        temp = tariff;
        f << temp << endl;
        double temp1 = balance;
        f << temp1 << endl;
        f.close();
    }
}

/// Считывает данные из файла fname и заполняет поля объекта sub
void TelSub::load_sub(const string& fname) {
    ifstream f(fname); // Открываем файл на чтение
    if (f.is_open()) {
        string temp;
        getline(f, temp);
        set_an(temp);
        getline(f, temp);
        set_name(temp);
        getline(f, temp);
        set_pn(temp);
        getline(f, temp);
        set_tariff(temp);
        double temp1;
        f >> temp1;
        balance = temp1;
        f.close();
        
    }
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

    // Тест функции save_sub
    string test_fname = "test.txt";
    TestSet.save_sub(test_fname);
    TelSub LoadSet;
    LoadSet.load_sub(test_fname);
    assert(LoadSet.to_string() == "+8(924)000-00-00 000001 Based Name Surname 150,000000\n");

    // Тест функции load_sub
    string test_fname2 = "test_load.txt";
    LoadSet.load_sub(test_fname2);
    assert(LoadSet.to_string() == "+8(914)000-00-00 000002 Based Name Surname 100,000000\n");
}
