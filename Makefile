# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/22 18:42:17 by sbos          #+#    #+#                  #
#    Updated: 2022/08/31 16:27:46 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

export DEBUG=1

################################################################################

LIBFT := libft/libft.a

LIBS := $(LIBFT)

LIBCTESTER_PATH := libctester

CC := cc

override TESTS_DIR := tests
OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror -Wconversion -Wpedantic -Wfatal-errors

################################################################################

ifdef DEBUG
CFLAGS += -g3
endif

ifdef SAN
CFLAGS += -fsanitize=address
endif

ifdef O3
CFLAGS += -O3
endif

################################################################################

INCLUDES_HEADERS :=\
	$(TESTS_DIR)/libft_tests.h\
	$(shell $(MAKE) -C $(HOME)/Documents/Programming/libctester/ -f headers.mk get_includes_headers)

#$(addprefix $(HOME)/Documents/Programming/libctester/, $(shell $(MAKE) -C $(HOME)/Documents/Programming/libctester/ -f headers.mk get_headers))

################################################################################

SOURCES := $(shell find $(TESTS_DIR) -name "*.c")

OBJECTS := $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

HEADERS += $(INCLUDES_HEADERS)

INCLUDES := $(sort $(addprefix -I, $(dir $(INCLUDES_HEADERS))))

################################################################################

# Only cleans when MAKE_DATA changes.
DATA_FILE := .make_data
MAKE_DATA := $(CFLAGS) $(SOURCES)
ifneq ($(shell echo "$(MAKE_DATA)"), $(shell cat "$(DATA_FILE)" 2> /dev/null))
PRE_RULES := clean
endif

################################################################################

.PHONY: all
all: $(PRE_RULES) $(LIBFT) $(OBJECTS)
	@echo "$(MAKE_DATA)" > $(DATA_FILE)

################################################################################

$(LIBFT):
	git submodule update --init --recursive
	@$(MAKE) -C $(dir $(LIBFT))

################################################################################

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

################################################################################

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	git submodule update --init --recursive
	@$(MAKE) -C $(dir $(LIBFT)) fclean
	@$(MAKE) -C $(LIBCTESTER_PATH) fclean

.PHONY: re
re: fclean all

################################################################################

.PHONY: get_libs
get_libs:
	@echo $(LIBS)

################################################################################
