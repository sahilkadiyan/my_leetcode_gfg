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
    //we will change this q to rotate the list by length-k places to the left and that will be same as that when we will rotate that towards right !!!
    int length(ListNode* head){
        ListNode* temp=head;
        int x;
        while(temp!=NULL){
            temp=temp->next;
            x++;
        }
        return x;
            
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* temp=head;
           ListNode* temp2=head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        int count=1;
        int len=length(head);
        if(k>len) k=k%len;
        k=len-k;
        if(k==0 || k==len) return head;
        //for pointing it to the kth node 
        while(count<k && temp!=NULL){
            temp=temp->next;
            count++;
        }
          // If temp is NULL then k is equal to the
    // count of nodes in the list
    // Don't change the list in this case
        if(temp==NULL) return head;
        ListNode* kth=temp; //if temp is not null then it will point to the kth node of ll
        //now we need the last node of ll so we need to traverse the ll 
     
        temp2->next=head; //i.e we need to connect the last node to head(previous one)
        head=kth->next;  //change head to k+1 node
         // Change next of kth node to NULL
        kth->next=NULL;
        return head;
        
    }
};