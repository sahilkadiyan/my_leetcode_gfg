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
        ListNode* temp=head;
        int x=0;
        while(temp!=NULL){
            temp=temp->next;
            x++;
        }
        return x;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int z=length(head);
        int y=z-n;
        if(head==NULL) return NULL;
        //this loop is so that we can reach the nth node from the end
        //here we need to take care of one case like suppose we have 1->2->3->4->5 and here we need to delete 4 so by the end of this while loop we should be at 3 not at 4 so that after deleting the node 4 we can directly connect 3 to 5 here we can do that easily by temp->next=temp2; otherwise just in case we are at 4 now it is difficult to do that we need to again traverse the ll to store the address 
        while(y>1){
            temp=temp->next;
            y--;
        }
        //this is when the length of the ll and the value of n is same i.e we need to delete the head of ll simply 
        if(y==0){
            temp=temp->next;
            delete(head);
            return temp;
        }
        ListNode* temp2=temp->next->next;
        delete(temp->next);
        temp->next=temp2;
        return head;
        
        
        
    }
};