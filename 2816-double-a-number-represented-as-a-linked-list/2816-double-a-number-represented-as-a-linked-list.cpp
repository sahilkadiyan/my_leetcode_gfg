class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* temp = NULL;
        while(cur) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        if(!head) return NULL;
        ListNode* head2 = reverse(head);
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;
        while(head2 != NULL || carry) {
            int sum = 0;
            if(head2) {
                sum += (head2->val * 2);
                head2 = head2->next;
            }
            
            sum += carry;
            
            carry = sum / 10;
            ListNode* curr = new ListNode(sum % 10);
            temp->next = curr;
            temp = temp->next;
        }
        
        return reverse(dummy->next);
    }
};