#include <iostream>

#include<string.h>

#include<math.h>
using namespace std;

class Graduate
{
private:
    char* name;
    bool gender;
    char id[20];
    double score;
    string research;
    string tutor;
public:
    Graduate();//无参构造函数的声明
    Graduate(char* ,bool ,char [],double ,string ,string );//有参构造函数的声明
    Graduate(const Graduate& r);//拷贝构造函数的声明
    ~Graduate();//析构函数的声明

    static double aver;

    void Display();
    void Display()const;//常成员函数
    friend void level(const Graduate& r);
    static double average();
};

double Graduate::aver=0;

Graduate::Graduate()//无参构造函数的声明
{
    cout<<"无参构造函数被自动调用"<<endl;
}

Graduate::Graduate(char *n,bool g,char i[],double s,string r,string t)
{
    cout<<"有参构造函数被自动调用"<<endl;
    strcpy(name,n);
    gender=g;
    strcpy(id,i);
    score=s;
    research=r;
    tutor=t;

}

Graduate::Graduate(const Graduate& r)//拷贝构造函数的定义
{
    double s;
    this->name=new char[strlen(r.name)+1];
    strcpy(this->name,r.name);
    this->gender=r.gender;
    strcpy(this->id,r.id);
    score=r.score;
    research=r.research;
    tutor=r.tutor;
    for(int i=0;i<20;i++)
    {
        s+=r.score;
    }
    aver=s/20;
    cout<<"拷贝构造函数被自动调用"<<endl;
}

Graduate::~Graduate()
{
    cout<<"析构函数被自动调用"<<endl;
}

double Graduate::average()
{
    return aver;
}

int level(Graduate &)
{
    double score;
    if(score>=90)
    {
        cout<<"A"<<endl;
    }
    else if(score>=80&&score<=89)
    {
        cout<<"B"<<endl;
    }
    else if(score>=70&&score<=79)
    {
        cout<<"C"<<endl;
    }
    else if(score>=60&&score<=69)
    {
        cout<<"D"<<endl;
    }
    else if(score<60)
    {
        cout<<"E"<<endl;
    }
}
void Graduate::Display( )
{
    cout<<name<<","<<gender<<","<<id[20]<<","<<score<<","<<research<<","<<tutor<<endl;
}

void Graduate::Display()const
{
    cout<<name<<","<<gender<<","<<id[20]<<","<<score<<","<<research<<","<<tutor<<endl;

}

int main()
{
    Graduate Graduate1;
    Graduate Graduate2("jiang",0,"123457",100,"Computer","Tsingke");
    Graduate Graduate3(Graduate2);
    Graduate2.Display();
    Graduate G1("tong",0,"123456",10,"Computer","Tsingke");
    G1.Display();
    cout<<"平均成绩为："<<Graduate::aver<<endl;
    level(Graduate2);
    return 0;
}
