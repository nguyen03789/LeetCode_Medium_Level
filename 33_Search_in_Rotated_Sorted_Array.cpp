#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Time complexity O(n)

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         if(nums[0] == target) return 0;
//         // Check Pri_Pos and check equal to target
//         int Pri_Pos = 0;
//         for(int i = 1; i <= nums.size() - 1; i++) {
//             if(nums[i] == target) return i;
//             if(nums[i] < nums[i - 1]) {
//                 Pri_Pos = i;
//                 break;
//             }
//         }
//         //if (Pri_Pos == 0 || Pri_Pos == 1 && nums.size() == 2) return -1;

//         // Binary Seach for other side of array
//         int left = Pri_Pos; 
//         int right = nums.size() - 1;
//         int mid = (left + right) / 2;

//         while (left <= right){
//             // Array only have 2 elements
//             if(right - left <= 1) {
//                 if(nums[left] == target) return left; 
//                 else if(nums[right] == target) return right;
//                 else return -1;
//             }
//             // Array have more than 2 elements
//             if(nums[mid] == target) return mid;
//             else if(nums[mid] > target) {
//                 right = mid;
//                 mid = mid = (left + right) / 2;
//             }
//             else if(nums[mid] < target) {
//                 left = mid;
//                 mid = (left + right) / 2;
//             }
//         }
//         return -5;
//     }
// };


// a b c d ... max  min x y z 
// (      A      ) (    B   )

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[0] == target) return 0;
        // Binary Seach for other side of array
        int left = 0; 
        int right = nums.size() - 1;
        int mid = (left + right) / 2;

        while (left <= right){
            // Array only have 2 elements
            if(right - left <= 1) {
                if(nums[left] == target) return left; 
                else if(nums[right] == target) return right;
                else return -1;
            }
            // Array have more than 2 elements
            mid = (left + right) / 2;
            if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) { // mid is privot pos
                if(target > nums[mid]) return -1;
                else if(target <= nums[nums.size() - 1]){ //target is in B --> binary B
                    left = mid + 1;
                    mid = (left + right) / 2;
                }
                else{// target is in A
                    right = mid;
                    mid = (left + right) / 2;
                } 
            }
            else { // mid is not privot pos
                //check mid is in A or B
                if(nums[mid] < nums[left]){ // mid is in B
                    if(target <= nums[nums.size() - 1]){
                        left = mid;
                        mid = (left + right) / 2;
                    }
                    else {
                        right = mid;
                        mid = (left + right) / 2;
                    }
                }
                else { // mid is in A
                    if(target <= nums[mid]){
                        right = mid;
                        mid = (left + right) / 2;
                    }
                    else{
                        left = mid;
                        mid = (left + right) / 2;
                    }
                }
            }            
            if(nums[mid] == target) return mid;
        }
        return -5;
    }
};


int main(){
    vector<int> input1 = {3,4,5,6,1,2};
    int input2 = 2;
    int output;
    Solution a;
    output = a.search(input1,input2);
    cout << output << endl;
    return 0;
}

