#!/bin/bash

FILES="./tests/test_main.c -I . ./libpf.a ../libft/libft.a -I ../libft/"

make

if [ "$OSTYPE" == "linux-gnu" ] ; then
    gcc $FILES -fsanitize=address
    ./a.out
    rm a.out
elif [ "$OSTYPE" == "darwin"* ] ; then
    gcc $FILES -fsanitize=address
    ./a.out
    rm a.out
elif [ "$OSTYPE" == "msys" ] ; then
    gcc $FILES
    ./a.exe
    rm a.exe
else
    echo "OS is not supported."
fi

rm -f fprintf.txt
rm -f ft_fprintf.txt
rm -f dprintf.txt
rm -f ft_dprintf.txt
rm -f printf.txt
rm -f ft_printf.txt
