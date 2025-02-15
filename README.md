# C++ Project Template 

This repository provides a basic template for starting a new C++ project. 

## Depedencies 

# C++ Project Template

This repository provides a basic template for starting a new C++ project. It includes a structured directory layout, a CMake build system, and example source files.


## Dependencies and Features

- **Compiler/Interpreter**: Clang
- **Testing Framework**: Google Test
- **Dependency Manager**: vcpkg
- **Code Formatting**: Clang Format
- **Static Analysis Tool**: Clang Tidy
- **Code Coverage**: gcov

## Build Instructions 

Build instructions for linux machines


### Downloading Dependencies

```
sudo apt-get update
sudo apt-get install -y ninja-build clang llvm lcov curl python3
sudo ln -sf $(which llvm-cov) /usr/bin/gcov            
sudo apt-get install -y software-properties-common lsb-release wget
wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc | sudo apt-key add -
sudo apt-add-repository 'deb https://apt.kitware.com/ubuntu/ focal main'
sudo apt-get update
sudo apt-get install -y cmake
python3 -m pip install pre-commit
cmake --version
```

Downloading Vcpkg: 

Vcpkg is a package manager for C++ that simplifies the process of managing dependencies. To set up vcpkg, run the following commands in the home directory:


```sh
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg install gtest
cd ..
```

### Setting Up Pre-Commit 

[Pre-Commit](https://pre-commit.com/) is a framework for managing and maintaining multi-language pre-commit hooks. It helps ensure code quality by running linters and formatters before commits. To customize the pre-commits edit the `.pre-commit-config.yaml` file

The pre-commits are currently only configure to run clang-format on all changed files. 

Currently, the pre-commit hooks are configured to run `clang-format` on all changed files to ensure consistent code formatting before commits.

```sh
pre-commit install
```



### Configuring Cmake with Ninja 
[Ninja](https://ninja-build.org/) is a small, fast build system that is designed to be used with CMake and other build tools.

```sh
mkdir -p build
cd build

cmake -G Ninja \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_TOOLCHAIN_FILE=${CIRCLE_WORKING_DIRECTORY}/vcpkg/scripts/buildsystems/vcpkg.cmake \
    -DVCPKG_TARGET_TRIPLET=x64-linux \
    -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ \
    ..

cd ..
```

### Building the Project Manually


```sh
cd build
ninja
cd ..
```

### Running Test 
```sh
cd build 
ctest -T Test
cd .. 
```


### Mac os 
These instructions are for macOS;

Ensure you have the following installed Xcode Command Line Tools, which includes clang
```sh
xcode-select --install
```

Install [Homebrew](https://docs.brew.sh/Installation) if you do not have it already installed. Homebrew is a package manager for macOS and Linux that simplifies the installation of software. Follow the link for installation guide and more information. 

The macOS commands are already included in the repository. Run the following scripts in the home directory to set up and build the project:

```sh
./scripts/mac/setup.sh
./scripts/mac/build.sh
```

## Setting Up CI/CD

This repository uses [CircleCI](https://circleci.com/) for continuous integration and deployment. CircleCI automates the build and testing process to ensure the project remains stable. Follow the instructions in the link to set up CircleCI.

The CircleCI configuration and settings can be found in the `.circleci` directory of this repository. The configuration file `.circleci/config.yml` defines the build steps, dependencies, and test execution process. 


## License

This project is licensed under the MIT License 


  


