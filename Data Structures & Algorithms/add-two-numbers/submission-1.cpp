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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = NULL;
        ListNode* curr = NULL;
        while(l1!=NULL && l2!=NULL) {
            int sum = l1->val + l2->val + carry;
            ListNode* next = new ListNode(sum%10);
            carry = sum/10;
            if(result != NULL) {
                curr->next = next;
                curr = next;
            } else {
                curr = next;
                result = curr;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l2!=NULL) {
            int sum = l2->val + carry;
            ListNode* next = new ListNode(sum%10);
            carry = sum/10;
            if(result != NULL) {
                curr->next = next;
                curr = next;
            } else {
                curr = next;
                result = curr;
            }
            l2=l2->next;
        }
        while(l1!=NULL) {
            int sum = l1->val + carry;
            ListNode* next = new ListNode(sum%10);
            carry = sum/10;
            if(result != NULL) {
                curr->next = next;
                curr = next;
            } else {
                curr = next;
                result = curr;
            }
            l1=l1->next;
        }
        if(carry > 0) {
            curr->next = new ListNode(carry);
        }
        return result;
    }
};
