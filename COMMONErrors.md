
# 🔧 Common Build Errors & Fixes for Micronet++

## 1. ❌ VCPKG\_ROOT not set

**Error:**

```Terminal
VCPKG_ROOT not set, using default: /home/arjunpathania/vcpkg
```

**Fix:**

```bash
export VCPKG_ROOT=~/vcpkg
```

Add to your shell profile (`.bashrc`, `.zshrc`) for permanence.

---

### 2. ❌ Vcpkg Git baseline error

**Error:**

```Terminal
error: while checking out baseline from commit '984f9232...', failed to `git show` versions/baseline.json
fatal: path 'versions/baseline.json' exists on disk, but not in '984f9232...'
```

**Fix:**

```bash
cd $VCPKG_ROOT
git pull
git fetch
./bootstrap-vcpkg.sh
```

---

### 3. ❌ CMake cannot find build program

**Error:**

```Terminal
CMAKE_MAKE_PROGRAM is not set. You probably need to select a different build tool.
```

**Fix:**

```bash
sudo apt install build-essential
```

Or for Ninja:

```bash
sudo apt install ninja-build
cmake .. -G "Ninja"
```

---

### 4. ❌ CMAKE\_CXX\_COMPILER not set

**Error:**

```Terminal
CMAKE_CXX_COMPILER not set, after EnableLanguage
```

**Fix:**

```bash
sudo apt install g++
```

---

### 5. ❌ No SOURCES given to target

**Error:**

```Terminal
No SOURCES given to target: micronet
```

**Fix:**
Update `CMakeLists.txt` to include sources:

```cmake
file(GLOB_RECURSE SOURCES src/*.cpp)
add_library(micronet ${SOURCES})
```

---

### 6. ❌ Source directory missing CMakeLists.txt

**Error:**

```Terminal
The source directory "/home/arjunpathania/github" does not appear to contain CMakeLists.txt
```

**Fix:**
Run `cmake ..` from inside the `build/` directory:

```bash
mkdir -p build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
```

---
