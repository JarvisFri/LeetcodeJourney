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
    //Method1: floyds
    //Traverse till end of the ll form any head, point null to head which creates cycle
    //Now keep two pointers starting from other head-slow and fast, they meet at node intersection
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Method2: Distance a= hA to intersect, b=hB to intersect and c=intersect to end of common len
        //pass1 L1:a+b, L2=b+c, interchange l1 and l2 now so till intersect both distance =a+b+c

        ListNode *L1=headA, *L2=headB;
        int countL1=0, countL2=0;


        while(L1!=L2 && countL1<=1 && countL2<=1){
            if(L1==NULL ){
                L1=headB;
                countL1++;
            }else{
                L1=L1->next;
            }
            if(L2==NULL ){
                L2=headA;
                countL2++;
            }else{
                L2=L2->next;
            }

        }
        if(countL1>1 || countL2>1) return NULL;

        return L1;

        // ListNode* ptr=headA;
        // while(ptr->next!=NULL){
        //     ptr=ptr->next;
        // }
        // ptr->next=headA;

        // bool isCyclic=false;
        // ListNode *slow=headB, *fast=headB,*ans=NULL;
        // while(fast->next!=NULL && fast->next->next!=NULL){
        //     slow=slow->next;
        //     fast=fast->next->next;
        //     cout<<slow->val<<" "<<fast->val<<endl;
        //     if(slow==fast){
        //         slow=headB;
        //         isCyclic=true;
        //         break;
        //     }
        // }

        // if(isCyclic){
        //     while(slow!=fast){
        //         slow=slow->next;
        //         fast=fast->next;
        //     }
        //     ans=slow;
        // }

        // ptr->next=NULL;

        // return ans;
    }
};