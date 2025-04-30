#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>
#include <string>

template <typename T>
class RedBlackTree {
private:
    struct Node {
        T data;
        Node* parent;
        Node* left;
        Node* right;
        bool isRed;

        Node(T val, Node* p = nullptr, Node* l = nullptr, Node* r = nullptr, bool red = true)
            : data(val), parent(p), left(l), right(r), isRed(red) {
        }
    };

    Node* root;
    Node* nil;

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nil) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nil) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nil) y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nil) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node* z) {
        while (z->parent->isRed) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;
                if (y->isRed) {
                    z->parent->isRed = false;
                    y->isRed = false;
                    z->parent->parent->isRed = true;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        rotateLeft(z);
                    }
                    z->parent->isRed = false;
                    z->parent->parent->isRed = true;
                    rotateRight(z->parent->parent);
                }
            }
            else {
                Node* y = z->parent->parent->left;
                if (y->isRed) {
                    z->parent->isRed = false;
                    y->isRed = false;
                    z->parent->parent->isRed = true;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rotateRight(z);
                    }
                    z->parent->isRed = false;
                    z->parent->parent->isRed = true;
                    rotateLeft(z->parent->parent);
                }
            }
        }
        root->isRed = false;
    }

    void printInOrder(Node* node) const {
        if (node != nil) {
            printInOrder(node->left);
            std::cout << node->data << " ";
            printInOrder(node->right);
        }
    }

public:
    RedBlackTree() {
        nil = new Node(T());
        nil->isRed = false;
        root = nil;
    }

    ~RedBlackTree() {
    }

    void add(T value) {
        Node* z = new Node(value);
        z->left = nil;
        z->right = nil;
        z->isRed = true;

        Node* y = nil;
        Node* x = root;

        while (x != nil) {
            y = x;
            if (z->data < x->data) x = x->left;
            else x = x->right;
        }

        z->parent = y;
        if (y == nil) root = z;
        else if (z->data < y->data) y->left = z;
        else y->right = z;

        fixInsert(z);
    }

    bool has(T value) const {
        Node* current = root;
        while (current != nil) {
            if (value == current->data) return true;
            else if (value < current->data) current = current->left;
            else current = current->right;
        }
        return false;
    }

    void print() const {
        printInOrder(root);
        std::cout << std::endl;
    }
};

#endif