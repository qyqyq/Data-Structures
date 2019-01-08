#include "WordLadder.h"
#include<bits/stdc++.h>
using namespace std;

WordLadder::WordLadder(const string &inputFile)
{
    ifstream inFS;

        inFS.open(inputFile);
        if(!inFS.is_open())
        {
            cout << "error" << endl;
            return;
        }
        string temp;
        while(!inFS.eof()){
            inFS >> temp;
            if(temp.size() != 5)
            {
                cout << "error" << endl;
                return;
            }
            dict.push_back(temp);
        }
        inFS.close();
}

void WordLadder::outputLadder(const string &start, const string &END, const string &outputFile)
{
    list<string>::iterator it;
    int fg1=1,fg2=1;
    for(it=dict.begin();it!=dict.end();it++)
    {
        if(*it == start) fg1=0;
        if(*it == END) fg2=0;
    }
    if(fg1 || fg2){
        cout << "error" <<endl;
        return;
    }
    if(start == END)
    {
        ofstream ofFS;
        ofFS.open(outputFile);
        ofFS << start << endl;
        ofFS.close();
        return;
    }

    stack<string>S,T;
    queue< stack<string> >Q;
    string p,q;
    S.push(start);
    Q.push(S);
    while(!Q.empty())
    {
        S=Q.front();
        Q.pop();
        q=S.top();
        for(it=dict.begin();it!=dict.end();)
        {
            p=*it;
            int cnt=0;
            for(int i=0;i<5;i++)
                if(p[i]!=q[i]) cnt++;
            if(cnt == 1)
            {
                if(p == END)
                {
                    //cout<<"a"<<endl;
                    ofstream ofFS;
                    ofFS.open(outputFile);
                    while(!T.empty())
                        T.pop();
                    T.push(p);
                    while(!S.empty())
                    {
                        T.push(S.top());
                        S.pop();
                    }
                    while(!T.empty())
                    {
                        ofFS << T.top() << endl;
                        T.pop();
                    }
                    ofFS.close();
                    return;

                }
                T=S;
                //cout<<"*"<<endl;
                T.push(p);
                //cout<<"**"<<endl;
                Q.push(T);
                //cout<<"***"<<endl;
                it=dict.erase(it);
                //cout<<"****"<<endl;
            }
            else it++;
        }
    }
    ofstream ofFS;
    ofFS.open(outputFile);
    ofFS << "No Word Ladder Found." <<endl;
    ofFS.close();
}
