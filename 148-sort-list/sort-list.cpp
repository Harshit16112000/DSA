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
        vector<int> order;

        ListNode* temp = head;
        ListNode* ans = head;
        while(temp != NULL)
        {
            order.push_back(temp->val);
            temp = temp->next;
        }

        sort(order.begin(), order.end());

        for(int i=0;i<order.size();i++)
        {
            ans->val = order[i];
            ans = ans->next;
        }

        return head;
    }
};