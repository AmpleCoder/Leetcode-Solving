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
    void reorderList(ListNode* head) {
        if(head->next == NULL || head->next->next == NULL){
            return;
        }

        ListNode *head1 = head;
        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *head2 = slow->next;
        ListNode *prev = NULL;
        ListNode *temp;
        slow->next = NULL;

        while(head2){
            temp = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = temp;
        }

        head2 = prev;

        while(head1 && head2){
            ListNode *tempHead1 = head1->next;
            ListNode *tempHead2 = head2->next;
            head1->next = head2;
            head2->next = tempHead1;
            head1 = tempHead1;
            head2 = tempHead2;
        }
    }
};