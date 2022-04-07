# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/04 14:13:59 by sbos          #+#    #+#                  #
#    Updated: 2022/04/07 17:24:09 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

PROJECT_NAME := libft

################################################################################

MAKEFILE_DIR := $(PROJECT_NAME)

export DEBUG := 1
include $(MAKEFILE_DIR)/Makefile
export NO_STATIC := 1

################################################################################

TESTS_DIR := tests
TESTS_OBJ_DIR := obj_tests

MASSERT_DIR := libmassert

TESTER := tester

# C_TESTER_DIR := /Users/sbos/Documents/Programming/c_tester

TESTER_HEADERS :=												\
	$(addprefix $(MAKEFILE_DIR)/, $(HEADERS))					\
	$(TESTS_DIR)/libft_tests.h									\
	$(MASSERT_DIR)/massert.h									\
	tests/unstable/overwritten_headers/stdlib.h

#	$(C_TESTER_DIR)/src/unstable/overwritten_headers/stdlib.h
#   ^ Can this header be removed from here? If not, add the others from C_TESTER_DIR?

MASSERT := $(MASSERT_DIR)/libmassert.a

TESTER_LIB_NAMES :=	\
	$(MASSERT)		\
	$(MAKEFILE_DIR)/libft.a

################################################################################

TESTER_SOURCES := $(wildcard $(TESTS_DIR)/**/*.c) $(TESTS_DIR)/tester.c
TESTER_OBJECTS := $(patsubst $(TESTS_DIR)/%,$(TESTS_OBJ_DIR)/%,$(TESTER_SOURCES:.c=.o))

TESTER_INCLUDES := $(sort $(addprefix -I, $(dir $(TESTER_HEADERS))))

TESTER_LIB_FLAGS := $(sort $(addprefix -L,$(dir $(TESTER_LIB_NAMES)))) $(sort $(patsubst lib%,-l%,$(basename $(notdir $(TESTER_LIB_NAMES)))))

START_OF_MAKEFILE := all
START_OF_MAKEFILE_SHORTCUT := foo$(START_OF_MAKEFILE)

################################################################################

$(START_OF_MAKEFILE_SHORTCUT):
	$(MAKE) -C $(MAKEFILE_DIR) $(START_OF_MAKEFILE)

.DEFAULT_GOAL := $(TESTER)
$(TESTER): $(START_OF_MAKEFILE_SHORTCUT) $(MASSERT) $(TESTER_OBJECTS)
	$(CC) $(CFLAGS) $(TESTER_INCLUDES) -g3 $(TESTER_OBJECTS) $(TESTER_LIB_FLAGS) -o $(TESTER)

$(TESTS_OBJ_DIR)/%.o: $(TESTS_DIR)/%.c $(TESTER_HEADERS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(TESTER_INCLUDES) -c $< -o $@

.PHONY: $(START_OF_MAKEFILE_SHORTCUT)

################################################################################

$(MASSERT):
	$(MAKE) -C $(MASSERT_DIR)

.PHONY: $(MASSERT)

################################################################################

fclean_t:
	rm -rf $(TESTS_OBJ_DIR)
	rm -f $(TESTER)
	$(MAKE) -C $(MAKEFILE_DIR) fclean
	$(MAKE) -C $(MASSERT_DIR) fclean

re_t: fclean_t $(TESTER)

.PHONY: fclean_t re_t

################################################################################

# TODO: Add grep for KOs so they are much easier to spot
run_tests: run_test_1 run_test_2

run_test_1:
	make -C testers/libft-unit-test f

run_test_2:
	make -C testers/libftTester

.PHONY: run_tests run_test_1 run_test_2

################################################################################
