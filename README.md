# Push_swap

![Push_swap Visualization](/Diagram_pushswap.png)

## Table of Contents
- [Introduction](#introduction)
- [How It Works](#how-it-works)
- [Installation](#installation)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Visualization](#visualization)
- [Acknowledgements](#acknowledgements)

## Introduction

Push_swap is a 42 School project that challenges students to create an efficient sorting algorithm using two stacks and a limited set of operations. The goal is to sort a given list of integers using the fewest possible moves.

## How It Works

The program takes a list of integers as input and uses two stacks, A and B, to sort them. The available operations are:

- `sa`: Swap the first two elements of stack A
- `sb`: Swap the first two elements of stack B
- `ss`: Perform `sa` and `sb` simultaneously
- `pa`: Push the top element from stack B to stack A
- `pb`: Push the top element from stack A to stack B
- `ra`: Rotate stack A (move the top element to the bottom)
- `rb`: Rotate stack B
- `rr`: Perform `ra` and `rb` simultaneously
- `rra`: Reverse rotate stack A (move the bottom element to the top)
- `rrb`: Reverse rotate stack B
- `rrr`: Perform `rra` and `rrb` simultaneously

The program outputs the list of operations needed to sort the input.

## Installation

1. Clone the repository:
   ```
   git clone https://github.com/yourusername/Push_swap-42.git
   ```
2. Navigate to the project directory:
   ```
   cd Push_swap-42
   ```
3. Compile the project:
   ```
   make
   ```

## Usage

Run the program with a list of integers as arguments:

```
./push_swap 4 67 3 87 23
```

For checker (if implemented):

```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Algorithm

This implementation uses a combination of algorithms depending on the input size:

- For 2 numbers: Simple swap if needed
- For 3 numbers: Hardcoded optimal solution
- For 4-5 numbers: Insertion sort
- For larger sets: Radix sort

The core sorting logic can be found in the following files:

```c:srcs/sort.c
startLine: 15
endLine: 29
```

```c:srcs/sort2-3-5.c
startLine: 31
endLine: 73
```

## Visualization

To better understand how the algorithm works, you can use the Push_swap Visualizer. Here's a snapshot of the visualization:

![Push_swap Visualization](https://camo.githubusercontent.com/2dd938af11d26d77728c954b4eab035200733dfa6506bc007584274bb2d2e985/68747470733a2f2f692e696d6775722e636f6d2f7a7163735a66592e706e67)

This image demonstrates the state of both stacks at different stages of the sorting process.

## Acknowledgements

Special thanks to [@o-reo](https://github.com/o-reo) for their excellent [Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer), which greatly helped in understanding and optimizing the algorithm.

---

Feel free to contribute, report issues, or suggest improvements!
