#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Time
{
public:
    Time():hour(),minute(0),sec(0){};
    Time(int h,int m,int s):hour(h),minute(m),sec(s){};
    void set_time();
    void show_time();
    void add_a_sec();///增加1秒钟
    void add_a_minute();///增加1分钟
    void add_an_hour();///增加1小时
    /*void add_a_seconds(int);///增加n秒钟
    void add_a_minutes(int);///增加n分钟
    void add_an_hours(int);///增加n小时*/
private:
   /*bool is_time(int,int,int);*/
    int hour;
    int minute;
    int sec;
};
void Time::set_time()
{
    cin>>hour>>minute>>sec;

    /* char c1,c2;
    cout<<"请输入时间（格式hh:mm:ss)";
    while(1)
    {
        cin>>hour>>c1>>minute>>c2>>sec;
        if(c1!=':'||c2!=':')
        cout<<"格式不正确，请重新输入"<<endl;
        else if(!is_time(hour,minute,sec))
            cout<<"时间非法，请重新输入"<<endl;
            else
                break;
    }*/
}
void Time::show_time()
{
    cout<<hour<<":"<<minute<<":"<<sec<<endl;
}
void Time::add_an_hour()
{
    ++hour;
    if(hour>23)
        hour=0;
}
void Time::add_a_minute()
{
    ++minute;
    if(minute>59)
    {
        minute=0;
        add_an_hour();
    }
}
void Time::add_a_sec()
{
    ++sec;
    if(sec>59)
    {
        sec=0;
        add_a_minute();
    }
}
/*void Time::add_an_hours(int n)
{
    hour+=n;
    if(hour>23)
        hour%=24;
}
void Time::add_a_minutes(int n)
{
    minute+=n;
    if(minute>59)
    {
        add_an_hours(minute/60);
        minute%=60;
    }
}
void Time::add_a_seconds(int n)
{
    sec+=n;
    if(sec>59)
    {
        add_a_minutes(sec/60);
        sec%=60;
    }
}*/

/*bool Time::is_time(int h,int m,int s)
{
    if(h=0||h>24||m<0||m>60||s<0||s>60)
        return false;
    return true;
}*/

int main()
{
   /*Time t1;
    t1.show_time();
    t1.set_time();
    t1.show_time();
    Time t2(8,20,50);
    t2.show_time();
    return 0;

   Time t1(8,20,50);
    t1.add_a_sec();
    t1.show_time();
    Time t2(8,20,59);
    t2.add_a_sec();
    t2.show_time();
    return 0;

   int i;
    Time t1(8,20,50);
    for(i=0;i<20;i++)
    {
        t1.add_a_sec();
        t1.show_time();
    }
    Time t2(10,56,50);
    for(i=0;i<20;i++)
    {
        t2.add_a_minute();
        t2.show_time();
    }
    Time t3(21,20,50);
    for(i=0;i<20;i++)
    {
        t3.add_an_hour();
        t3.show_time();
    }
    return 0;*/

   int debug=1;
    Time t1(8,20,50);
    while(debug)
    {
        t1.add_a_sec();
    }
    debug=1;
    while(debug)
    {
        t1.add_a_minute();
    }
    debug=1;
    while(debug)
        {
            t1.add_an_hour();
        }
    return 0;

    /*Time t1(21,32,45);
    t1.add_a_seconds(40);
    t1.show_time();
    t1.add_a_minutes(127);
    t1.show_time();
    t1.add_an_hours(8);
    t1.show_time();
    return 0;

   Time t1;
    t1.set_time();
    t1.show_time();
    return 0;*/
}
