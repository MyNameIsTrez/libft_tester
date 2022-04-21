NAME := libtests.a
LIBFT := libft/libft.a

CC := cc

OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror
CFLAGS += -O3 # -O1 adds tail recursion detection

LIBS :=
HEADERS := libft/libft.h tests/libft_tests.h $(addprefix $(HOME)/Documents/Programming/libctester/, $(shell $(MAKE) -C $(HOME)/Documents/Programming/libctester/ -f headers.mk))
SOURCES := $(wildcard tests/**/*.c)

FCLEANED_FILES := $(NAME)


ifdef DEBUG
LIBS +=
HEADERS +=
CFLAGS += -g3 -Wconversion
# CFLAGS += -fsanitize=address
FCLEANED_FILES +=
endif

OBJECT_PATHS := $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

INCLUDES := $(sort $(addprefix -I, $(dir $(HEADERS))))

# Only cleans when MAKE_DATA changes.
DATA_FILE := .make_data
MAKE_DATA := $(CFLAGS) $(SOURCES)
ifneq ($(shell echo "$(MAKE_DATA)"), $(shell cat "$(DATA_FILE)" 2> /dev/null))
PRE_RULES := clean
endif

all: $(PRE_RULES) $(NAME)

$(NAME): $(LIBFT) $(OBJECT_PATHS)
#	@cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJECT_PATHS)
	@echo "$(MAKE_DATA)" > $(DATA_FILE)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(dir $(LIBFT)) DEBUG=1

clean:
	rm -rf $(OBJ_DIR)/

fclean: clean
	@$(MAKE) -C $(dir $(LIBFT)) fclean
	rm -f $(FCLEANED_FILES)

re: fclean all

.PHONY: all clean fclean re
