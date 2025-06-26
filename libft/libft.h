/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:37 by jgalizio          #+#    #+#             */
/*   Updated: 2025/05/05 10:14:57 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef MAX_FD
#  define MAX_FD __FD_SETSIZE
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef enum e_bool
{
	f,
	t
}	t_bool;

char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);
int			ft_atoi(const char *str);
int			ft_fprintf(ssize_t fd, const char *str, ...);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_lstsize(t_list *lst);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_printf(const char *str, ...);
int			ft_putchar_fd(char c, ssize_t fd);
int			ft_puthex_fd(size_t nbr, char c, ssize_t fd);
int			ft_putmemaddr_fd(void *mem_addr, ssize_t fd);
int			ft_putnbr_fd(int n, ssize_t fd);
int			ft_putstr_fd(char *str, ssize_t fd);
int			ft_putunbr_fd(unsigned int nbr, ssize_t fd);
int			ft_strchr_index(char *str, int char_to_find);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);
long		ft_atol(const char *str);
size_t		count_tokens(char const *s, char c);
size_t		ft_numlen(int nb);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
t_bool		ft_str_isempty(char *str);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
uint32_t	ft_atoi_hex(const char *str);
void		error_call(char *err, char *msg);
void		error_exit(char *err, char *msg, int exit_code);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_free_matrix(void **mtx);
void		ft_free(void **ptr);
void		ft_lstadd_back(t_list **lst, t_list *newlst);
void		ft_lstadd_front(t_list **lst, t_list *newlst);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putendl_fd(char *s, int fd);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		perror_call(char *err, char *msg);
void		perror_exit(char *err, char *msg, int exit_code);
#endif
