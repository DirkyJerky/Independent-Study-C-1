CC := gcc
SRCDIR := src
BINDIR := bin
 
SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
TARGETS := $(patsubst $(SRCDIR)/%,$(BINDIR)/%,$(SOURCES:.$(SRCEXT)=.exe))
CFLAGS := -g # -Wall

$(BINDIR)/%.exe: $(SRCDIR)/%.$(SRCEXT)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	echo " Cleaning..."; 
	$(RM) -r $(BINDIR)

all: $(TARGETS)
	@true

.PHONY: clean all
