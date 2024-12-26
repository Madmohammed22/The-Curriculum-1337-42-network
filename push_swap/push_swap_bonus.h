/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:19:13 by mmad              #+#    #+#             */
/*   Updated: 2024/02/17 09:43:38 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <ctype.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
// # include "get_next_line.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

struct				s_handler
{
	int				number;
	int				number2;
};

# ifndef INVALID_READ 
#  define INVALID_READ -1
# endif

t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				del(t_list *data);
void				ft_lstclear(t_list **lst, void (*del)(t_list *));

char				*ft_argv(int argc, char **argv);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *nptr, struct s_handler *result,
						int sign, long long value);
int					ft__atoi(const char *nptr);
char				**ft_split(char const *s, char c);
void				ft_putendl_fd(char *s, int fd);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_push_linked_stack(t_list **stack, int value);
int					ft_return_longest(t_list *stack);
int					ft_return_lowest(t_list *stack);
int					find(t_list *head, int n);
void				ft_sort_stack(t_list **top, t_list **tempStack, int p);
t_list				*ft_copy_stack(t_list *stack_b, t_list *stack_a);
t_list				*ft_sort_list(t_list *stack);
int					ft_check_if_sorted(t_list **stack_a);
int					ft_check_if_valid(char **s, struct s_handler *checker);
int					ft_has_repeated_characters(char **s, int size);
void				ft_call_free(char **s, int index, char *arr,
						void (*ft_exit)(void));
void				ft_exit_zero(void);
void				ft_exit_one(void);

int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*get_next_line(int fd);
int					get_len(char **s);
int					execute_instructions(char *ar, t_list **stack_a,
						t_list **stack_b);
void				ft_build_list(char **s, t_list **stack_a,
						struct s_handler checker, long long value);
int					ft_checker(char **s, t_list **stack_a,
						struct s_handler checker, t_list **stack_b);
void				ft_clean(t_list **stack_a, t_list **stack_b);
void				ft_display_result(t_list **stack_a, t_list **stack_b);

void				b_sa(t_list **stack_a);
void				b_sb(t_list **stack_b);
void				b_pa(t_list **stack_a, t_list **stack_b);
void				b_pb(t_list **stack_a, t_list **stack_b);
void				b_rb(t_list **stack_b);
void				b_ra(t_list **stack_a);
void				b_rrb(t_list **stack_b);
void				b_rra(t_list **stack_a);
void				rrr(t_list **stack_a, t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				b_rr(t_list **stack_a, t_list **stack_b);
#endif
