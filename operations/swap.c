/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:15:38 by aisaev            #+#    #+#             */
/*   Updated: 2025/06/13 16:37:18 by aisaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Swaps the first two elements of stack a.
 * first points to the top (1st element)
 * second points to the second element
 * first skips second and points to the 3rd element
 * second points to first
 * The top of the stack is now second
 * @param a Pointer to stack a.
 */
void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	write(1, "sa\n", 3);
}

/**
 * @brief Swaps the first two elements of stack b.
 *
 * @param b Pointer to stack b.
 */
void	sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	write(1, "sb\n", 3);
}

/**
 * @brief Performs a swap on both stack a and stack b.
 *
 * @param a Pointer to stack a.
 * @param b Pointer to stack b.
 */
void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
