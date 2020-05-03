//Time Complexity : O(nlogn)
//Space Complexity : constant
ListNode* merge(ListNode* A, ListNode* B){
    ListNode* temp =new ListNode(0);
    ListNode* ans=temp;
    while(A&&B){
        if(A->val<B->val)
        {
            temp->next=A;
            A=A->next;
        }
        else{
            temp->next=B;
            B=B->next;
        }
        temp=temp->next;
    }
    if(A)
    temp->next=A;
    if(B)
    temp->next=B;
    return ans->next;
}
ListNode* divide (ListNode* A){
    if(A==NULL || A->next==NULL)
    return NULL;
    ListNode* slowprev=NULL;
    ListNode* slow=A;
    ListNode* fast=A;
    while(fast && fast->next){
        fast=fast->next->next;
        slowprev=slow;
        slow=slow->next;
    }
    slowprev->next=NULL;
    return slow;
}
ListNode* Solution::sortList(ListNode* A) {
    if(A==NULL || A->next==NULL)
    return A;
    ListNode* B = divide(A);
    A=sortList(A);
    B=sortList(B);
    return merge(A,B);
}

