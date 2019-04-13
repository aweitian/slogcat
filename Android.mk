LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := slogcat
LOCAL_SRC_FILES := \
	main.cpp
LOCAL_LDLIBS    := -llog -lGLESv2
include $(BUILD_EXECUTABLE)
