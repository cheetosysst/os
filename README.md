# OS

## build
Install qemu and make sure you can run `qemu-system-i386`.
```sh
make clean
make # Runs qemu after build complete.

make debug # Runs qemu with debug server.
make gdb # Runs gdb and connect with qemu.
```