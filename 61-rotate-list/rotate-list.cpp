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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
         if (!head || !head->next || k == 0) return head;
        int cnt = 1;
        while(temp->next != nullptr)
        {
            temp = temp->next;
            cnt++;
        }
        temp->next = head;

        k = k%cnt;
        int stepsToNewTail = cnt - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }
        
        head  = newTail->next;
        newTail->next = nullptr;
        return head;
    }
};