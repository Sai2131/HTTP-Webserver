bin      = httpserver
sources  = $(wildcard *.c)
objects  = $(sources:%.c=%.o)

cc       = clang
cflags   = -Wall -Wpedantic

all: $(bin)

$(bin): $(objects)
	$(cc) $(cflags) -o $@ $^

%.o : %.c
	$(cc) $(cflags) -c $< -o $@

clean:
	rm -f $(bin) $(objects)