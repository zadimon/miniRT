/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:42:24 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/15 18:22:29 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static size_t	ft_getsize(char const *s)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (s[0] != ' ' && s[0] != '\t' && s[0] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (i != 0 && s[i] != ' ' && s[i] != '\t'
			&& (s[i - 1] == ' ' || s[i - 1] == '\t'))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **str, size_t k)
{
	size_t	i;

	i = 0;
	while (i <= k)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	check_s(char const *s, char ***str, size_t *t)
{
	if (!(s))
		return (1);
	*t = ft_getsize(s);
	*str = malloc(sizeof(char **) * (*t + 1));
	if (!(str))
		return (1);
	return (0);
}

char	**ft_mod_split(char const *s)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	t;

	if (check_s(s, &str, &t))
		return (NULL);
	i = 0;
	k = 0;
	while (k < t)
	{
		while ((s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
			i++;
		j = i;
		while (s[j] != ' ' && s[j] != '\t' && s[j] != '\0')
			j++;
		str[k] = ft_substr(s, i, j - i);
		if (!(str[k]))
			return (ft_free(str, k));
		i = j;
		k++;
	}
	str[k] = 0;
	return (str);
}
