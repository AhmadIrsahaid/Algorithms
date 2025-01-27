// BST.h
#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T key;
    Node* left;
    Node* right;

    Node(T item) {
        key = item;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class BST {
private:
    Node<T>* root;

    Node<T>* insertRecursive(Node<T>* node, T x) {
        if (node == NULL) {
            return new Node<T>(x);
        }

        if (x < node->key) {
            node->left = insertRecursive(node->left, x);
        }
        else if (x > node->key) {
            node->right = insertRecursive(node->right, x);
        }

        return node;
    }

    Node<T>* insertIterative(Node<T>* node, T x) {
        Node<T>* temp = new Node<T>(x);

        if (node == NULL)
            return temp;

        Node<T>* parent = NULL;
        Node<T>* curr = node;

        while (curr != NULL) {
            parent = curr;
            if (curr->key > x)
                curr = curr->left;
            else if (curr->key < x)
                curr = curr->right;
            else
                return node;
        }

        if (parent->key > x)
            parent->left = temp;
        else
            parent->right = temp;

        return node;
    }

    void inorder(Node<T>* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }

    void preorder(Node<T>* node) {
        if (node != NULL) {
            cout << node->key << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node<T>* node) {
        if (node != NULL) {
            postorder(node->left);
            postorder(node->right);
            cout << node->key << " ";
        }
    }

    void reversePostorder(Node<T>* node) {
        if (node != NULL) {
            reversePostorder(node->right);
            reversePostorder(node->left);
            cout << node->key << " ";
        }
    }

    Node<T>* searchRecursive(Node<T>* node, T key) {
        if (node == NULL || node->key == key)
            return node;

        if (node->key < key)
            return searchRecursive(node->right, key);

        return searchRecursive(node->left, key);
    }

    Node<T>* minValueNode(Node<T>* node) {
        Node<T>* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    Node<T>* deleteNode(Node<T>* root, T key) {
        if (root == NULL)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == NULL) {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }

            Node<T>* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    
    Node<T>* getSuccessorNode(Node<T>* node) {
        return minValueNode(node->right);
    }

    
    void deleteTree(Node<T>* node) {
        if (node == NULL) return;

        
        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        
        deleteTree(root);
    }

    void insert(T x) {
        root = insertRecursive(root, x);
    }

    void insertUseIterative(T x) {
        root = insertIterative(root, x);
    }

    void inorderTraversal() {
        inorder(root);
    }

    void preorderTraversal() {
        preorder(root);
    }

    void postorderTraversal() {
        postorder(root);
    }

    void reversePostorderTraversal() {
        reversePostorder(root);
    }

    Node<T>* search(T key) {
        return searchRecursive(root, key);
    }

    void deleteKey(T key) {
        root = deleteNode(root, key);
    }

    bool isRoot(T key) {
        return root != NULL && root->key == key;
    }

    bool isParent(T key) {
        Node<T>* node = search(key);
        if (node == NULL) return false;
        return node->left != NULL || node->right != NULL;
    }

    bool isLeaf(T key) {
        Node<T>* node = search(key);
        if (node == NULL) return false;
        return node->left == NULL && node->right == NULL;
    }

    Node<T>* getSuccessor(T key) {
        Node<T>* node = search(key);
        if (node == NULL) return NULL;
        return getSuccessorNode(node);
    }
};
