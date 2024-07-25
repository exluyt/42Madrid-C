unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size == 0)
	{
		return (src_len);
	}
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
	{
		dest[i] = '\0';
	}
	return (src_len);
}


int	main()
{
	char src[] = "Hello";
	char dest[10];
	printf("%d\n", ft_strlcpy(dest, src, 3));
	printf("%s\n", strlcpy(dest, src, 3));
	return 0;
}

