/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2-3-5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:26:32 by eel-abed          #+#    #+#             */
/*   Updated: 2024/09/11 15:28:42 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

void	sort_2(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_3(t_stack *a)
{
	if (a->top->value > a->top->next->value
		&& a->top->next->value > a->top->next->next->value)
	{
		sa(a);
		rra(a);
	}
	else if (a->top->value > a->top->next->value
		&& a->top->value > a->top->next->next->value)
		ra(a);
	else if (a->top->value > a->top->next->value)
		sa(a);
	else if (a->top->value > a->top->next->next->value)
		rra(a);
	else if (a->top->next->value > a->top->next->next->value)
	{
		sa(a);
		ra(a);
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min;
	int	i;

	i = 0;
	while (i < 2)
	{
		min = find_min(a);
		while (a->top->value != min)
		{
			if (a->top->next->value == min)
				sa(a);
			else
				ra(a);
		}
		pb(a, b);
		i++;
	}
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}
