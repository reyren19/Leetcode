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
    struct Compare {
        bool operator() (ListNode*a, ListNode*b){
            return a->val > b->val; // returns the lesser of the two values
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(auto node: lists) if(node) pq.push(node); // push node using the comparator we wrote
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        while(!pq.empty()){
            ListNode* smallest = pq.top();
            pq.pop();
            ptr->next = smallest;
            ptr = ptr->next;
            if(smallest->next) pq.push(smallest->next);
        }
        return dummy->next;
    }
};