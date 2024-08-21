/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:23:46 by eel-abed          #+#    #+#             */
/*   Updated: 2024/08/21 16:38:50 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int has_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i <= stack->top)
	{
		j = i + 1;
		while (j <= stack->top)
		{
			if (stack->array[i] == stack->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int is_sorted(t_stack *stack)
{
	int i;

	if (stack->top < 0)
		return (1);
	i = stack->top;
	while (i > 0)
	{
		if (stack->array[i] < stack->array[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
