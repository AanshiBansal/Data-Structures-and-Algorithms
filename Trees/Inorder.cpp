//https://www.interviewbit.com/problems/inorder-traversal/
//Iterative approach very imp


void inorderRecursive(TreeNode* A, vector<int>&ans){
	if(A==NULL)
	return;
	inorderRecursive(A->left,ans);
	ans.push_back(A->val);
	inorderRecursive(A->right,ans);
	return;
}

vector<int> inorder(TreeNode* A){
	vector<int>ans;
	inorderRecursive(A,ans);
	return ans;
}

vector<int> inorderTraversal(TreeNode* A) {
    vector<int>ans;
    stack<TreeNode*>s;
    while(A || !s.empty()){
        while(A){
            s.push(A);
            A=A->left;
        }
        TreeNode* top=s.top();
        s.pop();
        ans.push_back(top->val);
        A=top->right;
    }
    return ans;
}
