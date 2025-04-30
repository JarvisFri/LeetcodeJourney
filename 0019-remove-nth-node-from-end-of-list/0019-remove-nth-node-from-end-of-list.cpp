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
    //Method 2: Keep two pointer one n steps ahead of other, p2->next ==NULL, p1->next=p1->next->next

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int gap=0;

        ListNode *p1=head, *p2=head;

        while(p2->next!=NULL){
            if(gap<n){
                p2=p2->next;
                gap++;
            }
            else{
                p1=p1->next;
                p2=p2->next;
            }
        }
        if(gap==n)
        p1->next=p1->next->next;
        else head=p1->next;

        return head;

        // int size=1;
        // ListNode* itr=head;
        // while(itr->next!=NULL){
        //     itr=itr->next;
        //     size++;
        // }

        // int idxToDel=size-n;//Next of this needs to be deleted
        // itr=head;
        // while(idxToDel>1){
        //     itr=itr->next;
        //     idxToDel--;
        // }

        // if (idxToDel==0)
        //     head=itr->next;
        // ListNode* temp=itr;
        // cout<<itr->val<<" ";
        // if(itr->next==NULL) return NULL;
        // itr->next=itr->next->next;
        // // free(temp);

        // return head;



    }
};