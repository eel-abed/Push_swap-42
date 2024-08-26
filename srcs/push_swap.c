/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:22:54 by eel-abed          #+#    #+#             */
/*   Updated: 2024/08/23 17:05:29 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_stack(t_stack *stack)
{
    t_stack *reversed_stack;
    int value;

    reversed_stack = create_stack(stack->size);
    if (!reversed_stack)
    {
        printf("Error\n");
        return;
    }

    while (stack->top >= 0)
    {
        value = pop(stack);
        push(reversed_stack, value);
    }

    free(stack->array);
    stack->array = reversed_stack->array;
    stack->top = reversed_stack->top;
    free(reversed_stack);
}
int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc < 2)
	{
		printf("Usage: ./push_swap [numbers]\n");
		return (0);
	}
	stack_a = create_stack(argc - 1);
	stack_b = create_stack(argc - 1);

	if (!stack_a || !stack_b)
	{
		printf("Error\n");
		return (0);
	}

	i = 1;
	while (i < argc)
	{
		push(stack_a, atoi(argv[i]));
		i++;
	}

	if (has_duplicates(stack_a))
	{
		printf("Error\n");
		return (0);
	}

	if (is_sorted(stack_a))
	{
		printf("Stack is already sorted\n");
		return (0);
	}
	reverse_stack(stack_a);
	sort(stack_a, stack_b);
	
	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
	return (0);
}
