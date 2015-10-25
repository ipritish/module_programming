#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x332aef30, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x4ba68ead, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0xc416f8ca, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x3832f140, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x80689e3f, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x8bc242c6, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0xce8b3243, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0xa9db7d5a, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "0F37B5F681485506656F4C8");
