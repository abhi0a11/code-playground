#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve0(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output,vector<int>& map){
    if(output.size() == nums.size()){
        ans.push_back(output);
        return;
    }

    for(int i = 0; i<nums.size(); i++){
        if(!map[i]){
            output.push_back(nums[i]);
            map[i] = 1;
            solve0(nums,ans,output,map);
            map[i] = 0;
            output.pop_back();
        }
    }
}

vector<vector<int>> permute0(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> map(nums.size(),0);
    vector<int> output;
    solve0(nums, ans, output,map);
    return ans;
}

// optimised approach
void solve(vector<int> nums, vector<vector<int>> &ans, int index)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int j = index ; j < nums.size(); j++)
    {
        swap(nums[index], nums[j]);
        solve(nums, ans, index + 1);
        // back track
        swap(nums[index], nums[j]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}

int main()
{
    vector<int> nums{0, 1};
    vector<vector<int>> num = permute0(nums);

    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < num[i].size(); j++)
        {
            cout << num[i][j];
        }
        cout << endl;
    }
    return 0;
}