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
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return true;
        if(head->next==NULL) return true;
        stack<int> s;
        for(ListNode* temp=head;temp!=NULL;temp=temp->next){
            s.push(temp->val);
        }
        for(ListNode* temp=head;temp!=NULL;temp=temp->next){
            if(s.top()!=temp->val) return false;
            s.pop();
        }
        return true;
    }
};