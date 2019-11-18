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
    Graduate();//�޲ι��캯��������
    Graduate(char* ,bool ,char [],double ,string ,string );//�вι��캯��������
    Graduate(const Graduate& r);//�������캯��������
    ~Graduate();//��������������

    static double aver;

    void Display();
    void Display()const;//����Ա����
    friend void level(const Graduate& r);
    static double average();
};

double Graduate::aver=0;

Graduate::Graduate()//�޲ι��캯��������
{
    cout<<"�޲ι��캯�����Զ�����"<<endl;
}

Graduate::Graduate(char *n,bool g,char i[],double s,string r,string t)
{
    cout<<"�вι��캯�����Զ�����"<<endl;
    strcpy(name,n);
    gender=g;
    strcpy(id,i);
    score=s;
    research=r;
    tutor=t;

}

Graduate::Graduate(const Graduate& r)//�������캯���Ķ���
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
    cout<<"�������캯�����Զ�����"<<endl;
}

Graduate::~Graduate()
{
    cout<<"�����������Զ�����"<<endl;
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
    cout<<"ƽ���ɼ�Ϊ��"<<Graduate::aver<<endl;
    level(Graduate2);
    return 0;
}
