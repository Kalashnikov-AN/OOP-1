#pragma once
#include <string>
using namespace std;
/// 
class TelSub{

private:
    string phone_number;
    string account_number;
    string tariff;
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
void print_sub(const TelSub & sub);