// Description
// Editorial
// Editorial
// Solutions
// Solutions
// Submissions
// Submissions


// Code
// Note
// Note
// Testcase
// Testcase
// Test Result
// 22. Generate Parentheses
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8

class Solution {
public:

    void recursiveF(int op, int cl, string s, vector<string>& ans){
        if(cl == 0) ans.push_back(s);
        if(op>0) recursiveF(op - 1, cl, s + "(", ans);
        if(cl>op) recursiveF(op, cl - 1, s + ")", ans);
    }

    vector<string> generateParenthesis(int n) {
        int op = n, cl = n;
        string s = "";
        vector<string> ans;

        recursiveF(op, cl, s, ans);
        return ans;
    }
};