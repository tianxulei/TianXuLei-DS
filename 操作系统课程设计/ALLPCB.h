#pragma once
#include<vector>
#include"PCB.h"

class ALLPCB
{
public:
    ALLPCB();
    void addwait(PCB* pcb);//���뵽�ȴ�����
    void addready(PCB* pcb);//���뵽��������
    void addwill(PCB* pcb);//���뵽δ�������
    void zhixing(PCB* pcb);//ִ�н���
    void addquanbu(PCB pcb);
    PCB* PCBing();//��������ִ�еĽ���ָ��
    vector<PCB*> Wait();//���صȴ�����
    vector<PCB*> Ready();//���ؾ�������
    vector<PCB*> Will();//����δ�������
    vector<PCB>* Quanbu() { return &quanbu; }
    void waitToready();//���ȴ����еĶ����ŵ���������
    void willTowait(int time);//���պõ���Ľ��̷���ȴ�����
    void finish();//�ͷ�����ִ�н��̵���Դ
    void printt()//��ӡȫ��
    {
        for (vector<PCB>::iterator it = quanbu.begin(); it != quanbu.end(); it++)
            (*it).shownormal();
    }
    void print0()//��ӡȫ��
    {
        for (vector<PCB>::iterator it = quanbu.begin(); it != quanbu.end(); it++)
            cout << (*it).getName() << endl;
    }
    void print1()//��ӡ�ȴ�
    {
        for (vector<PCB*>::iterator it = wait.begin(); it != wait.end(); it++)
            cout << (**it).getName() << endl;
    }
    void print2()//��ӡ����
    {
        for (vector<PCB*>::iterator it = ready.begin(); it != ready.end(); it++)
            cout << (**it).getName() << endl;
    }
    void print3()//��ӡδ��
    {
        for (vector<PCB*>::iterator it = will.begin(); it != will.end(); it++)
            cout << (**it).getName() << endl;
    }
    void print4()//��ӡִ��˳��
    {
        for (vector<string>::iterator it = shunxv.begin(); it != shunxv.end(); it++)
            cout << *it << endl;
    }
    void print()//��ӡȫ�������Լ���Դ
    {
        for (vector<PCB>::iterator it = quanbu.begin(); it != quanbu.end(); it++)
        {
            cout << (*it).getName();//����
            cout << (*it).getSize();//��Դ����
            for (int i = 0; i < (*it).getSize(); ++i)//��ӡ��Դ
            {
                cout << (*(*it).Resources[i]).getname();
            }
            cout << endl;
        }
    }
    bool over();//���׽�����־
//private:
    vector<PCB> quanbu;//ȫ������
    vector<PCB*> wait;//�ȴ�����
    vector<PCB*> ready;//��������
    vector<PCB*> will;//δ�������
    PCB* pcbing;//����ִ�еĽ���
    vector<string>shunxv;//��¼ִ��˳��
};

//#endif // ALLPCB_H_INCLUDED
ALLPCB::ALLPCB()
{
    quanbu.reserve(10000);
    wait.reserve(10000);
    ready.reserve(10000);
    will.reserve(10000);
    shunxv.reserve(10000);
}
void ALLPCB::addwait(PCB* pcb)
{
    wait.push_back(&(*pcb));
    (*wait.back()).setState("wait");
}

void ALLPCB::addready(PCB* pcb)
{
    ready.push_back(&(*pcb));
    (*ready.back()).setState("ready");
}

void ALLPCB::addquanbu(PCB pcb)
{
    quanbu.push_back(pcb);
    PCB* pcb1 = &quanbu.back();
    if (pcb.getArrivetime() > 0)
        addwill(pcb1);
    else
        addwait(pcb1);
    
    //delete(pcb1);
}

void ALLPCB::addwill(PCB* pcb)
{
    will.push_back(&(*pcb));
    (*will.back()).setState("will");
}

void ALLPCB::zhixing(PCB* pcb)
{
    pcbing = pcb;
    (*pcbing).setState("ing");
    //�Ӿ�������ɾ��
    for (vector<PCB*>::iterator it = ready.begin(); it != ready.end(); it++)
    {
        if ((**it).getName() == (*pcb).getName())
        {
            ready.erase(it);
            break;
        }
    }
    shunxv.push_back((*pcb).getName());
}

PCB* ALLPCB::PCBing()
{
    return pcbing;
}

vector<PCB*> ALLPCB::Wait()
{
    return wait;
}

vector<PCB*> ALLPCB::Ready()
{
    return ready;
}

vector<PCB*> ALLPCB::Will()
{
    return will;
}

void ALLPCB::waitToready()
{
    int flag0 = 1;
    while (!wait.empty() && flag0)
    {
        for (vector<PCB*>::iterator it = wait.begin(); it != wait.end(); it++)
        {
            int flag = 1;
            for (int i = 0; i < (**it).getSize(); ++i)//�ж�ÿ����Դ�Ƿ�����
            {
                if ((*(**it).Resources[i]).getsignal() == 0)
                    flag = 0;
            }
            flag0 = flag;
            if (flag)
            {
                for (int i = 0; i < (**it).getSize(); ++i)//Pÿһ����Դ
                    (*(**it).Resources[i]).P();
                PCB* pcb = *it;//ȡ��Ԫ��
                wait.erase(it);//ɾ��Ԫ��
                addready(pcb);//����׼������
                break;
            }
        }
    }
}
void ALLPCB::finish()
{
    for (int i = 0; i < (*pcbing).getSize(); ++i)
        (*(*pcbing).Resources[i]).V();
    if ((*pcbing).getRemaintime() == 0)//���ʣ��ʱ��==0������over״̬
        (*pcbing).setState("over");
    else
        addwait(&(*pcbing));
    pcbing = NULL;
}

bool ALLPCB::over()
{
    if (will.empty() && wait.empty() && ready.empty() && !pcbing)
        return true;
    return false;
}

void ALLPCB::willTowait(int time)
{
    int flag = 0;
    while (!will.empty() && !flag)
    {
        flag = 1;
        for (vector<PCB*>::iterator it = will.begin(); it != will.end(); it++)
        {
            if ((**it).getArrivetime() <= time)
            {
                PCB* pcb = &(**it);
                will.erase(it);
                addwait(pcb);
                flag = 0;
                //delete(pcb);
                break;
            }
        }
    }
}
