//Reverse a linked list from position m to n. Do it in-place and in one-pass.
//1 <= m <= n <= length of list
ListNode* reverse(ListNode* A, int count){
    ListNode* temp=A;
    ListNode* curr=A;
    ListNode* prev=NULL;
    ListNode* next;
    while(count){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count--;
    }
    temp->next=curr;
    return prev;
}
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode* ptr=new ListNode(0);
    ptr->next=A;
    ListNode* prev=NULL;
    ListNode* curr=ptr;
    int num=B;
    //we start with extra node
    //with first jump we ewach first node
    while(num){
        prev=curr;
        curr=curr->next;
        num--;
    }
    prev->next=reverse(curr,C-B+1);
    return ptr->next;
}

