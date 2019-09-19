/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:46:07 by ilian             #+#    #+#             */
/*   Updated: 2019/09/13 13:46:09 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_byte_code   *read_file(char *path)
{
    t_byte_code	*bytes;
    int			fd;
	char		buf[BUFF_SIZE];
	int			ret;
	char		*tmp;

	bytes = (t_byte_code*)ft_memalloc(sizeof(t_byte_code));
	*bytes = (t_byte_code){0, ft_strnew(MAX_FILE_LENGTH)};
	tmp = bytes->code;
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		free(bytes);
		ft_printf("Doesn't open!\n");
		return (NULL);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_memcpy(tmp, buf, ret);
		bytes->length += ret;
		tmp += ret;
	}
	if (ret == -1)
	{
		free(bytes);
		return (NULL);
	}
	close(fd);
    return (bytes);
}

// t_champ *get_i(t_champ *champ, int i)
// {
//     int j;

//     j = 0;
//     while (champ)
//     {
//         if (j == i)
//             return (champ);
//         j++;
//         champ = champ->next_champ;
//     }
//     return (NULL);
// }

// t_champ *set_champ_to_pos(t_champ *champ, int from, int to)
// {
//     t_champ *prev_fr;
//     t_champ *t_from;
//     t_champ *prev_to;
//     t_champ *t_to;
//     t_champ *tmp;

//     prev_fr = get_i(champ, from - 1);
//     t_from = get_i(champ, from);
//     prev_to = get_i(champ, to - 1);
//     t_to = get_i(champ, from);
//     tmp = t_from;
//     t_from->next_champ = t_to->next_champ;
//     t_to->next_champ = tmp->next_champ;
//     if (prev_fr)
//         prev_fr->next_champ = t_to;
//     if (prev_to)
//         prev_to->next_champ = t_from;
//     if (!prev_fr)
//         return (t_to);
//     if (!prev_to)
//         return (t_from);
//     return (champ);
// }

// t_champ *sort_champs(t_champ *champ, int argc, char **argv)
// {
//     int i;
//     int pos;
//     int curr;
    
//     i = 0;
//     curr = -1;
//     while (++i < argc)
//     {
//         if (ft_strlen(argv[i]) >= 4 && ft_strequ(argv[i] + (ft_strlen(argv[i]) - 4), ".cor"))
//             curr++;
//         if (ft_strequ(argv[i], "-n") && i < argc - 3)
//         {
//             pos = ft_atoi(argv[i + 1]);
//             if (pos > 0 && ft_strlen(argv[i + 2]) >= 4 && ft_strequ(argv[i + 2] + (ft_strlen(argv[i + 2]) - 4), ".cor"))
//                 champ = set_champ_to_pos(champ, curr + 1, pos);
//         }
//     }
//     return (champ);
// }

t_champ	*get_champs(int argc, char **argv)
{
    t_champ *champ;
    t_champ *tmp;
    int i;

    i = 0;
    champ = NULL;
    while (++i < argc)
    {
        if (ft_strlen(argv[i]) >= 4 && ft_strequ(argv[i] + (ft_strlen(argv[i]) - 4), ".cor"))
        {
			ft_printf("%s\n", argv[i]);
            if (champ)
            {
                tmp->next_champ = create_champ(read_file(argv[i]), i);
				if (tmp->next_champ)
                	tmp = tmp->next_champ;
            }
            else
            {
                tmp = create_champ(read_file(argv[i]), i);
                champ = tmp;
            }
        }
    }
    // champ = sort_champs(champ, argc, argv);
    return (champ);
}
