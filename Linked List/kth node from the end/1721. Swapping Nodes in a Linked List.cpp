/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *kthBegning=NULL,*kthEnd=head,*fast=head;
        
        for(int i=0;i<k;i++)
        {
            kthBegning=fast;
            fast=fast->next;
        }
        
        // cout<<fast->val<<endl;
        
        while(fast!=NULL)
        {
            kthEnd=kthEnd->next;
            fast=fast->next;
        }
        
        // cout<<kthBegning->val<<" "<<kthEnd->val;
        
        int temp = kthEnd->val;
        kthEnd->val = kthBegning->val;
        kthBegning->val = temp;
        
        return head;
    }
};