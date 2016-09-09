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

namespace   PBR
{
    namespace   Core
    {
        ///
        /// \brief This class is an abstract base class for an event.
        ///
        class PBR_CORE_EXPORTS Event
        {

            public:
                ///
                /// \brief existing event type
                ///
                enum    Type
                {
                    KEY_PRESSED, // \brief TODO
                    KEY_RELEASED,
                    MOUSE_BUTTON_PRESSED,
                    MOUSE_BUTTON_RELEASED,
                    MOUSE_MOVE,
                    RESIZE
                };

            protected:
                ///
                /// \brief Default Constructor can be only constructed from child class.
                ///
                Event(const Type &event_type);

            public:
                ///
                /// \brief Copy constructor.
                ///
                Event(const Event &other);

                ///
                /// \brief Move constructor.
                ///
                Event(Event &&other) noexcept;

                ///
                /// \brief Destructor.
                ///
                virtual ~Event(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Event   &operator=(const Event &other);

                ///
                /// \brief Move assignment operator.
                ///
                Event   &operator=(Event &&other) noexcept;

            public:
                ///
                /// \brief This method is used to know if the event have been used.
                ///
                bool    is_consumed(void) const;

                ///
                /// \brief This method consume the event.
                ///
                void    consume(void);

            public:
                ///
                /// \brief get the type of the event.
                ///
                const Type  &type(void) const;

            private:
                ///
                /// \brief This attribute contains the state of the event. consumed or not consumed.
                ///
                bool    m_consumed;

                ///
                /// \brief The type of the event.
                ///
                Type    m_type;
        };
    }
}
