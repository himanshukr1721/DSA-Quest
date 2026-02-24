// 3507. Minimum Pair Removal to Sort Array I
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an array nums, you can perform the following operation any number of times:

// Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
// Replace the pair with their sum.
// Return the minimum number of operations needed to make the array non-decreasing.

// An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 

// Example 1:

// Input: nums = [5,2,3,1]

// Output: 2

// Explanation:

// The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
// The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
// The array nums became non-decreasing in two operations.

// Example 2:

// Input: nums = [1,2,2]

// Output: 0

// Explanation:

// The array nums is already sorted.

 

// Constraints:

// 1 <= nums.length <= 50
// -1000 <= nums[i] <= 1000

class Solution {
public:
    int minPair(vector<int> v){
        int minSum = 1e9;
        int pos = -1;
        for(int i = 0; i < (int)v.size() - 1; i ++){
            if(v[i] + v[i + 1] < minSum){
                minSum = v[i] + v[i + 1];
                pos = i;
            }
        }
        return pos;
    }
    void mergePair(vector<int> &v, int pos){
        v[pos] += v[pos + 1];
        v.erase(v.begin() + pos + 1);
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while(!is_sorted(nums.begin(), nums.end())){
            mergePair(nums, minPair(nums));
            ops += 1;
        }
        return ops;
    }
};