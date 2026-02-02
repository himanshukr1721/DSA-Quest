// 82. Remove Duplicates from Sorted List II
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

// Example 1:


// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:


// Input: head = [1,1,1,2,3]
// Output: [2,3]
 

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* removeEle(ListNode* head, int x){
        if(head == nullptr) return head;
        bool a = false;

        if((head->val == x) || (head->next != nullptr && head->val == head->next->val)) a=true;
        head->next = removeEle(head->next, head->val);
        return (a) ? head->next: head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        return removeEle(head, -101);//-101 passed here to compare the prev and next so taken as reference 

    }
};