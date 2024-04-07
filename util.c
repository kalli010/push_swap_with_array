#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (s == NULL || fd < 0)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

///p.c

int	is_empty(stack *stack)
{
	if (stack->size == 0)
		return (1);
	else
		return (0);
}

int	is_full(stack *stack)
{
	if (stack->size == stack->capacity)
		return (1);
	else
		return (0);
}

int	push(stack *stack, int item)
{
	if (is_full(stack))
		return (0);
	stack->collection[stack->size] = item;
	stack->size++;
	return (1);
}

int	pop(stack *stack)
{
	if (is_empty(stack))
		return (0);
	stack->size--;
	return (1);
}

void	pa(stack *a, stack *b)
{
	push(a, b->collection[b->size - 1]);
	pop(b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(stack *b, stack *a)
{
	push(b, a->collection[a->size - 1]);
	pop(a);
	ft_putstr_fd("pb\n", 1);
}

///r.c

void	r(char d, stack *c)
{
	int	tmp;
	int	i;

	i = c->size - 1;
	tmp = c->collection[i];
	while (i > 0)
	{
		c->collection[i] = c->collection[i - 1];
		i--;
	}
	c->collection[0] = tmp;
	if (d == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (d == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	rr(stack *a, stack *b)
{
	int	tmp;
	int	i;

	i = a->size - 1;
	tmp = a->collection[i];
	while (i > 0)
	{
		a->collection[i] = a->collection[i - 1];
		i--;
	}
	a->collection[0] = tmp;
	i = b->size - 1;
	tmp = b->collection[i];
	while (i > 0)
	{
		b->collection[i] = b->collection[i - 1];
		i--;
	}
	b->collection[0] = tmp;
	ft_putstr_fd("rr\n", 1);
}

/// rr.c

void	revr(char d, stack *c)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = c->collection[i];
	while (i < c->size - 1)
	{
		c->collection[i] = c->collection[i + 1];
		i++;
	}
	c->collection[i] = tmp;
	if (d == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (d == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	revrr(stack *a, stack *b)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = a->collection[i];
	while (i < a->size - 1)
	{
		a->collection[i] = a->collection[i + 1];
		i++;
	}
	a->collection[i] = tmp;
	i = 0;
	tmp = b->collection[i];
	while (i < b->size - 1)
	{
		b->collection[i] = b->collection[i + 1];
		i++;
	}
	b->collection[i] = tmp;
	ft_putstr_fd("rrr\n", 1);
}

///s.c

void	s(char d, stack *c)
{
	int	tmp;

	tmp = c->collection[c->size - 1];
	c->collection[c->size - 1] = c->collection[c->size - 2];
	c->collection[c->size - 2] = tmp;
	if (d == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (d == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	ss(stack *a, stack *b)
{
	int	tmp;

	tmp = a->collection[a->size - 1];
	a->collection[a->size - 1] = a->collection[a->size - 2];
	a->collection[a->size - 2] = tmp;
	tmp = b->collection[b->size - 1];
	b->collection[b->size - 1] = b->collection[b->size - 2];
	b->collection[b->size - 2] = tmp;
	ft_putstr_fd("ss\n", 1);
}
