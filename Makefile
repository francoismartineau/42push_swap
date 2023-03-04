NAME = push_swap
SRCS_DIR = srcs/
SRCS = init/normalize.c \
	init/parse_arg.c \
	init/parse_arg_util.c \
	init/parse_args.c \
	operations/p.c \
	operations/r.c \
	operations/rr.c \
	operations/s.c \
	main.c \
	debug.c \
	runtime.c \
	sort/few.c \
	sort/to_b.c \
	sort/ranges.c \
	sort/ranges_util.c \
	sort/sort.c \
	stack/stack1.c \
	stack/stack2.c \
	stack/stack3.c \
	stack/stack4.c 
SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_DIRS = objs/
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIRS)%.o)
DEPS = $(OBJS:%.o=%.d)
BONUS_NAME = checker
BONUS_SRCS = apply_operations.c \
	main.c \
	operations/p.c \
	operations/r.c \
	operations/rr.c \
	operations/s.c 
BONUS_DIR = bonus/
BONUS_SRCS := $(BONUS_SRCS:%=$(SRCS_DIR)$(BONUS_DIR)%)
BONUS_OBJS := $(subst $(SRCS_DIR),$(OBJS_DIRS),$(BONUS_SRCS))
BONUS_OBJS := $(subst .c,.o,$(BONUS_OBJS))
BONUS_DEPS:= $(subst .o,.d,$(BONUS_OBJS))

CC = gcc
LIBFT_DIR = libft/
INCLUDE_DIR = include/
IQUOTES = $(addprefix -iquote, $(INCLUDE_DIR) $(LIBFT_DIR))
CFLAGS = -Wall -Werror -Wextra -MMD $(IQUOTES) -O3
# -g -fsanitize=address
LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@ $^

$(OBJS_DIRS)%.o:$(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(filter-out %main.o,$(OBJS))
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@ $^

$(BONUS_DIR)$(OBJS_DIRS)%.o:$(BONUS_DIR)$(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(MAKE) -C $(LIBFT_DIR) $@
	@rm -f $(OBJS) $(DEPS) $(BONUS_OBJS) $(BONUS_DEPS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) $@
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re

-include $(DEPS) $(BONUS_DEPS)