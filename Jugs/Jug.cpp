#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
#include <map>

#include "Jug.h"

using namespace std;

Jug::Jug(int ca, int cb, int n, int cfa, int cfb, int cea, int ceb, int cpab, int cpba)
{
    Ca = ca;
    Cb = cb;
    N = n;
    cfA = cfa;
    cfB = cfb;
    ceA = cea;
    ceB = ceb;
    cpAB = cpab;
    cpBA = cpba;
}

int h(int a,int b) { return a*1001+b; }

int Jug::solve(string &solution)
{
    solution.clear();
    if(Ca<=0||Cb<=0||N<=0||cfA<=0||cfB<=0||ceA<=0||ceB<=0||cpAB<=0||cpBA<=0)
        return -1;
    if(Ca > Cb || N > Cb ||Cb > 1000)
        return -1;

    map<int,int>d, p, q;

    queue<int>Q;

    Q.push(0);

    int u, v, a, b, t;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        a = u/1001;
        b = u%1001;
        //cout << a << " " << b << endl;
        if(a < Ca)
        {
            v = h(Ca,b);
            //cout << "v=" << v << "d[v]=" << d[v] << endl;
            //cout << "d[u]=" << d[u] << "cfA=" << cfA << endl;
            if((v && !d[v]) || d[v] > d[u]+cfA)
            {
                d[v] = d[u]+cfA;
                p[v] = u;
                q[v] = 1;
                Q.push(v);
                //cout << "1:" << v << endl;
            }
        }
        if(b < Cb)
        {
            v = h(a,Cb);
            if((v && !d[v]) || d[v] > d[u]+cfB)
            {
                d[v] = d[u]+cfB;
                p[v] = u;
                q[v] = 2;
                Q.push(v);
                //cout << "2:" << v << endl;
            }
        }
        if(a > 0)
        {
            v = h(0,b);
            if((v && !d[v]) || d[v] > d[u]+ceA)
            {
                d[v] = d[u]+ceA;
                p[v] = u;
                q[v] = 3;
                Q.push(v);
                //cout << "3:" << v << endl;
            }
        }
        if(b > 0)
        {
            v = h(a,0);
            if((v && !d[v]) || d[v] > d[u]+ceB)
            {
                d[v] = d[u]+ceB;
                p[v] = u;
                q[v] = 4;
                Q.push(v);
                //cout << "4:" << v << endl;
            }
        }
        if(a > 0 && b < Cb)
        {
            t = min(a, Cb-b);
            //cout << "t=" << t << endl;
            v = h(a-t, b+t);
            //cout << a-t << " " << b+t << " " << v <<endl;
            if((v && !d[v]) || d[v] > d[u]+cpAB)
            {
                d[v] = d[u]+cpAB;
                p[v] = u;
                q[v] = 5;
                Q.push(v);
                //cout << "5:" << v << endl;
            }
        }
        if(a < Ca && b > 0)
        {
            t = min(Ca-a, b);
            v = h(a+t, b-t);
            if((v && !d[v]) || d[v] > d[u]+cpBA)
            {
                d[v] = d[u]+cpBA;
                p[v] = u;
                q[v] = 6;
                Q.push(v);
                //cout << "6:" << v << endl;
            }
        }
    }

    //cout << "d[N]=" << d[N] << endl;

    if(!d[N])
        return 0;

    stack<int>S;
    u = N;
    while(u)
    {
        //cout << "u=" << u << ",p[u]=" << p[u] << ",q[u]" << q[u] <<endl;
        S.push(q[u]);
        u = p[u];
    }
    while(!S.empty())
    {
        u = S.top();
        S.pop();
        switch(u)
        {
            case 1:
                solution.append("fill A\n");break;
            case 2:
                solution.append("fill B\n");break;
            case 3:
                solution.append("empty A\n");break;
            case 4:
                solution.append("empty B\n");break;
            case 5:
                solution.append("pour A B\n");break;
            case 6:
                solution.append("pour B A\n");break;
        }
    }
    solution.append("success ");
    u = d[N];
    while(u)
    {
        S.push(u%10);
        u/=10;
    }
    while(!S.empty())
    {
        u = S.top();
        S.pop();
        solution.append(1,'0'+u);
    }
    //cout << solution;
    return 1;
}
