#ifndef LOAN_H
#define LOAN_H

class loan
{
private:
    double interestRate,
           value;
    int length; // in months
public:
    loan();
    loan(double, int, double);
    void getIR(double);
    void getValue(double);
    void getLength(int);
    double IR() const;
    double values () const;
    int lengths () const;
    double term();
    double payment(double);
    void menu();
    void monthPay();
    void interest();
    void principal();
    void balance();



};



#endif
