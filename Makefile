SRCDIR := src
INCDIR := include
OBJDIR := obj

TARGET := huffman-coding

CC := g++
CFLAGS := -Wall -Wextra -Werror -I$(INCDIR) -std=c++17 -g

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(OBJECTS) -O $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@


$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	- mkdir -p $(BINDIR)

clean:
	rm -f $(OBJECTS) $(DEPS)

distclean : clean


-include $(DEPS



-PHONY: all clean distclean)
