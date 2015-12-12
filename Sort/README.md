## Comparison model
####Theorem:  Any correct comparison-based sorting algorithm requires at least Ω(n log n) comparison operations.

|Sort|Running time|Analysis|Code|
|----|------------|--------|---|
|Selection Sort| Θ(n^2) | worst-case|[code](https://github.com/jingt06/Algorithms/blob/master/Sort/selection_sort.cc)|
|Insertion Sort| Θ(n^2) | worst-case|[code](https://github.com/jingt06/Algorithms/blob/master/Sort/insertion_sort.cc)|
|Bubble Sort| Θ(n^2) | worst-case|[code](https://github.com/jingt06/Algorithms/blob/master/Sort/bubble_sort.cc)|
|Merge Sort| Θ(n log n) |worst-case|[code](https://github.com/jingt06/Algorithms/blob/master/Sort/merge_sort.cc)|
|Heap Sort| Θ(n log n)| worst-case|[code](https://github.com/jingt06/Algorithms/blob/master/Sort/heap_sort.cc)|
|Quick Sort| Θ(n log n)| average-case|[code](https://github.com/jingt06/Algorithms/blob/master/Sort/quick_sort.cc)|
|Randomized Quick Sort| Θ(n log n)| expected|[code](https://github.com/jingt06/Algorithms/blob/master/Sort/randomized_quick_sort.cc)|
|Medians of Five Quick Sort| Θ(n log n)| worst-case| [code](https://github.com/jingt06/Algorithms/blob/master/Sort/medians_of_five_quick_sort.cc)|
|Heap Sort| O(n log n)||[code](https://github.com/jingt06/Algorithms/blob/master/Sort/heap_sort.cc)|

## Non-Comparison medel
|Sort|Running time|Auxiliary Space|Code|
|----|------------|--------|---|
|Counting Sort|Θ(n + k), which is Θ(n) if k ∈ O(n)| Θ(n + k)|[code](https://github.com/jingt06/Algorithms/blob/master/Sort/counting_sort.cc)|
|Radix Sort|Θ(d(n + k))|Θ(n + k)|[code](https://github.com/jingt06/Algorithms/blob/master/Sort/radix_sort.cc)|


##Summary
- Randomized algorithms can eliminate “bad cases”
- Best-case, worst-case, average-case, expected-case can all differ
- Sorting is an important and **very** well-studied algorithm
- Can be done in Θ(n log n) time; faster is not possible for general input
- HeapSort is the only fast algorithm we have seen with
O(1) auxiliary space
- QuickSort is often the fastest in practice
- MergeSort is also Θ(n log n), selection & insertion sorts are Θ(n^2)
- CountingSort, RadixSort can achieve o(n log n) if the input is special