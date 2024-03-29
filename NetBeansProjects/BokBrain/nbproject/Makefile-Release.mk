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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1835967288/Genetic.o \
	${OBJECTDIR}/_ext/1835967288/BokBrain.o \
	${OBJECTDIR}/_ext/1835967288/NNet.o \
	${OBJECTDIR}/_ext/1835967288/Neuron.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --libs libglog`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bokbrain

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bokbrain: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bokbrain ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1835967288/Genetic.o: ../../src/BokBrain/src/Genetic.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1835967288
	${RM} $@.d
	$(COMPILE.cc) -O2 `pkg-config --cflags libglog`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1835967288/Genetic.o ../../src/BokBrain/src/Genetic.cpp

${OBJECTDIR}/_ext/1835967288/BokBrain.o: ../../src/BokBrain/src/BokBrain.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1835967288
	${RM} $@.d
	$(COMPILE.cc) -O2 `pkg-config --cflags libglog`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1835967288/BokBrain.o ../../src/BokBrain/src/BokBrain.cpp

${OBJECTDIR}/_ext/1835967288/NNet.o: ../../src/BokBrain/src/NNet.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1835967288
	${RM} $@.d
	$(COMPILE.cc) -O2 `pkg-config --cflags libglog`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1835967288/NNet.o ../../src/BokBrain/src/NNet.cpp

${OBJECTDIR}/_ext/1835967288/Neuron.o: ../../src/BokBrain/src/Neuron.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1835967288
	${RM} $@.d
	$(COMPILE.cc) -O2 `pkg-config --cflags libglog`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1835967288/Neuron.o ../../src/BokBrain/src/Neuron.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bokbrain

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
