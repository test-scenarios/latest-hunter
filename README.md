# Hunter Latest

## Intention

Project to test latest Hunter

## Required toolchain

Some very good toolchains files available here:

https://github.com/ruslo/polly

in which case you can invoke cmake with:

`cmake -DCMAKE_TOOLCHAIN_FILE=<POLLY_DIR>/cxx17.cmake -H<SRC_DIR> -B<BUILD_DIR>`

Where:

* `POLLY_DIR` is the cloned polly repo
* `SRC_DIR` is the directory containing this file
* `BUILD_DIR` is the intended build directory (in-source builds are evil)
