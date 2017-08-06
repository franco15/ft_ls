#include "stdlib.h"
#include "stdio.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

void	ft_swap(char **s1, char **s2)
{
	char	*s3;

	s3 = *s1;
	*s1 = *s2;
	*s2 = s3;
}

int		partition(char **s, int start, int end, int (comp)(char *, char *))
{
	int		i;
	int		pi;
	char	*pivot;

	i = 0;
	pi = start;
	pivot = s[(start + end) / 2];
	while (i < (end - start))
	{
		if (comp(s[i], pivot))
			ft_swap(&s[i], &s[pi++]);
		i++;
	}
	ft_swap(&s[pi], &s[end]);
	return (pi);
}

void	ft_quicksort(char **s, int start, int end, int (comp)(char *, char *))
{
	int	pi;

	if (start >= end)
		return ;
	pi = partition(s, start, end, comp);
	ft_quicksort(s, start, pi - 1, comp);
	ft_quicksort(s, pi + 1, end, comp);
}

int main(int ac, char **av)
{
	char	**qs;
	int		i;

	i = 0;
	qs = (char**)malloc(sizeof(char*) * 5 + 1);
	qs[5] = 0;
	qs[0] = av[1];
	qs[1] = av[2];
	qs[2] = av[3];
	qs[3] = av[4];
	qs[4] = av[5];
	ft_quicksort(qs, 0, 4, ft_strcmp);
	i = 0;
	while (qs[i])
		printf("%s\n", qs[i++]);
	return (0);
}
