//
// Created by Vincent on 2021/1/25.
//
#include "medium.h"
#include "android/log.h"
extern "C" {
#include <libavformat/avformat.h>
}

void PrintfVersion()
{
    __android_log_print(ANDROID_LOG_INFO, "medium.cpp", "version = %d\n", avcodec_version());
}

