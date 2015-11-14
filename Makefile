CXX = clang++
CXXFLAGS = -stdlib=libc++ \
-ansi \
-std=c++11 \
-Werror \
-pedantic-errors \
-Weverything \
-Wno-float-equal \
-Wno-sign-conversion\
-Wno-missing-prototypes \
-Wno-exit-time-destructors \
-Wno-shadow \
-Wno-c++98-compat \
-Wno-c++98-compat-pedantic \
-Wno-documentation

OUTDIR = ./build
TESTS_DEPS = tests/main.cpp

all: clean test

clean:
	rm -rf $(OUTDIR)/*

test: $(TESTS_DEPS)
	mkdir -p $(OUTDIR)
	$(CXX) $(CXXFLAGS) ./tests/main.cpp -o $(OUTDIR)/test.a -ferror-limit=1

lint: $(TESTS_DEPS)
	cppcheck -v ./clns.h --report-progress --enable=all