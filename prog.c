#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#if defined _WIN32 || defined __CYGWIN__
  #define DLL_PUBLIC __declspec(dllexport)
#else
  #if defined __GNUC__
    #define DLL_PUBLIC __attribute__ ((visibility("default")))
  #else
    #pragma message ("Compiler does not support symbol visibility.")
    #define DLL_PUBLIC
  #endif
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
    exit(1);
  }

#ifdef _WIN32
  FreeLibrary(h);
#else
  dlclose(h);
#endif
}

int DLL_PUBLIC
func_from_executable(void)
{
  return 42;
}
