#include <iostream>
#include <vector>
#include"ALLPCB.h"
#include"hpf.h"
#include"fcfs.h"
#include"sf.h"
#include"hrn.h"
#include"tian.h"
#include"rr.h"
using namespace std;

int main()
{
    cout << "1.RR 2.FCFSÂí 3.HPF 4.SF 5.HRN 6.FCFSÌï" << endl;
    int i;
    cin >> i;
    switch (i)
    {
    case 1:RRmain();
    case 2:fcfs();
    case 3:hpf();
    case 4:sf();
    case 5:hrn();
    case 6:tfcfs();
    default:
        break;
    }

    return 0;
}

