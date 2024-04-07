#include "push_swap.h"
#include <stdio.h>
stack *create_stack(int capacity)
{
	if (capacity <= 0)
		return(NULL);
	stack *stack = malloc(sizeof(*stack));
	if (stack == NULL)
		return (NULL);
	stack->collection  = malloc(sizeof(int) * capacity);
	if (stack->collection == NULL)
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->size = 0;
	return (stack);
}
int mincher(stack *c)
{
	int min;
	int i;
	i = 1;
	min = 0;
	while (i < c->size)
	{
		if(c->collection[min] > c->collection[i])
			min = i;
		i++;
	}
	return(min);
}
int maxcher(stack *c)
{
	int max;
	int i;
	i = 0;
	max = 0;
	while (i < c->size)
	{
		if(c->collection[max] < c->collection[i])
			max = i;
		i++;
	}
	return(max);
}
void sort_three(stack *a)
{
	int max;
	max = maxcher(a);
	if(max == a->size - 1)
		r('a', a);
	else if(max == a->size - 2)
		revr('a', a);
	if(a->collection[a->size - 1] > a->collection[a->size - 2])
		s('a', a);
}
void sort_five(stack *a, stack *b)
{
	int min;
	while (a->size > 3)
	{
		min = mincher(a); 
		while (a->size / 2  <= min && min < a->size - 1)
		{
			r('a', a);
			min = mincher(a);
		}
		while (min == 1 || min == 0)
		{
			revr('a', a);
			min = mincher(a);
		}
		pb(b, a);
	}
	sort_three(a);
	while(b->size != 0)
		pa(a, b);
}
void creat_array(stack *a, int *tmp)
{
	int i;
	int j;
	int imax;
	i = 0;	
	while (i < a->size)
	{
		tmp[i] = a->collection[i];
		i++;
	}
	i = 0;
	while (i < a->size - 1)
	{
		j = 0;
		while(j < a->size - i - 1)
		{
			if(tmp[j] > tmp[j + 1])
			{
				imax = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = imax;
			}
			j++;
		}
		i++;
	}
}

void sort(stack *a, stack *b)
{
	int tmp[a->size];
	int mid;
	int offset;
	int start;
	int end;
	int i;
	int j;
	int k;
	int f;
	int l;
	////////////
	creat_array(a, tmp);
	mid = a->size / 2 - 1;
	offset = a->size / 8;
	start = mid - offset;
	end = mid + offset;
	/////////////
	i = a->size - 1;
	while(i >= 0 && a->size > 0)
	{
		j = start - 1;
		while(j <= end)
		{
			j++;
			if (tmp[j] == a->collection[i])
			{
				if(i < a->size / 2)
				{
					while(i >= 0)
					{
						revr('a', a);
						i--;	
					}
					if(is_empty(b))
						pb(b, a);
					else if(tmp[j] >= tmp[mid])
						pb(b, a);
					else
					{
						pb(b, a);
						r('b', b);
				
					}
				}
				else
				{
					while(i < a->size - 1)
					{
						r('a', a);
						i++;	
					}
					if(is_empty(b))
						pb(b, a);
					else if(tmp[j] >= tmp[mid])
						pb(b, a);
					else
					{
						pb(b, a);
						r('b', b);
					}
				}
				j = end + 1;
			}
		}
		i--;;
		if(i < 0)
		{
			start -= offset;
			if(start <= 0)
				start = 0;
			end += offset;
			if(end <= a->size - 1)
				end = a->size - 1;
			i = a->size - 1;
		}
	}
	
	i = b->size - 1;
	
	l = b->size - 1;
	while (i >= 0) 
	{
		j = a->size - 1;
		if(b->collection[b->size - 1] == tmp[i])
		{
			pa(a, b);
		}
		else
		{
			f = -1;
			while(j >= 0)
			{
				if(a->collection[j] == tmp[i])
				{
					f = j;
					j = 0;
				}
				j--;
			}
			if(f >= 0)
			{
        while(f >= 0)
				{
					revr('a', a);
					f--;
				}
			}
			else
			{
				k = b->size - 1;
				while(k >= 0)
				{
					if(b->collection[k] == tmp[i])
					{
						f = k;
						k = 0;
					}
					k--;
				}
				while(f < b->size - 1)
				{
					if(is_empty(a))
					{
						if(f >= (b->size / 2))
						{
							r('b', b);
							f++;
						}
						else
						{
							while(f >= 0)
							{
								revr('b', b);
								f--;
							}
							f = b->size - 1;
						}
					}
					else if (a->collection[0] != tmp[l] && \
					a->collection[0] > b->collection[b->size - 1])
					{
						if(f >= (b->size / 2))
						{
							r('b', b);
							f++;
						}
						else
						{
							while(f >= 0)
							{
								revr('b', b);
								f--;
							}
							f = b->size - 1;
						}
					}
					else if (a->collection[0] == tmp[l] ||\
					a->collection[0] < b->collection[b->size - 1]) 
	    				{
	        				pa(a, b);
	        				r('a', a);
	    				}
				}
				pa(a, b);
			}
		}
	    	i--;
	}
}
int main(int argc, char **argv)
{
	stack *a;
	stack *b;
	int i;
	char *av;
	int j;
	i = 1;
	a = NULL;
	b = NULL;
	av = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	
	i = 1;
	while (i <= argc - 1)
	{
		av = ft_strjoin(av, " ");
		av = ft_strjoin(av, argv[i++]);
	}
	i = 0;
	argv = ft_split(av, ' ');
	while (argv[i])
		i++;
	argc = i;
	if(argc == 1)
		return (1);
	if (argc >= 2)
	{
		while (i > 0)
		{
			i--;
			j = 0;
			while (argv[i][j] != '\0')
			{
				if(argv[i][0] == '\0' || !ft_isdigit(argv[i][j]))
					return (1);
				j++;
			}
		}
	}
	a = create_stack(argc);
	b = create_stack(argc);
	if (!a)
		return(1);
	i = argc - 1;
	while (i >= 0)
		push(a,ft_atoi(argv[i--]));
	
	if (a->size == 3 || a->size == 2)
		sort_three(a);
	if (a->size == 5 || a->size == 4)
		sort_five(a, b);
	if (a->size > 5)
		sort(a, b);
}
