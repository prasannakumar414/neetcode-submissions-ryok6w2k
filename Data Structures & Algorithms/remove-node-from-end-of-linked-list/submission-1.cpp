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
        ListNode* ptr = head;
        int size = 0;
        while(ptr!= NULL) {
            size++;
            ptr = ptr->next;
        }
        ptr = head;
        ListNode *prev = NULL;
        int val = size-n;
        while(val--) {
            prev = ptr;
            ptr = ptr->next;
        }
        if(prev != NULL) {
            prev->next = ptr->next;
        } else {
            head = ptr->next;
        }
        delete ptr;
        return head;
    }
};
