/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:53:10 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/06 12:34:46 by gzovkic          ###   ########.fr       */
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
	
}			t_stacks;

// error_msg.c_________________________________
void	printf_and_exit(char *message);

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


#endif