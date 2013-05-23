U-Boot 2011.03-00025-gb546673-dirty (Development build, svnversion: u-boot:exported, exec:exported) (Build time: Mar 12 2012 - 14:28:10)

BIST check passed.
WARNING!!!!!!: DDR Clock Rate (tCLK) exceeds DIMM specifications!!!!!!!!
Warning: Board descriptor tuple not found in eeprom, using defaults
DM5220 board revision major:1, minor:0, serial #: dm5220
OCTEON CN5220-CP pass 2.0, Core clock: 600 MHz, DDR clock: 400 MHz (800 Mhz data rate)
Base DRAM address used by u-boot: 0x41f800000, size: 0x800000
DRAM: 1 GiB
Clearing DRAM........ done
Flash: 32 MiB
Starting PCIE
PCIe: Port 0 link active, 4 lanes
PCIe: port=0, first_bus=0, last_bus=0,
        mem_base=0xe0000000, mem_size=0x10000000, io_base=0x1000, io_size=0xff000
PCIe: ERROR: cvmx_pcie_rc_initialize() called on port1, but port1 is disabled
Net:   octmgmt0, octmgmt1, octeth0, octeth1, octeth2, octeth3
Hit any key to stop autoboot:  0 
argv[2]: coremask=0x3
argv[3]: mem=700
## No elf image at address 0x1dd00000
   Uncompressing LZMA ...  
Allocating memory for ELF segment: addr: 0xffffffff80100000 (adjusted to: 0x100000), size 0x10eb2f0
Allocated memory for ELF segment: addr: 0xffffffff80100000, size 0x10eb2f0
Processing PHDR 0
## Loading Linux kernel with entry point: 0xffffffff80105c70 ...
Bootloader: Done loading app on coremask: 0x3
Starting cores 0x3
[    0.000000] Linux version 2.6.32.27DreamV1.0-00057-g9b3ab39 (ShadowStar@liuleideMacBookPro.local) (gcc version 4.3.3 (Cavium Network2
[    0.000000] CVMSEG size: 8 cache lines (1024 bytes)
[    0.000000] Cavium Networks SDK-2.2
[    0.000000] bootconsole [early0] enabled
[    0.000000] CPU revision is: 000d0708 (Cavium Octeon+)
[    0.000000] Checking for the multiply/shift bug... no.
[    0.000000] Checking for the daddiu bug... no.
[    0.000000] Determined physical RAM map:
[    0.000000]  memory: 00000000004f0000 @ 0000000000cb0000 (usable after init)
[    0.000000]  memory: 0000000004c00000 @ 0000000003200000 (usable)
[    0.000000]  memory: 0000000007c00000 @ 0000000008200000 (usable)
[    0.000000]  memory: 000000001f000000 @ 0000000020000000 (usable)
[    0.000000] Wasting 181888 bytes for tracking 3248 unused pages
[    0.000000] Initrd not found or empty - disabling initrd
[    0.000000] Using passed Device Tree.
[    0.000000] Placing 0MB software IO TLB between a80000000320e000 - a80000000324e000
[    0.000000] software IO TLB at phys 0x320e000 - 0x324e000
[    0.000000] Zone PFN ranges:
[    0.000000]   DMA32    0x00000cb0 -> 0x000f0000
[    0.000000]   Normal   0x000f0000 -> 0x000f0000
[    0.000000] Movable zone start PFN for each node
[    0.000000] early_node_map[4] active PFN ranges
[    0.000000]     0: 0x00000cb0 -> 0x000011a0
[    0.000000]     0: 0x00003200 -> 0x00007e00
[    0.000000]     0: 0x00008200 -> 0x0000fe00
[    0.000000]     0: 0x00020000 -> 0x0003f000
[    0.000000] Cavium Hotplug: Available coremask 0x0
[    0.000000] PERCPU: Embedded 10 pages/cpu @a800000003ffd000 s10112 r8192 d22656 u65536
[    0.000000] pcpu-alloc: s10112 r8192 d22656 u65536 alloc=16*4096
[    0.000000] pcpu-alloc: [0] 0 [0] 1 
[    0.000000] Built 1 zonelists in Zone order, mobility grouping on.  Total pages: 175956
[    0.000000] Kernel command line:  bootoctlinux 0x1dd00000 coremask=0x3 mtdparts=octeon_nor0:1m(BOOT),7m(LINUX),24m(CONFIG) console=t0
[    0.000000] PID hash table entries: 4096 (order: 3, 32768 bytes)
[    0.000000] Dentry cache hash table entries: 131072 (order: 8, 1048576 bytes)
[    0.000000] Inode-cache hash table entries: 65536 (order: 7, 524288 bytes)
[    0.000000] Primary instruction cache 32kB, virtually tagged, 4 way, 64 sets, linesize 128 bytes.
[    0.000000] Primary data cache 16kB, 64-way, 2 sets, linesize 128 bytes.
[    0.000000] Memory: 696320k/717760k available (4932k kernel code, 21004k reserved, 7034k data, 5056k init, 0k highmem)
[    0.000000] Hierarchical RCU implementation.
[    0.000000] NR_IRQS:453
[   16.491305] Calibrating delay loop (skipped) preset value.. 1200.00 BogoMIPS (lpj=6000000)
[   16.499559] Mount-cache hash table entries: 256
[   16.504250] Checking for the daddi bug... no.
[   16.508834] SMP: Booting CPU01 (CoreId  1)...
[   16.513034] CPU revision is: 000d0708 (Cavium Octeon+)
[   16.513240] Brought up 2 CPUs
[   16.523753] NET: Registered protoco2c bus 29
[   31.169414] i2c i2c-1: Added multiplexed i2c bus 30
[   31.174577] i2c i2c-1: Added multiplexed i2c bus 31
[   31us mode
[   46.023723] br-lan: port 1(eth1) entering disabled
