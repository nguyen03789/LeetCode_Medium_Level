#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int left = 0, right  = 0;
//         int res = __INT_MAX__;
//         int sum = nums[0];
//         while (left <= right && right < nums.size()){
//             if(sum >= target) {
//                 if(right == left) return 1;
//                 else res = (res > (right - left + 1)) ? (right - left + 1) : res;
//                 sum = sum - nums[left];
//                 left++;
//             } 
//             else {
//                 if(right < nums.size() - 1) {
//                     right++;
//                     sum = sum + nums[right];
//                 }
//                 else break;
//             }
//         }
//         return res = (res == __INT_MAX__) ? 0:res;
//     }
// };

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right  = 0;
        int res = __INT_MAX__;
        int sum = 0;
        for(right = 0 ; right < nums.size()  ; right++){
            sum += nums[right];
            while(sum >= target){
                res = min(res, right - left + 1);
                sum-=nums[left];
                left++;
            }
        }
        return res = (res == __INT_MAX__) ? 0:res;
    }
};

int main(){
    int input1 = 7;
    vector<int> input2 {1,2,3,4,5,6,7};
    int output;
    Solution a;
    output = a.minSubArrayLen(input1, input2);
    cout << output << endl;
    return 0;
}