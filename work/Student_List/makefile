cc=gcc
target=main
obj=main.o List1.o List2.o
$(target):$(obj)
	$(cc) $(obj) -Wall -o $(target)
main.o:main.c
	$(cc) -c main.c
List1.o:List1.c
	$(cc) -c List1.c
List2.o:List2.c
	$(cc) -c List2.c
.PHONY:clean
clean:
	rm -rf $(obj)
