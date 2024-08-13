/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:23:13 by eel-abed          #+#    #+#             */
/*   Updated: 2024/08/13 14:53:41 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int *array;
	int size;
	int top;
} t_stack;

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
t_stack	*create_stack(int size);
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_stack(t_stack *a, t_stack *b);
int		find_position(t_stack *stack, int num);
void	ra(t_stack *stack);




#endif
