# MagicVowels

Consider a string s, consisting of one or more of the following letters: a, e, i, o, and u.
 
We define a magical subsequence of s to be a sequence of letters derived from s that contains all five vowels in order. This means a magical subsequence will have one or more a's followed by one or more e's followed by one or more i's followed by one or more o's followed by one or more u's. For example, if s = "aeeiooua", then "aeiou" and "aeeioou" are magical subsequences but "aeio" and "aeeioua" are not.
 
Write a function to find length of longest magical subsequence with parameter string s.
 
Input Format
String s composed of English vowels (i.e., a, e, i, o, and u).
 
Output Format
Count denoting the length of the longest magical subsequence in s.
 
Sample Input 1
aeiaaioooaauuaeiou
 
Sample Output 1 : **_10_**
 
Explanation 1
In the table below, the component characters of the longest magical subsequence are **bold**:

> **aei**aa**iooo**aa**uu**aeio**u**

 
Sample Input 2
aeiaaioooaa
 
Sample Output 2 : **_0_**
 
Explanation 2
String s does not contain the letter u, so it is not possible to construct a magical subsequence.