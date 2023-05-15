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
    ListNode* swapNodes(ListNode* head, int k) {
         int nodeCount = 1;
        ListNode* headCopy = head;

        ListNode* firstSwapNode = nullptr;
        while(headCopy != nullptr)
        {
            if(nodeCount == k)
            {
                firstSwapNode = headCopy;
            }

            headCopy = headCopy->next;
            ++nodeCount;
        }

        int secondSwapNodeNum = nodeCount - k;
        nodeCount = 1;
        headCopy = head;

        while(nodeCount < secondSwapNodeNum)
        {
            ++nodeCount;
            headCopy = headCopy->next;
        }

        std::swap(headCopy->val, firstSwapNode->val);

        return head;
    }
};