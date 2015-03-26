caught_src =					\
	$(wildcard *.c)				\
	$(wildcard *.cc)			\
	$(wildcard *.hs)			\
	$(wildcard *.py)

primes_src =					\
digit_breakdown.cc				\
factoring.cc					\
limiter.cc					\
primes.c					\
radixsort.cc					\
util.cc						\

primes = prime_gen.cc $(primes_src)

modules = Util.hs util.py $(primes)

depfiles = $(patsubst %,.deps/%.d,$(wildcard *.c *.cc))

src = $(filter-out $(modules), $(caught_src))

extras = $(wildcard *.in)

progs = $(basename $(src))
tarfiles = GNUmakefile Makefile $(modules) $(caught_src) $(extras)

RM += -r

CC = gcc
OPTIMIZATION = -O2 -ftree-vectorize -fopenmp -mtune=native
PIC = -fPIC
CFLAGS = $(OPTIMIZATION) $(PIC)
CXXFLAGS = $(OPTIMIZATION) $(PIC)

LDFLAGS = -fopenmp -L. -Wl,--rpath,.
LIB_LDLIBS = -lm -lstdc++
LDLIBS = -lprimes -lgmpxx -lgmp $(LIB_LDLIBS)

all: libprimes.so $(progs)

debug:
	$(MAKE) CXXFLAGS='-g' all

primes.c: prime_gen
	./prime_gen

prime_gen: LDLIBS = $(LIB_LDLIBS)

libprimes.so: $(addsuffix .o,$(basename $(primes_src)))

lib%.so: %.o
	$(CXX) $(LDFLAGS) -shared $^ -o $@ $(LIB_LDLIBS)
	chmod a-x $@

%.h.gch: %.h
	$(COMPILE.c) $<

%.hh.gch: %.hh
	$(COMPILE.cc) $<

%: %.py
	cp $< $@
	chmod +x $@

%: %.hs %.o
	ghc -O2 $@
	touch $@

%.hi: %.o
	touch $@

%.o: %.hs
	ghc -c $<

mostlyclean:
	$(RM) *~ *.bak *.pyc *.pyo __pycache__ core core.*

clean: mostlyclean
	$(RM) $(progs) *.o *.hi *.d *.gch

check: $(progs)
	for i in $^; do ./$$i; done

linecount:
	wc -l $(src)

.deps/%.cc.d: %.cc
	$(COMPILE.cc) -MM $< > $@

Makefile: $(wildcard *.hs)
	touch $@
	ghc -M $^

GNUmakefile: Makefile .deps/.stamp $(depfiles)

%/.stamp:
	mkdir -p $*
	touch $@

-include Makefile $(depfiles)


.PHONY: all check clean linecount mostlyclean
.SUFFIXES: .c .cc .hs .py .o
