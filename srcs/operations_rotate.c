/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:46:49 by eel-abed          #+#    #+#             */
/*   Updated: 2024/08/13 13:47:22 by eel-abed         ###   ########.fr       */
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
