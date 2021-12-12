#pragma once
#include<vector>
#include"PCB.h"

class ALLPCB
{
public:
    ALLPCB();
    void addwait(PCB* pcb);//加入到等待队列
    void addready(PCB* pcb);//加入到就绪队列
    void addwill(PCB* pcb);//加入到未到达队列
    void zhixing(PCB* pcb);//执行进程
    void addquanbu(PCB pcb);
    PCB* PCBing();//返回正在执行的进程指针
    vector<PCB*> Wait();//返回等待队列
    vector<PCB*> Ready();//返回就绪队列
    vector<PCB*> Will();//返回未到达队列
    vector<PCB>* Quanbu() { return &quanbu; }
    void waitToready();//将等待队列的东西放到就绪队列
    void willTowait(int time);//将刚好到达的进程放入等待队列
    void finish();//释放正在执行进程的资源
    void printt()//打印全部
    {
        for (vector<PCB>::iterator it = quanbu.begin(); it != quanbu.end(); it++)
            (*it).shownormal();
    }
    void print0()//打印全部
    {
        for (vector<PCB>::iterator it = quanbu.begin(); it != quanbu.end(); it++)
            cout << (*it).getName() << endl;
    }
    void print1()//打印等待
    {
        for (vector<PCB*>::iterator it = wait.begin(); it != wait.end(); it++)
            cout << (**it).getName() << endl;
    }
    void print2()//打印就绪
    {
        for (vector<PCB*>::iterator it = ready.begin(); it != ready.end(); it++)
            cout << (**it).getName() << endl;
    }
    void print3()//打印未到
    {
        for (vector<PCB*>::iterator it = will.begin(); it != will.end(); it++)
            cout << (**it).getName() << endl;
    }
    void print4()//打印执行顺序
    {
        for (vector<string>::iterator it = shunxv.begin(); it != shunxv.end(); it++)
            cout << *it << endl;
    }
    void print()//打印全部进程以及资源
    {
        for (vector<PCB>::iterator it = quanbu.begin(); it != quanbu.end(); it++)
        {
            cout << (*it).getName();//名称
            cout << (*it).getSize();//资源数量
            for (int i = 0; i < (*it).getSize(); ++i)//打印资源
            {
                cout << (*(*it).Resources[i]).getname();
            }
            cout << endl;
        }
    }
    bool over();//彻底结束标志
//private:
    vector<PCB> quanbu;//全部队列
    vector<PCB*> wait;//等待队列
    vector<PCB*> ready;//就绪队列
    vector<PCB*> will;//未到达队列
    PCB* pcbing;//正在执行的进程
    vector<string>shunxv;//记录执行顺序
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
    //从就绪队列删除
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
            for (int i = 0; i < (**it).getSize(); ++i)//判断每个资源是否满足
            {
                if ((*(**it).Resources[i]).getsignal() == 0)
                    flag = 0;
            }
            flag0 = flag;
            if (flag)
            {
                for (int i = 0; i < (**it).getSize(); ++i)//P每一个资源
                    (*(**it).Resources[i]).P();
                PCB* pcb = *it;//取出元素
                wait.erase(it);//删除元素
                addready(pcb);//加入准备队列
                break;
            }
        }
    }
}
void ALLPCB::finish()
{
    for (int i = 0; i < (*pcbing).getSize(); ++i)
        (*(*pcbing).Resources[i]).V();
    if ((*pcbing).getRemaintime() == 0)//如果剩余时间==0，设置over状态
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
