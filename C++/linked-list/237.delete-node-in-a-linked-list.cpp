/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* pre=node;
        for(ListNode* i=node->next;i!=NULL;i=i->next){
            pre->val=i->val;
            pre=i;
        }
        ListNode* temp=node;
        pre=NULL;
        while(temp->next){
            pre=temp;
            temp=temp->next;
        }
        pre->next=NULL;
        delete temp;
    }
};
// @lc code=end

