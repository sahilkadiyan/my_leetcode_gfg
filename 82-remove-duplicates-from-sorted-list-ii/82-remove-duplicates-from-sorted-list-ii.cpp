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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* sentinel=new ListNode(0,head);
        ListNode* pred=sentinel;
        ListNode* temp=head;
        while(temp!=NULL){
            //here we are checking for the duplicates 
            if(temp->next!=NULL && temp->val==temp->next->val){
                //move till the end of the duplicates list
                while(temp->next!=NULL && temp->val==temp->next->val){
                    temp=temp->next;
                }
                
                pred->next=temp->next;
            }
            //when no duplicates so we need to move predecessor
            
            else{
                pred=pred->next;
                
            }
            temp=temp->next;
        }
        return sentinel->next;
        
        
    }
};