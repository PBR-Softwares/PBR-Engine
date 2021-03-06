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

#include    "PBR/Core/Configuration.hpp"
#include    "PBR/Core/Entity.hpp"

namespace   PBR
{
    namespace   Core
    {
        ///
        /// \brief This class is used to represent a light in the 3d world.
        ///
        class PBR_CORE_EXPORTS Light : public Entity
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                Light(Scene::Node *node);

                ///
                /// \brief Copy constructor.
                ///
                Light(const Light &other) = default;

                ///
                /// \brief Move constructor.
                ///
                Light(Light &&other) noexcept = default;

                ///
                /// \brief Destructor.
                ///
                virtual ~Light(void) noexcept;

            public:
                ///
                /// \brief Copy assigment operator.
                ///
                Light   &operator=(const Light &other) = default;

                ///
                /// \brief Move assigment operator.
                ///
                Light   &operator=(Light &&other) noexcept = default;

            public:
                ///
                /// \brief This method clone the light.
                ///
                virtual Light   *clone(void) const override;
        };
    }
}
