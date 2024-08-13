/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:23:33 by eel-abed          #+#    #+#             */
/*   Updated: 2024/08/13 13:31:15 by eel-abed         ###   ########.fr       */
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
	
}
void ss(t_stack *stack_a, t_stack *stack_b)
{
	
}
void pa(t_stack *stack_a, t_stack *stack_b)
{
	
}

void pb(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_a->top >= 0)
	{
		push(stack_b, pop(stack_a));
		write(1,"pb\n",3);
	}
}
