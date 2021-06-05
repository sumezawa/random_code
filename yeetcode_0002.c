/* CASE 2: ADDING DIGITS IN LINKED-LISTS */

#include <stdlib.h> // malloc()

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
    // Unlike in C++, the user-defined datatypes must always be preceded by
    // the keyword 'struct'
};

/* O(n) LINKED LIST ADDER */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode head; // holds the pointer to the head of the list
    struct ListNode* newlist = &head;
    bool carry = false;
    int digit;

    // SPECIAL CASES (TO SPEED UP CODE)
    if (!l1 && !l2) {
        return NULL;
    }
    else if (l1 && !l2) {
        return l1;
    }
    else if (!l1 && l2) {
        return l2;
    }

    // NORMAL CASES
    while (l1 || l2 || carry) { // expands the list, until l1, l2, and carry are all 0/nullptr
        digit = 0;
        if (carry) {
            ++digit;
            carry = false;
        }
        if (l1) {
            digit += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            digit += l2->val;
            l2 = l2->next;
        }
        carry = digit > 9;
        // Unlike in C++, value initialisations are done manually (there are no constructors)
        newlist->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        newlist->next->val = digit % 10;
        newlist->next->next = NULL;
        newlist = newlist->next;
    }
    return head.next;
}
