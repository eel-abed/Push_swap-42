/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:41:07 by eel-abed          #+#    #+#             */
/*   Updated: 2024/09/04 14:07:43 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

int get_max_value(t_stack *stack)
{
    t_node *current = stack->top;
    int max = current->value;

    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return max;
}

int get_digit(int value, int position)
{
    return (value / (int)pow(10, position)) % 10;
}

void sort_3(t_stack *a)
{
    if (a->top->value > a->top->next->value && a->top->next->value > a->top->next->next->value)
        sa(a);
    else if (a->top->value > a->top->next->value && a->top->value > a->top->next->next->value)
        rra(a);
    else if (a->top->value < a->top->next->value && a->top->next->value > a->top->next->next->value)
        ra(a);
}

void radix_sort(t_stack *a, t_stack *b)
{
    int max_value = get_max_value(a);
    int max_bits = 0;
    int i, j;

    while ((max_value >> max_bits) != 0)
        max_bits++;

    for (i = 0; i < max_bits; i++)
    {
        int size = a->size;
        for (j = 0; j < size; j++)
        {
            if (((a->top->value >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
        }

        while (b->size > 0)
            pa(a, b);
    }

    if (a->size == 3)
        sort_3(a);
	printf("stack a : ");
	for (t_node *tmp = a->top; tmp; tmp = tmp->next)
		printf("%d ", tmp->value);
}
