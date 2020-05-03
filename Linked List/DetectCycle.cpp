//Time Complexity O(length of List)
//Space Complexity O(length of List)
//one Pass
ListNode* Solution::detectCycle(ListNode* A) {
    unordered_set<ListNode*>s;
    while(A){
        if(s.find(A)==s.end())
        s.insert(A);
        else
        return A;
        A=A->next;
    }
    return NULL;
}

