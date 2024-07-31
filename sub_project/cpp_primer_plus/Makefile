# 定义编译器和编译标志
CXX = g++
CXXFLAGS = -Wall -std=c++11


TARGET = build/c02_basic
# 默认目标
all: build $(TARGET)

# 创建 build 目录
build:
	mkdir -p build

# 定义源文件和对象文件
SRCS_C02 = ./src/c02_basic.cpp
OBJS_C02 = $(SRCS_C02:.cpp=.o)
# 链接可执行文件
build/c02_basic: $(OBJS_C02)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_C02)

# 编译每个源文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# 清理生成的文件
clean:
	rm -f src/*.o build/*