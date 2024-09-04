/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:23:46 by eel-abed          #+#    #+#             */
/*   Updated: 2024/09/04 14:43:00 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse_arguments(int argc, char **argv, int *count)
{
	int	*numbers;
	int	i;

	*count = argc - 1;
	numbers = (int *)malloc(sizeof(int) * *count);
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < *count)
	{
		if (!is_number(argv[i + 1]))
		{
			free(numbers);
			return (NULL);
		}
		numbers[i] = atoi(argv[i + 1]);
		i++;
	}
	if (has_duplicates(numbers, *count))
	{
		free(numbers);
		return (NULL);
	}
	return (numbers);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}

void	rrr(t_stack *a, t_stack *b)
{
	stack_reverse_rotate(a);
	stack_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
