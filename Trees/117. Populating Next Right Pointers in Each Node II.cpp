/*
the most noob solution which i can think of
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        
        queue<Node*> q;
        Node *prev;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            prev=NULL;
            
            for(int i=0;i<size;i++){
                Node *currNode = q.front();
                q.pop();
                
                if(prev!=NULL){
                    prev->next=currNode;
                }
                
                if(currNode->left){
                    q.push(currNode->left);
                }
                
                if(currNode->right){
                    q.push(currNode->right);
                }
                
                prev=currNode;
            }
        }
        
        return root;
    }
};

/*
refer solution section well explained
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void process(Node *&childNode,Node *&prevChildNode,Node *&leftMost){
        if(childNode!=NULL){
            if(prevChildNode!=NULL){
                prevChildNode->next=childNode;
            } else{
                leftMost=childNode;  
            }
            
            prevChildNode = childNode;
        }
    }
    
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        
        Node *curr,*prevChildNode,*leftMost;
        leftMost=root;
        
        while(leftMost!=NULL){
            curr=leftMost;
            prevChildNode=NULL;
            leftMost=NULL;//most important step
            
            while(curr!=NULL){
                process(curr->left,prevChildNode,leftMost);
                process(curr->right,prevChildNode,leftMost);
                curr=curr->next;
            }
        }
        
        return root;
    }
};