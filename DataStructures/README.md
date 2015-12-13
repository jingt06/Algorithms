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
- **Operations**: 
  - **search(k)**: Compare k to current node, stop if found, else recurse on subtree unless it's empty. **Runtime: Θ(h)**
  - **insert(k,v)**: Search for k, then insert (k,v) as new node. **Runtime: Θ(h)**
  - **delete(k)**: Search for k, if node is a leaf, just delete it; if node has one child, move child up; Elsem swap with successor or predecessor node and than delete **Runtime: Θ(h)**
- **Height of a BST**: 
  - Worst-case: n - 1 = Θ(n)
  - Best-case: Θ(log n)
  - Average-case: Θ(log n)
- [code](https://github.com/jingt06/Algorithms/blob/master/DataStructures/BST.cc)

####AVL Tree
- Introduced by Adel’son-Vel’ski˘ı and Landis in 1962
- An **AVL Tree** is a BST with an additional structural property: The heights of the left and right subtree differ by at most 1
- **Balance Factor** = height(R) - height(L) ∈ {−1, 0, 1}
  - -1 means the tree is left-heavy
  - 0 means the tree is balanced
  - 1 means the tree is right-heavy
- **fix**: 
  - T.balance = -2 
     - if T.left.balance = 1, double right rotation
     - else, right rotation
  - T.balance = 2 
     - if T.right.balance = -1, double left rotation 
     -  else, left rotation
- **Operation**
  - **insert(T,k,v)**: Θ(height) and **fix** will be called at moset onece
  - **search(k)**: Θ(height)
  - **delete(k)**: Θ(height), **fix** may be called Θ(height) times. Total cost is Θ(height)
- **Height** of AVL Tree is Θ(log n)
- [code](https://raw.github.com/jingt06/Algorithms/blob/master/md/avl_height.jpg?raw=true)


#### 2-3 Tree
- 2-3 Tree is like a BST with additional structual properties:
  - Every node either conatins **one KVP** and **two children**, or **two KVPS** and **three chidlren**.
  - ALl the leaves are at the **same lavel**.
- **Operations**:
  - **Search** - Θ(height) Runtime
     - Searching through a 1-node is just like in a BST.
     - For a 2-node, we must examine both keys and follow the appropriate path.
  - **Insert** - Θ(height) Runtime
     - If the leaf has only 1 KVP, just add the new one to make a 2-node.
     - Otherwise, order the three keys as a < b < c. Split the leaf into two 1-nodes, containing a and c, and (recursively) insert b into the parent along with the new link 
  - **Delete** (delete KVP x form a node V) - Θ(height) Runtime
     -  if V is a 2-node, just delete x;
     -  if V has a **immediate sibling U**, perfrom a transfer
     -  Otherwise, **merge** V and a 1-node sibling U.
- [code](https://github.com/jingt06/Algorithms/blob/master/DataStructures/2-3Tree.cc) Still buggy

####B-Tree
- A **B-tree of minsize d** is a search tree satisfying:
   - Each node contains at most 2d KVPs. Each non-root node contains at least d KVPs.
   - All the leaves are at the same level
- **Height** of a B-tree is Θ
(log n)/(log d).
- Cost of **search**, **insert**, **delete** is = O(log n);