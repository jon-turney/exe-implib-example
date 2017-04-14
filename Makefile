all:
	$(CC) $(CFLAGS) -o module.o -c module.c
	$(CC) $(CFLAGS) -o prog.o -c prog.c
	$(CC) $(CFLAGS) -o prog.exe prog.o -Wl,--export-all,--out-implib,libprog.exe.a
	$(CC) $(CFLAGS) -o cygmodule.dll module.o libprog.exe.a -shared -Wl,-soname,cygmodule.dll -Wl,--out-implib=libmodule.dll.a
