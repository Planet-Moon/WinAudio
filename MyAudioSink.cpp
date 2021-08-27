#include <MyAudioSink.h>

MyAudioSink::MyAudioSink()
{
    return;
}

HRESULT MyAudioSink::CopyData(BYTE* pData_, UINT32 numFramesAvailable_, BOOL* Done_)
{
    Data.push_back(*pData_);
    numFramesAvailable = numFramesAvailable_;
    Done = *Done_;
    return S_OK;
}

HRESULT MyAudioSink::SetFormat(WAVEFORMATEX* waveformatex_)
{
    waveformatex = *waveformatex_;
    return S_OK;
}
