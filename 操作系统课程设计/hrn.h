
#include<iostream>
#include "ALLPCB.h"

using namespace std;

void hrn()
{
	ALLPCB allp;
	vector<resource> allr;
	allr.reserve(30000);
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
	cout << "请输入进程资源关系(以0结尾):" << endl;
	cout << "进程名称" << "\t" << "资源名称" << endl;
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
		//以下为根据时间初始化，确定最新的就绪队列
		allp.willTowait(time);
		allp.waitToready();

		//以下为运行过程输出
		cout << "当前时间:" << time << endl;
		cout << "资源名" << "\t" << "资源数量" << endl;
		for (int i = 0; i < allr.size(); i++)
		{
			cout << allr.at(i).getname() << "\t" << allr.at(i).getsignal() << endl;
		}
		cout << "进程名" << "\t" << "进程状态" << "\t" << "到达时间" << "\t" << "运行时间" << "\t"
			<< "剩余运行时间" << "\t" << "R" << "\t" << "运行需要资源" << endl;
		for (int i = 0; i < allp.Quanbu()->size(); i++)
		{
			cout << allp.Quanbu()->at(i).getName() << "\t"
				<< allp.Quanbu()->at(i).getState() << "\t"
				<< allp.Quanbu()->at(i).getArrivetime() << "\t"
				<< allp.Quanbu()->at(i).getservicetime() << "\t"
				<< allp.Quanbu()->at(i).getRemaintime() << "\t";
			if (time < allp.Quanbu()->at(i).getArrivetime())
			{
				cout << "还未到" << "\t";
			}
			else
			{
				cout << 1 + time - allp.Quanbu()->at(i).getArrivetime() / allp.Quanbu()->at(i).getservicetime() << "\t";
			}

			for (int j = 0; j < allp.Quanbu()->at(i).getSize(); j++)
			{
				cout << allp.Quanbu()->at(i).Resources[j]->getname() << " ";
			}
			cout << endl;

		}
		//以下为进程的hrn算法。
		PCB* pcb = NULL;
		int max = 0;
		if (allp.Ready().size() != 0)
		{
			for (int i = 0; i < allp.Ready().size(); i++)
			{
				if (allp.Ready().at(i)->getservicetime() > max)
				{
					max = 1 + time - allp.Quanbu()->at(i).getArrivetime() / allp.Quanbu()->at(i).getservicetime();
					pcb = allp.Ready().at(i);
				}
				allp.zhixing(pcb);
			}
		}

		//调度完成后开始执行
		time += 1;
		if (allp.PCBing() != NULL)
		{
			allp.PCBing()->setRemaintime(allp.PCBing()->getRemaintime() - 1);
			//执行完后进行判断，判断其是否已经执行完毕
			if (allp.PCBing()->getRemaintime() == 0) //执行完毕
			{
				allp.PCBing()->setFinishitime(time);
				allp.finish();

			}
		}
		string name;
		cin >> name;



	}
	cout << "当前时间:" << time << endl;
	cout << "资源名" << "\t" << "资源数量" << endl;
	for (int i = 0; i < allr.size(); i++)
	{
		cout << allr.at(i).getname() << "\t" << allr.at(i).getsignal() << endl;
	}
	cout << "进程名" << "\t" << "进程状态" << "\t" << "到达时间" << "\t" << "运行时间" << "\t"
		<< "剩余运行时间" << "\t" << "R" << "\t" << "运行需要资源" << endl;
	for (int i = 0; i < allp.Quanbu()->size(); i++)
	{
		cout << allp.Quanbu()->at(i).getName() << "\t"
			<< allp.Quanbu()->at(i).getState() << "\t"
			<< allp.Quanbu()->at(i).getArrivetime() << "\t"
			<< allp.Quanbu()->at(i).getservicetime() << "\t"
			<< allp.Quanbu()->at(i).getRemaintime() << "\t"
			<< "运行完毕" << "\t";

		for (int j = 0; j < allp.Quanbu()->at(i).getSize(); j++)
		{
			cout << allp.Quanbu()->at(i).Resources[j]->getname() << " ";
		}
		cout << endl;

	}







}
