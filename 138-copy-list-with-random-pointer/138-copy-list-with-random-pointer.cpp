/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* curr=head;
        Node* temp=NULL;
        //step1: insert additional node after every nodei.e copy of every node
        while(curr!=NULL){
            temp=curr->next; //so that link will not break 
            curr->next=new Node(curr->val); //now in curr->next put the new node i.e copy of the prev node 
            curr->next->next=temp;//connect the copy node with rest of the linked list 
            curr=temp;
        }
        
        //step2: adjust the random pointers 
        curr=head;//again need to update because after the loop it becomes NULL
        while(curr!=NULL){
              if(curr->next!=NULL){
            curr->next->random = (curr->random!=NULL) ?
                                 curr->random->next : curr->random;
              }
            //move to the next node if curr->next exists then curr->next->next 
             curr = (curr->next!=NULL)?curr->next->next:curr->next;
        }
        
        
        //step3: separate the original list and copied list
        
        Node* original = head, *copy = head->next;
        temp=copy;    // save the start of copied linked list
        
        //in this while loop we are just moving orginal and copy by two nodes 
        while(original !=NULL && copy!=NULL){
             original->next =
         original->next? original->next->next : original->next;
 
        copy->next = copy->next?copy->next->next:copy->next;
        original = original->next;
        copy = copy->next;
        }
        
        return temp;
        
        
        
        
        
    }
};