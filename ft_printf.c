#include <stdarg.h>
#include <unistd.h>

static int    ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int    ft_putstr(char *c)
{
  int i = 0;
	while (c[i] != '\0')
	{
	  (write(1, &c[i], 1));
	  i++;
	}
}

int    ft_printf(const char *format, ...)
{
  va_list    args;
  
  va_start(args, format);
  
  while (*format)
  {
	if (*format == '%')
	{
	  format++;
	  if (*format == 'c')
		ft_putchar(va_arg(args, int));
	  else if (*format == 's')
		ft_putstr(va_arg(args, char *));
	  else if (*format == '%')
		ft_putchar('%');
	  else
	  {
		ft_putchar('%');
		format--;
	  }
	}
	else
	  ft_putchar(*format);
	format++;
  }
  va_end(args);
}

int main() {
  ft_printf("Ola %Mundo %s com %s,%% %c",",tudo bem?","voce",'s');
  return 0;
}