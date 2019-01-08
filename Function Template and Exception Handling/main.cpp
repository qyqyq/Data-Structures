#include<bits/stdc++.h>
using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
    T minval = vals[index];
    unsigned minidx = index;
    for(;index < vals.size();index++)
    {
        if(vals[index] < minval)
        {
            minval = vals[index];
            minidx = index;
        }
    }
    return minidx;
}

template<typename T>
void selection_sort(vector<T> &vals)
{
    unsigned index;
    for(index = 0;index < vals.size();index++)
    {
        swap(vals[index],vals[min_index(vals,index)]);
    }
}

template<typename T>
T getElement(vector<T> vals, int index)
{
    if(index < 0 || index > (int)vals.size()){
        throw out_of_range("out of range exception occured");
    }
    return vals[index];
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main()
{
    vector<double> vs={4.7,2,1.5,9.0,5.3};
    selection_sort(vs);
    for(int i=0;i<vs.size();++i){
        cout<<vs[i]<<" "<<endl;
    }
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         try{
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
         }
         catch(const std::out_of_range& excpt){
             cout << excpt.what() << endl;
         }
    }
    return 0;
}
