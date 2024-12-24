#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"

void	test(void);
void	test_str(void);
void	test_unsigned(void);
void	test_hex(void);
void	check_diff(int r1, int r2);
void	test2(void);

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		test();
		test_str();
		test_unsigned();
		test_hex();
		test2();
		return (0);
	}
	else if (argc == 2)
	{
		printf("original : [%s]\n", argv[1]);
		ft_printf("    self : [%s]\n", argv[1]);
	}
	else if (argc == 3)
	{
		printf(argv[1], argv[2]);
		ft_printf(argv[1], argv[2]);
	}
	else if (argc == 4)
	{
		printf(argv[1], argv[2], argv[3]);
		ft_printf(argv[1], argv[2], argv[3]);
	}
	else if (argc == 5)
	{
		printf(argv[1], argv[2], argv[3], argv[4]);
		ft_printf(argv[1], argv[2], argv[3], argv[4]);
	}
	else if (argc == 6)
	{
		printf(argv[1], argv[2], argv[3], argv[4], argv[5]);
		ft_printf(argv[1], argv[2], argv[3], argv[4], argv[5]);
	}
	return (0);
}

static int	a[] = {-87, 64, 8245, -2147483648, 0, 5581, 2147483647, -913762};

void	test(void)
{
	int	r1;
	int	r2;

	r1 = printf(NULL);
	r2 = ft_printf(NULL);
	check_diff(r1, r2);

	r1 = printf("qwerty\t['%c', '%d', '%d']\n", '*', 'A', 42);
	r2 = ft_printf("qwerty\t['%c', '%d', '%d']\n", '*', 'A', 42);
	check_diff(r1, r2);

	r1 = printf("%s\n", "Hello World !");
	r2 = ft_printf("%s\n", "Hello World !");
	check_diff(r1, r2);

	for (int i = 0; i < 8; i++)
		printf("[i=%i | u=%u] ", a[i], a[i]);
	printf("\n");
	for (int i = 0; i < 8; i++)
		ft_printf("[i=%i | u=%u] ", a[i], a[i]);
	ft_printf("\n");

	r1 = printf("the value of the pointer : %p\n", a);
	r2 = ft_printf("the value of the pointer : %p\n", a);
	check_diff(r1, r2);

	for (int i = 0; i < 8; i++)
		printf("[%x : %X] ", a[i], a[i]);
	printf("\n");
	for (int i = 0; i < 8; i++)
		ft_printf("[%x : %X] ", a[i], a[i]);
	ft_printf("\n");

	for (int i = 0; i < 8; i++)
		printf("[%p] ", a + i);
	printf("\n");
	for (int i = 0; i < 8; i++)
		ft_printf("[%p] ", a + i);
	ft_printf("\n");

	r1 = printf(" > %p %p\n", 0, 0);
	r2 = ft_printf(" < %p %p\n", 0, 0);
	check_diff(r1, r2);

	r1 = printf("Lorem%%%% ipsum do%%lor sit am\bet, consec\ttetur a\ndipiscing\
		   	elit. Vivamu\bs non ri\\sus tortor.\n");
	r2 = ft_printf("Lorem%%%% ipsum do%%lor sit am\bet, consec\ttetur a\ndipiscing\
		   	elit. Vivamu\bs non ri\\sus tortor.\n");
	check_diff(r1, r2);

	for (int i = 0; i < 255; i++)
		printf("%c", i);
	printf("\n------------------------------------------\n");
	for (int i = 0; i < 255; i++)
		ft_printf("%c", i);
	ft_printf("\n------------------------------------------\n");

	//r1 = printf("test %t %h %w\n");
	//r2 = ft_printf("test %t %h %w\n");
	//check_diff(r1, r2);

	for (int i = 0; i < 8; i++)
	{
		r1 = printf(" %+d | %0d | %-d | %#x \n", a[i], a[i], a[i], a[i]);
		r2 = ft_printf(" %+d | %0d | %-d | %#x \n", a[i], a[i], a[i], a[i]);
		check_diff(r1, r2);
	}
	ft_printf("\n");

	r1 = printf("width :%5d#\n", 4242);
	r2 = ft_printf("width :%5d#\n", 4242);
	check_diff(r1, r2);
	r1 = printf("width :%05d#\n", 4242);
	r2 = ft_printf("width :%05d#\n", 4242);
	check_diff(r1, r2);

	ft_printf("\n------------------------------------------\n");

	r1 = printf("width :%20d#\n", -2147483642);
	r2 = ft_printf("width :%20d#\n", -2147483642);
	check_diff(r1, r2);
	r1 = printf("width :%020d#\n", -2147483642);
	r2 = ft_printf("width :%020d#\n", -2147483642);
	check_diff(r1, r2);

	ft_printf("\n------------------------------------------\n");

	r1 = printf("width :% d#\n", 4242);
	r2 = ft_printf("width :% d#\n", 4242);
	check_diff(r1, r2);
	r1 = printf("width :% d#\n", -2147483642);
	r2 = ft_printf("width :% d#\n", -2147483642);
	check_diff(r1, r2);

	ft_printf("\n------------------------------------------\n");

	for (int i = 'A'; i < 'Z'; i += 4)
	{
		r1 = printf("[%5c:%-5c|%8c:%-8c|%2c:%-2c|%1c:%-1c]\n", i, i, i, i, i, i, i, i);
		r2 = ft_printf("[%5c:%-5c|%8c:%-8c|%2c:%-2c|%1c:%-1c]\n", i, i, i, i, i, i, i, i);
		check_diff(r1, r2);
	}
}

void	test_str(void)
{
	int		r1;
	int		r2;
	char	*s = NULL;

	ft_printf("\n------------------------------------------\n");
	r1 = printf("|%-8s:%8s|<>|%12.7s:%-12.7s|\n", "qwerty", "qwerty", "hello world", "hello world");
	r2 = ft_printf("|%-8s:%8s|<>|%12.7s:%-12.7s|\n", "qwerty", "qwerty", "hello world", "hello world");
	check_diff(r1, r2);

	r1 = printf("@ >%.s\n", "-");
	r2 = ft_printf("# >%.s\n", "-");
	check_diff(r1, r2);
	r1 = printf("@ >%.s\n", "0123456789");
	r2 = ft_printf("# >%.s\n", "0123456789");
	check_diff(r1, r2);

	ft_printf("\n------------------------------------------\n");

	r1 = printf("      [%s]\n", s);
	r2 = ft_printf("      [%s]\n", s);
	check_diff(r1, r2);
	r1 = printf("      [%-s]\n", s);
	r2 = ft_printf("      [%-s]\n", s);
	check_diff(r1, r2);
	r1 = printf("  .2  [%.2s]\n", s);
	r2 = ft_printf("  .2  [%.2s]\n", s);
	check_diff(r1, r2);
	r1 = printf("  .2  [%-.2s]\n", s);
	r2 = ft_printf("  .2  [%-.2s]\n", s);
	check_diff(r1, r2);
	r1 = printf("  .5  [%.5s]\n", s);
	r2 = ft_printf("  .5  [%.5s]\n", s);
	check_diff(r1, r2);
	r1 = printf("  .5  [%-.5s]\n", s);
	r2 = ft_printf("  .5  [%-.5s]\n", s);
	check_diff(r1, r2);
	r1 = printf("  .8  [%.8s]\n", s);
	r2 = ft_printf("  .8  [%.8s]\n", s);
	check_diff(r1, r2);
	r1 = printf("  .8  [%-.8s]\n", s);
	r2 = ft_printf("  .8  [%-.8s]\n", s);
	check_diff(r1, r2);
	r1 = printf("  .12 [%.12s]\n", s);
	r2 = ft_printf("  .12 [%.12s]\n", s);
	check_diff(r1, r2);
	r1 = printf("  .12 [%-.12s]\n", s);
	r2 = ft_printf("  .12 [%-.12s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 2.2  [%2.2s]\n", s);
	r2 = ft_printf(" 2.2  [%2.2s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 2.2  [%-2.2s]\n", s);
	r2 = ft_printf(" 2.2  [%-2.2s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 2.5  [%2.5s]\n", s);
	r2 = ft_printf(" 2.5  [%2.5s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 2.5  [%-2.5s]\n", s);
	r2 = ft_printf(" 2.5  [%-2.5s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 2.8  [%2.8s]\n", s);
	r2 = ft_printf(" 2.8  [%2.8s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 2.8  [%-2.8s]\n", s);
	r2 = ft_printf(" 2.8  [%-2.8s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 2.12 [%2.12s]\n", s);
	r2 = ft_printf(" 2.12 [%2.12s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 2.12 [%-2.12s]\n", s);
	r2 = ft_printf(" 2.12 [%-2.12s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 5.2  [%5.2s]\n", s);
	r2 = ft_printf(" 5.2  [%5.2s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 5.2  [%-5.2s]\n", s);
	r2 = ft_printf(" 5.2  [%-5.2s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 5.5  [%5.5s]\n", s);
	r2 = ft_printf(" 5.5  [%5.5s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 5.5  [%-5.5s]\n", s);
	r2 = ft_printf(" 5.5  [%-5.5s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 5.8  [%5.8s]\n", s);
	r2 = ft_printf(" 5.8  [%5.8s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 5.8  [%-5.8s]\n", s);
	r2 = ft_printf(" 5.8  [%-5.8s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 5.12 [%5.12s]\n", s);
	r2 = ft_printf(" 5.12 [%5.12s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 5.12 [%-5.12s]\n", s);
	r2 = ft_printf(" 5.12 [%-5.12s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 8.2  [%8.2s]\n", s);
	r2 = ft_printf(" 8.2  [%8.2s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 8.2  [%-8.2s]\n", s);
	r2 = ft_printf(" 8.2  [%-8.2s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 8.5  [%8.5s]\n", s);
	r2 = ft_printf(" 8.5  [%8.5s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 8.5  [%-8.5s]\n", s);
	r2 = ft_printf(" 8.5  [%-8.5s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 8.8  [%8.8s]\n", s);
	r2 = ft_printf(" 8.8  [%8.8s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 8.8  [%-8.8s]\n", s);
	r2 = ft_printf(" 8.8  [%-8.8s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 8.12 [%8.12s]\n", s);
	r2 = ft_printf(" 8.12 [%8.12s]\n", s);
	check_diff(r1, r2);
	r1 = printf(" 8.12 [%-8.12s]\n", s);
	r2 = ft_printf(" 8.12 [%-8.12s]\n", s);
	check_diff(r1, r2);
	r1 = printf("12.2  [%12.2s]\n", s);
	r2 = ft_printf("12.2  [%12.2s]\n", s);
	check_diff(r1, r2);
	r1 = printf("12.2  [%-12.2s]\n", s);
	r2 = ft_printf("12.2  [%-12.2s]\n", s);
	check_diff(r1, r2);
	r1 = printf("12.5  [%12.5s]\n", s);
	r2 = ft_printf("12.5  [%12.5s]\n", s);
	check_diff(r1, r2);
	r1 = printf("12.5  [%-12.5s]\n", s);
	r2 = ft_printf("12.5  [%-12.5s]\n", s);
	check_diff(r1, r2);
	r1 = printf("12.8  [%12.8s]\n", s);
	r2 = ft_printf("12.8  [%12.8s]\n", s);
	check_diff(r1, r2);
	r1 = printf("12.8  [%-12.8s]\n", s);
	r2 = ft_printf("12.8  [%-12.8s]\n", s);
	check_diff(r1, r2);
	r1 = printf("12.12 [%12.12s]\n", s);
	r2 = ft_printf("12.12 [%12.12s]\n", s);
	check_diff(r1, r2);
	r1 = printf("12.12 [%-12.12s]\n", s);
	r2 = ft_printf("12.12 [%-12.12s]\n", s);
	check_diff(r1, r2);
}

void	test_unsigned(void)
{
	int	r1;
	int	r2;

	ft_printf("\n------------------------------------------\n");

	r1 = printf("%u\n", 0);
	r2 = ft_printf("%u\n", 0);
	check_diff(r1, r2);
	r1 = printf("%u\n", -1);
	r2 = ft_printf("%u\n", -1);
	check_diff(r1, r2);
	r1 = printf("%u\n", 1);
	r2 = ft_printf("%u\n", 1);
	check_diff(r1, r2);
	r1 = printf("%u\n", 11);
	r2 = ft_printf("%u\n", 11);
	check_diff(r1, r2);
	r1 = printf("%u\n", 17);
	r2 = ft_printf("%u\n", 17);
	check_diff(r1, r2);
	r1 = printf("%u\n", 100);
	r2 = ft_printf("%u\n", 100);
	check_diff(r1, r2);
	r1 = printf("%u\n", -99);
	r2 = ft_printf("%u\n", -99);
	check_diff(r1, r2);
	r1 = printf("%u\n", -101);
	r2 = ft_printf("%u\n", -101);
	check_diff(r1, r2);
	r1 = printf("%u\n", INT_MAX);
	r2 = ft_printf("%u\n", INT_MAX);
	check_diff(r1, r2);
	r1 = printf("%u\n", INT_MIN);
	r2 = ft_printf("%u\n", INT_MIN);
	check_diff(r1, r2);
	r1 = printf("%u\n", LONG_MAX);
	r2 = ft_printf("%u\n", LONG_MAX);
	check_diff(r1, r2);
	r1 = printf("%u\n", LONG_MIN);
	r2 = ft_printf("%u\n", LONG_MIN);
	check_diff(r1, r2);
	r1 = printf("%u\n", UINT_MAX);
	r2 = ft_printf("%u\n", UINT_MAX);
	check_diff(r1, r2);
	r1 = printf("%u\n", ULONG_MAX);
	r2 = ft_printf("%u\n", ULONG_MAX);
	check_diff(r1, r2);
	r1 = printf("%u\n", 9223372036854775807LL);
	r2 = ft_printf("%u\n", 9223372036854775807LL);
	check_diff(r1, r2);
	r1 = printf("%u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	r2 = ft_printf("%u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	check_diff(r1, r2);

	ft_printf("\n------------------------------------------\n");

	r1 = printf("[%06.15u]\n", 42);
	r2 = ft_printf("[%06.15u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%01.1u]\n", 42);
	r2 = ft_printf("[%01.1u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%03.1u]\n", 42);
	r2 = ft_printf("[%03.1u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%03.2u]\n", 42);
	r2 = ft_printf("[%03.2u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%03.3u]\n", 42);
	r2 = ft_printf("[%03.3u]\n", 42);

	ft_printf("\n------------------------------------------\n");

	check_diff(r1, r2);
	r1 = printf("[%04.1u]\n", 42);
	r2 = ft_printf("[%04.1u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%-4.1u]\n", 42);
	r2 = ft_printf("[%-4.1u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%04.4u]\n", 42);
	r2 = ft_printf("[%04.4u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%04.5u]\n", 42);
	r2 = ft_printf("[%04.5u]\n", 42);
	check_diff(r1, r2);

	ft_printf("\n------------------------------------------\n");

	r1 = printf("[%8u]\n", 42);
	r2 = ft_printf("[%8u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%.8u]\n", 42);
	r2 = ft_printf("[%.8u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%12.8u]\n", 42);
	r2 = ft_printf("[%12.8u]\n", 42);
	check_diff(r1, r2);

	r1 = printf("[%-8u]\n", 42);
	r2 = ft_printf("[%-8u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%-.8u]\n", 42);
	r2 = ft_printf("[%-.8u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%-12.8u]\n", 42);
	r2 = ft_printf("[%-12.8u]\n", 42);
	check_diff(r1, r2);

	r1 = printf("[%08u]\n", 42);
	r2 = ft_printf("[%08u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%0.8u]\n", 42);
	r2 = ft_printf("[%0.8u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%012.8u]\n", 42);
	r2 = ft_printf("[%012.8u]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%011.8d]\n", 42);
	r2 = ft_printf("[%011.8d]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%010.8d]\n", 42);
	r2 = ft_printf("[%010.8d]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%010.9d]\n", 42);
	r2 = ft_printf("[%010.9d]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%09.9d]\n", 42);
	r2 = ft_printf("[%09.9d]\n", 42);
	check_diff(r1, r2);
}

void	test_hex(void)
{
	int	r1;
	int	r2;

	for (int i = 0; i < 8; i++)
	{
		r1 = printf("[%16x:%16X|%-16x:%-16X|%20p:%-20p]\n", a[i], a[i], a[i], a[i], a + i, a + i);
		r2 = ft_printf("[%16x:%16X|%-16x:%-16X|%20p:%-20p]\n", a[i], a[i], a[i], a[i], a + i, a + i);
		check_diff(r1, r2);
	}

	ft_printf("\n------------------------------------------\n");

	for (int i = 0; i < 8; i++)
	{
		r1 = printf("[%12.8x:%-12.8x|%#14.13x:%#-14.13x|%15.18x:%-15.18x] [%-8.5d:%8.5d]\n", a[i], a[i], a[i], a[i], a[i], a[i], a[i], a[i]);
		r2 = ft_printf("[%12.8x:%-12.8x|%#14.13x:%#-14.13x|%15.18x:%-15.18x] [%-8.5d:%8.5d]\n", a[i], a[i], a[i], a[i], a[i], a[i], a[i], a[i]);
		check_diff(r1, r2);
	}

	ft_printf("\n------------------------------------------\n");

	r1 = printf("[%01x]\n", 0);
	r2 = ft_printf("[%01x]\n", 0);
	check_diff(r1, r2);
	r1 = printf("[%02x]\n", -1);
	r2 = ft_printf("[%02x]\n", -1);
	check_diff(r1, r2);
	r1 = printf("[%03x]\n", 1);
	r2 = ft_printf("[%03x]\n", 1);
	check_diff(r1, r2);
	r1 = printf("[%04x]\n", 9);
	r2 = ft_printf("[%04x]\n", 9);
	check_diff(r1, r2);
	r1 = printf("[%01x]\n", 10);
	r2 = ft_printf("[%01x]\n", 10);
	check_diff(r1, r2);
	r1 = printf("[%02x]\n", 11);
	r2 = ft_printf("[%02x]\n", 11);
	check_diff(r1, r2);
	r1 = printf("[%03x]\n", 15);
	r2 = ft_printf("[%03x]\n", 15);
	check_diff(r1, r2);
	r1 = printf("[%04x]\n", 16);
	r2 = ft_printf("[%04x]\n", 16);
	check_diff(r1, r2);
	r1 = printf("[%05x]\n", 17);
	r2 = ft_printf("[%05x]\n", 17);
	check_diff(r1, r2);
	r1 = printf("[%01x]\n", 99);
	r2 = ft_printf("[%01x]\n", 99);
	check_diff(r1, r2);
	r1 = printf("[%02x]\n", 100);
	r2 = ft_printf("[%02x]\n", 100);
	check_diff(r1, r2);
	r1 = printf("[%03x]\n", 101);
	r2 = ft_printf("[%03x]\n", 101);
	check_diff(r1, r2);
	r1 = printf("[%01x]\n", -9);
	r2 = ft_printf("[%01x]\n", -9);
	check_diff(r1, r2);
	r1 = printf("[%02x]\n", -10);
	r2 = ft_printf("[%02x]\n", -10);
	check_diff(r1, r2);
	r1 = printf("[%#03x]\n", -11);
	r2 = ft_printf("[%#03x]\n", -11);
	check_diff(r1, r2);
	r1 = printf("[%#04x]\n", -14);
	r2 = ft_printf("[%#04x]\n", -14);
	check_diff(r1, r2);
	r1 = printf("[%05x]\n", -15);
	r2 = ft_printf("[%05x]\n", -15);
	check_diff(r1, r2);
	r1 = printf("[%06x]\n", -16);
	r2 = ft_printf("[%06x]\n", -16);
	check_diff(r1, r2);
	r1 = printf("[%01x]\n", -99);
	r2 = ft_printf("[%01x]\n", -99);
	check_diff(r1, r2);
	r1 = printf("[%02x]\n", -100);
	r2 = ft_printf("[%02x]\n", -100);
	check_diff(r1, r2);
	r1 = printf("[%#03x]\n", -101);
	r2 = ft_printf("[%#03x]\n", -101);
	check_diff(r1, r2);
	r1 = printf("[%#09x]\n", INT_MAX);
	r2 = ft_printf("[%#09x]\n", INT_MAX);
	check_diff(r1, r2);
	r1 = printf("[%010x]\n", INT_MIN);
	r2 = ft_printf("[%010x]\n", INT_MIN);
	check_diff(r1, r2);
	r1 = printf("[%#011.5x]\n", LONG_MAX);
	r2 = ft_printf("[%#011.5x]\n", LONG_MAX);
	check_diff(r1, r2);
	r1 = printf("[%#010.6x]\n", 4242);
	r2 = ft_printf("[%#010.6x]\n", 4242);
	check_diff(r1, r2);
	r1 = printf("[%012x]\n", LONG_MIN);
	r2 = ft_printf("[%012x]\n", LONG_MIN);
	check_diff(r1, r2);
	r1 = printf("[%013x]\n", UINT_MAX);
	r2 = ft_printf("[%013x]\n", UINT_MAX);
	check_diff(r1, r2);
	r1 = printf("[%014x]\n", ULONG_MAX);
	r2 = ft_printf("[%014x]\n", ULONG_MAX);
	check_diff(r1, r2);
	r1 = printf("[%#015x]\n", 9223372036854775807LL);
	r2 = ft_printf("[%#015x]\n", 9223372036854775807LL);
	check_diff(r1, r2);
}

void	test2(void)
{
	int	r1, r2;

	ft_printf("\n------------------------------------------\n");
	r1 = printf("[%01.0c]\n", 0);
	r2 = ft_printf("[%01.0c]\n", 0);
	check_diff(r1, r2);
	r1 = printf("[%01.0c]\n", 42);
	r2 = ft_printf("[%01.0c]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%02.0c]\n", 0);
	r2 = ft_printf("[%02.0c]\n", 0);
	check_diff(r1, r2);
	r1 = printf("[%02.0c]\n", 42);
	r2 = ft_printf("[%02.0c]\n", 42);
	check_diff(r1, r2);

	ft_printf("\n------------------------------------------\n");
	r1 = printf("[%01.0i]\n", 0);
	r2 = ft_printf("[%01.0i]\n", 0);
	check_diff(r1, r2);
	r1 = printf("[%01.0i]\n", 42);
	r2 = ft_printf("[%01.0i]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%02.0i]\n", 0);
	r2 = ft_printf("[%02.0i]\n", 0);
	check_diff(r1, r2);
	r1 = printf("[%02.0i]\n", 42);
	r2 = ft_printf("[%02.0i]\n", 42);
	check_diff(r1, r2);

	ft_printf("\n------------------------------------------\n");
	r1 = printf("[%+01.0i]\n", 0);
	r2 = ft_printf("[%+01.0i]\n", 0);
	check_diff(r1, r2);
	r1 = printf("[%+01.0i]\n", 42);
	r2 = ft_printf("[%+01.0i]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%+02.0i]\n", 0);
	r2 = ft_printf("[%+02.0i]\n", 0);
	check_diff(r1, r2);
	r1 = printf("[%+02.0i]\n", 42);
	r2 = ft_printf("[%+02.0i]\n", 42);
	check_diff(r1, r2);

	ft_printf("\n------------------------------------------\n");
	r1 = printf("[%01.0x]\n", 0);
	r2 = ft_printf("[%01.0x]\n", 0);
	check_diff(r1, r2);
	r1 = printf("[%01.0x]\n", 42);
	r2 = ft_printf("[%01.0x]\n", 42);
	check_diff(r1, r2);
	r1 = printf("[%02.0x]\n", 0);
	r2 = ft_printf("[%02.0x]\n", 0);
	check_diff(r1, r2);
	r1 = printf("[%02.0x]\n", 42);
	r2 = ft_printf("[%02.0x]\n", 42);
	check_diff(r1, r2);

	ft_printf("\n------------------------------------------\n");
	r1 = printf("[%01.p]\n", NULL);
	r2 = ft_printf("[%01.p]\n", NULL);
	check_diff(r1, r2);
	r1 = printf("[%02.p]\n", NULL);
	r2 = ft_printf("[%02.p]\n", NULL);
	check_diff(r1, r2);
	r1 = printf("[%07.p]\n", NULL);
	r2 = ft_printf("[%07.p]\n", NULL);
	check_diff(r1, r2);
	r1 = printf("[%01.0p]\n", NULL);
	r2 = ft_printf("[%01.0p]\n", NULL);
	check_diff(r1, r2);
	r1 = printf("[%02.0p]\n", NULL);
	r2 = ft_printf("[%02.0p]\n", NULL);
	check_diff(r1, r2);
	r1 = printf("[%07.0p]\n", NULL);
	r2 = ft_printf("[%07.0p]\n", NULL);
	check_diff(r1, r2);

	ft_printf("\n------------------------------------------\n");
	r1 = printf("[%01.6p]\n", NULL);
	r2 = ft_printf("[%01.6p]\n", NULL);
	check_diff(r1, r2);
	r1 = printf("[%02.6p]\n", NULL);
	r2 = ft_printf("[%02.6p]\n", NULL);
	check_diff(r1, r2);
	r1 = printf("[%07.6p]\n", NULL);
	r2 = ft_printf("[%07.6p]\n", NULL);
	check_diff(r1, r2);
	r1 = printf("[%-01.6p]\n", NULL);
	r2 = ft_printf("[%-01.6p]\n", NULL);
	check_diff(r1, r2);
	r1 = printf("[%-02.6p]\n", NULL);
	r2 = ft_printf("[%-02.6p]\n", NULL);
	check_diff(r1, r2);
	r1 = printf("[%-07.6p]\n", NULL);
	r2 = ft_printf("[%-07.6p]\n", NULL);
	check_diff(r1, r2);
}

void	check_diff(int r1, int r2)
{
	if (r1 != r2)
		ft_printf("     # Not same return : r1=%d | r2=%d # -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- #\n", r1, r2);
}
