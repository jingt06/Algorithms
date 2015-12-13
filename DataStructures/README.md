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

##Multi-Dimensional Data

#### Quadtree
Suppose we have n points P = {(x0, y0),(x1, y1), . . . ,(xn−1, yn−1)} in the plane

**Build** a quadtree on P

1. Find square R that contains all points of P.
2. Root of quadtree corresponds to R
3. **Split**: Partition R into four equal subsquares, each is a child of R.
4. Recursively repeat this process for any node that containts more than one point
5. Each leaf stores one point

**Spread factor** of points P:β(P) = dmax/dmin 

dmax(dmin):max(min) distance between two points in P

**Height** of quadtree:  h ∈ Θ(log dmax/dmin)

Worst-case complexity to **build initial tree** = Θ(#nodes) = Θ(nh)

Worst-case complexity of **range search** = O(#nodes) = O(nh)

[code](https://github.com/jingt06/Algorithms/blob/master/DataStructures/Quadtree.cc)

####kd-tree
Suppose we have n points P = {(x0, y0),(x1, y1), . . . ,(xn−1, yn−1)} in the plane

**Build** a kd-tree on P

1. Split P into two equal subsets using vertical line
2. Split each of the two subsets into two equal pieces using horizontal lines
3. Continue until every point is in a separate region

**Complexity of build a kd-tree**: Θ(n log n)

**height of the tree**: Θ(log n)

**Complexity of Range Search**: O(k + U) where k is number of keys **reported** and U is number of regions we go to but **unsuccessfully**, It solves to O（k + √n)

- **Analysis**: consider if the query is with a vertical line l.
- **Observe**: At every vertical split, l is to one siede; while at every horizontal split l is to both sides (number of intersected region doubled)
- Let G(n) be the number of intersected d region in a kd-tree with n points(leaves). 
- G(1) = 1 
- G(n) = 1 + G(n/2) at even depth
- G(n) = 1 + 2G(n/2) at odd depth
- We get G(n) = 2 G(n/4) + O(1)
- Solves to G(n) = O(√n)


kd-tree for d-dimensional space

- **Storage**: O(n)
- **Construction time**: O(n log n)
- **Range Query Time**: O( n^(1- 1/d) + k)

[code](https://github.com/jingt06/Algorithms/blob/master/DataStructures/kd_tree.cc)

####Range Tree
Range trees for 2 dimensional

- **Range Search** Running time: O(k + log^2 n)
- **Construction Time**: O(n log n)
- **Space Usage**: O(n log n)

[code](https://github.com/jingt06/Algorithms/blob/master/DataStructures/RangeTree.cc) - Range Search not completed

**Range trees for d-dimensional space**

- **Storage**: O(n (log n)^(d−1))
- **Construction time**: O(n (log n)^(d−1))
- **Range query time**: O((log n)^d + k)