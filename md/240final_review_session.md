
##Boyer-Moore
P = YOYOMA

**Last occurence**

|L(c)|A|M|O|Y|
|---|---|---|---|---|
|k|5|4|3|2|

**suffix skip array**

|P[i]|Y|O|Y|O|M|A|
|---|---|---|---|---|---|---|
|k|-5|-4|-3|-2|-1|4|

P has length m = 6 

Given that you mismatch at P[i]=S[j]

1. Start at P[i] shift down once 
2. shift right m-1 times, 
3. shift left min(last occurence, sufffix skip[i])

|Y|A|M|A|H|A|Y|O|M|A|M|A|Y|O|Y|O|M|A|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||M\*1|A|
||||||||||O\*2|M|A|
|||||||||||||Y|O|Y|O|M|A|

1. min (-1,-2) = -2
2. min(5,-3) = -3


##KMP

P = reread

|F[i]|P[1...i]|P|F[j]|
|---|---|---|---|
|0||reread|0|
|1|e|reread|0|
|2|e**r**|**r**eread|1|
|3|e**re**|**re**read|2|
|4|erea|reread|0|
|5|ered|reread|0|

Given that you mismatch  at P[i] != S[j] 

1. start at P[i]
2. shift down onece
3. shift right max(1,i) times
4. shift left F[i-1] times, if i - 1 = -1, don't shift

|r|e|a|d|r|e|r|e|r|e|a|d|
|---|---|---|---|---|---|---|---|---|---|---|---|
|r|e|r\*1|
||||r\*2|
|||||r|e|r|e|a*3|
|||||||(r)|(e)|r|e|a|d|

1. F[1] = 0
2. F[-1] = 0
3. F[3] = 2

##Huffman Encoding

###Example 1
S = HUGE SUCCESS

|char|occ|encode|
|---|---|---|
|H|1|100|
|U|2|101|
|G|1|000|
|E|2|110|
| |1|001|
|S|3|01|
|C|2|111|

C = 100 101 000 110 001 01 101 111 111 110 01 01

###Example 2
C = 1011011001000

|char|encode|
|---|---|
|A|000|
|M|001|
|O|01|
|Y|1|

S = YOYOMA

##Burrows-Wheeler Transform

###Example 1: Encode racecar

**acyclic process**

|||||||||
|---|---|---|---|---|---|---|---|
|r|a|c|e|c|a|r|$|
|$|r|a|c|e|c|a|r|
|r|$|r|a|c|e|c|a|
|a|r|$|r|a|c|e|c|
|c|a|r|$|r|a|c|e|
|e|c|a|r|$|r|a|c|
|c|e|c|a|r|$|r|a|
|a|c|e|c|a|r|$|r|

**sort**

|||||||||
|---|---|---|---|---|---|---|---|
|$|r|a|c|e|c|a|r|
|a|c|e|c|a|r|$|r|
|a|r|$|r|a|c|e|c|
|c|a|r|$|r|a|c|e|
|c|e|c|a|r|$|r|a|
|e|c|a|r|$|r|a|c|
|r|$|r|a|c|e|c|a|
|r|a|c|e|c|a|r|$|

**encode**:
###Example 2: decode rrceaca$

|char|index|
|---|---|
|r|0|
|r|1|
|c|2|
|e|3|
|a|4|
|c|5|
|a|6|
|$|7|

**sort**

|index|char|sorted index|
|---|---|---|
|0|$|7|
|1|a|4|
|2|a|6|
|3|c|2|
|4|c|5|
|5|e|3|
|6|r|0|
|7|r|1|

####To decode

1. Sorte stable
2. Start at $'s inedex
3. output letter
4. start at letter's index
5. go to 3
6. until reach $ (no letter left)

Decode: racecar$


###Example 3: Decode n$niCadaa

|||
|---|---|
|n|0|
|$|1|
|n|2|
|i|3|
|C|4|
|a|5|
|d|6|
|a|7|
|a|8|

**sort**

||||
|---|---|---|
|0|$|1|
|1|C|4|
|2|a|5|
|3|a|7|
|4|a|8|
|5|d|6|
|6|i|3|
|7|n|0|
|8|n|2|

Decode: **Canadian**

##Lempel-Ziv Encode


###Example 1: Encode: **YOYOMA**
∑[0,127]

0 -> A

1 -> M

2 -> O

3 -> Y

4 -> $

5 -> #

6 ->  ..

.......
127 -> ..


- Take previous key and concatnate with the first letter of current key

|Previous |Current|Encode |Add dictionary|
|---|---|---|---|
| / | Y |3| / |
| Y | O |2| 128 -> YO|
| O | YO |128| 129 -> OY|
| YO | M | 1| 130 -> YOM|
| M | A | 0 | 131 -> MA|

###Example 2: Decode *3,2,128,1,0*
|Encode|Decode |Add dictionary|
|---|---|---|
|3| Y|
|2| O| 128 -> YO|
|128 | YO | 129 -> OY|
|1| M| 130 -> YOM|
|0| A| 131 -> MA|

###Example 3: Decode 1,4,3,7,0,9,13,5,8,2,6

∑[0...8]

||||
|---|---|---|
|0 -> _| 1 -> D| 2 -> G|
|3 -> N| 4-> O | 5 -> R|
|6 -> S | 7 -> T| 8 -> U|

|Encode|Decode |Add dictionary|
|---|---|---|
|1| D|
|4| O| 9 -> DO|
|3| N |10-> ON|
|7| T| 11 -> NT|
|0| _| 12 -> T_ |
|9| DO| 13 -> _D|
|13| _D| 14 -> DO_|
|5 | R|15 -> _DR| 
|8 | U|16 -> RU|
|2 | G|17 -> UG|
|6 | S|18 -> GS|

DONT_DO_DRUGS