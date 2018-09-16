/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:52:24 by vordynsk          #+#    #+#             */
/*   Updated: 2017/11/01 17:41:29 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	int		ft_now(char const *s, char c)
{
	int		i;
	int		l;
	int		n;

	l = 0;
	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			l = 0;
		if (s[i] != c && l == 0)
		{
			n++;
			l = 1;
		}
		i++;
	}
	return (n);
}

static	int		*ft_wordindex(char const *s, int n, char c)
{
	int		*index;
	int		i;
	int		l;
	int		j;

	i = 0;
	l = 0;
	j = 0;
	if (!(index = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			l = 0;
		if (s[i] != c && l == 0)
		{
			index[j] = i;
			j++;
			l = 1;
		}
		i++;
	}
	return (index);
}

static	char	*ft_word(char const *s, int start, char c)
{
	int		i;
	int		end;
	char	*word;

	i = start;
	while (s[i] != c && s[i] != '\0')
		i++;
	end = i - start;
	if (!(word = (char *)malloc(sizeof(char) * (end + 1))))
		return (NULL);
	word[end] = '\0';
	i = 0;
	while (i < end)
		word[i++] = s[start++];
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		n;
	int		*index;

	if (s == NULL)
		return (NULL);
	n = ft_now(s, c);
	index = ft_wordindex(s, n, c);
	if (!(res = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	res[n] = NULL;
	i = 0;
	while (i < n)
	{
		res[i] = ft_word(s, index[i], c);
		if (res[i] == NULL)
		{
			ft_memkill(res, i);
			return (NULL);
		}
		i++;
	}
	free(index);
	return (res);
}
