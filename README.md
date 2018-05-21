# opencl-aes

## Introduction

*opencl-aes* program can accelerate the [AES](https://en.wikipedia.org/wiki/Advanced_Encryption_Standard) by opencl.
> Now, only windows platform is supported.

## Build

* `Install OpenCL SDK`
    
    Before build the `opencl-aes`, make sure that the OpenCL SDK had been installed.
    
    Which OpenCL SDK should be installed depend on which graphics card installed in your computer. Here are some 
    OpenCL SDK link.

    * [Intel SDK for OpenCL](https://software.intel.com/en-us/intel-opencl?cid=sem43700008897667710&intel_term=%2Bintel+%2Bopencl+driver&gclid=EAIaIQobChMI5J7cvaKW2wIVB7nACh2UjATLEAAYASAAEgLGy_D_BwE&gclsrc=aw.ds)
    * [Nvidia SDK for OpenCL](https://software.intel.com/en-us/intel-opencl?cid=sem43700008897667710&intel_term=%2Bintel+%2Bopencl+driver&gclid=EAIaIQobChMI5J7cvaKW2wIVB7nACh2UjATLEAAYASAAEgLGy_D_BwE&gclsrc=aw.ds)
    * [AMD SDK for OpenCL](https://www.amd.com/en-us/solutions/professional/hpc/opencl)

* Build `opencl-aes` by vs2017

    Open the `openclhelloworld.sln` and then build it, the executable file will be generated in `./Release` folder.



    
