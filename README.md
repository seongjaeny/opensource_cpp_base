# C++ Project Template 

This repository provides a basic template for starting a new C++ project. 

## Depedencies 

# C++ Project Template

This repository provides a basic template for starting a new C++ project. It includes a structured directory layout, a CMake build system, and example source files.

## Features

- Organized project structure
- CMake support for cross-platform builds
- Sample C++ source code
- Unit testing setup (GoogleTest)
- `.gitignore` for common C++ project files

## Dependencies

- **Compiler/Interpreter**: Clang
- **Testing Framework**: Google Test
- **Dependency Manager**: vcpkg
- **Code Formatting**: Clang Format
- **Static Analysis Tool**: Clang Tidy
- **Code Coverage**: gcov

## Build Instructions 

These instructions are for macOS; for other systems, please refer to platform-specific documentation to find equivalent commands. 

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


### Downloading Dependencies

```
brew install cmake ninja clang-format pre_commit
```

downloading vcpkg is a package manager for C++ that simplifies the process of managing dependencies. To set up vcpkg, run the following commands in the home directory:


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
      -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake \
      -DCMAKE_C_COMPILER=$(xcrun --find clang) \
      -DCMAKE_CXX_COMPILER=$(xcrun --find clang++) \
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

## License

This project is licensed under the MIT License 


  


