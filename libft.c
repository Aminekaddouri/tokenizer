/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaddouri <kaddouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:42 by kaddouri          #+#    #+#             */
/*   Updated: 2024/04/28 03:13:52 by kaddouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (!slen || start > slen - 1)
		return (ft_strdup(""));
	i = 0;
	while (s[start + i] && i + 1 <= len)
		i++;
	substr = ft_calloc((i + 1), sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s1cpy;
	size_t	s1len;

	s1len = ft_strlen(s1);
	s1cpy = ft_calloc(s1len + 1, sizeof(char));
	if (!s1cpy)
		return (NULL);
	return (ft_memcpy(s1cpy, s1, s1len));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	tmp = malloc(size * count);
	if (!tmp)
		return (NULL);
	return (ft_memset(tmp, 0, size * count));
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while ((dst + i || src + i) && i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (!(char)c)
		return ((char *)(s + i));
	else
		return (NULL);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s)
			ft_putchar_fd(*s++, fd);
}


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n)
	{
		while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
			i++;
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
/**
Pay attention that the comparison is done using unsigned char
It doesn't really matter when checking for equality
because it is going to be the same either way.
But make sure to convert to unsigned char in the difference.
*/