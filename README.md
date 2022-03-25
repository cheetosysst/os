# OS

## build
Install qemu and make sure you can run `qemu-system-i386`.
```sh
make clean
make # Runs qemu after build complete.

make debug # Runs qemu with debug server.
```

### VSCode `launch.json`
```json
{
	"configurations": [
		{
			"name": "kernel-debug",
			"type": "cppdbg",
			"request": "launch",
			"miDebuggerServerAddress": "127.0.0.1:26000",
			"program": "${workspaceFolder}/build/kernel_bin",
			"args": [],
			"stopAtEntry": false,
			"cwd": "${workspaceFolder}",
			"environment": [],
			"externalConsole": false,
			"logging": {
				"engineLogging": false
			},
			"MIMode": "gdb"
		}
	]
}
```