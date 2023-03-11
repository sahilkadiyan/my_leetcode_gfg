class Solution {
public:
    TreeNode* func(ListNode*head,int n){
        //if we have the length of list 0 then we will simply return the nullptr
        if(n<=0){
            return nullptr;
        }
		//if we are remaining with only one length then we will make node of it and return it
        if(n==1){
            return new TreeNode(head->val);
        }
        int mid=n/2;
        ListNode*temp=head;
		//traversing to the mid of the list from head
        while(mid--){
            temp=temp->next;
        }
		//then we will get our ans
        TreeNode*ans=new TreeNode(temp->val,func(head,n/2),func(temp->next,n-n/2-1));
		//returning the ans
        return ans;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return nullptr;
        }
        int n=0;
		//we are calculating the length of the linked list
		//so that we can divide the linked list from middle
        ListNode*temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
		//then we are calling the function
        return func(head,n);
    }
};