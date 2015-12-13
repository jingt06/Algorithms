#Compression

[Examples](https://github.com/jingt06/Algorithms/blob/master/md/240final_review_session.md#huffman-encoding)

- **Source text**: The original data, string of characters S from the source alphabet.
- **Coded test**: The encoded data, string of characters C from the coded alphabet.
- **Encoding**: An algorithm mapping source texts to coded texts
- **Decoding** An algorithm mapping coded texts back to their original source text

###Type of Data Compression
- **Logical vs Physical**
  - **Logical Compression**: uses the meaning of the data and only applies to a certain domain (e.g. sound recordings)
  - **Physical Compression** only knows the physical bits in the data, not the meaning behind them
- **Lossy vs. Lossless**
  - **Lossy Compression** achieves better compressions ratios, but the decoding is approximate; the exact source text S is not recoverable
  - **Lossless Compression** always decodes S exactly  

##Run-Length Encoding
**RLE** is a variable-length code 

encode the binary length of k in **unary**, followed by the acctual value of k in **binary**

The prefix-free encoding of the positive integer k is in two parts:

- lg k copies of 0, followed by
- The binary representation of k

Eg.

S = 11111110010000000000000000000011111111111

C = 10011101010000101000001011

Compression ratio: 26/43 ≈ 63%


##Huffman Coding
- Source alphabet is arbitary, coded alphabet is {0,1}
- We build a binary trie to store the decoding dictionary D
- Each character is a leaf of the trie

Build decoding trie, cost is O(|S| + |Σ| log |Σ|)

**Building the best trie**: Determine the frequency of each character and merge two tries with the least weights, until there is only 1 trie left

The constructed trie is an optimal one that will give the shortest C


Huffman is the **best** we can do for encoding one character at a time

##Adaptive Dictionaries
Using **Move To Front**

MTF does not provide any compression on its own.

Two possible approaches:

- Prefix-free interger encoding(eg. RLE)
- Huffman coding

Must provided inital dictionary

##Lempel-Ziv
**Main Idea**: Each character in the coded text C either refers to a single character, or a substirng of S taht both encoder and decoder have already seen

Click [here](https://github.com/jingt06/Algorithms/blob/master/md/240final_review_session.md#lempel-ziv-encode) to see examples.

No need for providing dictionary. *(decoding will build the same dictionary on its own using Text)*

##Burrows-Wheeler Transform
The BWT is a sophisticated compression technique

- Transforms source text to a coded text with same letters, just in a different order
- **The coded text will be more easily compressible with MTF**
- BWT is a **block compression method**
- Decoding is more efficent than encoding

BWT steps

1. Place all cyclic shifts of S in a list L
2. Sort the strings in L lexicographically
3. C is the list of trailing  characters of each string in L

Click [here](https://github.com/jingt06/Algorithms/blob/master/md/240final_review_session.md#burrows-wheeler-transform) to see examples.

- **Encoding cost**: **O(n^2)** (using radix sort)
- **Decoding cost**: O(n)
- Both use **O(n) space**
- Tends to be slower than other methods but give better compression

#Summary
|Algorithm| Property|Extra data|
|---|---|---|
|**REL**| Variable-width, multiple-character encoding|Nothing|
|**Huffman**| Variable-width, single-character|Compressed Trie|
|**MTF**|Adaptive, transform to smaller integers, Must be followed by variable-width integer encoding|Initial order dictionary|
|**LZW**|Adaptive,fixed-width,multiple-character encoding, Augments dictionary with repeated substrings| Nothing *(decoder will make a same dictionary by Text)*|
|**BWT**|Block compression method, must be followed by MTF|Nothing|