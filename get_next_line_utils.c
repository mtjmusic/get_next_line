/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:14:06 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/25 20:19:26 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*out;
	char	*in;
	size_t	size_dest;
	size_t	size_src;

	out = dst;
	in = (char *)src;
	size_dest = ft_strlen((char *)dst);
	size_src = ft_strlen((char *)src);
	if (size_dest >= size)
		return (size + size_src);
	while (*out)
		out++;
	while (*in && size_dest + 1 < size)
	{
		*out++ = *in++;
		size--;
	}
	*out = '\0';
	return (size_dest + size_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	out_len;
	size_t	s1_len;
	size_t	s2_len;
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	out_len = s1_len + s2_len;
	out = (char *)malloc((out_len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_bzero(out, out_len + 1);
	ft_strlcat(out, s1, s1_len + 1);
	ft_strlcat(out + s1_len, s2, s2_len + 1);
	return (out);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	size_src;
	char	*out;
	char	*in;

	size_src = ft_strlen((char *)src);
	out = dst;
	in = (char *)src;
	if (size > 0)
	{
		while (*in && size-- > 1)
			*out++ = *in++;
		*out = '\0';
	}
	return (size_src);
}

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	len;

	len = ft_strlen((char *)s1);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1, len + 1);
	return (out);
}
