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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        //middle
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL &&fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            //here slow will be at premiddle 
            //and fast will be our middle
        }
        //now reverse the ll which is after the middle of the linked list 
        ListNode* premiddle=slow;
        ListNode* precurrent=slow->next;
        while(precurrent->next!=NULL){
            ListNode* current=precurrent->next;
            precurrent->next=current->next;
            current->next=premiddle->next;
            premiddle->next=current;
        }
        
        slow=head;
        fast=premiddle->next;
        while(slow!=premiddle){
            premiddle->next=fast->next;
            fast->next=slow->next;
            slow->next=fast;
            slow=fast->next;
            fast=premiddle->next;
            
        }
        
    }
};