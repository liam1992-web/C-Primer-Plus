// definition for the Stonewt class

#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
    private:
        enum {Lbs_per_stn = 14};	// pounds per stone
        // static const int Lbs_per_stn = 14;
        int stone;			// whole stones
        double pds_left;		// fractional pounds
        double pounds;			// entire weight in pounds
    public:
        Stonewt(double lbs);            //构造1 初始化为一个浮点数（单位为磅）
        Stonewt(int stn, double lbs);   //构造2 初始化为两个浮点数（分别单位为英石和磅）
        Stonewt();                      //构造3 创建对象而不进行初始化
        ~Stonewt();
        void show_lbs() const;		// show weight in pounds format
        void show_stn() const;		// show weight in stone format
};
#endif
