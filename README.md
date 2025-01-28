# Data Structures and Algorithms

This repository contains implementations of various data structures and sorting algorithms. Each folder corresponds to a specific data structure or set of algorithms. Below is a detailed description of the repository's contents:

## Contents

### **1. Binary Search Tree (BST)**
- A tree-like data structure where each node has at most two children (left and right).  
- **Key Property**: The left child has a value less than the parent, and the right child has a value greater than the parent.  
- **Use Cases**: Searching, insertion, and deletion operations with time complexity \(O(log n)\) in a balanced tree.

---

### **2. Heap**
- A special tree-based data structure that satisfies the **heap property**:  
  - **Max Heap**: Parent nodes are greater than or equal to their children.  
  - **Min Heap**: Parent nodes are less than or equal to their children.  
- **Use Cases**: Priority queues, efficient retrieval of the largest or smallest element.

---

### **3. Queue**
- A linear data structure that follows the **FIFO (First In, First Out)** principle.  
- Operations:  
  - **Enqueue**: Add an element to the back.  
  - **Dequeue**: Remove an element from the front.  
- **Use Cases**: Scheduling tasks, handling requests in a pipeline.

---

### **4. Stack**
- A linear data structure that follows the **LIFO (Last In, First Out)** principle.  
- Operations:  
  - **Push**: Add an element to the top.  
  - **Pop**: Remove the top element.  
- **Use Cases**: Undo/Redo operations, evaluating expressions (like postfix or infix).

---

### **5. Linked List**
- A sequence of nodes where each node contains:  
  - Data.  
  - A reference (or pointer) to the next node (in singly linked lists) or both next and previous nodes (in doubly linked lists).  
- Types:  
  - **Singly Linked List**: Nodes point to the next node only.  
  - **Doubly Linked List**: Nodes point to both the previous and the next nodes.
  - **Circular Linked List**:The last node points back to the first node, forming a circle.
  - **Use Cases**: Dynamic memory allocation, efficient insertion/deletion.
---

### **6. Sorting Algorithms**
- Algorithms to arrange elements of an array or list in a specific order (ascending or descending).  
- Common algorithms include:  
  - **Bubble Sort**: Repeatedly swaps adjacent elements if they are in the wrong order.  
  - **Quick Sort**: Divides the array into partitions and sorts them recursively.  
  - **Merge Sort**: Divides the array into halves, sorts them, and merges them back.  
  - **Heap Sort**: Uses a heap structure to sort elements.  
- **Use Cases**: Organizing data for searching, comparison, or visualization.

---

### **7. Huffman code Algorithm**
- Huffman Coding is a lossless compression algorithm that minimizes the total number of bits used to encode data.

- Calculate the frequency of each character.
- Create a priority queue (min-heap) of nodes based on frequency.
- Build a Huffman Tree:
- Remove two nodes with the smallest frequencies.
- Create a new node combining their frequencies.
- Insert the new node back into the queue.
- Assign binary codes to characters:
- Traverse the tree: left = 0, right = 1.
- Encode the data using the generated codes.
- Efficient for compressing data with repeated characters!
---

## Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/AhmadIrsahaid/DS-and-Algorithms.git
