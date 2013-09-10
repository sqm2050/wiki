# acl_hfa
```
    acl_hfa_rule_t *rinfo;
    eprm_procs_act_fwd(dpp, rinfo->eif_grp, rinfo->fmt_en);
```
# acl
    zxmx_acl_act aa;
    eprm_procs_act_fwd(dpp, aa.elif_grp, aa.fmt);
# aclex
    zxmx_aclex_act aa;
    eprm_procs_act_fwd(dpp, aa.elif_grp, aa.fmt);

---------
```
static inline void zxmd_pkt_process(zxmx_dpim_packet *dpp){
	int ret;
#if defined(CONFIG_ACLMASK) || defined(CONFIG_ACLEX)
	zxmx_acl_act aa;
	aa.data_64 = ZXMX_ACL_ACTION_INVALID; //need_free_dpp
	uint32_t hit_aclid = ACL0_ID_UNVALID;
#endif
	/*
	 * PKT inspection
	 */
	dpim_decode(dpp);
	ZXMX_PRINTF_DEBUG("DPIM decode pkt type %u\n", dpp->pkt_type);
#ifdef CONFIG_INS706
	learn_pkt_mac(dpp);
	zxmx_elia_one_t *elia_info;
	elia_info = &pgsif->elia.data[dpp->ipif];
	if(elia_info->mact_en){
		if(cvmx_likely(procs_pkt_mact(dpp) == 0))
			return;
	}
	goto csps;
#endif
	/*
	 * PKTTYPE process
	 */
	ret = zxmd_pkttype_process(dpp);
	ZXMX_PRINTF_DEBUG("five tuples 0x%08x-0x%08x-0x%04x-0x%04x-0x%02x\n"
			, dpp->pkthdr.sip, dpp->pkthdr.dip
			, dpp->pkthdr.sp, dpp->pkthdr.dp, dpp->pkthdr.proto);
	switch(ret){
	case PKT_DEFLT:
		goto csps;
	case PKT_RETRN:
		return;
	case PKT_CONTNE:
	default:
		break;
	}
	/*********
	 * FMT
	 **********/
fmt_procs:;
#ifdef CONFIG_FMT
	  if(cvmx_unlikely((dpp->pkthdr.proto != IP_P_UDP)
				  && (dpp->pkthdr.proto != IP_P_TCP))) {
		  goto acl_procs;
	  }
	  ZXMX_PRINTF_DEBUG("The packet is tcp or udp, goto fmt\n");
	  ret = zxmd_fmt_process(dpp);
	  switch(ret){
	  case PKT_RETRN:
		  return;
	  case PKT_CONTNE:
	  default:
		  break;
	  }
#endif
	  /* ******
	   * SSN
	   * *******/
ssn_procs:
#ifdef CONFIG_SSN
	  if(cvmx_unlikely((dpp->pkthdr.proto != IP_P_UDP)
				  && (dpp->pkthdr.proto != IP_P_TCP))) {
		  goto acl_procs;
	  }
	  ZXMX_PRINTF_DEBUG("The packet is tcp or udp, goto ssn\n");
	  ret = zxmd_ssn_process(dpp);
	  switch(ret){
	  case PKT_RETRN:
		  return;
	  case PKT_CONTNE:
	  default:
		  break;
	  }
#endif
	  /********************
	   * ACL main process
	   *********************/
acl_procs:
	  ZXMX_PRINTF_DEBUG("begin to process acl.\n");
#ifdef CONFIG_ACL_HFA
	  ret = zxmd_acl_put_pkt_to_hfa(dpp);
	  switch(ret){
	  case PKT_DEFLT:
		  goto csps;
	  case PKT_RETRN:
		  return;
	  case PKT_CONTNE:
	  default:
		  break;
	  }
#endif
#ifdef CONFIG_ACLMASK
	  ret = zxmd_aclmask_process(dpp, &aa, &hit_aclid);
	  switch(ret){
	  case PKT_DEFLT:
		  goto csps;
	  case PKT_RETRN:
		  return;
	  case PKT_CONTNE:
	  default:
		  break;
	  }
#endif
	  /***********************************
	   * ACLEX
	   * STRING/TCPFLAG/FRAMELEN/USERDATA
	   ************************************/
aclex_procs:
#ifdef CONFIG_ACLEX
	  ret = zxmd_aclex_process(dpp, &aa, &hit_aclid);
	  switch(ret){
	  case PKT_DEFLT:
		  goto csps;
	  case PKT_RETRN:
		  return;
	  case PKT_CONTNE:
	  default:
		  break;
	  }
#endif
	  /**********
	   * CSPS
	   ***********/
csps:
	  ZXMX_PRINTF_DEBUG("begin to process crosspass.\n");
	  return csps_procs_with_ipif(dpp);
}

```
