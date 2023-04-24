# push_swap

The push_swap project is a sorting algorithm project that requires you to sort a list of integers using two stacks and a set of specific operations. In this project, you will write two programs: one that check list of integers, and one that sorts that list using a set of specific operations.

# Installation:

To use this program in your projects, you must first compile it by running the following command:

`make`

This will compile the program into two executable files called push_swap and checker. You can then run the programs by entering the following commands:

`./push_swap <list_of_integers>`

`./checker <list_of_integers>`

# Usage:

The push_swap program takes a list of integers as input and returns a set of specific operations that will sort that list. The checker program takes the same list of integers as input and the set of operations returned by the push_swap program, and checks to see if the operations actually sort the list.

# Functionality:

The push_swap program sorts a list of integers using two stacks and a set of specific operations, including sa (swap the first two elements of stack A), sb (swap the first two elements of stack B), ss (swap the first two elements of both stacks), pa (push the first element of stack B to stack A), pb (push the first element of stack A to stack B), ra (rotate stack A so that the first element becomes the last), rb (rotate stack B so that the first element becomes the last), rr (rotate both stacks), rra (reverse rotate stack A so that the last element becomes the first), rrb (reverse rotate stack B so that the last element becomes the first), and rrr (reverse rotate both stacks).

The checker program checks to see if a set of specific operations actually sorts a list of integers. It returns OK if the operations sort the list, and KO if they do not.

The program also handles edge cases, such as if the input list contains duplicate numbers or if the input list is already sorted.

# Conclusion:

The push_swap project is a challenging and engaging project that will help you to gain a better understanding of how to create sorting algorithms and how to work with stacks in C. By completing this project, you will gain a deeper understanding of how to create complex algorithms and how to optimize code for efficiency.
