#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <string>
//p511
//Abstract Base Class
class AcctABC
{
    private:
        std::string fullName;
        long acctNum;
        double balance;
    protected:
        struct Formatting
        {
            std::ios_base::fmtflags flag;
            std::streamsize pr;
        };
        const std::string & FullName() const {return fullName;}
        long AcctNum() const {return acctNum;}      //内联函数
        Formatting SetFormat() const;
        void Restore(Formatting & f) const;
    public:
        AcctABC(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);    //使用类对象的程序都可以直接访问共有部分，但只能通过公有成员函数才能访问对象的私有成员
        void Deposit(double amt);   //定义默认构造函数的两种方式：1在已有构造函数的所有参数提供默认值；2通过函数重载来定义一个构造函数-一个没有参数的构造函数；
        virtual void Withdraw(double amt) = 0;
        double Balance() const {return balance;}
        virtual void ViewAcct() const = 0;      //纯虚函数
        virtual ~AcctABC() {}
};

//Brass Account Class
class Brass :public AcctABC     //AcctABC是一个共有基类，被称为公有派生
{
    public:
        Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0) :AcctABC(s, an, bal) {}
        virtual void Withdraw(double amt);
        virtual void ViewAcct() const;
        virtual ~Brass() {}
};

//Brass Plus Account Class
class BrassPlus :public AcctABC
{
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        BrassPlus(const std::string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
        BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
        virtual void ViewAcct() const;
        virtual void Withdraw(double amt);
        void ResetMax(double m) {maxLoan = m;}
        void ResetRate(double r) {rate = r;}
        void ResetOwes() {owesBank = 0;}
};


#endif