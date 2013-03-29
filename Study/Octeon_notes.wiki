1.  1:1映射
-------------------------------------------------------------------------------
	If 1:1 mapping is not used,memory is not mapped into the user segment .
	Instead it is accessed either via xkphys(for 64-bit applications)or via
	inline assembly code.Virtual address "0" (the first 1 MByte) is usually
	unmapped.If virtual address "0" is unmapped, a NULL pointer access will
	cause the core to crash because there is no TLB exception handler.

2. 报文进入
-------------------------------------------------------------------------------
  1) 获取wqe
	.wk =work;

  2) 获取数据地址
	dpp->data_h = (uint8_t *)cvmx_phys_to_ptr(dpp->wk->packet_ptr.s.addr);

  4) 检查获取vlan-tag，获取端口

	dpp->ipif = (eth->tag & ZXMX_VLAN_TAG_IPIF_MASK);			取出tag中的端口编号。
	在switch上:
	0	0 	0xfc0	1111 1100 0000
	0	1 	0xfc1	1111 1100 0001
	...
	0	23 	0xfd7	1111 1101 0111
	1	4	0xfd8	1111 1101 1000
	1	0	0xfd9	1111 1101 1001

3. 解析报文，填充dpp结构
-------------------------------------------------------------------------------

4. 报文发出
-------------------------------------------------------------------------------
  add:	add ruleset name1 acl 0 sip=192.168.10.0/24,dip=172.16.10.0/24,sport=25
	,dport=110,protocol=tcp,action=forword,slotgroup=0,outgroup=0

  sync: sync ruleset name1 acl

  出逻辑接口属性:
	typedef struct {
		uint64_t	if_l2_type: 2,
				vlan_id: 12,
	} zxmx_elia_one_t;
	
	typedef struct __elia{
		zxmx_elia_one_t		data[26];
	} zxmx_elia_t;

  出逻辑接口组:
	typedef union _elif_grp {
		struct {
			uint16_t rsv : 6,
				slot_grp : 4,
				epif_grp : 6;
		};
		uint16_t data_16;
	} elif_grp_t;

	dpp->elia = &pgsif->elia.data[dpp->elif];

  流输出接口组:
	typedef struct _eig_one {
		uint8_t         vpifnum;	/* 本组一共有多少个出口 */
		uint8_t         pifid[26];
	} zxmx_eig_one_t;

	typedef struct _eig {
		zxmx_eig_one_t          data[64];
	} zxmx_eig_t;
