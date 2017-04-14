project('shared module linked to symbol in executable', 'c')

dl = meson.get_compiler('c').find_library('dl', required : false)
m = shared_module('module', 'module.c')
e = executable('prog', 'prog.c', dependencies : dl)
test('test', e, args: m)
