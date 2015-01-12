libpath=3rd/lua-5.2.3/src
all:
	gcc -o t test_lua.c -L$(libpath) -I$(libpath) -llua -lm -ldl
	

lib:makelua

makelua:
	cd 3rd/lua-5.2.3/src && make linux \
		#&& cp lua*.o ../../../lib/

clean:
	cd 3rd/lua-5.2.3/src && make clean 

