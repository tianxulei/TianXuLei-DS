#pragma once
#include<iostream>
#include"ALLPCB.h"

using namespace std;

void addsignal(vector<resource>& resources)
{
    int flag = 1;
    while (flag)
    {
        system("CLS");
        for (vector<resource>::iterator it = resources.begin(); it != resources.end(); it++)
            (*it).print();
        cout << "添加资源? 0.no  1.yes" << endl;
        cin >> flag;
        if (flag)
        {
            string Name;
            int Signal;
            cout << "资源名称:"; cin >> Name;
            cout << "  信号量:"; cin >> Signal;
            resource* S = new resource(Name, Signal);
            resources.push_back(*S);
            delete(S);
        }
    }
    system("CLS");
    for (vector<resource>::iterator it = resources.begin(); it != resources.end(); it++)
        (*it).print();
}

void addpcb(ALLPCB* PCBS, vector<resource>& resources)
{
    int flag = 1;
    while (flag)
    {
        system("CLS");
        for (vector<resource>::iterator it = resources.begin(); it != resources.end(); it++)
            (*it).print();
        if ((*PCBS).Quanbu()->size() > 0)
        {
            cout << "进程名" << " " << "进程状态" << " " << "时间" << " " << "剩余运行时间" << " " << "需要资源" << endl;
            for (int i = 0; i < (*PCBS).Quanbu()->size(); i++)
            {
                cout << (*PCBS).quanbu[i].getName() << "\t" << (*PCBS).quanbu[i].getState() << "\t" << "  "
                    << (*PCBS).quanbu[i].getArrivetime() << "\t" << (*PCBS).quanbu[i].getRemaintime() << "\t" << "  ";
                for (int j = 0; j < (*PCBS).quanbu[i].getSize(); ++j)
                {
                    cout << (*(*PCBS).quanbu[i].Resources[j]).getname() << " ";
                }
                cout << endl;
            }
        }

        cout << "添加进程? 0.no  1.yes" << endl;
        cin >> flag;
        if (flag)
        {
            string Name;
            int Arrivetime;
            int Servetime;
            cout << "  进程名:"; cin >> Name;
            cout << "到达时间:"; cin >> Arrivetime;
            cout << "执行时间:"; cin >> Servetime;
            PCB* pcb = new PCB(Name, Arrivetime, Servetime);
            PCBS->addquanbu(*pcb);
            //(*PCBS).print();
            delete(pcb);
            int flag2 = 1;
            while (flag2)
            {
                cout << "给这个进程添加资源? 0.no  1.yes" << endl;
                cin >> flag2;
                if (flag2)
                {
                    string str;
                    cout << "输入资源名:"; cin >> str;
                    for (vector<resource>::iterator it = resources.begin(); it != resources.end(); it++)
                        if ((*it).getname() == str)
                        {
                            (*(*PCBS).Quanbu()).back().addresource(&(*it));
                            break;
                        }

                }
            }
            //(*PCBS).print();
        }
    }
}

void tfcfs()
{
    vector<resource>resources;
    resources.reserve(10000);
    addsignal(resources);

    ALLPCB PCBS;
    addpcb(&PCBS, resources);

    int time = 0;
    while (!PCBS.over())
    {
        PCBS.waitToready();
        system("CLS");
        cout << "当前时间:" << time << endl;
        cout << "资源名" << " " << "资源数量" << endl;
        for (vector<resource>::iterator it = resources.begin(); it != resources.end(); it++)
            (*it).print();
        cout << "进程名" << " " << "进程状态" << " " << "时间" << " " << "剩余运行时间" << " " << "需要资源" << endl;
        for (int i = 0; i < PCBS.Quanbu()->size(); i++)
        {
            cout << PCBS.quanbu[i].getName() << "\t" << PCBS.quanbu[i].getState() << "\t" << "  "
                << PCBS.quanbu[i].getArrivetime() << "\t" << PCBS.quanbu[i].getRemaintime() << "\t" << "  ";
            for (int j = 0; j < PCBS.quanbu[i].getSize(); ++j)
            {
                cout << (*PCBS.quanbu[i].Resources[j]).getname() << " ";
            }
            cout << endl;
        }
        if (!PCBS.Ready().empty())
        {
            PCB* pcb = NULL;
            int Min = 1000;
            for (vector<PCB*>::iterator it = PCBS.ready.begin(); it != PCBS.ready.end(); it++)
                if ((**it).getArrivetime() < Min)
                {
                    Min = (**it).getArrivetime();
                    pcb = (*it);
                }
            if (pcb)
                PCBS.zhixing(pcb);//它会记录并删除就绪队列的该进程
            (*pcb).setRemaintime(0);
            PCBS.finish();//它会释放该进程所占用的资源
            time = time + (*pcb).getservicetime();
            (*pcb).setFinishitime(time);
        }
        else
        {
            ++time;
        }
        PCBS.willTowait(time);
        system("PAUSE");
    }
    system("CLS");
    cout << "当前时间:" << time << endl;
    cout << "资源名" << " " << "资源数量" << endl;
    for (vector<resource>::iterator it = resources.begin(); it != resources.end(); it++)
        (*it).print();
    cout << "进程名" << " " << "进程状态" << " " << "时间" << " " << "剩余运行时间" << " " << "需要资源" << endl;
    for (int i = 0; i < PCBS.Quanbu()->size(); i++)
    {
        cout << PCBS.quanbu[i].getName() << "\t" << PCBS.quanbu[i].getState() << "\t" << "  "
            << PCBS.quanbu[i].getArrivetime() << "\t" << PCBS.quanbu[i].getRemaintime() << "\t" << "  ";
        for (int j = 0; j < PCBS.quanbu[i].getSize(); ++j)
        {
            cout << (*PCBS.quanbu[i].Resources[j]).getname() << " ";
        }
        cout << endl;
    }
    cout << "执行顺序" << endl;
    PCBS.print4();
}