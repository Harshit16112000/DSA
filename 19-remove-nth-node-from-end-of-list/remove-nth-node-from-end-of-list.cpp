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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* last = head;
        
        for (int i = 0; i < n; ++i) {
            if (last != nullptr)
                last = last->next;
            
        }

        if(last == NULL)  {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
         while (last->next != nullptr) {
            first = first->next;
            last = last->next;
        }

        
        first->next = first->next->next;
        return head;
    }
};