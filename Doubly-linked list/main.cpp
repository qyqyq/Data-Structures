#include <iostream>
#include "IntList.h"

using namespace std;

int main()
{
    IntList demo;
    for(int i=0;i<100;++i){
        demo.push_back(i);
    }
    demo.pop_front();
    demo.pop_front();
    cout<<demo<<endl;
    return 0;
}
