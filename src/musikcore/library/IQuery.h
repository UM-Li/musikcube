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

#include <string>
#include <vector>
#include <sigslot/sigslot.h>

#include <musikcore/library/IIndexer.h>
#include <musikcore/db/Connection.h>
#include <musikcore/support/DeleteDefaults.h>

namespace musik { namespace core { namespace db {

    class IQuery {
        public:
            typedef enum {
                Idle = 1,
                Running = 2,
                Failed = 3,
                Finished = 4,
                Canceled = 5
            } Status;

            DELETE_COPY_AND_ASSIGNMENT_DEFAULTS_WITH_DEFAULT_CTOR(IQuery)

            virtual ~IQuery() { }

            virtual int GetStatus() = 0;
            virtual int GetId() = 0;
            virtual int GetOptions() = 0;
            virtual std::string Name() = 0;
    };

    class ISerializableQuery: public IQuery {
        public:
            DELETE_COPY_AND_ASSIGNMENT_DEFAULTS_WITH_DEFAULT_CTOR(ISerializableQuery)

            virtual ~ISerializableQuery() { }

            virtual std::string SerializeQuery() = 0;
            virtual std::string SerializeResult() = 0;
            virtual void DeserializeResult(const std::string& data) = 0;
            virtual void Invalidate() = 0;
    };

} } }
