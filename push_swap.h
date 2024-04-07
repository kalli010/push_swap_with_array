#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct
{
	int	*collection;
	int	capacity;
	int	size;
}		stack;


stack	*create_stack(int capacity);
void	s(char d, stack *c);
void	ss(stack *a, stack *b);
void	r(char d, stack *c);
void	rr(stack *a, stack *b);
void	revr(char d, stack *c);
void	revrr(stack *a, stack *b);
void	pb(stack *b, stack *a);
void	pa(stack *a, stack *b);
int		pop(stack *stack);
int		push(stack *stack, int item);
int		is_full(stack *stack);
int		is_empty(stack *stack);

void	join(char *str, char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_count_words(const char *s, char c);
void	find_next_word(const char *s, size_t *start, char c, size_t *end);
char	*allocate_and_copy_word(const char *s, size_t start, size_t end);
char	**allocate_words(char const *s, char c, char **array,
			size_t word_count);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
