# RG
Study Loop

Always consider hash tables (dictionaries) with their O(1)-ness.

If at all array-related, try sorting first.

If search-related, consider binary search.

Start with a brute force solution, look for repeat work in that solution, and modify it to only do that work once.

Space-time trade-off! That is, for better time complexity, try using auxiliary data structures. E.g., do something in a single pass over an array—O(N) time—by using a hash table—O(N) space—vs. doing something in nested passes—O(N2)—without using any extra space—O(1).

Remember that you can use two pointers.

Try a greedy solution.

Does solving the problem for size (N – 1) make solving it for size N any easier? If so, try to solve recursively and/or with dynamic programming.

A lot of problems can be treated as graph problems and/or use breadth-first or depth-first traversal. And if the problem involves parsing or reversal in some way, consider using a stack.

Any time you repeatedly have to take the min or max of a dynamic collection, think heaps. (If you don’t need to insert random elements, prefer a sorted array.)

If you have a lot of strings, try putting them in a prefix tree / trie.

Not quite the same as N-1, but sometimes a divide-and-conquer approach is what is necessary. If I know the answer for exclusive parts of the problem, can I somehow combine to get the final answer?

For puzzle problems or anything where we can enumerate all possible solutions and there's a notion of a partial candidate solution, consider backtracking.
