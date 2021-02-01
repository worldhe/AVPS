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

void PrintfInfo(const char *name)
{
    __android_log_print(ANDROID_LOG_INFO, "medium.cpp", "name = %s\n", name);

    AVFormatContext *pAVFormatContext = nullptr;
    pAVFormatContext = avformat_alloc_context();

    avformat_open_input(&pAVFormatContext, name, nullptr, nullptr);
    __android_log_print(ANDROID_LOG_INFO, "medium.cpp", "pAVFormatContext->video_codec_id = %d\n", pAVFormatContext->video_codec_id);
    __android_log_print(ANDROID_LOG_INFO, "medium.cpp", "pAVFormatContext->filename = %s\n", pAVFormatContext->filename);

}

void PrintfInfo()
{
    const char *name = "/data/user/0/com.whh.avps/files/6s_video_sample_1080p60fps.mp4";
    //const char *name = "/data/user/0/com.whh.avps/files/Simpson.mp4";
    __android_log_print(ANDROID_LOG_INFO, "medium.cpp", "name = %s\n", name);

    if((LIBAVCODEC_VERSION_MAJOR < 59))
    {
        __android_log_print(ANDROID_LOG_INFO, "medium.cpp", "LIBAVCODEC_VERSION_MAJOR < 59\n");
    }

    AVFormatContext *pAVFormatContext = nullptr;
    __android_log_print(ANDROID_LOG_INFO, "medium.cpp", "1.\n");
    av_register_all();
    pAVFormatContext = avformat_alloc_context();
    __android_log_print(ANDROID_LOG_INFO, "medium.cpp", "2.\n");

    int i = avformat_open_input(&pAVFormatContext, name, nullptr, nullptr);
    if(i < 0)
    {
        __android_log_print(ANDROID_LOG_INFO, "medium.cpp", " errno = %d: %m.\n", errno);
    }
    __android_log_print(ANDROID_LOG_INFO, "medium.cpp", "3. i = %d\n", i);
    __android_log_print(ANDROID_LOG_INFO, "medium.cpp", "pAVFormatContext->video_codec_id = %d\n", pAVFormatContext->video_codec_id);
    //__android_log_print(ANDROID_LOG_INFO, "medium.cpp", "pAVFormatContext->filename = %s\n", pAVFormatContext->filename);

}

