COMPILER = g++
OPTIONS = -std=c++17 -Wall --pedantic-errors

TARGET = echoargs

SRC_SUFFIX = .cc
SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*$(SRC_SUFFIX))

HEADER_DIR = $(SRC_DIR)
HEADERS = $(wildcard $(HEADER_DIR)/*.h)
PRECOMPILED_HEADER_SUFFIX = .gch
PRECOMPILED_HEADERS = $(addsuffix $(PRECOMPILED_HEADER_SUFFIX), $(HEADERS))

.PHONY: run
run: $(TARGET)
	./$(TARGET) $(ARGS)

.PHONY: clean
clean:
	rm -rf $(TARGET)
	rm -rf $(PRECOMPILED_HEADERS)

$(TARGET): $(PRECOMPILED_HEADERS) $(SRCS)
	echo $(PRECOMPILED_HEADERS)
	$(COMPILER) $(OPTIONS) -o $@ $(SRCS)

$(PRECOMPILED_HEADERS): $(HEADERS)
	$(COMPILER) $(OPTIONS) -x c++-header -o $@ $^