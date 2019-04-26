# Compile
## Compile with GNU in Linux
```
$ aclocal
$ autoconf
$ autoheader
$ libtoolize --automake
$ automake –-add-missing

$ ./configure
$ make
```

## Compile with cmake in Linux/Windows
```
$ mkdir build
$ cd build
$ cmake -G "Visual Studio 15 Win64" ..
```