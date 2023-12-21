#ifndef BRASS_H_
#define BRASS_H_

#include <string>

class Brass
{
    private:
        std::string fullName;
        long acctNum;
        double balance;
    public:
        Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
        void Deposit(double amt);
        virtual void Withdraw(double amt);
        double Balance() const;
        virtual void ViewAcct() const;
        virtual ~Brass() {}
};

class BrassPlus : public Brass
{
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        BrassPlus(const std::string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
        BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
        virtual void ViewAcct() const;
        virtual void Withdraw(double amt);
        void ResetMax(double m) {maxLoan = m;}
        void ResetRate(double r) {rate = r;}
        void ResetOwes() {owesBank = 0;}
};
/*
使用virtual：如果方法是通过引用或指针而不是对象调用的，它将确定使用哪一种方法，根据引用或指针指向的对象的类型来选择方法
如果没有使用virtual，程序根据引用类型或指针类型选择方法
*/
#endif