#pragma once
#include <windows.h>
#include <MMdeviceapi.h>
#include <Audioclient.h>
#include <Audiopolicy.h>

#include <vector>

class MyAudioSink{
    public:
        explicit MyAudioSink();
        MyAudioSink(const MyAudioSink& other) = delete;
        virtual ~MyAudioSink() = default;
        virtual HRESULT CopyData(BYTE* pData, UINT32 numFramesAvailable, BOOL* Done);
        virtual HRESULT SetFormat(WAVEFORMATEX* waveformatex);

        std::vector<BYTE> Data;

    private:
        UINT32 numFramesAvailable;
        BOOL Done;
        WAVEFORMATEX waveformatex;
};
