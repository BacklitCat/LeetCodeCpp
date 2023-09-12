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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead1 ListNode类
     * @param pHead2 ListNode类
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // write code here
        auto vHead = new ListNode(0);
        ListNode* p = pHead1, *q = pHead2, *t, *m, *insert = vHead;
        while (p != nullptr && q != nullptr) {
            // if (p->val <= q->val) {
            //     m = p;
            // } else {
            //     m = q;
            // }

            m = p->val <= q->val ? p : q;
            // cout << m->val << " ";
            t = m->next;
            insert->next = m;
            m->next = nullptr;
            insert = m;

            if (p->val <= q->val) {
                p = t;
            } else {
                q = t;
            }
        }
        while (p != nullptr){
            t = p->next;
            insert->next = p;
            p->next = nullptr;
            insert = p;
            p = t;
        }
        while (q != nullptr){
            t = q->next;
            insert->next = q;
            q->next = nullptr;
            insert = q;
            q = t;
        }
        return vHead -> next;
    }
};