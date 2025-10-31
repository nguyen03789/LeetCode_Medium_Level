#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int left = 0;
//         int right = nums.size() - 1;
//         int mid = (left + right) / 2;
//         vector<int> res {-1, -1};
//         while(left <= right){
//             // Array have 2 elements
//             if(right - left <= 1){
//                 if(nums[left] == target){
//                     if(nums[left] == nums[right]) return  {left, right};
//                     else return {left, left};
//                 }
//                 else if(nums[right] == target) return {right, right};
//                 else return {-1, -1};
//             }
//             else {
//                 if(nums[mid] == target){
//                     res[0] = res[1] = mid;
//                     left = mid - 1;
//                     right = mid + 1;
//                     while( left >= 0 && right <= nums.size()){
//                         if( left != nums.size() - 1 && target == nums[left]) {
//                             res[0] = left;
//                             left = (left > 0) ? left - 1 : nums.size() - 1;
//                         }
//                         else if(right != 0 && target ==  nums[right]){
//                             res[1] = right;
//                             right = (right < nums.size() - 1) ? right + 1 : 0;
//                         }
//                         else break;
//                     }
//                     return res;
//                 }
//                 else if(target > nums[mid]){
//                     left = mid;
//                     mid = (left + right) / 2;
//                 }
//                 else {
//                     right = mid;
//                     mid = (left + right) / 2;
//                 }
//             } 
//         }
//         return {-1, -1};
//     }
// };


// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int left = 0;
//         int right = nums.size() - 1;
//         int mid = (left + right) / 2;
//         int Binary_leftside = 0;
//         int Binary_rightside = 0;
//         vector<int> res {-1, -1};
//         int temp_left = 0, temp_right = 0;
//         while(left <= right && temp_left <= right && left <= temp_right){
//             // Array have 2 elements
//             if(right - left <= 1){
//                 if(nums[left] == target){
//                     if(nums[left] == nums[right]) return  {left, right};
//                     else return {left, left};
//                 }
//                 else if(nums[right] == target) return {right, right};
//                 else return res;
//             }
//             if(Binary_leftside == 0 && Binary_rightside == 0){
//                 if(target == nums[mid]) {
//                     res[0] = res[1] = mid;
//                     if(nums[mid-1] == target) {
//                         Binary_leftside = 1;
//                         temp_right = mid - 1;
//                     }
//                     if(nums[mid+1] == target) {
//                         Binary_rightside = 1;
//                         temp_left = mid + 1;
//                     }
//                     if (Binary_leftside == 0 && Binary_rightside == 0) return res;
//                 }
//                 else if(target > nums[mid]){
//                     left = mid + 1;
//                     mid = (left + right) / 2;
//                 }
//                 else {
//                     right = mid - 1;
//                     mid = (left + right) / 2;
//                 }
//             }
//             else {
//                 if(Binary_leftside == 1){
//                     mid = (left + temp_right) / 2;
//                     if(nums[mid] == target){
//                         temp_right = mid - 1;
//                         res[0] = mid;
//                     }
//                     else if(nums[mid] < target){
//                         if(nums[mid+1] == target){
//                             Binary_leftside = 0;
//                             res[0] = mid + 1;
//                         }
//                         else left = mid + 1;
//                     }
//                 }
//                 else if(Binary_rightside == 1){
//                     mid = (right + temp_left) / 2;
//                     if(nums[mid] == target){
//                         temp_left = mid + 1;
//                         res[1] = mid;
//                     }
//                     else if(nums[mid] > target){
//                         if(nums[mid-1] == target){
//                             Binary_rightside = 0;
//                             res[1] = mid - 1;
//                         }
//                         else right = mid - 1;
//                     }
//                 }
//                 if (Binary_leftside == 0 && Binary_rightside == 0) return res;
//             }       
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         if (nums.empty()) return {-1, -1};
//         int left = 0;
//         int right = nums.size() - 1;
//         int mid = (left + right) / 2;
//         int Binary_leftside = 0;
//         int Binary_rightside = 0;
//         vector<int> res {-1, -1};
//         // Array have 2 elements
//         if(right - left <= 1){
//             if(nums[left] == target){
//                 if(nums[left] == nums[right]) return  {left, right};
//                 else return {left, left};
//             }
//             else if(nums[right] == target) return {right, right};
//             else return res;
//         }
//         while(left <= right){
//             mid = (left + right) / 2;
//             if(nums[mid] > target) right = mid - 1;
//             else if(nums[mid] < target) left = mid + 1 ;
//             else {
//                 res[0] = res[1] = mid;
//                 if (mid + 1 < nums.size() && nums[mid + 1] == target) Binary_rightside = 1;
//                 if (mid - 1 >= 0 && nums[mid - 1] == target) Binary_leftside = 1;
//                 if (Binary_leftside == 1 || Binary_rightside == 1) break;
//                 else return res;
//             }
//         }
//         if(Binary_leftside == 1){
//             int temp_left = left;
//             int temp_right = mid;
//             int temp_mid = (temp_left + temp_right) / 2;
//             while (temp_left <= temp_right && Binary_leftside != 0){
//                 temp_mid = (temp_left + temp_right) / 2;                    
//                 if(nums[temp_mid] == target){
//                     temp_right = temp_mid - 1;
//                     res[0] = temp_mid;
//                 }
//                 else if(nums[temp_mid] < target){
//                     if (temp_mid == nums.size() - 1) Binary_leftside = 0;
//                     else if(nums[temp_mid+1] == target){
//                         Binary_leftside = 0;
//                         res[0] = temp_mid + 1;
//                     }
//                     else temp_left = temp_mid + 1;
//                 }
//             }
//         }
//         if(Binary_rightside == 1){
//             int temp_left = mid;
//             int temp_right = right;
//             int temp_mid = (temp_left + temp_right) / 2;
//             while (temp_left <= temp_right && Binary_rightside != 0){
//                 temp_mid = (temp_left + temp_right) / 2; 
//                 if(nums[temp_mid] == target){
//                     temp_left = temp_mid + 1;
//                     res[1] = temp_mid;
//                 }
//                 else if(nums[temp_mid] > target){
//                     if (temp_mid == 0) Binary_rightside = 0;
//                     else if(temp_mid - 1 >= 0 && nums[temp_mid-1] == target){
//                         Binary_rightside = 0;
//                         res[1] = temp_mid - 1;
//                     }
//                     else temp_right = temp_mid - 1;
//                 }
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        vector<int> res {-1,-1};
        while (left <= right){
            mid = (left + right) / 2;
            if(nums[mid] > target) right = mid - 1;
            else if (nums[mid] < target) left = mid + 1;
            else {
                right = mid - 1;
                if (res[0] == -1) res[0] = mid;
                else res[0] = (res[0] < mid) ? mid : res[0];
            }
        }
        left = 0;
        right = nums.size() - 1;
        while (left <= right){
            mid = (left + right) / 2;
            if(nums[mid] > target) right = mid - 1;
            else if (nums[mid] < target) left = mid + 1;
            else {
                left = mid + 1;
                res[1] = (res[1] > mid) ? mid : res[1];
            }
        }
        return res;
    }
};

int main(){
    vector<int> input1 = {5,7,7,8,8,10};
    int input2 = 8;
    vector<int> output;
    Solution a;
    output = a.searchRange(input1,input2);
    // for (int x : output) cout << x << " ";
    cout << output[0] << " " << output[1] << endl;
    return 0;
}