
BUILD_DIR=$(shell mkdir -p ./install && cd -P ./install && pwd)
SOURCE_DIR=$(shell pwd)


all: cmake
	make -C $(BUILD_DIR) all


cmake:
	@if [ ! -d "$(BUILD_DIR)" ]; then mkdir -p $(BUILD_DIR); fi
	@cd $(BUILD_DIR); cmake "$(SOURCE_DIR)"


clean:
	rm -rf $(BUILD_DIR)