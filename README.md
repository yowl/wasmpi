
## Using c# and  Web Assembly wwith the WASI SDK to control the GPIO pins on a PI

Build with

### The C part
We need some C to fill in some gaps that the dotnet runtime defines but WASI SDK does not.  We won't use most of them so they are mostly stubs

`clang --target=wasm32-unknown-wasi -c wasi.c`

### The C# part

This requires https://github.com/dotnet/runtimelab/pull/1850 to be merged, then you need to follow the WASI SDK instructions at https://github.com/dotnet/runtimelab/blob/feature/NativeAOT-LLVM/docs/using-nativeaot/compiling.md#webassembly .  You can skip installing Emscripten 
as we are not using that here.

`dotnet publish -r browser-wasm -c Debug /p:TargetArchitecture=wasm /p:PlatformTarget=AnyCPU /p:MSBuildEnableWorkloadResolver=false --self-contained /p:WasiSdkPath=E:\wasi-sdk-14.0 /bl /p:WasmExtraLinkerArgs=wasi.o`




