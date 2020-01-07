CC = g++
CFLAGS = -Wall -Wextra -Iinclude/Exec -Iinclude/Tools -Iinclude/Class -Iinclude/Class/GameScene -Iinclude/Class/Scene -std=c++11 -g -fsanitize=address
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

OBJS_COMMON = $(filter $(OBJS_DIR)/Common/%, $(OBJS))
OBJS_GAME = $(filter $(OBJS_DIR)/Game/%, $(OBJS))
OBJS_EDITMAP = $(filter $(OBJS_DIR)/EditMap/%, $(OBJS))
OBJS_EDITANIMATION = $(filter $(OBJS_DIR)/EditAnimation/%, $(OBJS))
OBJS_EDITASSETS = $(filter $(OBJS_DIR)/EditAssets/%, $(OBJS))

#editMap editAnimation editAssets
all: game editAnimation

$(OBJS_DIR)/%.o $(OBJS_DIR)/%.o.wasm: src/%.cpp Makefile
	@$(PRECOMPILE)
	$(CC) $(CFLAGS) -c -o $@ $<
	@$(POSTCOMPILE)

game: $(OBJS_GAME) $(OBJS_COMMON)
editMap: $(OBJS_EDITMAP) $(OBJS_COMMON)
editAnimation: $(OBJS_EDITANIMATION) $(OBJS_COMMON)
editAssets: $(OBJS_EDITASSETS) $(OBJS_COMMON)

game editMap editAnimation editAssets:
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf build

fclean: clean
	rm -rf game editMap editAnimation editAssets

re:
	$(MAKE) fclean
	$(MAKE) all

include $(wildcard $(DEPS_DIR)/**/*.d)

.PHONY: all clean fclean re test
