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
	char	*tmp;
	int		*num;

	tmp = ft_strnew(sizeof(int) - 1);
	tmp[0] = str[3];
	tmp[1] = str[2];
	tmp[2] = str[1];
	tmp[3] = str[0];
	num = (int*)ft_memalloc(sizeof(int));
	ft_memcpy(num, tmp, sizeof(int));
	free(tmp);
	return (*num);
}