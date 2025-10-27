#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int *num_swap1;
        int *num_swap2;
        int max = 0;
        if(nums.size() < 3) return;
        
        for(int i = nums.size() - 1; i > 0 ; i--){
            if(nums[i] > nums[i - 1]){
                num_swap1 = &nums[i-1];
                num_swap2 = &nums[i];
                for (int j = nums.size() - 1; j >= i; j--) 
                if(nums[j] > *num_swap1 && nums[j] <= *num_swap2) {
                    num_swap2 = &nums[j];
                    break;
                }
                // swap
                int temp;
                temp = *num_swap1;
                *num_swap1 = *num_swap2;
                *num_swap2 = temp;
                // reverse the array
                if(i < nums.size() - 2){
                int left = i;
                int right  = nums.size() - 1;
                int temp1;
                    while (left < right){
                        temp1 = nums[left];
                        nums[left] = nums[right];
                        nums[right] = temp1;
                        left++;
                        right--;
                    }
                }
                break;
            }
            else if(i == 1 && nums[1] < nums[0]) max = 1;
        }
        if (max == 1) sort(nums.begin(), nums.end());
        for (int n : nums) cout << n << " ";
        cout << endl;
    }
};

int main(int argc, char** argv){
    vector<int> v = {2, 3, 1, 3, 3};
    Solution a;
    a.nextPermutation(v);
    return 0;
}