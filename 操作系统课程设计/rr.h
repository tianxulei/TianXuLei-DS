#ifndef RR_H_INCLUDED
#define RR_H_INCLUDED
#include <iostream>
#include<vector>
#include"ALLPCB.h"
#include"stdlib.h"
#include"time.h"
int RRmain();
int RRmain()
{
    int Time[20];
    ALLPCB allp;
    vector<resource> allr;
    int n;
    cout << "请输入创建进程数:";
    cin >> n;
    cout << "进程名称" << "\t" << "到达时间" << "\t" << "运行时间" << endl;
    for (int i = 0; i < n; i++)
    {
        string name;
        int arr;
        int ser;
        cin >> name >> arr >> ser;
        PCB pcb(name, arr, ser);
        allp.addquanbu(pcb);
    }
    cout << "请输入资源数:";
    cin >> n;
    cout << "资源名称" << "\t" << "信号量" << endl;
    for (int i = 0; i < n; i++)
    {
        string name;
        int signal;
        cin >> name >> signal;
        resource re(name, signal);
        allr.push_back(re);
    }
    cout << "请输入进程资源关系(以0结尾):";
    cout << "进程名称" << "资源名称" << endl;
    for (int i = 0; i < allp.Quanbu()->size(); i++)
    {
        cout << allp.Quanbu()->at(i).getName() << "\t";
        string name;
        cin >> name;
        while (name != "0")
        {
            for (int j = 0; j < allr.size(); j++)
            {
                if (allr.at(j).getname() == name)
                {
                    allp.Quanbu()->at(i).addresource(&(allr.at(j)));
                    break;
                }
            }
            cin >> name;
        }
    }
    srand((unsigned)time(NULL));
    for (int i = 0; i < 20; i++)
    {
        Time[i] = rand() % 5 + 1;
    }
    cout << "在本次时间片进程调度中，随机生成的时间片大小如下：" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << Time[i] << "   ";
    }
    cout << endl;
    cout << "进程初始化中" << endl;
    cout << "初始化完毕" << endl;
    allp.waitToready();
    cout << "全部"; allp.print0(); cout << endl;
    cout << "等待"; allp.print1(); cout << endl;
    cout << "就绪"; allp.print2(); cout << endl;
    cout << "未到"; allp.print3(); cout << endl;
    int ttime = 0;
    int i = 0;
    while (!allp.over())
    {
        allp.waitToready();
        if (!allp.Ready().empty())
        {
            allp.waitToready();
            int k = allp.Ready().size();
            int n = i % k;
            PCB* pcb = allp.Ready().at(n);
            cout << "当前时间为" << ttime << endl;
            cout << "当前就绪队列中进程数目为" << k << endl;
            int t = pcb->getRemaintime();
            if (t <= Time[i])
            {
                pcb->go(Time[i]);
                pcb->setState("C");
                cout << "当前执行进程为：" << endl;
                pcb->shownormal();
                cout << endl;
                ttime += t;
                pcb->setFinishitime(ttime);
                allp.zhixing(pcb);
                allp.finish();
            }
            else
            {
                pcb->go(Time[i]);
                pcb->setState("T");
                cout << "当前执行进程为：" << endl;
                pcb->shownormal();
                cout << endl;
                ttime += Time[i];

            }
            cout << "当前所有进程情况为：" << endl;
            allp.printt();
            allp.willTowait(ttime);
            i++;
        }
        else
        {
            ttime += 1;
        }
        system("pause");

    }
    return 0;
}


#endif // RR_H_INCLUDED
