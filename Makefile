FLAGS=-Werror -Wextra
example: *.c 
	clang -o $@ $^ $(FLAGS)
