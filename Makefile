.PHONY: clean list 

IDIR := include
SDIR := src
ODIR := obj
CXX := clang++
CXXFLAGS := 
LDFLAGS := -Llibs/fmt/bin -lfmt
DEBUG := -g

_FLAGS := -Werror -Wall -std=c++17 -Ilibs -Iinclude

uniq = $(if $1,$(firstword $1) $(call uniq,$(filter-out $(firstword $1),$1)))

_DEPS = $(shell ls $(IDIR))
DEPS = $(patsubst %,$(IDIR)/% ,$(_DEPS))

_OBJ = $(shell ls $(SDIR))
OBJ = $(subst .cpp,.o,$(patsubst %,$(ODIR)/%,$(_OBJ)))

MYFILES := $(shell find . -type f -not -path "./.*" -not -path "./run/*" -not -path "*fmt*" -not -path "*obj*" | tr "\n" " " )
ALLFILES := $(MYFILES) $(shell find . -type f -not -path "./.*" -not -path "./run/*")
ALLFILES := $(call uniq,$(ALLFILES))

run/myopl: $(OBJ)
	@mkdir -p run
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) $(DEBUG) $(_FLAGS) myopl.cpp 

$(ODIR)/%.o : $(SDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(DEBUG) $(_FLAGS)

zip:
	zip myopl.zip $(ALLFILES) 
	
gz:
	@tar czvf myopl.tar.gz $(ALLFILES)

xz:
	@tar cJvf myopl.tar.xz $(ALLFILES) 

list:
	@wc -l $(MYFILES) 

tree:
	tree --charset=utf-8 -C

dist: clean zip gz xz 

clean:
	rm -f run/* main *.zip *.gz *.xz *.tar $(ODIR)/*.o

install: myopl
	install run/myopl /bin/myopl
