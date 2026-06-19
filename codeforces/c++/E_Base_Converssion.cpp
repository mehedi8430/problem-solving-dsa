// problem link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/E

#include <bits/stdc++.h>
using namespace std;

void print_binary(int n)
{
    if (n == 0)
        return;

    print_binary(n / 2);
    cout << n % 2;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        print_binary(n);
        cout << endl;
    }

    return 0;
}