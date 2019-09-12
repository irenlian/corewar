#include "../../includes/corewar.h"

int get_quantity_players(t_champ *champ)
{
    int i;
    int size;

    i = 0;
    size = 0;
    while (champ)
    {
        champ = champ->next_champ;
        size++;
    }
    return (size);
}

void	*ft_memrev(const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)ft_memalloc(n);
	s2 = (char *)src;
	while (n)
	{
		s1[i] = s2[n];
		i++;
		n--;
	}
	return (s1);
}

int	byte_to_int(char *str)
{
	char	*sub;
	char	*tmp;
	int		*num;
	int t = sizeof(int);

	sub = ft_strnew(sizeof(int));
	ft_memcpy(sub, str, sizeof(int));
	tmp = ft_memrev(sub, sizeof(int));
	free(sub);
	num = (int*)ft_memalloc(sizeof(int));
	ft_memcpy(num, tmp, sizeof(int));
	free(tmp);
	return (*num);
}