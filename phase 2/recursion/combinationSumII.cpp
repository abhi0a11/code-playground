#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//no repeated solutions
// time complexity is 2^n * klogk not good
/*
void solve(vector<int>& arr, int n,set<vector<int>>& ans,vector<int>& result,int i, int target){
    if(i >= n){
        if(target == 0){
            ans.insert(result);
        }
        return;
    }

    if(arr[i] <= target){
        result.push_back(arr[i]);
        solve(arr,n,ans,result,i+1,target - arr[i]);
        result.pop_back();
    }

    solve(arr,n,ans,result,i+1,target);

}

vector<vector<int>> subsequenes(vector<int> arr, int n,int k){
    set<vector<int>> ans;
    vector<int> result;
    solve(arr,n,ans,result,0,k);
    
    vector<vector<int>> output;
    for(auto i:ans){
        output.push_back(i);
    }
    return output;
}
*/



// doing without set
// tc : 2^n * k (k = no of size of ans data structure)
void solve1(vector<int>& arr,int n,vector<vector<int>>&ans,vector<int> result, int index, int target){
    if(target == 0){
        ans.push_back(result);
        return; 
    }

    for(int i = index; i<n; i++){
        if(i != index && arr[i] == arr[i-1]) continue;

        if(arr[i] <= target){
            result.push_back(arr[i]);
            solve1(arr,n,ans,result,i+1,target-arr[i]);
            result.pop_back();
        }

        solve1(arr,n,ans,result,i+1,target);
    }
}

vector<vector<int>> subsequenes1(vector<int>& arr, int n,int k){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> result;
    solve1(arr,n,ans,result,0,k);
    
    return ans;
}

void print(vector<vector<int>> arr){
    for(auto i:arr){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main(){
    // vector<int> arr {2,3,2,6};
    // vector<vector<int>> ans = subsequenes(arr,4,7);
    // print(ans);

    vector<int> arr {2,3,2,6};
    vector<vector<int>> ans = subsequenes1(arr,4,7);
    print(ans);
    return 0;
}