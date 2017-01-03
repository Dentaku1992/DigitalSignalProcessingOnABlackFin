# Generated by the VisualDSP++ IDDE

# Note:  Any changes made to this Makefile will be lost the next time the
# matching project file is loaded into the IDDE.  If you wish to preserve
# changes, rename this file and run it externally to the IDDE.

# The syntax of this Makefile is such that GNU Make v3.77 or higher is
# required.

# The current working directory should be the directory in which this
# Makefile resides.

# Supported targets:
#     CoreB_Debug
#     CoreB_Debug_clean

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
# Begin "CoreB_Debug" configuration
#

ifeq ($(MAKECMDGOALS),CoreB_Debug)

CoreB_Debug : ../CoreB.dlb 

./Debug/Interrupt_Init.doj :Interrupt_Init.c main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h 
	@echo ".\Interrupt_Init.c"
	$(VDSP)/ccblkfn.exe -c .\Interrupt_Init.c -file-attr ProjectName=CoreB -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\Interrupt_Init.doj -MM

./Debug/Interrupt_Service.doj :Interrupt_Service.c main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h video.h 
	@echo ".\Interrupt_Service.c"
	$(VDSP)/ccblkfn.exe -c .\Interrupt_Service.c -file-attr ProjectName=CoreB -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\Interrupt_Service.doj -MM

./Debug/main.doj :main.c main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h 
	@echo ".\main.c"
	$(VDSP)/ccblkfn.exe -c .\main.c -file-attr ProjectName=CoreB -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\main.doj -MM

./Debug/PPI1_Init.doj :PPI1_Init.c main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h 
	@echo ".\PPI1_Init.c"
	$(VDSP)/ccblkfn.exe -c .\PPI1_Init.c -file-attr ProjectName=CoreB -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\PPI1_Init.doj -MM

./Debug/set_PLL.doj :../set_PLL.c main.h ../system.h $(VDSP)/Blackfin/include/cdefBF561.h $(VDSP)/Blackfin/include/defBF561.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/ccblkfn.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/builtins.h $(VDSP)/Blackfin/include/sys/builtins_support.h $(VDSP)/Blackfin/include/fract_typedef.h $(VDSP)/Blackfin/include/fr2x16_typedef.h $(VDSP)/Blackfin/include/r2x16_typedef.h $(VDSP)/Blackfin/include/raw_typedef.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/mc_typedef.h $(VDSP)/Blackfin/include/sys/exception.h 
	@echo "..\set_PLL.c"
	$(VDSP)/ccblkfn.exe -c ..\set_PLL.c -file-attr ProjectName=CoreB -O -Ov100 -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -mem -si-revision 0.5 -proc ADSP-BF561 -o .\Debug\set_PLL.doj -MM

../CoreB.dlb :./Debug/Interrupt_Init.doj ./Debug/Interrupt_Service.doj ./Debug/main.doj ./Debug/PPI1_Init.doj ./Debug/set_PLL.doj 
	@echo "Creating library..."
	$(VDSP)/ccblkfn.exe -proc ADSP-BF561 -build-lib -o ..\CoreB.dlb .\Debug\Interrupt_Init.doj .\Debug\Interrupt_Service.doj .\Debug\main.doj .\Debug\PPI1_Init.doj .\Debug\set_PLL.doj -MM

endif

ifeq ($(MAKECMDGOALS),CoreB_Debug_clean)

CoreB_Debug_clean:
	-$(RM) ".\Debug\Interrupt_Init.doj"
	-$(RM) ".\Debug\Interrupt_Service.doj"
	-$(RM) ".\Debug\main.doj"
	-$(RM) ".\Debug\PPI1_Init.doj"
	-$(RM) ".\Debug\set_PLL.doj"
	-$(RM) "..\CoreB.dlb"
	-$(RM) ".\Debug\*.ipa"
	-$(RM) ".\Debug\*.opa"
	-$(RM) ".\Debug\*.ti"
	-$(RM) ".\Debug\*.pgi"
	-$(RM) ".\*.rbld"

endif

