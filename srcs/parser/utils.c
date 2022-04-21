/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:31:11 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/04/17 17:35:01 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	count_sym(int fd)
{
	char	c;
	int		rs;
	int		count;

	count = 0;
	rs = read(fd, &c, 1);
	while (rs)
	{
		if (rs == -1)
			exit(put_error("Invalid file", NULL));
		rs = read(fd, &c, 1);
		count++;
	}
	close(fd);
	return (count);
}

char	*read_file(char *file_name)
{
	int		count;
	int		fd;
	int		rs;
	char	*content;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit(put_error("Invalid file", NULL));
	count = count_sym(fd);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit(put_error("Invalid file", NULL));
	content = malloc(sizeof(char) * (count + 1));
	rs = read(fd, content, count);
	content[rs] = '\0';
	return (content);
}

int	check_file_name(char *file_name)
{
	char	*tmp;

	tmp = ft_strnstr(file_name, ".rt", ft_strlen(file_name));
	while (tmp)
	{
		if (!ft_strcmp(tmp, ".rt"))
			return (0);
		tmp = ft_strnstr(tmp + 1, ".rt", ft_strlen(tmp + 1));
	}
	return (1);
}

void	init_null(t_sc *sc)
{
	sc->amb = NULL;
	sc->cam = NULL;
	sc->lig = NULL;
	sc->fig = NULL;
}

int	put_error(char *msg, char *w_case)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(msg, 2);
	if (w_case)
		ft_putstr_fd(w_case, 2);
	ft_putendl_fd("", 2);
	return (1);
}
