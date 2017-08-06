#include "stdlib.h"
#include "stdio.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	printf("comp\n");
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		printf("inside while comp\n");
		printf("s1: %s	s2: %s\n", s1, s2);
		if ((s1[i] && s2[i]) && s1[i] == s2[i])
		{
			printf("inside if comp\n");
			i++;
		}
		else
		{
			printf("ret comp\n");
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}
	return (0);
}

void	ft_swap(char *s1, char *s2)
{
	char	*s3;

	printf("ft_swap\n");
	s3 = *s1;
	*s1 = *s2;
	*s2 = s3;
}

int		partition(char **s, int start, int end, int (comp)(char *, char *))
{
	int		i;
	int		pi;
	char	*pivot;

	printf("partition\n");
	i = 0;
	pi = start;
	pivot = s[end];
	while (i < (end - start))
	{
		printf("s[i] in partition %s\n", s[i]);
		printf("inside while partition\n");
		printf("i in partition: %d\n", i);
		if (comp(s[i], pivot))
		{
			printf("inside if partition\n");
			ft_swap(&s[i], &s[pi++]);
		}
		i++;
		printf("after if partition\n");
	}
	ft_swap(&s[pi], &s[end]);
	return (pi);
}

void	ft_quicksort(char **s, int start, int end, int (comp)(char *, char *))
{
	int	pi;

	printf("ft_qs\n");
	if (start >= end)
		return ;
	printf("pre pi\n");
	pi = partition(s, start, end, comp);
	printf("after pi, b4 qs1\n");
	ft_quicksort(s, start, pi - 1, comp);
	printf("after qs1, b4 qs2\n");
	ft_quicksort(s, pi - 1, end, comp);
	printf("ft_qs done\n");
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
	while (qs[i])
		printf("%s\n", qs[i++]);	printf("pre qs\n");
	ft_quicksort(qs, 0, 9, ft_strcmp);
	printf("qs kewl\n");
	i = 0;
	while (qs[i])
		printf("%s\n", qs[i++]);
	return (0);
}
