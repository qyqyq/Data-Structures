#include "Heap.h"
#include <iostream>
#include <algorithm>

using namespace std;

#define f ((i-1)>>1)
#define l ((i<<1)+1)
#define r ((i<<1)+2)

Heap::Heap()
{
    //PrintJob *arr = new PrintJob*[MAX_HEAP_SIZE];
    numItems = 0;
}
void Heap::enqueue(PrintJob* cur)
{
    if(numItems == MAX_HEAP_SIZE)
        return;
    int i = numItems;
    arr[numItems++] = cur;
    while(i>0)
    {
        if(arr[i]->getPriority() > arr[f]->getPriority())
        {
            swap(arr[i],arr[f]);
            i=f;
        }
        else
            break;
    }
}
void Heap::dequeue()
{
    if(numItems == 0)
        return;
    arr[0]=arr[--numItems];
    int i = 0, j;
    while(i < numItems)
    {
        if(l >= numItems)
            break;
        if(r < numItems)
        {
            if(arr[l]->getPriority() > arr[r]->getPriority())
                j = l;
            else j = r;
        }
        else
            j = l;
        if(arr[j]->getPriority() > arr[i]->getPriority())
        {
            swap(arr[i],arr[j]);
            i = j;
        }
        else
            break;
    }
}
PrintJob* Heap::highest()
{
    return numItems == 0?nullptr:arr[0];
}
void Heap::print()
{
    if(numItems == 0)
        return;
    PrintJob* tmp = highest();
    cout << "Priority: " << tmp->getPriority() << ", Job Number: " <<tmp->getJobNumber() << ", Number of Pages: " << tmp->getPages() << endl;
}
