#obj=main.o
target=app
#makefile中自己维护的变量
#大写:系统维护的变量
src=$(wildcard ./*.c)
obj=$(patsubst ./%.c,./%.o,$(src))
CC = gcc
CPPFLAGS = -I
$(target):$(obj)
	$(CC) $(obj) -o $(target)

%.o:%.c
	$(CC) -c $< -o $@
.PHONY:clean#声明伪目标
clean:
	-rm # -:忽略命令，继续向下执行
	rm $(obj) $(target) -f

hello:
	echo "hello,makefile"
