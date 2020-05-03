//If B is greater than the size of the list, remove the first node of the list.
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* slow=A;
    ListNode* fast=A;
    //adding Extra Node at beginning
    ListNode* ans=new ListNode(0);
    ans->next=A;
    ListNode* prev=ans;
    while(fast && B>0){
        fast=fast->next;
        B--;
    }
    if(B!=0)
    return A->next;
    while(fast){
        prev=slow;
        slow=slow->next;
        fast=fast->next;
    }
    prev->next=slow->next;
    return ans->next;
}
