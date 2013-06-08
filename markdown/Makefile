export PATH:=.:${PATH}
all:a.out
objs := main.o markdown.o
a.out:$(objs) markdown.h css.h
	cc  $(objs) -o $@ 

main.o:main.c markdown.h css.h

markdown.o:markdown.c markdown.h

clean:
	@-rm *.o a.out
install: all
	a.out ~/wiki/Work/url_version.md out.html
	mv out.html ~/tmp/out.html
	make clean
