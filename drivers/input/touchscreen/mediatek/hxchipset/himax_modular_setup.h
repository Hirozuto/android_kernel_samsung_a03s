#define setup_symbol(sym) ({kp_##sym = &(sym); kp_##sym; })
#define setup_symbol_func(sym) ({kp_##sym = (sym); kp_##sym; })

#define assert_on_symbol(sym) \
		do { \
			if (!setup_symbol(sym)) { \
				E("%s: setup %s failed!\n", __func__, #sym); \
				ret = -1; \
			} \
		} while (0)

#define assert_on_symbol_func(sym) \
		do { \
			if (!setup_symbol_func(sym)) { \
				E("%s: setup %s failed!\n", __func__, #sym); \
				ret = -1; \
			} \
		} while (0)

#if !defined(__HIMAX_HX852xH_MOD__) && !defined(__HIMAX_HX852xG_MOD__)
#if !defined(__HIMAX_HX852xJ_MOD__)
extern struct fw_operation *pfw_op;
extern struct ic_operation *pic_op;
extern struct flash_operation *pflash_op;
extern struct driver_operation *pdriver_op;
#endif
#endif

#if defined(HX_ZERO_FLASH) && defined(CONFIG_TOUCHSCREEN_HIMAX_INCELL)
extern struct zf_operation *pzf_op;
extern int G_POWERONOF;
#endif

extern unsigned char IC_CHECKSUM;

#if defined(HX_EXCP_RECOVERY)
extern u8 HX_EXCP_RESET_ACTIVATE;
#endif

#if defined(HX_ZERO_FLASH) && defined(HX_CODE_OVERLAY)
#if defined(CONFIG_TOUCHSCREEN_HIMAX_INCELL)
extern uint8_t *ovl_idx;
#endif
#endif

extern unsigned long FW_VER_MAJ_FLASH_ADDR;
extern unsigned long FW_VER_MIN_FLASH_ADDR;
extern unsigned long CFG_VER_MAJ_FLASH_ADDR;
extern unsigned long CFG_VER_MIN_FLASH_ADDR;
extern unsigned long CID_VER_MAJ_FLASH_ADDR;
extern unsigned long CID_VER_MIN_FLASH_ADDR;
extern uint32_t CFG_TABLE_FLASH_ADDR;
extern uint32_t CFG_TABLE_FLASH_ADDR_T;

#if defined(HX_BOOT_UPGRADE) || defined(HX_ZERO_FLASH)
	extern int g_i_FW_VER;
	extern int g_i_CFG_VER;
	extern int g_i_CID_MAJ;
	extern int g_i_CID_MIN;
	extern const struct firmware *hxfw;
#endif

#if defined(HX_TP_PROC_2T2R)
	extern bool Is_2T2R;
#endif

#if defined(HX_USB_DETECT_GLOBAL)
extern void (himax_cable_detect_func)(bool force_renew);
#endif

#if defined(HX_RST_PIN_FUNC)
	extern void (himax_rst_gpio_set)(int pinnum, uint8_t value);
#endif

extern struct himax_ts_data *private_ts;
extern struct himax_core_fp g_core_fp;
extern struct himax_ic_data *ic_data;
/*   function */
#if !defined(__HIMAX_HX852xH_MOD__) && !defined(__HIMAX_HX852xG_MOD__)
#if !defined(__HIMAX_HX852xJ_MOD__)
extern void (himax_mcu_in_cmd_init)(void);
extern int (himax_mcu_in_cmd_struct_init)(void);
#else
extern struct on_driver_operation *on_pdriver_op;
extern struct on_flash_operation *on_pflash_op;
extern void (himax_mcu_on_cmd_init)(void);
extern int (himax_mcu_on_cmd_struct_init)(void);
#endif
#else
extern struct on_driver_operation *on_pdriver_op;
extern struct on_flash_operation *on_pflash_op;
extern void (himax_mcu_on_cmd_init)(void);
extern int (himax_mcu_on_cmd_struct_init)(void);
#endif

extern void (himax_parse_assign_cmd)(uint32_t addr, uint8_t *cmd, int len);

extern int (himax_bus_read)(uint8_t command, uint8_t *data, uint32_t length,
		uint8_t toRetry);
extern int (himax_bus_write)(uint8_t command, uint8_t *data, uint32_t length,
		uint8_t toRetry);
extern void (himax_int_enable)(int enable);
extern int (himax_ts_register_interrupt)(void);
extern uint8_t (himax_int_gpio_read)(int pinnum);
extern int (himax_gpio_power_config)(struct himax_i2c_platform_data *pdata);

/* kp */
#if !defined(__HIMAX_HX852xH_MOD__) && !defined(__HIMAX_HX852xG_MOD__)
#if !defined(__HIMAX_HX852xJ_MOD__)
extern struct fw_operation **kp_pfw_op;
extern struct ic_operation **kp_pic_op;
extern struct flash_operation **kp_pflash_op;
extern struct driver_operation **kp_pdriver_op;
#endif
#endif

#if defined(HX_ZERO_FLASH) && defined(CONFIG_TOUCHSCREEN_HIMAX_INCELL)
extern struct zf_operation **kp_pzf_op;
extern int *kp_G_POWERONOF;
#endif

extern unsigned char *kp_IC_CHECKSUM;

#if defined(HX_EXCP_RECOVERY)
extern u8 *kp_HX_EXCP_RESET_ACTIVATE;
#endif

#if defined(HX_ZERO_FLASH) && defined(HX_CODE_OVERLAY)
#if defined(CONFIG_TOUCHSCREEN_HIMAX_INCELL)
extern uint8_t **kp_ovl_idx;
#endif
#endif

extern unsigned long *kp_FW_VER_MAJ_FLASH_ADDR;
extern unsigned long *kp_FW_VER_MIN_FLASH_ADDR;
extern unsigned long *kp_CFG_VER_MAJ_FLASH_ADDR;
extern unsigned long *kp_CFG_VER_MIN_FLASH_ADDR;
extern unsigned long *kp_CID_VER_MAJ_FLASH_ADDR;
extern unsigned long *kp_CID_VER_MIN_FLASH_ADDR;
extern uint32_t *kp_CFG_TABLE_FLASH_ADDR;
extern uint32_t *kp_CFG_TABLE_FLASH_ADDR_T;

#if defined(HX_BOOT_UPGRADE) || defined(HX_ZERO_FLASH)
	extern int *kp_g_i_FW_VER;
	extern int *kp_g_i_CFG_VER;
	extern int *kp_g_i_CID_MAJ;
	extern int *kp_g_i_CID_MIN;
	extern const struct firmware **kp_hxfw;
#endif

#if defined(HX_TP_PROC_2T2R)
	extern bool *kp_Is_2T2R;
#endif


#if defined(HX_USB_DETECT_GLOBAL)
extern void (*kp_himax_cable_detect_func)(bool force_renew);
#endif
#if defined(HX_RST_PIN_FUNC)
extern void (*kp_himax_rst_gpio_set)(int pinnum, uint8_t value);
#endif

extern struct himax_ts_data **kp_private_ts;
extern struct himax_core_fp *kp_g_core_fp;
extern struct himax_ic_data **kp_ic_data;
/* kp function*/
#if !defined(__HIMAX_HX852xH_MOD__) && !defined(__HIMAX_HX852xG_MOD__)
#if !defined(__HIMAX_HX852xJ_MOD__)
extern void (*kp_himax_mcu_in_cmd_init)(void);
extern int (*kp_himax_mcu_in_cmd_struct_init)(void);
#else
extern struct on_driver_operation **kp_on_pdriver_op;
extern struct on_flash_operation **kp_on_pflash_op;
extern void (*kp_himax_mcu_on_cmd_init)(void);
extern int (*kp_himax_mcu_on_cmd_struct_init)(void);
#endif
#else
extern struct on_driver_operation **kp_on_pdriver_op;
extern struct on_flash_operation **kp_on_pflash_op;
extern void (*kp_himax_mcu_on_cmd_init)(void);
extern int (*kp_himax_mcu_on_cmd_struct_init)(void);
#endif

extern void (*kp_himax_parse_assign_cmd)(uint32_t addr, uint8_t *cmd,
		int len);

extern int (*kp_himax_bus_read)(uint8_t command, uint8_t *data,
		uint32_t length, uint8_t toRetry);
extern int (*kp_himax_bus_write)(uint8_t command, uint8_t *data,
		uint32_t length, uint8_t toRetry);
extern void (*kp_himax_int_enable)(int enable);
extern int (*kp_himax_ts_register_interrupt)(void);
extern uint8_t (*kp_himax_int_gpio_read)(int pinnum);
extern int (*kp_himax_gpio_power_config)(struct himax_i2c_platform_data *pdata);


int32_t himax_ic_setup_external_symbols(void)
{
	int32_t ret = 0;
#if !defined(__HIMAX_HX852xH_MOD__) && !defined(__HIMAX_HX852xG_MOD__)
#if !defined(__HIMAX_HX852xJ_MOD__)
	assert_on_symbol(pfw_op);
	assert_on_symbol(pic_op);
	assert_on_symbol(pflash_op);
	assert_on_symbol(pdriver_op);
	assert_on_symbol_func(himax_mcu_in_cmd_init);
	assert_on_symbol_func(himax_mcu_in_cmd_struct_init);
#else
	assert_on_symbol(on_pdriver_op);
	assert_on_symbol(on_pflash_op);
	assert_on_symbol_func(himax_mcu_on_cmd_init);
	assert_on_symbol_func(himax_mcu_on_cmd_struct_init);
#endif
#else
	assert_on_symbol(on_pdriver_op);
	assert_on_symbol(on_pflash_op);
	assert_on_symbol_func(himax_mcu_on_cmd_init);
	assert_on_symbol_func(himax_mcu_on_cmd_struct_init);
#endif

#if defined(HX_ZERO_FLASH) && defined(CONFIG_TOUCHSCREEN_HIMAX_INCELL)
	assert_on_symbol(pzf_op);
	assert_on_symbol(G_POWERONOF);
#endif

	assert_on_symbol(IC_CHECKSUM);

#if defined(HX_EXCP_RECOVERY)
	assert_on_symbol(HX_EXCP_RESET_ACTIVATE);
#endif

#if defined(HX_ZERO_FLASH) && defined(HX_CODE_OVERLAY)
#if defined(CONFIG_TOUCHSCREEN_HIMAX_INCELL)
	assert_on_symbol(ovl_idx);
#endif
#endif

	assert_on_symbol(FW_VER_MAJ_FLASH_ADDR);
	assert_on_symbol(FW_VER_MIN_FLASH_ADDR);
	assert_on_symbol(CFG_VER_MAJ_FLASH_ADDR);
	assert_on_symbol(CFG_VER_MIN_FLASH_ADDR);
	assert_on_symbol(CID_VER_MAJ_FLASH_ADDR);
	assert_on_symbol(CID_VER_MIN_FLASH_ADDR);
	assert_on_symbol(CFG_TABLE_FLASH_ADDR);
	assert_on_symbol(CFG_TABLE_FLASH_ADDR_T);

#if defined(HX_BOOT_UPGRADE) || defined(HX_ZERO_FLASH)
	assert_on_symbol(g_i_FW_VER);
	assert_on_symbol(g_i_CFG_VER);
	assert_on_symbol(g_i_CID_MAJ);
	assert_on_symbol(g_i_CID_MIN);
	assert_on_symbol(hxfw);
#endif

#if defined(HX_TP_PROC_2T2R)
	assert_on_symbol(Is_2T2R);
#endif

#if defined(HX_USB_DETECT_GLOBAL)
	assert_on_symbol_func(himax_cable_detect_func);
#endif

#if defined(HX_RST_PIN_FUNC)
	assert_on_symbol_func(himax_rst_gpio_set);
#endif

	assert_on_symbol(private_ts);
	assert_on_symbol(g_core_fp);
	assert_on_symbol(ic_data);

	assert_on_symbol_func(himax_parse_assign_cmd);
	assert_on_symbol_func(himax_bus_read);
	assert_on_symbol_func(himax_bus_write);
	assert_on_symbol_func(himax_int_enable);
	assert_on_symbol_func(himax_ts_register_interrupt);
	assert_on_symbol_func(himax_int_gpio_read);
	assert_on_symbol_func(himax_gpio_power_config);


	return ret;

}
