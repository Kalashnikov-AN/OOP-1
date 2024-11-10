#include <iostream>
#include <math.h>
#include "tel_sub.h"

using namespace std;




int main() {

    setlocale(LC_ALL, "ru-RU.UTF-8");

    // 
//subs[1].balance = 500;
//for(int i = 0; i < 2; i++){
    try {
        cout << "yes";
        //subs[2] = TelSub("+8(800)555-35-35", "000001", "Базовый", "Иванов Иван Иванович", 0);
        //subs[2].replenish_balance(250);
        //print_sub(subs[0]);
        TelSub subs[10];
        cout << "yes";
        subs[0].set_tariff("Based");
        subs[0].set_name("Jack Hopkins");
        subs[0].set_pn("+8(800)555-35-35");
        //subs[0].set_an("000003");
        cout << "yes";
        // TelSub subs1[2]{TelSub("+8(800)555-35-35", "000001", "Базовый", "Иванов Иван Иванович", 0),
        // TelSub("+8(800)555-35-35", "000001", "Базовый", "Иванов Иван Иванович", 0)};
    }
    catch (invalid_argument error) { // если поймали ошибку типа invalid_argument
        cout << error.what(); // выведем сообщение об ошибке на экран
    }
}
// coords[4].set_lon(22);
// cout << coords[4].to_string();



// GeoCoord *coord2 = new GeoCoord[200];    // 

// coord2[4].set_lon(22);
// cout << coord2[4].to_string();

// delete[] coord2;



// 
// GeoCoord* coords3[3];      // 

// for (int i = 0; i<3; i++){
//     coords3[i] = new GeoCoord( rand()%180-90, rand()%360-180 );
//     cout << coords3[i] -> to_string() << "\n";
// }


// for (int i = 0; i<3; i++)
//     delete coords3[i];

//}