/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:46:49 by eel-abed          #+#    #+#             */
/*   Updated: 2024/08/13 15:05:09 by eel-abed         ###   ########.fr       */
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
