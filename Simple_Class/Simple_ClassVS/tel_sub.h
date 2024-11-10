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
    // название тарифа абонента
    string tariff;
    // имя абонента
    string name;
public:
    double balance;
    TelSub();
    TelSub(string pn, string an, string tariff1, string name1, double balance1);

    ///
    string get_pn() const;
    ///
    string get_an() const;
    ///
    string get_tariff() const;
    string get_name() const;
    void set_pn( string pn );
    ///
    void set_an( const string& an );
    ///
    void set_tariff( string tariff1 );
    ///
    void set_name( string name1 );

    void replenish_balance(double balance1);
    /// 
    string to_string() const;
};
void Test_TelSub();
