#pragma once
#include<string>
#include<vector>
#include <malloc.h>
#include"resource.h"
using namespace std;

class PCB
{
public:
    PCB();
    virtual ~PCB();
    PCB(string na, int arrivetime, int servicetime);//构造函数，参数为进程名，到达时间，执行时间
    void  setName(string na);//修改名称
    void  setArrivetime(int arrive);//修改到达时间
    void  setFinishitime(int finishtime);//修改完成时间
    void  setSign(int sign_completion);//修改完成标识
    void  setRemaintime(int remaining_time);//设置剩余时间
    void  setState(string sta);//设置状态
    void  setPrio(int prio);//设置优先数
    int   getArrivetime();
    int   getFinishitime();
    int   getSign();
    int   getRemaintime();
    int   getservicetime() { return servicetime; }
    int   getSize() { return Size; }
    string getName() { return name; }
    string  getState();
    int   getPrio();
    void  shownormal();//进行一般显示，显示内容为，进程名，进程到达时间，进程剩余时间，进程状态
    void  showprio();//进行优先级算法的特殊显示，显示内容为进程名，进程到达时间，进程剩余时间，进程状态，优先数
    void  go(int time);//设置为进程获得一段时间的处理机，执行了一段时间，剩余时间进行改变
    void addresource(resource* S);//添加资源引用
    resource* Resources[20];
    void addSize() { ++this->Size; }

private:
    int Size;
    string name;      //进程名字
    int arrivetime;      //到达时间
    int servicetime;     //服务时间
    int finishtime;      //完成时刻
    int sign_completion; //标志是否完成调用，0表示没完成，1表示完成
    int remaining_time;  //剩余服务时间
    string state;          //状态
    int prio;            //设置优先数

};

//#endif // PCB_H_INCLUDED
PCB::PCB()
{
    //ctor
}
PCB::~PCB()
{
    //dtor
}
PCB::PCB(string name, int arrivetime, int servicetime)
{
    this->name = name;
    this->arrivetime = arrivetime;
    this->servicetime = servicetime;
    this->remaining_time = servicetime;
    this->state = "W";
    this->Size = 0;
}
void  PCB::setName(string na)
{
    this->name = na;
}
void  PCB::setArrivetime(int arrive)
{
    this->arrivetime = arrive;
}
void  PCB::setFinishitime(int finishtime)
{
    this->finishtime = finishtime;
}
void  PCB::setSign(int sign_completion)
{
    this->sign_completion = sign_completion;
}
void  PCB::setRemaintime(int remaining_time)
{
    this->remaining_time = remaining_time;
}

void  PCB::setState(string sta)
{
    this->state = sta;
}
void  PCB::setPrio(int prio)
{
    this->prio = prio;
}
int  PCB::getArrivetime()
{
    return this->arrivetime;
}
int PCB::getFinishitime()
{
    return this->finishtime;
}
int  PCB::getSign()
{
    return this->sign_completion;
}
int  PCB::getRemaintime()
{
    return this->remaining_time;
}
string PCB::getState()
{
    return this->state;
}
int  PCB::getPrio()
{
    return this->prio;
}
void PCB::go(int time)//
{
    if (this->remaining_time <= time)
    {
        this->remaining_time = 0;
        this->state = 'E';
    }
    else
    {
        this->remaining_time -= time;
        this->state = 'R';
    }
}
void PCB::shownormal()
{
    cout << this->name << "   " << this->arrivetime << "   " << this->remaining_time << "   " << this->state << endl;
}
void PCB::showprio()
{
    cout << this->name << "   " << this->arrivetime << "   " << this->remaining_time << "   " << this->state << "   " << this->prio << endl;
}
void PCB::addresource(resource* S)
{
    Resources[Size] = &(*S);
    addSize();
}
