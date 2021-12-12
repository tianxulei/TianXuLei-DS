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
    PCB(string na, int arrivetime, int servicetime);//���캯��������Ϊ������������ʱ�䣬ִ��ʱ��
    void  setName(string na);//�޸�����
    void  setArrivetime(int arrive);//�޸ĵ���ʱ��
    void  setFinishitime(int finishtime);//�޸����ʱ��
    void  setSign(int sign_completion);//�޸���ɱ�ʶ
    void  setRemaintime(int remaining_time);//����ʣ��ʱ��
    void  setState(string sta);//����״̬
    void  setPrio(int prio);//����������
    int   getArrivetime();
    int   getFinishitime();
    int   getSign();
    int   getRemaintime();
    int   getservicetime() { return servicetime; }
    int   getSize() { return Size; }
    string getName() { return name; }
    string  getState();
    int   getPrio();
    void  shownormal();//����һ����ʾ����ʾ����Ϊ�������������̵���ʱ�䣬����ʣ��ʱ�䣬����״̬
    void  showprio();//�������ȼ��㷨��������ʾ����ʾ����Ϊ�����������̵���ʱ�䣬����ʣ��ʱ�䣬����״̬��������
    void  go(int time);//����Ϊ���̻��һ��ʱ��Ĵ������ִ����һ��ʱ�䣬ʣ��ʱ����иı�
    void addresource(resource* S);//�����Դ����
    resource* Resources[20];
    void addSize() { ++this->Size; }

private:
    int Size;
    string name;      //��������
    int arrivetime;      //����ʱ��
    int servicetime;     //����ʱ��
    int finishtime;      //���ʱ��
    int sign_completion; //��־�Ƿ���ɵ��ã�0��ʾû��ɣ�1��ʾ���
    int remaining_time;  //ʣ�����ʱ��
    string state;          //״̬
    int prio;            //����������

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
