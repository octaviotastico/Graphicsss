TARGET = graphics

CC = g++
CFLAGS = -Werror -Wextra -Wall -g -O3 -pthread

OUTDIR = ./build

SUBDIR := $(wildcard src/**/.)
SUBDIR += src
SUBDIR += tests

INC_DIRS = -I./ $(addprefix -I, $(SUBDIR))

LIBS = -lm -lpthread -lsfml-graphics -lsfml-window -lsfml-system

INCS = $(wildcard *.hpp $(foreach fd, $(SUBDIR), $(fd)/*.hpp))

SRCS = $(wildcard *.cpp $(foreach fd, $(SUBDIR), $(fd)/*.cpp))
NODIR_SRC = $(notdir $(SRCS))
OBJS = $(addprefix $(OUTDIR)/, $(SRCS:cpp=o))

all: $(TARGET)

PHONY := $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $(OUTDIR)/$@ $(OBJS) $(LFLAGS) $(LIBS)

$(OUTDIR)/%.o: %.cpp $(INCS)
	mkdir -p $(@D)
	$(CC) -o $@ $(CFLAGS) -c $< $(INC_DIRS) $(LFLAGS) $(LIBS)

PHONY += clean
clean:
	rm -rf $(OUTDIR)

PHONY += echoes
echoes:
	@echo "INC files: $(INCS)"
	@echo "SRC files: $(SRCS)"
	@echo "OBJ files: $(OBJS)"
	@echo "LIB files: $(LIBS)"
	@echo "INC DIR: $(INC_DIRS)"
	@echo "LIB DIR: $(LIB_DIRS)"

.PHONY = $(PHONY)

