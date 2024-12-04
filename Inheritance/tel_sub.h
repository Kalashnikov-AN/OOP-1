// Автор: Калашников А.Н.
#pragma once
#include <string>
using namespace std;
/// Класс телефонного абонента
class TelSub{
private:
    // поля класса:
    // номер телефона абонента
    string phone_number;
    // номер лицевого счёта абонента
    string account_number;
    // имя абонента
    string name;
protected: // доступ имеют поля и методы базового и производных классов
    // название тарифа абонента
    string tariff;
public:
    // баланс абонента
    double balance;
    /// Конструктор по умолчанию
    TelSub();
    /// Конструктор с параметрами: pn - номер телефона, an - номер лицевого счёта, tariff1 - тариф, name1 - имя, balance1 - баланс
    TelSub(const string& pn, const string& an, const string& tariff1, const string& name1, const double& balance1);

    /// Возвращает номер телефона абонента
    string get_pn() const;
    /// Возвращает номер лицевого счёта абонента
    string get_an() const;
    /// Возвращает название тарифа абонента
    string get_tariff() const;
    /// Возвращает имя абонента
    string get_name() const;
    /// Изменяет поле номера телефона на номер телефона pn
    void set_pn(const string& pn);
    /// Изменяет поле лицевого счёта абонента на лицевой счёт an
    void set_an( const string& an );
    /// Изменяет поле тарифа на тариф tariff1
    virtual void set_tariff(const string& tariff1 );
    /// Изменяет поле имени абонента на имя name1
    void set_name(const string& name1 );
    /// Пополнение баланса абонента на величину balance1
    void replenish_balance(const double& balance1);
    /// Возвращает строку из всех полей объекта класса TelSub 
    virtual string to_string() const;
};

/// Класс корпоративного клиента, наследуется от класса TelSub обычного телефонного абонента
class CorporateTS: public TelSub {
private:
public:
    string company_name; // название компании
    string employee_status; // должность сотрудника, пользующегося данной корпоративной сим-картой
    double company_balance; // корпоративный баланс
    /// Конструктор по умолчанию, задаёт стандартные значения для аккаунта корпоративного клиента
    CorporateTS(); 
    /// Конструктор с параметрами: pn - номер телефона, an - номер лицевого счёта, tariff1 - тариф, name1 - имя, balance1 - баланс, comp_name - название компании, employee - должность сотрудника, comp_balance - корпоративный баланс
    CorporateTS(const string& pn, const string& an, const string& tariff1, const string& name1, const double& balance1,
        const string& comp_name, const string& employee, const double& comp_balance);
    /// Переопределённая функция задания тарифа tariff1 из базового класса
    void set_tariff(const string& tariff1) override;
    /// Возвращает строку из всех полей объекта класса CorporateTS
    string to_string() const override;
};

/// Класс клиента с премиум-аккаунтом, наследуется от класса TelSub обычного телефонного абонента
class PremiumTS: public TelSub {
private:
    int premium_duration; // количество оставшихся дней премиума
    string premium_level; // уровень премиума
    int reward_points; // бонусные баллы на премиум-аккаунте абонента
public:
    /// Конструктор по умолчанию, задаёт стандартные значения полей для аккаунта премиум-клиента
    PremiumTS();
    /// Конструктор с параметрами: pn - номер телефона, an - номер лицевого счёта, tariff1 - тариф, name1 - имя, balance1 - баланс, duration - количество оставшихся дней премиума, premium - уровень премиума, points - бонусные баллы
    PremiumTS(const string& pn, const string& an, const string& tariff1, const string& name1, const double& balance1,
        const int& duration, const string& premium, const int& points);
    /// Установить уровень премиума level
    void set_level(string level);
    /// Возвращает уровень премиума
    string get_level() const;
    /// Установить количество бонусных баллов points
    void set_rp(int points);
    /// Возвращает количество бонусных баллов
    int get_rp() const;
    void set_duration(int days);
    int get_duration() const;
    /// Возвращает строку из всех полей объекта класса PremiumTS
    string to_string() const override;

};

/// Тестирование методов класса
void Test_Classes();
