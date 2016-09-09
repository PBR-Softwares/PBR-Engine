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
#include    <glm/glm.hpp>

#include    "PBR/Core/Configuration.hpp"
#include    "PBR/Core/Entity.hpp"
#include    "PBR/Core/Scene.hpp"

namespace   PBR
{
    namespace   Core
    {
        ///
        /// \brief This class is used to store information about a basic camera in a 3D world.
        ///
        /// It is not a concrete implementation for a camera.
        ///
        class PBR_CORE_EXPORTS Camera : public Entity
        {
            public:
                ///
                /// \brief This struct is used to store the clipping plane of the camera.
                ///
                struct  ClippingPlane
                {
                    ///
                    /// \brief Distance of the near clipping plane from the camera.
                    ///
#undef  near // Windows compilation, windows...
                    float   near;

                    ///
                    /// \brief Distance of the far clipping plane from the camera.
                    ///
#undef  far // Windows compilation, windows...
                    float   far;
                };

                class Projection
                {
                    public:

                        Projection(void);
                        virtual ~Projection(void);

                    public:
                        virtual const glm::mat4     projection_matrix(void) const = 0;


                    private:
                        ///
                        /// \brief Screen aspect ratio.
                        ///
                        float   m_aspect;

                        ///
                        /// \brief The field of view angle for the horizontal axis in radian.
                        ///
                        float   m_fov;
                };

            public:
                ///
                /// \brief Default constructor
                ///
                Camera(Scene::Node *node);

                ///
                /// \brief Copy constructor.
                ///
                Camera(const Camera &other) = default;

                ///
                /// \brief Move constructor.
                ///
                Camera(Camera &&other) noexcept = default;

                ///
                /// \brief Destructor.
                ///
                virtual ~Camera(void) noexcept;

            public:
                ///
                /// \brief Copy assigment operator.
                ///
                Camera  &operator=(const Camera &other) = default;

                ///
                /// \brief Move assigment operator.
                ///
                Camera  &operator=(Camera &&other) noexcept = default;

            public:

                const Projection    &projection(void) const;
                const glm::mat4     &view_matrix(void) const;

            protected:
                ///
                /// \brief the clipping plane for the camera.
                ///
                ClippingPlane   m_clippingPlane;
        };
    }
}
