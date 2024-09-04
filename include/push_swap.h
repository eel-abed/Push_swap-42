/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:23:13 by eel-abed          #+#    #+#             */
/*   Updated: 2024/09/04 13:56:06 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_node
{
	int value;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *top;
	int size;
} t_stack;

// Fonctions de manipulation de pile
void	stack_push(t_stack *stack, int value);
int		stack_pop(t_stack *stack);
void	stack_rotate(t_stack *stack);
void	stack_reverse_rotate(t_stack *stack);
void	stack_swap(t_stack *stack);

// Opérations Push_swap
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// Fonctions d'algorithme
void radix_sort(t_stack *a, t_stack *b);

// Fonctions utilitaires
int		is_number(char *str);
int		has_duplicates(int *numbers, int count);
int		*parse_arguments(int argc, char **argv, int *count);
void	free_stack(t_stack *stack);


#endif
