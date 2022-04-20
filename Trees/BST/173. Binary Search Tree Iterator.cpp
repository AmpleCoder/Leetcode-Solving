/*
here the concept which is used is iterative inorder traversal 
first push all the nodes into the stack till left then pop nodes out then 
explore the right child of popped node in the above mentioned way

todo: solve all 
*/
class BSTIterator {
public:
    stack<TreeNode*> s;
    
    BSTIterator(TreeNode* root) {
        pushNodesintoTheStack(root);
    }
    
    void pushNodesintoTheStack(TreeNode *root){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode *topNode=s.top();
        s.pop();
        pushNodesintoTheStack(topNode->right);
        return topNode->val;
    }
    
    bool hasNext() {
        return (!s.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */