# BiscuitDB Developer Docs

**Table of Contents**

- [Getting Started](#getting-started)
- [Development](#development)

## Getting Started

Hi! Welcome to JU-DB Group.

### System setup

1. **GitHub** We use GitHub for all our development.
   - **Account** [Sign up](https://github.com/join) for a GitHub account. 
2. **OS** Make sure you are running [Ubuntu 20.04](https://releases.ubuntu.com/20.04/). If not, the recommended approach is to dual boot or to use a VM.
3. **IDE** We recommend [Visual Studio Code](https://code.visualstudio.com/download).
4. **Packages** Install using
   - Go to the folder: `cd ~/biscuitdb/script/installation`
   - Install all the necessary packages: `sudo bash ./packages.sh`

### Further reading

You should learn a little about the following:

1. [git](https://github.com/ju-db/biscuitdb/tree/master/docs/tech_git.md)
2. [C++ and how we use it](https://github.com/ju-db/biscuitdb/tree/master/docs/cpp_guidelines.md)

## Configuration

### CMake flags to know

- We try our best to list all available options in [CMakeLists.txt](https://github.com/ju-db/biscuitdb/blob/master/CMakeLists.txt). Search for `# HEADER CMake options and global variables.`

### CMake targets to know

- You should know these targets.
  - `biscuitdb`: Building will build the `biscuitdb` binary and all its dependencies. Running will run the DBMS.
  - `biscuitdb_benchmark`: Building will build and link the `biscuitdb` object file to the `benchmark` library. Running will run the benchmarks.
  - `test`: Building will run all unit tests using `gtest`.
  - `format`: Building will run the formatter `clang-format` on the codebase with our rules. Use this every time right before you commit and right before you make a pull request!
  - `check-format`: Building will check if the codebase is correctly formatted according to `clang-format` with our rules.
  - `check-clang-tidy`: Building will check if the codebase passes the `clang-tidy` static analyzer tests with our rules.
  - `check-lint`: Building will check if the codebase passes the `build-support/cpplint.py` checks.

If you run into issues, you may need your default `python` to point to a `python3` install. For example, add this to your `~/.zshrc`: `alias python=python3`

## Development

### Workflow

1. Check out the latest version of the biscuitdb repository.
   - `git checkout master`
   - `git pull upstream master`
2. Create a new branch.
   - `git checkout -b my_new_branch`
3. Work on your code. Add features, add documentation, add tests, add remove bugs, and so on.
4. Push your code.
   - Make sure you run tests locally! See below.
   - `git push -u origin my_new_branch`
5. Go to GitHub and open a [new pull request](https://github.com/ju-db/biscuitdb/compare).
6. When a pull request is opened, this triggers our Continuous Integration environment on circle-ci.
   - CI will clone the repo, apply your changes, and make sure that formatting, linting, tests, etc pass.
   - Code has to pass all the checks for it to be merged!

### Running tests locally

Use `make test` or `ninja test` to run inside your build folder.

### Benchmarks

1. Go to the folder: `cd ~/biscuitdb/build`
2. Generate optimized config with `cmake -GNinja .. -DCMAKE_BUILD_TYPE=Release`
3. Build project with `ninja`
4. Run `./biscuitdb_benchmark [...options]`
