/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:09:03 by adube             #+#    #+#             */
/*   Updated: 2023/07/27 10:29:50 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_pile
{
	int				value;
	void			*content;
	int				current_pos;
	int				final_index;
	int				move_price;
	bool			above_median;
	bool			cheapest;
	struct s_pile	*target;
	struct s_pile	*next;
	struct s_pile	*prev;
}				t_pile;

int				ft_atoi(const char *nptr);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *b, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			**ft_split(char *s, char c);
void			*ft_calloc(size_t count, size_t size);
int				ft_strlcpy(char *dest, const char *src, size_t size);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_lstadd_back(t_pile **lst, t_pile *new);
void			ft_lstadd_front(t_pile **lst, t_pile *new);
void			ft_lstclear(t_pile **lst, void (*del)(void *));
void			ft_lstdelone(t_pile *lst, void (*del)(void *));
void			ft_lstiter(t_pile *lst, void (*f)(void *));
t_pile			*ft_lstlast(t_pile *lst);
t_pile			*ft_lstmap(t_pile *lst, void *(*f)(void *),
					void (*del)(void *));
t_pile			*ft_lstnew(void *content);
int				ft_lstsize(t_pile *lst);

#endif
