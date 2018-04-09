# Build

## Log set up in main

``` shell
cmake -H. -B_bld -DLOG_IN_DLL=OFF
cmake --build _bld
_bld/bar
```

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



