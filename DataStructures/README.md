##Abstract Data Types
A description of **information** and a collection of **operations** on that information.

####Dynamic Arrays  
- Allocate a small array initially, and double its size as needed.
- Or Allocate one HUGE array, and only use the first part of it
- [code](https://github.com/jingt06/Algorithms/blob/master/DataStructures/Dynamic_Array.cc)

#### Stack ADT
- Items are removed in **LIFO** (last-in first-out) order
- Realizations of Stack ADT
  - Array
  - Linked list - [code](https://github.com/jingt06/Algorithms/blob/master/DataStructures/stack.cc) 


#### Queue ADT
- Items are removed in **FIFO** (first-in first-out) order
- Realizations of Queue ADT
  - using (circular) arrays
  - using linked list - [code](https://github.com/jingt06/Algorithms/blob/master/DataStructures/queue.cc) 

#### Dictionary ADT
- A **dictionary** is a collection of **items**, each of which contains a **key** and some **data** and is called a **key-value pair (KVP)**. Keys can be compared and are (typically) unique.  
- Unordered array or linked list
  - search Θ(n)
  - insert Θ(1)
  - delete Θ(n) (need to search)
- Ordered array
  - Θ(log n)
  - insert Θ(n)
  - delete Θ(n) 

##Tree
#### Binary Search Trees
- **Structure**: A BST is either empty or contains a KVP, left child.
- **Ordering**: Every key k in T.left is less than the root key. Ever key in T.right is greater than the root key.
- **operations**: 
  - **search(k)**: Compare k to current node, stop if found, else recurse on subtree unless it's empty. **Runtime: Θ(h)**
  - **insert(k,v)**: Search for k, then insert (k,v) as new node. **Runtime: Θ(h)**
  - **delete(k)**: Search for k, if node is a leaf, just delete it; if node has one child, move child up; Elsem swap with successor or predecessor node and than delete **Runtime: Θ(h)**
- **Height of a BST**: 
  - Worst-case: n - 1 = Θ(n)
  - Best-case: Θ(log n)
  - Average-case: Θ(log n)
- [code](https://github.com/jingt06/Algorithms/blob/master/DataStructures/BST.cc)