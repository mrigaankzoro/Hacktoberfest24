// https://www.naukri.com/code360/problems/rat-in-a-maze_1215030

#include <bits/stdc++.h>

using namespace std;

void recurseCall(int n, int row, int col, string str, vector<vector<int>> &mat, vector<string> &a)
{
    if (row == n - 1 && col == n - 1)
    {
        a.push_back(str);
        return;
    }

    mat[row][col] = 9;
    // LOOK SOUTH
    if (row + 1 <= n - 1 && mat[row + 1][col] == 1)
    {
        mat[row + 1][col] = 9;
        recurseCall(n, row + 1, col, str + 'D', mat, a);
        mat[row + 1][col] = 1;
    }

    // LOOK LEFT
    if (col - 1 >= 0 && mat[row][col - 1] == 1)
    {
        mat[row][col - 1] = 9;
        recurseCall(n, row, col - 1, str + 'L', mat, a);
        mat[row][col - 1] = 1;
    }

    // LOOK RIGHT
    if (col + 1 <= n - 1 && mat[row][col + 1] == 1)
    {
        mat[row][col + 1] = 9;
        recurseCall(n, row, col + 1, str + 'R', mat, a);
        mat[row][col + 1] = 1;
    }

    // LOOK NORTH
    if (row - 1 >= 0 && mat[row - 1][col] == 1)
    {
        mat[row - 1][col] = 9;
        recurseCall(n, row - 1, col, str + 'U', mat, a);
        mat[row - 1][col] = 1;
    }
    mat[row][col] = 1;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    // Write your code here.
    vector<string> a;
    string s;

    if (arr[0][0] == 1)
        recurseCall(n, 0, 0, s, arr, a);

    return a;
}

int main()
{
    // vector<vector<int>> a = {
    //     {1, 0, 0, 0},
    //     {1, 1, 0, 1},
    //     {1, 1, 0, 0},
    //     {0, 1, 1, 1},
    // };
    // vector<vector<int>> a = {{1, 0}, {1, 1}};

    // vector<vector<int>> a = {{1, 1}, {0, 1}};
    // vector<vector<int>> a = {{1, 0}, {1, 0}};

    // vector<vector<int>> a = {{1, 1, 1},
    //                          {1, 0, 1},
    //                          {1, 1, 1}};

    vector<vector<int>> a = {{1, 1, 1, 0}, {1, 1, 1, 0}, {1, 0, 1, 1}, {0, 0, 0, 1}};

    vector<string> ans;
    ans = searchMaze(a, a.size());
    // cout << endl
    //      << endl
    //      << endl
    //      << endl;
    for (auto i : ans)
    {
        cout << i << endl;
    }
}