# Define the subdirectories containing the projects
SUBDIRS := $(wildcard */)

# Define the targets
.PHONY: all clean $(SUBDIRS)

# Default target
all: $(SUBDIRS)

# Build all projects in subdirectories
$(SUBDIRS):
	$(MAKE) -C $@ build

# Clean all projects in subdirectories
clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

# Build only the subdirectory where make is called
build:
	@echo "Building in current directory: $(PWD)"
	@$(MAKE) -C $(shell basename $(CURDIR))