/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:23:38 by eel-abed          #+#    #+#             */
/*   Updated: 2024/08/13 13:20:44 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int size)
{
	t_stack *new_stack;

	new_stack = malloc(sizeof(t_stack));
	if(!new_stack)
		return (NULL);
	new_stack->array = malloc(size * sizeof(int));
	if (!new_stack->array)
	{
		free(new_stack);
		return (NULL);
	}
	new_stack->size = size;
	new_stack->top = -1;
	return (new_stack);
}

void	push(t_stack *stack, int value)
{
	if (stack->top < stack->size -1)
	{
		stack->top++;
		stack->array[stack->top] = value;
	}
	
}

int	pop(t_stack *stack)
{
	int value;
	
	if(stack->top >= 0)
	{
		value = stack->array[stack->top];
		stack->top--;
		return (value);
	}
	return (0);
}
