BLUE = echo "\033[0;36m"
RED = echo "\033[0;31m"
GREEN = echo "\033[0;32m"
END = echo "\033[0m"

NAME = fractol

G = gcc


SRC =	main.c \
		ft_mandelbrot.c \
		ft_get_color.c \
		ft_initialization.c \
		ft_julia.c \
		ft_ship.c \
		hook.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
		@echo "$$($(BLUE))*********************$$($(END))"
		@echo "$$($(BLUE))fractol: "I SURVIVED"$$($(END))"
		@echo "$$($(BLUE))*********************$$($(END))"

$(NAME) : $(OBJ)
		@make -C libft/
		@echo "$$($(GREEN))******************$$($(END))"
		@echo "$$($(GREEN))  libft: "READY"  $$($(END))"
		@echo "$$($(GREEN))******************$$($(END))"
		@$(G) $(FLAG) $(OBJ) libft/libft.a -o $(NAME)  -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@$(G) $(FLAG) -c $<

clean:
		@make -C libft/ clean
		@echo "$$($(RED))**********************$$($(END))"
		@echo "$$($(RED))  fractol: "DEL *.o"  $$($(END))"
		@echo "$$($(RED))**********************$$($(END))"
		@rm -f *.o

fclean: clean
		@echo "$$($(RED))********************$$($(END))"
		@echo "$$($(RED))libft: "DEL libft.a"$$($(END))"
		@echo "$$($(RED))********************$$($(END))"
		@rm -f libft/libft.a
		@echo "$$($(RED))************************$$($(END))"
		@echo "$$($(RED)) fractol: "DEL fractol" $$($(END))"
		@echo "$$($(RED))************************$$($(END))"
	@rm -f $(NAME)

re: fclean all