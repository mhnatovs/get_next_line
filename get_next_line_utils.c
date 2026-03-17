/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:09:14 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/08/25 10:55:56 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len || s_len == 0)
		return (NULL);
	if (len > s_len + start)
		len = s_len + start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

// char	*ft_strdup(const char *str)
// {
// 	char	*duplicate;
// 	size_t	i;

// 	if (!str)
// 		return (NULL);
// 	duplicate = (char *)malloc(ft_strlen(str) + 1);
// 	if (!duplicate)
// 		return (NULL);
// 	i = 0;
// 	while (str[i])
// 	{
// 		duplicate[i] = str[i];
// 		i++;
// 	}
// 	duplicate[i] = '\0';
// 	return (duplicate);
// }

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	char	*dest;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
// 	if (!dest)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 		dest[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		dest[j++] = s2[i++];
// 	dest[j] = '\0';
// 	return (dest);
// }