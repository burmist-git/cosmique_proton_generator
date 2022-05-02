ROOTCFLAGS    = $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS      = $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS     = $(shell $(ROOTSYS)/bin/root-config --glibs)

CXX  = g++
CXX += -I./	
CXX += -I./obj/

CXXFLAGS  = -g -Wall -fPIC -Wno-deprecated
CXXFLAGS += $(ROOTCFLAGS)

OUTLIB = ./obj/

#----------------------------------------------------#

all: cosmique_proton_generator mergeDATfiles

.PHONY: printmakehelp_and_reminder
printmakehelp_and_reminder: plots_effective_area.C Makefileterzina
	$(info  /******************************************************************************/)
	$(info  * task --> printmakehelp_and_reminder: plots_effective_area.C Makefileterzina *)
	$(info  * $$@ ----> $@                                         *)
	$(info  * $$< --------------------------------> $<                 *)
	$(info  * $$^ --------------------------------> $^ *)
	$(info  /******************************************************************************/)

cosmique_proton_generator: cosmique_proton_generator.C
	$(CXX) -o $@ $^ $(ROOTCFLAGS) $(ROOTLIBS) $(ROOTGLIBS)

mergeDATfiles: mergeDATfiles.C
	$(CXX) -o $@ $^ $(ROOTCFLAGS) $(ROOTLIBS) $(ROOTGLIBS)

clean:
	rm -f cosmique_proton_generator
	rm -f mergeDATfiles
	rm -f *~
	rm -f src/*~
	rm -f $(OUTLIB)*.o
