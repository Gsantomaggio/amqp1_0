# amqp1_0

A work in progress AMQP 1.0 Message format parser in C

# Build

```shell
$ cmake .
$ make 
```

# Test

```shell
$ ctest --extra-verbose .
```

# Libfuzzy test

```shell
$ docker build -t c_ubuntu   -f Docker/Dockerfile .
$ docker run -it -v $(PWD):/client c_ubuntu /bin/bash
$ docker run -it -v $(PWD):/client c_ubuntu /bin/bash
$ ./fuzzing/tutorial/libFuzzer/install-deps.sh
$ rm CMakeCache.txt 
$ cmake .
$ make
$ ./fuzz/fuzz_amqp_app
```
