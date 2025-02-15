check_command() {
    if ! command -v "$1" &> /dev/null; then
        echo "Error: $1 is not installed. Install it with:"
        echo "  brew install $2"
        exit 1
    fi
}

check_command cmake cmake
check_command ninja ninja
check_command clang-format clang-format


echo "Checking Clang installation..."
if ! command -v clang &> /dev/null; then
    echo "Error: Clang is not installed. Please install Xcode Command Line Tools with: xcode-select --install"
    exit 1
fi

if ! command -v clang++ &> /dev/null; then
    echo "Error: Clang++ is not installed. Please install Xcode Command Line Tools with: xcode-select --install"
    exit 1
fi

echo "Setting up vcpkg..."

git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg install gtest
cd ..

echo "Configuring CMake ..."

mkdir -p build
cd build

cmake -G Ninja \
      -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake \
      -DCMAKE_C_COMPILER=$(xcrun --find clang) \
      -DCMAKE_CXX_COMPILER=$(xcrun --find clang++) \
      .. 

cd ..
  
