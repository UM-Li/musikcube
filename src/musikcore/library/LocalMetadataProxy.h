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

#include <musikcore/library/ILibrary.h>
#include <musikcore/sdk/IMetadataProxy.h>

namespace musik { namespace core { namespace library { namespace query {

    class LocalMetadataProxy : public musik::core::sdk::IMetadataProxy {
        public:
            LocalMetadataProxy(musik::core::ILibraryPtr library);

            musik::core::sdk::ITrackList*
                QueryTracks(
                    const char* query = "",
                    int limit = -1,
                    int offset = 0) override;

            musik::core::sdk::ITrack*
                QueryTrackById(int64_t trackId) override;

            musik::core::sdk::ITrack*
                QueryTrackByExternalId(const char* externalId) override;

            musik::core::sdk::ITrackList*
                QueryTracksByCategory(
                    const char* categoryType,
                    int64_t selectedId,
                    const char* filter = "",
                    int limit = -1,
                    int offset = 0) override;

            musik::core::sdk::ITrackList*
                QueryTracksByCategories(
                    musik::core::sdk::IValue** categories,
                    size_t categoryCount,
                    const char* filter = "",
                    int limit = -1,
                    int offset = 0) override;

            musik::core::sdk::ITrackList* QueryTracksByExternalId(
                const char** externalIds, size_t externalIdCount) override;

            musik::core::sdk::IValueList* ListCategories() override;

            musik::core::sdk::IValueList*
                QueryCategory(
                    const char* type,
                    const char* filter = "") override;

            musik::core::sdk::IValueList*
                QueryCategoryWithPredicate(
                    const char* type,
                    const char* predicateType,
                    int64_t predicateId,
                    const char* filter = "") override;

            musik::core::sdk::IValueList*
                QueryCategoryWithPredicates(
                    const char* type,
                    musik::core::sdk::IValue** predicates,
                    size_t predicateCount,
                    const char* filter = "") override;

            musik::core::sdk::IMapList*
                QueryAlbums(const char* filter = "") override;

            musik::core::sdk::IMapList* QueryAlbums(
                const char* categoryIdName,
                int64_t categoryIdValue,
                const char* filter = "") override;

            int64_t SavePlaylistWithIds(
                int64_t* trackIds,
                size_t trackIdCount,
                const char* name,
                const int64_t playlistId = 0) override;

            int64_t SavePlaylistWithExternalIds(
                const char** externalIds,
                size_t externalIdCount,
                const char* playlistName,
                const int64_t playlistId = 0) override;

            int64_t SavePlaylistWithTrackList(
                musik::core::sdk::ITrackList* trackList,
                const char* playlistName,
                const int64_t playlistId = 0) override;

            bool RenamePlaylist(
                const int64_t playlistId,
                const char* name) override;

            bool DeletePlaylist(const int64_t playlistId) override;

            bool AppendToPlaylistWithIds(
                const int64_t playlistId,
                const int64_t* trackIds,
                size_t trackIdCount,
                int offset = -1) override;

            bool AppendToPlaylistWithExternalIds(
                const int64_t playlistId,
                const char** externalIds,
                size_t externalIdCount,
                int offset = -1) override;

            bool AppendToPlaylistWithTrackList(
                const int64_t playlistId,
                musik::core::sdk::ITrackList* trackList,
                int offset = -1) override;

            size_t RemoveTracksFromPlaylist(
                const int64_t playlistId,
                const char** externalIds,
                const int* sortOrders,
                int count) override;

            bool SendRawQuery(
                const char* query,
                musik::core::sdk::IAllocator& allocator,
                char** resultData,
                int* resultSize) override;

            void Release() noexcept override;

        private:
            musik::core::ILibraryPtr library;
    };

} } } }
