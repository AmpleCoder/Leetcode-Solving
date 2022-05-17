/*
simple and crisp code 
*/

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL){
            return NULL;
        }
        
        if(original==target){
            return cloned;
        }
        
        TreeNode *getTargetFromLeft=getTargetCopy(original->left,cloned->left,target);
        if(getTargetFromLeft!=NULL){
            return getTargetFromLeft;
        }
        
        TreeNode *getTargetFromRight=getTargetCopy(original->right,cloned->right,target);
        if(getTargetFromRight!=NULL){
            return getTargetFromRight;
        }
        
        return NULL;
    }
};