all:a.out
objs := main.o markdown.o
a.out:$(objs)
	cc  $(objs) -o $@ 

main.o:main.c

markdown.o:markdown.c

clean:
	@-rm *.o a.out
