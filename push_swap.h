/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:45:09 by aisaev            #+#    #+#             */
/*   Updated: 2025/06/16 12:26:31 by aisaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <libft.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	int				index;
}	t_stack;

//swap.c
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

//push.c
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

//rotate.c
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

//rev_rotate.c
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//units.c
int		get_index(t_stack *stack, int value);
void	free_stack(t_stack *stack);
void	exit_error(t_stack *stack);
int		get_direction(int pos, int size);
void	free_split(char **arr);

//parser.c
int		parse_args(t_stack **a, char **argv);

//radix_sort.c
void	radix_sort(t_stack **a, t_stack **b);

//sort_stack.c
int		stack_size(t_stack *stack);
void	sort_stack(t_stack **a, t_stack **b);
int		is_sorted(t_stack *stack);
void	find_and_assign_min(t_stack *stack, int i);
void	assign_indexes(t_stack *stack);

//sort_small.c
void	sort_three(t_stack **a);
void	sort_small(t_stack **a, t_stack **b);
#endif
