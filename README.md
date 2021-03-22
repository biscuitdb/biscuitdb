# BiscuitDB

(todo: add logo)

-----------------

![build](https://github.com/ju-db/biscuitdb/actions/workflows/build_tests.yml/badge.svg?branch=master)
[![codecov](https://codecov.io/gh/ju-db/biscuitdb/branch/master/graph/badge.svg?token=JXXLWUDNOT)](https://codecov.io/gh/ju-db/biscuitdb)

BiscuitDB is a relational database management system developed by the Jadavpur University Database Group. The research goal of the BiscuitDB project is to develop high-performance system components that support autonomous operation and optimization as a first-class design principle. This project is highly inspired by CMU's
[NoisePage](https://noise.page/) and [HyPer](http://hyper-db.de) from Technical University of Munich.

## Key Features
* Nothing yet

## Quickstart
The BiscuitDB project is built and tested on **Ubuntu 20.04**.

```
git clone https://github.com/ju-db/biscuitdb.git
cd biscuitdb
sudo ./script/installation/packages.sh
mkdir build
cd build
cmake -GNinja -DCMAKE_BUILD_TYPE=Release ..
ninja biscuitdb
./bin/biscuitdb
```

Additional Notes:
- If you know what you're doing, install the prerequisite packages from `./script/installation/packages.sh` manually.


## For Developers

Please see the [docs](https://github.com/ju-db/biscuitdb/tree/master/docs/).  

## Contributing

If you are a current student at Jadavpur University,
  - Get in touch with anyone from the JU-DB group.

Contributions from everyone are welcome!
