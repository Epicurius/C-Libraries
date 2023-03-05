/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 19/03/2023 Niklas Neronin
 * Updated: 26/03/2023 Niklas Neronin
 */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# define GNL_BUFF_SIZE 60
# define FTS_BUFF_SIZE 1000
# define GNL_FILE_NB 128

# define TRUE			1
# define FALSE			0
# define MAX_INT		2147483647
# define MIN_INT		-2147483648

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

double		ft_atof(const char *str);
int			ft_atoi(const char *nptr);
double		ft_fclamp(double x, double a, double b);
int			ft_clamp(int x, int a, int b);
t_list		*ft_dellstnode(t_list **lst, t_list *del);
char		*ft_fdtostr(int fd, int i);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isupper(int c);
int			ft_iswspace(int c);
char		*ft_itoa(int nbr);
int			ft_lstadd(t_list **alst, t_list *new);
int			ft_lstadd_new(t_list **list, void *content, size_t content_size);
int			ft_lstdelnode(t_list **alst, void (*del)(void*, size_t));
t_list		*ft_lstnew(void const *content, size_t content_size);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memalloc(size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memncmp(const void *ptr1, const void *ptr2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_memdel(void **ap);
void		*ft_memdup(const void *mem, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t len);
void		*ft_memset(void *dest, int val, size_t len);
double		ft_min(double a, double b);
double		ft_max(double a, double b);
int			ft_nbrlen(long nbr);
int			ft_uintlen(unsigned int x);
int			ft_intlen(int x);
double		ft_pow(double n, int pow);
long double	ft_long_pow(long double n, int pow);
void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putnchar(char c, int nbr);
void		ft_putnstr(char *str, int n);
void		ft_putstr(char const *s);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strchr(const char *str, int c);
int			ft_strchri(const char *str, int c);
int			ft_strcmp(const char *str1, const char *str2);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strtrim(char *str, int start, int len);
char		*ft_strdup(const char *s);
char		*ft_strjoin(const char *str1, const char *str2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strncat(char *dest, const char *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *s1, const char *s2, size_t n);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strrchr(const char *s, int c);
char		*ft_strrev(char *str);
char		**ft_strsplit(const char *s, char c, int *nb);
char 		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strsub(char const *str, int start, int len);
void		ft_swap(int *a, int *b);
void		ft_timer_start(void);
double		ft_timer_end(void);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			get_next_line(const int fd, char **line);

#endif
