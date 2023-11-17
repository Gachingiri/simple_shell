#include "shell.h"

int _erratoi(char *s)
{
   int i = 0;
   unsigned long int result = 0;

   if (*s == '+')
      s++;
   for (i = 0;  s[i] != '\0'; i++)
   {
      if (s[i] >= '0' && s[i] <= '9')
         result = result * 10 + (s[i] - '0');
      else
         return (-1);
   }
   return (result);
}

void print_error(info_t *info, char *estr)
{
   _eputs(info->fname);
   _eputs(": ");
   print_d(info->line_count, STDERR_FILENO);
   _eputs(": ");
   _eputs(info->argv[0]);
   _eputs(": ");
   _eputs(estr);
}

int print_d(int input, int fd)
{
   int (*__putchar)(char) = _putchar;
   int i, count = 0;
   unsigned int _abs_, current;

   if (fd == STDERR_FILENO)
      __putchar = _eputchar;
   if (input < 0)
   {
      __putchar('-');
      _abs_ = -input;
      count++;
   }
   else
      _abs_ = input;

   for (i = 1; _abs_ / i > 9; i *= 10)
      ;
   for (; i > 0; i /= 10)
   {
      if (_abs_ / i)
      {
         __putchar('0' + _abs_ / i);
         count++;
      }
      _abs_ %= i;
   }
   __putchar('0' + _abs_);
   count++;

   return (count);
}

char *convert_number(long int num, int base, int flags)
{
   static char *array;
   static char buffer[50];
   char sign = 0;
   char *ptr;
   unsigned long n = num;

   if (!(flags & CONVERT_UNSIGNED) && num < 0)
   {
      n = -num;
      sign = '-';
   }
   array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
   ptr = &buffer[49];
   *ptr = '\0';

   do {
      *--ptr = array[n % base];
      n /= base;
   } while (n != 0);

   if (sign)
      *--ptr = sign;
   return (ptr);
}

void remove_comments(char *buf)
{
   int i;

   for (i = 0; buf[i] != '\0'; i++)
      if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
      {
         buf[i] = '\0';
         break;
      }
}

