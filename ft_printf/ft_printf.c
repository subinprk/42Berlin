int ft_printf(const char *, )
int findPercent(const char *str)
{
    int index;

    index = 0;
    while (str[index] != 0)
    {
        if (str[index] == '%')
            if(!findAfterPercent(str, index + 1))
                return (0);
        else
            write(1, &str[index], 1);
        index ++;
    }
}
int findAfterPercent(const char *str, int index)
{
    if (str[index] == 'c')
    else if (str[index] == 's')
    else if (str[index] == 'p')
    else if (str[index] == 'd')
    else if (str[index] == 'i')
    else if (str[index] == 'u')
    else if (str[index] == 'x')
    else if (str[index] == 'X')
    else if (str[index] == '%')
        write(1, "%", 1);
    else
        return (0);
    return (1);
}