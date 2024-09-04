/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:46:49 by eel-abed          #+#    #+#             */
/*   Updated: 2024/09/04 14:37:49 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	stack_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	stack_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_rotate(b);
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	stack_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	stack_reverse_rotate(b);
	write(1, "rrb\n", 4);
}
