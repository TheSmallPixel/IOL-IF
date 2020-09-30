//
//  main.cpp
//  eq di secondo grado
//
//  Created by Andrea on 27/07/17.
//  Copyright © 2017 Andrea. All rights reserved.
//

#include <iostream>
#include <math.h>

double const Pgreco = 3.1415;

namespace andrea {
    int pini = 2;
    int cin = 7;
};

int  risolvente(float a, float b, float c, float &x1, float &x2);
int  saluta(float a);

using namespace std;

int main(int argc, const char * argv[]) {
    int pini = 33;
    cout << "Pini =" << pini  << endl;
    cout << "andrea Pini= " << andrea::pini << endl ;
    
    // insert code here...
    float a, b, c, x1, x2;
    cout << "a = " << a << endl;
    cout << "Equazione di secondo grado\n";
    cout << "inserisci a b c: " << endl;
    cin >> a >> b >> c ;
    cout << a <<" " << b << " " << c  << endl;
    risolvente(a, b, c, x1, x2);
    cout << "somma = " << x1 + x2 << endl;
    
    return 0;
}

int risolvente(float a, float b, float c, float &x1, float &x2){
    float  delta, ret;
    delta = 0;
    ret = saluta(a)-3;
    delta = pow(b,2)-4*a*c;
    if (delta >  0){
        x1 = (-b + sqrt(delta))/(2*a);
        cout << "x1 = " << x1 << endl;
        x2 = (-b - sqrt(delta))/(2*a);
        cout << "x2 = " << x2 << endl;
    }
    else {
        cout << "l'equazione ha soluzioni nel campo dei numeri complessi" << endl;
        ret = 4;
    }
    return ret;
}

int saluta(float a){
    return 3+a;
}