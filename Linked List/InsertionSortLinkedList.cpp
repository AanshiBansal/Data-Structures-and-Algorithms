ListNode* Solution::insertionSortList(ListNode* A) {
	//adding Extra Node at beginning
    ListNode* ptr= new ListNode(INT_MIN);
    ptr->next=A;
    ListNode* curr=A;
    ListNode* prev=ptr;
    while(curr){
        if(curr->val>=prev->val){
            prev=curr;
            curr=curr->next;
        }
        else{
            ListNode* wait=curr;
            prev->next=curr->next;
            curr=curr->next;
            ListNode* check=ptr->next;
            ListNode* prevCheck=ptr;
            while(1){
                if(wait->val<check->val){
                    prevCheck->next=wait;
                    wait->next=check;
                    break;
                }
                else{
                    prevCheck=check;
                    check=check->next;
                }
            }
        }
    }
    return ptr->next;
}

