#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int res = 0;
//         for(int i = 0; i < s.size(); i++){
//             map < char , int> map_char;
//             int j = i;
//             int range = 0;
//             while(j < s.size()){
//                 if(map_char.find(s[j]) == map_char.end()){
//                     map_char.insert({s[j],j});
//                     range++;
//                     j++;
//                 }
//                 else {
//                     map_char.clear();
//                     break;
//                 }
//                 res = max(res, range);
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int res = 0;
        int temp = 0;
        unordered_map <char , int> map_char;
        for(int right = 0; right < s.size(); right++){
            // co ky tu trong map
            if(map_char.find(s[right]) != map_char.end()) {
                left = max(left, map_char[s[right]]+1);
                map_char[s[right]] = right;
            }
            else map_char.insert({s[right] , right});
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main (){
    string input = "abcabcbb";
    Solution a;
    int output = a.lengthOfLongestSubstring(input);
    cout << output << endl;
    return 0;
}