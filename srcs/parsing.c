/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:30:24 by eel-abed          #+#    #+#             */
/*   Updated: 2024/09/08 15:32:47 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**init_args(int argc, char **argv, int *count, int *should_free)
{
	char	**args;

	*should_free = (argc == 2);
	if (*should_free)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv + 1;
		*count = argc - 1;
	}
	return (args);
}

static int	*allocate_numbers(char **args, int *count, int should_free)
{
	int	*numbers;

	if (should_free)
	{
		*count = 0;
		while (args[*count])
			(*count)++;
	}
	numbers = (int *)malloc(sizeof(int) * *count);
	if (!numbers && should_free)
		free_split(args);
	return (numbers);
}

static int	parse_numbers(char **args, int *numbers, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!is_number(args[i]))
			return (0);
		numbers[i] = atoi(args[i]);
		i++;
	}
	return (1);
}

int	*parse_arguments(int argc, char **argv, int *count)
{
	int		*numbers;
	char	**args;
	int		should_free;

	args = init_args(argc, argv, count, &should_free);
	if (!args)
		return (NULL);
	numbers = allocate_numbers(args, count, should_free);
	if (!numbers)
		return (NULL);
	if (!parse_numbers(args, numbers, *count)
		|| has_duplicates(numbers, *count))
	{
		free(numbers);
		if (should_free)
			free_split(args);
		return (NULL);
	}
	if (should_free)
		free_split(args);
	return (numbers);
}
