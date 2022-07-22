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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
          ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        ListNode* curr=head,*next1=NULL,*prev=NULL;
        int count=0;
        while(curr!=NULL && count<k){
            next1 = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next1;
            count++;
        }
        if(next1!=NULL){
            ListNode* rest_head=reverseKGroup(next1,k);
            head->next=rest_head;

        }
        return prev;
        
    }
};