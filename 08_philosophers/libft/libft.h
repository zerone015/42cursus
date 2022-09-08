/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:35:50 by yoson             #+#    #+#             */
/*   Updated: 2022/09/02 20:52:41 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

typedef struct s_lst
{
	void			*content;
	struct s_lst	*next;
}	t_lst;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isblank(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

int		ft_atoi(const char *str);
char	*ft_itoa(int n);

int		ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);

void	*ft_memset(void *mem, int c, size_t len);
void	ft_bzero(void *str, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*safe_malloc(size_t size);

char	**ft_split(char const *str, char sep);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *src, int start, int len);

void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_perror(const char *s);

void	ft_striteri(char *str, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

t_lst	*ft_lstnew(void *content);
void	ft_lstadd_front(t_lst **lst, t_lst *new);
void	ft_lstadd_back(t_lst **lst, t_lst *new);
int		ft_lstsize(t_lst *lst);
t_lst	*ft_lstlast(t_lst *lst);
void	ft_lstdelone(t_lst *lst, void (*del)(void *));
void	ft_lstclear(t_lst **lst, void (*del)(void *));
void	ft_lstiter(t_lst *lst, void (*f)(void *));
t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *));

#endif
