/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        for(ListNode* temp=head;temp!=NULL;temp=temp->next){
            if(s.find(temp)!=s.end()) return true;
            s.insert(temp);
            
        }
        return false;
    }
};