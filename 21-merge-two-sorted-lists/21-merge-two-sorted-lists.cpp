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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         ListNode* fh=NULL;
        //base case
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        if(list1->val<=list2->val){
            fh=list1;
            fh->next=mergeTwoLists(list1->next,list2);
        }
        else{
            fh=list2;
            fh->next=mergeTwoLists(list1,list2->next);
        }
        return fh;
    }
};