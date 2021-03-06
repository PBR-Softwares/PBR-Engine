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

namespace   PBR
{
    namespace   Core
    {
        ///
        /// \brief A texture class that can be used to store the information of a texture.
        ///
        class PBR_CORE_EXPORTS Texture
        {
            public:
                ///
                /// \brief Default constructor. create an empty texture.
                ///
                Texture(void);

                ///
                /// \brief Copy constructor.
                ///
                Texture(const Texture &other);

                ///
                /// \brief Move constructor.
                ///
                Texture(Texture &&other) noexcept;

                ///
                /// \brief Destructor.
                ///
                virtual ~Texture(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Texture &operator=(const Texture &other);

                ///
                /// \brief Move assignment operator.
                ///
                Texture &operator=(Texture &&other) noexcept;

            private:
                ///
                /// \brief This attribute is the name of the texture
                /// (its path is relative to the file loaded)
                ///
                std::string m_name;
        };
    }
}
