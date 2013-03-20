
1. ~/Documents/flow_md/sdk/OCTEON-SDK/linux
   ./copy-se2kernel.sh copy ~/Documents/flow_md/linux/OpenWRT/build_dir/linux-octeon-dream/linux-2.6.32.27



2. cd ~/Documents/flow_md/sdk/OCTEON-SDK/tools
   cp ./mips64-octeon-linux-gnu/sys-root/usr/lib64/octeon2/libgcc_s.so.1 ./lib

3. arch/mips/cavium-octeon setup.c 263:error CVMX_BOARD_TYPE_DM6645B undeclared
   临时把这个宏改成CVMX_BOARD_TYPE_DM6335B
