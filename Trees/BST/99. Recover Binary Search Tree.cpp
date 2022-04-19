/*
logic is to figure out which two nodes are the first and the second one when placed according to inorder traversal 
baaki need to dig more into pass by refernce
discuss morris traversal solution as well as it'll help in acheiving optimised space complexity
*/
class Solution {
public:
    void inorder(TreeNode *root,TreeNode *&firstNode,TreeNode *&secondNode,TreeNode *&prev){
        if(root!=NULL){
            inorder(root->left,firstNode,secondNode,prev);
            
            //do some of our own work here
            if(prev){
                if(root->val < prev->val){
                    if(firstNode==NULL){
                        firstNode=prev;
                    }
                    
                    // else{
                        secondNode=root;
                    // }
                }
            }
            
            prev=root;
            
            inorder(root->right,firstNode,secondNode,prev);
        }
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode *firstNode=NULL,*secondNode=NULL,*prev=NULL;
        inorder(root,firstNode,secondNode,prev);
        swap(firstNode->val,secondNode->val);
    }
};