# This is a list of all of the locations that contain a Makefile.dir. Entries are relative to this directory
# Some example directory lisitngs
# Module
# Group/Module1
# Group/Module1/SubModule1
# Group/Module1/SubModule2
HOST_DIRS =\

# This is another listing of directories incase you want to build a different/addition set of directories
# for a different ARCH
TARGET_DIRS =\

default: host

# Names of the libraries that are to be built as a part of this project. Only necessary if you wish to
# make libraries from the topmost directory
libs= 

# Name of the directories that contain Makefile.dir-templated Makefiles. These are required
dirs= 

# Used to create build rules for libs and dirs above for the "target" platform
define build_target
$(1)-$(2):
	@echo Building $(1) for $(2)
	make -s -C $(1) $(2)
endef

# Used to create the build rules for the above libs and dirs for the "host" platform
define rule_build
$(1)-$(2)
endef

# Used to create the "clean" rules for the libs and dirs above for the "target" platform
define clean_target
$(1)-$(2)-clean:
	@echo Cleaning $(1) for $(2)
	make -s -C $(1) clean
endef

# Used to create the "clean" rules for the above libs and dirs for the "host" platform
define rule_clean
$(1)-$(2)-clean
endef

# Used to create the "
define very_clean_target
$(1)-$(2)-very-clean:
	@echo Very cleaning $(1) for $(2)
	make -s -C $(1) very_clean
endef

define rule_very_clean
$(1)-$(2)-very-clean
endef

all: super-clean target clean-host host

target: $(foreach proj,$(TARGET_DIRS),$(call rule_build,$(proj),target))
	@echo Done Building for RaspberryPi

host: $(foreach proj,$(HOST_DIRS),$(call rule_build,$(proj),host))
	@echo Done Building for Desktop

clean: clean-target clean-host
	@echo Done Cleaning target and host

clean-target: $(foreach proj,$(TARGET_DIRS),$(call rule_clean,$(proj),target))
	@echo Done Cleaning target

clean-host: $(foreach proj,$(HOST_DIRS),$(call rule_clean,$(proj),host))
	@echo Done Cleaning  host

very_clean: very-clean-target very-clean-host
	@echo Done Very Cleaning target and host

very-clean-target: $(foreach proj,$(TARGET_DIRS),$(call rule_very_clean,$(proj),target))
	@echo Done Very Cleaning target

very-clean-host: $(foreach proj,$(HOST_DIRS),$(call rule_very_clean,$(proj),host))
	@echo Done Very Cleaning host

super-clean: very_clean super-clean-host super-clean-target
	@echo Super Clean!

super-clean-host:
	@echo ${libs} | sed 's/ /\n/g' | sed 's/lib\(.*\..*\)/host\/debug\/lib\/lib\1/g' | xargs rm -f
	@echo ${dirs} | sed 's/ /\n/g' | sed 's/\(.*\)/host\/debug\/include\/\1/g' | xargs rm -rf
	@echo ${libs} | sed 's/ /\n/g' | sed 's/lib\(.*\..*\)/host\/release\/lib\/lib\1/g' | xargs rm -f
	@echo ${dirs} | sed 's/ /\n/g' | sed 's/\(.*\)/host\/release\/include\/\1/g' | xargs rm -rf

super-clean-target:
	@echo ${libs} | sed 's/ /\n/g' | sed 's/lib\(.*\..*\)/target\/debug\/lib\/lib\1/g' | xargs rm -f
	@echo ${dirs} | sed 's/ /\n/g' | sed 's/\(.*\)/target\/debug\/include\/\1/g' | xargs rm -rf
	@echo ${libs} | sed 's/ /\n/g' | sed 's/lib\(.*\..*\)/target\/release\/lib\/lib\1/g' | xargs rm -f
	@echo ${dirs} | sed 's/ /\n/g' | sed 's/\(.*\)/target\/release\/include\/\1/g' | xargs rm -rf


# Define the rules for building
$(foreach proj,$(TARGET_DIRS),$(eval $(call build_target,$(proj),target)))
$(foreach proj,$(HOST_DIRS),$(eval $(call build_target,$(proj),host)))

# Define the rules for cleaning
$(foreach proj,$(TARGET_DIRS),$(eval $(call clean_target,$(proj),target)))
$(foreach proj,$(HOST_DIRS),$(eval $(call clean_target,$(proj),host)))

# Define the rules for cleaning everything
$(foreach proj,$(TARGET_DIRS),$(eval $(call very_clean_target,$(proj),target)))
$(foreach proj,$(HOST_DIRS),$(eval $(call very_clean_target,$(proj),host)))
