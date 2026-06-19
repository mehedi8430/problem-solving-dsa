// problem link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/Y

#include <bits/stdc++.h>
using namespace std;

int ways(int s, int e)
{
    // Reached destination
    if (s == e)
        return 1;

    // Went beyond destination
    if (s > e)
        return 0;

    // Try taking 1, 2, and 3 steps
    return ways(s + 1, e) + ways(s + 2, e) + ways(s + 3, e);
}

int main()
{
    int s, e;
    cin >> s >> e;

    cout << ways(s, e);

    return 0;
}