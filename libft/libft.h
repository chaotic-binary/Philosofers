/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:54:41 by ttamesha          #+#    #+#             */
/*   Updated: 2021/01/07 16:41:32 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

char					*ft_itoa(int n);
char					*ft_itoa_base_ll(long long n, long long bs);
char					*ft_strchr(const char *str, int c);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strdup(const char *src);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strnstr(const char *hst, const char *ndl, size_t n);
char					*ft_strmapi(char const *s,\
									char (*f)(unsigned int, char));
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_strrchr(const char *str, int c);
char					*ft_substr(char const *s, unsigned int start,\
									size_t len);
char					**ft_split(char const *s, char c);
int						ft_atoi(char *str);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
int						ft_isspace(int c);
int						ft_memcmp(const void *str1, const void *str2, size_t n);
int						ft_strcmp(char *str1, char *str2);
int						ft_strncmp(const char *str1, const char *str2,\
									size_t n);
int						ft_tolower(int c);
int						ft_toupper(int c);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlcpy(char *dest, const char *src, size_t size);
size_t					ft_strlen(const char *str);
void					ft_bzero(void *str, size_t n);
void					*ft_calloc(size_t nitems, size_t size);
void					*ft_memccpy(void *dest, const void *src,\
									int c, size_t n);
void					*ft_memchr(const void *str, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memset(void *str, int c, size_t n);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putnbr_base_ll(long long n, long long bs);
void					ft_putstr_fd(char *s, int fd);
void					*malloc_c(size_t size);
void					*calloc_c(size_t nitems, size_t size);
void					free_arr(char **arr);
void					free_and_null(char **str);
int						stradd(char **str, char *new);
double					ft_atof(char *str);
double					ft_pow(double n, double pow);
int						ft_max(int x, int y);
int						ft_min(int x, int y);
int						countdigits(int n);
int						countdigits_base_ll(long long n, long long bs);

typedef struct			s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
t_list					*ft_lstnew(void *content);
t_list					*ft_lstnew_c(void *content);
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),\
									void (*del)(void *));
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstadd_front(t_list **lst, t_list *new);
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));

typedef struct			s_dlist
{
	void				*content;
	struct s_dlist		*next;
	struct s_dlist		*prev;
}						t_dlist;

t_dlist					*ft_dlstnew(void *content);
t_dlist					*ft_dlstnew_c(void *content);
t_dlist					*ft_dlstlast(t_dlist *lst);
void					ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void					ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void					ft_dlstclear(t_dlist **lst, void (*del)(void *));

#endif
