ListNode* Solution::deleteDuplicates(ListNode* A) {
    //adding Extra Node at beginning
    ListNode* ptr = new ListNode(0);
    ptr->next=A;
    ListNode* prev=ptr;
    ListNode* curr=A;
    while(curr->next){
        if(curr->val==curr->next->val){
            prev->next=curr->next;
            curr=curr->next;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    return ptr->next;
}

