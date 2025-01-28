#pragma once
#include<iostream>
#include <queue>
#include<vector>
#include <string>
using namespace std;
class Node {
public:
    char data;
    int count;
    Node* left;
    Node* right;

    Node(char data, int freq) {
        this->data = data;
        this->count = freq;
        left = NULL;
        right = NULL;
    }

    ~Node() {
        delete left;
        delete right;
    }
};

class compareNode {
public:
    bool operator()(Node* a, Node* b) {
        return a->count > b->count;
    }
};

void generateNode(Node* root, string code, string codes[])
{
    if (root == NULL) {
        return;
    }
    if (!root->left && !root->right) {
        codes[root->data - 'a'] = code;
    }
    generateNode(root->left, code + "0", codes);
    generateNode(root->right, code + "1", codes);
}

// Function to generate Huffman codes for the paragraph
void HuffmanCodes(string paragraph, int occurrences[], string codes[], priority_queue<Node*, vector<Node*>, compareNode>& PriorityQueue)
{
    for (int i = 0; i < paragraph.length(); ++i) {
        char c = paragraph[i];
        if (isalpha(c)) {
            c = tolower(c);
            occurrences[c - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (occurrences[i] > 0) {
            PriorityQueue.push(new Node('a' + i, occurrences[i]));
        }
    }

    while (PriorityQueue.size() != 1) {
        Node* left = PriorityQueue.top();
        PriorityQueue.pop();
        Node* right = PriorityQueue.top();
        PriorityQueue.pop();

        int sumFreq = left->count + right->count;
        Node* newNode = new Node(NULL, sumFreq);
        newNode->left = left;
        newNode->right = right;
        PriorityQueue.push(newNode);
    }
    generateNode(PriorityQueue.top(), "", codes);
}

// Function to encode a string using Huffman codes
string encode(string input, string codes[]) {
    string encodedString = "";
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (isalpha(c)) {
            c = tolower(c);
            encodedString += codes[c - 'a'];
        }
    }
    return encodedString;
}

string decode(string encodedString, Node* root)
{
    string decodedString = "";
    Node* current = root;
    for (int i = 0; i < encodedString.length(); i++)
    {
        char bit = encodedString[i];
        if (bit == '0') {
            current = current->left;
        }
        else if (bit == '1') {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            decodedString += current->data;
            current = root;
        }
    }
    return decodedString;
}
