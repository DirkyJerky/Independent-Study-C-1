CC := g++ 
SRCDIR := src
BINDIR := bin
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.exe))
CFLAGS := -g # -Wall

$(BINDIR)/%.exe: $(SRCDIR)/%.$(SRCEXT)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	echo " Cleaning..."; 
	$(RM) -r $(BINDIR)


.PHONY: clean
