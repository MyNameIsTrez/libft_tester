# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/22 18:42:17 by sbos          #+#    #+#                  #
#    Updated: 2022/07/21 13:47:25 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

export DEBUG=1

LIBFT := libft/libft.a

LIBS := $(LIBFT)

LIBCTESTER_PATH := libctester

CC := cc

override TESTS_DIR := tests
OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror
CFLAGS += -O3 # -O1 or higher adds tail recursion detection.

ifdef DEBUG
CFLAGS += -g3 -Wconversion
endif

ifdef SAN
CFLAGS += -fsanitize=address
endif

HEADERS :=\
	$(TESTS_DIR)/libft_tests.h\
	$(addprefix $(HOME)/Documents/Programming/libctester/, $(shell $(MAKE) -C $(HOME)/Documents/Programming/libctester/ -f headers.mk get_headers))

################################################################################

SOURCES := $(shell find $(TESTS_DIR) -name "*.c")

OBJECTS := $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

INCLUDES := $(sort $(addprefix -I, $(dir $(HEADERS))))

################################################################################

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
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(dir $(LIBFT))

.PHONY: all

################################################################################

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(dir $(LIBFT)) fclean
	@$(MAKE) -C $(LIBCTESTER_PATH) fclean

re: fclean all

.PHONY: clean fclean re

################################################################################

get_libs:
	@echo $(LIBS)

.PHONY: get_libs

################################################################################
