#include <unordered_map>
#include <iostream>

using namespace std;
struct LinkNode {
    int key;
    int val;
    LinkNode *left;
    LinkNode *right;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Mid 146 https://leetcode.cn/problems/lru-cache
class LRUCache {
public:
    int cap;
    int len;
    LinkNode *head;
    unordered_map<int, LinkNode *> hashMap;

    LRUCache(int capacity) {
        len = 0;
        cap = capacity;
        head = new(LinkNode);
        head->left = nullptr;
        head->right = nullptr;
    }

    void printLRU() {
        cout << head->left << " " << head->right << " ";
        LinkNode *p = head->right;
        while (p != nullptr) {
            cout << "[" << p->key << "," << p->val << "]";
            p = p->right;
        }
    }

    // node 必须在链上
    void move(LinkNode *node) {
        if (head->right == node) { return; }

        // 修改左右节点
        node->left->right = node->right; // 修改左节点的右指针
        if (node->right != nullptr) { // 如果不是尾节点
            node->right->left = node->left; // 修改右节点的左指针
        } else {
            head->left = node->left; // 更新尾节点指针
        }

        // 修改自身
        node->left = head;
        node->right = head->right;

        // 修改头节点
        head->right->left = node; // 修改第一个节点的左指针
        head->right = node; // 修改头节点指针

//        cout << "after move ";
//        printLRU();
//        cout << endl;
    }

    int get(int key) {
//        cout << "get " << key << endl;
        auto node = hashMap.find(key);
        if (node == hashMap.end()) {
//            cout << "after get ";
//            printLRU();
//            cout << endl;
            return -1;
        } else {
            // 调整位置
            move(node->second);
//            cout << "after get and move";
//            printLRU();
//            cout << endl;
            return node->second->val;
        }
    }

    void put(int key, int value) {
//        cout << "put " << key << "-" << value << endl;
        // 如果已经存在，则修改值
        if (get(key) != -1) {
            head->right->val = value;
            return;
        }

        // 如果不在其中，则需要插入
        LinkNode *p;
        if (cap == len) {
            // 复用尾节点空间，避免重复申请内存
            p = head->left;
//            cout << head->left << " " << head->right << " " << p;
            // 淘汰
            hashMap.erase(p->key);
            // 移动
            move(p);
        } else {
            // 创建新节点
            p = new(LinkNode);
            p->left = head;
            p->right = head->right;
            if (head->right != nullptr) {
                head->right->left = p;
            } else {
                head->left = p;
            }
            head->right = p;
            len++;
        }
        // 更新
        p->key = key;
        p->val = value;
        hashMap[key] = p;
//        cout << "after put ";
//        printLRU();
//        cout << endl;
    }
};