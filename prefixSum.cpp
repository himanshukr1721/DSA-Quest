// 

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            int leftCount = i + 1;
            int rightCount = n - i;

            int totalSubarrays = leftCount * rightCount;
            int oddSubarrays = (totalSubarrays + 1) / 2;

            totalSum += arr[i] * oddSubarrays;
        }

        return totalSum;
    }
};