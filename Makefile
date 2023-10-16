BUILD=build
TARGET=bbb-playground

init:
	cmake -B $(BUILD)

build_project:
	cmake --build $(BUILD)

start:
	./$(BUILD)/$(TARGET)

clean:
	rm -rf $(BUILD)
