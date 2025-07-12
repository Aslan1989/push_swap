/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:57:36 by aisaev            #+#    #+#             */
/*   Updated: 2025/06/16 12:44:40 by aisaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Returns the index of a value in the stack.
 * searches for a node with a specific value in the stack
 *
 * @param stack Pointer to the stack.
 * @param value Value to find.
 * @return Index of the value, or -1 if not found.
 */
int	get_index(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == value)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

/**
 * @brief Frees the entire stack from memory.
 * temporary pointer to help free each node.
 * Save the current node in tmp
 * Move the stack pointer to the next node
 * Free the memory of the current node
 * @param stack Pointer to the stack to be freed.
 */
void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/**
 * @brief Exits the program with an error message.
 *
 * @param stack Stack to be freed before exit.
 */
void	exit_error(t_stack *stack)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * @brief Frees a 2D array of strings.
 * While the current pointer is not NULL
 * Finally, free the array of pointers itself
 * @param arr Array of strings to free.
 */
void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
