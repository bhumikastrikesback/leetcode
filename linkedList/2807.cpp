//2807. Insert Greatest Common Divisors in Linked List
/*Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

*/

 
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* nxt = curr->next;

            int g = gcd(curr->val, nxt->val);

            ListNode* node = new ListNode(g);

            // insert in between
            curr->next = node;
            node->next = nxt;

            // move ahead
            curr = nxt;
        }

        return head;
    }
};