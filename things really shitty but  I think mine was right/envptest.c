#include <stdio.h>
#include <stdlib.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && (i < n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i ++;
	return (i);
}
char	*ft_strdup(const char *s)
{
	char	*str;
	int		index;

	index = 0;
	str = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[index] != 0)
	{
		str[index] = s[index];
		index ++;
	}
	str[index] = 0;
	return (str);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;
	size_t	stringl;

	stringl = ft_strlen(s);
	if (len > stringl - start)
		len = stringl - start;
	if (stringl < start)
		return (ft_strdup(""));
	index = 0;
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[index + start] != 0 && index < len)
	{
		str[index] = s[index + start];
		index ++;
	}
	str[index] = 0;
	return (str);
}

int	countrow(char const *s, char c)
{
	char	prvc;
	int		index;
	int		row;

	row = 0;
	index = 0;
	prvc = 0;
	if (s[index] != c && s[index] != 0)
		row ++;
	while (s[index])
	{
		if (prvc == c && s[index] != c)
			row ++;
		prvc = s[index];
		index ++;
	}
	if (c == 0)
		row = row - 1;
	return (row);
}

int	tool4free(char **str, int i4str)
{
	if (str[i4str] == NULL)
	{
		while (i4str >= 0)
			free(str[i4str --]);
		free(str);
		return (-1);
	}
	return (1);
}

char	**linebyline(char **str, char const *s, char c)
{
	int	index;
	int	i4str;
	int	start;

	index = 0;
	i4str = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			start = index;
			while (s[index] != c && s[index])
				index ++;
			str[i4str] = ft_substr(s, start, index - start);
			if (tool4free(str, i4str) < 0)
				return (NULL);
			i4str ++;
		}
		else
			index ++;
	}
	str[i4str] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		row;

	row = countrow(s, c);
	str = (char **)malloc((row + 1) * sizeof(char *));
	if (!str || !s)
		return (NULL);
	str = linebyline(str, s, c);
	return (str);
}

char **paths_in_oneline(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(&envp[i][ft_strlen("PATH=")], ':'));
		i ++;
	}
	return (NULL);
}

int main(int argc, char **argv, char **envp)
{
	printf("%s", paths_in_oneline(envp)[0]);
	return 0;
}
