//Given a linked list and a value x, partition it 
//such that all nodes less than x come before nodes greater than or equal to x.
ListNode* Solution::partition(ListNode* A, int B) {
	//adding Extra Nodes
    ListNode* less= new ListNode(0);
    ListNode* equalMore= new ListNode(0);
    ListNode* ptrLess=less;
    ListNode* ptrEqualMore=equalMore;
    while(A){
        if(A->val<B){
            less->next=A;
            less=less->next;
        }else{
                equalMore->next=A;
                equalMore=equalMore->next;
        }
        A=A->next;
    }
    less->next=ptrEqualMore->next;
    equalMore->next=NULL;
    return ptrLess->next;
}

