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
    //pAVFormatContext = avformat_alloc_context();

    AVInputFormat *pAVInputFormat = nullptr;
    AVDictionary *pAVDictionary = nullptr;
    avformat_open_input(&pAVFormatContext, name, pAVInputFormat, &pAVDictionary);
    __android_log_print(ANDROID_LOG_INFO, "medium.cpp", "pAVFormatContext->video_codec_id = %d\n", pAVFormatContext->video_codec_id);
    __android_log_print(ANDROID_LOG_INFO, "medium.cpp", "pAVFormatContext->filename = %s\n", pAVFormatContext->filename);

}

