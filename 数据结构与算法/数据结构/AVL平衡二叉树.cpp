#include <bits/stdc++.h>

using namespace std;

struct Tree {
    int val;
    Tree *left;
    Tree *right;

    Tree() {}

    Tree(int val) : val(val), left(nullptr), right(nullptr) {}
};

/**
 * 左旋
 * @param p
 */
void leftRotate(Tree *p) {
    Tree *root = p->right;
    p->right = root->left;
    root->left = p;
    p = root;
}

/**
 * 右旋
 * @param p
 */
void rightRotate(Tree *p) {
    Tree *root = p->left;
    p->left = root->right;
    root->right = p;
    p = root;
}

/**
 * 二叉树查找\n
 * 时间复杂度O(log_2(n))
 * @param tree 树根节点
 * @param key 查询的关键词
 * @return 关键词所在的节点
 */
Tree *searchBST(Tree *tree, int key) {
    Tree *p = tree;
    while (p != nullptr) {
        if (key == p->val) {
            return p;
        }
        if (key < p->val) {
            p = p->left;
        }
        if (key > p->val) {
            p = p->right;
        }
    }
    return nullptr;
}

/**
 * 二叉树插入
 * @param root 树的根节点
 * @param val 插入的值
 * @return 返回插入的状态
 */
bool insertBST(Tree *root, int val) {
    if (root == nullptr) {
        root = new Tree(val);
        return true;
    }
    Tree *p = root;
    Tree *s = root;
    while (true) {
        if (p == nullptr) {
            if (s->val < val) {
                s->right = new Tree(val);
            } else {
                s->left = new Tree(val);
            }
            return true;
        }
        s = p;
        if (p->val == val) {
            return false;
        } else if (p->val < val) {
            p = p->right;
        } else {
            p = p->left;
        }
    }
}


/**
 * 二叉树删除的基础操作
 * @param p 删除节点
 * @return 删除的状态
 */
bool deleteBase(Tree *p) {
    Tree *q = p;
    Tree *s = new Tree();
    if (p->right == nullptr) {
        p = p->left;
        delete q;
    } else if (p->left == nullptr) {
        p = p->right;
        delete q;
    } else {
        s = p->left;
        while (s->right != nullptr) {
            q = s;
            s = s->right;
        }
        p->val = s->val;
        if (q != p) {
            q->right = s->left;
        } else {
            q->left = s->left;
        }
        delete s;
    }
    return true;
}

/**
 * 二叉树删除
 * @param p 根节点
 * @param key 删除点的值
 * @return 删除的状态
 */
bool deleteBST(Tree *p, int key) {
    if (p == nullptr) {
        return false;
    }
    if (p->val == key) {
        return deleteBase(p);
    } else if (p->val < key) {
        return deleteBST(p->right, key);
    } else {
        return deleteBST(p->left, key);
    }
}