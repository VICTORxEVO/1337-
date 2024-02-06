
#include "get_next_line.h"

int	ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}

char *ft_joinfree(char **buffer,char **remain)
{
    char * res;
    
    res = ft_strjoin(*buffer, *remain);
    free(*buffer);
    return (res);
}

char *ft_getline(char **remain)
{
    char 		*line;
    char 		*tmp;
	size_t		i;
	size_t		j;

	i = 0;
	while (remain[0][i] != '\0' && remain[0][i] != '\n')
		i++;
	line = ft_substr(*remain,0,i);
	j = i;
	while (remain[0][i] != '\0')
		i++;
	tmp = *remain;
	*remain = ft_substr(tmp,j,i);
	free(tmp);
	if (!line || !*remain)
		return (NULL);
    return (line);
}

char *get_next_line(int fd)
{
    static char     *remain;
    char            *res;
    if (fd < 0 || read(fd,0,0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    remain = (char *)ft_readfile(fd, &remain);
    if (!remain)
        return (NULL);
    res = ft_getline(&remain);
	printf("remain = %s\n",remain);
    return (res);
}

char	*ft_readfile(int fd, char **res)
{
	char		*buffer;
	ssize_t		byteread;

	if (!*res)
		*res = ft_strdup("");
	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	byteread = 1;
	while (byteread > 0)
	{
		byteread = read(fd, buffer, BUFFER_SIZE);
		if (byteread < 0)
		{
			free(*res);
			free(buffer);
			return (NULL);
		}
		buffer[byteread] = '\0';
		*res = ft_joinfree(res, &buffer);
		if (ft_strchr(*res,'\n'))
			break;
	}
	return (*res);
}

int main()
{
	static char *remain;
    int fd = open("text.txt", O_RDONLY);
	
	char *res = get_next_line(fd);
	char *res2 = get_next_line(fd);
	char *res3 = get_next_line(fd);
	printf("RES = %s\n",res);
	printf("RES = %s\n",res2);
	printf("RES = %s\n",res3);
    free(res);
    free(res2);
    free(res3);
    close(fd);
    return (0);
}