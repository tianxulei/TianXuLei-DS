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
        cout << "�����Դ? 0.no  1.yes" << endl;
        cin >> flag;
        if (flag)
        {
            string Name;
            int Signal;
            cout << "��Դ����:"; cin >> Name;
            cout << "  �ź���:"; cin >> Signal;
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
            cout << "������" << " " << "����״̬" << " " << "ʱ��" << " " << "ʣ������ʱ��" << " " << "��Ҫ��Դ" << endl;
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

        cout << "��ӽ���? 0.no  1.yes" << endl;
        cin >> flag;
        if (flag)
        {
            string Name;
            int Arrivetime;
            int Servetime;
            cout << "  ������:"; cin >> Name;
            cout << "����ʱ��:"; cin >> Arrivetime;
            cout << "ִ��ʱ��:"; cin >> Servetime;
            PCB* pcb = new PCB(Name, Arrivetime, Servetime);
            PCBS->addquanbu(*pcb);
            //(*PCBS).print();
            delete(pcb);
            int flag2 = 1;
            while (flag2)
            {
                cout << "��������������Դ? 0.no  1.yes" << endl;
                cin >> flag2;
                if (flag2)
                {
                    string str;
                    cout << "������Դ��:"; cin >> str;
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
        cout << "��ǰʱ��:" << time << endl;
        cout << "��Դ��" << " " << "��Դ����" << endl;
        for (vector<resource>::iterator it = resources.begin(); it != resources.end(); it++)
            (*it).print();
        cout << "������" << " " << "����״̬" << " " << "ʱ��" << " " << "ʣ������ʱ��" << " " << "��Ҫ��Դ" << endl;
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
                PCBS.zhixing(pcb);//�����¼��ɾ���������еĸý���
            (*pcb).setRemaintime(0);
            PCBS.finish();//�����ͷŸý�����ռ�õ���Դ
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
    cout << "��ǰʱ��:" << time << endl;
    cout << "��Դ��" << " " << "��Դ����" << endl;
    for (vector<resource>::iterator it = resources.begin(); it != resources.end(); it++)
        (*it).print();
    cout << "������" << " " << "����״̬" << " " << "ʱ��" << " " << "ʣ������ʱ��" << " " << "��Ҫ��Դ" << endl;
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
    cout << "ִ��˳��" << endl;
    PCBS.print4();
}