#!/bin/bash

# Exit on error
set -e

# Define VCPKG root if not already set
if [ -z "$VCPKG_ROOT" ]; then
  export VCPKG_ROOT=~/vcpkg
  echo "VCPKG_ROOT not set, using default: $VCPKG_ROOT"
fi

# Ensure vcpkg baseline is available (Git fetch fix)
echo "🔄 Ensuring Vcpkg baseline is up to date..."
cd "$VCPKG_ROOT"
git fetch origin
git checkout master  # or the branch you're using
git pull
cd -

# Clean and rebuild
echo "🔄 Cleaning previous build..."
rm -rf build

echo "📁 Creating new build directory..."
mkdir build && cd build

echo "⚙️ Configuring with CMake and Vcpkg..."
cmake .. -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake

echo "🛠️ Building the project..."
cmake --build .

echo "✅ Build complete!"
