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
    //Keep 2 pointers pointing  to head, move second twice as first
    //If second hits null return first
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr1=head;
        ListNode* ptr2=head;

        while(ptr2!=NULL){
            if(ptr2->next!=NULL) ptr2=ptr2->next->next;
            else break;
            ptr1=ptr1->next;
        }

        return ptr1;
    }
};