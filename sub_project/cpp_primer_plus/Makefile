# 定义编译器和编译标志
CXX = g++
CXXFLAGS = -Wall -std=c++11


TARGET = build/c02_basic build/c04_type
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

SRCS_C03 = ./src/c03_type.cpp
OBJS_C03 = $(SRCS_C03:.cpp=.o)
build/c03_type: $(OBJS_C03)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_C03)


SRCS_C04 = ./src/c04_compound.cpp
OBJS_C04 = $(SRCS_C04:.cpp=.o)
build/c04_compound: $(OBJS_C04)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_C04)

SRCS_C05 = ./src/c05_loop.cpp
OBJS_C05 = $(SRCS_C05:.cpp=.o)
build/c05_loop: $(OBJS_C05)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_C05)




# 编译每个源文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# 清理生成的文件
clean:
	rm -f src/*.o build/*