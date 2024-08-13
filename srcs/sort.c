/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:41:07 by eel-abed          #+#    #+#             */
/*   Updated: 2024/08/13 13:47:37 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack(t_stack *a, t_stack *b)
{
	int size = a->top + 1;

	if (size <= 1)
		return;

	// Push first two elements to B
	pb(b, a);
	pb(b, a);

	// Sort these two elements in B if needed
	if (b->array[b->top] < b->array[b->top - 1])
		sb(b);

	while (a->top >= 0)
	{
		int to_insert = a->array[a->top];
		int position = find_position(b, to_insert);

		// Rotate B to the correct position
		while (position > 0)
		{
			rb(b);
			position--;
		}

		// Push the element from A to B
		pb(b, a);
	}

	// Push all elements back to A
	while (b->top >= 0)
		pa(a, b);
}

int find_position(t_stack *stack, int num)
{
	int i;

	for (i = 0; i <= stack->top; i++)
	{
		if (num > stack->array[i])
			return i;
	}
	return i;
}
