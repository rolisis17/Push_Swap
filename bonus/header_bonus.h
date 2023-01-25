/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:14:03 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/25 18:06:27 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include "./gnl/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				pos;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

void	free_lst_bonus(t_list *lst);

void	new_node_bonus(t_list **lst, int nbr);

int		extract_number_bonus(t_list **lst, char **av);

int		make_list(int ac, char **av, t_list **lst_a);

void	do_swap(char *move, t_list **lst_a, t_list **lst_b);

void	show_mov_bonus(t_list **lst_a, t_list **lst_b, char *move);

void	swap_top_bonus(t_list **lst);

void	swap_rotate_bonus(t_list **lst);

void	swap_reverse_bonus(t_list **lst);

void	swap_ab_bonus(t_list **from, t_list **to);

int		ft_strcmp(const char *s1, const char *s2);

int		check_order_bonus(t_list *lst);

void	checker_cmp(char *line, t_list **lst_a, t_list **lst_b);

t_list	*get_last_bonus(t_list *lst_a);

int		is_nbr_bonus(char **str);

int		check_doubles_bonus(t_list *lst);

int		check_intmax_bonus(long nbr);

int		error_printer(void);

void	put_pos_bonus(t_list **lst);

#endif