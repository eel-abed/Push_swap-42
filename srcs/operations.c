/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:23:33 by eel-abed          #+#    #+#             */
/*   Updated: 2024/09/04 14:37:24 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	stack_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	stack_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->top)
	{
		stack_push(a, stack_pop(b));
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->top)
	{
		stack_push(b, stack_pop(a));
		write(1, "pb\n", 3);
	}
}
