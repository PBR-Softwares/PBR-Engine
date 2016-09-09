//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2016 PBR-Softwares (contact@pbr-softwares.com)
//

#pragma once

#include    <string>
#include    <map>

#include    "PBR/Core/Configuration.hpp"
#include    "PBR/Core/Library.hpp"
#include    "PBR/Core/Texture.hpp"

namespace   PBR
{
    namespace   Core
    {
        ///
        /// \brief A texture library
        ///
        class PBR_CORE_EXPORTS TextureLibrary : public Library<std::string, Texture *>
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                TextureLibrary(void);

                ///
                /// \brief Copy constructor.
                ///
                TextureLibrary(const TextureLibrary &other);

                ///
                /// \brief Move constructor.
                ///
                TextureLibrary(TextureLibrary &&other) noexcept;

                ///
                /// \brief Destructor.
                ///
                virtual ~TextureLibrary(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                TextureLibrary &operator=(const TextureLibrary &other);

                ///
                /// \brief Move assignment operator.
                ///
                TextureLibrary &operator=(TextureLibrary &&other) noexcept;

        };
    }
}
