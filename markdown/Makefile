all:a.out
objs := main.o markdown.o
a.out:$(objs) markdown.h
	cc  $(objs) -o $@ 

main.o:main.c

markdown.o:markdown.c

clean:
	@-rm *.o a.out
install:
	a.out sqm out.html
	cp out.html ~/tmp/out.html
