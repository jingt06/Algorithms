## Comparison model
####Theorem:  Any correct comparison-based sorting algorithm requires at least Ω(n log n) comparison operations.

|Sort|Running time|Analysis|
|----|------------|--------|
|Selection Sort| Θ(n^2) | worst-case|
|Insertion Sort| Θ(n^2) | worst-case|
|Merge Sort| Θ(n log n) |worst-case|
|Heap Sort| Θ(n log n)| worst-case|
|Quick Sort| Θ(n log n)| average-case|
|Randomized Quick Sort| Θ(n log n)| expected|
|Medians of Five Quick Sort| Θ(n log n)| worst-case
|Heap Sort| O(n log n)||

## Non-Comparison medel
|Sort|Running time|Auxiliary Space|
|----|------------|--------|
|Counting Sort|Θ(n + k), which is Θ(n) if k ∈ O(n)| Θ(n + k)|
|Radix Sort|Θ(d(n + k))|Θ(n + k)|


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