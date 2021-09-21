/*OSHN*/
#include <bits/stdc++.h>
#include "CopyConstAssiOpTest.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    CopyConstAssiOpTest a1(10), a2(12), a3(a1), a4;
    a4 = a2;
    cout << a1 << a2 << a3 << a4;



    return 0;
}
