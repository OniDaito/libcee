# Project details
project('cee', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17', 'werror=false'])

# Globals and constants
project_dir  = meson.current_source_dir() # MESON_SOURCE_ROOT
build_dir    = meson.current_build_dir() # MESON_BUILD_ROOT
compiler = meson.get_compiler('cpp')

build_args = [
]

pkg = import('pkgconfig')

# Debug or release
if get_option('buildtype') == 'debug'
  add_project_arguments('-DDEBUG', language : 'cpp')
endif

if get_option('buildtype') == 'release'
  add_project_arguments('-O3', language : 'cpp')
  add_project_arguments('-msse3', language : 'cpp')
  add_project_arguments('-ffast-math', language : 'cpp')
  add_project_arguments('-march=native', language : 'cpp')
endif

# External dependencies we assume the user has installed
# Most are installable on Linux but several need to be built under windows
# So I have included built versions in this repository.
message(['Building for', target_machine.system()])

# If we are under linux, add all these as external deps
if target_machine.system() == 'linux'
endif

# The include directories for the dependencies inside this project
include_dirs = [
  include_directories('include')
]

# Declare varible for subproject inclusion
libcee_includes = declare_dependency(include_directories: include_directories('include'))

if target_machine.system() == 'windows'
endif

build_args += [
  '-DPROJECT_NAME=' + meson.project_name(),
  '-DPROJECT_VERSION=' + meson.project_version(),
]


# The see Library itself
cee_lib = library('cee', sources : [
  'src/file.cpp',
  ],
  include_directories : include_dirs,
  link_args : '-Wl,-lstdc++fs,-lpthread',
  c_args : build_args,
  install : true,
 )

pkg.generate(cee_lib)

# Installer
headers = [ 'include/file.hpp',
'include/macros.hpp',
'include/math.hpp',
'include/string.hpp',
'include/threadpool.hpp',
 ]
install_headers(headers, subdir : 'libcee')

