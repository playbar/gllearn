# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := vulkan_headers
### Rules for final target.
$(obj).target/vulkan_headers.stamp: TOOLSET := $(TOOLSET)
$(obj).target/vulkan_headers.stamp:  FORCE_DO_CMD
	$(call do_cmd,touch)

all_deps += $(obj).target/vulkan_headers.stamp
# Add target alias
.PHONY: vulkan_headers
vulkan_headers: $(obj).target/vulkan_headers.stamp

# Add target alias to "all" target.
.PHONY: all
all: vulkan_headers

