SRCDIR := src
INCDIR := include
OBJDIR := obj
BINDIR := bin
TESTDIR := tests

TARGET := huffman-code 

CC := g++
CFLAGS := -Wall -Wextra -I$(INCDIR) -I/usr/include/gtest -std=c++17 -g
LDFLAGS := -lgtest -lgtest_main -pthread

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
TEST_SOURCES := $(wildcard $(TESTDIR)/*.cpp)

OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
TEST_OBJECTS := $(patsubst $(TESTDIR)/%.cpp, $(OBJDIR)/%.o, $(TEST_SOURCES))

DEPS := $(OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

all: $(BINDIR)/$(TARGET) tests

$(BINDIR)/$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

tests: $(TEST_OBJECTS) | $(BINDIR)
	$(CC) $(TEST_OBJECTS) $(OBJECTS) -o $(BINDIR)/tests $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(DEPS)

distclean: clean
	rm -f $(BINDIR)/$(TARGET) $(BINDIR)/tests

-include $(DEPS)

.PHONY: all clean distclean tests

