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

#include    "PBR/Core/Configuration.hpp"
#include    "PBR/Core/Library.hpp"
#include    "PBR/Core/Material.hpp"
#include    "PBR/Core/TextureLibrary.hpp"

namespace   PBR
{
    namespace   Core
    {
        ///
        /// \brief This material library wrap the Library<Material> and provide a constructor from assimp materials.
        ///
        class PBR_CORE_EXPORTS MaterialLibrary : public Library<unsigned int, Material *>
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                MaterialLibrary(void);

                ///
                /// \brief Copy constructor.
                ///
                MaterialLibrary(const MaterialLibrary &other);

                ///
                /// \brief Move constructor.
                ///
                MaterialLibrary(MaterialLibrary &&other) noexcept = default;

                ///
                /// \brief Destructor.
                ///
                virtual ~MaterialLibrary(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                MaterialLibrary     &operator=(const MaterialLibrary &other);

                ///
                /// \brief Move assignment operator.
                ///
                MaterialLibrary     &operator=(MaterialLibrary &&other) noexcept = default;

        };
    }
}
