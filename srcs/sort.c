/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:41:07 by eel-abed          #+#    #+#             */
/*   Updated: 2024/09/05 15:31:37 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_value(t_stack *stack)
{
	t_node	*current;
	int		max;

	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_digit(int value, int position)
{
	return ((value / ft_pow(10, position)) % 10);
}

void	sort_3(t_stack *a)
{
	if (a->top->value > a->top->next->value
		&& a->top->next->value > a->top->next->next->value)
		sa(a);
	else if (a->top->value > a->top->next->value
		&& a->top->value > a->top->next->next->value)
		rra(a);
	else if (a->top->value < a->top->next->value
		&& a->top->next->value > a->top->next->next->value)
		ra(a);
}

static	void	init_radix_sort(t_stack *a, int *max_bits, int *max_value)
{
	*max_value = get_max_value(a);
	*max_bits = 0;
	while ((*max_value >> *max_bits) != 0)
		(*max_bits)++;
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		i;
	int		j;
	int		size;

	init_radix_sort(a, &max_bits, &(int){0});
	i = 0;
	while (i < max_bits)
	{
		size = a->size;
		j = 0;
		while (j < size)
		{
			if (((a->top->value >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
	if (a->size == 3)
		sort_3(a);
}
