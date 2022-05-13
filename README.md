Code for advanced algorithm lecture
Prof. Wonjun Kim

The copyright belongs to Jang Hyeon-seo, konkuk university.
Prohibits unauthorized modification or distribution.
If you have any questions about the code, please email gustj9320@konkuk.ac.kr

Last Revision Date: May 2, 2022
1. Added the shortest_adjlist function to find the minimum path of the graph expressed as a list.
2. Added the dijkstra function to find the minimum path of the graph expressed as a matrix.
3. Renamed node header to queue header.
4. Now in the check array, 0 means the root node.
5. A kruskal function that performs PFS SEARCH around the edge was added.
6. Find_set and union_set functions were added to assist the kruskal function
7. The pq_update function was renamed to the heap_update function and moved to the heap header.

Revision Date: April 19, 2022 
1. Modified the data type of Parent.
2. Modified the data type of GL.
3. Modified the parameter data type of input_adjlist and print_adjlist.
4. A function to output a score based on the search path was added.
Discussion: Articulation points are likely to be related to finding the shortest path.

Revision Date: April 13, 2022 
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

Revision Date: April 11, 2022 
1. Recursion project integrated.
2. Separate into header and source for code brevity of graph search project.
3. Add codes related to heap (note that they are implemented differently from the class)
