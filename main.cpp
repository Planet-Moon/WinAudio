#include <iostream>
#include <microsoft_example.h>

int main(int argc, char *argv[])
{
    std::cout << "running" << std::endl;

    HRESULT hr = CoInitialize(nullptr);

    MyAudioSink audio_sink = MyAudioSink();

    RecordAudioStream(&audio_sink);

    CoUninitialize();
    return 0;
}