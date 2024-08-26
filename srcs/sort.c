/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:41:07 by eel-abed          #+#    #+#             */
/*   Updated: 2024/08/26 14:00:02 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>


void sort_three(t_stack *a) {
    if (a == NULL || a->size != 3)
        return;

    int first = a->top->value;
    int second = a->top->next->value;
    int third = a->top->next->next->value;

    if (first > second && second < third && first < third) {
        sa(a); // Swap first and second
    } else if (first > second && second > third && first > third) {
        sa(a); // Swap first and second
        rra(a); // Reverse rotate
    } else if (first > second && second < third && first > third) {
        ra(a); // Rotate
    } else if (first < second && second > third && first < third) {
        sa(a); // Swap first and second
        ra(a); // Rotate
    } else if (first < second && second > third && first > third) {
        rra(a); // Reverse rotate
    }
}

void rotate_to_top(t_stack *a, int value) {
    if (a == NULL || a->top == NULL) {
        return; // Handle empty stack case
    }

    int position = 0;
    t_node *current = a->top;

    // Find the position of the value in Stack A
    while (current && current->value != value) {
        position++;
        current = current->next;
    }

    // If the value is not found, return
    if (current == NULL) {
        return;
    }

    // Determine the number of rotations needed
    int rotations = position;
    int reverse_rotations = a->size - position;

    // Perform rotations
    if (rotations <= reverse_rotations) {
        // Forward rotations
        for (int i = 0; i < rotations; i++) {
            ra(a); // Assuming ra function rotates the stack upwards
        }
    } else {
        // Reverse rotations
        for (int i = 0; i < reverse_rotations; i++) {
            rra(a); // Assuming rra function rotates the stack downwards
        }
    }
}


int calculate_operations(t_stack *a, t_stack *b, int value) {
    int a_rotations = 0;
    int b_rotations = 0;
    t_node *current = a->top;

    // Find the position of the value in Stack A
    while (current && current->value != value) {
        a_rotations++;
        current = current->next;
    }

    // Find the correct position in Stack B
    current = b->top;
    while (current) {
        if (current->value < value && (!current->next || current->next->value > value)) {
            break;
        }
        b_rotations++;
        current = current->next;
    }

    // If the value should be placed at the end of Stack B
    if (!current) {
        b_rotations = b->size;
    }

    // Calculate the total number of operations
    int total_operations = a_rotations + b_rotations;

    // Consider reverse rotations if they are more efficient
    if (a_rotations > a->size / 2) {
        a_rotations = a->size - a_rotations;
    }
    if (b_rotations > b->size / 2) {
        b_rotations = b->size - b_rotations;
    }

    total_operations = a_rotations + b_rotations;

    return total_operations;
}
int find_min_value(t_stack *a) {
    if (a == NULL || a->top == NULL) {
        return INT_MAX; // or handle the error appropriately
    }

    int min_value = a->top->value;
    t_node *current = a->top->next;

    // Traverse Stack A
    while (current) {
        // Compare and update the minimum value
        if (current->value < min_value) {
            min_value = current->value;
        }
        current = current->next;
    }

    return min_value;
}
int find_correct_position(t_stack *a, int value) {
    t_node *current = a->top;
    t_node *best_node = NULL;

    while (current) {
        if (current->value > value && (!best_node || current->value < best_node->value)) {
            best_node = current;
        }
        current = current->next;
    }

    if (best_node) {
        return best_node->value;
    }

    // If no suitable position is found, return the minimum value
    return find_min_value(a);
}



void turk_sort(t_stack *a, t_stack *b) {
    // Push elements to Stack B until 3 elements are left in Stack A
    while (a->size > 3) {
        pb(a, b);
    }

    // Sort the last three elements in Stack A
    sort_three(a);

    // Push elements back to Stack A
    while (b->size > 0) {
        int target_value = find_correct_position(a, b->top->value);
        rotate_to_top(a, target_value);
        pa(a, b);
    }

    // Final arrangement
    int min_value = find_min_value(a);
    rotate_to_top(a, min_value);

    // Print the sorted stack
    printf("stackA: ");
    for (t_node *tmp = a->top; tmp; tmp = tmp->next)
        printf("%d ", tmp->value);
    printf("\n");
}
