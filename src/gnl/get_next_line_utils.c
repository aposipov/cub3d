/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:26:38 by lchristi          #+#    #+#             */
/*   Updated: 2021/11/22 17:26:50 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *str1, char *str2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	str = malloc(sizeof(char) * (gnl_strlen(str1) + gnl_strlen(str2) + 1));
	if (!str)
		return (NULL);
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		str[i + j] = str2[j];
		j++;
	}
	str[i + j] = '\0';
	free(str1);
	return (str);
}

char	*gnl_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i != 0)
		if (s[i--] == (char)c)
			return ((char *)s);
	return (NULL);
}
