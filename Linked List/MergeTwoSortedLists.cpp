ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
	//adding Extra Node at beginning
    ListNode* ptr = new ListNode(0);
    ListNode* sol = ptr;
    while(A&&B){
        if(A->val<B->val){
            sol->next=A;
            A=A->next;
            sol=sol->next;
        }
        else{
            sol->next=B;
            B=B->next;
            sol=sol->next;
        }
    }
    if(A)
    sol->next=A;
    else
    sol->next=B;
    return ptr->next;
}

