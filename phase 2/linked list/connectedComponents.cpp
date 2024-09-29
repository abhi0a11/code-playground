// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:


//     int solve(ListNode* head, vector<int>& nums,int cnt){
//         if(head == NULL ){
//             return cnt;
//         }

//         ListNode *temp = head;

//         int val1 = temp->val;
//         temp = temp->next;
//         int val2 = temp->val;

//         for(auto value1: nums){
//             if(value1 == val1){
//                 for(auto value2: nums){
//                     if(value2 == val2){
//                         cnt++;
//                     }
//                 }
//             }
//         }

//        return solve(temp,nums,cnt);
//     }


//     int numComponents(ListNode* head, vector<int>& nums) {
//         int cnt =0;
//         int ans = solve(head, nums, cnt);
//         return ans;
//     }
// };