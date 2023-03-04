/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:45:53 by lmontes-          #+#    #+#             */
/*   Updated: 2023/02/16 16:44:14 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	unsigned char	*a;
	size_t			len;

	len = size * count;
	p = (void *)malloc(len);
	if (!p)
		return (NULL);
	a = p;
	while (len > 0)
	{
		*a = 0;
		a++;
		len--;
	}
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{	
	char	*join;
	size_t	l1;
	size_t	l2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	join = malloc(sizeof(char) * (l1 + l2 +1));
	if (!join)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		join[i] = s1[i];
		i++;
	}	
	i = 0;
	while (i < l2)
		join[l1++] = s2[i++];
	join[l1++] = '\0';
	return (join);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;

	if (!dst && !src)
		return (dst);
	d = dst;
	while (n > 0)
	{
		*d = *(char *)src;
		d++;
		src++;
		n--;
	}
	return (dst);
}
