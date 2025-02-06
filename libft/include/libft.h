/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:40:53 by trolland          #+#    #+#             */
/*   Updated: 2025/02/06 08:21:07 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//****************************************************************************//
// -------------------------- NECESSARY LIBRARIES --------------------------- //
//****************************************************************************//

# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

//****************************************************************************//
// ------------------------- SYSTEM'S SPECIFICATION ------------------------- //
//****************************************************************************//

# if defined(__linux__)
#  define PTRNULL "(nil)"
# elif defined(__APPLE__)
#  define PTRNULL "(0x0)"
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//****************************************************************************//
// ------------------------------- CHAR UTILS ------------------------------- //
//****************************************************************************//

/*verify if a char is a letter (returns 1 if true, 0 if false)*/
int					ft_isalpha(int c);
/*verify if a char is a digit (returns 1 if true, 0 if false)*/
int					ft_isdigit(int c);
/*verify if a char is a letter or a digit (returns 1 if true, 0 if false)*/
int					ft_isalnum(int c);
/*verify if a char is a ASCII char (returns 1 if true, 0 if false)*/
int					ft_isascii(int c);
/*verify if a char is printable (returns 1 if true, 0 if false)*/
int					ft_isprint(int c);
/*verify if a char is a '+' or '-' (returns 1 if true, 0 if false)*/
int					ft_isposneg(int c);
/*verify if a char is a whitespace (returns 1 if true, 0 if false)*/
int					ft_iswhitespace(int c);
/*verify if a char is a lowercase (returns 1 if true, 0 if false)*/
int					ft_islower(int c);
/*verify if a char is a upercase (returns 1 if true, 0 if false)*/
int					ft_isupper(int c);
/*convert a char to lowercase*/
int					ft_toupper(int c);
/*convert a char to upercase*/
int					ft_tolower(int c);

//****************************************************************************//
// ------------------------------ STRING UTILS ------------------------------ //
//****************************************************************************//

/*calculate the length of a string*/
size_t				ft_strlen(const char *str);
/*copy a src string to dest with a maxlen*/
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*concatenate a src string to dest with a maxlen*/
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
/*search for a char in a string and return a pointer to the first occurence*/
char				*ft_strchr(const char *s, int c);
/*search for a char in a string and return a pointer to the last occurence*/
char				*ft_strrchr(const char *s, int c);
/*search for a string in a string and return a pointer to the 1st occurence*/
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
/*duplicate a string*/
char				*ft_strdup(const char *s1);
/*join two strings*/
char				*ft_strjoin(char const *s1, char const *s2);
/*split a string in an array of strings separated by a single char*/
char				**ft_split(char const *s, char c);
/*split a string in an array of strings separated by a specific list of chars*/
char				**ft_split_multi(char const *s, char *c);
/*extracts a substring from a given string starting at a specified index for
a specified length*/
char				*ft_substr(char const *s, unsigned int start, size_t len);
/*trim a string from a set of characters at the beginning and the end*/
char				*ft_strtrim(char const *s1, char const *set);
/*transforms an integer to a string*/
int					ft_strncmp(const char *s1, const char *s2, size_t n);
/*verify if last characters of a string are equal to another string*/
int					ft_strcmp(char *s1, char *s2);
/*compares two strings and returns 0 if they are identical*/
int					check_last_characters(char *str, char *last);
/*counts the number of words in a string separated by a single char*/
int					count_words(char const *str, char charset);
/*counts the number of words in a string separated by a specific list of chars*/
int					count_words_sep(char const *str, char *charset);
/*checks if a character is in a string*/
int					is_in_string(char c, char *str);
/*transform an integer to a string*/
char				*ft_itoa(int n);
/*transforms a nuumber in a string to an integer*/
int					ft_atoi(const char *str);
/*transforms a nuumber in a string to a long long integer*/
long long			ft_atoll(const char *str);
/*reads a line from a file descriptor*/
char				*get_next_line(int fd);
/*iterate over a string and apply a function to each character*/
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
/*create a new string by applying a function to each character of a string*/
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

//****************************************************************************//
// ------------------------------ MEMORY UTILS ------------------------------ //
//****************************************************************************//

/*allocate memory for a string and initialize it with '\0'*/
void				*ft_calloc(size_t count, size_t size);
/*set a memory block of size len to 0*/
void				ft_bzero(void *s, size_t n);
/*returns a pointer to a memory block of size len set to a specific value c*/
void				*ft_memset(void *b, int c, size_t len);
/*copies a memory block from src to dest, and returns a pointer to dest.
undifined behavior if the memory blocks overlap*/
void				*ft_memcpy(void *dst, const void *src, size_t n);
/*copies a memory block from src to dest, and returns a pointer to dest.
the memory blocks can overlap*/
void				*ft_memmove(void *dst, const void *src, size_t len);
/*returns a pointer to the first occurence of a byte c in a memory block*/
void				*ft_memchr(const void *s, int c, size_t n);
/*compares byte strings s1 and s2. returns 0 if they are identical*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);
/*frees an array of strings*/
void				ft_free_tab(char **tab);

//****************************************************************************//
// ------------------------------ PRINT UTILS ------------------------------- //
//****************************************************************************//

/*recreate the printf function*/
int					ft_printf(const char *str, ...);
/*writes a char to a file descriptor*/
int					ft_putchar_fd(char c, int fd);
/*writes a char to the standard output*/
int					ft_putchar(char c);
/*writes a string to a file descriptor*/
int					ft_putstr_fd(char *s, int fd);
/*writes a string to the standard output*/
int					ft_putstr(char *s);
/*writes a string to a file descriptor followed by a newline*/
int					ft_putendl_fd(char *s, int fd);
/*writes a number to a file descriptor*/
int					ft_putnbr_fd(int n, int fd);
/*writes a number to the standard output*/
int					ft_putnbr(int n);
/*writes a number to rhe standard output in a specific base*/
int					ft_putnbr_base(unsigned long long nbr, char *base);

//****************************************************************************//
// ------------------------------ MATHS UTILS ------------------------------- //
//****************************************************************************//

/*swaps two variables*/
void				ft_swap(void *a, void *b, size_t size);
/*swaps two integers*/
void				ft_int_xor_swap(int *a, int *b);
/*returns the rounded value of a float*/
int					ft_round(float num);
/*returns the maximum value between two integers*/
int					ft_max(int nb1, int nb2);
/*returns the minimum value between two integers*/
int					ft_min(int nb1, int nb2);

//****************************************************************************//
// ------------------------------ LINKED LIST ------------------------------- //
//****************************************************************************//

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
