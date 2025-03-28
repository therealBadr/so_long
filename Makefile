NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS =	main.c \
	parsing.c \
	checks.c \
	checks2.c \
	belongs_to_set.c \
	ft_arrlen.c \
	ft_split.c \
	ft_strcmp.c \
	get_next_line.c \
	get_next_line_utils.c \
	rendering.c \
	error_handling.c \
	moves_cases.c \
	moves.c \
	close.c \
	parsing_helper.c

OBJS = $(SRCS:.c=.o)

# Map testing variables - CHANGED TO maps/invalids
MAPS_DIR = maps/invalids
MAPS = $(wildcard $(MAPS_DIR)/*.ber)
NUM_MAPS = $(words $(MAPS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Generate test targets for each invalid map
define MAP_TEST_TEMPLATE
test-invalid$(1):
	@echo "\n\033[1;34m=== Testing invalid map $$(word $(1),$$(MAPS)) ===\033[0m"
	@echo "\033[1;33mMap content:\033[0m"
	@cat $$(word $(1),$$(MAPS)) || (echo "\033[1;31mError displaying map\033[0m"; exit 1)
	@echo "\n\033[1;32mRunning so_long:\033[0m"
	@./$(NAME) $$(word $(1),$$(MAPS)) && (echo "\033[1;31mMap $$(word $(1),$$(MAPS)) should have failed but passed!\033[0m"; exit 1) \
	|| echo "\033[1;32mCorrectly rejected invalid map\033[0m"
endef

# Create test targets for each map
$(foreach i,$(shell seq 1 $(NUM_MAPS)),$(eval $(call MAP_TEST_TEMPLATE,$(i))))

# List all test targets
list-invalid-tests:
	@echo "\033[1;36mAvailable invalid map test targets:\033[0m"
	@for i in `seq 1 $(NUM_MAPS)`; do \
		echo "\033[1;33mmake test-invalid$$i\033[0m - $$(word $$i,$(MAPS))"; \
	done

# Test all invalid maps with display
test-all-invalids:
	@for i in `seq 1 $(NUM_MAPS)`; do \
		make test-invalid$$i; \
	done

.PHONY: all clean fclean re list-invalid-tests test-all-invalids $(addprefix test-invalid,$(shell seq 1 $(NUM_MAPS)))

# NAME = so_long
# CC = gcc
# FLAGS = -Wall -Wextra -Werror
# MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

# SRCS =	main.c \
# 	parsing.c \
# 	checks.c \
# 	checks2.c \
# 	belongs_to_set.c \
# 	ft_arrlen.c \
# 	ft_split.c \
# 	ft_strcmp.c \
# 	get_next_line.c \
# 	get_next_line_utils.c \
# 	rendering.c \
# 	error_handling.c \
# 	moves_cases.c \
# 	moves.c \
# 	close.c \
# 	parsing_helper.c \

# OBJS = $(SRCS:.c=.o)

# # Map testing variables - CHANGED TO maps_valid
# MAPS_DIR = maps_valid
# MAPS = $(wildcard $(MAPS_DIR)/*.ber)
# NUM_MAPS = $(words $(MAPS))

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(FLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# %.o: %.c so_long.h
# 	$(CC) $(FLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# # Generate test targets for each map
# define MAP_TEST_TEMPLATE
# test$(1):
# 	@echo "\n\033[1;34m=== Testing map $$(word $(1),$$(MAPS)) ===\033[0m"
# 	@echo "\033[1;33mMap content:\033[0m"
# 	@cat $$(word $(1),$$(MAPS)) || (echo "\033[1;31mError displaying map\033[0m"; exit 1)
# 	@echo "\n\033[1;32mRunning so_long:\033[0m"
# 	@./$(NAME) $$(word $(1),$$(MAPS)) || (echo "\033[1;31mMap $$(word $(1),$$(MAPS)) failed\033[0m"; exit 1)
# endef

# # Create test targets for each map
# $(foreach i,$(shell seq 1 $(NUM_MAPS)),$(eval $(call MAP_TEST_TEMPLATE,$(i))))

# # List all test targets
# list-tests:
# 	@echo "\033[1;36mAvailable test targets:\033[0m"
# 	@for i in `seq 1 $(NUM_MAPS)`; do \
# 		echo "\033[1;33mmake test$$i\033[0m - $$(word $$i,$(MAPS))"; \
# 	done

# # Test all maps with display
# test-all:
# 	@for i in `seq 1 $(NUM_MAPS)`; do \
# 		make test$$i; \
# 	done

# .PHONY: all clean fclean re list-tests test-all $(addprefix test,$(shell seq 1 $(NUM_MAPS)))

###

# NAME = so_long
# CC = gcc
# FLAGS = -Wall -Wextra -Werror
# MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

# SRCS =	main.c \
# 	parsing.c \
# 	checks.c \
# 	checks2.c \
# 	belongs_to_set.c \
# 	ft_arrlen.c \
# 	ft_split.c \
# 	ft_strcmp.c \
# 	get_next_line.c \
# 	get_next_line_utils.c \
# 	rendering.c \
# 	error_handling.c \
# 	moves_cases.c \
# 	moves.c \
# 	close.c \
# 	parsing_helper.c \

# OBJS = $(SRCS:.c=.o)

# # Map testing variables
# MAPS_DIR = maps_err
# MAPS = $(wildcard $(MAPS_DIR)/*.ber)
# NUM_MAPS = $(words $(MAPS))

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(FLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# %.o: %.c so_long.h
# 	$(CC) $(FLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# # Generate test targets for each map
# define MAP_TEST_TEMPLATE
# test$(1):
# 	@echo "\n\033[1;34m=== Testing map $$(word $(1),$$(MAPS)) ===\033[0m"
# 	@echo "\033[1;33mMap content:\033[0m"
# 	@cat $$(word $(1),$$(MAPS)) || (echo "\033[1;31mError displaying map\033[0m"; exit 1)
# 	@echo "\n\033[1;32mRunning so_long:\033[0m"
# 	@./$(NAME) $$(word $(1),$$(MAPS)) || (echo "\033[1;31mMap $$(word $(1),$$(MAPS)) failed\033[0m"; exit 1)
# endef

# # Create test targets for each map
# $(foreach i,$(shell seq 1 $(NUM_MAPS)),$(eval $(call MAP_TEST_TEMPLATE,$(i))))

# # List all test targets
# list-tests:
# 	@echo "\033[1;36mAvailable test targets:\033[0m"
# 	@for i in `seq 1 $(NUM_MAPS)`; do \
# 		echo "\033[1;33mmake test$$i\033[0m - $$(word $$i,$(MAPS))"; \
# 	done

# # Test all maps with display
# test-all:
# 	@for i in `seq 1 $(NUM_MAPS)`; do \
# 		make test$$i; \
# 	done

# .PHONY: all clean fclean re list-tests test-all $(addprefix test,$(shell seq 1 $(NUM_MAPS)))






# NAME = so_long
# CC = cc
# FLAGS = -Wall -Wextra -Werror
# MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

# SRCS =	main.c \
# 	parsing.c \
# 	checks.c \
# 	checks2.c \
# 	belongs_to_set.c \
# 	ft_arrlen.c \
# 	ft_split.c \
# 	ft_strcmp.c \
# 	get_next_line.c \
# 	get_next_line_utils.c \
# 	rendering.c \
# 	error_handling.c \
# 	moves_cases.c \
# 	moves.c \
# 	close.c \

# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(FLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# %.o: %.c so_long.h
# 	$(CC) $(FLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re