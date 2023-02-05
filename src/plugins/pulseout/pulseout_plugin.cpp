//////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2007-2016 musikcube team
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright notice,
//      this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of the author nor the names of other contributors may
//      be used to endorse or promote products derived from this software
//      without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include <musikcore/sdk/constants.h>
#include <musikcore/sdk/IPlugin.h>
#include <musikcore/sdk/IOutput.h>

#include "PulseOut.h"

class PulsePlugin : public musik::core::sdk::IPlugin {
    public:
        void Release() override { delete this; }
        const char* Name() override { return "PulseAudio IOutput"; }
        const char* Version() override { return MUSIKCUBE_VERSION_WITH_COMMIT_HASH; }
        const char* Author() override { return "clangen"; }
        const char* Guid() override { return "67c7e90b-5123-41c0-b03a-838ecd6cb8b5"; }
        bool Configurable() override { return false; }
        void Configure() override { }
        void Reload() override { }
        int SdkVersion() override { return musik::core::sdk::SdkVersion; }
};

extern "C" musik::core::sdk::IPlugin* GetPlugin() {
    return new PulsePlugin();
}

extern "C" musik::core::sdk::IOutput* GetAudioOutput() {
    return new PulseOut();
}
