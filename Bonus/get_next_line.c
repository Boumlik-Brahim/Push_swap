/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:46:57 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/30 21:53:10 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_join(char *s1, char *s2)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = 0;
	}
	len = ft_len(s1) + ft_len(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

static char	*ft_sub_red_line(int n, int fd, char *buff, char *line)
{
	while (1)
	{
		n = read(fd, buff, 1);
		if (n == -1)
		{
			free(buff);
			free(line);
			return (NULL);
		}
		if (n == 0)
		{
			free(buff);
			return (line);
		}
		buff[1] = 0;
		if (buff[0] == '\n')
		{
			line = ft_join(line, buff);
			free(buff);
			return (line);
		}
		line = ft_join(line, buff);
	}
}

char	*ft_red_line(int fd)
{
	char	*buff;
	char	*line;
	int		n;

	n = 0;
	buff = (char *)malloc(sizeof(char) + 2);
	if (!buff)
		return (NULL);
	line = NULL;
	line = ft_sub_red_line(n, fd, buff, line);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*res;

	res = NULL;
	if (fd < 0)
		return (NULL);
	res = ft_red_line(fd);
	return (res);
}
