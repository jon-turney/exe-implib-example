
#define DLL_PUBLIC __declspec(dllexport)

extern int func_from_executable(void);

int DLL_PUBLIC func(void) {
   return func_from_executable();
}
