/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cub3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:29:24 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/30 15:01:41 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_CUB3D_H
# define PARS_CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define RED_W "\x1B[31m"
# define GRN_W "\x1B[32m"
# define RESET "\x1B[0m"

char	*get_next_line(int fd);
void	*ft_malloc(size_t n);
char	**ft_create_two_dimensional_array(char **argv);
bool	ft_grep_to_pars_if(char ch, t_condition *game_condition,
			bool (*f)(t_list *, t_condition *));
bool	ft_to_do_textures(t_list *node, t_condition *game_condition);
bool	ft_to_do_c_floor(t_list *node, t_condition *game_condition);
bool	ft_to_do_map(t_list *node, t_condition *game_condition);
t_list	*ft_add_substrings_to_linked_list(t_list *node, char **sub_str,
			int flag);
void	ft_print_linked_list(t_list *node);
bool	ft_duplicates(t_list *node);
bool	ft_pars_each_node(t_list *node, t_condition *game_condition);
bool	ft_pars_portion(char **substr, t_condition *game_condition);
int		find_specific_char(char *str, int c);
int		ft_count_substr(char **substr);
void	ft_print_substr(char **substr);
bool	ft_spin(const char *str);
char	**ft_buffer_to_two_d_array(t_list *node, int length, int flag);
void	ft_print_double_list(t_list **nodes);
bool	process_c_flor(char *str);
void	ft_print_substr(char **substr);
void	ft_enqueue(int x, int y, t_queue **front, t_queue **rear);
void	ft_dequeue(t_queue **front, t_queue **rear);
bool	process_textture(char *str);
int		ft_count_substr(char **substr);
bool	ft_atoi_if(const char *nptr);
int		ft_count_specific_char(char *str, char c);
bool	ft_check_up(char *str);
int		ft_n_columns_2d(char **substr);
void	fill_modified_map(t_condition *game_condition);
bool	breadth_first_search(char **new_map, t_condition *game_condition);
void	ft_find_direction(char **new_map, int *x, int *y,
			t_condition *game_condition);
int		ft_check_start_end(char **map, int *n_direction, int flag);
bool	check_for_dead_ends(char **new_map);
int		ft_find_longest_line(char **substr, int *hight);
void	ft_process_game_condition(t_list *textures, t_list *c_flor, t_list *map,
			t_condition *game_condition);
bool	ft_find_color(char *str, char c);
void	ft_import_colors(t_list *floor, t_list *ceiling,
			t_condition *condition);
void	ft_node_colors(t_list *node, t_condition *condition);
bool	ft_to_do_map_bonus(t_list *node, t_condition *game_condition);
bool	move_on_if_map_valid_bonus(t_condition *condition);
void	ft_print_queue(t_queue *front);
t_queue	*fill_directions(void);
void	ft_costom_map(t_condition *cnd);
bool	valid(t_condition *condition, int x, int y);
void	scale_size_of_map(t_condition *condition, int *new_hight,
			int *new_width);
#endif