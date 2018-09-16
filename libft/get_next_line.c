/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:05:48 by vordynsk          #+#    #+#             */
/*   Updated: 2018/01/09 12:05:50 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

static t_list	*ft_check_add(t_list **list, size_t fd)
{
	t_list	*buff_list;
	t_list	*new;

	if (*list == NULL)
	{
		*list = ft_lstnew(NULL, BUFF_SIZE);
		(*list)->content_size = fd;
		return (*list);
	}
	buff_list = *list;
	while (buff_list != NULL)
	{
		if (buff_list->content_size == fd)
			return (buff_list);
		buff_list = buff_list->next;
	}
	new = ft_lstnew(NULL, BUFF_SIZE);
	new->content_size = fd;
	ft_lstadd(list, new);
	return (new);
}

void			ft_cut_and_paste(t_list *list, char **line)
{
	int		a;
	char	*buff2;

	a = 0;
	buff2 = list->content;
	if (buff2 != NULL && ft_strchr(buff2, '\n') != NULL)
		a = ft_strchr(buff2, '\n') - buff2;
	else if (buff2 != NULL)
		a = (int)ft_strlen(list->content);
	*line = ft_strsub(buff2, 0, a);
	if (buff2[a] == '\n')
		a++;
	ft_memmove(list->content, list->content + a,
	ft_strlen(list->content + a) + 1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*rd;
	t_list			*buff_lst;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || read(fd, NULL, 0) < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	buff_lst = ft_check_add(&rd, fd);
	ft_bzero(buff, BUFF_SIZE + 1);
	*line = NULL;
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		buff_lst->content = ft_realloc(buff_lst->content, BUFF_SIZE);
		buff_lst->content = ft_strcat(buff_lst->content, buff);
		if (ft_strchr(buff, '\n') != NULL)
			break ;
		ft_bzero(buff, BUFF_SIZE);
	}
	if (buff_lst->content && ft_strlen(buff_lst->content) > 0)
		ft_cut_and_paste(buff_lst, line);
	else if (!buff_lst->content || ft_strlen(buff_lst->content) == 0)
		return (0);
	return (1);
}
