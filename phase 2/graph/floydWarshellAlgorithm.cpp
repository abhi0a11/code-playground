#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// multi sorce shortest path algorithm
void floydWarshall(vector<vector<int>> &grid)
{
    int n = grid.size();

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
            }
        }
    }
}
int main()
{
    vector<vector<int>> grid = {{0, 1, 43}, {1, 0, 6}, {INT_MAX, INT_MAX, 0}};

    floydWarshall(grid);
    return 0;
}