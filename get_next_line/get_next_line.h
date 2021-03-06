/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:28:06 by mandriic          #+#    #+#             */
/*   Updated: 2021/11/11 14:29:36 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../bonus/push_swap_bonus.h"

char	*get_next_line(int fd);
char	*ft_strdup_mod(char *s, int check);
int		ft_strlen_mod(const char *s);
char	*ft_strjoin_mod(char *s1, char *s2);
int		ft_strchr_mod(const char *s, char c);
char	*ft_strjoin_mod2(char *s1, char *s2, char c);
#endif
