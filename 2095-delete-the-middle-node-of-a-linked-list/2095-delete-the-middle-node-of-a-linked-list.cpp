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
    int length(ListNode* head){
        if(head==NULL) return 0;
        int x=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            x++;
        }
        return x;
        
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
       int count=length(head);
        ListNode* temp=head;
        ListNode* temp1=head->next;
        for(int i=0;i<(count/2)-1;i++){
            temp=temp->next;
            temp1=temp1->next;
        }
        temp->next=temp1->next;
        delete(temp1);
        return head;
        
    }
};