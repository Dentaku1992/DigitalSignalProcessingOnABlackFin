# Generated by the VisualDSP++ IDDE

# Note:  Any changes made to this Makefile will be lost the next time the
# matching project file is loaded into the IDDE.  If you wish to preserve
# changes, rename this file and run it externally to the IDDE.

# The syntax of this Makefile is such that GNU Make v3.77 or higher is
# required.

# The current working directory should be the directory in which this
# Makefile resides.

# Supported targets:
#     CoreA_Debug
#     CoreA_Debug_clean

# Define this variable if you wish to run this Makefile on a host
# other than the host that created it and VisualDSP++ may be installed
# in a different directory.

ADI_DSP=C:\Program Files (x86)\Analog Devices\VisualDSP 5.1.2


# $VDSP is a gmake-friendly version of ADI_DIR

empty:=
space:= $(empty) $(empty)
VDSP_INTERMEDIATE=$(subst \,/,$(ADI_DSP))
VDSP=$(subst $(space),\$(space),$(VDSP_INTERMEDIATE))

RM=cmd /C del /F /Q

#
# Begin "CoreA_Debug" configuration
#

ifeq ($(MAKECMDGOALS),CoreA_Debug)

CoreA_Debug : ../CoreA.dlb 

Debug/ADV7179_reset.doj :ADV7179_reset.c main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h 
	@echo ".\ADV7179_reset.c"
	$(VDSP)/ccblkfn.exe -c .\ADV7179_reset.c -file-attr ProjectName=CoreA -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\ADV7179_reset.doj -MM

Debug/ADV7183_reset.doj :ADV7183_reset.c main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h 
	@echo ".\ADV7183_reset.c"
	$(VDSP)/ccblkfn.exe -c .\ADV7183_reset.c -file-attr ProjectName=CoreA -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\ADV7183_reset.doj -MM

Debug/Init_SDRAM.doj :../Init_SDRAM.c main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h 
	@echo "..\Init_SDRAM.c"
	$(VDSP)/ccblkfn.exe -c ..\Init_SDRAM.c -file-attr ProjectName=CoreA -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\Init_SDRAM.doj -MM

Debug/Interrupt_Init.doj :Interrupt_Init.c main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h 
	@echo ".\Interrupt_Init.c"
	$(VDSP)/ccblkfn.exe -c .\Interrupt_Init.c -file-attr ProjectName=CoreA -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\Interrupt_Init.doj -MM

Debug/Interrupt_Service.doj :Interrupt_Service.c main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h 
	@echo ".\Interrupt_Service.c"
	$(VDSP)/ccblkfn.exe -c .\Interrupt_Service.c -file-attr ProjectName=CoreA -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\Interrupt_Service.doj -MM

Debug/main.doj :main.c video.h main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h 
	@echo ".\main.c"
	$(VDSP)/ccblkfn.exe -c .\main.c -file-attr ProjectName=CoreA -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\main.doj -MM

Debug/PPI0_Init.doj :PPI0_Init.c main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h 
	@echo ".\PPI0_Init.c"
	$(VDSP)/ccblkfn.exe -c .\PPI0_Init.c -file-attr ProjectName=CoreA -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\PPI0_Init.doj -MM

Debug/set_PLL.doj :../set_PLL.c main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h 
	@echo "..\set_PLL.c"
	$(VDSP)/ccblkfn.exe -c ..\set_PLL.c -file-attr ProjectName=CoreA -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\set_PLL.doj -MM

Debug/video.doj :video.c main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h video.h 
	@echo ".\video.c"
	$(VDSP)/ccblkfn.exe -c .\video.c -file-attr ProjectName=CoreA -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\video.doj -MM

../CoreA.dlb :./Debug/ADV7179_reset.doj ./Debug/ADV7183_reset.doj ./Debug/Init_SDRAM.doj ./Debug/Interrupt_Init.doj ./Debug/Interrupt_Service.doj ./Debug/main.doj ./Debug/PPI0_Init.doj ./Debug/set_PLL.doj ./Debug/video.doj 
	@echo "Creating library..."
	$(VDSP)/ccblkfn.exe -proc ADSP-BF561 -build-lib -o ..\CoreA.dlb .\Debug\ADV7179_reset.doj .\Debug\ADV7183_reset.doj .\Debug\Init_SDRAM.doj .\Debug\Interrupt_Init.doj .\Debug\Interrupt_Service.doj .\Debug\main.doj .\Debug\PPI0_Init.doj .\Debug\set_PLL.doj .\Debug\video.doj -MM

endif

ifeq ($(MAKECMDGOALS),CoreA_Debug_clean)

CoreA_Debug_clean:
	-$(RM) "Debug\ADV7179_reset.doj"
	-$(RM) "Debug\ADV7183_reset.doj"
	-$(RM) "Debug\Init_SDRAM.doj"
	-$(RM) "Debug\Interrupt_Init.doj"
	-$(RM) "Debug\Interrupt_Service.doj"
	-$(RM) "Debug\main.doj"
	-$(RM) "Debug\PPI0_Init.doj"
	-$(RM) "Debug\set_PLL.doj"
	-$(RM) "Debug\video.doj"
	-$(RM) "..\CoreA.dlb"
	-$(RM) ".\Debug\*.ipa"
	-$(RM) ".\Debug\*.opa"
	-$(RM) ".\Debug\*.ti"
	-$(RM) ".\Debug\*.pgi"
	-$(RM) ".\*.rbld"

endif


