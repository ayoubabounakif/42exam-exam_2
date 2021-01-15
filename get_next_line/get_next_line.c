/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:21:08 by aabounak          #+#    #+#             */
/*   Updated: 2021/01/15 11:21:09 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		i = 0;
	
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char c)
{
	char	*str;
	int		i;

	i = ft_strlen(line);
	if (!(str = (char *)malloc(i + 2)))
		return (0);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

int		get_next_line(char **line)
{
	char	*buffer;
	int		n;

	buffer = (char *)malloc(2);
	if (!line || !buffer || !(*line = (char *)malloc(1)))
		return (-1);
	*line[0] = '\0';
	while ((n = read(0, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
			break ;
		*line = ft_strjoin(*line, buffer[0]);
	}
	free(buffer);
	return (n);
}
