APPS = lps_manacher 
SRCS = $(addsuffix .c, $(APPS))
OBJS = $(addsuffix .o, $(APPS))

all: $(APPS)
.PHONY: all clean

lps_manacher: lps_manacher.o
	gcc $^ -o $@

%.o: %.c
	gcc -c $^ -o $@

clean:
	rm -f $(APPS) *.o 
