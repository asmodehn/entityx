# EntityX++ Library built as static library
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := entityx_static
LOCAL_MODULE_FILENAME := entityx_static

LOCAL_CPP_EXTENSION := .cc

LOCAL_SRC_FILES :=    	entityx/deps/Dependencies.cc\
						entityx/Entity.cc\
						entityx/Event.cc\
						entityx/Manager.cc\
						entityx/System.cc\
						entityx/tags/TagsComponent.cc\
						entityx/help/Timer.cc

LOCAL_CFLAGS += -fvisibility=hidden

LOCAL_C_INCLUDES := $(LOCAL_PATH)

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)

include $(BUILD_STATIC_LIBRARY)
