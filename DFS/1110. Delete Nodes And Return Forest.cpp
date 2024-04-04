/*
this is one of the intuitive problem where before solving this we need to have a deep understanding of where things might go wrong
(if we delete certain node which is to be deleted whoses level is lesser than the other to be deleted)
so folowing this we can simple maintain the levels of the nodes and after that we can sort the nodes on the basis of decreasing levels
of nodes to be deleted then after that we can maintains parents of each nodes after that and after that things are pretty simple only case we 
need to consider is for root at the end 
try thinking this you can simply do that :)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> level;
    vector<TreeNode*> ans;
    unordered_map<TreeNode*,TreeNode*> parent;
    unordered_map<int,TreeNode*> mapping;
    
    void dfs_lvl(TreeNode *root,TreeNode *par,int lvl)
    {
        parent[root]=par;
        
        if(root!=NULL)
        {
            mapping[root->val]=root;
            level[root->val]=lvl;
            dfs_lvl(root->left,root,lvl+1);
            dfs_lvl(root->right,root,lvl+1);
        }
    }
    
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        level.resize(1001,0);
        dfs_lvl(root,NULL,0);
        sort(to_delete.begin(),to_delete.end(),[&](const int &a,const int &b){
            return level[a]>level[b];
        } );
        
        bool flag=1;
        
        for(auto &x:to_delete)
        {
            TreeNode *ref=mapping[x];
            TreeNode *par=parent[ref];
            TreeNode *leftChild=ref->left;
            TreeNode *rightChild=ref->right;
            
            if(leftChild!=NULL)
            {
                ans.push_back(leftChild);
            }
            
            if(rightChild!=NULL)
            {
                ans.push_back(rightChild);
            }
            
            if(par==NULL)
            {
                flag=0;
                break;
            }
            
            if(par->left!=NULL && par->left->val==x)
            {
                par->left=NULL;
            }
            
            else if(par->right!=NULL && par->right->val==x)
            {
                par->right=NULL;
            }
        }
        
        if(flag==1)
        {
            ans.push_back(root);
        }
        
        return ans;
    }
};

/*
    approach 2:
        for each node set kr diya parent ko then uske bad we've to delete this node for that before deleting this node 
        2 things we've to do 
            1) set parent of it's left and right child to NULL if they exist
            2) set curr nodes parent's left if this node is left child or right to null

        then delete this node
*/
class Solution {
public:
    void setParent(unordered_map<TreeNode*, TreeNode*>  &parentMap, TreeNode* currNode, TreeNode* parent){
        if(currNode == NULL){
            return;
        }

        parentMap[currNode] = parent;
        setParent(parentMap, currNode->left, currNode);
        setParent(parentMap, currNode->right, currNode);
    }

    void setValueToNodeMap(unordered_map<int, TreeNode*> &valueToNodeMap, unordered_map<TreeNode*, TreeNode*> &parentMap){
        for(auto currMapElement: parentMap){
            TreeNode* currNode = currMapElement.first;
            int currValue = currNode->val;
            valueToNodeMap[currValue] = currNode;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        unordered_map<int, TreeNode*> valueToNodeMap;
        setParent(parentMap, root, NULL);
        setValueToNodeMap(valueToNodeMap, parentMap);
        vector<TreeNode*> forest;

        for(int currNodeValue: to_delete){
            TreeNode *currNode = valueToNodeMap[currNodeValue];
            TreeNode *currParent = parentMap[currNode];
            TreeNode *leftChild = currNode->left;
            TreeNode *rightChild = currNode->right;

            
            //if curr node par exist 
            if(currParent != NULL){
                //if node to be deleted is left child 
                if(currParent->left != NULL && currParent->left->val == currNodeValue){
                    currParent->left = NULL;
                }

                //if node to be deleted is right child 
                if(currParent->right != NULL && currParent->right->val == currNodeValue){
                    currParent->right = NULL;
                }
            }

            if(leftChild != NULL){
                parentMap[leftChild] = NULL;
            }
            
            if(rightChild != NULL){
                parentMap[rightChild] = NULL;
            }

            //delete the node
            parentMap.erase(currNode);
        }

        for(auto currParentMapNode: parentMap){
            TreeNode *currNode = currParentMapNode.first;
            TreeNode *parentNode = currParentMapNode.second;

            if(parentNode == NULL){
                forest.push_back(currNode);
            }
        }

        return forest;
    }
};