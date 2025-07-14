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
    int getDecimalValue(ListNode* head) {
        string ans = "";
        ListNode* tmp = head;
        while(tmp != NULL)
        {
            
            ans.append(to_string(tmp->val));
            tmp = tmp->next;
        }
        return stoi(ans,nullptr,2);
    }
};