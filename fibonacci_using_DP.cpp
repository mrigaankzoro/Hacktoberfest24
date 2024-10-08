#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Github: https://github.com/imgurujeet

vector<int> dp;

int f(int n)
{
    if (n == 0 or n == 1)
        return n;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = f(n - 1) + f(n - 2);
}

int main()
{
    int n;
    cin >> n;
    dp.resize(n + 1, -1);
    cout << f(n) << "\n";
    return 0;
}