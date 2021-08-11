# BiscuitDB

(todo: add logo)

-----------------

![build](https://github.com/biscuitdb/biscuitdb/actions/workflows/build_tests.yml/badge.svg?branch=master)
[![codecov](https://codecov.io/gh/biscuitdb/biscuitdb/branch/master/graph/badge.svg?token=JXXLWUDNOT)](https://codecov.io/gh/biscuitdb/biscuitdb)

BiscuitDB is a relational database management system developed by the Jadavpur University Database Group. The research goal of the BiscuitDB project is to develop high-performance system components that support autonomous operation and optimization as a first-class design principle. This project is highly inspired by CMU's
[NoisePage](https://noise.page/) and [HyPer](http://hyper-db.de) from Technical University of Munich.

## Key Features
* Nothing yet

## Quickstart
The BiscuitDB project is built and tested on **Ubuntu 20.04**.

```
git clone https://github.com/biscuitdb/biscuitdb.git
cd biscuitdb
sudo ./script/installation/packages.sh
mkdir build
cd build
cmake -GNinja -DCMAKE_BUILD_TYPE=Release ..
ninja biscuitdb
./bin/biscuitdb
```

To run the unit tests provided, 

```
$ cd build
$ cmake -GNinja -DCMAKE_BUILD_TYPE=Release ..
$ ninja
$ ./bin/biscuitdb_test
```

To run the benchmarks,
Note: `-DCMAKE_BUILD_TYPE=Release` is needed

```
$ cd build
$ cmake -GNinja -DCMAKE_BUILD_TYPE=Release ..
$ ninja
$ ./bin/biscuitdb_benchmark
```

Before pushing or making a pull request  ( The tests must pass, compulsory !! )

```
$ ninja
$ ninja check-format
$ ninja check-clang-tidy
$ ninja check-lint
$ ninja test
```

Additional Notes:
- If you know what you're doing, install the prerequisite packages from `./script/installation/packages.sh` manually.


## For Developers

Please see the [docs](https://github.com/biscuitdb/biscuitdb/tree/master/docs/).  

## Contributing

If you are willing to contribute
  - Get in touch with anyone from the biscuitdb group.

Contributions from everyone are welcome!
