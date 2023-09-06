/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 *
 * Created: 25/03/2023 Niklas Neronin
 * Updated: 26/03/2023 Niklas Neronin
 */

#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "libpf.h"

int x = 12359;
char *str = "Hello World!";
unsigned long int uli = 234;

void compareString(char *str1, char *str2)
{
	if (strcmp(str1, str2))
		printf("libpf: %sstdio: %s", str1, str2);
}

void compareFiles(char *name1, char *name2)
{
	FILE *fp1 = fopen(name1, "r");
	FILE *fp2 = fopen(name2, "r");

	char ch1 = getc(fp1);
	char ch2 = getc(fp2);
	char *ptr1;
	char *ptr2;

	int bufferLength = 255;
	char buff1[bufferLength];
	char buff2[bufferLength];
	while(fgets(buff1, bufferLength, fp1) && fgets(buff2, bufferLength, fp2))
		compareString(buff1, buff2);

    fclose(fp1);
    fclose(fp2);
}

int	test_printf(int (*func)(const char * restrict, ...))
{
	char a = 'a';
	unsigned int t = 96;
	unsigned short int tt = 948;
	long double dd = 11112312.123123123;
	unsigned char xx = 22;
	signed char hh = a;
	short int h = -1234;
	long int l = 1234;
	unsigned long long int ulli = 1242;
	long long int ll = -9223372036854775807;
	long long int lll = -9223372036854775807;
	long fgh = 123;
	long long tyu = 12345;
	long double asd1 = -3123.82312;
	double d = -11.1;
	double nbd = 12345.123456789123456789123456789;
	double nbd2 = -12547.58;

	func("0 2 |%c|\n", 'j');
	func("1 s: %s %s\n", str, str);
	func("2 c: %c\n", a);
	func("3 d: %.d\n", x);
	func("4 i: %i %i %i\n", 12, 012, 0x12);
	func("5 u: %u\n", t);
	func("6 o: %20.10o\n", x);
	func("7 x: %x\n", x);
	func("8 X: %20.10X\n", x);
	func("9 %% percent: %d\n", x);
	func("10 d: %+7.5d\n", -123);
	func("11 d: %+7.3d\n", 12345);
	func("12 d: %+5.3d\n", 1234567);
	func("13 d: %+5.7d\n", 123);
	func("14 d: %+3.7d\n", 12345);
	func("15 d: %+3.5d\n", 1234567);
	func("16 ld: %+7.5ld\n", fgh);
	func("17 lld: %+7.3lld\n", tyu);
	func("18 many: %d %i %5.3d%s %lx\n idk what more to test\n", 1, x, 1234567, str, uli);
	func("19 Characters: %c %c \n", 'a', 65);
	func("20 Decimals: %d %ld\n", 1977, 650000L);
	func("21 Preceding with blanks: %10d \n", 1977);
	func("22 Preceding with zeros: %010d \n", 1977);
	func("23 Some different radices: %d %x %o %#10.5xh %7.5o \n", 100, 100, 100, 100, 100);
	func("24 floats: %4.2f \n", 3.1416);
	func("25 Width trick: %*d \n", 5, 10);
	func("26 %s \n", "A string");
	func("27 o: %#o\n", x);
	func("28 x: %#x\n", x);
	func("29 X: %#X\n", x);
	func("30 o: %#20o\n", x);
	func("31 x: %#20x\n", x);
	func("32 X: %#20X\n", x);
	func("33 o: %#20.10o\n", x);
	func("34 x: %#20.10x\n", x);
	func("35 X: %#20.10X\n", x);
	func("36 f: %f\n", d);
	func("37 .10f: %.10f\n", d);
	func("38 +f: %+f\n", d);
	func("39 f: %.3f\n", d);
	func("40 f: %.10lf\n", d);
	func("41 s: %s\n", NULL);
	func("42 p3 %.4s\n", NULL);
	func("43 %.2s is a string\n", "");
	func("44 %5.2s is a string\n", "");
	func("45 %-5.2s is a string\n", "");
	func("46 %#08x < Aidsssss\n", 42);
	func("47 %#8x\n", 42);
	func("48 Characters: %c %c \n", 'a', 65);
	func("49 Decimals: %d %ld\n", 1977, 650000L);
	func("50 Some different radices: %d %x %o %#10.5xh %7.5o \n", 100, 100, 100, 100, 100);
	func("51 floats: %4.2f \n", 3.1416);
	func("52 Width trick: %*d \n", 5, 10);
	func("53 |%s|\n", "abc");
	func("54 |%4.s|\n", "42");
	func("55 |%4.1s|\n", "42");
	func("56 |%4s|\n", "42");
	func("57 |%.01s|\n", "");
	func("58 |%.02s|\n", "");
	func("59 |%2s|\n", "");
	func("60 |%01.u|\n", 0);
	func("61 |%01.d|\n", 0);
	func("62 |%f|\n", -12547.58);
	func("63 {%#5o}\n", 1);
	func("64 {%#5o}\n", 0);
	func("65 {%5o}\n", 0);
	func("67 {%.o, %.0o}\n", 0, 0);
	func("68 {%#.o, %#.0o}\n", 1, 1);
	func("69 {%.o, %.0o}\n", 1, 1);
	func("70 {%#05o, %#05o}\n", 1, 1);
	func("71 |%#7.5o|\n", 0xab);
	func("72 |%7.5o|\n", 0xab);
	func("73 |%#7.5o|\n", 0xab);
	func("74 {%#.5o}\n", 1);
	func("75 {%.5o}\n", 1);
	func("76 {%5.5o}\n", 1);
	func("77 {%#.5o}\n", 0);
	func("78 @moulitest: |%o|\n", 0);
	func("79 |%#o|\n", 0);
	func("81 |%#6o|\n", 2500);
	func("82 |%-#6o|\n", 2500);
	func("83 J'ai %i %s et %c yeux et 0.1%% de capacite cerebrale\n\n", 4, "dents", '2');
	func("84 check(TEST: uint:	%u\n", 55555);
	func("85 check(TEST: hexa:	%x\n", 55555);
	func("86 check(TEST: hexa maj:	%X\n", 55555);
	func("87 check(TEST: octal:	%o\n", 55555);
	func("88 |%-10.0lf|\n", nbd);
	func("89 |%-1.10lf|\n", nbd);
	func("90 |%3.2lf|\n", nbd);
	func("91 |%09lf|\n", nbd);
	func("92 |%03lf|\n", nbd);
	func("93 |%-5.0lf|\n", nbd);
	func("94 |%#-5.0lf|\n", nbd);
	func("95 |%#-10.0lf|\n", nbd);
	func("96 |%#10.0lf|\n", nbd);
	func("97 |%#10.lf|\n", nbd);
	func("98 |%+#10.lf|\n", nbd);
	func("99 |%+-#10.lf|\n", nbd);
	func("100 |%+-#10.9lf|\n", nbd);
	func("101 |% -#10.9lf|\n", nbd);
	func("102 |% -#10.lf|\n", nbd);
	func("103 |% -#10.10lf|\n", nbd);
	func("104 |% f|\n", nbd2);
	func("105 |%+f|\n", nbd2);
	func("106 |%#f|\n", nbd2);
	func("107 |%.2f|\n", nbd2);
	func("108 |%.12f|\n", nbd2);
	func("109 |%#.0f|\n", nbd2);
	func("110 |% .5f|\n", nbd2);
	func("111 |%# .0f|\n", nbd2);
	func("112 |% #.0f|\n", nbd2);
	func("113 |%+.5f|\n", nbd2);
	func("114 |%+.0f|\n", nbd2);
	func("115 |%#+.0f|\n", nbd2);
	func("116 |%0.5f|\n", nbd2);
	func("117 |%-.5f|\n", nbd2);
	func("118 |%5f|\n", nbd2);
	func("119 |% 5f|\n", nbd2);
	func("120 |%+5f|\n", nbd2);
	func("121 |%# 5f|\n", nbd2);
	func("122 |%#+5f|\n", nbd2);
	func("123 |%-5f|\n", nbd2);
	func("124 |%05f|\n", nbd2);
	func("125 |%+05f|\n", nbd2);
	func("126 |%0+5f|\n", nbd2);
	func("127 |%05.3f|\n", nbd2);
	func("128 |%0#5.0f|\n", nbd2);
	func("129 |%-5.3f|\n", nbd2);
	func("130 |%-#5.0f|\n", nbd2);
	func("131 |%+05.3f|\n", nbd2);
	func("132 |%0+#5.0f|\n", nbd2);
	func("133 |%0 5.3f|\n", nbd2);
	func("134 |% 05.3f|\n", nbd2);
	func("135 |%#0 5.0f|\n", nbd2);
	func("136 |%-+5.3f|\n", nbd2);
	func("137 |%#+5.0f|\n", nbd2);
	func("138 {% 5.f}\n", 137.0);
	func("139 {%05.f}\n", 137.0);
	func("140 {%+5.f}\n", 137.0);
	func("141 {%+#5.f}\n", 137.0);
	func("142 {%-5.f}\n", 137.0);
	func("143 {%#5.f}\n", 137.0);
	func("144 {%5.f}\n", 137.0);
	func("145 {%5.f}\n", 0.0);
	func("146 {%#5f}\n", 1.0);
	func("147 {%#5f}\n", 0.0);
	func("148 {%5f}\n", 0.0);
	func("149 {%#.f, %#.0f}\n", 0.0, 0.0);
	func("150 {%.f, %.0f}\n", 0.0, 0.0);
	func("151 {%#.f, %#.0f}\n", 1.0, 1.0);
	func("152 {%.f, %.0f}\n", 1.0, 1.0);
	func("153 {%#05f, %#05f}\n", 1.0, 1.0);
	func("154 |%#07.5f|\n", 175.0);
	func("155 |%7.5f|\n", 175.0);
	func("156 {%#.5f}\n", 1.0);
	func("157 {%.5f}\n", 1.0);
	func("158 {%#.5f}\n", 0.0);
	func("159 {%.f}\n", 0.0);
	func("160 {%5f}\n", 1.5);
	func("161 {%.5f}\n", 1.5);
	func("162 {%5f}\n", 1500.5);
	func("163 {%.5f}\n", 1500.5);
	func("164 {%5.5f}\n", 0.0);
	func("165 2147483648.123450012: %.0f\n", 2147483648.123450012);
	func("166 0.01: %.15f\n", 0.01);
	func("167 0.0: %f\n", 0.0);
	func("168 1.0: %f\n", 1.0);
	func("169 01.01: %.4f\n", 01.01);
	func("170 0.00000000000000000001: %f\n", 0.00000000000000000001);
	func("171 0.1234567: %f\n", 0.1234567);
	func("172 0.1234564: %f\n", 0.1234564);
	func("173 -1.5: %.2f\n", -1.5);
	func("174 -0.05: %f\n", -0.05);
}

int	test_sprintf()
{
	char	s1[PF_BUFF_SIZE];
	char	s2[PF_BUFF_SIZE];

	ft_sprintf(s1, "many: %d %i %5.3d%s\n %lx idk what more to test", 1, x, 1234567, str, uli);
	sprintf(s2, "many: %d %i %5.3d%s\n %lx idk what more to test", 1, x, 1234567, str, uli);
	compareString(s1, s2);

	ft_sprintf(s1, "Characters: %c %c ", 'a', 65);
	sprintf(s2, "Characters: %c %c ", 'a', 65);
	compareString(s1, s2);

	ft_sprintf(s1, "Decimals: %d %ld", 1977, 650000L);
	sprintf(s2, "Decimals: %d %ld", 1977, 650000L);
	compareString(s1, s2);

	ft_sprintf(s1, "Some different radices: %d %x %o %#10.5xh %7.5o", 100, 100, 100, 100, 100);
	sprintf(s2, "Some different radices: %d %x %o %#10.5xh %7.5o", 100, 100, 100, 100, 100);
	compareString(s1, s2);

	ft_sprintf(s1, "floats: %4.2f ", 3.1416);
	sprintf(s2, "floats: %4.2f ", 3.1416);
	compareString(s1, s2);

	ft_sprintf(s1, "Width trick: %*d ", 5, 10);
	sprintf(s2, "Width trick: %*d ", 5, 10);
	compareString(s1, s2);
}

int	test_asprintf()
{
	char *s1;
	char *s2;

	ft_asprintf(&s1, "many: %d %i %5.3d%s\n %lx idk what more to test", 1, x, 1234567, str, uli);
	asprintf(&s2, "many: %d %i %5.3d%s\n %lx idk what more to test", 1, x, 1234567, str, uli);
	compareString(s1, s2);
	free(s1);
	free(s2);

	ft_asprintf(&s1, "Characters: %c %c ", 'a', 65);
	asprintf(&s2, "Characters: %c %c ", 'a', 65);
	compareString(s1, s2);
	free(s1);
	free(s2);

	ft_asprintf(&s1, "Decimals: %d %ld", 1977, 650000L);
	asprintf(&s2, "Decimals: %d %ld", 1977, 650000L);
	compareString(s1, s2);
	free(s1);
	free(s2);

	ft_asprintf(&s1, "Some different radices: %d %x %o %#10.5xh %7.5o", 100, 100, 100, 100, 100);
	asprintf(&s2, "Some different radices: %d %x %o %#10.5xh %7.5o", 100, 100, 100, 100, 100);
	compareString(s1, s2);
	free(s1);
	free(s2);

    ft_asprintf(&s1, "floats: %4.2f ", 3.1416);
	asprintf(&s2, "floats: %4.2f ", 3.1416);
	compareString(s1, s2);
	free(s1);
	free(s2);

    ft_asprintf(&s1, "Width trick: %*d ", 5, 10);
	asprintf(&s2, "Width trick: %*d ", 5, 10);
	compareString(s1, s2);
	free(s1);
	free(s2);
}

int	test_snprintf()
{
	char s1[PF_BUFF_SIZE];
	char s2[PF_BUFF_SIZE];

	ft_snprintf(s1, PF_BUFF_SIZE, "many: %d %i %5.3d%s\n %lx idk what more to test", 1, x, 1234567, str, uli);
	snprintf(s2, PF_BUFF_SIZE, "many: %d %i %5.3d%s\n %lx idk what more to test", 1, x, 1234567, str, uli);
	compareString(s1, s2);

	ft_snprintf(s1, PF_BUFF_SIZE, "Characters: %c %c ", 'a', 65);
	snprintf(s2, PF_BUFF_SIZE, "Characters: %c %c ", 'a', 65);
	compareString(s1, s2);

	ft_snprintf(s1, PF_BUFF_SIZE, "Decimals: %d %ld", 1977, 650000L);
	snprintf(s2, PF_BUFF_SIZE, "Decimals: %d %ld", 1977, 650000L);
	compareString(s1, s2);

	ft_snprintf(s1, PF_BUFF_SIZE, "Some different radices: %d %x %o %#10.5xh %7.5o", 100, 100, 100, 100, 100);
	snprintf(s2, PF_BUFF_SIZE, "Some different radices: %d %x %o %#10.5xh %7.5o", 100, 100, 100, 100, 100);
	compareString(s1, s2);

	ft_snprintf(s1, PF_BUFF_SIZE, "floats: %4.2f ", 3.1416);
	snprintf(s2, PF_BUFF_SIZE, "floats: %4.2f ", 3.1416);
	compareString(s1, s2);

	ft_snprintf(s1, PF_BUFF_SIZE, "Width trick: %*d ", 5, 10);
	snprintf(s2, PF_BUFF_SIZE, "Width trick: %*d ", 5, 10);
	compareString(s1, s2);

}

int	test_fprintf()
{
	FILE *fd1, *fd2;

	fd1 = fopen("ft_fprintf.txt", "w");
	ft_fprintf(fd1, "many: %d %i %5.3d%s %lx\n idk what more to test\n", 1, x, 1234567, str, uli);
	fclose(fd1);

	fd2 = fopen("fprintf.txt", "w");
	fprintf(fd2, "many: %d %i %5.3d%s %lx\n idk what more to test\n", 1, x, 1234567, str, uli);
	fclose(fd2);

	compareFiles("fprintf.txt", "ft_fprintf.txt");
}

int	test_dprintf()
{
	int fd1, fd2;

	fd1 = open("ft_dprintf.txt", O_CREAT | O_WRONLY | O_TRUNC);
	ft_dprintf(fd1, "many: %d %i %5.3d%s %lx\n idk what more to test\n", 1, x, 1234567, str, uli);
	close(fd1);

	// fd2 = open("dprintf.txt", O_CREAT | O_WRONLY | O_TRUNC);
	// dprintf(fd2, "many: %d %i %5.3d%s %lx\n idk what more to test\n", 1, x, 1234567, str, uli);
	// close(fd2);

	// compareFiles("dprintf.txt", "ft_dprintf.txt");
}

static int err_report(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	return -1;
}

int unit_test(char *file, int (*func)(const char * restrict, ...))
{
	int fd1, fd2;
	/* Connect standard output to given file */
	fflush(stdout);
	fd1 = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd1 < 0)
		return err_report("Failed to open %s for writing\n", file);
	fd2 = dup(STDOUT_FILENO);
	if (fd2 < 0)
		return err_report("Failed to duplicate standard output\n");
	if (dup2(fd1, STDOUT_FILENO) < 0)
		return err_report("Failed to duplicate %s to standard output\n", file);
	close(fd1);

    /* Write to standard output */
	test_printf(func);

	/* Reconnect original standard output */
	fflush(stdout);
	if (dup2(fd2, STDOUT_FILENO) < 0)
		return err_report("Failed to reinstate standard output\n");
	close(fd2);
}

int test_color()
{
	ft_printf("{RESET}RESET{RESET}?\n");
	ft_printf("{RED}RED{RESET}?\n");
	ft_printf("{GREEN}GREEN{RESET}?\n");
	ft_printf("{YELLOW}YELLOW{RESET}?\n");
	ft_printf("{BLUE}BLUE{RESET}?\n");
	ft_printf("{MAGENTA}MAGENTA{RESET}?\n");
	ft_printf("{CYAN}CYAN{RESET}?\n");
	ft_printf("{BOLD}BOLD{RESET}?\n");
	ft_printf("{ITALIC}ITALIC{RESET}?\n");
	ft_printf("{UND}UND{RESET}?\n");
	ft_printf("{INVERT}INVERT{RESET}?\n");
	ft_printf("{CLR:41}CLR:41{RESET}?\n");
	ft_printf("{CLR:41?\n");
	ft_printf("{CLR:Marko{CLR:200}Polo{RESET}?\n");
}

int main()
{
	test_color();

	unit_test("ft_printf.txt", ft_printf);
	unit_test("printf.txt", printf);
	compareFiles("ft_printf.txt", "printf.txt");

	test_sprintf();
	test_asprintf();
	test_snprintf();
	test_fprintf();
	test_dprintf();
}
