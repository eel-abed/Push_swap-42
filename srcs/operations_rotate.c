/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:46:49 by eel-abed          #+#    #+#             */
/*   Updated: 2024/08/21 16:09:40 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack *stack_a)
{
	int tmp;
	int i;

	if (stack_a->top >= 1)
	{
		tmp = stack_a->array[stack_a->top];
		i = stack_a->top;
		while (i > 0)
		{
			stack_a->array[i] = stack_a->array[i - 1];
			i--;
		}
		stack_a->array[0] = tmp;
		write(1, "ra\n", 3);
	}
}
void rb(t_stack *stack_b)
{
	int tmp;
	int i;

	if (stack_b->top >= 1)
	{
		tmp = stack_b->array[stack_b->top];
		i = stack_b->top;
		while (i > 0)
		{
			stack_b->array[i] = stack_b->array[i - 1];
			i--;
		}
		stack_b->array[0] = tmp;
		write(1, "rb\n", 3);
	}
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}

void rra(t_stack *stack_a)
{
	int tmp;
	int i;

	if (stack_a->top >= 1)
	{
		tmp = stack_a->array[0];
		i = 0;
		while (i < stack_a->top)
		{
			stack_a->array[i] = stack_a->array[i + 1];
			i++;
		}
		stack_a->array[stack_a->top] = tmp;
		write(1, "rra\n", 4);
	}
}

void rrb(t_stack *stack_b)
{
	int tmp;
	int i;

	if (stack_b->top >= 1)
	{
		tmp = stack_b->array[0];
		i = 0;
		while (i < stack_b->top)
		{
			stack_b->array[i] = stack_b->array[i + 1];
			i++;
		}
		stack_b->array[stack_b->top] = tmp;
		write(1, "rrb\n", 4);
	}
}
