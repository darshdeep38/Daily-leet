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
    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes
        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }

    // Function to find the middle node
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Main function to sort list
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Split list into two halves
        ListNode* mid = getMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;

        // Sort each half recursively
        ListNode* left = sortList(head);
        right = sortList(right);

        // Merge the two sorted halves
        return merge(left, right);
    }
};
