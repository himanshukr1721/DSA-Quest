// 54. Spiral Matrix
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

    class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;




        while(top<=bottom && left<=right){
            for(int col = left; col<=right; col++){   //for moving left->right
                ans.push_back(matrix[top][col]);
            }
            top++;

            for(int row = top; row<=bottom; row++){
                ans.push_back(matrix[row][right]);
            }
            right--;

            if(top<=bottom){
                for(int col = right; col>=left; col--){
                    ans.push_back(matrix[bottom][col]);
                }
            }
            bottom--;

            if(left<=right){
                for(int row = bottom; row>=top; row--){
                    ans.push_back(matrix[row][left]);
                }
            }

            left++;
        }
        return ans;
        
    }
};