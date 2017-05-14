APPS = kmp
SRCS = $(addsuffix .c, $(APPS))
OBJS = $(addsuffix .o, $(APPS))

all: $(APPS)
.PHONY: all clean

$(APPS): $(OBJS)
	gcc $< -o $@

$(OBJS): $(SRCS)
	gcc -c $<

clean:
	rm -f $(APPS) 
