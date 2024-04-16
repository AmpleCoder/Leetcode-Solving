/*
    approach:
        pretty simple i felt simulate whatever is asked
*/
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            newRoot->right = NULL;
            return newRoot;
        }

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while(!q.empty()){
            auto [currNode, currDepth] = q.front();
            q.pop();

            if(currDepth == depth - 1){
                TreeNode *newNodeLeft = new TreeNode(val);
                TreeNode *currLeftChild = currNode->left;
                currNode->left = newNodeLeft;
                newNodeLeft->left = currLeftChild;
                if(currLeftChild != NULL){
                    q.push({currLeftChild, currDepth + 2});
                }
                

                
                TreeNode *newNodeRight = new TreeNode(val);
                TreeNode *currRightChild = currNode->right;
                currNode->right = newNodeRight;
                newNodeRight->right = currRightChild;
                if(currRightChild != NULL){
                    q.push({currRightChild, currDepth + 2});
                }
            }

            else{
                if(currNode->left != NULL){
                    q.push({currNode->left, currDepth + 1});
                }

                if(currNode->right != NULL){
                    q.push({currNode->right, currDepth + 1});
                }
            }
        }

        return root;
    }
};