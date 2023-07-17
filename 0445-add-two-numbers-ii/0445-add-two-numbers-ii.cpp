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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next1 = NULL;
        
        while(curr != NULL){
            next1 = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next1;
        }
        
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = reverse(l1);
        ListNode* temp2 = reverse(l2);
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;
        while(temp1 != NULL || temp2 != NULL || carry != 0){
            int val1 = 0;
            if(temp1 != NULL){
                val1 = temp1 -> val;
                temp1 = temp1 -> next;
            }
            
            int val2 = 0;
            if(temp2 != NULL){
                val2 = temp2 -> val;
                temp2 = temp2 -> next;
            }
            
            int sum = val1 + val2 + carry;
            ListNode* newN = new ListNode(sum % 10);
            carry = sum / 10;
            temp -> next = newN;
            temp = temp -> next;
        }
        
        return reverse(dummy -> next);
    }
};