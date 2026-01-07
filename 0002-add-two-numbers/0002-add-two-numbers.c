/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int ans=0,t=0;
    struct ListNode* now1=l1;
    struct ListNode* now2=l2;
    struct ListNode* l3=NULL;
    while(now1!=NULL||now2!=NULL||t!=0){
        if(now1!=NULL&&now2!=NULL){
            ans = now1->val+now2->val+t;
            now1=now1->next;
            now2=now2->next;
        }
        else if(now1!=NULL){
            ans = now1->val+t;
            now1=now1->next;
        }
        else if(now2!=NULL){
            ans = now2->val+t;
            now2=now2->next;
        }
        else{
            ans = 1;
        }
        
        if(ans>9){
            ans=ans%10;
            t=1;
        }
        else{
            t=0;
        }

        struct ListNode* cur = l3;
        struct ListNode* newptr = malloc(sizeof(struct ListNode));
        newptr->val = ans;
        while(cur!=NULL && cur->next!=NULL){
            cur = cur->next;
        }
        if(cur == NULL){
            newptr->next = NULL;
            l3 = newptr;
        }
        else{
            newptr->next = NULL;
            cur->next = newptr;
        }

    }
    
    
    return l3;
}