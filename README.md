# Description
This repository contains the source code for the embedded operating system kernel I wrote for an independent study in my final semester
at Northeastern University. It is generally based on the [kernel specification from Bill Cowan's CS452 class at UWaterloo](http://www.cgl.uwaterloo.ca/wmcowan/teaching/cs452/w15/assignments/index.html). It runs on the Xilinx ZedBoard platform. 

The majority of th kernel code is in the `zedboard_os` directory. The other two directories contain the BSP generated
by the Xilinx SDK, but contain some small changes.

This code was originally hosted on a private repo owned by my school but was recently moved over to this location.

**Note** This will most likely only build/run for me since it requires a specific configuration of the Xilinx SDK, a
specific version of QEMU, and/or a ZedBoard with a specific FPGA build.

# Documentation
Documentation for the internal design and API of the kernel can be found [here](https://docs.google.com/document/d/18sXmxzo7YyZr7R91Oic_56EAQsgoXOu1wLV_5C1wiNw/edit?usp=sharing).
