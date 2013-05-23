mdu_pcie.c:
pcie_send_request_conf_data(OCTEON_DMA_MODE dma_mode, OCTEON_RESPONSE_ORDER resp_order, 
				OCTEON_RESPONSE_MODE  resp_mode, uint32_t octeon_id, zxmd_conf_mesg *conf_data)
	\create_soft_request_conf_data(OCTEON_DMA_MODE dma_mode, OCTEON_RESPONSE_ORDER resp_order,
					OCTEON_RESPONSE_MODE resp_mode, uint32_t inbuf_cnt,
					uint32_t outbuf_cnt, uint32_t tag,
					uint32_t q_no, uint32_t octeon_id,
					zxmx_conf_mesg *conf_data)
		\soft_req,req_info,
		\set_req_data_bufs(soft_req,inbuf_cnt, outbuf_cnt, conf_data)

	\send_req_data(soft_req)

libpcie_req.c:
unordered_blocking_request(int oct_id, void *buf, int len)
	\create_soft_request(oct_id, OS_DMA_MODE, OS_RESP_ORDER, OS_RESP_MODE, 0 ,0)
			(const int oct_id, OCTEON_DMA_MODE dma_mode,
			OCTEON_DMA_ORDER resp_order, OCTEON_RESPONSE_MODE resp_mode,
			uint32_t tag, uint32_t queue)
		\soft_req,req_info

	\send_request(oct_id, soft_req)
-------------------------------------------------------------------------------------------
cli.c:
cli_loop
	\cli_configure
		\cmd_main_configure
			\cmd_mdu_mode
				\cvmx_bootmem_find_named_block(BOOTMEM_SERV_REG)
				 先保证bootmem，OK，核已经激活	
				\cmd_dev_gtpimsi_configure
					\cmd_qry_gtp
						\mduapi_query_remote_gtp_node
							\pcie_send_request_conf_data
