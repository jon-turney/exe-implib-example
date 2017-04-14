project('shared module linked to symbol in executable', 'c')

dl = meson.get_compiler('c').find_library('dl', required : false)
e = executable('prog', 'prog.c', dependencies : dl, implib: true)
m = shared_module('module', 'module.c', link_with: e)
test('test', e, args: m)
