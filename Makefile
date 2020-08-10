BUILD_DIR="build"
BIN_DIR="bin"
LIB_DIR="lib"

all: release debug

release debug : $(BUILD_DIR)/Makefile
	@echo "Building" $@
	@$(MAKE) -C $(BUILD_DIR) config=$@ verbose=1

$(BUILD_DIR)/Makefile: premake.lua
	@echo " "
	@echo "Generating makefiles..."
	@echo " "
	@premake --file=premake.lua gmake

clean:
# 	premake --file=premake.lua $@
	@echo "Cleaning..."
	@rm -rf $(BIN_DIR)
	@rm -rf $(BUILD_DIR)
	@rm -rf $(LIB_DIR)

help: $(BUILD_DIR)/Makefile
	@$(MAKE) -C $(BUILD_DIR) $@

