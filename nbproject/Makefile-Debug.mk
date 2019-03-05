#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ESU.o \
	${OBJECTDIR}/Graph.o \
	${OBJECTDIR}/NautyLink.o \
	${OBJECTDIR}/RandESU.o \
	${OBJECTDIR}/RandomGraphAnalysis.o \
	${OBJECTDIR}/RandomGraphGenerator.o \
	${OBJECTDIR}/StatisticalAnalysis.o \
	${OBJECTDIR}/Subgraph.o \
	${OBJECTDIR}/SubgraphCount.o \
	${OBJECTDIR}/SubgraphProfile.o \
	${OBJECTDIR}/nauty/gtools.o \
	${OBJECTDIR}/nauty/naugraph.o \
	${OBJECTDIR}/nauty/naurng.o \
	${OBJECTDIR}/nauty/nausparse.o \
	${OBJECTDIR}/nauty/nautil.o \
	${OBJECTDIR}/nauty/nautinv.o \
	${OBJECTDIR}/nauty/naututil.o \
	${OBJECTDIR}/nauty/nauty.o \
	${OBJECTDIR}/nauty/schreier.o \
	${OBJECTDIR}/nauty/sorttemplates.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/newsimpletest.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++11
CXXFLAGS=-std=c++11

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/libnemostaticlib.a

${CND_DISTDIR}/libnemostaticlib.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}
	${RM} ${CND_DISTDIR}/libnemostaticlib.a
	${AR} -rv ${CND_DISTDIR}/libnemostaticlib.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/libnemostaticlib.a

${OBJECTDIR}/ESU.o: ESU.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ESU.o ESU.cpp

${OBJECTDIR}/Graph.o: Graph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graph.o Graph.cpp

${OBJECTDIR}/NautyLink.o: NautyLink.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NautyLink.o NautyLink.cpp

${OBJECTDIR}/RandESU.o: RandESU.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandESU.o RandESU.cpp

${OBJECTDIR}/RandomGraphAnalysis.o: RandomGraphAnalysis.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandomGraphAnalysis.o RandomGraphAnalysis.cpp

${OBJECTDIR}/RandomGraphGenerator.o: RandomGraphGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandomGraphGenerator.o RandomGraphGenerator.cpp

${OBJECTDIR}/StatisticalAnalysis.o: StatisticalAnalysis.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StatisticalAnalysis.o StatisticalAnalysis.cpp

${OBJECTDIR}/Subgraph.o: Subgraph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Subgraph.o Subgraph.cpp

${OBJECTDIR}/SubgraphCount.o: SubgraphCount.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SubgraphCount.o SubgraphCount.cpp

${OBJECTDIR}/SubgraphProfile.o: SubgraphProfile.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SubgraphProfile.o SubgraphProfile.cpp

${OBJECTDIR}/nauty/gtools.o: nauty/gtools.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/gtools.o nauty/gtools.c

${OBJECTDIR}/nauty/naugraph.o: nauty/naugraph.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/naugraph.o nauty/naugraph.c

${OBJECTDIR}/nauty/naurng.o: nauty/naurng.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/naurng.o nauty/naurng.c

${OBJECTDIR}/nauty/nausparse.o: nauty/nausparse.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/nausparse.o nauty/nausparse.c

${OBJECTDIR}/nauty/nautil.o: nauty/nautil.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/nautil.o nauty/nautil.c

${OBJECTDIR}/nauty/nautinv.o: nauty/nautinv.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/nautinv.o nauty/nautinv.c

${OBJECTDIR}/nauty/naututil.o: nauty/naututil.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/naututil.o nauty/naututil.c

${OBJECTDIR}/nauty/nauty.o: nauty/nauty.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/nauty.o nauty/nauty.c

${OBJECTDIR}/nauty/schreier.o: nauty/schreier.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/schreier.o nauty/schreier.c

${OBJECTDIR}/nauty/sorttemplates.o: nauty/sorttemplates.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/sorttemplates.o nauty/sorttemplates.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newsimpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/newsimpletest.o: tests/newsimpletest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newsimpletest.o tests/newsimpletest.cpp


${OBJECTDIR}/ESU_nomain.o: ${OBJECTDIR}/ESU.o ESU.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ESU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ESU_nomain.o ESU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ESU.o ${OBJECTDIR}/ESU_nomain.o;\
	fi

${OBJECTDIR}/Graph_nomain.o: ${OBJECTDIR}/Graph.o Graph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Graph.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graph_nomain.o Graph.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Graph.o ${OBJECTDIR}/Graph_nomain.o;\
	fi

${OBJECTDIR}/NautyLink_nomain.o: ${OBJECTDIR}/NautyLink.o NautyLink.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/NautyLink.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NautyLink_nomain.o NautyLink.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/NautyLink.o ${OBJECTDIR}/NautyLink_nomain.o;\
	fi

${OBJECTDIR}/RandESU_nomain.o: ${OBJECTDIR}/RandESU.o RandESU.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RandESU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandESU_nomain.o RandESU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/RandESU.o ${OBJECTDIR}/RandESU_nomain.o;\
	fi

${OBJECTDIR}/RandomGraphAnalysis_nomain.o: ${OBJECTDIR}/RandomGraphAnalysis.o RandomGraphAnalysis.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RandomGraphAnalysis.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandomGraphAnalysis_nomain.o RandomGraphAnalysis.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/RandomGraphAnalysis.o ${OBJECTDIR}/RandomGraphAnalysis_nomain.o;\
	fi

${OBJECTDIR}/RandomGraphGenerator_nomain.o: ${OBJECTDIR}/RandomGraphGenerator.o RandomGraphGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RandomGraphGenerator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandomGraphGenerator_nomain.o RandomGraphGenerator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/RandomGraphGenerator.o ${OBJECTDIR}/RandomGraphGenerator_nomain.o;\
	fi

${OBJECTDIR}/StatisticalAnalysis_nomain.o: ${OBJECTDIR}/StatisticalAnalysis.o StatisticalAnalysis.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/StatisticalAnalysis.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StatisticalAnalysis_nomain.o StatisticalAnalysis.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/StatisticalAnalysis.o ${OBJECTDIR}/StatisticalAnalysis_nomain.o;\
	fi

${OBJECTDIR}/Subgraph_nomain.o: ${OBJECTDIR}/Subgraph.o Subgraph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Subgraph.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Subgraph_nomain.o Subgraph.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Subgraph.o ${OBJECTDIR}/Subgraph_nomain.o;\
	fi

${OBJECTDIR}/SubgraphCount_nomain.o: ${OBJECTDIR}/SubgraphCount.o SubgraphCount.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SubgraphCount.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SubgraphCount_nomain.o SubgraphCount.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SubgraphCount.o ${OBJECTDIR}/SubgraphCount_nomain.o;\
	fi

${OBJECTDIR}/SubgraphProfile_nomain.o: ${OBJECTDIR}/SubgraphProfile.o SubgraphProfile.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SubgraphProfile.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SubgraphProfile_nomain.o SubgraphProfile.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SubgraphProfile.o ${OBJECTDIR}/SubgraphProfile_nomain.o;\
	fi

${OBJECTDIR}/nauty/gtools_nomain.o: ${OBJECTDIR}/nauty/gtools.o nauty/gtools.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	@NMOUTPUT=`${NM} ${OBJECTDIR}/nauty/gtools.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/gtools_nomain.o nauty/gtools.c;\
	else  \
	    ${CP} ${OBJECTDIR}/nauty/gtools.o ${OBJECTDIR}/nauty/gtools_nomain.o;\
	fi

${OBJECTDIR}/nauty/naugraph_nomain.o: ${OBJECTDIR}/nauty/naugraph.o nauty/naugraph.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	@NMOUTPUT=`${NM} ${OBJECTDIR}/nauty/naugraph.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/naugraph_nomain.o nauty/naugraph.c;\
	else  \
	    ${CP} ${OBJECTDIR}/nauty/naugraph.o ${OBJECTDIR}/nauty/naugraph_nomain.o;\
	fi

${OBJECTDIR}/nauty/naurng_nomain.o: ${OBJECTDIR}/nauty/naurng.o nauty/naurng.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	@NMOUTPUT=`${NM} ${OBJECTDIR}/nauty/naurng.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/naurng_nomain.o nauty/naurng.c;\
	else  \
	    ${CP} ${OBJECTDIR}/nauty/naurng.o ${OBJECTDIR}/nauty/naurng_nomain.o;\
	fi

${OBJECTDIR}/nauty/nausparse_nomain.o: ${OBJECTDIR}/nauty/nausparse.o nauty/nausparse.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	@NMOUTPUT=`${NM} ${OBJECTDIR}/nauty/nausparse.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/nausparse_nomain.o nauty/nausparse.c;\
	else  \
	    ${CP} ${OBJECTDIR}/nauty/nausparse.o ${OBJECTDIR}/nauty/nausparse_nomain.o;\
	fi

${OBJECTDIR}/nauty/nautil_nomain.o: ${OBJECTDIR}/nauty/nautil.o nauty/nautil.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	@NMOUTPUT=`${NM} ${OBJECTDIR}/nauty/nautil.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/nautil_nomain.o nauty/nautil.c;\
	else  \
	    ${CP} ${OBJECTDIR}/nauty/nautil.o ${OBJECTDIR}/nauty/nautil_nomain.o;\
	fi

${OBJECTDIR}/nauty/nautinv_nomain.o: ${OBJECTDIR}/nauty/nautinv.o nauty/nautinv.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	@NMOUTPUT=`${NM} ${OBJECTDIR}/nauty/nautinv.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/nautinv_nomain.o nauty/nautinv.c;\
	else  \
	    ${CP} ${OBJECTDIR}/nauty/nautinv.o ${OBJECTDIR}/nauty/nautinv_nomain.o;\
	fi

${OBJECTDIR}/nauty/naututil_nomain.o: ${OBJECTDIR}/nauty/naututil.o nauty/naututil.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	@NMOUTPUT=`${NM} ${OBJECTDIR}/nauty/naututil.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/naututil_nomain.o nauty/naututil.c;\
	else  \
	    ${CP} ${OBJECTDIR}/nauty/naututil.o ${OBJECTDIR}/nauty/naututil_nomain.o;\
	fi

${OBJECTDIR}/nauty/nauty_nomain.o: ${OBJECTDIR}/nauty/nauty.o nauty/nauty.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	@NMOUTPUT=`${NM} ${OBJECTDIR}/nauty/nauty.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/nauty_nomain.o nauty/nauty.c;\
	else  \
	    ${CP} ${OBJECTDIR}/nauty/nauty.o ${OBJECTDIR}/nauty/nauty_nomain.o;\
	fi

${OBJECTDIR}/nauty/schreier_nomain.o: ${OBJECTDIR}/nauty/schreier.o nauty/schreier.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	@NMOUTPUT=`${NM} ${OBJECTDIR}/nauty/schreier.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/schreier_nomain.o nauty/schreier.c;\
	else  \
	    ${CP} ${OBJECTDIR}/nauty/schreier.o ${OBJECTDIR}/nauty/schreier_nomain.o;\
	fi

${OBJECTDIR}/nauty/sorttemplates_nomain.o: ${OBJECTDIR}/nauty/sorttemplates.o nauty/sorttemplates.c 
	${MKDIR} -p ${OBJECTDIR}/nauty
	@NMOUTPUT=`${NM} ${OBJECTDIR}/nauty/sorttemplates.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/sorttemplates_nomain.o nauty/sorttemplates.c;\
	else  \
	    ${CP} ${OBJECTDIR}/nauty/sorttemplates.o ${OBJECTDIR}/nauty/sorttemplates_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/libnemostaticlib.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
