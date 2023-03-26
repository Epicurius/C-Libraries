make

if [ "$OSTYPE" == "linux-gnu"* ] ; then
    echo "linux is not supported"
elif [ "$OSTYPE" == "darwin"* ] ; then
    gcc ./tests/test_main.c ./libpf.a ../libft/libft.a -fsanitize=address
    ./a.out
    rm a.out
elif [ "$OSTYPE" == "cygwin" ] ; then
    echo "cygwin is not supported"
elif [ "$OSTYPE" == "msys" ] ; then
    gcc ./tests/test_main.c -I . ./libpf.a ../libft/libft.a -I ../libft/
    ./a.exe
    rm a.exe
elif [ "$OSTYPE" == "win32" ] ; then
    echo "win32 is not supported"
else
    echo "Unknown."
fi

rm -f fprintf.txt
rm -f ft_fprintf.txt
rm -f dprintf.txt
rm -f ft_dprintf.txt
rm -f printf.txt
rm -f ft_printf.txt

