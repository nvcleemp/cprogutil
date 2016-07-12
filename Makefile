all: build/libcprogutil.a headers

headers: build/queue.h build/unionfind.h build/boolean.h build/bitset.h\
         build/allocate_sprint.h

build/libcprogutil.a: build/queue.o build/unionfind.o build/allocate_sprint.o
	ar rcs $@ $^

build/%.o: %.c
	mkdir -p build
	cc -c $^ -o $@ -O3 -Wall

build/%.h: %.h
	mkdir -p build
	cp $^ $@
