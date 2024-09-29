#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> arr, int index, int size, int sum, int& ans){
	if(index >= arr.size()){
		if((sum&1) == 0){
			ans = max(ans,size);
		}
		return;
	}

	sum  += arr[index+1] - arr[index];
	solve(arr,index+1,size+1,sum,ans);
	sum -= arr[index+1] - arr[index];
	
	solve(arr, index+1,size,sum,ans);
}
int getMax(vector<int> arr){
	int ans = 0;
	int index = 0;
	int size = 0;
	int sum = 0;
	solve(arr,index,size,sum,ans);
	return ans;
}
int main(){
	vector<int> v {87,99,85,50,93};
	cout<<getMax(v);
	return 0;
}