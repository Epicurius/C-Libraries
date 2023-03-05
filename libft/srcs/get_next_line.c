/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 25/03/2023 Niklas Neronin
 */

#include "libft.h"

static char	*ft_strcut(char *str, int start, int end)
{
	char	*new;
	int		i;

	if (!str)
		return NULL;
	if (end <= 0)
		end = ft_strlen(str);
	new = malloc(end - start + 1);
	if (!new)
		return NULL;
	i = start;
	while (i < end) {
		new[i - start] = str[i];
		i++;
	}
	new[i - start] = '\0';
	free(str);
	return new;
}

static char	*ft_strjoinf(char *s1, const char *s2)
{
	char	*str;

	if (!s1)
		return 0;
	if (!s2) {
		ft_memdel((void *)&s1);
		return 0;
	}
	str = ft_strnew((ft_strlen(s1) + ft_strlen(s2)));
	if (!str) {
		ft_memdel((void *)&s1);
		return 0;
	}
	if (!(ft_strcpy(str, s1)))
		return 0;
	if (!(ft_strcat(str, s2)))
		return 0;
	ft_memdel((void *)&s1);
	return str;
}

static int	contains_zero(char *buf, int size)
{
	int	i;

	i = 0;
	while (i < size) {
		if (buf[i] == 0)
			return 1;
		i++;
	}
	return 0;
}

static int	string_edit(char **file, const int fd, char **line, int char_nbr)
{
	int		i;

	if (char_nbr == 0 && file[fd][0] == '\0') {
		ft_memdel((void *)&file[fd]);
		return 0;
	}
	i = ft_strchri(file[fd], '\n');
	if (i || file[fd][0] == '\n') {
		*line = ft_strsub(file[fd], 0, i);
		file[fd] = ft_strcut(file[fd], i + 1, 0);
		return 1;
	}
	i = ft_strchri(file[fd], '\0');
	if (i) {
		*line = ft_strdup(file[fd]);
		file[fd][0] = '\0';
	}
	return 1;
}

/*
 * Returns a line read from file descriptor 'fd'.
 */
int	get_next_line(const int fd, char **line)
{
	static char		*file[GNL_FILE_NB];
	char			read_buffer[GNL_BUFF_SIZE + 1];
	int				char_nbr;

	if (fd < 0 || !line || GNL_BUFF_SIZE < 1 || read(fd, read_buffer, 0) < 0)
		return -1;
	if (file[fd] == 0)
		file[fd] = ft_strnew(0);
	while (!ft_strchr(file[fd], '\n')) {
		char_nbr = read(fd, read_buffer, GNL_BUFF_SIZE);
		if (char_nbr < 0)
			return -1;
		if (!char_nbr || contains_zero(read_buffer, char_nbr))
			break ;
		read_buffer[char_nbr] = '\0';
		file[fd] = ft_strjoinf(file[fd], read_buffer);
	}
	return (string_edit(file, fd, line, char_nbr));
}
