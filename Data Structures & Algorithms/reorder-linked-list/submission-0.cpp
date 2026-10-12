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
    void reorderList(ListNode* head) {
        ListNode* ptr2 = head;
        ListNode* ptr1 = head;
        ListNode* curr = head;
        while(ptr2->next != NULL) {
            ptr1 = ptr1->next;
            if(ptr2->next->next == NULL) {
                ptr2 = ptr2->next;
                break;
            }
            ptr2 = ptr2->next->next;
        }
        while(ptr2 != ptr1) {
            ListNode* ptr3 = ptr1;
            while(ptr3->next->next != NULL) {
                ptr3 = ptr3->next;
            }
            ListNode* tmp = curr->next;
            curr->next = ptr2;
            curr->next->next = tmp;
            curr = tmp;
            ptr3->next = NULL;
            ptr2 = ptr3;
        }
    }
};
