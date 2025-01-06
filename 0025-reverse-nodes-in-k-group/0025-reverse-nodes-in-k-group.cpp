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
    int findLength(ListNode* head){
        ListNode* ptr = head;
        int len=0;
        while(ptr!=NULL){
            ptr=ptr->next;
            len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = findLength(head);
        int remaining = len;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while(remaining>=k){
            ListNode* curr=prev->next;
            for(int i=1; i<k; i++){
                ListNode* temp= curr->next;
                curr->next = temp->next;
                temp->next =prev->next;
                prev->next=temp;
            }
            prev=curr;
            remaining -= k;
        }   
        return dummy->next;
    }
};