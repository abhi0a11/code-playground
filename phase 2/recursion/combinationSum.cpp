#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// multiple values are allowed
void solve(vector<int>& arr, int n,vector<vector<int>>& ans,vector<int>& result,int index,int sum , int k){
    if(index >= n ){
        if(sum == k){
            ans.push_back(result);
            return;
        }
        else    return;
    }
    if(sum > k) return;

    result.push_back(arr[index]);
    solve(arr,n,ans,result,0,sum + arr[index],k);
    result.pop_back();

    solve(arr,n,ans,result,index+1,sum,k);

}
vector<vector<int>> subsequenes(vector<int> arr, int n,int k){
    vector<vector<int>> ans;
    vector<int> result;
    int sum = 0;
    solve(arr,n,ans,result,0,sum,k);
    
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
    vector<int> arr {2,3,7,6};
    vector<vector<int>> ans = subsequenes(arr,4,7);
    print(ans);
    return 0;
}


