# Build

## Log set up in main

``` shell
cmake -H. -B_bld -DLOG_IN_DLL=OFF
cmake --build _bld
_bld/bar
```

Output on OSX:
- Darwin JiriMBP.local 16.7.0 Darwin Kernel Version 16.7.0: Tue Jan 30 11:27:06 PST 2018; root:xnu-3789.73.11~1/RELEASE_X86_64 x86_64 i386 MacBookPro11,2 Darwin
- clang version 5.0.0 (tags/RELEASE_500/final)
- Target: x86_64-apple-darwin16.7.0
- Thread model: posix
- InstalledDir: /Users/Jiri/anaconda/bin

``` shell
Loading dll
4
g3log g3FileSink shutdown at: 14:49:31 720365
Log file at: [logs/FOO.g3log.20180409-144931.log]
Unloading dll
```

## Log set up in dll

``` shell
cmake -H. -B_bld -DLOG_IN_DLL=ON
cmake --build _bld
_bld/bar
```

Output:

``` shell
Loading dll
Segmentation fault: 11
```



