// 179. Largest Number
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

 

// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109

class Solution {
public:
    static bool comp(string s1, string s2){
        return s1+s2 > s2+s1;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int num : nums){
            str.push_back(to_string(num));
        }

        sort(str.begin(), str.end(), comp);
        string ans;
        for(auto x : str){
            ans += x;
        }
        if(ans[0] == '0'){ 
             return "0";
        }else{
            return ans;
        }
        
         
    }
};