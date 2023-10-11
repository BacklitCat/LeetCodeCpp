struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // 快慢指针 指向删除节点的前一个节点
        auto vHead = new ListNode(0);
        vHead->next = head;

        ListNode *fast = vHead, *slow = vHead, *t;
        int k = n + 1;
        while (k--) { // 题目保证n正确
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        // cout << slow -> val;
        // slow 为删除节点的前置节点 t 为删除节点
        t = slow->next;
        slow->next = t->next;
        free(t);
        return vHead->next;
    }
};