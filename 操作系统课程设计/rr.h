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
    cout << "�����봴��������:";
    cin >> n;
    cout << "��������" << "\t" << "����ʱ��" << "\t" << "����ʱ��" << endl;
    for (int i = 0; i < n; i++)
    {
        string name;
        int arr;
        int ser;
        cin >> name >> arr >> ser;
        PCB pcb(name, arr, ser);
        allp.addquanbu(pcb);
    }
    cout << "��������Դ��:";
    cin >> n;
    cout << "��Դ����" << "\t" << "�ź���" << endl;
    for (int i = 0; i < n; i++)
    {
        string name;
        int signal;
        cin >> name >> signal;
        resource re(name, signal);
        allr.push_back(re);
    }
    cout << "�����������Դ��ϵ(��0��β):";
    cout << "��������" << "��Դ����" << endl;
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
    cout << "�ڱ���ʱ��Ƭ���̵����У�������ɵ�ʱ��Ƭ��С���£�" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << Time[i] << "   ";
    }
    cout << endl;
    cout << "���̳�ʼ����" << endl;
    cout << "��ʼ�����" << endl;
    allp.waitToready();
    cout << "ȫ��"; allp.print0(); cout << endl;
    cout << "�ȴ�"; allp.print1(); cout << endl;
    cout << "����"; allp.print2(); cout << endl;
    cout << "δ��"; allp.print3(); cout << endl;
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
            cout << "��ǰʱ��Ϊ" << ttime << endl;
            cout << "��ǰ���������н�����ĿΪ" << k << endl;
            int t = pcb->getRemaintime();
            if (t <= Time[i])
            {
                pcb->go(Time[i]);
                pcb->setState("C");
                cout << "��ǰִ�н���Ϊ��" << endl;
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
                cout << "��ǰִ�н���Ϊ��" << endl;
                pcb->shownormal();
                cout << endl;
                ttime += Time[i];

            }
            cout << "��ǰ���н������Ϊ��" << endl;
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
