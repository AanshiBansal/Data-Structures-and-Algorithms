//https://www.interviewbit.com/problems/preorder-traversal/

void preorderRecursive(TreeNode* A, vector<int>&ans){
	if(A==NULL)
	return;
	ans.push_back(A->val);
	preorderRecursive(A->left,ans);
	preorderRecursive(A->right,ans);
	return;
}

vector<int> preorder(TreeNode* A){
	vector<int>ans;
	preorderRecursive(A,ans);
	return ans;
}

vector<int> preorderTraversal(TreeNode* A) {
    vector<int>ans;
    if(A==NULL)
    return ans;
    stack<TreeNode*>s;
    s.push(A);
    while(!s.empty()){
            A=s.top();
            s.pop();
            ans.push_back(A->val);
            if(A->right!=NULL)
                s.push(A->right);
            if(A->left!=NULL)
                s.push(A->left);
        }
    return ans;
}

