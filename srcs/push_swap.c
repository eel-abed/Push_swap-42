/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:22:54 by eel-abed          #+#    #+#             */
/*   Updated: 2024/08/21 16:16:30 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
	return (0);
}
