#include "get_next_line.h"
#include <fcntl.h>

char	*clean_line(char	*str)
{
	int		i;
	char	*new_line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	new_line = ft_calloc(i + 1, 1);
    i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_line[i] = str[i];
		i++;
	}
	return (new_line);
}

char    *clean_statics(char *str)
{
    char    *new_statics;
    int     i;
    int     j;
    
    i = 0;
    j = 0;
    while (str[i] && str[i] != '\n')
		i++;
	while (str[j + i])
		j++;
	new_statics = ft_calloc(j, 1);
	j = 0;
	i++;
	while (str[i] != '\0')
    {
        new_statics[j] = str[i];
        i++;
        j++;
	}
    return (new_statics);
}


char	*read_file(int fd, char	*statics)
{
	int		read_n;
	char	*buf;

	if (!statics)
		statics = ft_calloc(0, 1);
	while (ft_strchr(statics, '\n') == 0)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, 1);
		read_n = read(fd, buf, BUFFER_SIZE);
		if (read_n == -1)
			return (0);
		else if (read_n == 0)
			break ;
		statics = ft_strjoin(statics, buf);
		free(buf);
	}
	if (*statics == '\0')
		return NULL;
    return (statics);
}

char	*get_next_line(int fd)
{
	static char		*statics[4096];
	char			*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    statics[fd] = read_file(fd, statics[fd]);
	if (!statics[fd])
		return (NULL);
    new_line = clean_line(statics[fd]);
	statics[fd] = clean_statics(statics[fd]);
    return(new_line);
}


