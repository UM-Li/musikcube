//////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2004-2023 musikcube team
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

#pragma once

#include <musikcore/config.h>
#include <musikcore/library/LocalLibrary.h>
#include <musikcore/library/RemoteLibrary.h>
#include <musikcore/runtime/IMessageQueue.h>
#include <sigslot/sigslot.h>
#include <map>
#include <vector>

namespace musik { namespace core {

    class LibraryFactory {
        public:
            using LibraryVector = std::vector<ILibraryPtr>;
            using LibraryMap = std::map<int, ILibraryPtr>;
            using LibrariesUpdatedEvent = sigslot::signal0<>;
            using IMessageQueue = musik::core::runtime::IMessageQueue;

            LibrariesUpdatedEvent LibrariesUpdated;

            ~LibraryFactory();

            static void Initialize(IMessageQueue& messageQueue);
            static LibraryFactory& Instance();
            static void Shutdown();

            ILibraryPtr DefaultLocalLibrary();
            ILibraryPtr DefaultRemoteLibrary();
            ILibraryPtr DefaultLibrary(ILibrary::Type type);

            LibraryVector Libraries();
            ILibraryPtr CreateLibrary(const std::string& name, ILibrary::Type type);

            ILibraryPtr GetLibrary(int identifier);

        private:
            LibraryFactory();

            ILibraryPtr AddLibrary(int id, ILibrary::Type type, const std::string& name);

            LibraryVector libraries;
            LibraryMap libraryMap;
    };

} }
