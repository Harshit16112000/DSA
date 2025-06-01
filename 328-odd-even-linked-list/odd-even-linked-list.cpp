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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;

        vector<ListNode*> oddNodes;
        vector<ListNode*> evenNodes;

        ListNode* curr = head;
        int index = 1;

        // Step 1: Separate nodes into odd and even position lists
        while (curr) {
            if (index % 2 == 1)
                oddNodes.push_back(curr);
            else
                evenNodes.push_back(curr);
            curr = curr->next;
            index++;
        }

        // Step 2: Link odd nodes together
        for (int i = 0; i < oddNodes.size() - 1; ++i)
            oddNodes[i]->next = oddNodes[i + 1];

        // Step 3: Link even nodes together
        for (int i = 0; i < evenNodes.size() - 1; ++i)
            evenNodes[i]->next = evenNodes[i + 1];

        // Step 4: Connect last odd node to first even node
        if (!oddNodes.empty())
            oddNodes.back()->next = evenNodes.empty() ? nullptr : evenNodes[0];

        // Step 5: Terminate the final node
        if (!evenNodes.empty())
            evenNodes.back()->next = nullptr;

        return oddNodes[0];
    }

};