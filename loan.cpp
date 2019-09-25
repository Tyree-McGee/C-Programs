#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "loan.h"
#include <cmath>

using namespace std;

loan::loan()
{
    interestRate = 0.0;
    value = 0.0;
    length = 0;
}
loan::loan(double val, int m, double i)
{
    value = val;
    length = m;
    interestRate = i;
}

void loan::getIR(double i)
{
    interestRate = i;
}

void loan::getValue(double d)
{
    value = d;
}

void loan::getLength(int m)
{
    length = m;

}

double loan:: IR() const
{
    return interestRate;
}

double loan:: values() const
{
    return value;
}

int loan:: lengths() const
{
    return length;
}

void loan :: menu()
{
    cout << "Press A to display monthly payment" << endl
         << "Press B to display monthly interest" << endl
         << "Press C to display monthly principal payment" << endl
         /*<< "Press D to display monthly payments during the loan period" << endl*/
         << "Press E to exit the program" << endl;

}

double loan:: term()
{
    double t;
    t = pow(1+(IR()/12),lengths()*12);
    return t;
}
double loan:: payment(double cash)
{
    double p;
    p = (cash*(IR()/12)*term())/(term()-1);
    return p;
}
void loan:: monthPay()
{
    double hold = values();
    for (int i = 0; i < length*12; i++)
    {
        cout << "Your monthly payment for month " << i+1 << " is $ ";
        cout << fixed << setprecision(2) << payment(hold) << endl;
        hold = hold - payment(hold);
    }
}
void loan:: interest()
{
    double v = values();

    for (int i = 0; i < length*12; i++)
    {
        cout << "Your monthly interest for " << i+1 << " is $ ";
        cout << fixed << setprecision(2);
        cout << (payment(v)*IR()) << endl;
        v = v - payment(v);
    }

}
void loan:: principal()
{
    double p = values();
    for (int i = 0; i < length*12; i++)
    {
        cout << "Your principal for month " << i+1 << " is $ ";
        cout << fixed << setprecision(2);
        cout << payment(p) - (IR() * payment(p)) << endl;
        p = p - payment(p);
    }

}
/*void loan:: balance()
{
    double b = value;
    for (int i = 0; i < length*12; i++)
    {
        cout << "Your balance for month " << i+1 << " is $ ";
        cout << fixed << setprecision(2);
        cout << b/(lengths()*12) << endl;
        b = b - payment(b);
    }
}
*/
