#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

int
main (int argc, char **argv)
{
#ifdef _WIN32
  HMODULE h = LoadLibraryA(argv[1]);
#else
  void *h = dlopen(argv[1], RTLD_NOW);
#endif

  if (!h) {
    printf ("failed to load library\n");
  }

#ifdef _WIN32
  FreeLibrary(h);
#else
  dlclose(h);
#endif
}

int
func_from_executable(void)
{
  return 42;
}
