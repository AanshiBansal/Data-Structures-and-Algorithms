//https://www.interviewbit.com/problems/postorder-traversal/

void postorderRecursive(TreeNode* A, vector<int>&ans){
	if(A==NULL)
	return;
	postorderRecursive(A->left,ans);
	postorderRecursive(A->right,ans);
	ans.push_back(A->val);
	return;
}

vector<int> postorder(TreeNode* A){
	vector<int>ans;
	postorderRecursive(A,ans);
	return ans;
}

vector<int> postorderTraversal(TreeNode* A) {
    vector<int>ans;
    if(A==NULL)
    return ans;
    stack<TreeNode*>s;
    s.push(A);
    while(!s.empty()){
        A=s.top();
        s.pop();
        if(A->left)
        s.push(A->left);
        if(A->right)
        s.push(A->right);
        ans.push_back(A->val);
    }
    vector<int>result;
    for(int i=ans.size()-1;i>=0;i--){
        result.push_back(ans[i]);
    }
    return result;
}

