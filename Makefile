NAME	= fractol

CC	= gcc
FLAGS	= -Wall -Werror -Wextra -g

INCLUDE = -I$(HEADDIR) -I$(LFTHEAD) -I$(MLXHEAD)

LFTLIB	= -lft -L$(LFTDIR) 
LIBFT	= $(LFTDIR)libft.a
LFTDIR	= ./libft/
LFTHEAD = $(LFTDIR)includes/

MLXLIB	= -lmlx -L$(MLXDIR) -framework OpenGL -framework AppKit
MLX	= $(MLXDIR)libmlx.a
MLXDIR	= ./minilibx/
MLXHEAD = $(MLXDIR)

HEADLST = fractol.h
HEADDIR = ./includes/
HEADERS = $(addprefix $(HEADDIR), $(HEADLST))

SRCLST = main.c def_color.c draw_pix.c mandelbrot.c julia.c burningship.c\
	legenda.c key_events.c mouse_event.c key_events1.c celtic_julia.c heart.c\
	key_events2.c def_color1.c celtic_mandelbrot.c mandelbar.c  mandelbar_4.c\
	bird.c flower.c julia_3.c julia_4.c julia_5.c mandelbrot_3.c mandelbrot_4.c\
	mandelbrot_5.c init_fract.c key_events3.c choose_fract.c put_fract.c\
	distrib_fract.c distrib_fract_2.c draw_fractal.c init_mlx.c\
	init_param_fractals.c service.c mouse_move.c mouse_move_2.c\
	fract_threads.c

SRCDIR = ./srcs/
SRCS = $(addprefix $(SRCDIR), $(SRCLST))

OBJDIR = obj/
OBJLST = $(patsubst %.c, %.o, $(SRCLST))
OBJECTS	= $(addprefix $(OBJDIR), $(OBJLST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(MLX) $(OBJECTS)
	@$(CC) $(FLAGS) $(LFTLIB) $(MLXLIB) $(INCLUDE) $(OBJECTS) -o $(NAME)
	@echo "executable created"
	
$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "object dir created"

$(OBJDIR)%.o : $(SRCDIR)%.c $(HEADERS) $(HEADDIR)
	@$(CC) $(FLAGS) -c $(INCLUDE) $< -o $@
	@echo "recompiling"

$(LIBFT): $(LFTHEAD)
	@make -C $(LFTDIR)

$(MLX): $(MLXDIR)
	@make -C $(MLXDIR)

clean:
	@$(MAKE) -C $(LFTDIR) clean
	@$(MAKE) -C $(MLXDIR) clean
	@rm -rf $(OBJDIR)
	@echo "clean maked"
	
fclean: clean
	@rm -f $(MLX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@echo "fclean maked"

re: fclean all
