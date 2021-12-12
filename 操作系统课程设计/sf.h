//#ifndef HPF_H_INCLUDED
//#define HPF_H_INCLUDED
#pragma once
#include<iostream>
#include "ALLPCB.h"

using namespace std;

void sf()
{
	ALLPCB allp;
	vector<resource> allr;
	allr.reserve(30000);
	int n;
	cout << "�����봴��������:";
	cin >> n;
	cout << "��������" << "\t" << "����ʱ��" << "\t" << "����ʱ��" << "\t" << endl;
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
	cout << "�����������Դ��ϵ(��0��β):" << endl;
	cout << "��������" << "\t" << "��Դ����" << endl;
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
	int time = 0;
	while (!allp.over())
	{	
		allp.willTowait(time);
		//����Ϊ���й������
		cout << "��ǰʱ��:" << time << endl;
		cout << "��Դ��" << "\t" << "��Դ����" << endl;
		for (int i = 0; i < allr.size(); i++)
		{
			cout << allr.at(i).getname() << "\t" << allr.at(i).getsignal() << endl;
		}
		cout << "������" << "\t" << "����״̬" << "\t" << "����ʱ��" << "\t" << "����ʱ��" << "\t"
			<< "ʣ������ʱ��" << "\t" << "������Ҫ��Դ" << endl;
		for (int i = 0; i < allp.Quanbu()->size(); i++)
		{
			cout << allp.Quanbu()->at(i).getName() << "\t"
				<< allp.Quanbu()->at(i).getState() << "\t"
				<< allp.Quanbu()->at(i).getArrivetime() << "\t"
				<< allp.Quanbu()->at(i).getservicetime() << "\t"
				<< allp.Quanbu()->at(i).getRemaintime() << "\t";

			for (int j = 0; j < allp.Quanbu()->at(i).getSize(); j++)
			{
				cout << allp.Quanbu()->at(i).Resources[j]->getname() << " ";
			}
			cout << endl;

		}
		//��ʱ�������㷨
		int min = 100;
		PCB* pcb = NULL;
		if (allp.Quanbu()->size() != 0)
		{
			for (int i = 0; i < allp.Ready().size(); i++)
			{
				if (allp.Ready().at(i)->getservicetime() < min)
				{
					min = allp.Ready().at(i)->getservicetime();
					pcb = allp.Ready().at(i);
				}
			}
			allp.zhixing(pcb);
		}
		//����ִ��
		time += 1;
		if (allp.PCBing() != NULL)
		{
			allp.PCBing()->setRemaintime(allp.PCBing()->getRemaintime() - 1);
			//ִ���������жϣ��ж����Ƿ��Ѿ�ִ�����
			if (allp.PCBing()->getRemaintime() == 0) //ִ�����
			{
				allp.PCBing()->setFinishitime(time);
				allp.finish();

			}
		}
		string name;
		cin >> name;
	}
	cout << "��ǰʱ��:" << time << endl;
	cout << "��Դ��" << "\t" << "��Դ����" << endl;
	for (int i = 0; i < allr.size(); i++)
	{
		cout << allr.at(i).getname() << "\t" << allr.at(i).getsignal() << endl;
	}
	cout << "������" << "\t" << "����״̬" << "\t" << "����ʱ��" << "\t" << "����ʱ��" << "\t"
		<< "ʣ������ʱ��" << "\t" << "������" << "\t" << "������Ҫ��Դ" << endl;
	for (int i = 0; i < allp.Quanbu()->size(); i++)
	{
		cout << allp.Quanbu()->at(i).getName() << "\t"
			<< allp.Quanbu()->at(i).getState() << "\t"
			<< allp.Quanbu()->at(i).getArrivetime() << "\t"
			<< allp.Quanbu()->at(i).getservicetime() << "\t"
			<< allp.Quanbu()->at(i).getRemaintime() << "\t"
			<< allp.Quanbu()->at(i).getPrio() << "\t";

		for (int j = 0; j < allp.Quanbu()->at(i).getSize(); j++)
		{
			cout << allp.Quanbu()->at(i).Resources[j]->getname() << " ";
		}
		cout << endl;

	}






}

//#endif HPF_H_INCLUDED
#pragma once
