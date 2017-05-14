APPS = kmp kmp_improve
SRCS = $(addsuffix .c, $(APPS))
OBJS = $(addsuffix .o, $(APPS))

all: $(APPS)
.PHONY: all clean

kmp: kmp.o
	gcc $^ -o $@

kmp_improve: kmp_improve.o
	gcc $^ -o $@

%.o: %.c
	gcc -c $^ -o $@


clean:
	rm -f $(APPS) 
