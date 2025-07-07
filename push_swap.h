/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:24:57 by dancuenc          #+#    #+#             */
/*   Updated: 2025/07/07 13:24:57 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/************************************
 * main.c
 ************************************/
/**
 * @brief Entry point for the push_swap program.
 *
 * Parses command-line arguments, initializes stacks,
 * and sorts the stack using the appropriate algorithm.
 *
 * @param ac Argument count (int).
 * @param av Argument vector (array of strings).
 * @return 0 on success, 1 on error or invalid input.
 */
int				main(int ac, char **av);

/************************************
 * error.c
 ************************************/
/**
 * @brief Checks if a string is a valid integer (syntax only).
 *
 * Accepts optional '+' or '-' at the start, followed by digits.
 *
 * @param str The string to check.
 * @return 1 if invalid, 0 if valid.
 */
int				error_syntax(char *str);

/**
 * @brief Checks if a value already exists in the stack.
 *
 * @param a The stack to search (t_stack_node*).
 * @param n The integer to check for duplicates.
 * @return 1 if duplicate found, 0 otherwise.
 */
int				error_duplicate(t_stack_node *a, int n);

/**
 * @brief Frees all memory used by a stack.
 *
 * @param stack Pointer to the stack to free (t_stack_node**).
 */
void			free_stack(t_stack_node **stack);

/**
 * @brief Frees the stack, prints an error message, and exits the program.
 *
 * @param a Pointer to the stack to free (t_stack_node**).
 */
void			free_errors(t_stack_node **a);

/************************************
 * stack_init.c
 ************************************/
/**
 * @brief Initializes stack 'a' from an array of strings.
 *
 * Converts each string to an integer, checks for errors, and adds to the stack.
 *
 * @param a Pointer to the stack to initialize (t_stack_node**).
 * @param av Array of strings representing numbers.
 */
void			init_stack_a(t_stack_node **a, char **av);

/**
 * @brief Finds the node marked as 'cheapest' in the stack.
 *
 * @param stack The stack to search (t_stack_node*).
 * @return Pointer to the cheapest node, or NULL if not found.
 */
t_stack_node	*get_cheapest(t_stack_node *stack);

/**
 * @brief Rotates the stack until the given node is on top.
 *
 * Uses the optimal direction for stack 'a' or 'b'.
 *
 * @param stack Pointer to the stack (t_stack_node**).
 * @param top_node The node to bring to the top (t_stack_node*).
 * @param stack_name 'a' or 'b' to indicate which stack is being operated on.
 */
void			prep_for_push(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);

/************************************
 * mutable_split.c
 ************************************/
/**
 * @brief Splits a string into an array of words using a delimiter.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return Array of strings (char**), NULL-terminated. Exits on error.
 */
char			**split(char *s, char c);

/************************************
 * init_a_to_b.c
 ************************************/
/**
 * @brief Updates the index and above_median fields for each node in the stack.
 *
 * @param stack The stack to update (t_stack_node*).
 */
void			current_index(t_stack_node *stack);

/**
 * @brief Marks the node with the lowest push_cost as 'cheapest'.
 *
 * @param stack The stack to search (t_stack_node*).
 */
void			set_cheapest(t_stack_node *stack);

/**
 * @brief Prepares stack 'a' for moving elements to 'b'
 * by setting indices, targets, and costs.
 *
 * @param a Stack a (t_stack_node*).
 * @param b Stack b (t_stack_node*).
 */
void			init_nodes_a(t_stack_node *a, t_stack_node *b);

/************************************
 * init_b_to_a.c
 ************************************/
/**
 * @brief Prepares stack 'b' for moving elements to 'a' by setting targets.
 *
 * @param a Stack a (t_stack_node*).
 * @param b Stack b (t_stack_node*).
 */
void			init_nodes_b(t_stack_node *a, t_stack_node *b);

/************************************
 * stack_utils.c
 ************************************/
/**
 * @brief Counts the number of nodes in a stack.
 *
 * @param stack The stack to count (t_stack_node*).
 * @return The number of nodes in the stack.
 */
int				stack_len(t_stack_node *stack);

/**
 * @brief Finds the last node in a stack.
 *
 * @param stack The stack to search (t_stack_node*).
 * @return Pointer to the last node, or NULL if empty.
 */
t_stack_node	*find_last(t_stack_node *stack);

/**
 * @brief Checks if the stack is sorted in ascending order.
 *
 * @param stack The stack to check (t_stack_node*).
 * @return true if sorted, false otherwise.
 */
bool			stack_sorted(t_stack_node *stack);

/**
 * @brief Finds the node with the minimum value in the stack.
 *
 * @param stack The stack to search (t_stack_node*).
 * @return Pointer to the node with the smallest value.
 */
t_stack_node	*find_min(t_stack_node *stack);

/**
 * @brief Finds the node with the maximum value in the stack.
 *
 * @param stack The stack to search (t_stack_node*).
 * @return Pointer to the node with the largest value.
 */
t_stack_node	*find_max(t_stack_node *stack);

/**
 * Swaps the first two elements of stack 'a'.
 * @param a Pointer to stack 'a' (t_stack_node**).
 * @param print If false, prints "sa\n" to output.
 */
void			sa(t_stack_node **a, bool print);

/**
 * Swaps the first two elements of stack 'b'.
 * @param b Pointer to stack 'b' (t_stack_node**).
 * @param print If false, prints "sb\n" to output.
 */
void			sb(t_stack_node **b, bool print);

/**
 * Swaps the first two elements of both stacks.
 * @param a Pointer to stack 'a' (t_stack_node**).
 * @param b Pointer to stack 'b' (t_stack_node**).
 * @param print If false, prints "ss\n" to output.
 */
void			ss(t_stack_node **a, t_stack_node **b, bool print);

/**
 * Rotates stack 'a' upwards (first element becomes last).
 * @param a Pointer to stack 'a' (t_stack_node**).
 * @param print If false, prints "ra\n" to output.
 */
void			ra(t_stack_node **a, bool print);

/**
 * Rotates stack 'b' upwards (first element becomes last).
 * @param b Pointer to stack 'b' (t_stack_node**).
 * @param print If false, prints "rb\n" to output.
 */
void			rb(t_stack_node **b, bool print);

/**
 * Rotates both stacks upwards.
 * @param a Pointer to stack 'a' (t_stack_node**).
 * @param b Pointer to stack 'b' (t_stack_node**).
 * @param print If false, prints "rr\n" to output.
 */
void			rr(t_stack_node **a, t_stack_node **b, bool print);

/**
 * Reverse rotates stack 'a' (last element becomes first).
 * @param a Pointer to stack 'a' (t_stack_node**).
 * @param print If false, prints "rra\n" to output.
 */
void			rra(t_stack_node **a, bool print);

/**
 * Reverse rotates stack 'b' (last element becomes first).
 * @param b Pointer to stack 'b' (t_stack_node**).
 * @param print If false, prints "rrb\n" to output.
 */
void			rrb(t_stack_node **b, bool print);

/**
 * Reverse rotates both stacks.
 * @param a Pointer to stack 'a' (t_stack_node**).
 * @param b Pointer to stack 'b' (t_stack_node**).
 * @param print If false, prints "rrr\n" to output.
 */
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

/**
 * Pushes the top element from stack 'b' to stack 'a'.
 * @param a Pointer to stack 'a' (t_stack_node**).
 * @param b Pointer to stack 'b' (t_stack_node**).
 * @param print If false, prints "pa\n" to output.
 */
void			pa(t_stack_node **a, t_stack_node **b, bool print);

/**
 * Pushes the top element from stack 'a' to stack 'b'.
 * @param b Pointer to stack 'b' (t_stack_node**).
 * @param a Pointer to stack 'a' (t_stack_node**).
 * @param print If false, prints "pb\n" to output.
 */
void			pb(t_stack_node **b, t_stack_node **a, bool print);

/**
 * Sorts a stack of exactly three elements.
 * @param a Pointer to stack 'a' (t_stack_node**).
 */
void			sort_three(t_stack_node **a);

/**
 * Sorts stacks larger than three elements using the main algorithm.
 * @param a Pointer to stack 'a' (t_stack_node**).
 * @param b Pointer to stack 'b' (t_stack_node**).
 */
void			sort_stacks(t_stack_node **a, t_stack_node **b);

#endif
