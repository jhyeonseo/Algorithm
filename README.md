Code for advanced algorithm lecture
Prof. Wonjun Kim

The copyright belongs to Jang Hyeon-seo, konkuk university.
Prohibits unauthorized modification or distribution.
If you have any questions about the code, please email gustj9320@konkuk.ac.kr

Revision Date: April 11, 2022 
1. Recursion project integrated.
2. Separate into header and source for code brevity of graph search project.
3. Add codes related to heap (note that they are implemented differently from the class)

Last Revision Date: April 13, 2022 
1. input_adjlist now accepts input as a file.
2. Node structures now have weights as variables.
3. print_adjlist now outputs weights as well.
4. The heap now sets the maximum value based on the weight.
5. A heap sort function adjust_heap was added.
6. A function pq_update was added to update weights and heaps.
7. A function pis_adjlist that searches for NODE through the PFS algorithm was added.
8. The print_heap function outputs weights and outputs characters instead of integers.
9. Added a variable 'parent' that stores the node that called itself.
10. Added a function print_tree that outputs the tree structure.
Discussion: How to find the best path? May be articulation...
