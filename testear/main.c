/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:44:33 by lmontes-          #+#    #+#             */
/*   Updated: 2023/02/17 10:58:23 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		n;
	char	*t;
	int	lines = 2;

	if (argc == 1)
		fd = open("text_gnl.txt", O_RDONLY);
	else
		fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		write(1, "No file opened\n", 15);
		return (0);
	}
	n = 0;
	while (n < lines)
	{
		t = get_next_line(fd);
		printf("### Línea #%d ###\n%s\n######\n", n + 1, t);
		free(t);
		n++;
	}
	system("leaks gnl.out");
}
