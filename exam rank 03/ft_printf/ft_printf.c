#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_strchr(const char *s, int c)
{
	unsigned int i = 0;
	unsigned char *str;
	str = (unsigned char *)s;
	while (str[i] != '\0' && str[i] != (unsigned char)c)
		i++;
	if (str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	return (0);
}

void	ft_putchar(int c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(const char *s, int *len)
{
	int i = 0;
	if (!s)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], len);
		i++;
	}
}

void ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", len);
	else if (n < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(-n, len);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, len);
		ft_putchar(n % 10 + '0', len);
	}
	else
		ft_putchar(n % 10 + '0', len);
}

void	ft_puthex(unsigned int n, int *len)
{
	char *str = "0123456789abcdef";
	if (n < 16)
		ft_putchar(str[n], len);
	else
	{
		ft_puthex(n /16, len);
		ft_puthex(n % 16, len);
	}
}

void	check_flag(int c, va_list args, int *len)
{
	if (c == 'd')
		ft_putnbr(va_arg(args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), len);
	else
		*len = -1;
}

int ft_printf(const char *str, ...)
{
	int i = 0;
	va_list args;
	int len = 0;

	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("dsx", str[i + 1]))
		{
			check_flag(str[i + 1], args, &len);
			if (len == -1)
				return -1;
			i++;
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	return (len);
}

int main()
{
	ft_printf("%d\n", 1337);
	ft_printf("%s\n", "hello");
	ft_printf("%x\n", 1337);
	ft_printf("hello again\n");
}
