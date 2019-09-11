/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:00:41 by dlian             #+#    #+#             */
/*   Updated: 2018/12/01 21:02:56 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_line(char *s1, char *s2)
{
	char		*str;

	if (!s1)
	{
		str = ft_strdup(s2);
		return (str);
	}
	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

t_list	*find_fd(const int fd, t_list **list)
{
	t_list			*new;
	t_list			*tmp;

	tmp = *list;
	if (!*list)
	{
		*list = ft_lstnew(NULL, 0);
		(*list)->content_size = fd;
		return (*list);
	}
	while (tmp)
	{
		if ((int)(tmp->content_size) == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new = ft_lstnew(NULL, 0);
	new->content_size = fd;
	ft_lstadd(list, new);
	return (new);
}

char	*get_line(char *content, char **line)
{
	char			*tmp;
	char			*founded;

	if (content == NULL || !ft_strlen(content))
	{
		if (content)
			free(content);
		return (NULL);
	}
	if ((founded = ft_strchr(content, '\n')))
	{
		tmp = ft_strsub(content, 0, ft_strlen(content) - ft_strlen(founded));
		*line = create_line(*line, tmp);
		free(tmp);
		tmp = ft_strsub(content, ft_strlen(content) -
			ft_strlen(founded) + 1, ft_strlen(content));
		free(content);
		content = tmp;
		return (content);
	}
	*line = create_line(*line, content);
	free(content);
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*curr;
	char			str_buf[BUFF_SIZE + 1];
	int				readed;
	char			*founded;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	curr = find_fd(fd, &list);
	while ((readed = read(fd, str_buf, BUFF_SIZE)) > 0)
	{
		str_buf[readed] = '\0';
		curr->content = create_line(curr->content, str_buf);
		if ((founded = ft_strchr(str_buf, '\n')))
			break ;
	}
	if (readed < 0)
		return (-1);
	curr->content = get_line(curr->content, line);
	if (!*line)
		return (0);
	return (1);
}
