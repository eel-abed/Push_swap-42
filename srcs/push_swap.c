/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:22:54 by eel-abed          #+#    #+#             */
/*   Updated: 2024/09/05 14:58:19 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack->top || !stack->top->next)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_pow(int base, int exp)
{
	int	result;

	result = 1;
	while (exp > 0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

static void	initialize_stacks(t_stack *a, t_stack *b, int *numbers, int count)
{
	int	i;

	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
	i = count - 1;
	while (i >= 0)
	{
		stack_push(a, numbers[i]);
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*numbers;
	int		count;

	if (argc < 2)
		return (0);
	numbers = parse_arguments(argc, argv, &count);
	if (!numbers)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	initialize_stacks(&a, &b, numbers, count);
	free(numbers);
	if (count > 1 && !is_sorted(&a))
		radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
