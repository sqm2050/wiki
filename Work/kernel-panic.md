Starting cores 0x3
[    0.000000] Linux version 2.6.32.27DreamV1.0-00017-gcdbf8c9 (sqm@sqm-juson) (gcc version 4.3.3 (Cavium Networks Version: 2_2_0 build3
[    0.000000] CVMSEG size: 8 cache lines (1024 bytes)
[    0.000000] Cavium Networks SDK-2.2
[    0.000000] bootconsole [early0] enabled
[    0.000000] CPU revision is: 000d0708 (Cavium Octeon+)
[    0.000000] Checking for the multiply/shift bug... no.
[    0.000000] Checking for the daddiu bug... no.
[    0.000000] Determined physical RAM map:
[    0.000000]  memory: 0000000000530000 @ 0000000000cb0000 (usable after init)
[    0.000000]  memory: 0000000004c00000 @ 0000000003400000 (usable)
[    0.000000]  memory: 0000000007c00000 @ 0000000008200000 (usable)
[    0.000000]  memory: 000000001f000000 @ 0000000020000000 (usable)
[    0.000000] Wasting 45472 bytes for tracking 812 unused pages
[    0.000000] Initrd not found or empty - disabling initrd
[    0.000000] Using passed Device Tree.
[    0.000000] Placing 0MB software IO TLB between a80000000340c000 - a80000000344c000
[    0.000000] software IO TLB at phys 0x340c000 - 0x344c000
[    0.000000] Zone PFN ranges:
[    0.000000]   DMA32    0x0000032c -> 0x0003c000
[    0.000000]   Normal   0x0003c000 -> 0x0003c000
[    0.000000] Movable zone start PFN for each node
[    0.000000] early_node_map[4] active PFN ranges
[    0.000000]     0: 0x0000032c -> 0x00000478
[    0.000000]     0: 0x00000d00 -> 0x00002000
[    0.000000]     0: 0x00002080 -> 0x00003f80
[    0.000000]     0: 0x00008000 -> 0x0000fc00
[    0.000000] Cavium Hotplug: Available coremask 0x0
[    0.000000] PERCPU: Embedded 3 pages/cpu @a8000000037e0000 s10112 r8192 d30848 u65536
[    0.000000] pcpu-alloc: s10112 r8192 d30848 u65536 alloc=4*16384
[    0.000000] pcpu-alloc: [0] 0 [0] 1 
[    0.000000] Built 1 zonelists in Zone order, mobility grouping on.  Total pages: 44658
[    0.000000] Kernel command line:  bootoctlinux 0x1dd00000 coremask=0x3 mtdparts=octeon_nor0:1m(BOOT),7m(LINUX),24m(CONFIG) console=t0
[    0.000000] PID hash table entries: 4096 (order: 1, 32768 bytes)
[    0.000000] Dentry cache hash table entries: 131072 (order: 6, 1048576 bytes)
[    0.000000] Inode-cache hash table entries: 65536 (order: 5, 524288 bytes)
[    0.000000] Primary instruction cache 32kB, virtually tagged, 4 way, 64 sets, linesize 128 bytes.
[    0.000000] Primary data cache 16kB, 64-way, 2 sets, linesize 128 bytes.
[    0.000000] Memory: 706432k/718016k available (4936k kernel code, 10976k reserved, 7029k data, 5312k init, 0k highmem)
[    0.000000] Hierarchical RCU implementation.
[    0.000000] NR_IRQS:453
[   16.716707] Calibrating delay loop (skipped) preset value.. 1200.00 BogoMIPS (lpj=6000000)
[   16.724948] Mount-cache hash table entries: 1024
[   16.729748] Checking for the daddi bug... no.
[   16.734303] SMP: Booting CPU01 (CoreId  1)...
[   16.738502] CPU revision is: 000d0708 (Cavium Octeon+)
[   16.738708] Brought up 2 CPUs
[   16.749151] NET: Registered protocol family 16
[   16.754202] PCIe: Initializing port 0
[   16.784507] PCIe: Port 0 aligning TLP counters as workaround to maintain ordering
[   16.823304] PCIe: Port 0 link active, 4 lanes
[   16.931897] PCIe: Port 1 not in root complex mode, skipping.
[   16.940995] bio: create slab <bio-0> at 0
[   17.036244] pci 0000:00:00.0: PME# supported from D0 D3hot D3cold
[   17.057188] pci 0000:00:00.0: PME# disabled
[   17.241479] pci 0000:01:01.0: PME# supported from D0 D3hot D3cold
[   17.262422] pci 0000:01:01.0: PME# disabled
[   17.356623] pci 0000:01:02.0: PME# supported from D0 D3hot D3cold
[   17.377566] pci 0000:01:02.0: PME# disabled
[   17.471762] pci 0000:01:03.0: PME# supported from D0 D3hot D3cold
[   17.492705] pci 0000:01:03.0: PME# disabled
[   17.586912] pci 0000:01:0a.0: PME# supported from D0 D3hot D3cold
[   17.607856] pci 0000:01:0a.0: PME# disabled
[   17.702055] pci 0000:01:0b.0: PME# supported from D0 D3hot D3cold
[   17.722998] pci 0000:01:0b.0: PME# disabled
[   17.817203] pci 0000:01:0c.0: PME# supported from D0 D3hot D3cold
[   17.838146] pci 0000:01:0c.0: PME# disabled
[   17.932342] pci 0000:01:0d.0: PME# supported from D0 D3hot D3cold
[   17.953284] pci 0000:01:0d.0: PME# disabled
[   18.047479] pci 0000:01:0e.0: PME# supported from D0 D3hot D3cold
[   18.068423] pci 0000:01:0e.0: PME# disabled
[   18.162618] pci 0000:01:0f.0: PME# supported from D0 D3hot D3cold
[   18.183561] pci 0000:01:0f.0: PME# disabled
[   18.923294] pci 0000:03:00.0: PME# supported from D0 D1 D3hot
[   18.943888] pci 0000:03:00.0: PME# disabled
[   20.394168] pci 0000:01:01.0: PCI bridge, secondary bus 0000:02
[   20.399927] pci 0000:01:01.0:   IO window: disabled
[   20.449920] pci 0000:01:01.0:   MEM window: disabled
[   20.484736] pci 0000:01:01.0:   PREFETCH window: disabled
[   20.565021] pci 0000:01:02.0: PCI bridge, secondary bus 0000:03
[   20.570778] pci 0000:01:02.0:   IO window: disabled
[   20.620678] pci 0000:01:02.0:   MEM window: 0xe0000000-0xefffffff
[   20.656625] pci 0000:01:02.0:   PREFETCH window: disabled
[   20.721892] pci 0000:01:03.0: PCI bridge, secondary bus 0000:04
[   20.727648] pci 0000:01:03.0:   IO window: disabled
[   20.777546] pci 0000:01:03.0:   MEM window: disabled
[   20.812362] pci 0000:01:03.0:   PREFETCH window: disabled
[   20.937672] pci 0000:01:0a.0: PCI bridge, secondary bus 0000:05
[   20.943429] pci 0000:01:0a.0:   IO window: disabled
[   20.993331] pci 0000:01:0a.0:   MEM window: disabled
[   21.028149] pci 0000:01:0a.0:   PREFETCH window: 0x000000f0000000-0x000000f5ffffff
[   21.095591] pci 0000:01:0b.0: PCI bridge, secondary bus 0000:06
[   21.101348] pci 0000:01:0b.0:   IO window: disabled
[   21.151245] pci 0000:01:0b.0:   MEM window: disabled
[   21.186061] pci 0000:01:0b.0:   PREFETCH window: disabled
[   21.311374] pci 0000:01:0c.0: PCI bridge, secondary bus 0000:07
[   21.317130] pci 0000:01:0c.0:   IO window: disabled
[   21.367032] pci 0000:01:0c.0:   MEM window: disabled
[   21.401850] pci 0000:01:0c.0:   PREFETCH window: 0x000000f6000000-0x000000fbffffff
[   21.529336] pci 0000:01:0d.0: PCI bridge, secondary bus 0000:08
[   21.535093] pci 0000:01:0d.0:   IO window: disabled
[   21.584991] pci 0000:01:0d.0:   MEM window: disabled
[   21.619808] pci 0000:01:0d.0:   PREFETCH window: 0x000000fc000000-0x00000101ffffff
[   21.747295] pci 0000:01:0e.0: PCI bridge, secondary bus 0000:09
[   21.753051] pci 0000:01:0e.0:   IO window: disabled
[   21.802953] pci 0000:01:0e.0:   MEM window: disabled
[   21.837771] pci 0000:01:0e.0:   PREFETCH window: 0x00000102000000-0x00000107ffffff
[   21.905213] pci 0000:01:0f.0: PCI bridge, secondary bus 0000:0a
[   21.910970] pci 0000:01:0f.0:   IO window: disabled
[   21.960868] pci 0000:01:0f.0:   MEM window: disabled
[   21.995683] pci 0000:01:0f.0:   PREFETCH window: disabled
[   22.060950] pci 0000:00:00.0: PCI bridge, secondary bus 0000:01
[   22.066707] pci 0000:00:00.0:   IO window: disabled
[   22.116606] pci 0000:00:00.0:   MEM window: 0xe0000000-0xefffffff
[   22.152555] pci 0000:00:00.0:   PREFETCH window: 0x000000f0000000-0x00000107ffffff
[   22.235017] PCI: Enabling device 0000:00:00.0 (0000 -> 0002)
[   22.735867] PCI: Enabling device 0000:01:02.0 (0000 -> 0002)
[   23.236716] PCI: Enabling device 0000:01:0a.0 (0000 -> 0002)
[   23.737563] PCI: Enabling device 0000:01:0c.0 (0000 -> 0002)
[   23.998243] PCI: Enabling device 0000:01:0d.0 (0000 -> 0002)
[   24.258922] PCI: Enabling device 0000:01:0e.0 (0000 -> 0002)
[   24.974890] Switching to clocksource OCTEON_CVMCOUNT
[   24.981308] NET: Registered protocol family 2
[   24.985600] IP route cache hash table entries: 8192 (order: 2, 65536 bytes)
[   24.992702] TCP established hash table entries: 32768 (order: 5, 524288 bytes)
[   25.000433] TCP bind hash table entries: 32768 (order: 5, 524288 bytes)
[   25.007569] TCP: Hash tables configured (established 32768 bind 32768)
[   25.013946] TCP reno registered
[   25.017287] NET: Registered protocol family 1
[   30.571924] /proc/octeon_perf: Octeon performance counter interface loaded
[   30.578975] octeon_wdt: Initial granularity 5 Sec.
[   30.583952] octeon_gpio 1070000000800.gpio-controller: probed
[   30.590812] squashfs: version 4.0 (2009/01/31) Phillip Lougher
[   30.596501] JFFS2 version 2.2. (NAND) (SUMMARY)  .. 2001-2006 Red Hat, Inc.
[   30.603618] msgmni has been set to 1380
[   30.607539] io scheduler noop registered
[   30.611334] io scheduler cfq registered (default)
[   30.616280] pci-stub: invalid id string ""
[   30.787514] octeon_rng octeon_rng: Octeon Random Number Generator
[   30.793579] Serial: 8250/16550 driver, 3 ports, IRQ sharing disabled
[   30.801847] brd: module loaded
[   30.807598] loop: module loaded
[   30.811089] mdio-octeon: probed
[   30.814775] mdio-octeon 1180000001800.mdio: Version 1.0
[   30.819986] mdio-octeon: probed
[   30.822979] mdio-octeon 1180000001900.mdio: Version 1.0
[   30.828682] octeon_mgmt 1070000100000.ethernet: Version 2.0
[   30.834408] octeon_mgmt 1070000100800.ethernet: Version 2.0
[   30.840068] i2c /dev entries driver
[   30.844184] i2c-octeon 1180000001000.i2c: version 2.0
[   30.849357] at24 0-0057: 256 byte 24c02 EEPROM (writable)
[   30.855366] i2c-octeon 1180000001200.i2c: version 2.0
[   30.860545] rtc-pcf8563 1-0051: chip found, driver version 0.4.3
[   30.866731] rtc-pcf8563 1-0051: rtc core: registered rtc-pcf8563 as rtc0
[   30.874915] i2c i2c-0: Added multiplexed i2c bus 2
[   30.880315] i2c i2c-0: Added multiplexed i2c bus 3
[   30.885649] i2c i2c-0: Added multiplexed i2c bus 4
[   30.891020] i2c i2c-0: Added multiplexed i2c bus 5
[   30.896076] i2c i2c-0: Added multiplexed i2c bus 6
[   30.901194] i2c i2c-0: Added multiplexed i2c bus 7
[   30.906241] i2c i2c-0: Added multiplexed i2c bus 8
[   30.911337] i2c i2c-0: Added multiplexed i2c bus 9
[   30.915969] pca954x 0-0070: registered 8 multiplexed busses for I2C switch pca9548
[   30.924260] i2c i2c-1: Added multiplexed i2c bus 10
[   30.929391] i2c i2c-1: Added multiplexed i2c bus 11
[   30.934542] i2c i2c-1: Added multiplexed i2c bus 12
[   30.939669] i2c i2c-1: Added multiplexed i2c bus 13
[   30.944874] i2c i2c-1: Added multiplexed i2c bus 14
[   30.950030] i2c i2c-1: Added multiplexed i2c bus 15
[   30.955172] i2c i2c-1: Added multiplexed i2c bus 16
[   30.960341] i2c i2c-1: Added multiplexed i2c bus 17
[   30.965058] pca954x 1-0071: registered 8 multiplexed busses for I2C switch pca9548
[   30.973336] i2c i2c-1: Added multiplexed i2c bus 18
[   30.978488] i2c i2c-1: Added multiplexed i2c bus 19
[   30.983662] i2c i2c-1: Added multiplexed i2c bus 20
[   30.988803] i2c i2c-1: Added multiplexed i2c bus 21
[   30.994019] i2c i2c-1: Added multiplexed i2c bus 22
[   30.999159] i2c i2c-1: Added multiplexed i2c bus 23
[   31.004323] i2c i2c-1: Added multiplexed i2c bus 24
[   31.009463] i2c i2c-1: Added multiplexed i2c bus 25
[   31.014233] pca954x 1-0072: registered 8 multiplexed busses for I2C switch pca9548
[   31.022436] i2c i2c-1: Added multiplexed i2c bus 26
[   31.027583] i2c i2c-1: Added multiplexed i2c bus 27
[   31.032753] i2c i2c-1: Added multiplexed i2c bus 28
[   31.037898] i2c i2c-1: Added multiplexed i2c bus 29
[   31.043124] i2c i2c-1: Added multiplexed i2c bus 30
[   31.048271] i2c i2c-1: Added multiplexed i2c bus 31
[   31.053475] i2c i2c-1: Added multiplexed i2c bus 32
[   31.058629] i2c i2c-1: Added multiplexed i2c bus 33
[   31.063359] pca954x 1-0073: registered 8 multiplexed busses for I2C switch pca9548
[   31.072245] tmp401 2-004c: Detected TI TMP411 chip
[   31.077989] tmp401 3-004c: Detected TI TMP411 chip
[   31.083782] tmp401 4-004c: Detected TI TMP411 chip
[   31.088614] TCP westwood registered
[   31.091949] NET: Registered protocol family 17
[   31.096442] L2 lock: TLB refill 256 bytes
[   31.100428] L2 lock: General exception 128 bytes
[   31.104979] L2 lock: low-level interrupt 128 bytes
[   31.109760] L2 lock: interrupt 640 bytes
[   31.113708] L2 lock: memcpy 1152 bytes
[   31.118395] 1180000000800.serial: ttyS0 at MMIO 0x1180000000800 (irq = 125) is a OCTEON
[   31.126293] console [ttyS0] enabled, bootconsole disabled
[   31.126293] console [ttyS0] enabled, bootconsole disabled
[   31.138358] 1180000000c00.serial: ttyS1 at MMIO 0x1180000000c00 (irq = 126) is a OCTEON
[   31.147684] 1180000000400.serial: ttyS2 at MMIO 0x1180000000400 (irq = 127) is a OCTEON
[   31.156339] Bootbus flash: Setting flash for 32MB flash at 0x1dc00000
[   31.162871] octeon_nor0: Found 1 x16 devices at 0x0 in 8-bit bank
[   31.168982]  Amd/Fujitsu Extended Query Table at 0x0040
[   31.174246] octeon_nor0: CFI does not contain boot bank location. Assuming top.
[   31.181580] number of CFI chips: 1
[   31.184989] cfi_cmdset_0002: Disabling erase-suspend-program due to code brokenness.
[   31.192767] 3 cmdlinepart partitions found on MTD device octeon_nor0
[   31.199134] Creating 3 MTD partitions on "octeon_nor0":
[   31.204382] 0x000000000000-0x000000100000 : "BOOT"
[   31.210238] 0x000000100000-0x000000800000 : "LINUX"
[   31.215968] 0x000000800000-0x000002000000 : "CONFIG"
[   31.223459] octeon-ethernet 2.0
[   31.226608] EtherPCI Enabled
[   31.229608] Memory range a800000001400000 - a8000000015fffff reserved for hardware
[   31.237247] Memory range a800000001600000 - a80000000161ffff reserved for hardware
[   31.244911] Memory range a800000001620000 - a80000000171ffff reserved for hardware
[   31.252790] Interface 0 has 4 ports (SGMII)
[   31.257113] Interface 2 has 4 ports (NPI)
[   31.261162] Interface 3 has 4 ports (LOOP)
[   31.275918] Memory range a800000001727800 - a800000001746bff reserved for hardware
[   31.294062] Memory range a800000001746c00 - a800000001765fff reserved for hardware
[   31.311811] Memory range a800000001766000 - a8000000017853ff reserved for hardware
[   31.329961] Memory range a800000001785400 - a8000000017a47ff reserved for hardware
[   31.337582] Force link up
[   31.340584] Memory range a8000000017a4800 - a8000000017c3bff reserved for hardware
[   31.348203] Force link up
[   31.351206] Memory range a8000000017c3c00 - a8000000017e2fff reserved for hardware
[   31.358827] Force link up
[   31.361833] Memory range a8000000017e3000 - a8000000018023ff reserved for hardware
[   31.369453] Force link up
[   31.372499] Memory range a800000001802400 - a8000000018217ff reserved for hardware
[   31.380495] Memory range a800000001821800 - a800000001840bff reserved for hardware
[   31.388483] Memory range a800000001840c00 - a80000000185ffff reserved for hardware
[   31.396502] Memory range a800000001860000 - a80000000187f3ff reserved for hardware
[   31.404527] Memory range a80000000187f400 - a80000000189e7ff reserved for hardware
[   31.413798] rtc-pcf8563 1-0051: low voltage detected, date/time is not reliable.
[   31.421240] rtc-pcf8563 1-0051: setting system clock to 2002-04-15 01:03:28 UTC (1018832608)
[   31.431632] Freeing unused kernel memory: 5312k freed
[   31.439144] Kernel panic - not syncing: Attempted to kill init!

*** NMI Watchdog interrupt on Core 0x01 ***
        $0      0x0000000000000000      at      0xffffffff81210008
        v0      0xffffffff80100b60      v1      0x0000000000000001
        a0      0xfffffffffffffffd      a1      0x0000000000000000
        a2      0xffffffff80cae6b8      a3      0x0000000000000001
        a4      0x0000000400000000      a5      0xa80000003ee88298
        a6      0xa80000003ef66c98      a7      0xffffffff80cae6b0
        t0      0x0000000000000000      t1      0x000000001000001f
        t2      0xa80000003ef6c000      t3      0x0000000000000000
        s0      0xffffffff81210000      s1      0xa8000000037e14e8
        s2      0x0000000000200200      s3      0x0000000000100100
        s4      0xffffffff80c2dbb8      s5      0x0000000000000002
        s6      0xffffffffffffffff      s7      0x0000000000000079
        t8      0x0000000000000000      t9      0xffffffff80119cc0
        k0      0x000000009c004370      k1      0xa80000003ef7fe60
        gp      0xa80000003ef7c000      sp      0xa80000003ef7fbe0
        s8      0xffffffff80c2e3f8      ra      0xffffffff8039c198
        err_epc 0xffffffff80100b80      epc     0xffffffff80100b80
        status  0x0000000010588ce4      cause   0x0000000040808800
        sum0    0x0000000000000000      en0     0x0000000000000000
*** Chip soft reset soon ***
