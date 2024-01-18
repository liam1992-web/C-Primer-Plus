// revised definition for the Stonewt class

#ifndef STONEWT1_H_
#define STONEWT1_H_

class Stonewt
{
    private:
        enum {Lbs_per_stn = 14};
        // static const int Lbs_per_stn = 14;
        int stone;
        double pds_left;
        double pounds;
    public:
        Stonewt(double lbs);            //构造1 初始化为一个浮点数（单位为磅）
        Stonewt(int stn, double lbs);   //构造2 初始化为两个浮点数（分别单位为英石和磅）
        Stonewt();                      //构造3 创建对象而不进行初始化
        ~Stonewt();
        void show_lbs() const;
        void show_stn() const;
        operator int() const;       //没有声明返回类型，但也将返回需要的值
        operator double() const;
        Stonewt operator+(const Stonewt & st) const;
        friend Stonewt operator+(const Stonewt & st1, const Stonewt & st2);
};
#endif
