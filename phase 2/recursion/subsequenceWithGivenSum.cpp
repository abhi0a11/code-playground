#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int n,vector<vector<int>>& ans,vector<int>& result,int index,int sum , int k){
    if(index >= n ){
        if(sum == k){
            ans.push_back(result);
            return;
        }
        else    return;
    }

    result.push_back(arr[index]);
    sum += arr[index];
    solve(arr,n,ans,result,index+1,sum,k);
    result.pop_back();
    sum -= arr[index];

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


// print number of subsequence with given sum

int solve(vector<int>& arr, int tempSum, int sum,int i){
    if(tempSum > sum)   return 0;
    if(i == arr.size()){
        if(sum == tempSum)  return 1;
        else    return 0;
    }

    int incl = solve(arr,tempSum + arr[i], sum,i+1);

    int excl = solve(arr,tempSum, sum, i+1);

    return incl + excl;
}
int noOfSubsS(vector<int>& arr, int sum){
    return solve(arr,0,sum,0);
}


// print only one possible subsequence
bool solve1(vector<int>& arr, int n,vector<int>& result,int index,int sum , int k){
    if(sum > k)   return 0;
    if(index >= n){
        if(sum == k){
            return true;
        }
        else    return false;
    }

    result.push_back(arr[index]);
    sum += arr[index];
    if(solve1(arr,n,result,index+1,sum,k) == true){
        return true;
    }
    result.pop_back();
    sum -= arr[index];

    if(solve1(arr,n,result,index+1,sum,k) == true){
        return true;
    }

    return false;
}
vector<int> anyPossibleSubsequence(vector<int> arr, int n,int k){
    vector<int> result;
    int sum = 0;
    bool temp = solve1(arr,n,result,0,sum,k);
    
    return result;
}
int main(){
    vector<int> arr {1,1,2};
    vector<vector<int>> ans = subsequenes(arr,3,4);
    print(ans);
    cout<<endl<<endl;
    vector<int> res = anyPossibleSubsequence(arr,3,2);
    for(auto i:res){
        cout<<i<<" ";
    }
    return 0;
}