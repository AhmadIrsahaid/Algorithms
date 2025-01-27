#include <iostream>
#include"TreeImp.h"
using namespace std;
int main() {
    BST<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder Traversal (LNR): ";
    tree.inorderTraversal();
    cout << endl;

    cout << "Preorder Traversal (NLR): ";
    tree.preorderTraversal();
    cout << endl;

    cout << "Postorder Traversal (LRN): ";
    tree.postorderTraversal();
    cout << endl;

    cout << "Reverse Postorder Traversal (RNL): ";
    tree.reversePostorderTraversal();
    cout << endl;

    if (tree.search(19) != NULL)
        cout << "Found 19\n";
    else
        cout << "Not Found 19\n";

    if (tree.search(80) != NULL)
        cout << "Found 80\n";
    else
        cout << "Not Found 80\n";

   
    tree.deleteKey(20);
    cout << "Inorder Traversal after deleting 20: ";
    tree.inorderTraversal();
    cout << endl;

    
    cout << "Is 50 the root? " << (tree.isRoot(50) ? "Yes" : "No") << endl;
    cout << "Is 30 a parent? " << (tree.isParent(30) ? "Yes" : "No") << endl;
    cout << "Is 40 a leaf? " << (tree.isLeaf(40) ? "Yes" : "No") << endl;

    Node<int>* successor = tree.getSuccessor(30);
    if (successor != NULL) {
        cout << "Successor of 30: " << successor->key << endl;
    }
    else {
        cout << "No successor found for 30\n";
    }

    return 0;
}

