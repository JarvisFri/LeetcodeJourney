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
    //Traverse till end - get size
    // Nose to remove from start:temp= (size-n )->next
    //store (size-n )->next=(size-n)->next->next, free(temp)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=1;
        ListNode* itr=head;
        while(itr->next!=NULL){
            itr=itr->next;
            size++;
        }

        int idxToDel=size-n;//Next of this needs to be deleted
        itr=head;
        while(idxToDel>1){
            itr=itr->next;
            idxToDel--;
        }

        if (idxToDel==0)
            head=itr->next;
        ListNode* temp=itr;
        cout<<itr->val<<" ";
        if(itr->next==NULL) return NULL;
        itr->next=itr->next->next;
        // free(temp);

        return head;



    }
};