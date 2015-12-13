#Search

##Binary Search
Check index **(l + r)/2**

- Worst Case O(log n)
- Best Case O(1)
- Average Case O(log n)
- Worst Case Space Complexity O(1)

[code using dynamic array](https://github.com/jingt06/Algorithms/blob/master/Search/Binary_Search.cc)

[code using binary search tree](https://github.com/jingt06/Algorithms/blob/master/Search/Binary_Search_Tree.cc)

##Interpolation Search
**Guess** its location

Check index **l + (k-A[l]) / (A[r]-A[l]) * (r-l)**

Works well if keys are uniformly distributed: **O(loglog n)** on average

Bad worst case performance: **O(n)** 

[code](https://github.com/jingt06/Algorithms/blob/master/Search/Interpolation_Search.cc)

##Gallop Search
Problem in Binary-Search: when we cannot see the end of the array (data streams, a huge file, etc)

Check if k is in A[i ... 2i],
then perform binary search in A[i ... 2i], Otherwise, double i.

**O(log m) comparisons** (m: location of k in A)

[code](https://github.com/jingt06/Algorithms/blob/master/Search/Gallop_Search.cc)

##Dynamic Ordering
- **Move-To-Front(MTF)**: Upon a successful search, move the accessed item to the front of the list.   [code](https://github.com/jingt06/Algorithms/blob/master/Search/Move_To_Front.cc)
- **Transpose**:  Upon a successful search, swap the accessed item with the item immediately preceding it. [code](https://github.com/jingt06/Algorithms/blob/master/Search/Transpose_Sequential_Search.cc)

##Skip Lists
- Randomized data structure for dictionary ADT
- A hierachy of ordered linked list
- Expected **space** usage: O(n)
- Expected **height** O(log n)
- Operations:
   - **Search**: O(log n) Expected time 
   - **Insert**: O(log n) Expected time 
   - **Delete**: O(log n) Expected time
- [code](https://github.com/jingt06/Algorithms/blob/master/Search/Skip_List.cc) 