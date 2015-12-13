#Hashing
- **Uniform Hashing Assumption**: Each hash function value is equally likely.
- A good hash function should:
   - be very efficient to compute
   - be unrelated to any possible patterns in the data
   - depend on all parts of the key 
- **Collision Resolution**: two basic strategies:
   - Allow multiple items at each table location (**buckets**) 
   - Allow each item to go into multiple locations (**open addressing**)
- **load factor** α = n/M. 
- **rehashing**: rebuild the whole hash table when load factor gets too large or too small

##Direct Addressing
**Requirement:** For a given M ∈ N, every key k is an integer with 0 <= k < M

- **search(k)** : Check whether A[k] is empty
- **insert(k, v)** : A[k] ← v
- **delete(k)** : A[k] ← empty

Each operation is **Θ(1)**

Total storage is **Θ(M**)

Direct addressing isn't possible if keys are not integers. And the storage is very Wastfull if n<<M.

[code](https://github.com/jingt06/Algorithms/blob/master/Hashing/Direct_Hashing.cc)

##Chaining
Each table entry is a **bucket** containg 0 or more KVPs.

Assuming **uniform hashing**, average bucket size is exactly α.

Analysis of operations:

- **Search**: Θ(1 + α) average-case, Θ(n) worst-case
- **Insert**: O(1) worst-case (always insert in front)
- **Delete**: Θ(1 + α) average, Θ(n) worst-case (same as search)


## Linear Probing
h(k,i) = (h(k) + i) mod M, for some hash function h

- **Search**: 1 / (1 - α)^2
- **Insert**: 1 / (1 - α)^2
- **Delete**: 1 / (1 - α)

[code](https://github.com/jingt06/Algorithms/blob/master/Hashing/Linear_Probing.cc)

##Double Hashing
use **two** hash functions h1, h2 that are **independent**.

assume the probability that a key k has h1(k) = a and h2(k) = b, for any particular a and b is 1/M^2

Define h(k,i) = (h1(k) + i* h2(k)) mod M

- **Search**: 1 / (1 - α)
- **Insert**: 1 / (1 - α)
- **Delete**: 1/α log( 1 / (1 - α))


##Cuckoo Hashing
From Pagh and Rodler in 2001

use two independent hash functions h1, h2

**Always** insert a new item into h1(k)

If it kick out another item, re-insert into its alternate position

Insertion might fail if there is a loop, in this case we have to rehash with a large M.

- **Search**: 1
- **Insert**: α / (1 - 2α)^2
- **Delete**: 1

[code](https://github.com/jingt06/Algorithms/blob/master/Hashing/Cuckoo_Hashing.cc)

##Extendible Hashing
####Basic ids:
- The **directory** is stored in **internal memory**. Contains a hash table of size 2^d, where d is called **order**.
-  Each directory entry points a **block** stored in **external memory**
-  Each block contains at most S items, sorted by hash value

####Properties of the direcotry:
-  Directory has **order** d<=L, L is length of binary sequences
-  Directory contains a hash table with indices 0, 1,... 2^d -1
-  Look up a key, use high-order d bits of h(k)
-  Each directory entry points to a single block

####Properties of a block B:
- B has a **local depth** k <= d and size n <= S.
- B stores n KVPs, sorted by the hahs values of the keys.
- Hash value in B is same as the high-order k bits. Call this the **block index** i, where 0 <= i < 2^k
- Exactly 2^(d-k) directory entries point to block B

####Opearation
- **Search**
  -  CPU time: Θ(log S)
  -  Page faults: 1 
- **Insert** and **Delete**
  - CPU time: **Θ(S)** without a directory grow/shrink (which rarely happen) Directory grow/shrink costs **Θ(2^d)**
  - Page faults: 1 or 2, depending on whether there is a block split/merge.
