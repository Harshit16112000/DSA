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
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL)  return head;
       ListNode* slow = head;
       ListNode* fast = head->next;

       while(fast != NULL && fast->next != NULL)
       {
          slow = slow->next;
          fast = fast->next->next;
       } 

       ListNode* mid = slow->next;
       slow->next = NULL;

       ListNode* left = sortList(head);
       ListNode* right = sortList(mid);
       return mergeList(left, right);
    }

    ListNode* mergeList(ListNode* slow, ListNode* fast)
    {
        ListNode* temp = new ListNode();
        ListNode* dummy = temp;
        while(slow && fast )
        {
            if(slow->val <=  fast->val)
            {
                temp->next = slow;
                slow = slow->next;
                 temp = temp->next;
            }
            else {
                temp->next = fast;
                temp = temp->next;
                fast = fast->next;
            }
        }

            if (slow) temp->next = slow;
            else    
            temp->next = fast;

        return dummy->next;
    }
};