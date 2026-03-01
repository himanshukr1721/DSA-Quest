// 3856. Trim Trailing Vowels
// Solved
// Easy
// premium lock icon
// Companies
// Hint
// You are given a string s that consists of lowercase English letters.

// Return the string obtained by removing all trailing vowels from s.

// The vowels consist of the characters 'a', 'e', 'i', 'o', and 'u'.

 

// Example 1:

// Input: s = "idea"

// Output: "id"

// Explanation:

// Removing "idea", we obtain the string "id".

// Example 2:

// Input: s = "day"

// Output: "day"

// Explanation:

// There are no trailing vowels in the string "day".

// Example 3:

// Input: s = "aeiou"

// Output: ""

// Explanation:

// Removing "aeiou", we obtain the string "".

 

// Constraints:

// 1 <= s.length <= 100
// s consists of only lowercase English letters.

class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string trimTrailingVowels(string s) {
        int n = s.length();
        int i = n-1;
        while(i >= 0 && isVowel(s[i])){
            i--;
        }
        if(i<0) return "";
        return s.substr(0, i+1);
    }
};