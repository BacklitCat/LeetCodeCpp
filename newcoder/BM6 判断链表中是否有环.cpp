/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 快慢指针
    bool hasCycle(ListNode *head) {
        ListNode *fast=head, *slow=head;
        while (fast) {
            if(fast->next && fast->next->next){
                fast = fast->next->next;
                slow = slow ->next;
                if (fast == slow){
                    return true;
                }
            }else {
                return false;
            }
        }
        return false;
    }
};