#include <bits/stdc++.h>

using namespace std;
int findSize(int n)
{
    int i = 0;
    while (1)
    {
        if (i * (i + 1) == 2 * n)
        {
            return i;
        }
        else if (i * (i + 1) > 2 * n)
        {
            break;
        }
        i++;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;

    int size = findSize(n);
    if (size == -1)
    {
        cout << " Not Possible ";
        return 0;
    }
    vector<vector<int>> ans(size, vector<int>(size, 0));
    

    int cnt = 1;
    bool upTOdowm = 1;
    int rowSize = size;
    for (int col = 0; col < size; col++)
    {
        if (upTOdowm)
        {
            int row = 0;
            row += size - rowSize;
            for (row; row < size; row++)
            {
                ans[row][col] = cnt;
                cnt++;
            }
        }
        else{
            int k = rowSize;
            int row = size-1;
            while(k>0){
                ans[row][col] = cnt;
                cnt++;
                row--;
                k--;
            }
        }
        rowSize--;
        upTOdowm = !upTOdowm;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}