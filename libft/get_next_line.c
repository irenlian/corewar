/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:10:12 by pdemian           #+#    #+#             */
/*   Updated: 2019/02/05 19:13:00 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static t_list		*giveme_my_list(const int fd, t_list **main)
{
	t_list	*list;

	list = *main;
	while (list)
	{
		if ((int)list->content_size == fd)
			return (list);
		list = list->next;
	}
	list = ft_lstnew("\0", fd);
	ft_lstadd(main, list);
	return (list);
}

static int			make_it_for_me(char **line, char *list_content)
{
	int		i;
	int		j;
	char	*rabbit;

	i = 0;
	j = 0;
	rabbit = *line;
	while (list_content[i] && list_content[i] != '\n')
		i++;
	if (!(rabbit = ft_strnew(i)))
		return (0);
	while (list_content[j] && j < i)
	{
		rabbit[j] = list_content[j];
		j++;
	}
	if (!(*line = rabbit))
		return (0);
	return (i);
}

static int			read_this_ducking_file(const int fd, char **tmp)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*str;

	if ((read(fd, buff, 0) < 0))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		str = *tmp;
		*tmp = ft_strjoin(str, buff);
		free(str);
		if (ft_strchr(buff, '\n'))
			return (ret);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	static	t_list	*please;
	t_list			*work;
	char			*tmp;

	if (line == NULL || fd < 0 || fd > OPEN_MAX)
		return (-1);
	work = giveme_my_list(fd, &please);
	tmp = work->content;
	if ((ret = read_this_ducking_file(fd, &tmp)) < 0)
		return (-1);
	if (!ft_strlen(tmp))
		return (0);
	ret = make_it_for_me(line, tmp);
	work->content = tmp;
	if (tmp[ret])
	{
		work->content = ft_strdup(ft_strchr(tmp, '\n'));
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
}
