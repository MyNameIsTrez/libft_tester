# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/22 18:42:17 by sbos          #+#    #+#                  #
#    Updated: 2022/04/22 18:53:57 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

LIBFT := libft/libft.a

CC := cc

OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror
CFLAGS += -O3 # -O1 adds tail recursion detection

HEADERS := libft/libft.h tests/libft_tests.h $(addprefix $(HOME)/Documents/Programming/libctester/, $(shell $(MAKE) -C $(HOME)/Documents/Programming/libctester/ -f headers.mk))
SOURCES := $(wildcard tests/**/*.c)

################################################################################

ifdef DEBUG
CFLAGS += -g3 -Wconversion
# CFLAGS += -fsanitize=address
endif

################################################################################

OBJECTS := $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

INCLUDES := $(sort $(addprefix -I, $(dir $(HEADERS))))

# Only cleans when MAKE_DATA changes.
DATA_FILE := .make_data
MAKE_DATA := $(CFLAGS) $(SOURCES)
ifneq ($(shell echo "$(MAKE_DATA)"), $(shell cat "$(DATA_FILE)" 2> /dev/null))
PRE_RULES := clean
endif

################################################################################

all: $(PRE_RULES) $(LIBFT) $(OBJECTS)
	@echo "$(MAKE_DATA)" > $(DATA_FILE)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(dir $(LIBFT)) DEBUG=1

.PHONY: all

################################################################################

clean:
	rm -rf $(OBJ_DIR)/

fclean: clean
	@$(MAKE) -C $(dir $(LIBFT)) fclean

re: fclean all

.PHONY: clean fclean re

################################################################################
