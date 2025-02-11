/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:53:10 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/11 17:15:05 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/ft_printf/ft_printf.h"
# include "libft/includes/get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <limits.h>

typedef struct	s_stacks
{
	int *stack_a;
	int *stack_b;
	int *index_stack;
	int	size_a;
	int size_b;
	int size_i;
	
}			t_stacks;

// error_msg.c_________________________________
void	printf_and_exit(char *message);
void	check_doubles(t_stacks *stacks);

// utils.c_____________________________________
int	ft_strlen_index(char *map[]);
void	free_split(char **map);
void	check_argument(char *stack_a);
long	ft_atolo(const char *str);


// Malloc_func.c_______________________________
char **create_stack_a_split(char *stack_a);
int *create_stack_a_int(char **stack_a_split);
char *create_argument_str(char *argv[]);

// sorting_func.c______________________________
int	*bubble_sort_stack(int *stack_a_int, int stack_a_length);

// s_operations.c______________________________
void sa(t_stacks *stacks);
void sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

// p_operations.c_______________________________
void pa(t_stacks *stacks);
void pb(t_stacks *stacks);

// r_operations.c________________________________
void ra(t_stacks *stacks);
void rb(t_stacks *stacks);
void rr(t_stacks *stacks);

// rr_operations.c_________________________________
void rra(t_stacks *stacks);
void rrb(t_stacks *stacks);
void rrr(t_stacks *stacks);

// New functions
void switch_index(t_stacks *stacks);
void return_to_sender(t_stacks *stacks);

#endif