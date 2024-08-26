/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:41:07 by eel-abed          #+#    #+#             */
/*   Updated: 2024/08/23 17:04:31 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
static int find_min(t_stack *stack)
{
    int i;
    int min;
    int min_index;

    i = 0;
    min = stack->array[0];
    min_index = 0;
    while (i <= stack->top)
    {
        if (stack->array[i] < min)
        {
            min = stack->array[i];
            min_index = i;
        }
        i++;
    }
    return min_index;
}

static void sort_three(t_stack *stack)
{
    int a = stack->array[2];
    int b = stack->array[1];
    int c = stack->array[0];

    if (a > b && b < c && a < c)
        sa(stack);
    else if (a > b && b > c)
    {
        sa(stack);
        rra(stack);
    }
    else if (a > b && b < c && a > c)
        ra(stack);
    else if (a < b && b > c && a < c)
    {
        sa(stack);
        ra(stack);
    }
    else if (a < b && b > c && a > c)
        rra(stack);
}

static int find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    int cheapest_index;
    int cost;
    int min_cost;

    i = 0;
    min_cost = INT_MAX;
    while (i <= stack_a->top)
    {
        cost = 0;
        // Calculate cost to move to top of stack_a
        if (i <= stack_a->top / 2)
            cost += i;
        else
            cost += stack_a->top - i + 1;
        
        // Calculate cost to insert into correct position in stack_b
        int j = 0;
        while (j <= stack_b->top && stack_b->array[j] < stack_a->array[i])
            j++;
        if (j <= stack_b->top / 2)
            cost += j;
        else
            cost += stack_b->top - j + 1;
        
        if (cost < min_cost)
        {
            min_cost = cost;
            cheapest_index = i;
        }
        i++;
    }
    return cheapest_index;
}

static void move_to_b(t_stack *stack_a, t_stack *stack_b, int index)
{
    if (index <= stack_a->top / 2)
    {
        while (index > 0)
        {
            ra(stack_a);
            index--;
        }
    }
    else
    {
        while (index <= stack_a->top)
        {
            rra(stack_a);
            index++;
        }
    }
    pb(stack_b, stack_a);
}

static void move_to_a(t_stack *stack_a, t_stack *stack_b)
{
    int index;
    
    while (stack_b->top >= 0)
    {
        index = 0;
        while (index <= stack_a->top && stack_a->array[index] < stack_b->array[stack_b->top])
            index++;
        
        if (index <= stack_a->top / 2)
        {
            while (index > 0)
            {
                ra(stack_a);
                index--;
            }
        }
        else
        {
            while (index <= stack_a->top)
            {
                rra(stack_a);
                index++;
            }
        }
        pa(stack_a, stack_b);
    }
}

void sort(t_stack *stack_a, t_stack *stack_b)
{
    int size = stack_a->top + 1;

    if (size <= 3)
    {
        sort_three(stack_a);
        return;
    }

    // Push first two elements to stack_b
    pb(stack_b, stack_a);
    pb(stack_b, stack_a);

    // Push remaining elements except last three
    while (stack_a->top > 2)
    {
        int cheapest = find_cheapest(stack_a, stack_b);
        move_to_b(stack_a, stack_b, cheapest);
    }

    // Sort remaining three elements in stack_a
    sort_three(stack_a);

    // Push back elements from stack_b to stack_a
    move_to_a(stack_a, stack_b);

    // Rotate stack_a to bring minimum to top
    int min_index = find_min(stack_a);
    if (min_index <= stack_a->top / 2)
    {
        while (min_index > 0)
        {
            ra(stack_a);
            min_index--;
        }
    }
    else
    {
        while (min_index <= stack_a->top)
        {
            rra(stack_a);
            min_index++;
        }
    }
}
