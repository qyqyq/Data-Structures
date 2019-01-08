#include <iostream>

#include "Jug.h"

using namespace std;

int main()
{
    string solution;
    Jug head(3, 5, 4, 1, 2, 3, 4, 5, 6);
    if (head.solve(solution) != 1)
    {
        cout << "Error 3" << endl;
    }
    cout << solution << endl << endl;
    cout <<"fill A\npour A B\nfill A\npour A B\nempty B\npour A B\nfill A\npour A B\nsuccess 8"<<endl;
}
