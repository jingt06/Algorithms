#Pattern Matching
[Examples](https://github.com/jingt06/Algorithms/blob/master/md/240final_review_session.md)

##Brute-force Algorithm
- T is string of length n, P is a string of length m
- **guess** i from 0 to n-m
- **check** if T[i + j] = P[j]

Worst case performance **Θ((n − m + 1)m)**

when m <= n/2 -> **Θ(mn)**

[code](https://github.com/jingt06/Algorithms/blob/master/PatternMatching/BruteforcePM.cc)

##Knuth-Morris-Pratt Algorithm (1977)
- Compares the pattern to the text in **left-to-right**
- **Shifts** the pattern more **intelligently**than brute-force algorithm
- When a mismatch occurs, shift the pattern based on the previous matches

###Failure Array
- **Failure array** F of size m: F[j] is defined as the length of the largest prefix of P[0...j] that is also a suffix of P[1...j]
- If **mismatch** occurs at P[j], we set j = F[j - 1]

###KMP Analysis
- **Failure Array** no more than 2m iterations of the loop, runtime: **Θ(m)**
- **KMP** no more than 2n iterations of the loop, runtime:**Θ(n)**

[code](https://github.com/jingt06/Algorithms/blob/master/PatternMatching/KMP.cc)

##Boyer-Moore Algorithm
Based on three key ideas:

- **Reverse-order searching**: Compare P with a subsequence of T moving **backwards**
- **Bad character jumps**: When mismatch occurs at T[i] = c
  - If P contains c, we can shift P to align the last occurrence of c in P with T[i]
  - Otherwise, we can shift P to align P[o] with T[i+1]
- **Good suffix jumps**: If we have already matched a suffix of P, then get a mismatch, we can shift P forward to align with the previous occurence of that suffix(with a mismatch)
- Can Skip large parts of T 

###Last-Occurrence Function
L(c) is defined as

 - the largest index i such that P[i] = c or 
 - -1 if no such index exists

###Suffix skip array
- for 0 <= i < m, S[i] is the largest index j such that P[i+1 ... m-1] = P[j+1 ... j+m-1-i] and P[j] != P[i]

**Boyer Moore** Worst-case running time ∈ O(n + |Σ|)

[code](https://github.com/jingt06/Algorithms/blob/master/PatternMatching/Boyer_Moore.cc)


##Suffix tree
Search for **many patterns** P within the same fixed text T.

**Idea**: Preprocess the Text T.

- Build a compressed trie that stores all suffixes of text T
- Insert suffixes in decreasing order of length
- If suffix is a prefix of another suffix, do not insert it


##Summary
||Brute-Force|KMP|Boyer-Moore|Suffx trees|
|---|---|---|---|---|
|**Preprocessing**| /| O(m)|O (m + \|Σ\|)| O(n^2)|
|**Search time**|O(nm)|O(n)|O(n) often better|O(m)|
|**Extra space**|/ | O(m)|O (m + \|Σ\|) | O(n)|