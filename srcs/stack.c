/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:23:38 by eel-abed          #+#    #+#             */
/*   Updated: 2024/09/04 14:42:35 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	stack_pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (!stack->top)
		return (0);
	temp = stack->top;
	value = temp->value;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return (value);
}

void	stack_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*first;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	stack_reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack->top || !stack->top->next)
		return ;
	last = stack->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = stack->top;
	stack->top = last;
	second_last->next = NULL;
}

void	stack_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}
