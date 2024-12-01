// Автор: Калашников А.Н.
#pragma once
#include <string>
using namespace std;
/// КлФасс телефонного абонента
class TelSub{
private:
    // поля класса:
    // номер телефона абонента
    string phone_number;
    // номер лицевого счёта абонента
    string account_number;
    
    // имя абонента
    string name;
protected:
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
    /// Записывает поля объекта класса TelSub в файл fname
    void save_sub(const string& fname) const;
    /// Считывает данные из файла fname и заполняет поля объекта sub
    void load_sub(const string& fname);
};

class CorporateTS: public TelSub {
private:
public:
    string company_name;
    string employee_status;
    double company_balance;
    CorporateTS();
    void set_tariff(const string& tariff1) override;
    string to_string() const override;
};

class PremiumTS: public TelSub {
private:
    string premium_level;
    int reward_points;
public:
    PremiumTS();
    void set_level(string level);
    string get_level() const;
    void set_rp(int points);
    int get_rp() const;
    string to_string() const override;
};

/// Тестирование методов класса
void Test_TelSub();
