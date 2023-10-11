/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

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
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write code here
        ListNode *vHead = new ListNode(0);
        vHead->next = head;

        int reverseNum = n - m + 1, k = m - 1;

        // 找到反转区间的前一个节点
        ListNode *p = vHead, *preHead = vHead, *tail;
        while (k--) p = p->next;
        preHead = p;

        p = p->next;
        tail = p;

        while (reverseNum-- && p != nullptr) {
            if (p == preHead->next) {
                p = p->next;
                continue;
            }

            ListNode *temp = p->next;
            // p 头插
            p->next = preHead->next;
            preHead->next = p;

            p = temp;
            tail->next = temp;
        }
        return vHead->next;
    }
};