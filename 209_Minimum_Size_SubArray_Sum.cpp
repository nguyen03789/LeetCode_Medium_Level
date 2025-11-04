#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right  = 0;
        int res = 0;
        int sum = nums[0];
        if(nums.size() == 1) return (nums[0] >= target) ? 1 : 0;
        
        while (left <= right && right < nums.size()){
            if(sum >= target) {
                if(right == left) return 1;
                else {
                    res = (res > (right - left + 1)) ? right - left + 1 : res;
                }
                sum = sum - nums[left];
                left++;
            } 
            else {
                right++;
                sum = sum + nums[right];
            }
        }
        return res;
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