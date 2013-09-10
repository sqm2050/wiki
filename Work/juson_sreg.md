# Real Mode开关，添加
## define
* mduapi/src/common/mduapi_reg.h mduapi_reg_info
	> acl_real_mode:1,
		
* libexec/common/zxmx_sreg.h zxmx_ctrl_sw
	> flag_acl_real_mode:1,

* 枚举 & 宏
	> mduapi/src/common/mduapi_reg.h mduapi_reg_flag
```
	// REAL MODE
	MDUAPI_FLAG_REG_ACL_REAL_MODE_EN,
	MDUAPI_FLAG_REG_ACL_REAL_MODE_DIS,
	#define MDUAPI_REG_INFO_QUOTE_ACL_REAL_MODE(p) 	p->s.acl_real_mode
```

## SE配置
### set
* mduapi/src/common/mduapi_reg.c
	- mduapi_dev_reg_set
```
	case MDUAPI_FLAG_REG_ACL_REAL_MODE_EN:
		psd->ctrl_sw.flag_acl_real_mode = 1;
		break;
	case MDUAPI_FLAG_REG_ACL_REAL_MODE_DIS:
		psd->ctrl_sw.flag_acl_real_mode = 0;
		break;
```
### show
* mduapi/src/common/mduapi_reg.c
	- mduapi_dev_reg_get_all
```
	if(psd->ctrl_sw.flag_acl_real_mode)
		info->s.acl_real_mode = 1;
	else
		info->s.acl_real_mode = 0;
```

## diff
```
diff --git a/libexec/common/zxmx_sreg.h b/libexec/common/zxmx_sreg.h
index e7299fa..3b38688 100644
--- a/libexec/common/zxmx_sreg.h
+++ b/libexec/common/zxmx_sreg.h
@@ -99,7 +99,8 @@ typedef struct _ctrl_sw{
 			uint64_t    flag_url_blklog_en:1,
 				    flag_url_rst_eif_grp:6,
 				    flag_url_blklog_eif_grp:6,
-				    rsv:51;
+				    flag_acl_real_mode:1,
+				    rsv:50;
 		};
 		uint64_t        data_64[2];
 	};
diff --git a/mduapi/src/common/mduapi_reg.c b/mduapi/src/common/mduapi_reg.c
index e6143e0..d8419f2 100644
--- a/mduapi/src/common/mduapi_reg.c
+++ b/mduapi/src/common/mduapi_reg.c
@@ -575,6 +575,13 @@ mduapi_dev_reg_set(uint8_t octeon_id,
 					 strtoul(argv[0], NULL, 0);
 		}
 		break;
+	// REAL MODE
+	case MDUAPI_FLAG_REG_ACL_REAL_MODE_EN:
+		psd->ctrl_sw.flag_acl_real_mode = 1;
+		break;
+	case MDUAPI_FLAG_REG_ACL_REAL_MODE_DIS:
+		psd->ctrl_sw.flag_acl_real_mode = 0;
+		break;
 	default:
 		slog_error("Not support the flag %u", flag);
 		break;
@@ -743,6 +750,12 @@ mduapi_dev_reg_get_all(uint8_t octeon_id,
 		info->s.url_blklog_en = 0;
 	info->s.url_rst_grp = psd->ctrl_sw.flag_url_rst_eif_grp;
 	info->s.url_blklog_grp = psd->ctrl_sw.flag_url_blklog_eif_grp;
+	
+	/* REAL MODE */
+	if(psd->ctrl_sw.flag_acl_real_mode)
+		info->s.acl_real_mode = 1;
+	else
+		info->s.acl_real_mode = 0;
 	return MDUAPI_REG_RET_NOERR;
 }
 
diff --git a/mduapi/src/common/mduapi_reg.h b/mduapi/src/common/mduapi_reg.h
index eb8345f..8ea2e45 100644
--- a/mduapi/src/common/mduapi_reg.h
+++ b/mduapi/src/common/mduapi_reg.h
@@ -60,6 +60,9 @@ typedef enum _mduapi_reg_flag{
 	MDUAPI_FLAG_REG_URL_BLKLOG_DIS, /* block log disable */
 	MDUAPI_FLAG_REG_URL_RST_EIF_GRP, /* tcp rst pkt send grp */
 	MDUAPI_FLAG_REG_URL_BLKLOG_EIF_GRP, /* block log  send grp */
+	// REAL MODE
+	MDUAPI_FLAG_REG_ACL_REAL_MODE_EN,
+	MDUAPI_FLAG_REG_ACL_REAL_MODE_DIS,
 }mduapi_reg_flag;
 
 #define MDUAPI_REG_RET_BEGIN 	20
@@ -133,7 +136,8 @@ typedef struct _mduapi_reg_info{
 			uint64_t 	url_rst_grp:6,
 					url_blklog_grp:6,
 					url_blklog_en:1,
-					rsv4:51;
+					acl_real_mode:1,
+					rsv4:50;
 
 		}s;
 		uint64_t 	data_64[4];
@@ -179,6 +183,9 @@ typedef struct _mduapi_reg_info{
 #define MDUAPI_REG_INFO_QUOTE_URL_RST_GRP(p) 		p->s.url_rst_grp
 #define MDUAPI_REG_INFO_QUOTE_URL_BLKLOG_GRP(p) 	p->s.url_blklog_grp
 
+// REAL MODE
+#define MDUAPI_REG_INFO_QUOTE_ACL_REAL_MODE(p) 	p->s.acl_real_mode
+
 /*
 * Function: mduapi_dev_reg_set.
 * Description: This function sets the registers defined by MD. 
diff --git a/sse/zxmd_mproc.c b/sse/zxmd_mproc.c
index d931323..ebb4005 100644
--- a/sse/zxmd_mproc.c
+++ b/sse/zxmd_mproc.c
@@ -432,8 +432,10 @@ static inline int zxmd_fmt_process(zxmx_dpim_packet *dpp){
 		cvmx_fau_atomic_add64(CNTER_FPRM_FMT_FINDED, 1);
 		switch(fmt_find->k.act) {
 		case FMT_ACT_FWD:
-			cvmx_fau_atomic_add64(CNTER_FPRM_FMT_VAL_FWD
-					, 1);
+			if (pgsreg->ctrl_sw.flag_acl_real_mode) {
+				return PKT_CONTNE;
+			}
+			cvmx_fau_atomic_add64(CNTER_FPRM_FMT_VAL_FWD, 1);
 			dpp->fmt_val = 1;
 #ifdef CONFIG_DATANG
 			if(flag_revers)
 ```
