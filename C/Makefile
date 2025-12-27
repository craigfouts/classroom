CC := cc
CFLAGS := -std=c23 -Wall -Wextra -pedantic $(shell pkg-config --cflags SDL3)
LDFLAGS := $(shell pkg-config --libs SDL3)
BIN := ./bin
OBJ := ./obj
SRC := ./src
SRCS := $(foreach x, $(SRC), $(wildcard $(addprefix $(x)/*,.c*)))
OBJS := $(addprefix $(OBJ)/, $(addsuffix .o, $(notdir $(basename $(SRCS)))))
TARGET := $(BIN)/out
CLEAN := $(OBJS) $(TARGET)

default: makedir all

.PHONY: makedir
makedir:
	@mkdir -p $(BIN) $(OBJ)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	@rm -f $(CLEAN)

$(TARGET): $(OBJS) 
	@$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.c*
	@$(CC) -o $@ -c $< $(CFLAGS)
