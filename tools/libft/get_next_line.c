/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:48:35 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/17 15:16:48 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int 	fd5;

	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	fd4 = open("tests/test4.txt", O_RDONLY);
	fd5 = open("tests/test5.txt", O_RDONLY);

	i = 1;
	while (i < 2)
	{
		line = get_next_line(fd2);
		//printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	return (0);
}*/

static char	*ft_free(char *to_free)
{
	free(to_free);
	return (NULL);
}

char	*next_line(char *buf, int fd)
{
	char	*tmp;
	char	*s;
	int		i;

	tmp = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!tmp)
		return (NULL);
	i = 1;
	while (!ft_strchr(tmp, '\n') && i != 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (ft_free(tmp));
		}
		tmp[i] = 0;
		s = ft_strjoin(buf, tmp);
		free(buf);
		if (!s)
			return (ft_free(tmp));
		buf = s;
	}
	free (tmp);
	return (buf);
}

static char	*give_line(char *buf)
{
	int		i;
	char	*zs;

	i = 0;
	if (ft_strlen(buf) == 0)
		return (NULL);
	while (buf[i] != '\n' && buf[i])
		i++;
	zs = ft_calloc(i + 2, 1);
	if (!zs)
		return (0);
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		zs[i] = buf[i];
		i++;
	}
	zs[i] = buf[i];
	return (zs);
}

static char	*nl_buffer(char *buf)
{
	char	*s;
	int		j;
	int		i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
		return (ft_free(buf));
	s = ft_calloc((int)ft_strlen(buf) - i + 1, 1);
	i++;
	j = 0;
	while (buf[i])
	{
		s[j] = buf[i];
		j++;
		i++;
	}
	free (buf);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*zs;

	if (fd < 0)
		return (0);
	buf = next_line(buf, fd);
	if (!buf)
		return (NULL);
	zs = give_line(buf);
	buf = nl_buffer(buf);
	return (zs);
}
