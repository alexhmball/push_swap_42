# Push_swap - Sorting Integers Using Stacks

Push_swap is a sorting algorithm project that aims to sort a random set of integers using two stacks and a specific set of instructions to manipulate these stacks. The goal of this project is to write a C program called push_swap that calculates and displays on the standard output the smallest program, made of Push_swap language instructions, that sorts the given integers in ascending order.

## Learning Goals
Push_swap allowed me to achieve the following learning goals:

1. **Sorting Algorithms:** This project provided an opportunity to dive into sorting algorithms and their complexities. Implementing efficient sorting solutions for different configurations of integers improved my algorithmic thinking.

2. **C Programming:** Writing a program in C, adhering to the project's requirements and following the Norm, honed my C programming skills.

3. **Complexity Analysis:** Understanding and evaluating the complexity of the implemented sorting algorithms became an essential part of this project. Efficient sorting with the fewest operations became the primary goal.

## Details

The project involved two stacks, named "a" and "b," each containing a random amount of negative and/or positive numbers without duplicates at the beginning. The main goal was to sort the numbers in stack "a" in ascending order using specific operations on the stacks.

The following instructions were available to manipulate the stacks:

- sa (swap a): Swap the first 2 elements at the top of stack "a." Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack "b." Do nothing if there is only one or no elements.
- ss: Perform sa and sb at the same time.
- pa (push a): Take the first element at the top of "b" and put it at the top of "a." Do nothing if "b" is empty.
- pb (push b): Take the first element at the top of "a" and put it at the top of "b." Do nothing if "a" is empty.
- ra (rotate a): Shift up all elements of stack "a" by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack "b" by 1. The first element becomes the last one.
- rr: Perform ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack "a" by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack "b" by 1. The last element becomes the first one.
- rrr: Perform rra and rrb at the same time.
  
The program push_swap was required to display the smallest list of instructions possible to sort stack "a," with the smallest number at the top. The instructions were separated by a '\n' character.

## Reflection
Push_swap was a challenging project that allowed me to deepen my understanding of sorting algorithms and complexity analysis. Implementing the sorting algorithm using stack operations was an excellent exercise in algorithmic thinking and efficiency.

I focused on writing clean and well-organized C code that adhered to the project's requirements and the Norm. The ability to sort the integers with the fewest operations became the primary goal, and I aimed to optimize the algorithm for various input configurations.

I enjoyed working on this project, as it not only improved my C programming skills but also provided valuable insights into sorting algorithms that are widely used in real-world applications. The project served as a stepping stone for more complex algorithmic challenges in my journey as a developer.
