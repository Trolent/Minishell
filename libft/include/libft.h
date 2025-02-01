/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:40:53 by trolland          #+#    #+#             */
/*   Updated: 2025/02/01 18:11:30 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//****************************************************************************//
// -------------------------- NECESSARY LIBRARIES --------------------------- //
//****************************************************************************//

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

//****************************************************************************//
// --------- GIVEN FUNCTIONS WHICH ARE PART OF THE STANDARD LIBRARY --------- //
//****************************************************************************//

/*returns 1 if character is an alphabetic character, 0 otherwise*/
int					ft_isalpha(int c);
/*returns 1 if character is a digit, 0 otherwise*/
int					ft_isdigit(int c);
/*returns 1 if character is an alphanumeric character, 0 otherwise*/
int					ft_isalnum(int c);
/*returns 1 if character is an ASCII character, 0 otherwise*/
int					ft_isascii(int c);
/*returns 1 if character is a printable character, 0 otherwise*/
int					ft_isprint(int c);
/*returns the length of a string*/
size_t				ft_strlen(const char *str);
/*fills the first n bytes of the memory area pointed to by s with a byte c*/
void				*ft_memset(void *b, int c, size_t len);
/*fills the first n bytes of the memory area pointed to by s with 0*/
void				ft_bzero(void *s, size_t n);
/*copies n bytes from memory area src to memory area dst*/
void				*ft_memcpy(void *dst, const void *src, size_t n);
/*copies n bytes from memory area src to memory area dst, areas may overlap*/
void				*ft_memmove(void *dst, const void *src, size_t len);
/*copies n characters from the string src to the string dst*/
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*append the string src to the end of dst (up to dstsize - strlen(dst) - 1)*/
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
/*capitalizes the letter c*/
int					ft_toupper(int c);
/*lowercases the letter c*/
int					ft_tolower(int c);
/*returns a pointer to the first occurrence of the character c in the string s*/
char				*ft_strchr(const char *s, int c);
/*returns a pointer to the last occurrence of the character c in the string s*/
char				*ft_strrchr(const char *s, int c);
/*compares the first n bytes of s1 and s2*/
int					ft_strncmp(const char *s1, const char *s2, size_t n);
/*returns a pointer to the first occurence of c in s, NULL if c is not found*/
void				*ft_memchr(const void *s, int c, size_t n);
/*compares the first n bytes of s1 and s2*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);
/*locates the first occurrence of the string needle in the string haystack*/
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
/*converts a string to an integer*/
int					ft_atoi(const char *str);
/*allocates count * size bytes to 0 and returns a ptr to the allocated memory*/
void				*ft_calloc(size_t count, size_t size);
/*duplicates the string s1 and returns a pointer to the new string*/
char				*ft_strdup(const char *s1);

//****************************************************************************//
// --------- GIVEN FUNCTIONS WHICH ARE PART OF THE STANDARD LIBRARY --------- //
//****************************************************************************//

/*returns a string of size len starting at index start of string s*/
char				*ft_substr(char const *s, unsigned int start, size_t len);
/*creates a new string resulting from the concatenation of s1 and s2*/
char				*ft_strjoin(char const *s1, char const *s2);
/*retturns the string trimmed s1 trimed at the beginning and end by set*/
char				*ft_strtrim(char const *s1, char const *set);
/*splits the string s using the character c as a delimiter*/
char				**ft_split(char const *s, char c);
/*transforms the integer n into a string and returns the string*/
char				*ft_itoa(int n);
/*returns a string created from the application of the function f to a string*/
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*applies the function f to each character of the string passed as argument*/
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
/*writes the character c to the file descriptor fd*/
void				ft_putchar_fd(char c, int fd);
/*writes the string s to the file descriptor fd*/
void				ft_putstr_fd(char *s, int fd);
/*writes the string s followed by a newline to the file descriptor fd*/
void				ft_putendl_fd(char *s, int fd);
/*writes the integer n to the file descriptor fd*/
void				ft_putnbr_fd(int n, int fd);

//****************************************************************************//
// ------------------------------- BONUS PART ------------------------------- //
//****************************************************************************//

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*allocates memory for a new element and initializes its content*/
t_list				*ft_lstnew(void *content);
/*adds the element new at the beginning of the list*/
void				ft_lstadd_front(t_list **alst, t_list *new);
/*returns the number of elements in the list*/
int					ft_lstsize(t_list *lst);
/*returns the last element of the list*/
t_list				*ft_lstlast(t_list *lst);
/*adds the element new at the end of the list*/
void				ft_lstadd_back(t_list **alst, t_list *new);
/*deletes and frees the memory of the element passed as argument*/
void				ft_lstdelone(t_list *lst, void (*del)(void *));
/*deletes and frees the memory of the elements of the list*/
void				ft_lstclear(t_list **lst, void (*del)(void *));
/*applies the function f to the content of each element of the list*/
void				ft_lstiter(t_list *lst, void (*f)(void *));
/*returns a new list resulting from the application of the function f
to the list*/
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

//****************************************************************************//
// --------------------------------- MY OWN --------------------------------- //
//****************************************************************************//

int					ft_strcmp(char *s1, char *s2);

#endif
