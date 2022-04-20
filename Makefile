# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/04 14:13:59 by sbos          #+#    #+#                  #
#    Updated: 2022/04/20 14:20:27 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

PROJECT_NAME := libft

################################################################################

MAKEFILE_DIR := $(PROJECT_NAME)

export DEBUG := 1
include $(MAKEFILE_DIR)/Makefile

################################################################################

TESTS_DIR := tests
TESTS_OBJ_DIR := obj_tests

MASSERT_DIR := libmassert
CTESTER_DIR := libctester

TESTER := tester

TESTER_HEADERS :=												\
	$(addprefix $(MAKEFILE_DIR)/, $(HEADERS))					\
	$(TESTS_DIR)/libft_tests.h									\
	$(MASSERT_DIR)/massert.h									\
	$(CTESTER_DIR)/libctester.h									\
	$(CTESTER_DIR)/src/unstable/libft_unstable.h				\
	$(CTESTER_DIR)/src/unstable/overwritten_headers/stdlib.h
# TODO: ^ Can this header be removed from here? If not, add the others from CTESTER_DIR?

MASSERT := $(MASSERT_DIR)/libmassert.a
CTESTER := $(CTESTER_DIR)/libctester.a

TESTER_LIB_NAMES :=			\
	$(MASSERT)				\
	$(CTESTER)				\
	$(MAKEFILE_DIR)/libft.a

################################################################################

TESTER_SOURCES := $(wildcard $(TESTS_DIR)/**/*.c) $(TESTS_DIR)/tester.c
TESTER_OBJECTS := $(patsubst $(TESTS_DIR)/%,$(TESTS_OBJ_DIR)/%,$(TESTER_SOURCES:.c=.o))

TESTER_INCLUDES := $(sort $(addprefix -I, $(dir $(TESTER_HEADERS))))

TESTER_LIB_FLAGS := $(sort $(addprefix -L,$(dir $(TESTER_LIB_NAMES)))) $(sort $(patsubst lib%,-l%,$(basename $(notdir $(TESTER_LIB_NAMES)))))

PROJECT_MAKEFILE_ENTRY := all
PROJECT_MAKEFILE_ENTRY_SHORTCUT := foo$(PROJECT_MAKEFILE_ENTRY)

################################################################################

$(PROJECT_MAKEFILE_ENTRY_SHORTCUT):
	$(MAKE) -C $(MAKEFILE_DIR) $(PROJECT_MAKEFILE_ENTRY)

.DEFAULT_GOAL := $(TESTER)
$(TESTER): $(PROJECT_MAKEFILE_ENTRY_SHORTCUT) $(MASSERT) $(CTESTER) $(TESTER_OBJECTS)
	$(CC) $(CFLAGS) $(TESTER_INCLUDES) -g3 $(TESTER_OBJECTS) $(TESTER_LIB_FLAGS) -o $(TESTER)

$(TESTS_OBJ_DIR)/%.o: $(TESTS_DIR)/%.c $(TESTER_HEADERS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(TESTER_INCLUDES) -c $< -o $@

.PHONY: $(PROJECT_MAKEFILE_ENTRY_SHORTCUT)

################################################################################

$(MASSERT):
	$(MAKE) -C $(MASSERT_DIR)

$(CTESTER):
	$(MAKE) -C $(CTESTER_DIR)

.PHONY: $(MASSERT) $(CTESTER)

################################################################################

fclean_t:
	rm -rf $(TESTS_OBJ_DIR)
	rm -f $(TESTER)
	$(MAKE) -C $(MAKEFILE_DIR) fclean
	$(MAKE) -C $(MASSERT_DIR) fclean
	$(MAKE) -C $(CTESTER_DIR) fclean

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
