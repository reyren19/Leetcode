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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newNode = new ListNode(-1);
        ListNode* head = newNode;
        ListNode* p = list1;
        ListNode* q = list2;
        while(p!=NULL && q!=NULL){
            if(p->val <= q->val){
                newNode->next = new ListNode(p->val);
                p=p->next;
            }
            else{
                newNode->next = new ListNode(q->val);
                q=q->next;
            }
            newNode = newNode->next;
        }
        while(p){
            newNode->next = new ListNode(p->val);
            p=p->next;
            newNode = newNode->next;
        }
        while(q){
            newNode->next = new ListNode(q->val);
            q=q->next;            
            newNode = newNode->next;        
        }
        return head->next;
    }
};