#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> base, vector<int> newBox){
    if(newBox[0] <= base[0] && newBox[1] <= base[1] &&newBox[2] <= base[2])
        return true;
    
    else    
        return false;
}
int solveSO(int n, vector<vector<int>>& a){
    vector<int> currRow(n+1,0);
    vector<int> nextRow(n+1,0);

    for(int curr = n-1; curr>=0; curr--){
        for(int prev = curr-1; prev>=-1; prev--){
            //include
            int take = 0;
            if(prev == -1 || check(a[curr] , a[prev])){
                take = a[curr][2] + nextRow[curr+1];
            }

            // exclude
            int notTake = 0 + nextRow[prev+1];
            currRow[prev+1] = max(take,notTake);
        }
        nextRow = currRow;
    }
    return nextRow[-1+1];
}
int maxWeight(vector<vector<int>> & cuboid){
    //step1: sort all dimensions for every cuboid
    for(auto &a:cuboid){
        sort(a.begin(), a.end());
    }

    //step2: sort all cuboids basis on width or leength
    sort(cuboid.begin(),cuboid.end());

    //step3: use Longest increaasing subproblem logic for height 
    return solveSO(cuboid.size(), cuboid);
}

int main(){
    
    return 0;
}