#pragma once
#include<string>
using namespace std;

class resource
{
public:
    resource(string Name, int Signal);
    void P();
    void V();
    string getname();
    int getsignal();
    void print() { cout << "Name is:" << name << "  Signal is:" << signal << endl; }
private:
    string name;
    int signal;//
};

//#endif // RESOURCE_H_INCLUDED

resource::resource(string Name, int Signal)
{
    name = Name;
    signal = Signal;
}

void resource::P()
{
    --signal;
}

void resource::V()
{
    ++signal;
}

string resource::getname()
{
    return name;
}

int resource::getsignal()
{
    return signal;
}
