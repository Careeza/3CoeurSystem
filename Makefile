CC = g++
CFLAGS = -Wall -Wextra -Iinclude -std=c++11 # -fsanitize=address
LDFLAGS = `sdl2-config --libs --cflags` -lSDL2_image -lSDL2_ttf -lm

BUILD_DIR = build
OBJS_DIR = $(BUILD_DIR)/objs
DEPS_DIR = $(BUILD_DIR)/deps

PRECOMPILE = mkdir -p $(dir $@)
POSTCOMPILE = sleep 0

ifndef NODEPS

PRECOMPILE += ;mkdir -p $(dir $(DEPS_DIR)/$*)
CFLAGS += -MT $@ -MMD -MP -MF $(DEPS_DIR)/$*.Td
POSTCOMPILE += ;mv -f $(DEPS_DIR)/$*.Td $(DEPS_DIR)/$*.d && touch $@

endif

include src.mk

OBJS = $(patsubst src/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))

OBJS_CLASS = $(filter $(OBJS_DIR)/Class/%, $(OBJS))
OBJS_GAME = $(filter $(OBJS_DIR)/Game/%, $(OBJS))

all: game

$(OBJS_DIR)/%.o $(OBJS_DIR)/%.o.wasm: src/%.cpp Makefile
	@$(PRECOMPILE)
	$(CC) $(CFLAGS) -c -o $@ $<
	@$(POSTCOMPILE)

game: $(OBJS_GAME) $(OBJS_CLASS)

game:
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf build

fclean: clean
	rm -rf game

re:
	$(MAKE) fclean
	$(MAKE) all

include $(wildcard $(DEPS_DIR)/**/*.d)

.PHONY: all clean fclean re test
