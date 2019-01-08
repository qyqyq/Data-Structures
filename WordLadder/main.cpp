#include<bits/stdc++.h>
#include"WordLadder.h"
using namespace std;

int main()
{

    WordLadder* wl = new WordLadder("dictionary.txt");
    wl->outputLadder("udder","udder","output.txt");

    return 0;
}
