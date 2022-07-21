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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
          if(left == right)
            return head;
        
        if(left > 1)
        {
            head->next = reverseBetween(head->next,  left- 1, right - 1);
            return head;
        }
        else
        {
            ListNode * tailNode = reverseBetween(head->next, 1, right - 1);
            ListNode * tailNodeNext = head->next->next;
            
            head->next->next = head;
            head->next = tailNodeNext;

            return tailNode;
        }
    }
};