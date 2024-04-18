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
    bool isSmaller(string &result, string &currStr){
        int sizeRes = result.size();
        int sizeCurrStr = currStr.size();
        // cout << result << " " << currStr << endl;

        int i = sizeRes - 1, j = sizeCurrStr - 1;

        while(i >= 0 && j >= 0){
            if(result[i] == currStr[j]){
                i--;
                j--;
            }

            else if(result[i] < currStr[j]){
                return false;
            }

            else{
                return true;
            }
        }

        if(i >= 0 && j < 0){
            return true;
        }

        return false;
    }

    void smallestFromLeafUtil(TreeNode *root, string currStr, string &result){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            currStr.push_back(root->val + 'a');
            // cout << currStr << endl;
            if(result.size() == 0){
                result = currStr;
            }

            else if(isSmaller(result, currStr)){
                result = currStr;
            }

            currStr.pop_back();

            return;
        }

        char currChar = root->val + 'a';

        currStr.push_back(currChar);
        smallestFromLeafUtil(root->left, currStr, result);
        smallestFromLeafUtil(root->right, currStr, result);
        currStr.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        string result;
        string currStr;
        smallestFromLeafUtil(root, currStr, result);
        reverse(result.begin(), result.end());
        return result;
    }
};