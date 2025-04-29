/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //Traverse till end of the ll form any head, point null to head which creates cycle
    //Now keep two pointers starting from other head-slow and fast, they meet at node intersection
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr=headA;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=headA;

        bool isCyclic=false;
        ListNode *slow=headB, *fast=headB,*ans=NULL;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            cout<<slow->val<<" "<<fast->val<<endl;
            if(slow==fast){
                slow=headB;
                isCyclic=true;
                break;
            }
        }

        if(isCyclic){
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            ans=slow;
        }

        ptr->next=NULL;

        return ans;
    }
};