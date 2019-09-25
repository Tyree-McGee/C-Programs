#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "loan.h"
#include "loan.cpp"

using namespace std;

int main()
{

    double money,
           rate;
    int years;
    char choice;

    loan car;

    cout << "Please enter the amount of the loan: ";
    cin >> money;
    cout << "Please enter the interest rate: ";
    cin >> rate;
    rate = rate/100;
    cout << "Please enter the length of the loan in years: ";
    cin >> years;

    car.getValue(money);
    car.getIR(rate);
    car.getLength(years);
    do
    {
        car.menu();
        cin >> choice;
        if (choice == 'A' || choice == 'a')
        {
            car.monthPay();
        }
        else if (choice == 'B' || choice == 'b')
        {
            car.interest();
        }
        else if (choice == 'C' || choice == 'c')
        {
            car.principal();
        }
      /*  else if (choice == 'D' || choice == 'd')
        {
            car.balance();
        }*/
        else if (choice == 'E' || choice == 'e')
        {
            cout << "Program Terminating";
            system("PAUSE>NUL");

            return 0;

        }
        else
            cout << "Invalid Choice." << endl;
    }while(choice != 'E' || choice !='e');

    system("PAUSE>NUL");

    return 0;

}
