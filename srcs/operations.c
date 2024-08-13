/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:23:33 by eel-abed          #+#    #+#             */
/*   Updated: 2024/08/13 14:08:33 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *stack_a)
{
	int tmp;

	if (stack_a->top >= 1)
	{
		tmp = stack_a->array[stack_a->top];
		stack_a->array[stack_a->top] = stack_a->array[stack_a->top-1];
		stack_a->array[stack_a->top -1] = tmp;
		write(1,"sa\n",3);
	}
	
}
void sb(t_stack *stack_b)
{
	int tmp;

	if (stack_b->top >= 1)
	{
		tmp = stack_b->array[stack_b->top];
		stack_b->array[stack_b->top] = stack_b->array[stack_b->top-1];
		stack_b->array[stack_b->top -1] = tmp;
		write(1,"sb\n",3);
	}
	
}
void ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1,"ss\n",3);
}
void pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top >= 0)
	{
		push(stack_a, pop(stack_b));
		write(1,"pa\n",3);
	}
}

void pb(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_a->top >= 0)
	{
		push(stack_b, pop(stack_a));
		write(1,"pb\n",3);
	}
}
