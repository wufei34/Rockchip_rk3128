#
# (C) 版权所有 2000 - 2013
# Wolfgang Denk，DENX 软件工程，wd@denx.de。
#
# SPDX-许可证-标识符：GPL-2.0+
#

概括：
========

该目录包含 U-Boot 的源代码，U-Boot 是一个引导加载程序
基于 PowerPC、ARM、MIPS 和其他几种的嵌入式板
处理器，可以安装在引导 ROM 中并用于
初始化并测试硬件或下载并运行应用程序
代码。

U-Boot的发展与Linux密切相关：部分部分
源代码源自 Linux 源代码树，我们有一些
头文件是通用的，并且做了特殊规定
支持Linux镜像启动。

为了使这个软件变得容易，我们付出了一些努力
可配置和可扩展。例如，所有监视命令都是
使用相同的调用接口实现，因此非常容易
添加新命令。另外，不要永久添加很少使用的
代码（例如硬件测试实用程序）到监视器，您可以
动态加载并运行它。


地位：
=======

一般来说，配置选项中存在的所有板
Makefile已经经过一定程度的测试，可以考虑
“在职的”。事实上，其中许多都用于生产系统。

如果出现问题，请参阅 CHANGELOG 文件以找出贡献者
特定端口。此外，还有各种MAINTAINERS文件
分散在 U-Boot 源中识别人员或
负责各种板和子系统的公司。

注意：截至 2010 年 8 月，目录中不再有 CHANGELOG 文件。
实际的 U-Boot 源代码树；但是，它可以动态创建
从 Git 日志中使用：

	制定变更日志


从哪里获得帮助：
=================

如果您有疑问、问题或贡献
U-Boot，您应该向 U-Boot 邮件列表发送消息，网址为
<u-boot@lists.denx.de>。还有以前的流量存档
在邮件列表上 - 请在询问常见问题解答之前搜索存档。
请参阅http://lists.denx.de/pipermail/u-boot和
http://dir.gmane.org/gmane.comp.boot-loaders.u-boot


哪里可以获得源代码：
=========================

U-Boot 源代码保存在 Git 存储库中：
git: //www.denx.de/git/u-boot.git ;您可以在线浏览
http://www.denx.de/cgi-bin/gitweb.cgi?p=u-boot.git;a=summary

此页面上的“快照”链接允许您下载以下版本的 tarball
您可能感兴趣的任何版本。还有官方版本
可从 ftp://ftp.denx.de/pub/u-boot/ 进行 FTP 下载
目录。

预构建（和测试）的图像可从
ftp://ftp.denx.de/pub/u-boot/images/


我们来自哪里：
===================

- 从8xxrom源开始
- 创建 PPCBoot 项目 ( http://sourceforge.net/projects/ppcboot )
- 清理代码
- 更容易添加自定义板
- 可以添加其他[PowerPC] CPU
- 扩展功能，特别是：
  * 为Linux引导加载程序提供扩展接口
  * S记录下载
  * 网络启动
  * PCMCIA / CompactFlash / ATA磁盘 / SCSI ...引导
- 创建ARMBoot项目（http://sourceforge.net/projects/armboot）
- 添加其他 CPU 系列（从 ARM 开始）
- 创建 U-Boot 项目（http://sourceforge.net/projects/u-boot）
- 当前项目页面：参见http://www.denx.de/wiki/U-Boot


名称和拼写：
===================

该项目的“官方”名称是“Das U-Boot”。拼写
“U-Boot”应用于所有书面文本（文档、注释
在源文件等中）。例子：

	这是 U-Boot 项目的自述文件。

文件名等应基于字符串“u-boot”。例子：

	包含/asm-ppc/u-boot.h

	#include <asm/u-boot.h>

变量名称、预处理器常量等应基于
字符串“u_boot”或“U_BOOT”上。例子：

	U_BOOT_VERSION u_boot_logo
	IH_OS_U_BOOT u_boot_hush_start


版本控制：
===========

从 2008 年 10 月发布开始，版本名称
更改为数字版本号，没有更深层次的含义
转换为基于时间戳的编号。定期发布由以下内容标识
名称由发布日期的日历年和月组成。
其他字段（如果存在）指示候选版本或错误修复
在“稳定”维护树中发布。

例子：
	U-Boot v2009.11 - 2009 年 11 月发布
	U-Boot v2009.11.1 - 2009 年 11 月版本稳定树中的第 1 版
	U-Boot v2010.09-rc1 - 2010 年 9 月发布的候选版本 1


目录层次结构：
===================

/arch 架构特定文件
  /arc ARC 架构通用的文件
  /arm ARM 架构通用的文件
  /avr32 AVR32 架构通用的文件
  /blackfin Analog Devices Blackfin 架构通用的文件
  /m68k m68k 架构通用的文件
  /microblaze microblaze 架构通用的文件
  /mips MIPS 架构通用的文件
  /nds32 NDS32 架构通用的文件
  /nios2 Altera NIOS2 架构通用的文件
  /openrisc OpenRISC 架构通用的文件
  /powerpc PowerPC 架构通用的文件
  /sandbox 独立于硬件的“沙箱”的通用文件
  /sh SH 架构通用的文件
  /sparc SPARC 架构通用的文件
  /x86 x86 架构通用的文件
/api Machine/arch 外部应用程序的独立 API
/board 董事会相关文件
/cmd U-Boot 命令功能
/common 其他架构独立功能
/configs 主板默认配置文件
/disk 磁盘驱动器分区处理代码
/doc 文档（不要期望太多）
/drivers 常用的设备驱动程序
/dts 包含用于构建内部 U-Boot fdt 的 Makefile。
/examples 独立应用程序的示例代码等。
/fs 文件系统代码（cramfs、ext2、jffs2 等）
/包括头文件
/lib 所有体系结构通用的库例程
/Licenses 各种许可证文件
/net 网络代码
/post 开机自检
/scripts 各种构建脚本和 Makefiles
/test 各种单元测试文件
/tools 用于构建 S-Record 或 U-Boot 映像等的工具。

软件配置：
=======================

配置通常使用 C 预处理器定义来完成；这
其背后的基本原理是尽可能避免死代码。

配置变量有两类：

* 配置_选项_：
  这些可由用户选择，并且名称以
  “配置_”。

* 配置_设置_：
  这些取决于硬件等，如果
  你不知道自己在做什么；他们的名字开头为
  “配置_系统_”。

以前，所有配置都是手动完成的，其中涉及创建
符号链接和手动编辑配置文件。最近，
U-Boot 添加了 Linux 内核使用的 Kbuild 基础设施，
允许您使用“make menuconfig”命令来配置您的
建造。


处理器架构和板类型的选择：
-------------------------------------------------- -

对于所有支持的板，都有现成的默认值
可用配置；只需输入“make <board_name>_defconfig”。

示例：对于 TQM823L 模块类型：

	光盘启动
	制作TQM823L_defconfig

注意：如果您正在寻找主板的默认配置文件
你肯定曾经在那里但现在失踪了，检查文件
doc/README.scrapyard 了解不再受支持的主板列表。

沙盒环境：
--------------------

U-Boot 可以使用“沙箱”本地构建以在 Linux 主机上运行
木板。这允许非主板或架构的功能开发
具体在本机平台上进行。沙箱还用于
运行一些 U-Boot 的测试。

有关更多详细信息，请参阅 board/sandbox/README.sandbox。


板初始化流程：
--------------------------

这是板的预期启动流程。这应该适用于两者
SPL 和 U-Boot 本身（即它们都遵循相同的规则）。

注意：“SPL”代表“辅助程序加载器”，其解释见
此文件稍后会提供更多详细信息。

目前，SPL大多使用单独的代码路径，但函数名称
并且各个功能的作用是相同的。一些板或架构
可能不符合这个。至少大多数 ARM 板使用
CONFIG_SPL_FRAMEWORK 符合这一点。

执行通常从特定于体系结构的（并且可能
CPU特定的）start.S文件，如：

	- 拱/臂/cpu/armv7/start.S
	- 拱门/powerpc/cpu/mpc83xx/start.S
	- 拱门/mips/cpu/start.S

等等。从那里，调用三个函数；目的和
下面描述了每个功能的限制。

低级初始化（）：
	- 目的：必要的 init 允许执行到达 board_init_f()
	- 没有全局数据或 BSS
	- 没有堆栈（ARMv7 可能有一个，但很快就会被删除）
	- 不得设置 SDRAM 或使用控制台
	- 必须只做最低限度的事情以允许执行继续
		board_init_f()
	- 这几乎不需要
	- 从此函数正常返回

board_init_f():
	- 目的：设置机器准备运行 board_init_r()：
		即SDRAM和串行UART
	- 全局数据可用
	- 堆栈位于 SRAM 中
	- BSS 不可用，因此不能使用全局/静态变量，
		仅堆栈变量和global_data

	非 SPL 特定注释：
	- 调用 dram_init() 来设置 DRAM。如果已经在 SPL 中完成此操作
		无能为力

	SPL 特定注释：
	- 您可以用自己的函数覆盖整个 board_init_f() 函数
		根据需要版本。
	- preloader_console_init() 可以在极端情况下在这里调用
	- 应该设置 SDRAM 以及使 UART 工作所需的任何内容
	- 这些不需要清除BSS，它将由crt0.S完成
	- 必须从此函数正常返回（不要调用 board_init_r()
		直接地）

到这里BSS就被清除了。对于 SPL，如果定义了 CONFIG_SPL_STACK_R，则在
此时堆栈和global_data被重新定位到下面
CONFIG_SPL_STACK_R_ADDR。对于非 SPL，U-Boot 被重新定位到运行在
记忆。

board_init_r():
	- 目的：主要执行，通用代码
	- 全局数据可用
	- SDRAM 可用
	- BSS可用，所有静态/全局变量都可以使用
	- 执行最终继续到main_loop()

	非 SPL 特定注释：
	- U-Boot 被重新定位到内存顶部，现在从
		那里。

	SPL 特定注释：
	- 如果定义了 CONFIG_SPL_STACK_R 并且则堆栈可选地位于 SDRAM 中
		CONFIG_SPL_STACK_R_ADDR 指向 SDRAM
	- preloader_console_init() 可以在这里调用 - 通常这是
		通过定义 CONFIG_SPL_BOARD_INIT 然后提供
		包含此调用的 spl_board_init() 函数
	- 加载 U-Boot 或（在 falcon 模式下）Linux



配置选项：
----------------------

配置取决于主板和CPU类型的组合；全部
此类信息保存在配置文件中
“include/configs/<board_name>.h”。

示例：对于 TQM823L 模块，所有配置设置都位于
“包括/配置/TQM823L.h”。


许多选项的名称与相应的 Linux 完全相同
内核配置选项。目的是为了让大家更容易
稍后构建一个配置工具。


需要配置以下选项：

- CPU 类型：仅定义一种，例如 CONFIG_MPC85XX。

- 板类型：仅定义一种，例如 CONFIG_MPC8540ADS。

- CPU 子板类型：（如果定义了 CONFIG_ATSTK1000）
		精确定义一个，例如 CONFIG_ATSTK1002

- Marvell 家族成员
		CONFIG_SYS_MVFS - 如果要启用则定义它
					  一次有多个 fs 选项
					  对于 Marvell soc 家族

- 8xx CPU 选项：（如果使用 MPC8xx CPU）
		CONFIG_8xx_GCLK_FREQ - 已弃用：CPU 时钟如果
					  get_gclk_freq() 无法工作
					  例如，如果没有 32KHz
					  参考 PIT/RTC 时钟
		CONFIG_8xx_OSCLK - PLL 输入时钟（EXTCLK
					  或 XTAL/EXTAL）

- 859/866/885 CPU 选项：（如果使用 MPC859 或 MPC866 或 MPC885 CPU）：
		CONFIG_SYS_8xx_CPUCLK_MIN
		CONFIG_SYS_8xx_CPUCLK_MAX
		CONFIG_8xx_CPUCLK_DEFAULT
			请参阅文档/README.MPC866

		CONFIG_SYS_MEASURE_CPUCLK

		定义它来测量实际的 CPU 时钟
		依赖配置的正确性
		价值观。对于董事会启动最有用，以确保
		PLL 被锁定在预期频率。笔记
		这需要一个（稳定的）参考时钟（32 kHz
		RTC时钟或CONFIG_SYS_8XX_XIN）

		CONFIG_SYS_DELAYED_ICACHE

		如果您想启用此选项，请定义此选项
		仅当代码从 RAM 运行时才使用 ICache。

- 85xx CPU 选项：
		配置_SYS_PPC64

		指定内核是 64 位 PowerPC 实现（实现
		Power ISA 的“64”类别）。这对于 ePAPR 是必要的
		合规性等可能的原因。

		CONFIG_SYS_FSL_TBCLK_DIV

		定义核心时基时钟分频比
		系统时钟。在大多数 PQ3 设备上，该值为 8，在较新的 QorIQ 上则为 8
		对于不同的设备，它可以是 16 或 32。该比率因 SoC 的不同而异。

		CONFIG_SYS_FSL_PCIE_COMPAT

		定义尝试匹配 PCIe 设备时要使用的字符串
		给定平台的树节点。

		CONFIG_SYS_FSL_ERRATUM_A004510

		启用勘误表 A004510 的解决方法。如果设置，
		然后 CONFIG_SYS_FSL_ERRATUM_A004510_SVR_REV 和
		必须设置 CONFIG_SYS_FSL_CORENET_SNOOPVEC_COREONLY。

		CONFIG_SYS_FSL_ERRATUM_A004510_SVR_REV
		CONFIG_SYS_FSL_ERRATUM_A004510_SVR_REV2（可选）

		定义一或两个 SoC 修订版（SVR 的低 8 位）
		应应用 A004510 解决方法。

		SVR 的其余部分与决策无关
		是否存在勘误（例如 p2040 与
		p2041）或由构建目标暗示，它控制
		是否设置 CONFIG_SYS_FSL_ERRATUM_A004510。

		有关详细信息，请参阅飞思卡尔应用说明 4493
		这个勘误表。

		CONFIG_A003399_NOR_WORKAROUND
		启用 IFC 勘误 A003399 的解决方法。这只是
		NOR 启动期间需要。

		CONFIG_A008044_WORKAROUND
		启用 T1040/T1042 勘误表 A008044 的解决方法。这只是
		NAND 启动期间需要，并且对于 Rev 1.0 SoC 修订版有效

		CONFIG_SYS_FSL_CORENET_SNOPVEC_COREONLY

		这是要写入 CCSR 偏移 0x18600 的值
		根据 A004510 解决方法。

		CONFIG_SYS_FSL_DSP_DDR_ADDR
		该值表示 DDR 内存的起始偏移量，即
		专门连接到 DSP 内核。

		CONFIG_SYS_FSL_DSP_M2_RAM_ADDR
		该值表示M2内存的起始偏移量
		它直接连接到DSP内核。

		CONFIG_SYS_FSL_DSP_M3_RAM_ADDR
		该值表示M3内存的起始偏移量，可以直接
		连接到DSP核心。

		CONFIG_SYS_FSL_DSP_CCSRBAR_DEFAULT
		该值表示 DSP CCSR 空间的起始偏移量。

		CONFIG_SYS_FSL_SINGLE_SOURCE_CLK
		单源时钟是某些 FSL SoC 中存在的时钟模式。
		在此模式下，使用单个差分时钟来提供
		时钟为 sysclock、ddrclock 和 usbclock。

		CONFIG_SYS_CPC_REINIT_F
		当 CPC 配置为 SRAM 时定义此 CONFIG
		U-Boot进入时间，需要重新初始化。

		配置_深度_睡眠
		表示该 SoC 支持深度睡眠功能。如果深度睡眠是
		支持，核心唤醒后将开始执行uboot。

- 通用CPU选项：
		CONFIG_SYS_GENERIC_GLOBAL_DATA
		定义全局数据在通用板 board_init_f() 中初始化。
		如果定义了该宏，则会在以下位置创建和清除全局数据：
		通用板board_init_f()。如果没有这个宏，架构/板
		应在调用 board_init_f() 之前初始化全局数据。

		CONFIG_SYS_BIG_ENDIAN、CONFIG_SYS_LITTLE_ENDIAN

		定义 CPU 的字节顺序。实施那些
		值是特定于拱门的。

		CONFIG_SYS_FSL_DDR
		使用中的飞思卡尔 DDR 驱动程序。这种类型的DDR控制器是
		在 mpc83xx、mpc85xx、mpc86xx 以及一些 ARM 内核中发现
		SoC。

		CONFIG_SYS_FSL_DDR_ADDR
		飞思卡尔 DDR 内存映射寄存器基数。

		CONFIG_SYS_FSL_DDR_EMU
		指定模拟器对 DDR 的支持。一些 DDR 功能，例如
		不提供相差校正培训。

		CONFIG_SYS_FSL_DDRC_GEN1
		飞思卡尔 DDR1 控制器。

		CONFIG_SYS_FSL_DDRC_GEN2
		飞思卡尔 DDR2 控制器。

		CONFIG_SYS_FSL_DDRC_GEN3
		飞思卡尔 DDR3 控制器。

		CONFIG_SYS_FSL_DDRC_GEN4
		飞思卡尔 DDR4 控制器。

		CONFIG_SYS_FSL_DDRC_ARM_GEN3
		适用于基于 ARM 的 SoC 的飞思卡尔 DDR3 控制器。

		CONFIG_SYS_FSL_DDR1
		使用 DDR1 的主板配置。可以通过以下方式为 SoC 启用它：
		飞思卡尔 DDR1 或 DDR2 控制器，具体取决于主板
		实施。

		CONFIG_SYS_FSL_DDR2
		使用 DDR2 的主板配置。可以通过以下方式为 SoC 启用它：
		飞思卡尔 DDR2 或 DDR3 控制器，具体取决于主板
		执行。

		CONFIG_SYS_FSL_DDR3
		使用 DDR3 的主板配置。可以通过以下方式为 SoC 启用它：
		飞思卡尔 DDR3 或 DDR3L 控制器。

		CONFIG_SYS_FSL_DDR3L
		使用 DDR3L 的主板配置。可以通过以下方式为 SoC 启用它：
		DDR3L 控制器。

		CONFIG_SYS_FSL_DDR4
		使用 DDR4 的主板配置。可以通过以下方式为 SoC 启用它：
		DDR4 控制器。

		CONFIG_SYS_FSL_IFC_BE
		将 IFC 控制器寄存器空间定义为 Big Endian

		CONFIG_SYS_FSL_IFC_LE
		将 IFC 控制器寄存器空间定义为 Little Endian

		CONFIG_SYS_FSL_IFC_CLK_DIV
		定义平台时钟的分频器（IFC 控制器的时钟输入）。

		CONFIG_SYS_FSL_LBC_CLK_DIV
		定义平台时钟的分频器（eLBC 控制器的时钟输入）。

		CONFIG_SYS_FSL_PBL_PBI
		它可以在内置映像中添加 RCW（上电复位配置）。
		请参阅 doc/README.pblimage 了解更多详细信息

		CONFIG_SYS_FSL_PBL_RCW
		它在 u-boot 构建映像中添加了 PBI（预启动指令）命令。
		PBI 命令可用于在 SoC 开始执行之前对其进行配置。
		请参阅 doc/README.pblimage 了解更多详细信息

		配置_SPL_FSL_PBL
		它添加了一个目标来创建具有 PBI 格式的 SPL 二进制文件的引导二进制文件
		与 u-boot 二进制文件连接。

		CONFIG_SYS_FSL_DDR_BE
		将 DDR 控制器寄存器空间定义为 Big Endian

		CONFIG_SYS_FSL_DDR_LE
		将 DDR 控制器寄存器空间定义为 Little Endian

		CONFIG_SYS_FSL_DDR_SDRAM_BASE_PHY
		从DDR控制器的角度来看的物理地址。它是
		与所有 Power SoC 的 CONFIG_SYS_DDR_SDRAM_BASE 相同。但
		对于 ARM SoC 来说可能会有所不同。

		CONFIG_SYS_FSL_DDR_INTLV_256B
		DDR 控制器在 256 字节上交错。这是一个特殊的
		交错模式，由 Dickens for Freescale Layerscape 处理
		具有 ARM 内核的 SoC。

		CONFIG_SYS_FSL_DDR_MAIN_NUM_CTRLS
		用作主存储器的控制器数量。

		CONFIG_SYS_FSL_OTHER_DDR_NUM_CTRLS
		用于主存储器以外的控制器的数量。

		CONFIG_SYS_FSL_HAS_DP_DDR
		定义 SoC 具有用于 DPAA 的 DP-DDR。

		CONFIG_SYS_FSL_SEC_BE
		将 SEC 控制器寄存器空间定义为 Big Endian

		CONFIG_SYS_FSL_SEC_LE
		将 SEC 控制器寄存器空间定义为 Little Endian

- MIPS CPU 选项：
		CONFIG_SYS_INIT_SP_OFFSET

		相对于初始堆栈的 CONFIG_SYS_SDRAM_BASE 的偏移量
		指针。这是之前需要的临时堆栈
		搬迁。

		CONFIG_SYS_MIPS_CACHE_MODE

		MIPS CPU 的缓存操作模式。
		另请参见 arch/mips/include/asm/mipsregs.h。
		可能的值为：
			CONF_CM_CACHABLE_NO_WA
			CONF_CM_CACHABLE_WA
			CONF_CM_UNCACHED
			CONF_CM_CACHABLE_NONCOHERENT
			CONF_CM_CACHABLE_CE
			CONF_CM_CACHABLE_COW
			CONF_CM_CACHABLE_CUW
			CONF_CM_CACHABLE_ACCELERATED

		CONFIG_SYS_XWAY_EBU_BOOTCFG

		Lantiq XWAY SoC 的特殊选项，用于从 NOR 闪存启动。
		另请参见 arch/mips/cpu/mips32/start.S。

		CONFIG_XWAY_SWAP_BYTES

		启用 Lantiq 所需的工具/xway-swap-bytes 编译
		用于从 NOR 闪存启动的 XWAY SoC。 U-Boot 映像需要
		如果使用闪存编程器，则可以交换。

- ARM 选项：
		CONFIG_SYS_EXCEPTION_VECTORS_HIGH

		选择ARM内核的高异常向量，例如，不要
		清除CP15的c1寄存器的V位。

		CONFIG_SYS_THUMB_BUILD

		使用此标志通过 Thumb 指令构建 U-Boot
		为 ARM 架构设置。 Thumb指令集提供
		更好的代码密度。对于支持的 ARM 架构
		Thumb2 该标志将导致 Thumb2 代码生成
		海湾合作委员会。

		CONFIG_ARM_ERRATA_716044
		CONFIG_ARM_ERRATA_742230
		CONFIG_ARM_ERRATA_743622
		CONFIG_ARM_ERRATA_751472
		CONFIG_ARM_ERRATA_761320
		CONFIG_ARM_ERRATA_773022
		CONFIG_ARM_ERRATA_774769
		CONFIG_ARM_ERRATA_794072

		如果设置，则会尽早应用这些 ARM 勘误表的解决方法
		在 U-Boot 启动期间。请注意，这些选项强制
		要应用的解决方法；没有 CPU 类型/版本检测
		存在，与 Linux 内核中的类似选项不同。不要
		设置这些选项，除非它们适用！

		COUNTER_FREQUENCY
		通用定时器时钟源频率。

		COUNTER_FREQUENCY_REAL
		如果真实时钟是通用定时器时钟源频率
		与 COUNTER_FREQUENCY 不同，只能确定
		在运行时。

		注意：以下可能是机器特定的勘误表。这些
		有能力提供初级版本和机器
		具体检查，但预计不会进行产品检查。
		CONFIG_ARM_ERRATA_430973
		CONFIG_ARM_ERRATA_454179
		CONFIG_ARM_ERRATA_621766
		CONFIG_ARM_ERRATA_798870
		CONFIG_ARM_ERRATA_801819

- Tegra SoC 选项：
		CONFIG_TEGRA_SUPPORT_NON_SECURE

		支持在非安全（NS）模式下执行U-Boot。肯定
		如果CPU处于NS模式，将跳过不可能的动作，
		如ARM架构定时器初始化。

- Linux 内核接口：
		CONFIG_CLOCKS_IN_MHZ

		U-Boot 以 Hz 为单位存储所有时钟信息
		内部。与旧版 Linux 的二进制兼容性
		内核（期望时钟在
		bd_info 数据以 MHz 为单位）环境变量
		可以定义“clocks_in_mhz”，以便 U-Boot
		在将时钟数据传递到之前将其转换为 MHZ
		Linux 内核。
		当定义 CONFIG_CLOCKS_IN_MHZ 时，定义
		“clocks_in_mhz=1”自动包含在
		默认环境。

		CONFIG_MEMSIZE_IN_BYTES [仅与 MIPS 相关]

		某些版本向Linux传输memsize参数时
		期望它以字节为单位，其他以 MB 为单位。
		定义 CONFIG_MEMSIZE_IN_BYTES 以使其以字节为单位。

		CONFIG_OF_LIBFDT

		新的内核版本预计固件设置为
		使用扁平化设备树（基于开放固件
		概念）。

		CONFIG_OF_LIBFDT
		 * 新的基于 libfdt 的支持
		 * 添加“fdt”命令
		 * bootm命令自动更新fdt

		OF_CPU - cpus 节点的正确名称（仅需要
			基于 MPC512X 和 MPC5xxx 的板）。
		OF_SOC - soc 节点的正确名称（仅对于
			基于 MPC512X 和 MPC5xxx 的板）。
		OF_TBCLK - 时基频率。
		OF_STDOUT_PATH - 控制台设备的路径

		具有 QUICC 引擎的板需要 OF_QE 来设置 UCC MAC
		地址

		CONFIG_OF_BOARD_SETUP

		板代码有其想要进行的附加修改
		在将其交给内核之前先到平面设备树

		CONFIG_OF_SYSTEM_SETUP

		其他代码有想要进行的附加修改
		在将其交给内核之前先将其分配给平面设备树。
		这会导致 ft_system_setup() 在启动之前被调用
		内核。

		CONFIG_OF_IDE_FIXUP

		U-Boot 可以检测 IDE 设备是否存在。
		如果没有，并且这个新的配置选项被激活，U-Boot
		在启动 Linux 之前从 DTS 中删除 ATA 节点，
		因此 Linux IDE 驱动程序不会探测设备并且
		碰撞。这是有缺陷的硬件（uc101）所需要的，其中
		信号 IDE5V_DD7 上未连接下拉电阻。

		CONFIG_MACH_TYPE [仅与 ARM 相关][强制]

		对于只有一个的所有板，此设置是强制性的
		机器类型，必须用于指定机器类型
		ARM 机器注册表中显示的编号
		（参见http://www.arm.linux.org.uk/developer/machines/）。
		仅支持具有多种机器类型的板
		在单个配置文件中，机器类型是
		运行时可发现，不必使用此设置。

- vxWorks启动参数：

		bootvx 使用以下内容构建有效的引导行
		环境变量：bootdev、bootfile、ipaddr、网络掩码、
		serverip、gatewayip、主机名、othbootargs。
		它加载 vxWorks 映像指向的引导文件。

		注意：如果定义了“bootargs”环境，它将覆盖
		上面讨论的默认值。

- 缓存配置：
		CONFIG_SYS_ICACHE_OFF - 不要在 U-Boot 中启用指令缓存
		CONFIG_SYS_DCACHE_OFF - 不在 U-Boot 中启用数据缓存
		CONFIG_SYS_L2CACHE_OFF-不在 U-Boot 中启用 L2 缓存

- ARM 的缓存配置：
		CONFIG_SYS_L2_PL310 - 启用对 ARM PL310 L2 缓存的支持
				      控制器
		CONFIG_SYS_PL310_BASE - PL310的物理基地址
					控制器寄存器空间

- 串行端口：
		CONFIG_PL010_SERIAL

		如果您想要支持 Amba PrimeCell PL010 UART，请定义此项。

		CONFIG_PL011_SERIAL

		如果您想要支持 Amba PrimeCell PL011 UART，请定义此项。

		CONFIG_PL011_时钟

		如果您有 Amba PrimeCell PL011 UART，请将此变量设置为
		UART 的时钟速度。

		CONFIG_PL01x_PORTS

		如果您的主板上有 Amba PrimeCell PL010 或 PL011 UART，
		将其定义为每个（支持）的基地址列表
		港口。参见例如 include/configs/versatile.h

		CONFIG_SERIAL_HW_FLOW_CONTROL

		定义此变量以在串行驱动程序中启用硬件流控制。
		该选项的当前用户是 drivers/serial/nsl16550.c driver

- 控制台界面：
		根据板卡，精确定义一个串行端口
		（如 CONFIG_8xx_CONS_SMC1、CONFIG_8xx_CONS_SMC2、
		CONFIG_8xx_CONS_SCC1，...），或关闭串行
		通过定义 CONFIG_8xx_CONS_NONE 来控制台

		注意：如果定义了CONFIG_8xx_CONS_NONE，则串行
		端口例程必须在其他地方定义
		（即serial_init（），serial_getc（），...）

- 控制台波特率：
		CONFIG_BAUDRATE - 以 bps 为单位
		选择列出的波特率之一
		CONFIG_SYS_BAUDRATE_TABLE，见下文。
		CONFIG_SYS_BRGCLK_PRESCALE，波特率预分频

- 控制台接收缓冲区长度
		使用 CONFIG_SYS_SMC_RXBUFLEN 可以定义
		SMC 的最大接收缓冲区长度。
		该选项实际上仅适用于 82xx 和 8xx。
		如果使用 CONFIG_SYS_SMC_RXBUFLEN 也使用 CONFIG_SYS_MAXIDLE
		必须定义，以设置最大空闲超时
		SMC。

- 自动启动命令：
		CONFIG_BOOT命令
		仅当 CONFIG_BOOTDELAY 启用时需要；
		定义自动执行的命令字符串
		当控制台界面没有读到字符时
		复位后“启动延迟”内。

		CONFIG_BOOTARGS
		这可用于将参数传递给 bootm
		命令。 CONFIG_BOOTARGS 的值进入
		环境值“bootargs”。

		CONFIG_RAMBOOT 和 CONFIG_NFSBOOT
		这些的价值进入环境
		分别为“ramboot”和“nfsboot”，并且可以使用
		为了方便起见，在从以下启动之间切换时
		RAM 和 NFS。

- 启动计数：
		CONFIG_BOOTCOUNT_LIMIT
		实现检测重复重启的机制
		循环，参见：
		http://www.denx.de/wiki/view/DULG/UBootBootCountLimit

		CONFIG_BOOTCOUNT_ENV
		如果硬件上没有找到软复位保存寄存器
		“bootcount”存储在环境中。为了防止
		每次重新启动时 saveenv，环境变量
		使用“upgrade_available”。如果“upgrade_available”是
		0，如果“upgrade_available”为，“bootcount”始终为 0
		1 “bootcount”在环境中递增。
		因此用户空间应用程序必须设置“upgrade_available”
		如果引导成功，则“bootcount”变量设置为 0。

- 预启动命令：
		配置_预启动

		当该选项为 #define 时，存在
		将检查环境变量“preboot”
		在启动 CONFIG_BOOTDELAY 之前
		倒计时和/或运行自动启动命令。
		进入交互模式。

		当“预引导”被启用时，此功能特别有用
		自动生成或修改。举个例子
		查看LWMON板的具体代码：这里的“preboot”是
		当用户按住某个键时修改
		（特殊）键盘上的按键组合
		启动系统

- 串行下载回显模式：
		CONFIG_LOADS_ECHO
		如果定义为 1，则在一个过程中接收到的所有字符
		串行下载（使用“loads”命令）是
		回响着。某些终端可能需要这
		仿真（如“cu”），但也可以只采用
		花在别人身上的时间。这个设置 #define 是初始的
		“loads_echo”环境变量的值。

- Kgdb 串行波特率：（如果定义了 CONFIG_CMD_KGDB）
		CONFIG_KGDB_BAUDRATE
		选择列出的波特率之一
		CONFIG_SYS_BAUDRATE_TABLE，见下文。

- 监控功能：
		可以包含或排除监视器命令
		使用#include 文件进行构建
		<config_cmd_all.h> 和 #undef'ing 不需要的
		命令，或者为想要的命令添加#define。

		默认命令配置包括所有命令
		以下标有“*”的除外。

		CONFIG_CMD_AES AES 128 CBC 加密/解密
		CONFIG_CMD_ASKENV * 请求环境变量
		CONFIG_CMD_BDI bdinfo
		CONFIG_CMD_BEDBUG * 包括 BedBug 调试器
		CONFIG_CMD_BMP * BMP 支持
		CONFIG_CMD_BSP * 板特定命令
		CONFIG_CMD_BOOTD 启动
		CONFIG_CMD_BOOTI * ARM64 Linux 内核镜像支持
		CONFIG_CMD_CACHE * icache，dcache
		CONFIG_CMD_CLK * 时钟命令支持
		CONFIG_CMD_CONSOLE 配置信息
		CONFIG_CMD_CRC32 * crc32
		CONFIG_CMD_DATE * 支持 RTC、日期/时间...
		CONFIG_CMD_DHCP * DHCP 支持
		CONFIG_CMD_DIAG * 诊断
		CONFIG_CMD_DS4510 * ds4510 I2C GPIO 命令
		CONFIG_CMD_DS4510_INFO * ds4510 I2C 信息命令
		CONFIG_CMD_DS4510_MEM * ds4510 I2C eeprom/sram 命令
		CONFIG_CMD_DS4510_RST * ds4510 I2C 第一个命令
		CONFIG_CMD_DTT * 数字温度计和恒温器
		CONFIG_CMD_ECHO 回显参数
		CONFIG_CMD_EDITENV 编辑环境变量
		CONFIG_CMD_EEPROM * EEPROM读/写支持
		CONFIG_CMD_EEPROM_LAYOUT* EEPROM 布局感知命令
		CONFIG_CMD_ELF * bootelf，bootvx
		CONFIG_CMD_ENV_CALLBACK * 显示有关 env 回调的详细信息
		CONFIG_CMD_ENV_FLAGS * 显示有关环境标志的详细信息
		CONFIG_CMD_ENV_EXISTS * 检查环境变量是否存在
		CONFIG_CMD_EXPORTENV * 导出环境
		CONFIG_CMD_EXT2 * ext2命令支持
		CONFIG_CMD_EXT4 * ext4命令支持
		CONFIG_CMD_FS_GENERIC * 文件系统命令（例如 load、ls）
					  适用于多种文件系统类型
		CONFIG_CMD_FS_UUID * 查找文件系统 UUID
		CONFIG_CMD_SAVEENV 保存环境
		CONFIG_CMD_FDC * 软盘支持
		CONFIG_CMD_FAT * FAT命令支持
		CONFIG_CMD_FLASH flinfo，擦除，保护
		CONFIG_CMD_FPGA FPGA器件初始化支持
		CONFIG_CMD_FUSE * 设备熔丝支持
		CONFIG_CMD_GETTIME * 获取自启动以来的时间
		CONFIG_CMD_GO *“go”命令（执行代码）
		CONFIG_CMD_GREPENV * 搜索环境
		CONFIG_CMD_HASH * 计算哈希/摘要
		CONFIG_CMD_I2C * I2C串行总线支持
		CONFIG_CMD_IDE * IDE硬盘支持
		CONFIG_CMD_IMI 信息
		CONFIG_CMD_IMLS 列出 NOR 闪存中找到的所有映像
		CONFIG_CMD_IMLS_NAND * 列出 NAND 闪存中找到的所有映像
		CONFIG_CMD_IMMAP * IMMR 转储支持
		CONFIG_CMD_IOTRACE * 用于调试的 I/O 跟踪
		CONFIG_CMD_IMPORTENV * 导入环境
		CONFIG_CMD_INI * 将数据从ini文件导入到环境中
		CONFIG_CMD_IRQ * irqinfo
		CONFIG_CMD_ITEST 2 个值的整数/字符串测试
		CONFIG_CMD_JFFS2 * JFFS2 支持
		CONFIG_CMD_KGDB * kgdb
		CONFIG_CMD_LDRINFO * ldrinfo（显示Blackfin加载程序）
		CONFIG_CMD_LINK_LOCAL * 链路本地IP地址自动配置
					  (169.254.*.*)
		CONFIG_CMD_LOADB 负载b
		CONFIG_CMD_LOADS 加载
		CONFIG_CMD_MD5SUM * 打印 md5 消息摘要
					  （需要 CONFIG_CMD_MEMORY 和 CONFIG_MD5）
		CONFIG_CMD_MEMINFO * 显示详细的内存信息
		CONFIG_CMD_MEMORY md、mm、nm、mw、cp、cmp、crc、base、
					  循环，循环
		CONFIG_CMD_MEMTEST * mtest
		CONFIG_CMD_MISC 其他功能，如睡眠等
		CONFIG_CMD_MMC * MMC内存映射支持
		CONFIG_CMD_MII * MII实用程序命令
		CONFIG_CMD_MTDPARTS * MTD分区支持
		CONFIG_CMD_NAND * NAND 支持
		CONFIG_CMD_NET bootp、tftpboot、rarpboot
		CONFIG_CMD_NFS NFS 支持
		CONFIG_CMD_PCA953X * PCA953x I2C gpio 命令
		CONFIG_CMD_PCA953X_INFO * PCA953x I2C gpio 信息命令
		CONFIG_CMD_PCI * pciinfo
		CONFIG_CMD_PCMCIA * PCMCIA 支持
		CONFIG_CMD_PING * 发送 ICMP ECHO_REQUEST 到网络
					  主持人
		CONFIG_CMD_PORTIO * 端口 I/O
		CONFIG_CMD_READ * 从分区读取原始数据
		CONFIG_CMD_REGINFO * 寄存器转储
		CONFIG_CMD_RUN 在环境变量中运行命令
		CONFIG_CMD_SANDBOX * sb命令访问沙箱功能
		CONFIG_CMD_SAVES * 保存S记录转储
		CONFIG_SCSI * SCSI 支持
		CONFIG_CMD_SDRAM * 打印SDRAM配置信息
					  （需要 CONFIG_CMD_I2C）
		CONFIG_CMD_SETGETDCR 支持 DCR 寄存器访问
					  （仅限 4xx）
		CONFIG_CMD_SF * 读/写/擦除 SPI NOR 闪存
		CONFIG_CMD_SHA1SUM * 打印 sha1 内存摘要
					  （需要 CONFIG_CMD_MEMORY）
		CONFIG_CMD_SOFTSWITCH * BF60x 的软开关设置命令
		CONFIG_CMD_SOURCE“源”命令支持
		CONFIG_CMD_SPI * SPI串行总线支持
		CONFIG_CMD_TFTPSRV * 服务器模式下的TFTP传输
		CONFIG_CMD_TFTPPUT * TFTP put命令（上传）
		CONFIG_CMD_TIME * 运行命令并报告执行时间（ARM 特定）
		CONFIG_CMD_TIMER * 访问系统滴答计时器
		CONFIG_CMD_USB * USB 支持
		CONFIG_CMD_CDP * Cisco发现协议支持
		CONFIG_CMD_MFSL * Microblaze FSL 支持
		CONFIG_CMD_XIMG 加载多图像的一部分
		CONFIG_CMD_UUID * 生成随机UUID或GUID字符串

		示例：如果您想要除网络之外的所有功能
		支持你可以写：

		#include“config_cmd_all.h”
		#undef CONFIG_CMD_NET

	其他命令：
		fdt（扁平设备树）命令：CONFIG_OF_LIBFDT

	注意：不要启用“icache”和“dcache”命令
		（配置选项CONFIG_CMD_CACHE）除非你知道
		您（和您的 U-Boot 用户）正在做什么。数据
		无法在 8xx 或等系统上启用缓存
		8260（对 IMMR 区域的访问必须是
		未缓存），并且不能在所有其他设备上禁用它
		我们（错误）使用数据缓存来保存数据的系统
		初始堆栈和一些数据。


		XXX - 此列表需要更新！

- 删除命令
		如果不需要命令启动，可以禁用
		CONFIG_CMDLINE 来删除它们。在这种情况下，命令行
		将不可用，并且当 U-Boot 想要执行
		启动命令（启动时）它将调用 board_run_command()
		反而。这可以显着减小图像尺寸
		简单的启动程序。

- 正则表达式支持：
		配置正则表达式
		如果定义了该变量，则 U-Boot 会链接到
		SLRE（超轻正则表达式）库，
		它为某些命令添加了正则表达式支持，例如
		例如“env grep”和“setexpr”。

- 设备树：
		配置控制
		如果定义了该变量，U-Boot 将使用设备树
		配置其设备，而不是静态依赖
		在板文件中编译#defines。这个选项是
		实验性的，仅在少数板上可用。装置
		树在全局数据中可用，形式为 gd->fdt_blob。

		U-Boot 需要从某处获取其设备树。这个可以
		使用以下两个选项之一完成：

		配置_OF_嵌入
		如果定义了这个变量，U-Boot将嵌入一个设备树
		其图像中的二进制。该设备树文件应该位于
		board 目录并命名为 <soc>-<board>.dts。二进制文件
		然后在 board_init_f() 中获取并通过
		全局数据结构为gd->blob。

		CONFIG_OF_SEPARATE
		如果定义了这个变量，U-Boot将构建一个设备树
		二进制。它将被称为 u-boot.dtb。特定于架构的
		代码将在运行时找到它。一般来说，这是通过以下方式实现的：

			cat u-boot.bin u-boot.dtb >image.bin

		事实上，U-Boot 会为您完成此操作，创建一个名为
		u-boot-dtb.bin 在常见情况下很有用。你可以
		如果您需要更多内容，仍然可以使用单个文件
		异国情调。

- 看门狗：
		配置看门狗
		如果定义了该变量，它将启用看门狗
		对SoC的支持。 SoC中必须有支持
		看门狗的特定代码。对于 8xx 和 8260
		CPU，SYPCR 中启用了 SIU 看门狗功能
		登记。当特定 SoC 支持时
		可用，那么不应有进一步的板特定代码
		需要使用它。

		CONFIG_HW_WATCHDOG
		当使用外部看门狗电路时
		SoC，然后定义这个变量并提供board
		“hw_watchdog_reset”函数的具体代码。

		CONFIG_AT91_HW_WDT_TIMEOUT
		指定超时（以秒为单位）。默认2秒。

- U 启动版本：
		配置版本变量
		如果定义了该变量，则为环境变量
		名为“ver”由 U-Boot 创建，显示 U-Boot
		由“version”命令打印的版本。
		对此变量的任何更改都将在
		下次重置。

- 实时时钟：

		当选择CONFIG_CMD_DATE时，RTC的类型
		也必须选择。准确定义其中之一
		以下选项：

		CONFIG_RTC_MPC8xx - 使用MPC8xx的内部RTC
		CONFIG_RTC_PCF8563 - 使用飞利浦 PCF8563 RTC
		CONFIG_RTC_MC13XXX - 使用 MC13783 或 MC13892 RTC
		CONFIG_RTC_MC146818 - 使用 MC146818 RTC
		CONFIG_RTC_DS1307 - 使用 Maxim, Inc. DS1307 RTC
		CONFIG_RTC_DS1337 - 使用 Maxim, Inc. DS1337 RTC
		CONFIG_RTC_DS1338 - 使用 Maxim, Inc. DS1338 RTC
		CONFIG_RTC_DS1339 - 使用 Maxim, Inc. DS1339 RTC
		CONFIG_RTC_DS164x - 使用达拉斯 DS164x RTC
		CONFIG_RTC_ISL1208 - 使用 Intersil ISL1208 RTC
		CONFIG_RTC_MAX6900 - 使用 Maxim, Inc. MAX6900 RTC
		CONFIG_SYS_RTC_DS1337_NOOSC - 关闭 DS1337 的 OSC 输出
		CONFIG_SYS_RV3029_TCR - 启用涓流充电器
					  RV3029 实时时钟。

		注意，如果RTC使用I2C，则I2C接口
		还必须配置。请参阅下面的 I2C 支持。

- GPIO 支持：
		CONFIG_PCA953X - 使用NXP的PCA953X系列I2C GPIO

		CONFIG_SYS_I2C_PCA953X_WIDTH 选项指定一系列
		芯片-ngpio 对告诉 PCA953X 驱动程序的数量
		特定芯片支持的引脚。

		注意，如果GPIO设备使用I2C，那么I2C接口
		还必须配置。请参阅下面的 I2C 支持。

- I/O 跟踪：
		当选择 CONFIG_IO_TRACE 时，U-Boot 拦截所有 I/O
		访问并可以对它们进行校验和或写出它们的列表
		记忆。有关详细信息，请参阅“iotrace”命令。这是
		对于测试设备驱动程序很有用，因为它可以确认
		驱动程序在代码之前和之后的行为方式相同
		改变。目前，沙箱和arm都支持这一点。到
		添加对您的架构的支持，添加“#include <iotrace.h>”
		到 arch/<arch>/include/asm/io.h 的底部并进行测试。

		“iotrace stats”命令的输出示例如下。
		请注意，如果跟踪缓冲区耗尽，校验和将
		仍继续经营。

			iotrace 已启用
			开始：10000000（缓冲区起始地址）
			大小：00010000（缓冲区大小）
			偏移量：00000120（当前缓冲区偏移量）
			输出：10000120（开始+偏移）
			计数：00000018（跟踪记录数）
			CRC32：9526fb66（所有跟踪记录的CRC32）

- 时间戳支持：

		当选择 CONFIG_TIMESTAMP 时，时间戳
		图像的（日期和时间）由图像打印
		像 bootm 或 iminfo 这样的命令。这个选项是
		当您选择 CONFIG_CMD_DATE 时自动启用。

- 支持的分区标签（磁盘标签）：
		以下零个或多个：
		CONFIG_MAC_PARTITION Apple 的 MacOS 分区表。
		CONFIG_DOS_PARTITION MS Dos 分区表，传统上
				       Intel 架构、USB 棒等
		CONFIG_ISO_PARTITION ISO分区表，用于CDROM等。
		CONFIG_EFI_PARTITION GPT 分区表，当 EFI 为
				       引导加载程序。注意2TB分区限制；看
				       磁盘/part_efi.c
		CONFIG_MTD_PARTITIONS 内存技术设备分区表。

		如果启用 IDE 或 SCSI 支持（CONFIG_CMD_IDE 或
		CONFIG_SCSI）您必须配置支持
		至少还有一种非 MTD 分区类型。

- IDE重置方法：
		CONFIG_IDE_RESET_ROUTINE - 这是在几个中定义的
		板配置文件但无处使用！

		CONFIG_IDE_RESET - 是否已定义，IDE 重置将
		通过调用函数来执行
			ide_set_reset（int重置）
		必须在特定于板的文件中定义

- ATAPI 支持：
		配置ATAPI

		设置此项以启用 ATAPI 支持。

- LBA48 支持
		配置_LBA48

		设置此项以启用对大于 137GB 的磁盘的支持
		另请查看 CONFIG_SYS_64BIT_LBA。
		如果没有这些，LBA48 支持使用 32 位变量并且将“仅”
		支持高达 2.1TB 的磁盘。

		CONFIG_SYS_64BIT_LBA：
			启用后，使 IDE 子系统使用 64 位扇区地址。
			默认为 32 位。

- SCSI 支持：
		目前仅支持
		SYM53C8XX SCSI 控制器；定义
		CONFIG_SCSI_SYM53C8XX 以启用它。

		CONFIG_SYS_SCSI_MAX_LUN [8]、CONFIG_SYS_SCSI_MAX_SCSI_ID [7] 和
		CONFIG_SYS_SCSI_MAX_DEVICE [CONFIG_SYS_SCSI_MAX_SCSI_ID *
		CONFIG_SYS_SCSI_MAX_LUN]可以调整来定义
		LUN、SCSI ID 和目标的最大数量
		设备。
		CONFIG_SYS_SCSI_SYM53C8XX_CCF 修复时钟时序 (80Mhz)

		环境变量“scsidevs”设置为
		上次扫描期间发现的 SCSI 设备。

- 网络支持（PCI）：
		配置_E1000
		支持Intel 8254x/8257x千兆芯片。

		配置_E1000_SPI
		用于直接访问 Intel 8257x 上的 SPI 总线的实用程序代码。
		除非您至少设置了一个，否则这不会做任何有用的事情
		CONFIG_CMD_E1000 或 CONFIG_E1000_SPI_GENERIC。

		CONFIG_E1000_SPI_GENERIC
		允许对 Intel 8257x 上的 SPI 总线进行通用访问，
		例如“sspi”命令。

		配置_CMD_E1000
		E1000设备的管理命令。在设备上使用时
		借助 SPI 支持，您可以从 U-Boot 重新编程 EEPROM。

		配置_EEPRO100
		支持Intel 82557/82559/82559ER芯片。
		可选 CONFIG_EEPRO100_SROM_WRITE 启用 EEPROM
		编写首次初始化例程。

		配置_郁金香
		支持 Digital 2114x 芯片。
		针对特定板的可选 CONFIG_TULIP_SELECT_MEDIA
		调制解调器芯片初始化（KS8761/QS6611）。

		配置_NATSEMI
		支持国创dp83815芯片。

		配置_NS8382X
		支持National dp8382[01]千兆芯片。

- 网络支持（其他）：

		CONFIG_DRIVER_AT91EMAC
		支持 AT91RM9200 EMAC。

			配置_RMII
			定义它以使用简化的 MII 接口

			CONFIG_DRIVER_AT91EMAC_QUIET
			如果定义了这一点，则驱动程序将保持安静。
			驱动程序不显示链接状态消息。

		配置_CALXEDA_XGMAC
		支持 Calxeda XGMAC 设备

		配置_LAN91C96
		支持SMSC的LAN91C96芯片。

			CONFIG_LAN91C96_USE_32_BIT
			定义此项以启用 32 位寻址

		配置_SMC91111
		支持SMSC的LAN91C111芯片

			CONFIG_SMC91111_BASE
			定义它来保存物理地址
			设备的（I/O 空间）

			CONFIG_SMC_USE_32_BIT
			如果数据总线是 32 位则定义此项

			CONFIG_SMC_USE_IOFUNCS
			定义它以使用 i/o 函数而不是宏
			（某些硬件无法使用宏）

		CONFIG_DRIVER_TI_EMAC
		支持达芬奇 emac

			CONFIG_SYS_DAVINCI_EMAC_PHY_COUNT
			如果您有超过 3 个 PHY，请定义此项。

		配置_FTGMAC100
		支持 Faraday 的 FTGMAC100 千兆位 SoC 以太网

			CONFIG_FTGMAC100_EGIGA
			将此定义为使用千兆位 PHY 的 GE 链路更新。
			如果 FTGMAC100 连接到千兆位 PHY，请定义此项。
			如果您的系统只有 10/100 PHY，则可能不会发生
			错误的行为。因为PHY通常会返回超时或
			轮询千兆位状态和千兆位时无用的数据
			控制寄存器。此行为不会影响
			10/100 链接速度更新的正确性。

		配置_SMC911X
		支持 SMSC 的 LAN911x 和 LAN921x 芯片

			CONFIG_SMC911X_BASE
			定义它来保存物理地址
			设备的（I/O 空间）

			CONFIG_SMC911X_32_BIT
			如果数据总线是 32 位则定义此项

			CONFIG_SMC911X_16_BIT
			如果数据总线是 16 位，则定义此项。如果您的处理器
			自动将一个 32 位字转换为两个 16 位字
			你也可以尝试CONFIG_SMC911X_32_BIT。

		配置_SH_ETHER
		支持瑞萨电子片上以太网控制器

			CONFIG_SH_ETHER_USE_PORT
			定义要使用的端口数量

			CONFIG_SH_ETHER_PHY_ADDR
			定义 ETH PHY 的地址

			CONFIG_SH_ETHER_CACHE_WRITEBACK
			如果设置此选项，驱动程序将启用缓存刷新。

- 脉宽调制支持：
		配置_PWM_IMX
		在imx6上支持PWM模块。

- TPM 支持：
		配置_TPM
		支持TPM设备。

		CONFIG_TPM_TIS_INFINEON
		支持英飞凌 i2c 总线 TPM 设备。只有一台设备
		目前支持每个系统。

			CONFIG_TPM_TIS_I2C_BURST_LIMITATION
			定义突发计数字节上限

		CONFIG_TPM_ST33ZP24
		支持 STMicroElectronics TPM 设备。需要 DM_TPM 支持。

			CONFIG_TPM_ST33ZP24_I2C
			支持意法半导体 ST33ZP24 I2C 设备。
			需要 TPM_ST33ZP24 和 I2C。

			CONFIG_TPM_ST33ZP24_SPI
			支持意法半导体 ST33ZP24 SPI 设备。
			需要 TPM_ST33ZP24 和 SPI。

		CONFIG_TPM_ATMEL_TWI
		支持 Atmel TWI TPM 设备。需要 I2C 支持。

		配置_TPM_TIS_LPC
		支持通用并行端口 TPM 设备。只有一台设备
		目前支持每个系统。

			CONFIG_TPM_TIS_BASE_ADDRESS
			映射通用 TPM 设备的基地址
			到。现代 x86 系统通常将其映射到
			0xfed40000。

		配置_CMD_TPM
		添加tpm监控功能。
		需要 CONFIG_TPM。如果设置了 CONFIG_TPM_AUTH_SESSIONS，也
		提供对授权功能的监控访问。

		配置_TPM
		定义此项以启用 TPM 支持库，该库提供
		一些 TPM 命令的功能接口。
		需要 TPM 设备支持。

		CONFIG_TPM_AUTH_SESSIONS
		定义此项以启用 TPM 库中的授权功能。
		需要 CONFIG_TPM 和 CONFIG_SHA1。

- USB 支持：
		目前只有 UHCI 主机控制器
		支持（PIP405、MIP405、MPC5200）；定义
		CONFIG_USB_UHCI 以启用它。
		定义 CONFIG_USB_KEYBOARD 以启用 USB 键盘
		并定义 CONFIG_USB_STORAGE 以启用 USB
		存储设备。
		笔记：
		支持 USB 键盘和 USB 软盘驱动器
		（TEAC FD-05PUB）。
		MPC5200 USB 需要额外的定义：
			配置_USB_时钟
				对于 528 MHz 时钟：0x0001bbbb
			配置_PSC3_USB
				适用于 PSC3 上的 USB
			配置_USB_配置
				对于差分驱动器：0x00001000
				对于单端驱动程序：0x00005000
				对于 PSC3 上的差分驱动器：0x00000100
				对于 PSC3 上的单端驱动程序：0x00004100
			CONFIG_SYS_USB_EVENT_POLL
				可以定义为允许中断轮询
				而不是使用异步中断

		CONFIG_USB_EHCI_TXFIFO_THRESH 启用设置
		复位时 EHCI 控制器中的 txfilltuning 字段。

		CONFIG_USB_DWC2_REG_ADDR DWC2 的物理 CPU 地址
		硬件模块寄存器。

- USB 设备：
		如果您想使用 USB 控制台，请定义以下内容。
		从串行控制台重建固件后，会发出
		命令“setenv stdin usbtty；setenv stdout usbtty”和
		连接您的 USB 电缆。 Unix 命令“dmesg”应该打印
		它发现了一个新设备。环境变量usbtty
		可以设置为 gserial 或 cdc_acm 以使您的设备能够
		对于 USB 主机来说，它显示为 Linux gserial 设备或
		通用设备类抽象控制模型串行设备。
		如果您选择 usbtty = gserial 您应该能够枚举
		Linux 主机
		# modprobe usbserial 供应商=0xVendorID 产品=0xProductID
		否则，如果使用 cdc_acm，只需设置环境
		变量 usbtty 为 cdc_acm 就足够了。下列
		可能在 YourBoardName.h 中定义

			配置_USB_设备
			定义这个来构建 UDC 设备

			配置_USB_TTY
			定义它以拥有可用的 tty 类型设备
			与 UDC 设备对话

			配置_USBD_HS
			定义此项以启用对 USB 的高速支持
			设备和 usbtty。如果启用此功能，则例程
			int is_usbd_high_speed(void)
			也需要由驱动程序定义来动态轮询
			枚举是否高速成功或全速成功
			速度。

			CONFIG_SYS_CONSOLE_IS_IN_ENV
			如果您想要 stdin、stdout 和/或 stderr，请定义此项
			设置为 usbtty。

			mpc8xx：
				CONFIG_SYS_USB_EXTC_CLK 0xBLAH
				从外部时钟“blah”导出 USB 时钟
				- CONFIG_SYS_USB_EXTC_CLK 0x02

		如果您有 USB-IF 分配的 VendorID，那么您可能希望
		在 BoardName.h 中定义您自己的供应商特定值
		或者直接在 usbd_vendor_info.h 中。如果你不定义
		CONFIG_USBD_MANUFACTURER、CONFIG_USBD_产品_名称、
		CONFIG_USBD_VENDORID 和 CONFIG_USBD_PRODUCTID，然后是 U-Boot
		应该对目标主机伪装成 Linux 设备。

			CONFIG_USBD_MANUFACTURER
			将此字符串定义为您的公司名称
			- CONFIG_USBD_MANUFACTURER“我的公司”

			CONFIG_USBD_PRODUCT_NAME
			将此字符串定义为您的产品名称
			- CONFIG_USBD_PRODUCT_NAME“acme USB 设备”

			CONFIG_USBD_VENDORID
			将其定义为您从 USB 分配的供应商 ID
			实施者论坛。这*必须*是真实的供应商 ID
			以避免污染 USB 命名空间。
			- CONFIG_USBD_VENDORID 0xFFFF

			CONFIG_USBD_ProductID
			将其定义为唯一的产品 ID
			适合您的设备
			- CONFIG_USBD_ProductID 0xFFFF

- ULPI 层支持：
		ULPI（UTMI 低引脚（计数）接口）PHY 通过以下方式支持
		通用 ULPI 层。通用层访问 ULPI PHY
		通过平台视口，因此您需要通用层和
		视口已启用。目前仅基于 Chipidea/ARC
		支持视口。
		要启用 ULPI 层支持，请定义 CONFIG_USB_ULPI 和
		CONFIG_USB_ULPI_VIEWPORT 在您的板配置文件中。
		如果您的 ULPI phy 需要与
		标准 24 MHz 那么你必须定义 CONFIG_ULPI_REF_CLK 到
		以 Hz 为单位的适当值。

- MMC 支持：
		支持 Intel PXA 上的 MMC 控制器。到
		启用此定义 CONFIG_MMC。 MMC可以是
		通过映射设备从引导提示符进行访问
		类似于闪存的物理内存。命令行是
		使用 CONFIG_CMD_MMC 启用。 MMC 驱动程序还可以与
		FAT 文件系统。这是通过 CONFIG_CMD_FAT 启用的。

		配置_SH_MMCIF
		支持瑞萨电子片上 MMCIF 控制器

			CONFIG_SH_MMCIF_ADDR
			定义MMCIF寄存器的基地址

			CONFIG_SH_MMCIF_CLK
			定义 MMCIF 的时钟频率

		CONFIG_SUPPORT_EMMC_BOOT
		启用 eMMC 引导分区的一些附加功能。

		CONFIG_SUPPORT_EMMC_RPMB
		启用读取、写入和编程命令
		eMMC 中重播保护内存块分区的密钥。

- USB 设备固件更新 (DFU) 类支持：
		CONFIG_USB_FUNCTION_DFU
		这启用了 DFU USB 类的 USB 部分

		配置_CMD_DFU
		这启用了命令“dfu”，该命令用于具有
		U-Boot 通过 USB 创建 DFU 类设备。这个命令
		要求“dfu_alt_info”环境变量是
		设置并定义要向主机公开的 alt 设置。

		配置_DFU_MMC
		这使得支持通过 DFU 公开 (e)MMC 设备。

		配置_DFU_NAND
		这使得支持通过 DFU 公开 NAND 设备。

		配置_DFU_RAM
		这可以支持通过 DFU 公开 RAM。
		注意：DFU 规范指的是非易失性内存使用，但
		允许超出规范范围的使用 - 这里是 RAM 使用，
		一种对开发人员有最大帮助的方法。

		CONFIG_SYS_DFU_DATA_BUF_SIZE
		Dfu 传输在将数据写入之前使用缓冲区
		原始存储设备。设置该缓冲区的大小（以字节为单位）
		可配置。该缓冲区的大小也是可配置的
		通过“dfu_bufsiz”环境变量。

		CONFIG_SYS_DFU_MAX_FILE_SIZE
		当更新文件而不是原始存储设备时，
		我们使用静态缓冲区将文件复制到其中然后写入
		一旦我们获得了整个文件，缓冲区就会被释放。定义
		这是缓冲区的最大文件大小（以字节为单位）。
		如果未定义，默认值为 4 MiB。

		DFU_DEFAULT_POLL_TIMEOUT
		轮询超时 [ms]，是设备可以发送到
		主持人。主机必须等待此超时才能发送
		向设备发出后续 DFU_GET_STATUS 请求。

		DFU_MANIFEST_POLL_TIMEOUT
		轮询超时 [ms]，设备在以下情况下发送到主机：
		进入 dfuMANIFEST 状态。主机在此超时之前等待
		再次向设备发送 USB 请求。

- USB 设备 Android Fastboot 支持：
		CONFIG_USB_FUNCTION_FASTBOOT
		这将启用 fastboot 小工具的 USB 部分

		CONFIG_CMD_FASTBOOT
		这将启用命令“fastboot”，从而启用 Android
		平台 USB 设备的快速启动模式。 Fastboot是USB
		下载图像、刷新和设备控制的协议
		在 Android 设备上使用。
		有关更多信息，请参阅 doc/README.android-fastboot。

		CONFIG_ANDROID_BOOT_IMAGE
		这可以支持使用 Android 的启动映像
		图像格式标题。

		CONFIG_FASTBOOT_BUF_ADDR
		fastboot 协议需要大的内存缓冲区
		下载。将其定义为要使用的起始 RAM 地址
		下载的图像。

		CONFIG_FASTBOOT_BUF_SIZE
		fastboot 协议需要大的内存缓冲区
		下载。该缓冲区应该尽可能大
		平台。将其定义为可用于快速启动的 RAM 大小。

		配置_快速启动_闪存
		fastboot 协议包括用于写入的“flash”命令
		将下载的图像保存到非易失性存储设备中。定义
		这将启用“fastboot flash”命令。

		CONFIG_FASTBOOT_FLASH_MMC_DEV
		fastboot“flash”命令需要附加信息
		关于非易失性存储设备。将其定义为
		fastboot 用于存储映像的 eMMC 设备。

		CONFIG_FASTBOOT_GPT_NAME
		fastboot“flash”命令支持写入下载的
		映像到保护性 MBR 和主 GUID 分区
		桌子。 （此外，此下载的图像经过后期处理
		生成并写入备份 GUID 分区表。）
		当指定的“分区名称”在
		“fastboot flash”命令行与此值匹配。
		如果未定义，则默认为“gpt”。

		CONFIG_FASTBOOT_MBR_NAME
		fastboot“flash”命令支持写入下载的
		映像到 DOS MBR。
		当在“分区名称”上指定时会发生这种情况
		“fastboot flash”命令行与此值匹配。
		如果未定义，则使用默认值“mbr”。

- 日志 Flash 文件系统支持：
		配置_JFFS2_NAND
		为 NAND 设备上的默认分区定义这些

		CONFIG_SYS_JFFS2_FIRST_SECTOR，
		CONFIG_SYS_JFFS2_FIRST_BANK、CONFIG_SYS_JFFS2_NUM_BANKS
		为 NOR 设备上的默认分区定义这些

- FAT（文件分配表）文件系统写入功能支持：
		CONFIG_FAT_WRITE

		定义此项以支持将内存数据保存为
		FAT 格式分区中的文件。

		这也将启用命令“fatwrite”，从而启用
		用户将文件写入 FAT。

- CBFS（核心引导文件系统）支持：
		配置_CMD_CBFS

		定义此项以启用对从 Coreboot 读取的支持
		文件系统。可用命令有 cbfsinit、cbfsinfo、cbfsls
		和 cbfsload。

- FAT（文件分配表）文件系统簇大小：
		CONFIG_FS_FAT_MAX_CLUSTSIZE

		定义胖操作的最大簇大小
		将定义默认值 65536。

- 键盘支持：
		有关可用的键盘驱动程序，请参阅 Kconfig 帮助。

		配置键盘

		定义此项以启用自定义键盘支持。
		这只是调用 drv_keyboard_init() ，它必须是
		在您的板特定文件中定义。该选项已被弃用
		并且仅由诺维娜使用。对于新板，使用驱动程序模型
		反而。

- 视频支持：
		CONFIG_FSL_DIU_FB
		启用飞思卡尔 DIU 视频驱动程序。参考板用于
		具有 DIU 的 SOC 应定义此宏以启用 DIU
		支持，并且还应该定义这些其他宏：

			CONFIG_SYS_DIU_ADDR
			配置_视频
			配置_CMD_BMP
			配置_CFB_控制台
			CONFIG_VIDEO_SW_CURSOR
			CONFIG_VGA_AS_SINGLE_DEVICE
			配置_视频_徽标
			CONFIG_VIDEO_BMP_LOGO

		DIU 驱动程序将寻找“视频模式”环境
		变量，如果定义了，则在期间启用 DIU 作为控制台
		启动。请参阅文档文件 doc/README.video 了解
		该变量的描述。

- LCD 支持：CONFIG_LCD

		定义此项以启用 LCD 支持（用于输出到 LCD
		展示）;还选择支持的显示器之一
		通过定义其中之一：

		CONFIG_ATMEL_LCD：

			日立 TX09D70VM1CCA，3.5 英寸，240x320。

		配置_NEC_NL6448AC33：

			NEC NL6448AC33-18。活动、彩色、单次扫描。

		CONFIG_NEC_NL6448BC20

			NEC NL6448BC20-08。 6.5 英寸，640x480。
			活动、彩色、单次扫描。

		CONFIG_NEC_NL6448BC33_54

			NEC NL6448BC33-54。 10.4 英寸，640x480。
			活动、彩色、单次扫描。

		CONFIG_SHARP_16x9

			夏普 320x240。活动、彩色、单次扫描。
			它不是 16x9，我不确定它是什么。

		CONFIG_SHARP_LQ64D341

			夏普 LQ64D341 显示屏，640x480。
			活动、彩色、单次扫描。

		配置_HLD1045

			HLD1045 显示屏，640x480。
			活动、彩色、单次扫描。

		CONFIG_OPTREX_BW

			Optrex CBL50840-2 NF-FW 99 22 M5
			或者
			日立 LMG6912RPFC-00T
			或者
			日立SP14Q002

			320x240。黑，白。

		正常情况下显示为白底黑字；定义
		CONFIG_SYS_WHITE_ON_BLACK 将其反转。

		配置_LCD_对齐

		通常 LCD 是页对齐的（通常为 4KB）。如果这是
		定义后，LCD 将与该值对齐。
		对于 ARM，有时使用 MMU_SECTION_SIZE 很有用
		在这里，因为更改数据缓存设置更便宜
		以每个部分为基础。


		配置_LCD_旋转

		有时，例如如果显示器纵向安装
		模式或者即使它是横向安装但旋转 180 度，
		我们需要相对于显示内容旋转
		帧缓冲区，以便用户可以读取其中的消息
		打印出来。
		一旦定义了 CONFIG_LCD_ROTATION，lcd_console 将被
		使用来自“vl_rot”的给定旋转进行初始化
		“vidinfo_t”由主板特定代码提供。
		vl_rot 的值编码如下（匹配
		fbcon=rotate:<n> linux 内核命令行）：
		0 = 不旋转分别 0 度
		1 = 90 度旋转
		2 = 180 度旋转
		3 = 270 度旋转

		如果 CONFIG_LCD_ROTATION 未定义，控制台将是
		初始化为 0 度旋转。

		CONFIG_LCD_BMP_RLE8

		支持在 LCD 上绘制 RLE8 压缩位图。

		配置_I2C_EDID

		启用可读取 EDID 的“i2c edid”命令
		通过 I2C 从连接的 LCD 显示屏获取信息。

- 启动画面支持：CONFIG_SPLASH_SCREEN

		如果设置此选项，则会检查环境
		变量“splashimage”。如果找到，则正常显示
		LCD 上的徽标、版权和系统信息
		被抑制，并且地址处的 BMP 图像
		而是加载“splashimage”中指定的内容。这
		控制台也被重定向到“nulldev”。这
		允许在出现闪屏的情况下“静音”启动
		通电后加载速度非常快。

		配置_SPLASHIMAGE_GUARD

		如果设置了该选项，那么U-Boot将阻止环境
		变量“splashimage”被设置为有问题的地址
		（参见 doc/README.displaying-bmps）。
		此选项对于由于对齐而导致的目标很有用
		限制，不正确对齐的 BMP 图像将导致数据
		中止。如果您认为未对齐不会有问题
		访问（例如因为您的工具链阻止它们）
		无需设置该选项。

		CONFIG_SPLASH_SCREEN_ALIGN

		如果设置此选项，则启动图像可以自由定位
		屏幕上。环境变量“splashpos”指定
		位置为“x，y”。如果给出正数，则将其用作
		距左/上的像素数。如果给出负数
		用作从右/底部开始的像素数。你也可以
		指定“m”使图像居中。

		例子：
		设置环境splashpos m,m
			=> 图像位于屏幕中央

		设置环境splashpos 30,20
			=> x = 30 和 y = 20 处的图像

		设置环境splashpos -10,m
			=> 垂直居中的图像
			   在 x = dspWidth - bmpWidth - 9

- Gzip 压缩 BMP 图像支持：CONFIG_VIDEO_BMP_GZIP

		如果设置此选项，除了标准 BMP 之外
		图像，gzipped BMP 图像可以通过显示
		启动画面支持或 bmp 命令。

- 运行长度编码的 BMP 图像 (RLE8) 支持：CONFIG_VIDEO_BMP_RLE8

		如果设置此选项，则为 8 位 RLE 压缩 BMP 图像
		可以通过闪屏支持或
		bmp 命令。

压缩支持：
		配置_GZIP

		默认启用以支持 gzip 压缩图像。

		配置_BZIP2

		如果设置该选项，则支持 bzip2 压缩
		包括图像。如果没有，则仅解压缩和 gzip
		支持压缩图像。

		注意：bzip2 算法需要大量 RAM，因此
		malloc 区域（由 CONFIG_SYS_MALLOC_LEN 定义）应该
		至少 4MB。

		配置_LZMA

		如果设置此选项，则支持 lzma 压缩
		包括图像。

		注意：LZMA 算法添加了 2 到 4KB 的代码，并且它
		需要一定量的动态内存，该内存量由
		公式：

			(1846 + 768 << (lc + lp)) * sizeof(uint16)

		其中 lc 和 lp 分别代表文字上下文位
		和文字 pos 位。

		在最坏的情况下，该值的上限为 14MB。反正，
		对于 ~4MB 大内核映像，我们有 lc=3 和 lp=0
		总量 (1846 + 768 << (3 + 0)) * 2 = ~41KB...即
		一个非常小的缓冲区。

		使用 lzmainfo 工具确定 lc 和 lp 值并
		然后计算所需的动态内存量（确保
		适当的 CONFIG_SYS_MALLOC_LEN 值）。

		配置_LZO

		如果设置此选项，则支持LZO压缩图像
		已经包括了。

- MII/PHY 支持：
		配置_PHY_地址

		MII 总线上 PHY 的地址。

		CONFIG_PHY_CLOCK_FREQ (ppc4xx)

		MII总线的时钟频率

		配置_PHY_GIGE

		如果设置此选项，则支持速度/双工
		包括千兆位 PHY 的检测。

		CONFIG_PHY_RESET_DELAY

		某些 PHY（例如 Intel LXT971A）需要额外的延迟
		在可以访问任何 MII 寄存器之前复位。
		对于此类 PHY，请将此选项设置为 usec 延迟
		必需的。 （LXT971A 至少 300usec）

		CONFIG_PHY_CMD_DELAY (ppc4xx)

		某些 PHY（例如 Intel LXT971A）需要额外的延迟
		在读取 MII 状态寄存器之前发出的命令

- IP地址：
		配置_IPADDR

		定义要使用的 IP 地址的默认值
		默认以太网接口，以防万一
		通过例如 bootp 确定。
		（环境变量“ipaddr”）

- 服务器的IP地址：
		配置服务器IP

		定义 TFTP IP 地址的默认值
		使用“tftboot”命令时要联系的服务器。
		（环境变量“serverip”）

		CONFIG_KEEP_SERVERADDR

		在 env 'serveraddr' 中保留服务器的 MAC 地址
		用于传递给 bootargs（如 Linux 的 netconsole 选项）

- 网关IP地址：
		CONFIG_GATEWAYIP

		定义 IP 地址的默认值
		发送至其他网络的数据包所在的默认路由器
		发给。
		（环境变量“gatewayip”）

- 子网掩码：
		配置网络掩码

		定义子网掩码的默认值（或
		路由前缀），用于确定 IP 是否
		地址属于本地子网或需要
		通过路由器转发。
		（环境变量“网络掩码”）

- 组播TFTP模式：
		配置_MCAST_TFTP

		定义是否要支持组播 TFTP
		rfc-2090；例如与 atftp 一起使用。让很多目标
		同时通过 tftp 下载同一个启动映像。注：以太网
		使用的驱动程序必须提供一个函数： mcast() 来加入/离开
		多播组。

- BOOTP恢复模式：
		CONFIG_BOOTP_RANDOM_DELAY

		如果网络中有许多目标试图
		使用 BOOTP 启动，您可能想避免这一切
		系统在完全相同的时间发出 BOOTP 请求
		时刻（例如在恢复时会发生
		电源故障时，所有系统都会尝试
		引导，从而淹没 BOOTP 服务器。定义
		CONFIG_BOOTP_RANDOM_DELAY 导致随机延迟
		在发送 BOOTP 请求之前插入。这
		然后插入以下延迟：

		第一个 BOOTP 请求：延迟 0 ... 1 秒
		第二个 BOOTP 请求：延迟 0 ... 2 秒
		第三个 BOOTP 请求：延迟 0 ... 4 秒
		第四个及以下
		BOOTP 请求：延迟 0 ... 8 秒

		CONFIG_BOOTP_ID_CACHE_SIZE

		BOOTP 数据包使用 32 位 ID 进行唯一标识。这
		服务器会将客户端请求中的 ID 复制到响应中，
		U-Boot 将使用它来确定它是否是目标
		传入的响应。有些服务器会检查地址
		在分发之前没有使用过（通常使用 ARP
		ping），因此最多需要几百毫秒
		回应。网络拥塞也可能影响时间
		需要响应才能返回给客户端。如果说
		时间过长，U-Boot会重发请求。为了
		允许在这些之后仍然接受早期的回复
		重传时，U-Boot 的 BOOTP 客户端会保留一小部分缓存
		身份证。 CONFIG_BOOTP_ID_CACHE_SIZE 控制该缓存的大小
		缓存。默认情况下最多保留四个未完成的 ID
		要求。增加此项将允许 U-Boot 接受报价
		来自延迟异常高的网络中的 BOOTP 客户端。

- DHCP 高级选项：
		您可以通过定义来微调 DHCP 功能
		CONFIG_BOOTP_* 符号：

		CONFIG_BOOTP_SUBNETMASK
		CONFIG_BOOTP_GATEWAY
		CONFIG_BOOTP_HOSTNAME
		CONFIG_BOOTP_NISDOMAIN
		CONFIG_BOOTP_BOOTPATH
		CONFIG_BOOTP_BOOTFILESIZE
		CONFIG_BOOTP_DNS
		CONFIG_BOOTP_DNS2
		CONFIG_BOOTP_SEND_HOSTNAME
		CONFIG_BOOTP_NTPSERVER
		CONFIG_BOOTP_TIMEOFFSET
		CONFIG_BOOTP_VENDOREX
		CONFIG_BOOTP_MAY_FAIL

		CONFIG_BOOTP_SERVERIP - TFTP 服务器将是 serverip
		环境变量，而不是 BOOTP 服务器。

		CONFIG_BOOTP_MAY_FAIL - 如果未找到 DHCP 服务器
		超过配置的重试次数后，调用将失败
		而不是重新开始。这可用于故障转移
		如果 DHCP 服务器为链路本地 IP 地址配置
		不可用。

		CONFIG_BOOTP_DNS2 - 如果 DHCP 客户端请求 DNS
		来自 DHCP 服务器的 serverip，可能有更多
		向客户端提供的 DNS 服务器 IP 不只一个。
		如果启用 CONFIG_BOOTP_DNS2，则辅助 DNS
		serverip 将存储在附加环境中
		变量“dnsip2”。第一个 DNS 服务器 IP 始终是
		存储在变量“dnsip”中，当 CONFIG_BOOTP_DNS
		被定义为。

		CONFIG_BOOTP_SEND_HOSTNAME - 某些 DHCP 服务器可以
		动态更新 DNS 服务器。为了做到这一点，他们
		需要 DHCP 请求者的主机名。
		如果定义了 CONFIG_BOOTP_SEND_HOSTNAME，则内容
		“主机名”环境变量的传递为
		选项 12 到 DHCP 服务器。

		CONFIG_BOOTP_DHCP_REQUEST_DELAY

		以微秒为单位的 32 位值，表示延迟时间
		接收“DHCP Offer”并发送“DHCP Request”。
		这解决了某些 DHCP 服务器不支持的问题
		100% 响应“DHCP 请求”。例如在
		AT91RM9200处理器运行在180MHz，需要这个延迟
		在 Windows Server 2003 之前*至少* 15,000 usec
		DHCP 服务器将 100% 回复。我推荐在
		至少 50,000 usec 才安全。另一种选择是希望
		其中一次重试将会成功，但请注意
		DHCP 超时和重试过程花费的时间超过
		这个延迟。

 - 链路本地IP地址协商：
		与本地网络上的其他链路本地客户端协商
		对于不需要显式配置的地址。
		如果无法保证 DHCP 服务器，这尤其有用
		存在于设备必须运行的所有环境中。

		请参阅 doc/README.link-local 了解更多信息。

 - CDP 选项：
		CONFIG_CDP_DEVICE_ID

		CDP 触发帧中使用的设备 ID。

		CONFIG_CDP_DEVICE_ID_PREFIX

		MAC 地址前缀的两个字符串
		设备的。

		CONFIG_CDP_PORT_ID

		包含 ascii 名称的 printf 格式字符串
		港口。通常设置为“eth%d”，它设置
		eth0 用于第一个以太网，eth1 用于第二个以太网，依此类推。

		CONFIG_CDP_CAPABILITIES

		一个32位整数，表示设备能力；
		0x00000010 为不转发的普通主机。

		CONFIG_CDP_版本

		包含软件版本的 ascii 字符串。

		CONFIG_CDP_PLATFORM

		包含平台名称的 ascii 字符串。

		配置_CDP_触发

		在触发器上发送的 32 位整数。

		CONFIG_CDP_POWER_CONSUMPTION

		包含功耗的 16 位整数
		设备功耗为 0.1 毫瓦。

		CONFIG_CDP_APPLIANCE_VLAN_TYPE

		包含 VLAN id 的字节。

- 状态 LED：CONFIG_LED_STATUS

		多种配置允许显示当前
		使用 LED 指示状态。例如，LED 会闪烁
		运行 U-Boot 代码时速度很快，停止闪烁
		一旦收到对 BOOTP 请求的回复，并且
		Linux 内核运行后开始缓慢闪烁
		（由 Linux 中的状态 LED 驱动程序支持）
		核心）。定义 CONFIG_LED_STATUS 可以启用此功能
		U-Boot 中的功能。

		其他选项：

		CONFIG_LED_STATUS_GPIO
		状态 LED 可以连接到 GPIO 引脚。
		在这种情况下，gpio_led 驱动程序可以用作
		状态 LED 后端实现。定义 CONFIG_LED_STATUS_GPIO
		将 gpio_led 驱动程序包含在 U-Boot 二进制文件中。

		CONFIG_GPIO_LED_INVERTED_TABLE
		某些 GPIO 连接的 LED 可能具有反极性，其中
		GPIO 高电平值对应于 LED 关闭状态并且
		GPIO 低值对应于 LED 亮起状态。
		在这种情况下，可以定义 CONFIG_GPIO_LED_INVERTED_TABLE
		包含极性反转的 GPIO LED 列表。

- CAN 支持：CONFIG_CAN_DRIVER

		定义 CONFIG_CAN_DRIVER 启用 CAN 驱动程序支持
		在支持此功能的系统上（可选）
		功能，如 TQM8xxL 模块。

- I2C 支持：CONFIG_SYS_I2C

		这将启用新的 i2c 子系统，并允许您使用
		u-boot 命令行中的 i2c 命令（只要你设置
		CONFIG_COMMANDS中的CONFIG_CMD_I2C）并与i2c通信
		基于实时时钟芯片或其他 i2c 设备。看
		common/cmd_i2c.c 用于命令行的描述
		界面。

		将 i2c 驱动程序移植到新框架：
		- 驱动程序/i2c/soft_i2c.c：
		  - 使用 CONFIG_SYS_I2C_SOFT 定义激活第一条总线
		    CONFIG_SYS_I2C_SOFT_SPEED 和 CONFIG_SYS_I2C_SOFT_SLAVE
		    用于定义速度和从机地址
		  - 使用 I2C_SOFT_DECLARATIONS2 定义激活第二条总线
		    CONFIG_SYS_I2C_SOFT_SPEED_2 和 CONFIG_SYS_I2C_SOFT_SLAVE_2
		    用于定义速度和从机地址
		  - 使用 I2C_SOFT_DECLARATIONS3 定义激活第三总线
		    CONFIG_SYS_I2C_SOFT_SPEED_3 和 CONFIG_SYS_I2C_SOFT_SLAVE_3
		    用于定义速度和从机地址
		  - 使用 I2C_SOFT_DECLARATIONS4 定义激活第四总线
		    CONFIG_SYS_I2C_SOFT_SPEED_4 和 CONFIG_SYS_I2C_SOFT_SLAVE_4
		    用于定义速度和从机地址

		- 驱动程序/i2c/fsl_i2c.c：
		  - 使用 CONFIG_SYS_I2C_FSL 激活 i2c 驱动程序
		    定义 CONFIG_SYS_FSL_I2C_OFFSET 用于设置寄存器
		    i2c 速度的偏移 CONFIG_SYS_FSL_I2C_SPEED 和
		    CONFIG_SYS_FSL_I2C_SLAVE 为第一个的从地址
		    公共汽车。
		  - 如果您的主板支持第二个 fsl i2c 总线，请定义
		    CONFIG_SYS_FSL_I2C2_OFFSET 为寄存器偏移量
		    CONFIG_SYS_FSL_I2C2_SPEED 用于速度和
		    CONFIG_SYS_FSL_I2C2_SLAVE 为从地址
		    第二辆巴士。

		- 驱动程序/i2c/tegra_i2c.c：
		  - 使用 CONFIG_SYS_I2C_TEGRA 激活此驱动程序
		  - 该驱动程序添加了 4 个具有固定速度的 i2c 总线
		    100000 和从地址 0！

		- 驱动程序/i2c/ppc4xx_i2c.c
		  - 使用 CONFIG_SYS_I2C_PPC4XX 激活此驱动程序
		  - CONFIG_SYS_I2C_PPC4XX_CH0 激活硬件通道 0
		  - CONFIG_SYS_I2C_PPC4XX_CH1 激活硬件通道 1

		- 驱动程序/i2c/i2c_mxc.c
		  - 使用 CONFIG_SYS_I2C_MXC 激活此驱动程序
		  - 使用 CONFIG_SYS_I2C_MXC_I2C1 启用总线 1
		  - 使用 CONFIG_SYS_I2C_MXC_I2C2 启用总线 2
		  - 使用 CONFIG_SYS_I2C_MXC_I2C3 启用总线 3
		  - 使用 CONFIG_SYS_I2C_MXC_I2C4 启用总线 4
		  - 使用 CONFIG_SYS_MXC_I2C1_SPEED 定义总线 1 的速度
		  - 使用 CONFIG_SYS_MXC_I2C1_SLAVE 定义总线 1 从站
		  - 使用 CONFIG_SYS_MXC_I2C2_SPEED 定义总线 2 的速度
		  - 使用 CONFIG_SYS_MXC_I2C2_SLAVE 定义总线 2 从站
		  - 使用 CONFIG_SYS_MXC_I2C3_SPEED 定义总线 3 的速度
		  - 使用 CONFIG_SYS_MXC_I2C3_SLAVE 定义总线 3 从站
		  - 使用 CONFIG_SYS_MXC_I2C4_SPEED 定义总线 4 的速度
		  - 使用 CONFIG_SYS_MXC_I2C4_SLAVE 定义总线 4 从机
		如果未设置这些定义，则默认值为 100000
		代表速度，0 代表从机。

		- 驱动程序/i2c/rcar_i2c.c：
		  - 使用 CONFIG_SYS_I2C_RCAR 激活此驱动程序
		  - 该驱动程序添加了 4 个 i2c 总线

		  - CONFIG_SYS_RCAR_I2C0_BASE 用于设置寄存器通道0
		  - CONFIG_SYS_RCAR_I2C0_SPEED 用于速度通道 0
		  - CONFIG_SYS_RCAR_I2C1_BASE 用于设置寄存器通道1
		  - CONFIG_SYS_RCAR_I2C1_SPEED 用于速度通道 1
		  - CONFIG_SYS_RCAR_I2C2_BASE 用于设置寄存器通道2
		  - CONFIG_SYS_RCAR_I2C2_SPEED 用于速度通道 2
		  - CONFIG_SYS_RCAR_I2C3_BASE 用于设置寄存器通道3
		  - CONFIG_SYS_RCAR_I2C3_SPEED 用于速度通道 3
		  - CONFIF_SYS_RCAR_I2C_NUM_CONTROLLERS 用于 i2c 总线数量

		- 驱动程序/i2c/sh_i2c.c：
		  - 使用 CONFIG_SYS_I2C_SH 激活此驱动程序
		  - 该驱动程序添加了 2 到 5 个 i2c 总线

		  - CONFIG_SYS_I2C_SH_BASE0 用于设置寄存器通道0
		  - CONFIG_SYS_I2C_SH_SPEED0 用于速度通道 0
		  - CONFIG_SYS_I2C_SH_BASE1 用于设置寄存器通道1
		  - CONFIG_SYS_I2C_SH_SPEED1 用于速度通道 1
		  - CONFIG_SYS_I2C_SH_BASE2 用于设置寄存器通道2
		  - CONFIG_SYS_I2C_SH_SPEED2 用于速度通道 2
		  - CONFIG_SYS_I2C_SH_BASE3 用于设置寄存器通道3
		  - CONFIG_SYS_I2C_SH_SPEED3 用于速度通道 3
		  - CONFIG_SYS_I2C_SH_BASE4 用于设置寄存器通道4
		  - CONFIG_SYS_I2C_SH_SPEED4 用于速度通道 4
		  - CONFIG_SYS_I2C_SH_NUM_CONTROLLERS 用于 i2c 总线数量

		- 驱动程序/i2c/omap24xx_i2c.c
		  - 使用 CONFIG_SYS_I2C_OMAP24XX 激活此驱动程序
		  - CONFIG_SYS_OMAP24_I2C_SPEED 速度通道 0
		  - CONFIG_SYS_OMAP24_I2C_SLAVE 从地址通道 0
		  - CONFIG_SYS_OMAP24_I2C_SPEED1 速度通道 1
		  - CONFIG_SYS_OMAP24_I2C_SLAVE1 从地址通道 1
		  - CONFIG_SYS_OMAP24_I2C_SPEED2 速度通道 2
		  - CONFIG_SYS_OMAP24_I2C_SLAVE2 从地址通道 2
		  - CONFIG_SYS_OMAP24_I2C_SPEED3 速度通道 3
		  - CONFIG_SYS_OMAP24_I2C_SLAVE3 从地址通道 3
		  - CONFIG_SYS_OMAP24_I2C_SPEED4 速度通道 4
		  - CONFIG_SYS_OMAP24_I2C_SLAVE4 从地址通道 4

		- 驱动程序/i2c/zynq_i2c.c
		  - 使用 CONFIG_SYS_I2C_ZYNQ 激活此驱动程序
		  - 设置 CONFIG_SYS_I2C_ZYNQ_SPEED 进行速度设置
		  - 为从地址设置 CONFIG_SYS_I2C_ZYNQ_SLAVE

		- 驱动程序/i2c/s3c24x0_i2c.c：
		  - 使用 CONFIG_SYS_I2C_S3C24X0 激活此驱动程序
		  - 该驱动程序添加了 i2c 总线（Exynos5250、Exynos5420 为 11
		    9 个用于 Exynos4 的 i2c 总线和 1 个用于三星 S3C24X0 SoC 的 i2c 总线）
		    固定速度为 100000，从属地址为 0！

		- 驱动程序/i2c/ihs_i2c.c
		  - 使用 CONFIG_SYS_I2C_IHS 激活此驱动程序
		  - CONFIG_SYS_I2C_IHS_CH0 激活硬件通道 0
		  - CONFIG_SYS_I2C_IHS_SPEED_0 速度通道 0
		  - CONFIG_SYS_I2C_IHS_SLAVE_0 从地址通道 0
		  - CONFIG_SYS_I2C_IHS_CH1 激活硬件通道 1
		  - CONFIG_SYS_I2C_IHS_SPEED_1 速度通道 1
		  - CONFIG_SYS_I2C_IHS_SLAVE_1 从地址通道 1
		  - CONFIG_SYS_I2C_IHS_CH2 激活硬件通道 2
		  - CONFIG_SYS_I2C_IHS_SPEED_2 速度通道 2
		  - CONFIG_SYS_I2C_IHS_SLAVE_2 从地址通道 2
		  - CONFIG_SYS_I2C_IHS_CH3 激活硬件通道 3
		  - CONFIG_SYS_I2C_IHS_SPEED_3 速度通道 3
		  - CONFIG_SYS_I2C_IHS_SLAVE_3 从地址通道 3
		  - 使用 CONFIG_SYS_I2C_IHS_DUAL 激活双通道
		  - CONFIG_SYS_I2C_IHS_SPEED_0_1 速度通道 0_1
		  - CONFIG_SYS_I2C_IHS_SLAVE_0_1 从地址通道 0_1
		  - CONFIG_SYS_I2C_IHS_SPEED_1_1 速度通道 1_1
		  - CONFIG_SYS_I2C_IHS_SLAVE_1_1 从地址通道 1_1
		  - CONFIG_SYS_I2C_IHS_SPEED_2_1 速度通道 2_1
		  - CONFIG_SYS_I2C_IHS_SLAVE_2_1 从地址通道 2_1
		  - CONFIG_SYS_I2C_IHS_SPEED_3_1 速度通道 3_1
		  - CONFIG_SYS_I2C_IHS_SLAVE_3_1 从地址通道 3_1

		附加定义：

		CONFIG_SYS_NUM_I2C_BUSES
		保存您要使用的 i2c 总线的数量。

		CONFIG_SYS_I2C_DIRECT_BUS
		如果您不在硬件上使用 i2c 多路复用器，请定义此值。
		如果 CONFIG_SYS_I2C_MAX_HOPS 未定义或 == 0 你可以
		省略这个定义。

		CONFIG_SYS_I2C_MAX_HOPS
		定义最大连续连接的多路复用器数量
		在一根 i2c 总线上。如果您不使用 i2c 多路复用器，请忽略此
		定义。

		CONFIG_SYS_I2C_BUSES
		保存您要使用的巴士列表，仅在以下情况下使用
		CONFIG_SYS_I2C_DIRECT_BUS 未定义，例如
		CONFIG_SYS_I2C_MAX_HOPS = 1 的板并且
		CONFIG_SYS_NUM_I2C_BUSES = 9：

		 CONFIG_SYS_I2C_BUSES {{0, {I2C_NULL_HOP}}, \
					{0, {{I2C_MUX_PCA9547, 0x70, 1}}}, \
					{0, {{I2C_MUX_PCA9547, 0x70, 2}}}, \
					{0, {{I2C_MUX_PCA9547, 0x70, 3}}}, \
					{0, {{I2C_MUX_PCA9547, 0x70, 4}}}, \
					{0, {{I2C_MUX_PCA9547, 0x70, 5}}}, \
					{1，{I2C_NULL_HOP}}，\
					{1, {{I2C_MUX_PCA9544, 0x72, 1}}}, \
					{1, {{I2C_MUX_PCA9544, 0x72, 2}}}, \
					}

		它定义了
			适配器 0 上的总线 0 没有复用器
			适配器 0 上的总线 1，地址 0x70 端口 1 上有 PCA9547
			适配器 0 上的总线 2，地址 0x70 端口 2 上有 PCA9547
			适配器 0 上的总线 3，地址 0x70 端口 3 上有 PCA9547
			适配器 0 上的总线 4，地址 0x70 端口 4 上有 PCA9547
			适配器 0 上的总线 5，地址 0x70 端口 5 上有 PCA9547
			适配器 1 上的总线 6，不带多路复用器
			适配器 1 上的总线 7，地址 0x72 端口 1 上有 PCA9544
			适配器 1 上的总线 8，地址 0x72 端口 2 上有 PCA9544

		如果您的主板上没有 i2c 多路复用器，请忽略此定义。

- 传统 I2C 支持：CONFIG_HARD_I2C

		注意：旨在将驱动程序移动到 CONFIG_SYS_I2C
		提供以下引人注目的优势：

		- 可以使用多个 i2c 适配器
		- 批准的多总线支持
		- 更好的 i2c 多路复用器支持

		** 请考虑立即更新您的 I2C 驱动程序。 **

		这些启用传统 I2C 串行总线命令。定义
		CONFIG_HARD_I2C 将包含适当的 I2C 驱动程序
		对于所选的 CPU。

		这将允许您在 u-boot 中使用 i2c 命令
		命令行（只要您在中设置 CONFIG_CMD_I2C
		CONFIG_COMMANDS）并与基于 i2c 的实时通信
		时钟芯片。参见 common/cmd_i2c.c 的描述
		命令行界面。

		CONFIG_HARD_I2C 选择硬件 I2C 控制器。

		还有其他几个量也必须
		在定义 CONFIG_HARD_I2C 时定义。

		在这两种情况下，您都需要定义 CONFIG_SYS_I2C_SPEED
		是您希望 i2c 总线的频率（以 Hz 为单位）
		运行，CONFIG_SYS_I2C_SLAVE 是该节点的地址（即
		CPU 的 i2c 节点地址）。

		现在，mpc8xx 的 u-boot i2c 代码
		(arch/powerpc/cpu/mpc8xx/i2c.c) 将CPU设置为主节点
		因此它的地址应该被清除为 0（参见，
		例如，MPC823e 用户手册第 16-473 页）。所以，设置
		CONFIG_SYS_I2C_SLAVE 为 0。

		CONFIG_SYS_I2C_INIT_MPC5XXX

		当板在 i2c 总线传输期间重置时
		芯片可能会认为当前的传输仍在
		进行中。通过发送 start 来重置从设备
		命令直到从设备响应。

		这就是 CONFIG_HARD_I2C 所需的全部内容。

		如果使用软件i2c接口（CONFIG_SYS_I2C_SOFT）
		那么需要定义以下宏（示例是
		来自 include/configs/lwmon.h):

		I2C_初始化

		（选修的）。启用 I2C 所需的任何命令
		控制器或配置端口。

		例如：#define I2C_INIT (immr->im_cpm.cp_pbdir |= PB_SCL)

		I2C_端口

		（仅适用于 MPC8260 CPU）。要使用的 I/O 端口（代码
		假设两个位都在同一端口上）。有效值
		对于端口 A..D 为 0..3

		I2C_活动

		激活 I2C 数据线所需的代码
		（驱动）。如果数据线是集电极开路，则此
		定义可以为空。

		例如：#define I2C_ACTIVE (immr->im_cpm.cp_pbdir |= PB_SDA)

		I2C_三态

		使 I2C 数据线处于三态所需的代码
		（不活动）。如果数据线是集电极开路，则此
		定义可以为空。

		例如：#define I2C_TRISTATE (immr->im_cpm.cp_pbdir &= ~PB_SDA)

		I2C_读

		如果 I2C 数据线为高电平则返回 true 的代码，
		如果低则为假。

		例如：#define I2C_READ ((immr->im_cpm.cp_pbdat & PB_SDA) != 0)

		I2C_SDA（位）

		如果 <bit> 为真，则将 I2C 数据线设置为高电平。如果它
		为假，则将其清除（低）。

		例如：#define I2C_SDA(位) \
			if(位) immr->im_cpm.cp_pbdat |= PB_SDA; \
			否则 immr->im_cpm.cp_pbdat &= ~PB_SDA

		I2C_SCL（位）

		如果 <bit> 为真，则将 I2C 时钟线设置为高电平。如果它
		为假，则将其清除（低）。

		例如：#define I2C_SCL(位) \
			if(位) immr->im_cpm.cp_pbdat |= PB_SCL; \
			否则 immr->im_cpm.cp_pbdat &= ~PB_SCL

		I2C_延迟

		每个时钟周期会调用此延迟四次，因此
		控制数据传输速率。数据速率因此
		为 1 / (I2C_DELAY * 4)。通常被定义为某物
		喜欢：

		#定义 I2C_DELAY udelay(2)

		CONFIG_SOFT_I2C_GPIO_SCL / CONFIG_SOFT_I2C_GPIO_SDA

		如果您的架构支持通用 GPIO 框架 (asm/gpio.h)，
		那么您也可以定义两个 GPIO
		用作SCL/SDA。任何先前的 I2C_xxx 宏都会
		根据需要为它们分配基于 GPIO 的默认值。

		您应该将这些定义为直接给定的 GPIO 值
		通用 GPIO 功能。

		CONFIG_SYS_I2C_INIT_BOARD

		当板在 i2c 总线传输期间重置时
		芯片可能会认为当前的传输仍在
		进行中。在某些板上可以访问
		直接使用 i2c SCLK 线
		处理器引脚作为 GPIO 或通过具有第二个引脚
		连接到总线。如果此选项定义为
		Boards/xxx/board.c 中的自定义 i2c_init_board() 例程
		在启动序列的早期运行。

		CONFIG_SYS_I2C_BOARD_LATE_INIT

		CONFIG_SYS_I2C_INIT_BOARD 的替代方案。如果这个选项是
		定义了一个自定义 i2c_board_late_init() 例程
		boards/xxx/board.c 在 i2c_init() 中的操作之后运行
		完成了。该调用点可用于取消重置 i2c 总线
		使用 CPU i2c 控制器寄存器访问具有 i2c 的 CPU
		控制器提供了这样的方法。它在末尾被调用
		i2c_init() 允许 i2c_init 操作设置 i2c 总线
		CPU 上的控制器（例如设置总线速度和从机地址）。

		CONFIG_I2CFAST（仅限 PPC405GP|PPC405EP）

		此选项启用 bi_iic_fast[] 标志的配置
		基于u-boot环境的u-boot bd_info结构中
		变量“i2cfast”。 （另请参阅 i2cfast）

		配置_I2C_多_总线

		该选项允许使用多个 I2C 总线，每个总线
		必须有一个控制器。在任何时间点，只有一辆公交车
		积极的。要切换到不同的总线，请使用“i2c dev”命令。
		请注意，总线编号是从零开始的。

		CONFIG_SYS_I2C_NOPROBES

		该选项指定将跳过的 I2C 设备列表
		当发出“i2cprobe”命令时。如果CONFIG_I2C_MULTI_BUS
		设置后，指定总线设备对的列表。否则，指定
		设备地址的一维数组

		例如
			#undef CONFIG_I2C_MULTI_BUS
			#define CONFIG_SYS_I2C_NOPROBES {0x50,0x68}

		将跳过具有一条 I2C 总线的板上的地址 0x50 和 0x68

			#定义CONFIG_I2C_MULTI_BUS
			#define CONFIG_SYS_I2C_NOPROBES {{0,0x50},{0,0x68},{1,0x54}}

		将跳过总线 0 上的地址 0x50 和 0x68 以及总线 1 上的地址 0x54

		CONFIG_SYS_SPD_BUS_NUM

		如果已定义，则表示 DDR SPD 的 I2C 总线编号。
		如果未定义，则 U-Boot 假定 SPD 位于 I2C 总线 0 上。

		CONFIG_SYS_RTC_BUS_NUM

		如果已定义，则表示 RTC 的 I2C 总线编号。
		如果未定义，则 U-Boot 假定 RTC 位于 I2C 总线 0 上。

		CONFIG_SYS_DTT_BUS_NUM

		如果已定义，则表示 DTT 的 I2C 总线编号。
		如果未定义，则 U-Boot 假定 DTT 位于 I2C 总线 0 上。

		CONFIG_SYS_I2C_DTT_ADDR：

		如果定义，则指定 DTT 设备的 I2C 地址。
		如果未定义，则 U-Boot 使用预定义值
		指定的 DTT 设备。

		CONFIG_SOFT_I2C_READ_REPEATED_START

		定义这个将强制 i2c_read() 函数
		soft_i2c 驱动程序执行 I2C 重复启动
		在写地址指针和读之间
		数据。如果省略此定义，则默认行为
		将使用执行停止-启动序列的方法。大多数 I2C
		设备可以使用任一方法，但有些需要一个或
		另一个。

- SPI 支持：CONFIG_SPI

		启用 SPI 驱动程序（到目前为止仅测试过
		SPI EEPROM，也是一个与 Crystal A/D 配合使用的实例
		SACSng 董事会的 D/A）

		配置_SH_SPI

		启用 SuperH 上 SPI 控制器的驱动程序。现在
		仅支持 SH7757。

		配置软SPI

		启用软件（bit-bang）SPI 驱动程序，而不是
		使用硬件支持。这是一个通用目的
		仅需要三个通用 I/O 端口引脚的驱动程序
		（两个输出，一个输入）运行。如果这是
		定义后，板卡配置必须定义几个
		SPI 配置项（要使用的端口引脚等）。为了
		示例请参见 include/configs/sacsng.h。

		配置_硬_SPI

		启用硬件 SPI 驱动程序以进行通用读取
		并写道。与 CONFIG_SOFT_SPI 一样，板配置
		必须定义片选函数指针列表。
		目前在某些 MPC8xxx 处理器上受支持。为
		示例，请参见 include/configs/mpc8349emds.h。

		配置_MXC_SPI

		启用 i.MX 和 MXC 上 SPI 控制器的驱动程序
		SoC。目前支持 i.MX31/35/51。

		CONFIG_SYS_SPI_MXC_WAIT
		等待 spi 传输完成的超时。
		默认值：(CONFIG_SYS_HZ/100) /* 10 毫秒 */

- FPGA 支持：CONFIG_FPGA

		启用 FPGA 子系统。

		CONFIG_FPGA_<供应商>

		启用对特定芯片供应商的支持。
		（阿尔特拉、赛灵思）

		CONFIG_FPGA_<系列>

		支持 FPGA 系列。
		（SPARTAN2、SPARTAN3、VIRTEX2、CYCLONE2、ACEX1K、ACEX）

		配置_FPGA_COUNT

		指定要支持的 FPGA 设备数量。

		CONFIG_CMD_FPGA_LOADMK

		启用对 fpga loadmk 命令的支持

		CONFIG_CMD_FPGA_LOADP

		启用对 fpga loadp 命令的支持 - 加载部分比特流

		CONFIG_CMD_FPGA_LOADBP

		启用对 fpga loadbp 命令的支持 - 加载部分比特流
		（仅限赛灵思）

		CONFIG_SYS_FPGA_PROG_FEEDBACK

		在 FPGA 配置期间启用哈希标记打印。

		CONFIG_SYS_FPGA_CHECK_BUSY

		启用 FPGA 配置接口繁忙检查
		通过配置功能的状态。这个选项
		将需要一个板或设备的特定功能
		被写下来。

		配置_FPGA_延迟

		如果已定义，则为 FPGA 中提供延迟的函数
		配置驱动程序。

		CONFIG_SYS_FPGA_CHECK_CTRLC
		允许 Control-C 中断 FPGA 配置

		CONFIG_SYS_FPGA_CHECK_ERROR

		检查 FPGA 位文件期间的配置错误
		加载中。例如，在 Virtex II 期间中止
		如果 INIT_B 线变低（即
		指示 CRC 错误）。

		CONFIG_SYS_FPGA_WAIT_INIT

		等待 INIT_B 线取消断言的最长时间
		在 Virtex II 期间 PROB_B 被取消置位后
		FPGA 配置顺序。默认时间为500
		多发性硬化症。

		CONFIG_SYS_FPGA_WAIT_BUSY

		期间等待 BUSY 解除置位的最长时间
		Virtex II FPGA 配置。默认值为 5 毫秒。

		CONFIG_SYS_FPGA_WAIT_CONFIG

		FPGA 配置后等待的时间。默认为
		200 毫秒

- 配置管理：
		配置_构建_目标

		某些 SoC 需要特殊的映像类型（例如 U-Boot 二进制文件）
		带有特殊标头）作为构建目标。通过定义
		CONFIG_BUILD_TARGET 在 SoC/board header 中，这个
		调用时会自动构建特殊图像
		制造/建造者。

		CONFIG_IDENT_STRING

		如果定义，该字符串将被添加到 U-Boot
		版本信息（U_BOOT_VERSION）

- 供应商参数保护：

		U-Boot 考虑环境的价值
		变量“serial#”（板序列号）和
		“ethaddr”（以太网地址）是参数
		由板供应商/制造商设置一次，并且
		保护这些变量不被随意修改
		用户。一旦设置，这些变量是只读的，
		并且写入或删除尝试被拒绝。你可以
		改变这种行为：

		如果 CONFIG_ENV_OVERWRITE 在您的配置中#define
		文件，供应商参数的写保护是
		完全禁用。任何人都可以更改或删除
		这些参数。

		或者，如果您在中定义了 _both_ ethaddr
		默认环境_和_ CONFIG_OVERWRITE_ETHADDR_ONCE，默认值
		环境中安装以太网地址，
		用户可以准确地更改一次。 [这
		serial# 不受此影响，即它仍然存在
		只读。]

		同样可以通过更灵活的方式完成
		通过配置访问类型对于任何变量
		允许“.flags”变量中的这些变量
		或定义 CONFIG_ENV_FLAGS_LIST_STATIC。

- 受保护的内存：
		配置_PRAM

		定义此变量以启用保留
		“受保护的RAM”，即不被覆盖的RAM
		通过U-Boot。定义 CONFIG_PRAM 来保存数量
		您要为 pRAM 保留的 kB。你可以覆盖
		通过定义环境来设置此默认值
		变量“pram”为您想要的 kB 数
		预订。请注意，董事会信息结构将
		仍然显示 RAM 的全部容量。如果 pRAM 是
		保留，一个新的环境变量“mem”将
		自动被定义为持有的金额
		剩余的 RAM 可以作为引导传递
		Linux 的争论，例如：

			setenv bootargs ... mem=\${mem}
			保存环境

		这样你就可以告诉Linux不要使用这块内存，
		要么，这会导致一个内存区域
		不受重启影响。

		*警告* 如果您的主板配置使用自动
		检测 RAM 大小，您必须确保
		此内存测试是非破坏性的。到目前为止，
		已知以下板配置是
		“pRAM-干净”：

			IVMS8、IVML24、SPD8xx、TQM8xxL、
			HERMES、IP860、RPXlite、LWMON、
			弗拉加DM，TQM8260

- 访问物理内存区域（> 4GB）
		为内存上的操作提供了一些基本支持，而不是
		通常可由 U-Boot 访问 - 例如某些架构
		在32位上支持访问4GB以上内存
		使用物理地址扩展或类似的机器。
		定义 CONFIG_PHYSMEM 来访问此基本支持，其中
		目前仅支持清除内存。

- 错误恢复：
		CONFIG_PANIC_HANG

		定义此变量以在发生以下情况时停止系统
		致命错误，因此您必须手动重置它。
		对于嵌入式系统来说这可能不是一个好主意
		您希望系统重新启动的系统
		尽可能快地自动执行，但可能会
		在开发过程中很有用，因为您可以尝试调试
		导致该情况的条件。

		CONFIG_NET_RETRY_COUNT

		该变量定义了重试次数
		网络操作，例如 ARP、RARP、TFTP 或 BOOTP
		在放弃操作之前。如果没有定义，一个
		使用默认值 5。

		配置ARP超时

		等待 ARP 回复的超时时间（以毫秒为单位）。

		CONFIG_NFS_TIMEOUT

		NFS 协议中使用的超时（以毫秒为单位）。
		如果您在 nfs 命令中遇到“ERROR: Cannot umount”，
		尝试更长的超时，例如
		#定义 CONFIG_NFS_TIMEOUT 10000UL

- 命令解释器：
		配置_自动_完成

		使用 TAB 启用命令自动完成。

		CONFIG_SYS_PROMPT_HUSH_PS2

		这定义了辅助提示字符串，即
		当命令解释器需要更多输入时打印
		来完成一个命令。通常是“>”。

	笔记：

		在当前的实现中，局部变量
		空间和全局环境变量空间是
		分开了。局部变量是您定义的变量
		只需输入“名称=值”即可。访问本地
		稍后变量，你可以写“$name”或
		`${名称}';执行变量的内容
		直接在命令提示符下键入“$name”。

		全局环境变量是您使用的变量
		setenv/printenv 来使用。运行存储的命令
		在这样的变量中，您需要使用 run 命令，
		并且您不能使用“$”符号来访问它们。

		将命令和特殊字符存储在
		变量，请使用双引号
		围绕变量的整个文本，而不是
		分号和特殊符号之前的反斜杠
		符号。

- 命令行编辑和历史记录：
		CONFIG_CMDLINE_编辑

		启用交互式编辑和历史记录功能
		命令行输入操作

- 命令行 PS1/PS2 支持：
		CONFIG_CMDLINE_PS_SUPPORT

		启用对更改命令提示符字符串的支持
		在运行时。目前仅支持静态字符串。
		该字符串是从环境变量 PS1 获取的
		和PS2。

- 默认环境：
		CONFIG_EXTRA_ENV_SETTINGS

		定义它包含任意数量的空终止
		字符串（变量 = 值对）将成为
		编译到启动映像中的默认环境。

		例如，将这样的东西放在你的
		板的配置文件：

		#定义CONFIG_EXTRA_ENV_SETTINGS \
			“myvar1=值1\0”\
			“myvar2=值2\0”

		警告：此方法基于以下知识：
		内部格式如何存储环境
		U 引导代码。这不是官方的，导出的
		界面！虽然这种格式不太可能
		很快就会改变，也没有保证。
		你最好知道你在这里做什么。

		注意：过度（滥用）使用默认环境是
		灰心。确保检查其他预设方式
		环境，如“source”命令或
		首先启动命令。

		CONFIG_ENV_VARS_UBOOT_CONFIG

		定义它是为了添加描述的变量
		U-Boot 构建配置到默认环境。
		它们将被命名为 arch、cpu、board、vendor 和 soc。

		启用此选项将导致定义以下内容：

		- CONFIG_SYS_ARCH
		- 配置_系统_CPU
		- 配置系统板
		- 配置_系统_供应商
		- 配置_系统_SOC

		CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG

		定义它是为了添加描述某些的变量
		运行时确定有关硬件的信息
		环境。这些将被命名为 board_name、board_rev。

		配置_延迟_环境

		通常情况下，开发板启动时会加载环境
		初始化以便 U-Boot 可以使用它。这抑制了
		这样环境才可用，直到
		稍后由 U-Boot 代码显式加载。使用 CONFIG_OF_CONTROL
		这是由值控制的
		/config/加载环境。

- 数据闪存支持：
		CONFIG_HAS_DATAFLASH

		定义此选项可启用 DataFlash 功能并
		允许通过标准在 Dataflash 中读/写
		命令 cp、md...

- 串行闪存支持
		配置_CMD_SF

		定义此选项启用 SPI 闪存命令
		'sf 探测/读/写/擦除/更新'。

		使用需要一个初始“探针”来定义序列
		闪存参数，然后是读/写/擦除/更新
		命令。

		平台可能会提供以下默认值
		处理只有一个序列时的常见情况
		系统上存在闪存。

		CONFIG_SF_DEFAULT_BUS 总线标识符
		CONFIG_SF_DEFAULT_CS 片选
		CONFIG_SF_DEFAULT_MODE（参见 include/spi.h）
		CONFIG_SF_DEFAULT_SPEED（以赫兹为单位）

		CONFIG_CMD_SF_TEST

		定义此选项以包含破坏性 SPI 闪存
		测试（'sf 测试'）。

		CONFIG_SF_DUAL_FLASH 双闪存

		定义此选项以使用双闪光灯支持，其中两个闪光灯
		存储器可以与给定的 cs 线连接。
		目前 Xilinx Zynq qspi 支持这些类型的连接。

- SystemACE 支持：
		CONFIG_SYSTEMACE

		添加此选项可增加对 Xilinx SystemACE 的支持
		通过某种本地总线连接的芯片。地址
		芯片的还必须定义在
		CONFIG_SYS_SYSTEMACE_BASE 宏。例如：

		#定义CONFIG_SYSTEMACE
		#定义CONFIG_SYS_SYSTEMACE_BASE 0xf0000000

		添加 SystemACE 支持后，“ace”设备类型
		变得可用于 fat 命令，即 fatls。

- TFTP 固定 UDP 端口：
		配置_TFTP_端口

		如果定义了这个，环境变量 tftpsrcp
		用于提供 TFTP UDP 源端口值。
		如果未定义 tftpsrcp，则为普通伪随机端口
		使用数字生成器。

		此外，环境变量 tftpdstp 用于提供
		TFTP UDP 目标端口值。如果 tftpdstp 不是
		定义后，使用普通端口 69。

		tftpsrcp 的目的是允许 TFTP 服务器
		使用预配置盲目启动TFTP传输
		目标IP地址和UDP端口。这有以下效果
		“突破”（Windows XP）防火墙，允许
		TFTP 传输的其余部分正常进行。
		更好的解决方案是正确配置防火墙，
		但有时这是不允许的。

- 哈希支持：
		CONFIG_CMD_HASH

		这启用了通用的“哈希”命令，可以生成
		来自一些算法（例如 SHA1、SHA256）的哈希值/摘要。

		CONFIG_HASH_VERIFY

		启用哈希验证命令 (hash -v)。这会添加到代码中
		尺寸有点。

		CONFIG_SHA1 - 此选项支持使用 SHA1 进行哈希处理
		算法。哈希值是在软件中计算的。
		CONFIG_SHA256 - 此选项支持使用散列
		SHA256 算法。哈希值是在软件中计算的。
		CONFIG_SHA_HW_ACCEL - 此选项启用硬件加速
		用于 SHA1/SHA256 哈希。
		这会影响“hash”命令以及
		hash_lookup_algo() 函数。
		CONFIG_SHA_PROG_HW_ACCEL - 此选项启用
		SHA1/SHA256 渐进式哈希的硬件加速。
		数据可以一次在一个块中传输，并且散列
		是在硬件中执行的。

		注意：还有一个 sha1sum 命令，也许应该
		已弃用，取而代之的是“hash sha1”。

- 飞思卡尔 i.MX 特定命令：
		CONFIG_CMD_HDMIDETECT
		这将启用“hdmidet”命令，如果
		检测到 HDMI 显示器。该命令是 i.MX 6 特定的。

		CONFIG_CMD_BMODE
		这将启用“bmode”（引导模式）命令来强制
		从特定媒体启动。

		这对于强制 ROM 的 USB 下载器很有用
		在看门狗重置时激活，这在迭代时很好
		在 U 启动上。使用重置按钮或运行 bmode 正常
		会将其恢复正常。目前该命令
		支持 i.MX53 和 i.MX6。

- 启动计数支持：
		CONFIG_BOOTCOUNT_LIMIT

		这将启用启动计数器支持，请参阅：
		http://www.denx.de/wiki/DULG/UBootBootCountLimit

		CONFIG_AT91SAM9XE
		在基于 at91sam9xe 的板上启用特殊引导计数器支持。
		配置_BLACKFIN
		在基于 blackfin 的主板上启用特殊的引导计数器支持。
		配置_SOC_DA8XX
		在基于 da850 的主板上启用特殊引导计数器支持。
		CONFIG_BOOTCOUNT_RAM
		启用对 RAM 中启动计数器的支持
		CONFIG_BOOTCOUNT_I2C
		在 i2c（如 RTC）设备上启用对启动计数器的支持。
			CONFIG_SYS_I2C_RTC_ADDR = i2c芯片地址
			CONFIG_SYS_BOOTCOUNT_ADDR = i2c地址，用于
						    引导计数器。
			CONFIG_BOOTCOUNT_ALEN = 地址长度

- 显示启动进度：
		CONFIG_SHOW_BOOT_PROGRESS

		定义此选项允许添加一些板 -
		具体代码（调用用户提供的函数
		“show_boot_progress(int)”) 使您能够显示
		某些显示屏上的系统启动进度（例如
		例如，板上的一些 LED）。眼下，
		实施了以下检查点：


旧版 uImage 格式：

  精氨酸何时何地
    1 common/cmd_bootm.c 在尝试启动映像之前
   -1 common/cmd_bootm.c 图像头有错误的幻数
    2 common/cmd_bootm.c 图像头具有正确的幻数
   -2 common/cmd_bootm.c 图像头的校验和错误
    3 common/cmd_bootm.c 图像头具有正确的校验和
   -3 common/cmd_bootm.c 图像数据的校验和错误
    4 common/cmd_bootm.c 图像数据具有正确的校验和
   -4 common/cmd_bootm.c 图像适用于不受支持的架构
    5 common/cmd_bootm.c 架构检查OK
   -5 common/cmd_bootm.c 错误的映像类型（不是内核，多）
    6 common/cmd_bootm.c 镜像类型检查OK
   -6 common/cmd_bootm.cgunzip解压缩错误
   -7 common/cmd_bootm.c 未实现的压缩类型
    7 common/cmd_bootm.c 解压 OK
    8 common/cmd_bootm.c 无解压缩/复制覆盖错误
   -9 common/cmd_bootm.c 不支持的操作系统（不包括 Linux、BSD、VxWorks、QNX）

    9 common/image.c 开始初始ramdisk验证
  -10 common/image.c Ramdisk 标头有错误的幻数
  -11 common/image.c Ramdisk 标头的校验和错误
   10 common/image.c Ramdisk头文件OK
  -12 common/image.c Ramdisk 数据的校验和错误
   11 common/image.c Ramdisk数据有正确的校验和
   12 common/image.c Ramdisk验证完成，开始加载
  -13 common/image.c 错误的映像类型（不是 PPC Linux ramdisk）
   13 common/image.c 启动多文件图像验证
   14 common/image.c 无初始 ramdisk，无多文件，继续。

   15 arch/<arch>/lib/bootm.c 所有准备工作完成，将控制权转移给操作系统

  -30 arch/powerpc/lib/board.c 致命错误，挂起系统
  -31 post/post.c POST 测试失败，由 post_output_backlog() 检测到
  -32 post/post.c POST 测试失败，由 post_run_single() 检测到

   34 common/cmd_doc.c 在从 DOC 设备加载图像之前
  -35 common/cmd_doc.c “doc”命令的错误用法
   35 common/cmd_doc.c “doc”命令的正确用法
  -36 common/cmd_doc.c 无启动设备
   36 common/cmd_doc.c 正确的启动设备
  -37 common/cmd_doc.c 启动设备上的未知芯片 ID
   37 common/cmd_doc.c 找到正确的芯片 ID，设备可用
  -38 common/cmd_doc.c 启动设备上读取错误
   38 common/cmd_doc.c 从 DOC 设备读取图像头 OK
  -39 common/cmd_doc.c 图像标题有错误的幻数
   39 common/cmd_doc.c 图像标题具有正确的幻数
  -40 common/cmd_doc.c 从 DOC 设备读取图像时出错
   40 common/cmd_doc.c 图像标题具有正确的幻数
   41 common/cmd_ide.c 在从 IDE 设备加载图像之前
  -42 common/cmd_ide.c “ide”命令的错误使用
   42 common/cmd_ide.c “ide”命令的正确用法
  -43 common/cmd_ide.c 无启动设备
   43 common/cmd_ide.c 找到启动设备
  -44 common/cmd_ide.c 设备不可用
   44 common/cmd_ide.c 设备可用
  -45 common/cmd_ide.c 选择了错误的分区
   选择45个common/cmd_ide.c分区
  -46 common/cmd_ide.c 未知分区表
   46 common/cmd_ide.c 找到有效的分区表
  -47 common/cmd_ide.c 无效的分区类型
   47 common/cmd_ide.c 正确的分区类型
  -48 common/cmd_ide.c 在启动设备上读取图像标头时出错
   48 common/cmd_ide.c 从 IDE 设备读取图像头 OK
  -49 common/cmd_ide.c 图像头有错误的幻数
   49 common/cmd_ide.c 图像头具有正确的幻数
  -50 common/cmd_ide.c 图像头的校验和错误
   50 common/cmd_ide.c 图像头具有正确的校验和
  -51 common/cmd_ide.c 从 IDE 设备读取图像时出错
   51 common/cmd_ide.c 从 IDE 设备读取图像 OK
   52 common/cmd_nand.c 在从 NAND 设备加载图像之前
  -53 common/cmd_nand.c “nand”命令的错误使用
   53 common/cmd_nand.c “nand”命令的正确用法
  -54 common/cmd_nand.c 无启动设备
   54 common/cmd_nand.c 找到启动设备
  -55 common/cmd_nand.c 启动设备上的未知芯片 ID
   55 common/cmd_nand.c 找到正确的芯片 ID，设备可用
  -56 common/cmd_nand.c 读取引导设备上的图像标头时出错
   56 common/cmd_nand.c 从 NAND 设备读取 Image Header OK
  -57 common/cmd_nand.c 图像头有错误的幻数
   57 common/cmd_nand.c 图像头具有正确的幻数
  -58 common/cmd_nand.c 从 NAND 设备读取图像时出错
   58 common/cmd_nand.c 从NAND设备读取Image OK

  -60 common/env_common.c 环境有错误的 CRC，使用默认值

   64 net/eth.c 从以太网配置开始。
  -64 net/eth.c 未找到以太网。
   65 net/eth.c 找到以太网。

  -80 common/cmd_net.c使用错误
   80 调用 net_loop() 之前的 common/cmd_net.c
  -81 common/cmd_net.c net_loop() 中发生一些错误
   81 common/cmd_net.c net_loop() 返回无错误
  -82 common/cmd_net.c size == 0（加载大小为0的文件）
   82 common/cmd_net.c 尝试自动启动
   83 common/cmd_net.c 运行“source”命令
  -83 common/cmd_net.c 自动启动或“source”命令中出现一些错误
   84 common/cmd_net.c结束没有错误

FIT u图像格式：

  精氨酸何时何地
  100 common/cmd_bootm.c 内核 FIT 映像格式正确
 -100 common/cmd_bootm.c 内核 FIT 映像格式不正确
  101 common/cmd_bootm.c 无内核子映像单元名称，使用配置
 -101 common/cmd_bootm.c 无法获取内核子映像的配置
  102 common/cmd_bootm.c 指定内核单元名称
 -103 common/cmd_bootm.c 无法获取内核子映像节点偏移量
  103 common/cmd_bootm.c 找到配置节点
  104 common/cmd_bootm.c 获取内核子映像节点偏移量
 -104 common/cmd_bootm.c 内核子映像哈希验证失败
  105 common/cmd_bootm.c 内核子映像哈希验证 OK
 -105 common/cmd_bootm.c 内核子映像适用于不支持的架构
  106 common/cmd_bootm.c 架构检查 OK
 -106 common/cmd_bootm.c 内核子映像类型错误
  107 common/cmd_bootm.c 内核子映像类型 OK
 -107 common/cmd_bootm.c 无法获取内核子映像数据/大小
  108 common/cmd_bootm.c 获取内核子映像数据/大小
 -108 common/cmd_bootm.c 错误的映像类型（不是旧版，FIT）
 -109 common/cmd_bootm.c 无法获取内核子映像类型
 -110 common/cmd_bootm.c 无法获取内核子映像 comp
 -111 common/cmd_bootm.c 无法获取内核子映像操作系统
 -112 common/cmd_bootm.c 无法获取内核子映像加载地址
 -113 common/cmd_bootm.c 图像解压缩/复制覆盖错误

  120 common/image.c 开始初始 ramdisk 验证
 -120 common/image.c Ramdisk FIT 映像格式不正确
  121 common/image.c Ramdisk FIT 映像格式正确
  122 common/image.c 无 ramdisk 子映像单元名称，使用配置
 -122 common/image.c 无法获取 ramdisk 子映像的配置
  123 common/image.c 指定 Ramdisk 单元名称
 -124 common/image.c 无法获取 ramdisk 子映像节点偏移量
  125 common/image.c 获取 ramdisk 子映像节点偏移量
 -125 common/image.c Ramdisk 子映像哈希验证失败
  126 common/image.c Ramdisk 子镜像哈希验证 OK
 -126 common/image.c 不支持的架构的 Ramdisk 子映像
  127 common/image.c 架构检查 OK
 -127 common/image.c 无法获取 ramdisk 子映像数据/大小
  128 common/image.c 获取 ramdisk 子映像数据/大小
  129 common/image.c 无法获取 ramdisk 加载地址
 -129 common/image.c 获取 ramdisk 加载地址

 -130 common/cmd_doc.c FIT图像格式不正确
  131 common/cmd_doc.c FIT图像格式OK

 -140 common/cmd_ide.c FIT图像格式不正确
  141 common/cmd_ide.c FIT图像格式OK

 -150 common/cmd_nand.c FIT图像格式不正确
  151 common/cmd_nand.c FIT图像格式OK

- 旧图像格式：
		CONFIG_IMAGE_FORMAT_LEGACY
		在 U-Boot 中启用旧图像格式支持。

		默认：
		如果未定义 CONFIG_FIT_SIGNATURE，则启用。

		CONFIG_DISABLE_IMAGE_LEGACY
		禁用旧图像格式

		引入此定义是因为旧图像格式是
		默认启用以实现向后兼容性。

- FIT图像支持：
		CONFIG_FIT_DISABLE_SHA256
		支持 SHA256 哈希对二进制大小有很大影响。
		对于受限系统，可以禁用 sha256 哈希支持
		有了这个选项。

		TODO(sjg@chromium.org)：将此选项调整为正，
		并将其移至 Kconfig

- 独立程序支持：
		CONFIG_STANDALONE_LOAD_ADDR

		该选项定义了板的特定值
		加载独立程序的地址，因此
		覆盖依赖于体系结构的默认值
		设置。

- 帧缓冲区地址：
		配置_FB_地址

		如果要使用特定的，请定义 CONFIG_FB_ADDR
		帧缓冲区的地址。通常是这种情况
		当使用图形控制器时有单独的视频
		记忆。然后，U-Boot 会将帧缓冲区放置在
		给定的地址而不是动态保留它
		通过调用 lcd_setmem() 在系统 RAM 中获取
		帧缓冲区的内存取决于
		配置面板尺寸。

		请参阅 board_init_f 函数。

- 通过 TFTP 服务器自动软件更新
		CONFIG_UPDATE_TFTP
		CONFIG_UPDATE_TFTP_CNT_MAX
		CONFIG_UPDATE_TFTP_MSEC_MAX

		这些选项启用和控制自动更新功能；
		有关更详细的说明，请参阅 doc/README.update。

- MTD 支持（mtdparts 命令、UBI 支持）
		配置_MTD_设备

		从 Linux 内核添加 MTD 设备基础设施。
		mtdparts 命令支持所需。

		CONFIG_MTD_PARTITIONS

		从 Linux 添加 MTD 分区基础架构
		核心。需要 UBI 支持。

- 全民基本收入支持
		CONFIG_CMD_UBI

		添加与格式化的 MTD 分区交互的命令
		带有 UBI 闪存转换层

		还需要定义 CONFIG_RBTREE

		CONFIG_UBI_SILENCE_MSG

		停止打印来自 UBI 的详细消息。这留下
		启用警告和错误。


		CONFIG_MTD_UBI_WL_THRESHOLD
		该参数定义了最高值之间的最大差异
		擦除计数器值和擦除块的最低擦除计数器值
		UBI 设备。当超过此阈值时，UBI 开始执行
		通过从低擦除的擦除块中移动数据来实现磨损均衡
		具有高擦除计数器的擦除块计数器。

		对于 SLC NAND 闪存、NOR 闪存和
		其他擦除块生命周期为 100000 或以上的闪存。
		然而，对于通常具有擦除块的 MLC NAND 闪存
		生命周期小于10000，应降低阈值（例如，
		到 128 或 256，但不一定是 2 的幂）。

		默认值：4096

		CONFIG_MTD_UBI_BEB_LIMIT
		该选项指定最大坏物理擦除块UBI
		预期在 MTD 设备上（每 1024 个擦除块）。如果
		底层闪存不允许有坏的擦除块（例如 NOR
		flash），该值被忽略。

		NAND 数据表通常指定最小和最大 NVM
		（有效块数）决定闪光灯的耐用寿命。
		每 1024 个擦除块的最大预期坏擦除块
		那么可以计算为“1024 * (1 - MinNVB / MaxNVB)”，
		大多数 NAND 的值为 20（MaxNVB 基本上是总数
		芯片上擦除块的数量）。

		换句话说，如果这个值为20，UBI会尝试
		为坏块保留约1.9%的物理擦除块
		处理。这将占整个擦除块的 1.9%
		NAND芯片，不仅仅是UBI附加的MTD分区。这意味着
		如果你有一个 NAND 闪存芯片最多承认 40 个坏点
		擦除块，并且它被分割在相同的两个MTD分区上
		大小，UBI在附加一个擦除块时将保留40个擦除块
		分割。

		默认值：20

		CONFIG_MTD_UBI_FASTMAP
		Fastmap 是一种允许附加 UBI 设备的机制
		在几乎恒定的时间内。它不是扫描整个 MTD 设备
		只需要在设备上找到一个检查点（称为 fastmap）。
		闪存快速地图包含附加所需的所有信息
		装置。使用 fastmap 仅在大型设备上才有意义
		通过扫描附加需要很长时间。 UBI不会自动安装
		旧图像上的快速地图，但您可以设置 UBI 参数
		如果需要，可将 CONFIG_MTD_UBI_FASTMAP_AUTOCONVERT 设置为 1。请注意
		支持 fastmap 的图像仍然可以与 UBI 实现一起使用
		没有快速地图支持。在典型的闪存设备上，整个快速地图
		适合一个 PEB。 UBI 将预留 PEB 来保存两张快速地图。

		CONFIG_MTD_UBI_FASTMAP_AUTOCONVERT
		设置此参数以在图像上自动启用快速地图
		没有快速地图。
		默认值：0

		CONFIG_MTD_UBI_FM_DEBUG
		启用 UBI fastmap 调试
		默认值：0

-UBIFS 支持
		CONFIG_CMD_UBIFS

		添加与 UBI 卷交互的命令，格式为
		UBIFS。 UBIFS 在 u-boot 中是只读的。

		需要 UBI 支持以及 CONFIG_LZO

		CONFIG_UBIFS_SILENCE_MSG

		停止打印来自 UBIFS 的详细消息。这留下
		启用警告和错误。

- SPL框架
		配置_SPL
		启用全局 SPL 构建。

		配置_SPL_LDSCRIPT
		LDSCRIPT 用于链接 SPL 二进制文件。

		CONFIG_SPL_MAX_FOOTPRINT
		分配给 SPL（包括 BSS）的最大内存大小。
		定义后，链接器检查实际内存
		SPL 从 _start 到 __bss_end 使用的数量不超过它。
		CONFIG_SPL_MAX_FOOTPRINT 和 CONFIG_SPL_BSS_MAX_SIZE
		不能同时定义。

		CONFIG_SPL_MAX_SIZE
		SPL 图像的最大大小（文本、数据、rodata 和
		链接器列出了部分），BSS 除外。
		定义后，链接器会检查实际大小
		不超过它。

		CONFIG_SPL_TEXT_BASE
		TEXT_BASE 用于链接 SPL 二进制文件。

		CONFIG_SPL_RELOC_TEXT_BASE
		搬迁地址。如果未指定，则等于
		CONFIG_SPL_TEXT_BASE（即不进行重定位）。

		CONFIG_SPL_BSS_START_ADDR
		SPL 二进制文件中 BSS 的链接地址。

		CONFIG_SPL_BSS_MAX_SIZE
		分配给 SPL BSS 的最大内存大小。
		定义后，链接器检查实际使用的内存
		从 __bss_start 到 __bss_end 的 SPL 不超过它。
		CONFIG_SPL_MAX_FOOTPRINT 和 CONFIG_SPL_BSS_MAX_SIZE
		不能同时定义。

		配置_SPL_堆栈
		SPL 将使用的堆栈起始地址

		CONFIG_SPL_PANIC_ON_RAW_IMAGE
		定义后，如果 SPL 具有图像，则 SPL 将panic()
		加载没有签名。
		当代码加载图像时定义它很有用
		在SPL中不能保证绝对所有的读取错误
		会被抓住的。
		一个例子是 LPC32XX MLC NAND 驱动程序，它将
		认为完全不可读的 NAND 块是坏的，
		因此应该默默地跳过。

		CONFIG_SPL_ABORT_ON_RAW_IMAGE
		定义后，SPL 将继续执行另一种引导方法
		如果它加载的图像没有签名。

		CONFIG_SPL_RELOC_STACK
		之后将使用的堆栈 SPL 的起始地址
		搬迁。如果未指定，则等于
		CONFIG_SPL_STACK。

		CONFIG_SYS_SPL_MALLOC_START
		SPL 中使用的 malloc 池的起始地址。
		设置此选项后，SPL 中将使用完整的 malloc，并且
		它是由 spl_init() 设置的，在此之前是简单的 malloc()
		如果定义了 CONFIG_SYS_MALLOC_F 则可以使用。

		CONFIG_SYS_SPL_MALLOC_SIZE
		SPL 中使用的 malloc 池的大小。

		配置_SPL_框架
		启用common/下的SPL框架。这个框架
		支持U-Boot和NAND的MMC、NAND和YMODEM加载
		Linux 内核的 NAND 加载。

		CONFIG_SPL_OS_BOOT
		启用从 SPL 直接引导至操作系统。
		另请参阅：doc/README.falcon

		CONFIG_SPL_DISPLAY_PRINT
		对于 ARM，启用可选功能以打印更多信息
		关于运行系统。

		CONFIG_SPL_INIT_MINIMAL
		Arch 初始化代码应该为非常小的图像构建

		CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_PARTITION
		对 MMC 进行分区，以便在 MMC 启动时加载 U-Boot
		在原始模式下使用

		CONFIG_SYS_MMCSD_RAW_MODE_KERNEL_SECTOR
		MMC 运行时加载内核 uImage 的扇区
		用于原始模式（用于 Falcon 模式）

		CONFIG_SYS_MMCSD_RAW_MODE_ARGS_SECTOR，
		CONFIG_SYS_MMCSD_RAW_MODE_ARGS_SECTORS
		加载内核参数的扇区和扇区数
		MMC 在原始模式下使用时的参数
		（适用于猎鹰模式）

		CONFIG_SYS_MMCSD_FS_BOOT_PARTITION
		对 MMC 进行分区，以便在 MMC 启动时加载 U-Boot
		用于 fs 模式

		CONFIG_SPL_FS_LOAD_PAYLOAD_NAME
		从文件系统读取时加载 U-Boot 时要读取的文件名

		CONFIG_SPL_FS_LOAD_KERNEL_NAME
		读取时加载内核 uImage 的文件名
		来自文件系统（对于 Falcon 模式）

		CONFIG_SPL_FS_LOAD_ARGS_NAME
		要读取以加载内核参数的文件名
		从文件系统读取时（对于 Falcon 模式）

		CONFIG_SPL_MPC83XX_WAIT_FOR_NAND
		为 PPC mpc83xx 目标上的 NAND SPL 设置此项，以便
		start.S 等待 SPL 的其余部分加载之前
		继续（硬件在刚刚之后开始执行
		加载第一页而不是完整的 4K）。

		CONFIG_SPL_SKIP_RELOCATE
		避免 SPL 重新定位

		CONFIG_SPL_NAND_BASE
		将 nand_base.c 包含在 SPL 中。需要
		CONFIG_SPL_NAND_DRIVERS。

		CONFIG_SPL_NAND_驱动程序
		SPL 使用普通 NAND 驱动程序，而不是最小驱动程序。

		配置_SPL_NAND_ECC
		在 SPL 中包含标准软件 ECC

		CONFIG_SPL_NAND_SIMPLE
		使用简单的 NAND 驱动程序支持 NAND 启动
		公开 cmd_ctrl() 接口。

		配置_SPL_UBI
		支持轻量级 UBI（快速地图）扫描仪和
		装载机

		CONFIG_SPL_NAND_RAW_ONLY
		支持仅启动原始 u-boot.bin 映像。仅使用此
		如果您需要节省空间。

		CONFIG_SPL_COMMON_INIT_DDR
		设置为带有串行存在检测的通用 ddr 初始化
		SPL 二进制。

		CONFIG_SYS_NAND_5_ADDR_CYCLE、CONFIG_SYS_NAND_PAGE_COUNT、
		CONFIG_SYS_NAND_PAGE_SIZE、CONFIG_SYS_NAND_OOBSIZE、
		CONFIG_SYS_NAND_BLOCK_SIZE、CONFIG_SYS_NAND_BAD_BLOCK_POS、
		CONFIG_SYS_NAND_ECCPOS、CONFIG_SYS_NAND_ECCSIZE、
		CONFIG_SYS_NAND_ECCBYTES
		定义 SPL 使用的 NAND 的大小和行为
		读取U-Boot

		CONFIG_SPL_NAND_BOOT
		添加支持NAND启动

		CONFIG_SYS_NAND_U_BOOT_OFFS
		NAND 中读取 U-Boot 的位置

		CONFIG_SYS_NAND_U_BOOT_DST
		内存中加载 U-Boot 的位置

		CONFIG_SYS_NAND_U_BOOT_SIZE
		要加载的图像大小

		CONFIG_SYS_NAND_U_BOOT_START
		加载图像中要跳转到的入口点

		CONFIG_SYS_NAND_HW_ECC_OOBFIRST
		如果您需要先读取 OOB，然后读取
		数据。例如，这用于达芬奇平台。

		CONFIG_SPL_OMAP3_ID_NAND
		支持一组特定于 OMAP3 的函数来返回
		第一个连接的 NAND 芯片的 ID 和 MFR（如果存在）。

		CONFIG_SPL_RAM_DEVICE
		支持运行 RAM 中已存在的 SPL 二进制映像

		配置_SPL_PAD_TO
		在附加之前应将 SPL 填充到的图像偏移量
		SPL 有效负载。默认情况下，这定义为
		CONFIG_SPL_MAX_SIZE，如果 CONFIG_SPL_MAX_SIZE 未定义，则为 0。
		CONFIG_SPL_PAD_TO 必须为 0，表示附加 SPL
		没有任何填充的有效负载，或 >= CONFIG_SPL_MAX_SIZE。

		配置_SPL_目标
		最终目标图像包含 SPL 和有效负载。一些 SPL
		使用特定于架构的 makefile 片段来代替，例如
		例如，如果需要生成多张图像。

		CONFIG_FIT_SPL_PRINT
		打印有关 FIT 图像的信息会增加相当多的信息
		代码为 SPL。所以这通常在 SPL 中被禁用。用这个
		选项来重新启用它。这会影响输出
		启动 FIT 映像时的 bootm 命令。

- TPL框架
		配置_TPL
		推动全球第三方物流建设。

		CONFIG_TPL_PAD_TO
		在附加之前应将 TPL 填充到的图像偏移量
		TPL 有效负载。默认情况下，这定义为
		CONFIG_SPL_MAX_SIZE，如果 CONFIG_SPL_MAX_SIZE 未定义，则为 0。
		CONFIG_SPL_PAD_TO 必须为 0，表示附加 SPL
		没有任何填充的有效负载，或 >= CONFIG_SPL_MAX_SIZE。

- 中断支持（PPC）：

		常见的有interrupt_init()和timer_interrupt()
		适用于所有 PPC 拱门。中断_init() 调用中断_init_cpu()
		用于CPU特定的初始化。中断_init_cpu()
		应将 decrementer_count 设置为适当的值。如果
		CPU在中断后自动复位减量器
		(ppc4xx) 它应该将 decrementer_count 设置为零。
		timer_interrupt() 调用timer_interrupt_cpu() 获取CPU
		具体处理。如果主板有看门狗/status_led
		/ other_activity_monitor 它自动工作
		通用timer_interrupt()。


板初始化设置：
------------------------------------------

在初始化期间，u-boot 调用许多板特定函数
允许准备电路板特定的先决条件，例如引脚设置
在驱动程序初始化之前。要启用这些回调
必须定义以下配置宏。目前这是
特定于架构，因此请检查 arch/your_architecture/lib/board.c
通常在 board_init_f() 和 board_init_r() 中。

- CONFIG_BOARD_EARLY_INIT_F：调用board_early_init_f()
- CONFIG_BOARD_EARLY_INIT_R：调用 board_early_init_r()
- CONFIG_BOARD_LATE_INIT：调用 board_late_init()
- CONFIG_BOARD_POSTCLK_INIT：调用board_postclk_init()

配置设置：
-----------------------

- CONFIG_SYS_SUPPORT_64BIT_DATA：如果编译为 64 位，则自动定义。
		可以选择将其定义为支持 64 位内存命令。

- CONFIG_SYS_LONGHELP：当您想要包含长帮助消息时定义；
		当你内存不足时取消定义它。

- CONFIG_SYS_HELP_CMD_WIDTH：当您想要覆盖默认值时定义
		“help”命令输出中列出的命令的宽度。

- CONFIG_SYS_PROMPT：这是 U-Boot 在控制台上打印的内容
		提示用户输入。

- CONFIG_SYS_CBSIZE：控制台输入的缓冲区大小

- CONFIG_SYS_PBSIZE：控制台输出的缓冲区大小

- CONFIG_SYS_MAXARGS：最大。监视器命令接受的参数数量

- CONFIG_SYS_BARGSIZE：传递给的引导参数的缓冲区大小
		应用程序（通常是 Linux 内核）
		启动

- 配置_系统_波特率_表：
		该板的合法波特率设置列表。

- CONFIG_SYS_MEMTEST_START、CONFIG_SYS_MEMTEST_END：
		所使用区域的开始和结束地址
		简单的记忆测试。

- CONFIG_SYS_ALT_MEMTEST：
		启用替代的、更广泛的内存测试。

- CONFIG_SYS_MEMTEST_SCRATCH：
		备用内存测试使用的暂存地址
		仅当地址零不可写时才需要设置此项

- CONFIG_SYS_MEM_RESERVE_SECURE
		目前仅针对 ARMv8 实现。
		如果已定义，则为 CONFIG_SYS_MEM_RESERVE_SECURE 内存的大小
		从总 RAM 中减去，不会报告给操作系统。
		该存储器可以用作安全存储器。一个变量
		gd->arch.secure_ram 用于跟踪位置。在系统中
		RAM 基数不为零，或者 RAM 被划分为多个存储体，
		需要重新计算该变量才能获取地址。

- CONFIG_SYS_MEM_TOP_HIDE：
		如果 CONFIG_SYS_MEM_TOP_HIDE 在板配置标头中定义，
		这个指定的内存区域将从顶部减去
		（结束）RAM 并且不会被 U-Boot“触及”。经过
		修复 gd->ram_size Linux 内核应该通过
		现在“更正”的内存大小，也不会触及它。
		这应该适用于 arch/ppc 和 arch/powerpc。仅Linux
		arch/powerpc 中的板端口带有 bootwrapper 支持
		从 SDRAM 控制器设置重新计算内存大小
		还必须在 Linux 中进行修复。

		此选项可用作 440EPx/GRx 的解决方法
		CHIP 11 勘误表，其中 SDRAM 中的最后 256 字节不应该
		被感动。

		警告：请确保该值是以下值的倍数
		Linux 页面大小（通常为 4k）。如果情况并非如此，
		那么Linux内存的结束地址将位于
		非页面大小对齐地址，这可能会导致重大
		问题。

- CONFIG_SYS_LOADS_BAUD_CHANGE：
		串行下载时启用临时波特率更改

- CONFIG_SYS_SDRAM_BASE：
		SDRAM的物理起始地址。这里_必须_为0。

- CONFIG_SYS_FLASH_BASE：
		Flash存储器的物理起始地址。

- CONFIG_SYS_MONITOR_BASE：
		启动监视器代码的物理起始地址（由
		使配置文件与文本基地址相同
		(CONFIG_SYS_TEXT_BASE) 链接时使用） - 与
		从闪存启动时的 CONFIG_SYS_FLASH_BASE。

- CONFIG_SYS_MONITOR_LEN：
		为监控代码保留的内存大小，用于
		确定_at_compile_time_（！）如果环境是
		嵌入到 U-Boot 映像中，或者单独的
		闪存扇区。

- CONFIG_SYS_MALLOC_LEN：
		保留供 malloc() 使用的 DRAM 大小。

- CONFIG_SYS_MALLOC_F_LEN
		重定位之前使用的 malloc() 池的大小。如果
		这是定义的，然后是一个非常简单的 malloc() 实现
		将在搬迁前可用。地址只是
		低于全局数据，并且堆栈向下移动以使得
		空间。

		此功能分配地址递增的区域
		区域内。支持 calloc()，但支持 realloc()
		不可用。支持 free() 但不执行任何操作。
		内存将被释放（或者实际上只是被遗忘）
		U-Boot 自行重新定位。

- CONFIG_SYS_MALLOC_SIMPLE
		为那些提供简单而小的 malloc() 和 calloc()
		在 SPL 中不使用完整 malloc 的板（即
		通过 CONFIG_SYS_SPL_MALLOC_START 启用）。

- CONFIG_SYS_NONCACHED_MEMORY：
		非缓存内存区域的大小。该内存区域将是
		通常位于 malloc() 区域的正下方并映射
		未缓存在 MMU 中。这对于那些需要
		否则需要大量显式缓存维护。为了
		有些司机也无法正确维护
		缓存。例如，如果需要刷新的区域
		不是缓存行大小、*和*填充的倍数
		不能在区域之间分配来对齐它们（即
		如果硬件需要连续的区域数组，并且
		每个区域的大小不是缓存对齐的），然后刷新
		一个区域可能会导致覆盖硬件已有的数据
		写入同一缓存行中的另一个区域。这个可以
		例如在网络驱动程序中发生的情况，其中描述符
		缓冲区通常小于 CPU 高速缓存行（例如
		16 字节与 32 或 64 字节）。

		目前仅 32 位 ARM 支持非缓存内存。

- CONFIG_SYS_BOOTM_LEN：
		通常压缩的 uImage 仅限于
		未压缩大小为 8 MB。如果这还不够，
		您可以在板配置文件中定义 CONFIG_SYS_BOOTM_LEN
		根据您的需要调整此设置。

- CONFIG_SYS_BOOTMAPSZ：
		启动代码映射的最大内存大小
		Linux 内核；所有必须处理的数据
		Linux 内核（bd_info、启动参数、FDT blob，如果
		使用）必须低于此限制，除非“bootm_low”
		环境变量已定义且非零。在这种情况下
		Linux 内核的所有数据必须在“bootm_low”之间
		和“bootm_low”+ CONFIG_SYS_BOOTMAPSZ。环境
		变量“bootm_mapsize”将覆盖的值
		CONFIG_SYS_BOOTMAPSZ。如果 CONFIG_SYS_BOOTMAPSZ 未定义，
		那么将使用“bootm_size”中的值。

- CONFIG_SYS_BOOT_RAMDISK_HIGH：
		启用 initrd_high 功能。如果定义的话
		initrd_high 功能已启用并且 bootm ramdisk 子命令
		已启用。

- CONFIG_SYS_BOOT_GET_CMDLINE：
		允许在之间的空间中分配和保存内核命令行
		“bootm_low”和“bootm_low”+ BOOTMAPSZ。

- CONFIG_SYS_BOOT_GET_KBD：
		允许在以下位置分配和保存 bd_info 的内核副本
		“bootm_low”和“bootm_low”+ BOOTMAPSZ 之间的空格。

- CONFIG_SYS_MAX_FLASH_BANKS：
		最大闪存存储体数量

- CONFIG_SYS_MAX_FLASH_SECT：
		Flash芯片上的最大扇区数

- CONFIG_SYS_FLASH_ERASE_TOUT：
		闪存擦除操作超时（以毫秒为单位）

- CONFIG_SYS_FLASH_WRITE_TOUT：
		闪存写入操作超时（以毫秒为单位）

- CONFIG_SYS_FLASH_LOCK_TOUT
		闪存设置扇区锁定位操作的超时（以毫秒为单位）

- CONFIG_SYS_FLASH_UNLOCK_TOUT
		闪存清除锁定位操作超时（以毫秒为单位）

- CONFIG_SYS_FLASH_PROTECTION
		如果定义，则使用硬件闪存扇区保护
		而不是 U-Boot 软件保护。

- CONFIG_SYS_DIRECT_FLASH_TFTP：

		启用 TFTP 直接传输到闪存；
		如果没有此选项，则必须进行下载
		分两步执行：(1) 下载到 RAM，以及 (2)
		从 RAM 复制到闪存。

		两步法通常更可靠，因为
		您可以在擦除之前检查下载是否有效
		闪存，但在某些情况下（当系统RAM
		太有限，无法临时复制
		下载的图像）这个选项可能非常有用。

- CONFIG_SYS_FLASH_CFI：
		定义闪存驱动程序是否使用额外的元素
		用于存储闪存几何结构的通用闪存结构。

- CONFIG_FLASH_CFI_DRIVER
		此选项还可以构建 cfi_flash 驱动程序
		在驱动程序目录中

- CONFIG_FLASH_CFI_MTD
		此选项允许构建 cfi_mtd 驱动程序
		在驱动程序目录中。驱动导出CFI flash
		到MTD层。

- CONFIG_SYS_FLASH_USE_BUFFER_WRITE
		使用缓冲写入闪存。

- CONFIG_FLASH_SPANION_S29WS_N
		s29ws-n MirrorBit 闪存具有用于缓冲的非标准地址
		写命令。

- CONFIG_SYS_FLASH_QUIET_TEST
		如果定义了该选项，则普通CFI flash不会
		在无法识别的闪存库上打印警告。这
		很有用，如果某些配置的银行只是
		可选。

- CONFIG_FLASH_SHOW_PROGRESS
		如果定义（必须是整数），则打印出倒计时
		数字和点。建议值：45 (9..1) for 80
		列显示，15 (3..1) 表示 40 列显示。

- 配置_闪存_验证
		如果定义，则比较闪存（目标）的内容
		写操作后针对源。错误消息
		当内容不相同时将打印。
		请注意，此选项几乎在所有情况下都是无用的，
		因为此类闪存编程错误通常会更早被检测到
		同时取消保护/擦除/编程。请仅启用
		如果您确实知道自己在做什么，则可以选择此选项。

- CONFIG_SYS_RX_ETH_BUFFER：
		定义以太网接收缓冲区的数量。一些
		以太网控制器建议设置该值
		到 8 甚至更高（EEPRO100 或 405 EMAC），因为所有
		启用接口后不久缓冲区可能会满
		在高以太网流量上。
		如果未定义，则默认为 4。

- CONFIG_ENV_MAX_ENTRIES

	使用的哈希表中的最大条目数
	内部存储环境设置。默认
	设置应该是慷慨的并且应该适用于大多数
	案例。此设置可用于调整行为；看
	lib/hashtable.c 了解详细信息。

- CONFIG_ENV_FLAGS_LIST_DEFAULT
- CONFIG_ENV_FLAGS_LIST_STATIC
	启用对环境变量指定值的验证
	调用环境集。变量只能限制为小数，
	十六进制或布尔值。如果 CONFIG_CMD_NET 也被定义，
	变量还可以限制为 IP 地址或 MAC 地址。

	列表的格式为：
		类型属性 = [s|d|x|b|i|m]
		访问属性 = [a|r|o|c]
		属性 = 类型属性[访问属性]
		条目 = 变量名[:属性]
		列表 = 条目[,列表]

	类型属性有：
		s - 字符串（默认）
		d - 十进制
		x - 十六进制
		b - 布尔值 ([1yYtT|0nNfF])
		i - IP 地址
		m - MAC 地址

	访问属性有：
		a - 任何（默认）
		r - 只读
		o - 一次写入
		c - 更改默认值

	- CONFIG_ENV_FLAGS_LIST_DEFAULT
		将其定义为列表（字符串）以定义“.flags”
		默认或嵌入式环境中的环境变量。

	- CONFIG_ENV_FLAGS_LIST_STATIC
		将其定义为列表（字符串）以定义验证
		如果在“.flags”中找不到条目，​​则应执行此操作
		环境变量。覆盖静态中的设置
		列表中，只需将相同变量名的条目添加到
		“.flags”变量。

	如果定义了 CONFIG_REGEX，则上面的变量名称将被评估为
	正则表达式。这允许多个变量定义相同的
	标志，但没有为每个变量明确列出它们。

- CONFIG_ENV_ACCESS_IGNORE_FORCE
	如果已定义，则不允许 -f 切换到 env set override 变量
	访问标志。

- CONFIG_OMAP_PLATFORM_RESET_TIME_MAX_USEC（仅限 OMAP）
	这是由 OMAP 板设置的重置应该的最长时间
	被断言。有关如何操作的详细信息，请参阅 doc/README.omap-reset-time
	该值可以在给定的板上计算。

- CONFIG_USE_STDINT
	如果 stdint.h 在您的工具链中可用，您可以定义它
	选项来启用它。您可以在以下情况下提供选项“USE_STDINT=1”：
	构建 U-Boot 来实现这一点。

以下涉及放置和管理的定义
环境数据（可变区域）；总的来说，我们支持
以下配置：

- CONFIG_BUILD_ENVCRC：

	使用目标环境构建 envcrc，以便外部实用程序
	可以轻松提取它并将其嵌入到最终的 U-Boot 映像中。

- CONFIG_ENV_IS_IN_FLASH：

	如果环境位于闪存中，请定义此项。

	a) 环境占用一整个闪存扇区，即
	   “嵌入”到带有 U-Boot 代码的文本段中。这
	   通常发生在“底部引导扇区”或“顶部引导”
	   扇区”型闪存芯片，其中有几个较小的
	   开头或结尾的扇区。例如，这样一个
	   布局的扇区大小可以为 8、2x4、16、Nx32 kB。在
	   在这种情况下，您可以将环境置于其中之一
	   4 kB 扇区 - 前后都有 U-Boot 代码。和
	   “顶部引导扇区”类型的闪存芯片，你可以把
	   最后一个部门的环境，留下了差距
	   U-Boot 和环境之间。

	- CONFIG_ENV_OFFSET：

	   环境数据（变量区域）的偏移量
	   闪存的开始；例如，带有底部引导
	   类型flash芯片第二个扇区可以使用：偏移量
	   此处给出了该部门的信息。

	   CONFIG_ENV_OFFSET 是相对于 CONFIG_SYS_FLASH_BASE 使用的。

	- CONFIG_ENV_ADDR：

	   这只是指定起始地址的另一种方法
	   包含环境的闪存扇区（而不是
	   CONFIG_ENV_OFFSET）。

	- CONFIG_ENV_SECT_SIZE：

	   包含环境的部门的规模。


	b) 有时，闪存芯片的扇区数量很少、大小相同、很大。
	   在这种情况下，您不想花费整个扇区
	   环境。

	- 配置环境大小：

	   如果将此与 CONFIG_ENV_IS_IN_FLASH 结合使用
	   和CONFIG_ENV_SECT_SIZE，可以指定只使用一部分
	   该闪存扇区的环境。这节省了
	   环境的 RAM 副本的内存。

	   如果您决定使用它，它还可以节省闪存
	   当您的环境“嵌入”到 U-Boot 代码中时，
	   从那时起，闪存扇区的剩余部分就可以使用了
	   U-Boot 代码。需要指出的是，这是
	   从稳健性的角度来看，强烈建议不要这样做：
	   更新闪存中的环境使其始终
	   需要擦除整个扇区。如果有事发生
	   在从副本恢复内容之前错误
	   RAM，你的目标系统将会死掉。

	- CONFIG_ENV_ADDR_REDUND
	  CONFIG_ENV_SIZE_REDUND

	   这些设置描述了用于保存的第二个存储区域
	   环境数据的冗余副本，以便有
	   有效的备份副本，以防期间发生电源故障
	   “saveenv”操作。

当心！对闪存布局的任何更改以及对
源代码将需要修改 <board>/u-boot.lds*
因此！


- CONFIG_ENV_IS_IN_NVRAM：

	如果您有一些非易失性存储设备，请定义此项
	（NVRAM，电池缓冲 SRAM）
	环境。

	- CONFIG_ENV_ADDR：
	- 配置环境大小：

	  这两个#define用来确定你的内存区域
	  想要用于环境。假设这个内存
	  可以直接读取和写入，无需任何特殊操作
	  条款。

当心！第一次接触环境发生得很早
在 U-Boot 初始化中（当我们尝试获取
控制台波特率）。那么您*必须*已经映射了您的 NVRAM 区域，或者
U-Boot 将挂起。

请注意，即使使用 NVRAM，我们仍然使用
RAM 中的环境：我们可以直接在 NVRAM 上工作，但我们想要
保持设置始终不变，除非有人使用“saveenv”
保存当前设置。


- CONFIG_ENV_IS_IN_EEPROM：

	如果您有 EEPROM 或类似的串行访问，请使用此选项
	设备及其驱动程序。

	- CONFIG_ENV_OFFSET：
	- 配置环境大小：

	  这两个#define指定了偏移量和大小
	  EEPROM 总内存中的环境区域。

	- CONFIG_SYS_I2C_EEPROM_ADDR：
	  如果已定义，则指定 EEPROM 设备的芯片地址。
	  默认地址为零。

	- CONFIG_SYS_I2C_EEPROM_BUS：
	  如果定义，则指定 EEPROM 设备的 i2c 总线。

	- CONFIG_SYS_EEPROM_PAGE_WRITE_BITS：
	  如果已定义，则用于寻址字节中的位数
	  EEPROM 器件中的单页。例如，64 字节页
	  需要六位。

	- CONFIG_SYS_EEPROM_PAGE_WRITE_DELAY_MS：
	  如果已定义，则延迟的毫秒数
	  页写道。默认值为零毫秒。

	- CONFIG_SYS_I2C_EEPROM_ADDR_LEN：
	  EEPROM 存储器阵列地址的长度（以字节为单位）。笔记
	  这不是芯片地址长度！

	- CONFIG_SYS_I2C_EEPROM_ADDR_OVERFLOW：
	  实现“地址溢出”的EEPROM芯片是
	  像 Catalyst 24WC04/08/16 一样，它有 9/10/11 位
	  地址和额外的位最终在“芯片地址”位中
	  插槽。这使得24WC08（1Kbyte）芯片看起来像四个256
	  字节芯片。

	  请注意，我们考虑地址字段的长度
	  仍然是一个字节，因为额外的地址位被隐藏了
	  在芯片地址中。

	- CONFIG_SYS_EEPROM_SIZE：
	  EEPROM 设备的大小（以字节为单位）。

	- CONFIG_ENV_EEPROM_IS_ON_I2C
	  如果您激活了 I2C 和 SPI，并且您的
	  保存环境的 EEPROM 位于 I2C 总线上。

	- CONFIG_I2C_ENV_EEPROM_BUS
	  如果 EEPROM 上的环境达到了
	  I2C 多路复用器，您可以在此处定义，如何实现此目的
	  EEPROM。例如：

	  #定义CONFIG_I2C_ENV_EEPROM_BUS 1

	  保存环境的 EEPROM 已达到
	  一个 pca9547 i2c 多路复用器，地址为 0x70，通道 3。

- CONFIG_ENV_IS_IN_DATAFLASH：

	如果您有一个 DataFlash 存储设备，请定义此项
	想要用于环境。

	- CONFIG_ENV_OFFSET：
	- CONFIG_ENV_ADDR：
	- 配置环境大小：

	  这三个 #define 指定了偏移量和大小
	  您的 DataFlash 总内存中的环境区域
	  在指定地址。

- CONFIG_ENV_IS_IN_SPI_FLASH：

	如果您有 SPI 闪存设备，请定义此项
	想要用于环境。

	- CONFIG_ENV_OFFSET：
	- 配置环境大小：

	  这两个#define指定了偏移量和大小
	  SPI Flash 内的环境区域。 CONFIG_ENV_OFFSET 必须是
	  与擦除扇区边界对齐。

	- CONFIG_ENV_SECT_SIZE：

	  定义 SPI 闪存的扇区大小。

	- CONFIG_ENV_OFFSET_REDUND（可选）：

	  该设置描述了CONFIG_ENV_SIZE的第二个存储区域
	  用于保存环境数据的冗余副本的大小，因此
	  在发生电源故障时有有效的备份副本
	  在“saveenv”操作期间。 CONFIG_ENV_OFFSET_REDUND 必须是
	  与擦除扇区边界对齐。

	- CONFIG_ENV_SPI_BUS（可选）：
	- CONFIG_ENV_SPI_CS（可选）：

	  定义 SPI 总线和片选。如果没有定义，它们将为 0。

	- CONFIG_ENV_SPI_MAX_HZ（可选）：

	  定义 SPI 最大工作时钟。如果未定义则使用 1MHz。

	- CONFIG_ENV_SPI_MODE（可选）：

	  定义SPI工作模式。如果未定义，则使用 SPI_MODE_3。

- CONFIG_ENV_IS_IN_REMOTE：

	如果您有一个远程内存空间，请定义此空间
	想要用于本地设备的环境。

	- CONFIG_ENV_ADDR：
	- 配置环境大小：

	  这两个#define指定了地址和大小
	  远程内存空间内的环境区域。这
	  本地设备可以从远程内存获取环境
	  通过 SRIO 或 PCIE 链路占用空间。

当心！对于某些特殊情况，本地设备无法使用
“saveenv”命令。例如，本地设备将获取
通过 SRIO 或 PCIE 链路存储在远程 NOR 闪存中的环境，
但不能通过SRIO或PCIE接口擦除、写入该NOR Flash。

- CONFIG_ENV_IS_IN_NAND：

	如果您有要使用的 NAND 设备，请定义此项
	为了环境。

	- CONFIG_ENV_OFFSET：
	- 配置环境大小：

	  这两个#defines指定了环境的偏移量和大小
	  第一个 NAND 器件内的区域。 CONFIG_ENV_OFFSET 必须是
	  与擦除块边界对齐。

	- CONFIG_ENV_OFFSET_REDUND（可选）：

	  该设置描述了CONFIG_ENV_SIZE的第二个存储区域
	  用于保存环境数据的冗余副本的大小，因此
	  在发生电源故障时有有效的备份副本
	  在“saveenv”操作期间。 CONFIG_ENV_OFFSET_REDUND 必须是
	  与擦除块边界对齐。

	- CONFIG_ENV_RANGE（可选）：

	  指定环境所在区域的长度
	  可以写。这应该是 NAND 设备的倍数
	  块大小。指定擦除块数多于的范围
	  需要保持 CONFIG_ENV_SIZE 允许坏块
	  应避免的范围。

	- CONFIG_ENV_OFFSET_OOB（可选）：

	  启用对动态检索偏移量的支持
	  来自块零的带外数据的环境。这
	  “nand env.oob”命令可以用来记录这个偏移量。
	  目前，不支持 CONFIG_ENV_OFFSET_REDUND
	  使用 CONFIG_ENV_OFFSET_OOB。

- CONFIG_NAND_ENV_DST

	定义 RAM 中的地址，nand_spl 代码应将
	环境。如果使用冗余环境，则会复制到
	CONFIG_NAND_ENV_DST + CONFIG_ENV_SIZE。

- CONFIG_ENV_IS_IN_UBI：

	如果您有要用于以下用途的 UBI 卷，请定义此项：
	环境。这有利于环境磨损均衡
	访问，这对 NAND 很重要。

	- CONFIG_ENV_UBI_PART：

	  将其定义为一个字符串，该字符串是包含 UBI 的 mtd 分区。

	- CONFIG_ENV_UBI_VOLUME：

	  将此定义为您要存储的卷的名称
	  环境中.

	- CONFIG_ENV_UBI_VOLUME_REDUND：

	  将其定义为另一个卷的名称以存储第二个副本
	  这将在 UBI 中启用冗余环境。
	  假设两个卷位于同一 MTD 分区中。

	- CONFIG_UBI_SILENCE_MSG
	- CONFIG_UBIFS_SILENCE_MSG

	  您可能需要定义这些以避免系统变得非常嘈杂
	  将 env 存储在 UBI 中时。

- CONFIG_ENV_IS_IN_FAT：
       如果您想在环境中使用 FAT 文件系统，请定义此项。

       - FAT_ENV_INTERFACE：

         将其定义为一个字符串，该字符串是块设备的名称。

       - FAT_ENV_DEVICE_AND_PART：

         将其定义为字符串以指定设备的分区。它可以
         如下：

           "D:P"、"D:0"、"D"、"D:" 或 "D:auto" （D、P 为整数。且 P >= 1）
               - “D:P”：设备D分区P。如果设备D没有分区，则会出错
                        分区表。
               - “D:0”：设备 D。
               - “D”或“D:”：如果设备 D 有分区，则设备 D 分区 1
                              表，或者整个设备 D（如果没有分区）
                              桌子。
               - “D:auto”：设备 D 中设置了可引导标志的第一个分区。
                           如果没有，则在设备 D 中第一个有效分区。如果没有
                           分区表则表示设备 D。

       - FAT_ENV_FILE：

         它是 FAT 文件名的字符串。该文件用于存储
         环境。

       - CONFIG_FAT_WRITE：
         这应该被定义。否则无法保存环境文件。

- CONFIG_ENV_IS_IN_MMC：

	如果您有一个 MMC 设备要用于
	环境。

	- CONFIG_SYS_MMC_ENV_DEV：

	  指定环境存储在哪个 MMC 设备中。

	- CONFIG_SYS_MMC_ENV_PART（可选）：

	  指定环境存储在哪个 MMC 分区中。如果没有
	  设置，默认为分区0，用户区。共同的价值观可能是
	  1（第一个 MMC 启动分区）、2（第二个 MMC 启动分区）。

	- CONFIG_ENV_OFFSET：
	- 配置环境大小：

	  这两个#defines指定了环境的偏移量和大小
	  指定 MMC 设备内的区域。

	  如果偏移量为正（通常情况），则将其视为相对于
	  MMC 分区的开始。如果 offset 为负，则进行处理
	  相对于 MMC 分区的末尾。这可能很有用，如果
	  您的主板可能配备了不同的 MMC 设备，这些设备具有
	  MMC 分区的大小不同，并且您始终希望
	  环境放置在分区的最末端，以留下
	  它之前的最大可能空间，用于存储其他数据。

	  这两个值以字节为单位，但必须对齐
	  MMC 扇区边界。

	- CONFIG_ENV_OFFSET_REDUND（可选）：

	  指定 CONFIG_ENV_SIZE 大小的第二个存储区域，用于
	  保存环境数据的冗余副本。这提供了一个
	  有效的备份副本，以防其他副本损坏，例如由于
	  在“saveenv”操作期间发生电源故障。

	  该值也可以是正数或负数；这是在
	  与 CONFIG_ENV_OFFSET 相同。

	  该值也是以字节为单位，但也必须对齐
	  MMC 扇区边界。

	- CONFIG_ENV_SIZE_REDUND（可选）：

	  即使 CONFIG_ENV_OFFSET_REDUND 为
	  放。如果设置了该值，则必须将其设置为与
	  CONFIG_ENV_SIZE。

- CONFIG_SYS_SPI_INIT_OFFSET

	定义 DPRAM 中初始 SPI 缓冲区的偏移量。这
	如果环境良好，则在早期阶段使用区域（ROM部分）
	配置为驻留在 SPI EEPROM 中：我们需要一个 520 字节
	划伤 DPRAM 区域。它在两次初始化之间使用
	调用（spi_init_f() 和 spi_init_r()）。值 0xB00 似乎
	是一个不错的选择，因为它离
	数据区域的开始以及堆栈指针。

请注意，环境是只读的，直到监视器
已重新定位到 RAM，并且环境的 RAM 副本已
创建；另外，当使用 EEPROM 时，您必须使用 getenv_f()
直到那时读取环境变量。

环境受 CRC32 校验和保护。显示器前
被重新定位到 RAM 中，由于 CRC 错误，您将继续工作
使用编译的默认环境 - *默默地*!!! [这是
必要的，因为我们需要的第一个环境变量是
控制台的“波特率”设置 - 如果我们的 CRC 错误，我们不会
有任何设备可供我们投诉。]

注意：一旦显示器被重新定位，那么它会抱怨：
使用默认环境；一旦你计算出一个新的 CRC
使用“saveenv”命令存储有效的环境。

- CONFIG_SYS_FAULT_ECHO_LINK_DOWN：
		将反向以太网链路状态回显到故障 LED。

		注意：如果此选项处于活动状态，则 CONFIG_SYS_FAULT_MII_ADDR
		      也需要定义。

- CONFIG_SYS_FAULT_MII_ADDR：
		用于检查以太网链路状态的 PHY 的 MII 地址。

- CONFIG_NS16550_MIN_FUNCTIONS：
		如果您只想使用 NS16550_init，请定义此项
		和 NS16550_putc 函数用于串行驱动程序，位于
		驱动程序/串行/ns16550.c。该选项对于保存很有用
		空间已经非常有限的图像，包括但不
		仅限于 NAND_SPL 配置。

- CONFIG_DISPLAY_BOARDINFO
		显示有关运行 U-Boot 的板的信息
		当U-Boot启动时。调用棋盘函数 checkboard()
		去做这个。

- CONFIG_DISPLAY_BOARDINFO_LATE
		与上一个选项类似，但显示此信息
		稍后，一旦 stdio 运行并且输出进入 LCD，如果
		展示。

- CONFIG_BOARD_SIZE_LIMIT：
		U-Boot 映像的最大大小。定义时，
		构建系统检查实际大小不
		超过它。

低级（硬件相关）配置选项：
-------------------------------------------------- -

- CONFIG_SYS_CACHELINE_SIZE：
		CPU 的高速缓存线大小。

- CONFIG_SYS_DEFAULT_IMMR：
		系统复位后IMMR的默认地址。

		某些 8260 系统（MPC8260ADS、PQ2FADS-ZU、
		和 RPXsuper）能够调整位置
		复位后的 IMMR 寄存器。

- CONFIG_SYS_CCSRBAR_DEFAULT：
		Freescale 上 CCSR 的默认（上电复位）物理地址
		PowerPC SOC。

- CONFIG_SYS_CCSRBAR：
		CCSR 的虚拟地址。在 32 位版本上，这通常是
		与 CONFIG_SYS_CCSRBAR_DEFAULT 的值相同。

		CONFIG_SYS_DEFAULT_IMMR 也必须设置为该值，
		对于使用该宏的跨平台代码。

- CONFIG_SYS_CCSRBAR_PHYS：
		CCSR 的物理地址。 CCSR 可以迁移到新的
		物理地址（如果需要）。在这种情况下，这个宏应该
		被设置为该地址。否则，应将其设置为
		与 CONFIG_SYS_CCSRBAR_DEFAULT 的值相同。例如，CCSR
		通常在 36 位版本上重新定位。推荐
		该宏通过 _HIGH 和 _LOW 宏定义：

		#define CONFIG_SYS_CCSRBAR_PHYS ((CONFIG_SYS_CCSRBAR_PHYS_HIGH
			* 1ull) << 32 | CONFIG_SYS_CCSRBAR_PHYS_LOW）

- CONFIG_SYS_CCSRBAR_PHYS_HIGH：
		CONFIG_SYS_CCSRBAR_PHYS 的位 33-36。该值通常是
		0（32 位构建）或 0xF（36 位构建）。这个宏是
		在汇编代码中使用，因此它不能包含类型转换或
		整数大小后缀（例如“ULL”）。

- CONFIG_SYS_CCSRBAR_PHYS_LOW：
		CONFIG_SYS_CCSRBAR_PHYS 的低 32 位。这个宏是
		在汇编代码中使用，因此它不能包含类型转换或
		整数大小后缀（例如“ULL”）。

- CONFIG_SYS_CCSR_DO_NOT_RELOCATE：
		如果定义了该宏，则 CONFIG_SYS_CCSRBAR_PHYS 将是
		强制设置为确保 CCSR 不会重新定位的值。

- 软盘支持：
		CONFIG_SYS_FDC_DRIVE_NUMBER

		默认驱动器号（默认值0）

		CONFIG_SYS_ISA_IO_STRIDE

		定义FDC芯片组寄存器之间的间距
		（默认值1）

		CONFIG_SYS_ISA_IO_OFFSET

		定义寄存器相对于地址的偏移量。它
		取决于数据总线的哪一部分连接到
		FDC芯片组。 （默认值0）

		如果 CONFIG_SYS_ISA_IO_STRIDE CONFIG_SYS_ISA_IO_OFFSET 和
		CONFIG_SYS_FDC_DRIVE_NUMBER 未定义，它们采用自己的
		默认值。

		如果定义了 CONFIG_SYS_FDC_HW_INIT，则该函数
		fdc_hw_init() 在 FDC 的开头调用
		设置。 fdc_hw_init() 必须由板提供
		源代码。它用于使硬件依赖
		初始化。

- 配置_IDE_AHB：
		大多数 IDE 控制器被设计为与 PCI 连接
		界面。其中只有少数是为 AHB 接口设计的。
		当软件执行 ATA 命令和数据传输时
		IDE设备通过IDE-AHB控制器，一些额外的
		访问此类 IDE-AHB 控制器的寄存器
		是必须的。

- CONFIG_SYS_IMMR：内部存储器的物理地址。
		除非你确切知道自己是什么，否则不要改变
		正在做！ (11-4) [仅限 MPC8xx/82xx 系统]

- CONFIG_SYS_INIT_RAM_ADDR：

		可用于的内存区域的起始地址
		初始数据和堆栈；请注意，这必须是
		无需特殊即可工作的可写内存
		初始化，即您不能使用普通 RAM
		仅在编程后才可用
		内存控制器并运行某些初始化
		序列。

		U-Boot 使用以下内存类型：
		- MPC8xx和MPC8260：IMMR（CPU的内部存储器）
		- MPC824X：数据缓存
		- PPC4xx：数据缓存

- CONFIG_SYS_GBL_DATA_OFFSET：

		初始数据结构在内存中的偏移量
		由 CONFIG_SYS_INIT_RAM_ADDR 定义的区域。通常
		CONFIG_SYS_GBL_DATA_OFFSET 的选择使得初始
		数据位于可用空间的末尾
		（有时写为（CONFIG_SYS_INIT_RAM_SIZE -
		GENERATED_GBL_DATA_SIZE），初始堆栈只是
		低于该区域（从 (CONFIG_SYS_INIT_RAM_ADDR +
		CONFIG_SYS_GBL_DATA_OFFSET）向下。

	笔记：
		在 MPC824X（或其他使用数据的系统上）
		初始内存的缓存）选择的地址
		CONFIG_SYS_INIT_RAM_ADDR 基本上是任意的 - 它必须
		指向之间未使用的地址空间
		RAM 的顶部和 PCI 空间的开始。

- CONFIG_SYS_SIUMCR：SIU 模块配置 (11-6)

- CONFIG_SYS_SYPCR：系统保护控制（11-9）

- CONFIG_SYS_TBSCR：时基状态和控制 (11-26)

- CONFIG_SYS_PISCR：周期性中断状态和控制 (11-31)

- CONFIG_SYS_PLPRCR：PLL、低功耗和复位控制寄存器 (15-30)

- CONFIG_SYS_SCCR：系统时钟和复位控制寄存器 (15-27)

- CONFIG_SYS_OR_TIMING_SDRAM：
		SDRAM时序

- CONFIG_SYS_MAMR_PTA：
		周期性刷新定时器

- CONFIG_SYS_DER：调试事件寄存器 (37-47)

- FLASH_BASE0_PRELIM、FLASH_BASE1_PRELIM、CONFIG_SYS_REMAP_OR_AM、
  CONFIG_SYS_PRELIM_OR_AM、CONFIG_SYS_OR_TIMING_FLASH、CONFIG_SYS_OR0_REMAP、
  CONFIG_SYS_OR0_PRELIM、CONFIG_SYS_BR0_PRELIM、CONFIG_SYS_OR1_REMAP、CONFIG_SYS_OR1_PRELIM、
  CONFIG_SYS_BR1_PRELIM：
		内存控制器定义：BR0/1 和 OR0/1（闪存）

- SDRAM_BASE2_PRELIM、SDRAM_BASE3_PRELIM、SDRAM_MAX_SIZE、
  CONFIG_SYS_OR_TIMING_SDRAM、CONFIG_SYS_OR2_PRELIM、CONFIG_SYS_BR2_PRELIM、
  CONFIG_SYS_OR3_PRELIM、CONFIG_SYS_BR3_PRELIM：
		内存控制器定义：BR2/3 和 OR2/3 (SDRAM)

- CONFIG_SYS_MAMR_PTA、CONFIG_SYS_MPTPR_2BK_4K、CONFIG_SYS_MPTPR_1BK_4K、CONFIG_SYS_MPTPR_2BK_8K、
  CONFIG_SYS_MPTPR_1BK_8K、CONFIG_SYS_MAMR_8COL、CONFIG_SYS_MAMR_9COL：
		机器模式寄存器和存储器周期定时器
		预分频器定义（SDRAM 时序）

- CONFIG_SYS_I2C_UCODE_PATCH、CONFIG_SYS_I2C_DPMEM_OFFSET [0x1FC0]：
		启用 I2C 微代码重定位补丁 (MPC8xx)；
		定义 DPRAM 中的重定位偏移量 [DSP2]

- CONFIG_SYS_SMC_UCODE_PATCH、CONFIG_SYS_SMC_DPMEM_OFFSET [0x1FC0]：
		启用S​​MC微码重定位补丁（MPC8xx）；
		定义 DPRAM 中的重定位偏移量 [SMC1]

- CONFIG_SYS_SPI_UCODE_PATCH、CONFIG_SYS_SPI_DPMEM_OFFSET [0x1FC0]：
		启用S​​PI微代码重定位补丁（MPC8xx）；
		定义 DPRAM 中的重定位偏移量 [SCC4]

- CONFIG_SYS_CPM_POST_WORD_ADDR：（仅限 MPC8xx、MPC8260）
		post 使用的 DPRAM 中引导模式字的偏移量
		（开机自检）。该定义覆盖
		#在 commproc.h 中定义默认值。
		cpm_8260.h。

- CONFIG_SYS_PCI_SLV_MEM_LOCAL、CONFIG_SYS_PCI_SLV_MEM_BUS、CONFIG_SYS_PICMR0_MASK_ATTRIB、
  CONFIG_SYS_PCI_MSTR0_LOCAL、CONFIG_SYS_PCIMSK0_MASK、CONFIG_SYS_PCI_MSTR1_LOCAL、
  CONFIG_SYS_PCIMSK1_MASK、CONFIG_SYS_PCI_MSTR_MEM_LOCAL、CONFIG_SYS_PCI_MSTR_MEM_BUS、
  CONFIG_SYS_CPU_PCI_MEM_START、CONFIG_SYS_PCI_MSTR_MEM_SIZE、CONFIG_SYS_POCMR0_MASK_ATTRIB、
  CONFIG_SYS_PCI_MSTR_MEMIO_LOCAL、CONFIG_SYS_PCI_MSTR_MEMIO_BUS、CPU_PCI_MEMIO_START、
  CONFIG_SYS_PCI_MSTR_MEMIO_SIZE、CONFIG_SYS_POCMR1_MASK_ATTRIB、CONFIG_SYS_PCI_MSTR_IO_LOCAL、
  CONFIG_SYS_PCI_MSTR_IO_BUS、CONFIG_SYS_CPU_PCI_IO_START、CONFIG_SYS_PCI_MSTR_IO_SIZE、
  CONFIG_SYS_POCMR2_MASK_ATTRIB：（仅限 MPC826x）
		如果设置，则覆盖 arch/powerpc/cpu/mpc8260/pci.c 中的默认 PCI 内存映射。

- CONFIG_PCI_DISABLE_PCIE：
		在支持但不支持 PCI-Express 的系统上禁用 PCI-Express
		必需的。

- CONFIG_PCI_ENUM_ONLY
		仅扫描并获取公交车上的设备。
		不要做任何设置工作，可能是因为某人或
		有些事情已经完成了，我们不需要这样做
		第二次。对于预启动的平台很有用
		通过 coreboot 或类似的。

- CONFIG_PCI_INDIRECT_BRIDGE：
		启用对间接 PCI 桥接器的支持。

- CONFIG_SYS_SRIO：
		芯片有无SRIO

- 配置_SRIO1：
		主板有 SRIO 1 端口可用

- 配置_SRIO2：
		主板有 SRIO 2 端口可用

- CONFIG_SRIO_PCIE_BOOT_MASTER
		主板可支持从 SRIO 和 PCIE 启动的主控功能

- CONFIG_SYS_SRIOn_MEM_VIRT：
		SRIO 端口“n”内存区域的虚拟地址

- CONFIG_SYS_SRIOn_MEM_PHYS：
		SRIO 端口“n”内存区域的物理地址

- CONFIG_SYS_SRIOn_MEM_SIZE：
		SRIO 端口“n”内存区域的大小

- CONFIG_SYS_NAND_BUSWIDTH_16BIT
		定义为告诉NAND控制器该NAND芯片正在使用
		16 位总线。
		并非所有 NAND 驱动程序都使用此符号。
		使用它的驱动程序示例：
		- 驱动程序/mtd/nand/ndfc.c
		- 驱动程序/mtd/nand/mxc_nand.c

- CONFIG_SYS_NDFC_EBC0_CFG
		设置 NDFC 的 EBC0_CFG 寄存器。如果没有定义
		将使用默认值。

- 配置_SPD_EEPROM
		从 I2C EEPROM 获取 DDR 时序信息。常见的
		具有可插拔内存模块，例如 SODIMM

  SPD_EEPROM_地址
		SPD EEPROM 的 I2C 地址

- CONFIG_SYS_SPD_BUS_NUM
		如果 SPD EEPROM 位于第一个以外的 I2C 总线上
		一、此处指定。请注意，该值必须解析
		您的司机可以处理的事情。

- CONFIG_SYS_DDR_RAW_TIMING
		从 SPD 以外的地方获取 DDR 时序信息。常见于
		板载DDR芯片，无需SPD。 DDR 原始时序
		参数从数据表中提取并硬编码到
		头文件或板特定文件。

- CONFIG_FSL_DDR_INTERACTIVE
		启用交互式 DDR 调试。请参阅 doc/README.fsl-ddr。

- CONFIG_FSL_DDR_SYNC_REFRESH
		为多个控制器启用刷新同步。

- CONFIG_FSL_DDR_BIST
		启用飞思卡尔 DDR 控制器的内置内存测试。

- CONFIG_SYS_83XX_DDR_USES_CS0
		仅适用于 83xx 系统。如果指定，则 DDR 应
		使用 CS0 和 CS1 而不是 CS2 和 CS3 进行配置。

- CONFIG_ETHER_ON_FEC[12]
		定义在 8xx 系列处理器上启用 FEC[12]。

- CONFIG_FEC[12]_PHY
		定义为对应的硬编码 PHY 地址
		到给定的FEC； IE
			#定义CONFIG_FEC1_PHY 4
		表示地址为4的PHY连接到FEC1

		当设置为 -1 时，意味着探测第一个可用的。

- CONFIG_FEC[12]_PHY_NORXERR
		PHY 没有 RXERR 线（仅限 RMII）。
		（因此对 FEC 进行编程以忽略它）。

- 配置_RMII
		为所有 FEC 启用 RMII 模式。
		请注意，这是一个全局选项，我们不能
		在标准 MII 模式下有一个 FEC，在 RMII 模式下有另一个 FEC。

- 配置_CRC32_验证
		向 crc32 命令添加验证选项。
		语法是：

		=> crc32 -v <地址> <计数> <crc32>

		其中地址/计数表示内存区域
		并且 crc32 是正确的 crc32
		区应该有。

- CONFIG_LOOPW
		添加“loopw”内存命令。这仅在以下情况下生效
		内存命令被全局激活（CONFIG_CMD_MEM）。

- CONFIG_MX_CYCLIC
		添加“mdc”和“mwc”内存命令。这些都是循环的
		“md/mw”命令。
		例子：

		=> mdc.b 10 4 500
		此命令将每 500 毫秒打印 4 个字节 (10,11,12,13)​​。

		=> mwc.l 100 12345678 10
		该命令将在 10 毫秒内将 12345678 写入地址 100。

		仅当内存命令被激活时才会生效
		全局（CONFIG_CMD_MEM）。

- CONFIG_SKIP_LOWLEVEL_INIT
		[仅限 ARM、NDS32、MIPS] 如果定义了此变量，则某些
		低级初始化（例如设置内存
		控制器）被省略和/或 U-Boot 不
		将自身重新定位到 RAM 中。

		通常这个变量不能被定义。唯一的
		例外是当 U-Boot 被某些人加载（到 RAM）时
		其他引导加载程序或由执行的调试器
		这些初始化本身。

- CONFIG_SKIP_LOWLEVEL_INIT_ONLY
		[仅限 ARM926EJ-S] 这仅允许调用 lowlevel_init()
		被跳过。正常的 CP15 初始化（例如启用
		指令缓存）仍然执行。

- 配置_SPL_构建
		修改编译加载程序时 start.S 的行为
		它在实际 U-Boot 之前执行。例如当
		编译 NAND SPL。

- CONFIG_TPL_BUILD
		修改编译加载程序时 start.S 的行为
		它在 SPL 之后、实际 U-Boot 之前执行。
		它由 SPL 加载。

- CONFIG_SYS_MPC85XX_NO_RESETVEC
		仅适用于 85xx 系统。如果指定了该变量，则该部分
		.resetvec 不保留，.bootpg 部分放置在
		.text 部分的前 4k。

- CONFIG_ARCH_MAP_SYSMEM
		一般来说，U-Boot（特别是 md 命令）使用
		有效地址。因此没有必要考虑
		U-Boot地址为需要转换的虚拟地址
		到物理地址。然而，沙箱需要这样做，因为
		它维护自己的小 RAM 缓冲区，其中包含所有
		可寻址内存。该选项会导致一些内存访问
		通过map_sysmem() / unmap_sysmem()进行映射。

- CONFIG_X86_RESET_VECTOR
		如果定义，则包含 x86 重置向量代码。这不是
		当 U-Boot 从 Coreboot 运行时需要。

- CONFIG_SYS_MPUCLK
		定义 MPU 时钟速度（以 MHz 为单位）。

		注意：目前仅在 AM335x 平台上受支持。

- CONFIG_SPL_AM33XX_ENABLE_RTC32K_OSC：
		在基于 AM33xx 的平台上启用 RTC32K OSC

- CONFIG_SYS_NAND_NO_SUBPAGE_WRITE
		在 NAND 驱动程序中禁用子页写入的选项
		使用这个的驱动程序：
		驱动程序/mtd/nand/davinci_nand.c

飞思卡尔 QE/FMAN 固件支持：
-----------------------------------

飞思卡尔 QUICCEngine (QE) 和帧管理器 (FMAN) 均支持
加载以 QE 固件二进制格式编码的“固件”。
这个固件经常需要在U-Boot启动时加载，所以宏
用于识别存储设备（NOR flash、SPI等）和地址
在该设备内。

- CONFIG_SYS_FMAN_FW_ADDR
	FMAN微码所在存储设备中的地址。这
	该地址的含义取决于哪个 CONFIG_SYS_QE_FW_IN_xxx 宏
	也被指定。

- CONFIG_SYS_QE_FW_ADDR
	QE微码所在存储设备中的地址。这
	该地址的含义取决于哪个 CONFIG_SYS_QE_FW_IN_xxx 宏
	也被指定。

- CONFIG_SYS_QE_FMAN_FW_LENGTH
	固件的最大可能大小。固件二进制格式
	有一个字段指定固件的实际大小，但它
	可能无法读取固件的任何部分，除非某些
	首先分配本地存储来保存整个固件。

- CONFIG_SYS_QE_FMAN_FW_IN_NOR
	指定 QE/FMAN 固件位于 NOR 闪存中，映射为
	通过 LBC 的正常可寻址内存。 CONFIG_SYS_FMAN_FW_ADDR 是
	NOR闪存中的虚拟地址。

- CONFIG_SYS_QE_FMAN_FW_IN_NAND
	指定 QE/FMAN 固件位于 NAND 闪存中。
	CONFIG_SYS_FMAN_FW_ADDR 是 NAND 闪存内的偏移量。

- CONFIG_SYS_QE_FMAN_FW_IN_MMC
	指定 QE/FMAN 固件位于主 SD/MMC 上
	设备。 CONFIG_SYS_FMAN_FW_ADDR 是该设备上的字节偏移量。

- CONFIG_SYS_QE_FMAN_FW_IN_REMOTE
	指定 QE/FMAN 固件位于远程（主）
	内存空间。 CONFIG_SYS_FMAN_FW_ADDR 是一个虚拟地址，
	可以从从 TLB->从 LAW->从 SRIO 或 PCIE 出站映射
	窗口->主入站窗口->主LAW->ucode地址
	主人的记忆空间。

飞思卡尔 Layerscape 管理复杂固件支持：
-------------------------------------------------- --------
飞思卡尔 Layerscape Management Complex (MC) 支持加载
“固件”。
这个固件经常需要在U-Boot启动时加载，所以宏
用于识别存储设备（NOR flash、SPI等）和地址
在该设备内。

- CONFIG_FSL_MC_ENET
	为 Layerscape SoC 启用 MC 驱动程序。

飞思卡尔 Layerscape 调试服务器支持：
-------------------------------------------
飞思卡尔 Layerscape 调试服务器支持支持加载
“调试服务器固件”并触发 SP boot-rom。
该固件通常需要在 U-Boot 启动过程中加载。

- CONFIG_SYS_MC_RSV_MEM_ALIGN
	定义 MC 所需保留内存的对齐方式

可重复的构建
-------------------

为了实现可重现的构建，U-Boot 构建中使用了时间戳
process 必须设置为固定值。

这是使用 SOURCE_DATE_EPOCH 环境变量完成的。
SOURCE_DATE_EPOCH 将在构建主机的 shell 上设置，而不是作为配置
U-Boot 的选项或 U-Boot 中的环境变量。

SOURCE_DATE_EPOCH 应设置为自纪元以来的秒数（UTC）。

构建软件：
=====================

构建 U-Boot 已在多个本机构建环境中进行了测试
以及在许多不同的交叉环境中。我们当然不能支持
交叉开发工具的所有可能现有版本
（可能已过时）版本。如果出现工具链问题，我们
推荐使用 ELDK（参见http://www.denx.de/wiki/DULG/ELDK）
它广泛用于构建和测试 U-Boot。

如果您没有使用本机环境，则假设您
您的路径中有可用的 GNU 交叉编译工具。在这种情况下，
您必须在 shell 中设置环境变量 CROSS_COMPILE。
请注意，不会对 Makefile 或任何其他源文件进行任何更改
必要的。例如，在 4xx CPU 上使用 ELDK，请输入：

	$ CROSS_COMPILE=ppc_4xx-
	$导出CROSS_COMPILE

注意：如果您希望生成 Windows 版本的实用程序
      可以使用MinGW工具链的tools目录
      （http://www.mingw.org）。将您的主机工具设置为 MinGW
      工具链并执行“制作工具”。例如：

       $ make HOSTCC=i586-mingw32msvc-gcc HOSTSTRIP=i586-mingw32msvc-strip 工具

      将创建诸如tools/mkimage.exe之类的二进制文件，它可以
      在运行 Windows 的计算机上执行。

U-Boot 旨在简化构建。安装后
您必须为一种特定的板类型配置 U-Boot。这
通过输入以下内容完成：

	制作 NAME_defconfig

其中“NAME_defconfig”是现有配置之一的名称
口粮；请参阅boards.cfg 以了解支持的名称。

注意：对于某些板可能存在特殊配置名称；检查是否
      可以从主板供应商处获得更多信息；为了
      例如，TQM823L 系统无需（标准）
      或带有 LCD 支持。您可以选择此类附加“功能”
      选择配置时，即

      制作TQM823L_defconfig
	- 将配置为普通 TQM823L，即不支持 LCD

      使TQM823L_LCD_defconfig
	- 将在 LCD 上配置带有 U-Boot 控制台的 TQM823L

      ETC。


最后，输入“make all”，您应该会得到一些可用的 U-Boot
图像已准备好下载到/安装在您的系统上：

- “u-boot.bin”是原始二进制映像
- “u-boot”是 ELF 二进制格式的映像
- “u-boot.srec”采用 Motorola S-Record 格式

默认情况下，构建在本地执行并保存对象
在源目录中。可以使用这两种方法之一来改变
此行为并将 U-Boot 构建到某个外部目录：

1. 将 O= 添加到 make 命令行调用中：

	make O=/tmp/build distclean
	使 O=/tmp/build NAME_defconfig
	使 O=/tmp/构建全部

2. 设置环境变量 KBUILD_OUTPUT 以指向所需位置：

	导出 KBUILD_OUTPUT=/tmp/build
	使 distclean
	制作 NAME_defconfig
	使所有

请注意，命令行“O=”设置会覆盖 KBUILD_OUTPUT 环境
多变的。


请注意，Makefile 假定您使用的是 GNU make，因此
例如在 NetBSD 上您可能需要使用“gmake”而不是
本机“制作”。


如果您拥有的系统板未列出，那么您将需要
将 U-Boot 移植到您的硬件平台。为此，请遵循以下步骤
脚步：

1. 创建一个新目录来保存您的主板特定代码。添加任何
    您需要的文件。在你的板目录中，你至少需要
    “Makefile”和“<board>.c”。
2. 创建一个新的配置文件“include/configs/<board>.h”
    你的董事会。
3. 如果您要将 U-Boot 移植到新的 CPU，那么还要创建一个新的
    目录来保存您的 CPU 特定代码。添加您需要的任何文件。
4. 使用您的新名称运行“make <board>_defconfig”。
5. 输入“make”，您应该会得到一个可用的“u-boot.srec”文件
    安装在您的目标系统上。
6、调试并解决可能出现的问题。
    [当然，最后一步比听起来要困难得多。]


U-Boot 修改、新硬件端口等测试：
=================================================== ===========

如果您修改了U-Boot源（例如添加了新板
或对新设备、新 CPU 等的支持）您应该
向其他开发人员提供反馈。反馈通常需要
“补丁”的形式，即针对某个（最新的）的上下文差异
官方或 git 存储库中的最新版本）U-Boot 源代码。

但在您提交此类补丁之前，请验证您的修改-
阳离子并没有破坏现有的代码。至少确保*全部*
支持的主板编译时不会出现任何编译器警告。为此，
只需运行 buildman 脚本 (tools/buildman/buildman)，它将
为所有支持的系统配置和构建 U-Boot。请注意，这
需要一段时间。请参阅 buildman 自述文件，或运行“buildman -H”
用于文档。


另请参阅下面的“U-Boot 移植指南”。


监控命令 - 概述：
============================

go - 在地址“addr”处启动应用程序
run - 在环境变量中运行命令
bootm - 从内存启动应用程序映像
bootp - 使用 BootP/TFTP 协议通过网络启动映像
bootz - 从内存启动 zImage
tftpboot- 使用 TFTP 协议通过网络启动映像
	       和环境变量“ipaddr”和“serverip”
	       （最终是“gatewayip”）
tftpput - 使用 TFTP 协议通过网络上传文件
rarpboot- 使用 RARP/TFTP 协议通过网络启动映像
diskboot- 从 IDE 启动 devicebootd - 默认启动，即运行“bootcmd”
加载 - 通过串行线加载 S-Record 文件
loadb - 通过串行线加载二进制文件（kermit 模式）
md——内存显示
mm - 内存修改（自动递增）
nm - 内存修改（常量地址）
mw - 内存写入（填充）
cp——内存复制
cmp——内存比较
crc32 - 校验和计算
i2c - I2C 子系统
sspi - SPI 实用程序命令
基址 - 打印或设置地址偏移量
printenv-打印环境变量
setenv——设置环境变量
saveenv - 将环境变量保存到持久存储中
保护 - 启用或禁用 FLASH 写保护
擦除 - 擦除闪存
flinfo——打印FLASH存储器信息
nand - NAND 内存操作（参见 doc/README.nand）
bdinfo - 打印板信息结构
iminfo - 打印应用程序映像的标题信息
coninfo - 打印控制台设备和信息
ide - IDE 子系统
循环 - 地址范围上的无限循环
Loopw - 地址范围上的无限写入循环
mtest - 简单的 RAM 测试
icache - 启用或禁用指令缓存
dcache - 启用或禁用数据缓存
复位 - 执行 CPU 复位
echo - 将参数回显到控制台
版本 - 打印监控版本
帮助 - 打印在线帮助
？ - “帮助”的别名


监控命令 - 详细说明：
=========================================

去做。

现在：只需输入“help <命令>”。


环境变量：
=====================

U-Boot 支持使用环境变量进行用户配置
可以通过保存到闪存来持久化。

环境变量使用“setenv”设置，使用打印
“printenv”，并使用“saveenv”保存到 Flash。使用“setenv”
没有值可用于从变量中删除
环境。只要你不拯救环境，你就是
使用内存中的副本。如果 Flash 区域包含
环境被意外删除，提供了默认环境。

可以使用环境变量设置某些配置选项。

环境变量列表（很可能不完整）：

  波特率 - 请参阅 CONFIG_BAUDRATE

  引导延迟 - 请参阅 CONFIG_BOOTDELAY

  bootcmd - 请参阅 CONFIG_BOOTCOMMAND

  bootargs - 启动 RTOS 映像时的启动参数

  bootfile - 使用 TFTP 加载的映像的名称

  bootm_low - bootm 中可用于图像处理的内存范围
		  命令可以被限制。该变量给出为
		  十六进制数并定义允许的最低地址
		  供 bootm 命令使用。另请参阅“bootm_size”
		  环境变量。 “bootm_low”定义的地址是
		  也是 Linux 初始内存映射的基础
		  内核——参见 CONFIG_SYS_BOOTMAPSZ 的描述和
		  bootm_mapsize。

  bootm_mapsize - Linux 内核的初始内存映射的大小。
		  该变量以十六进制数形式给出，并且它
		  定义从基址开始的内存区域的大小
		  Linux 内核可访问的地址 bootm_low
		  在早期启动期间。如果未设置，则使用 CONFIG_SYS_BOOTMAPSZ
		  如果已定义，则作为默认值，并且 bootm_size 为
		  否则使用。

  bootm_size - bootm 中可用于图像处理的内存范围
		  命令可以被限制。该变量给出为
		  一个十六进制数并定义区域的大小
		  允许 bootm 命令使用。另请参阅“bootm_low”
		  环境变量。

  updatefile - TFTP 服务器上软件更新文件的位置，使用
		  通过自动软件更新功能。请参阅
		  doc/README.update 中的文档了解更多详细信息。

  自动加载 - 如果设置为“no”（任何以“n”开头的字符串），
		  “bootp”只会加载并执行查找
		  从 BOOTP 服务器进行配置，但不尝试
		  使用 TFTP 加载任何图像

  autostart - 如果设置为“yes”，则使用“bootp”加载图像，
		  “rarpboot”、“tftpboot”或“diskboot”命令将
		  自动启动（通过内部调用
		  “启动”）

		  如果设置为“no”，则将独立图像传递到
		  “bootm”命令将被复制到加载地址
		  （并最终解压缩），但不启动。
		  这可用于加载和解压缩任意
		  数据。

  fdt_high - 如果设置，则限制最大地址
		  扁平化设备树将在启动时复制到其中。
		  例如，如果您的系统具有 1 GB 内存
		  位于物理地址0x10000000，而Linux内核
		  仅将前 704 MB 识别为低内存，您
		  可能需要将 fdt_high 设置为 0x3C000000 才能获得
		  设备树 blob 被复制到最大地址
		  704 MB 低内存，以便 Linux 内核可以
		  在引导过程中访问它。

		  如果将其设置为特殊值 0xFFFFFFFF 则
		  fdt 在启动时根本不会被复制。为了这
		  要工作它必须驻留在可写内存中，有
		  其末尾有足够的填充，以便 u-boot
		  将需要的信息添加进去，以及内存
		  必须可以被内核访问。

  fdtcontroladdr-如果设置，则这是扁平化控件的地址
		  CONFIG_OF_CONTROL 为时 U-Boot 使用的设备树
		  定义的。

  i2cfast -（仅限 PPC405GP|PPC405EP）
		  如果设置为“y”，则配置 Linux I2C 驱动程序以实现快速
		  模式（400kHz）。该环境变量用于
		  初始化代码。因此，为了使改变有效
		  必须保存它并且必须重置板。

  initrd_high - 限制 initrd 映像的定位：
		  如果未设置此变量，initrd 映像将是
		  复制到 RAM 中可能的最高地址；这
		  通常是你想要的，因为它允许
		  最大 initrd 大小。如果出于某种原因你想要
		  确保 initrd 映像加载到下面
		  CONFIG_SYS_BOOTMAPSZ限制，可以设置这个环境
		  变量的值为“no”或“off”或“0”。
		  或者，您可以将其设置为最大上限
		  要使用的地址（U-Boot 仍会检查它
		  不会覆盖 U-Boot 堆栈和数据）。

		  例如，当您有一个 16 MB 的系统时
		  RAM，并希望保留 4 MB 供 Linux 使用，
		  您可以通过将“mem = 12M”添加到值来做到这一点
		  “bootargs”变量。然而，现在你必须
		  确保 initrd 映像放置在第一个
		  12 MB 以及 - 这可以通过

		  setenv initrd_high 00c00000

		  如果将 initrd_high 设置为 0xFFFFFFFF，则这是一个
		  向 U-Boot 指示所有地址都是合法的
		  对于 Linux 内核，包括闪存中的地址
		  记忆。在这种情况下，U-Boot 将不会复制
		  根本没有虚拟磁盘。这可能有助于减少
		  系统上的启动时间，但要求这
		  您的 Linux 内核支持该功能。

  ipaddr——IP地址； tftpboot 命令需要

  loadaddr - “bootp”等命令的默认加载地址，
		  “rarpboot”、“tftpboot”、“loadb”或“diskboot”

  load_echo - 请参阅 CONFIG_LOADS_ECHO

  serverip - TFTP 服务器 IP 地址； tftpboot 命令需要

  bootretry - 请参阅 CONFIG_BOOT_RETRY_TIME

  bootdelaykey - 请参阅 CONFIG_AUTOBOOT_DELAY_STR

  bootstopkey - 请参阅 CONFIG_AUTOBOOT_STOP_STR

  ethprime - 控制首先使用哪个接口。

  ethact - 控制当前处于活动状态的接口。
		  例如，您可以执行以下操作

		  => setenv ethact FEC
		  => ping 192.168.0.1 # 通过 FEC 发送的流量
		  => setenv ethact SCC
		  => ping 10.0.0.1 # 在 SCC 上发送的流量

  ethrotate - 设置为“否”时，U-Boot 不会执行所有操作
		  可用的网络接口。
		  它只是停留在当前选择的界面。

  netretry - 当设置为“no”时，每个网络操作都会
		  要么成功，要么失败，无需重试。
		  当设置为“一次”时，网络操作将
		  当所有可用网络接口都失败时
		  尝试过一次没有成功。
		  对于控制重试操作的脚本很有用
		  他们自己。

  npe_ucode - 设置 NPE 微码的加载地址

  silent_linux - 如果设置，那么 Linux 将被告知以静默方式启动，方法是
		  将控制台更改为空。如果“是”将会是
		  沉默了。如果“否”，则不会保持沉默。如果
		  未设置，则如果 U-Boot 控制台将保持沉默
		  沉默了。

  tftpsrcp - 如果设置此值，则该值用于 TFTP
		  UDP 源端口。

  tftpdstp - 如果设置此值，则该值用于 TFTP 的 UDP
		  目标端口而不是众所周知的端口 69。

  tftpblocksize - 用于 TFTP 传输的块大小；如果没有设置，
		  我们使用 TFTP 服务器的默认块大小

  tftptimeout - TFTP 数据包的重传超时（以毫秒为单位）
		  秒，最小值为 1000 = 1 秒）。定义
		  当一个数据包被认为丢失时，它必须
		  被重传。默认值为 5000 = 5 秒。
		  降低该值可能会使下载成功
		  在丢包率较高的网络中速度更快，或者
		  使用不可靠的 TFTP 服务器。

  tftptimeoutcountmax - TFTP 超时的最大计数（无
		  单位，最小值 = 0)。定义多少次超时
		  在此之前的单个文件传输期间可能会发生
		  传输被中止。默认为10，0表示
		  “不允许超时”。增加这个值可能会有所帮助
		  下载成功但丢包率较高，或者
		  不可靠的 TFTP 服务器或客户端硬件。

  vlan - 当设置为 < 4095 的值时，流量将超过
		  以太网通过 802.1q 封装/接收
		  VLAN 标记的帧。

  bootpretryperiod - BOOTP/DHCP 发送重试的周期。
		  无符号值，以毫秒为单位。如果未设置，则该期间将
		  可以是默认值 (28000)，也可以是基于
		  CONFIG_NET_RETRY_COUNT（如果已定义）。这个值有
		  优先于基于 CONFIG_NET_RETRY_COUNT 的值。

以下图像位置变量包含图像的位置
在启动时使用。 “图像”栏给出了图像的作用，并且是
不是环境变量名称。其他列是环境
变量名称。 “文件名”给出 TFTP 上文件的名称
服务器，“RAM 地址”给出了图像在 RAM 中的位置
加载到，“Flash Location”给出图像在 NOR 中的地址
闪存或 NAND 闪存中的偏移量。

*注意* - 不必为所有板定义这些变量，某些板
董事会目前使用其他变量来实现这些目的，并且一些
董事会将这些变量用于其他目的。

图像文件名称 RAM 地址 闪存位置
----- --------- ----------- --------------
u-boot u-boot u-boot_addr_r u-boot_addr
Linux 内核引导文件 kernel_addr_r kernel_addr
设备树 blob fdtfile fdt_addr_r fdt_addr
ramdisk ramdiskfile ramdisk_addr_r ramdisk_addr

可以自动使用以下环境变量
由网络启动命令（“bootp”和“rarpboot”）更新，
取决于引导服务器提供的信息：

  引导文件 - 见上文
  dnsip - 您的域名服务器的 IP 地址
  dnsip2 - 您的辅助域名服务器的 IP 地址
  gatewayip - 要使用的网关（路由器）的 IP 地址
  主机名 - 目标主机名
  ipaddr - 见上文
  网络掩码 - 子网掩码
  rootpath - NFS 服务器上根文件系统的路径名
  serverip - 见上文


有两个特殊的环境变量：

  Serial# - 包含硬件识别信息，例如
		  作为字符串类型和/或序列号
  ethaddr - 以太网地址

这些变量只能设置一次（通常在制造过程中）
董事会）。 U-Boot 拒绝删除或覆盖这些变量
一旦它们被设置一次。


其他特殊环境变量：

  ver - 包含打印的 U-Boot 版本字符串
		  使用“版本”命令。这个变量是
		  只读（请参阅 CONFIG_VERSION_VARIABLE）。


请注意，更改某些配置参数可能需要
仅在下次启动后生效（是的，这就像 Windoze :-）。


环境变量的回调函数：
--------------------------------------------------------

对于某些环境变量，u-boot 的行为需要改变
当它们的值改变时。此功能允许函数
与任意变量相关联。创建、覆盖或
删除，回调将为某一方提供机会
影响发生或变更被拒绝。

回调使用以下方式命名并与函数关联
主板或驱动程序代码中的 U_BOOT_ENV_CALLBACK 宏。

这些回调通过两种方式之一与变量关联。这
可以通过定义 CONFIG_ENV_CALLBACK_LIST_STATIC 添加静态列表
在板配置中定义一个字符串
协会。该列表必须采用以下格式：

	条目 = 变量名称[:回调名称]
	列表 = 条目[,列表]

如果未指定回调名称，则删除该回调。
列表中的任何位置也允许有空格。

回调也可以通过定义“.callbacks”变量来关联
与上面相同的列表格式。 “.callbacks”中的任何关联都会
覆盖静态列表中的任何关联。您可以定义
CONFIG_ENV_CALLBACK_LIST_DEFAULT 到一个列表（字符串）来定义
默认或嵌入式环境中的“.callbacks”环境变量。

如果定义了 CONFIG_REGEX，则上面的变量名称将被评估为
正则表达式。这允许多个变量连接到
相同的回调，但没有明确列出它们。


命令行解析：
=====================

U-Boot 有两种不同的命令行解析器：
旧的“简单”shell 和更强大的“hush”shell：

旧的、简单的命令行解析器：
--------------------------------

- 支持环境变量（通过setenv / saveenv命令）
- 多个命令在一行上，用“;”分隔
- 使用“... ${name} ...”语法进行变量替换
- 特殊字符（'$'、';'）可以通过添加前缀 '\' 进行转义，
  例如：
	setenv bootcmd bootm \${地址}
- 您还可以通过用单个撇号括起来来转义文本，例如：
	setenv addip 'setenv bootargs $bootargs ip=$ipaddr:$serverip:$gatewayip:$netmask:$hostname::off'

静音外壳：
------------

- 类似于 Bourne shell，具有如下控制结构
  if...then...else...fi，for...do...done；当……做……完成时，
  直到……做……完成，……
- 支持环境（“全局”）变量（通过 setenv / saveenv
  命令）和本地 shell 变量（通过标准 shell 语法
  “名称=值”）；只有环境变量可以与“run”一起使用
  命令

一般规则：
--------------

(1) 如果命令行（或“run”执行的环境变量
    命令）包含多个用分号分隔的命令，并且
    这些命令之一失败，则其余命令将
    无论如何都被执行了。

(2) 如果通过一次调用 run 执行多个变量（即
    使用变量列表作为参数调用 run），任何失败
    命令将导致“run”终止，即剩余的
    变量不被执行。

冗余以太网接口注意事项：
=========================================

有些板卡带有冗余以太网接口； U-Boot 支持
此类配置并能够自动选择
需要时“工作”界面。 MAC 分配的工作原理如下：

网络接口编号为 eth0, eth1, eth2, ... 对应
MAC 地址可以作为“ethaddr”（=>eth0）存储在环境中，
“eth1addr”（=>eth1），“eth2addr”，...

如果网络接口存储了一些有效的 MAC 地址（例如
在SROM中），如果没有相应的地址，则将其用作默认地址
环境中的叮叮设置；如果有相应的环境
设置变量，这会覆盖卡中的设置；这意味着：

o 如果 SROM 具有有效的 MAC 地址，并且在
  环境中，使用 SROM 的地址。

o 如果 SROM 中没有有效地址，并且在
  环境存在，则环境变量的值为
  用过的。

o 如果 SROM 和环境都包含 MAC 地址，并且
  两个地址相同，则使用此 MAC 地址。

o 如果 SROM 和环境都包含 MAC 地址，并且
  地址不同，使用环境中的值并且
  打印警告。

o 如果 SROM 和环境都不包含 MAC 地址，则会出现错误
  被提出。如果定义了 CONFIG_NET_RANDOM_ETHADDR，那么在这种情况下
  使用随机的、本地分配的 MAC。

如果以太网驱动程序实现了“write_hwaddr”函数，则有效的 MAC 地址
作为初始化过程的一部分将被编程到硬件中。这
可以通过设置适当的“ethmacskip”环境变量来跳过。
命名约定如下：
“ethmacskip”（=>eth0）、“eth1macskip”（=>eth1）等。

图像格式：
=============

U-Boot 能够启动（并执行其他辅助操作）
两种格式的图像：

新的 uImage 格式 (FIT)
-----------------------

基于Flattened Image Tree的灵活而强大的格式——FIT（类似
扁平化设备树）。它允许使用多个图像
组件（几个内核、ramdisk 等），其内容受以下保护
SHA1、MD5 或 CRC32。更多详细信息可以在 doc/uImage.FIT 目录中找到。


旧的 uImage 格式
-----------------

旧的图像格式基于二进制文件，基本上可以是任何东西，
前面有一个特殊的标头；请参阅 include/image.h 中的定义
细节;基本上，标头定义了以下图像属性：

* 目标操作系统（OpenBSD、NetBSD、FreeBSD、
  4.4BSD、Linux、SVR4、Esix、Solaris、Irix、SCO、戴尔、NCR、VxWorks、
  LynxOS、pSOS、QNX、RTEMS、完整性；
  目前支持：Linux、NetBSD、VxWorks、QNX、RTEMS、LynxOS、
  正直）。
* 目标CPU架构（提供Alpha、ARM、AVR32、Intel x86、
  IA64、MIPS、NDS32、Nios II、PowerPC、IBM S390、SuperH、Sparc、Sparc 64 位；
  目前支持：ARM、AVR32、Intel x86、MIPS、NDS32、Nios II、PowerPC）。
* 压缩类型（未压缩、gzip、bzip2）
* 加载地址
* 入口点
* 图片名称
* 图像时间戳

标头由特殊的 Magic Number 标记，并且标头
并且图像的数据部分通过以下方式防止损坏
CRC32 校验和。


Linux 支持：
=============

尽管 U-Boot 应该支持任何操作系统或独立应用程序
很容易，在设计过程中主要关注点始终是Linux
U 启动。

U-Boot 包含许多功能，到目前为止，这些功能已成为某些
Linux 内核中的特殊“引导加载程序”代码。另外，任何
要使用的“initrd”映像不再是一个大型 Linux 映像的一部分；
相反，内核和“initrd”是单独的映像。本次实施
有几个目的：

- 相同的功能可用于其他操作系统或独立操作系统
  应用程序（例如：使用压缩图像来减少
  闪存占用空间）

- 移植新的 Linux 内核版本变得更加容易，因为
  许多低级的、依赖于硬件的东西都是由 U-Boot 完成的

- 现在可以将相同的 Linux 内核映像与不同的“initrd”一起使用
  图片;当然这也意味着不同的内核镜像可以
  使用相同的“initrd”运行。这使得测试更容易（你不需要
  必须构建一个新的“zImage.initrd”Linux 映像，当您刚刚
  更改“initrd”中的文件）。此外，现场升级
  现在软件更容易了。


Linux 指南：
===========

将 Linux 移植到基于 U-Boot 的系统：
---------------------------------------

U-Boot 无法让您免于进行所有必要的修改
配置 Linux 设备驱动程序以与您的目标硬件一起使用
（不，我们不打算提供完整的虚拟机接口
Linux :-)。

但现在您可以忽略所有引导加载程序代码（在 arch/powerpc/mbxboot 中）。

只需确保您的机器特定的头文件（例如
include/asm-ppc/tqm8xx.h) 包含与董事会相同的定义
我们在 include/asm-<arch>/u-boot.h 中定义的信息结构，
并确保您的 IMAP_ADDR 定义使用相同的值
作为 CONFIG_SYS_IMMR 中的 U-Boot 配置。

注意，U-Boot 现在有一个驱动程序模型，一个驱动程序的统一模型。
如果您要添加新驱动程序，请将其插入驱动程序模型。如果有
如果没有可用的 uclass，我们鼓励您创建一个。看
文档/驱动程序模型。


配置Linux内核：
----------------------------

对 U-Boot 没有具体要求。确保你有一些根
目标系统的设备（初始 ramdisk、NFS）。


构建 Linux 映像：
-----------------------

使用 U-Boot，“普通”构建目标（如“zImage”或“bzImage”）是
不曾用过。如果您使用最新的内核源代码，则需要一个新的构建目标
“uImage”将存在，它会自动构建可用的图像
U 启动。大多数较旧的内核还支持“pImage”目标，
它是为我们的前身项目 PPCBoot 引入的，并使用
100% 兼容格式。

例子：

	制作TQM850L_defconfig
	制作旧配置
	使部门
	制作uImage

“uImage”构建目标使用特殊工具（在“tools/mkimage”中）来
用头信息封装压缩的Linux内核映像，
CRC32 校验和等与 U-Boot 一起使用。这就是我们正在做的：

* 构建标准的“vmlinux”内核映像（ELF 二进制格式）：

* 将内核转换为原始二进制图像：

	${CROSS_COMPILE}-objcopy -O 二进制文件 \
				 -R .note -R .comment \
				 -S vmlinux linux.bin

* 压缩二值图像：

	gzip -9 linux.bin

* 为U-Boot打包压缩二进制镜像：

	mkimage -A ppc -O linux -T 内核 -C gzip \
		-a 0 -e 0 -n "Linux 内核映像" \
		-d linux.bin.gz uImage


“mkimage”工具也可用于创建 ramdisk 映像以供使用
使用 U-Boot，与 Linux 内核映像分离，或者
合并为一个文件。 “mkimage”用 64 位封装图像
包含有关目标体系结构的信息的字节标头，
操作系统、图像类型、压缩方法、入口点、时间
印记、CRC32 校验和等

“mkimage”可以通过两种方式调用：验证现有图像和
打印标题信息，或构建新图像。

在第一种形式（带有“-l”选项）mkimage 列出信息
包含在现有 U-Boot 映像的标头中；这包括
校验和验证：

	工具/mkimage -l 图像
	  -l ==> 列出图像头信息

第二种形式（带有“-d”选项）用于构建 U-Boot 映像
来自用作图像有效负载的“数据文件”：

	工具/mkimage -A arch -O os -T type -C comp -a addr -e ep \
		      -n 名称 -d 数据文件图像
	  -A ==> 将架构设置为“arch”
	  -O ==> 将操作系统设置为“os”
	  -T ==> 将图像类型设置为“类型”
	  -C ==> 设置压缩类型 'comp'
	  -a ==> 将加载地址设置为“addr”（十六进制）
	  -e ==> 将入口点设置为“ep”（十六进制）
	  -n ==> 将图像名称设置为“名称”
	  -d ==> 使用“数据文件”中的图像数据

目前，PowerPC 系统的所有 Linux 内核都使用相同的负载
地址（0x00000000），但入口点地址取决于
内核版本：

- 2.2.x 内核的入口点位于 0x0000000C，
- 2.3.x 及更高版本的内核的入口点位于 0x00000000。

因此，构建 U-Boot 映像的典型调用将如下所示：

	->tools/mkimage -n 'TQM850L 的 2.4.4 内核' \
	> -A ppc -O linux -T 内核 -C gzip -a 0 -e 0 \
	> -d /opt/elsk/ppc_8xx/usr/src/linux-2.4.4/arch/powerpc/coffboot/vmlinux.gz \
	> 示例/uImage.TQM850L
	镜像名称：TQM850L 的 2.4.4 内核
	创建时间：2000 年 7 月 19 日星期三 02:34:59
	映像类型：PowerPC Linux 内核映像（gzip 压缩）
	数据大小：335725 字节 = 327.86 kB = 0.32 MB
	加载地址：0x00000000
	入口点：0x00000000

要验证图像的内容（或检查是否损坏）：

	-> 工具/mkimage -l 示例/uImage.TQM850L
	镜像名称：TQM850L 的 2.4.4 内核
	创建时间：2000 年 7 月 19 日星期三 02:34:59
	映像类型：PowerPC Linux 内核映像（gzip 压缩）
	数据大小：335725 字节 = 327.86 kB = 0.32 MB
	加载地址：0x00000000
	入口点：0x00000000

注意：对于启动时间至关重要的嵌入式系统，您可以进行交易
内存速度并安装未压缩的图像：这
需要更多闪存空间，但启动速度更快，因为它不需要
需要解压：

	->gunzip /opt/elsk/ppc_8xx/usr/src/linux-2.4.4/arch/powerpc/coffboot/vmlinux.gz
	->tools/mkimage -n 'TQM850L 的 2.4.4 内核' \
	> -A ppc -O linux -T 内核 -C 无 -a 0 -e 0 \
	> -d /opt/elsk/ppc_8xx/usr/src/linux-2.4.4/arch/powerpc/coffboot/vmlinux \
	> 示例/uImage.TQM850L-未压缩
	镜像名称：TQM850L 的 2.4.4 内核
	创建时间：2000 年 7 月 19 日星期三 02:34:59
	映像类型：PowerPC Linux 内核映像（未压缩）
	数据大小：792160 字节 = 773.59 kB = 0.76 MB
	加载地址：0x00000000
	入口点：0x00000000


类似地，您可以从“ramdisk.image.gz”文件构建 U-Boot 映像
当您的内核打算使用初始 ramdisk 时：

	-> tools/mkimage -n '简单 Ramdisk 映像' \
	> -A ppc -O linux -T ramdisk -C gzip \
	> -d /LinuxPPC/images/SIMPLE-ramdisk.image.gz 示例/simple-initrd
	映像名称：简单 Ramdisk 映像
	创建时间：2000 年 1 月 12 日星期三 14:01:50
	映像类型：PowerPC Linux RAMDisk 映像（gzip 压缩）
	数据大小：566530 字节 = 553.25 kB = 0.54 MB
	加载地址：0x00000000
	入口点：0x00000000

“dumpimage”是一个用于反汇编 mkimage 构建的映像的工具。它的“-i”
选项执行 mkimage 第二种形式的相反操作（“-d”
选项）。给定一个由 mkimage 构建的映像，dumpimage 会提取一个“数据文件”
从图像中：

	工具/dumpimage -i 图像 -T 类型 -p 位置数据文件
	  -i ==> 从“图像”中提取特定的“数据文件”
	  -T ==> 将图像类型设置为“类型”
	  -p ==> “图像”内“数据文件”的“位置”（从 0 开始）


安装 Linux 映像：
------------------------

要通过串行（控制台）接口下载 U-Boot 映像，
您必须将图像转换为 S-Record 格式：

	objcopy -I 二进制 -O srec 示例/图像示例/image.srec

“objcopy”不理解 U-Boot 中的信息
图像头，因此生成的 S-Record 文件将相对于
地址0x00000000。要将其加载到给定地址，您需要
使用“loads”将目标地址指定为“offset”参数
命令。

示例：将映像安装到地址 0x40100000（位于
TQM8xxL 位于第一个闪存组中）：

	=> 擦除 40100000 401FFFFF

	.......... 完毕
	擦除8个扇区

	=> 负载 40100000
	## 准备下载 S-Record ...
	〜>示例/image.srec
	1 2 3 4 5 6 7 8 9 10 11 12 13 ...
	...
	15989 15990 15991 15992
	[文件传输完成]
	[连接的]
	## 起始地址 = 0x00000000


您可以使用“iminfo”命令检查下载是否成功；
这包括校验和验证，因此您可以确保没有数据
腐败发生：

	=> 伊米 40100000

	## 检查 40100000 处的图像 ...
	   映像名称：TQM850L 上的 initrd 的 2.2.13
	   映像类型：PowerPC Linux 内核映像（gzip 压缩）
	   数据大小：335725 字节 = 327 kB = 0 MB
	   加载地址：00000000
	   入口点：0000000c
	   正在验证校验和...确定


启动Linux：
------------

“bootm”命令用于启动存储在
存储器（RAM 或闪存）。对于 Linux 内核映像，内容
“bootargs”环境变量的传递给内核作为
参数。您可以使用以下命令检查和修改此变量
“printenv”和“setenv”命令：


	=> printenv 引导参数
	bootargs=root=/dev/ram

	=> setenv bootargs root=/dev/nfs rw nfsroot=10.0.0.2:/LinuxPPC nfsaddrs=10.0.0.99:10.0.0.2

	=> printenv 引导参数
	bootargs=root=/dev/nfs rw nfsroot=10.0.0.2:/LinuxPPC nfsaddrs=10.0.0.99:10.0.0.2

	=> 引导40020000
	## 在 40020000 处启动 Linux 内核 ...
	   映像名称：TQM850L 上的 NFS 2.2.13
	   映像类型：PowerPC Linux 内核映像（gzip 压缩）
	   数据大小：381681 字节 = 372 kB = 0 MB
	   加载地址：00000000
	   入口点：0000000c
	   正在验证校验和...确定
	   解压缩内核映像... OK
	Linux 版本 2.2.13 (wd@denx.local.net)（gcc 版本 2.95.2 19991024（发布））#1 七月 19 日星期三 02:35:17 MEST 2000
	引导参数： root=/dev/nfs rw nfsroot=10.0.0.2:/LinuxPPC nfsaddrs=10.0.0.99:10.0.0.2
	time_init: 减量器频率 = 187500000/60
	正在校准延迟环... 49.77 BogoMIPS
	内存：15208k 可用（700k 内核代码、444k 数据、32k init）[c0000000,c1000000]
	...

如果你想用初始 RAM 磁盘启动 Linux 内核，你可以通过
内核和 initrd 映像的内存地址 (PPBCOOT
格式！）到“bootm”命令：

	=> 伊米 40100000 40200000

	## 检查 40100000 处的图像 ...
	   映像名称：TQM850L 上的 initrd 的 2.2.13
	   映像类型：PowerPC Linux 内核映像（gzip 压缩）
	   数据大小：335725 字节 = 327 kB = 0 MB
	   加载地址：00000000
	   入口点：0000000c
	   正在验证校验和...确定

	## 检查 40200000 处的图像 ...
	   映像名称：简单 Ramdisk 映像
	   映像类型：PowerPC Linux RAMDisk 映像（gzip 压缩）
	   数据大小：566530 字节 = 553 kB = 0 MB
	   加载地址：00000000
	   入口点：00000000
	   正在验证校验和...确定

	=> 启动 40100000 40200000
	## 在 40100000 处启动 Linux 内核 ...
	   映像名称：TQM850L 上的 initrd 的 2.2.13
	   映像类型：PowerPC Linux 内核映像（gzip 压缩）
	   数据大小：335725 字节 = 327 kB = 0 MB
	   加载地址：00000000
	   入口点：0000000c
	   正在验证校验和...确定
	   解压缩内核映像... OK
	## 正在加载 40200000 处的 RAMDisk 映像 ...
	   映像名称：简单 Ramdisk 映像
	   映像类型：PowerPC Linux RAMDisk 映像（gzip 压缩）
	   数据大小：566530 字节 = 553 kB = 0 MB
	   加载地址：00000000
	   入口点：00000000
	   正在验证校验和...确定
	   正在加载 Ramdisk...好的
	Linux 版本 2.2.13 (wd@denx.local.net)（gcc 版本 2.95.2 19991024（发布））#1 七月 19 日星期三 02:32:08 MEST 2000
	启动参数：root=/dev/ram
	time_init: 减量器频率 = 187500000/60
	正在校准延迟环... 49.77 BogoMIPS
	...
	RAMDISK：在块 0 处找到压缩映像
	VFS：已安装的根（ext2 文件系统）。

	bash#

启动 Linux 并传递扁平设备树：
------------

首先，必须使用适当的定义来编译 U-Boot。参见 参考资料 部分
上面标题为“Linux 内核接口”以获得更深入的解释。这
以下是如何启动内核并传递更新的示例
平面设备树：

=> 打印oftaddr
oftaddr=0x300000
=> 经常打印
oft=oftrees/mpc8540ads.dtb
=> tftp $oftaddr $oft
速度：1000，全双工
使用 TSEC0 设备
来自服务器 192.168.1.1 的 TFTP；我们的IP地址是192.168.1.101
文件名“oftrees/mpc8540ads.dtb”。
加载地址：0x300000
加载中： ＃
完毕
传输的字节数 = 4106（100a 十六进制）
=> tftp $loadaddr $bootfile
速度：1000，全双工
使用 TSEC0 设备
来自服务器 192.168.1.1 的 TFTP；我们的IP地址是192.168.1.2
文件名“uImage”。
加载地址：0x200000
加载中：＃＃＃＃＃＃＃＃＃＃＃＃
完毕
传输的字节数 = 1029407（fb51f 十六进制）
=> 打印加载地址
负载地址=200000
=> 打印oftaddr
oftaddr=0x300000
=> bootm $loadaddr - $oftaddr
## 启动映像位于 00200000 ...
   镜像名称：Linux-2.6.17-dirty
   映像类型：PowerPC Linux 内核映像（gzip 压缩）
   数据大小：1029343 字节 = 1005.2 kB
   加载地址：00000000
   入口点：00000000
   正在验证校验和...确定
   解压缩内核映像... OK
使用 0x300000 处的平面设备树启动
使用 MPC85xx ADS 机器说明
内存CAM映射：CAM0=256Mb，CAM1=256Mb，CAM2=0Mb 剩余：0Mb
[剪]


有关 U-Boot 映像类型的更多信息：
------------------------------------------

U-Boot 支持以下镜像类型：

   “独立程序”可直接在环境中运行
	由U-Boot提供；预计（如果他们的行为
	好吧）你可以从返回后继续在U-Boot中工作
	独立程序。
   “操作系统内核映像”通常是某些嵌入式操作系统的映像，
	将完全接管控制权。通常这些程序
	将安装自己的一组异常处理程序、设备
	驱动程序、设置 MMU 等 - 这意味着您不能
	除非重置CPU，否则无法重新进入U-Boot。
   “RAMDisk 映像”或多或少只是数据块，它们的
	参数（地址、大小）被传递到操作系统内核
	正在开始。
   “多文件映像”包含多个映像，通常是一个操作系统
	(Linux) 内核映像和一个或多个数据映像，例如
	RAM磁盘。例如，当您想要时，此结构很有用
	使用 BOOTP 等通过网络启动，其中启动
	服务器只提供一个图像文件，但你想要得到
	例如操作系统内核和 RAMDisk 映像。

	“多文件图像”以图像尺寸列表开始，每个图像尺寸
	图像大小（以字节为单位）由网络中的“uint32_t”指定
	字节顺序。该列表以“(uint32_t)0”结束。
	终止 0 后紧跟着图像，一个接着一个
	一，全部在“uint32_t”边界上对齐（大小四舍五入到
	4 字节的倍数）。

   “固件映像”是包含固件的二进制映像（例如
	U-Boot 或 FPGA 映像）通常会被编程为
	闪存。

   “脚本文件”是将由以下命令执行的命令序列
	U-Boot的命令解释器；这个功能特别
	当你配置 U-Boot 使用真正的 shell 时很有用（嘘）
	作为命令解释器。

启动 Linux zImage：
------------------------

在某些平台上，可以启动 Linux zImage。这个做完了
使用“bootz”命令。 “bootz”命令的语法相同
作为“bootm”命令的语法。

注意，定义 CONFIG_SUPPORT_RAW_INITRD 允许用户提供
带有原始 initrd 映像的内核。语法略有不同，
initrd 的地址必须增加其大小，如下所示
格式：“<initrd 地址>:<initrd 大小>”。


独立操作指南：
=================

U-Boot的特点之一是可以动态加载和
运行“独立”应用程序，它可以使用某些资源
U-Boot 类似控制台 I/O 功能或中断服务。

来源中包含两个简单的示例：

“你好世界”演示：
-------------------

'examples/hello_world.c' 包含一个小型的“Hello World”演示
应用;当你构建 U-Boot 时它会自动编译。
它被配置为在地址 0x00040004 处运行，因此您可以使用它
像那样：

	=> 负载
	## 准备下载 S-Record ...
	~>示例/hello_world.srec
	1 2 3 4 5 6 7 8 9 10 11 ...
	[文件传输完成]
	[连接的]
	## 起始地址 = 0x00040004

	=> 转到 40004 你好世界！这是一个测试。
	## 从 0x00040004 开始应用程序 ...
	你好世界
	参数=7
	argv[0] = "40004"
	argv[1] = "你好"
	argv[2] = "世界！"
	argv[3] = "这个"
	argv[4] = "是"
	argv[5] = "a"
	argv[6] =“测试”。
	argv[7] = "<NULL>"
	按任意键退出...

	## 应用程序终止，rc = 0x0

另一个例子，演示了如何注册CPM中断
带有 U-Boot 代码的处理程序可以在“examples/timer.c”中找到。
这里，设置了一个 CPM 定时器，每秒生成一个中断。
中断服务例程很简单，只是打印一个“.”。
字符，但这只是一个演示程序。该应用程序可以是
由以下按键控制：

	？ - 打印 CPM 计时器寄存器的当前值
	b - 启用中断并启动定时器
	e - 停止定时器并禁用中断
	q - 退出应用程序

	=> 负载
	## 准备下载 S-Record ...
	~>示例/timer.srec
	1 2 3 4 5 6 7 8 9 10 11 ...
	[文件传输完成]
	[连接的]
	## 起始地址 = 0x00040004

	=>去40004
	## 从 0x00040004 开始应用程序 ...
	定时器=0xfff00980
	使用定时器1
	  tgcr @ 0xfff00980，tmr @ 0xfff00990，trr @ 0xfff00994，tcr @ 0xfff00998，tcn @ 0xfff0099c，ter @ 0xfff009b0

按“b”：
	[q, b, e, ?] 设置间隔 1000000 us
	启用定时器
打 '？'：
	[q、b、e、？]........
	tgcr=0x1, tmr=0xff1c, trr=0x3d09, tcr=0x0, tcn=0xef6, ter=0x0
打 '？'：
	[q、b、e、？]。
	tgcr=0x1, tmr=0xff1c, trr=0x3d09, tcr=0x0, tcn=0x2ad4, ter=0x0
打 '？'：
	[q、b、e、？]。
	tgcr=0x1, tmr=0xff1c, trr=0x3d09, tcr=0x0, tcn=0x1efc, ter=0x0
打 '？'：
	[q、b、e、？]。
	tgcr=0x1, tmr=0xff1c, trr=0x3d09, tcr=0x0, tcn=0x169d, ter=0x0
按“e”：
	[q, b, e, ?] ...停止计时器
按“q”：
	[q, b, e, ?] ## 应用程序终止，rc = 0x0


迷你通讯警告：
===============

随着时间的推移，许多人在尝试使用该工具时报告了问题
用于串行下载的“minicom”终端仿真程序。我（wd）
考虑minicom已损坏，建议不要使用它。在下面
Unix，我建议使用 C-Kermit 进行通用用途（并且
特别是对于 kermit 二进制协议下载（“loadb”命令），以及
使用“cu”进行 S-Record 下载（“loads”命令）。看
http://www.denx.de/wiki/view/DULG/SystemSetup#Section_4.3。
寻求克米特的帮助。


不过，如果您绝对想使用它，请尝试添加此
配置到“文件传输协议”部分：

	   名称 程序名称 U/D FullScr IO-Red。多
	X kermit /usr/bin/kermit -i -l %l -s YU Y N N
	Y kermit /usr/bin/kermit -i -l %l -r ND Y N N


NetBSD 注释：
=============

从版本 0.9.2 开始，U-Boot 支持 NetBSD 作为主机
（构建 U-Boot）和目标系统（启动 NetBSD/mpc8xx）。

构建需要跨环境；众所周知，它致力于
NetBSD/i386 与 cross-powerpc-netbsd-1.3 软件包（您还将
需要 gmake，因为 Makefile 与 BSD make 不兼容）。
请注意，cross-powerpc 软件包不会安装包含文件；
尝试构建 U-Boot 将失败，因为 <machine/ansi.h> 是
丢失的。该文件必须手动安装和修补：

	# cd /usr/pkg/cross/powerpc-netbsd/include
	# mkdir powerpc
	# ln -s powerpc 机器
	# cp /usr/src/sys/arch/powerpc/include/ansi.h powerpc/ansi.h
	# ${EDIT} powerpc/ansi.h ## 必须删除 __va_list, _BSD_VA_LIST

由于本机之间不兼容，本机构建*不*工作
和 U-Boot 包含文件。

引导假设引导的映像（的第一部分）是
stage-2 加载器依次加载并调用内核
恰当的。 Loader 源最终将出现在 NetBSD 源中
树（可能在 sys/arc/mpc8xx/stand/u-boot_stage2/ 中）；在里面
同时，请参阅 ftp://ftp.denx.de/pub/u-boot/ppcboot_stage2.tar.gz


实施内部：
=========================

以下内容并不旨在对每个内容进行完整描述
实施细节。然而，它应该有助于理解
U-Boot 的内部工作原理并使其更容易移植到自定义
硬件。


初始堆栈，全局数据：
----------------------------

U-Boot 的实现比较复杂，因为 U-Boot
开始耗尽 ROM（闪存），通常无法访问
系统RAM（因为内存控制器尚未初始化）。
这意味着我们没有可写的Data或BSS段，并且BSS
未初始化为零。能够让 C 环境正常工作
无论如何，我们必须至少分配一个最小的堆栈。执行
此选项由所使用的 CPU 定义和限制：某些 CPU
型号提供片上存储器（如 MPC8xx 和上的 IMMR 区域）
MPC826x 处理器），在其他（部分）数据缓存上可以
锁定为（误）用作内存等。

	Chris Hallinan 将这些问题的精彩总结发布到
	U-Boot 邮件列表：

	主题：回复：[U-Boot-Users] 回复：更多关于 Memory Bank x（无）的信息？
	来自：“Chris Hallinan”<clh@net1plus.com>
	日期：2003 年 2 月 10 日星期一 16:43:46 -0500（美国标准时间 22:43）
	...

	如果我错了，请纠正我，但我的理解方式
	是这样的：使用 DCACHE 作为堆栈等的初始 RAM 不会
	需要任何物理 RAM 来备份缓存。聪明之处
	是缓存被用作临时供应
	设置 SDRAM 控制器之前必要的存储。它是
	超出了此列表的范围来解释详细信息，但您
	可以通过研究缓存架构来了解它是如何工作的
	架构和处理器特定手册中的操作。

	OCM 是 On Chip Memory，我相信 405GP 有 4K。它
	是系统设计者用作的另一种选择
	SDRAM 可用之前的初始堆栈/RAM 区域。任何一个
	选项应该适合你。如果您使用 CS 4 应该没问题
	电路板设计人员还没有将它用于某些用途
	让您在初次启动时感到悲伤！往往不是
	用过的。

	CONFIG_SYS_INIT_RAM_ADDR 应该位于不会干扰的地方
	与您的处理器/主板/系统设计。默认值
	你会在最近的任何 u-boot 发行版中找到
	walnut.h 应该适合你。我将其设置为更大的值
	比你的SDRAM模块。如果您有 64MB SDRAM 模块，请设置
	高于 400_0000。只要确保您的董事会没有资源即可
	应该响应该地址！该代码在
	start.S 已经存在一段时间了，应该可以正常工作
	你的配置是正确的。

	-克里斯·哈利南
	DS4.COM 公司

记住这一点很重要，因为它对 C 有一些影响
初始化过程的代码：

* 初始化的全局数据（数据段）是只读的。不要试
  来写它。

* 不要使用任何未初始化的全局数据（或隐式初始化的数据）
  作为零数据 - BSS 段） - 这是未定义的，initial-
  稍后执行（重定位到 RAM 时）。

* 堆栈空间非常有限。避免大数据缓冲区或类似的东西
  那。

仅将堆栈作为可写内存限制意味着我们无法使用
正常的全局数据在代码之间共享信息。但它
原来U-Boot的执行可以大大
通过使全局数据结构（gd_t）可供所有人使用来简化
功能。我们可以将指向该数据的指针作为参数传递给 _all_
函数，但这会使代码变得臃肿。相反，我们使用以下功能
GCC编译器（全局寄存器变量）共享数据：我们
将指向全局数据的指针（gd）放入我们要使用的寄存器中
为此目的预留。

当为此目的选择寄存器时，我们受到以下限制：
当前架构的相关 (E)ABI 规范，以及
GCC 的实施。

对于 PowerPC，以下寄存器具有特定用途：
	R1：堆栈指针
	R2：保留供系统使用
	R3-R4：参数传递和返回值
	R5-R10：参数传递
	R13：小数据区指针
	R30：GOT指针
	R31：帧指针

	（U-Boot 也使用 R12 作为内部 GOT 指针。r12
	是一个易失性寄存器，因此 r12 需要重置
	在 asm 和 C 之间来回切换）

    ==> U-Boot 将使用 R2 来保存指向全局数据的指针

    注意：在 PPC 上，我们可以使用静态初始化程序（因为
    全局数据结构的地址在编译时已知），
    但事实证明，保留寄存器会导致一些结果
    较小的代码 - 尽管节省的代码并没有那么大（在
    所有板的平均整个 U-Boot 映像为 752 字节，
    624 个文本 + 127 个数据）。

在 Blackfin 上，遵循正常的 C ABI（P3 除外），如下所述：
	http://docs.blackfin.uclinux.org/doku.php?id=application_binary_interface

    ==> U-Boot 将使用 P3 来保存指向全局数据的指针

在 ARM 上，使用以下寄存器：

	R0：函数参数字/整数结果
	R1-R3：函数参数字
	R9：特定于平台
	R10：堆栈限制（仅在启用堆栈检查时使用）
	R11：参数（框架）指针
	R12：临时工作空间
	R13：堆栈指针
	R14：链接寄存器
	R15：程序计数器

    ==> U-Boot 将使用 R9 来保存指向全局数据的指针

    注意：在 ARM 上，仅支持 R_ARM_RELATIVE 重定位。

在 Nios II 上，ABI 记录如下：
	http://www.altera.com/literature/hb/nios2/n2cpu_nii51016.pdf

    ==> U-Boot 将使用 gp 来保存指向全局数据的指针

    注意：在 Nios II 上，我们为 gcc 提供“-G0”选项，并且不使用 gp
    访问小数据部分，所以 gp 是免费的。

在 NDS32 上，使用以下寄存器：

	R0-R1：参数/返回
	R2-R5：参数
	R15：汇编器临时寄存器
	R16：蹦床寄存器
	R28：帧指针（FP）
	R29：全局指针（GP）
	R30：链接寄存器（LP）
	R31：堆栈指针（SP）
	PC：程序计数器（PC）

    ==> U-Boot 将使用 R10 来保存指向全局数据的指针

注意：DECLARE_GLOBAL_DATA_PTR 必须与文件全局范围一起使用，
或者当前版本的 GCC 可能会过度“优化”代码。

内存管理：
------------------

U-Boot运行在系统状态并使用物理地址，即
MMU 既不用于地址映射，也不用于内存保护。

使用内存将可用内存映射到固定地址
控制器。在此过程中，每个块都会形成一个连续的块。
存储器类型（闪存、SDRAM、SRAM），即使它由多个存储器组成
物理内存库。

U-Boot 安装在第一个闪存组的前 128 kB 中（在
TQM8xxL 模块，范围为 0x40000000 ... 0x4001FFFF)。后
启动、调整和初始化 DRAM，代码会自行重新定位
到 DRAM 的上端。紧接着 U-Boot 代码下面的一些
内存被保留供 malloc() 使用 [请参阅 CONFIG_SYS_MALLOC_LEN
配置设置]。下面是一个具有全球董事会的结构
放置信息数据，然后是堆栈（向下增长）。

此外，一些异常处理程序代码被复制到低 8 kB
DRAM（0x00000000 ... 0x00001FFF）。

因此，具有 16 MB DRAM 的典型内存配置可能如下所示
这：

	0x0000 0000 异常向量代码
	      ：
	0x0000 1FFF
	0x0000 2000 免费供应用程序使用
	      ：
	      ：

	      ：
	      ：
	0x00FB FF20 监视器堆栈（向下增长）
	0x00FB FFAC 板信息数据和全局数据的永久副本
	0x00FC 0000 Malloc 竞技场
	      ：
	0x00FD FFFF
	0x00FE 0000 监视器代码的 RAM 副本
	...最终：LCD 或视频帧缓冲区
	...最终：pRAM（受保护的RAM - 重置后不变）
	0x00FF FFFF [RAM 结束]


系统初始化：
----------------------

在重置配置中，U-Boot 在重置入口点启动
（在大多数 PowerPC 系统上，地址为 0x00000100）。因为重置了
CS0# 的配置，这是板载闪存的镜像。
为了能够重新映射内存，U-Boot 然后跳转到其链接地址。
为了能够用 C 语言实现初始化代码，需要一个（小！）
初始堆栈设置在内部双端口 RAM 中（如果 CPU
提供这样的功能，如 MPC8xx 或 MPC8260），或者在锁定的
数据缓存的一部分。之后，U-Boot初始化CPU核心，
缓存和 SIU。

接下来，所有（可能）可用的存储体都使用映射
初步测绘。例如，我们将它们放在 512 MB 边界上
（0x20000000 的倍数：0x00000000 和 0x20000000 上的 SDRAM，Flash
在 0x40000000 和 0x60000000 上，SRAM 在 0x80000000 上）。那么 UPM A 是
编程用于 SDRAM 访问。使用临时配置，
运行简单的内存测试以确定 SDRAM 的大小
银行。

当有多个 SDRAM Bank 且这些 Bank 为
大小不同，先映射最大的。对于相同大小，第一个
首先映射库 (CS2#)。第一个映射始终用于地址
0x00000000，任何其他银行立即创建
从0开始的连续内存。

然后，监视器将自身安装在SDRAM区域的上端
并分配内存供 malloc() 使用和全局 Board
信息数据；此外，异常向量代码被复制到低 RAM
页，并设置了最终堆栈。

只有经过这次重定位，你才会有一个“正常”的C环境；
直到你在几个方面受到限制，主要是因为你
从 ROM 运行，并且因为代码必须重新定位到
RAM 中的新地址。


U-Boot 移植指南：
----------------------

[基于 Jerry Van Baren 在 U-Boot-Users 邮件中的消息
名单，2002 年 10 月]


int main(int argc, char *argv[])
{
	叹息者不再有时间；

	信号（SIGALRM，no_more_time）；
	警报（PROJECT_DEADLINE - toSec（3 * WEEK））；

	如果（可用资金>可用人力）{
		付费顾问移植U-Boot；
		返回0；
	}

	下载最新的U-Boot源码；

	订阅 u-boot 邮件列表；

	如果（无知）
		email("嗨，我是 U-Boot 新手，我该如何开始？");

	同时（学习）{
		阅读顶层目录中的README文件；
		阅读http://www.denx.de/twiki/bin/view/DULG/Manual；
		阅读适用的 doc/*.README；
		阅读来源，卢克；
		/* 寻找 。 -名称“*。[chS]”| xargs grep -i <关键字> */
	}

	if (available_money > toLocalCurrency ($2500))
		购买BDI3000；
	别的
		增加很多烦恼和时间；

	if (存在类似的板) { /* 希望... */
		cp -a board/<类似> 板/<我的板>
		cp include/configs/<similar>.h include/configs/<myboard>.h
	} 别的 {
		创建您自己的板支持子目录；
		创建您自己的板 include/configs/<myboard>.h 文件；
	}
	编辑新的 board/<myboard> 文件
	编辑新的 include/configs/<myboard>.h

	而（！接受）{
		在跑步的时候） {
			做 {
				添加/修改源代码；
			} 直到（编译）；
			调试;
			如果（无知）
				电子邮件（“嗨，我遇到问题...”）；
		}
		发送补丁文件到U-Boot邮件列表；
		如果（合理的批评）
			纳入电子邮件列表代码审查的改进；
		别的
			捍卫书面代码；
	}

	返回0；
}

无效 no_more_time (int sig)
{
      雇用_a_guru（）；
}


编码标准：
-----------------

对 U-Boot 的所有贡献都应符合 Linux 内核
编码风格；请参阅文件“Documentation/CodingStyle”和脚本
Linux 内核源目录中的“scripts/Lindent”。

源自不同项目的源文件（例如
MTD 子系统）通常不受这些准则的约束，并且不属于
重新格式化以方便后续迁移到较新版本
来源。

请注意，U-Boot 是用 C 语言实现的（以及一些小部分）
汇编器）；没有使用 C++，所以请不要使用 C++ 风格的注释 (//)
在你的代码中。

另请遵守以下格式规则：
- 删除所有尾随空白
- 使用制表符进行缩进和垂直对齐，而不是空格
- 确保不要使用 DOS '\r\n' 换行符
- 不要在源文件中添加超过 2 个连续的空行
- 不要在源文件中添加尾随空行

不符合标准的提交材料可能会被退回
并请求重新格式化更改。


提交补丁：
-------------------

由于U-Boot的补丁数量不断增加，我们需要
制定一些规则。不符合本规则的提交内容
即使它们包含重要且有价值的内容，也可能会被拒绝。
详细信息
请参见http://www.denx.de/wiki/U-Boot/Patches 。

补丁应发送至 u-boot 邮件列表 <u-boot@lists.denx.de>；
参见http://lists.denx.de/mailman/listinfo/u-boot

当您发送补丁时，请包含以下信息
它：

* 对于错误修复：错误的描述以及补丁如何修复
  这个错误。请尝试包含一种方法来证明
  补丁实际上修复了一些东西。

* 对于新功能：该功能的描述以及您的
  执行。

* 纯文本形式的变更日志条目（与补丁分开）

* 对于主要贡献，请添加一个 MAINTAINERS 文件，其中包含您的
  信息以及关联的文件和目录引用。

* 当您添加对新板的支持时，不要忘记添加
  Boards.cfg 文件的维护者电子邮件地址。

* 如果您的补丁添加了新的配置选项，请不要忘记
  将这些记录在 README 文件中。

* 补丁本身。如果你正在使用 git （这是*强烈*
  推荐）您可以使用以下命令轻松生成补丁
  “git 格式补丁”。如果您然后使用“git send-email”将其发送到
  U-Boot 邮件列表，您将避免大多数常见问题
  与其他一些邮件客户端。

  如果您无法使用 git，请使用“diff -purN OLD NEW”。如果您的版本是
  diff 不支持这些选项，然后获取最新版本
  GNU 差异。

  运行此命令时的当前目录应为父目录
  U-Boot 源代码树的目录（即请确保
  您的补丁包含足够的目录信息
  受影响的文件）。

  我们更喜欢纯文本形式的补丁。不鼓励使用 MIME 附件，
  不得使用压缩附件。

* 如果一组逻辑修改影响或创建了多个
  文件中，所有这些更改应在单个补丁文件中提交。

* 包含不同、不相关修改的变更集应
  作为单独的补丁提交，每个变更集一个补丁。


笔记：

* 在发送补丁之前，在您的补丁上运行 buildman 脚本
  源树并确保没有报告错误或警告
  对于任何一块板。

* 将修改保持在必要的最低限度：补丁
  包含几个不相关的更改或任意重新格式将
  返回并请求重新格式化/拆分它。

* 如果您修改现有代码，请确保您的新代码不会
  添加到代码的内存占用；-) 小即是美！
  添加新功能时，应仅根据条件进行编译
  （使用#ifdef），以及具有新功能的生成代码
  禁用必须不需要比旧代码更多的内存，而不需要您的
  修改。

* 请记住，每条消息的大小限制为 100 kB
  u-boot 邮件列表。更大的补丁将得到缓和。如果他们是
  合理且不太大，他们会得到承认。但补丁
  应避免大于尺寸限制。
