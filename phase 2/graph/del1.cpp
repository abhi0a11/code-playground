#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(int x1, int y1, int x2, int y2, int x3, int y3, int a, int b)
{
    double abp = abs(x1 * (y2 - b) + x2 * (b - y1) + a * (y1 - y2)) / 2.0;
    double acp = abs(x1 * (y3 - b) + x3 * (b - y1) + a * (y1 - y3)) / 2.0;
    double bcp = abs(x2 * (y3 - b) + x3 * (b - y2) + a * (y2 - y3)) / 2.0;
    double area = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;

    return area == acp + abp + bcp;
}
int solve(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp, int xq, int yq)
{
    int ab = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    int bc = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
    int ac = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);

    // cout << ab << " " << bc << " " << ac << " ";
    if (ab + bc <= ac || ab + ac <= bc || ac + bc <= ab)
    {

        return 0;
    }

    if (check(x1, y1, x2, y2, x3, y3, xp, yp) && !check(x1, y1, x2, y2, x3, y3, xq, yq))
        return 1;
    if (!check(x1, y1, x2, y2, x3, y3, xp, yp) && check(x1, y1, x2, y2, x3, y3, xq, yq))
        return 2;
    if (check(x1, y1, x2, y2, x3, y3, xp, yp) && check(x1, y1, x2, y2, x3, y3, xq, yq))
        return 3;
    // if (!check(x1, y1, x2, y2, x3, y3, xp, yp) && !check(x1, y1, x2, y2, x3, y3, xq, yq))
    return 4;
}
int main()
{
    cout << solve(3, 1, 7, 1, 5, 5,3,1,0,0);
    return 0;
}
