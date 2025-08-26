//Problem 86 Leetcode :- Partition List  
//Statement:- Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.
//Below is the C++ solution for the same: 

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
    ListNode* partition(ListNode* head, int x) {
        


        ListNode* small = new ListNode(0);
        ListNode* large  = new ListNode(0);

        ListNode* smallPtr = small;
        ListNode* largePtr = large ;

        while(head != NULL){

            if( head-> val < x){
                smallPtr -> next = head;
                smallPtr = smallPtr-> next ;
            }
            else{
                largePtr -> next = head ; 
                largePtr = largePtr ->next ;
            }

            head = head->next;
        }

        smallPtr -> next = large->next;
        largePtr -> next = NULL;
        head = small-> next ;

        return head;

    }
};

//
//equivalent java code
//
class ListNode {
    int val;
    ListNode next;
    ListNode(int val) {
        this.val = val;
    }
}

class Solution {
    public ListNode partition(ListNode head, int x) {
 
        ListNode small = new ListNode(0);
        ListNode large = new ListNode(0);
        

        ListNode smallPtr = small;
        ListNode largePtr = large;
        
        while (head != null) {
            if (head.val < x) {
                smallPtr.next = head;
                smallPtr = smallPtr.next;
            } else {
                largePtr.next = head;
                largePtr = largePtr.next;
            }
            head = head.next;
        }


        smallPtr.next = large.next;
        largePtr.next = null; // Important to avoid cycle

        return small.next;
    }
}

