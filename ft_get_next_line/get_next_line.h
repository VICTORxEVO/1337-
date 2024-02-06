
#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE 

//tobe removed
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <stddef.h>
#include <limits.h>

#define BUFFER_SIZE 12

char    *get_next_line(int fd);
char    *ft_getline(char **remain);
char    *ft_strjoin(char *s1,char *s2);
size_t  ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, size_t start, size_t len);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char    *ft_joinfree(char **buffer,char **remain);
int     ft_strchr(char *s, int c);
char	*ft_readfile(int fd, char **res);



#endif