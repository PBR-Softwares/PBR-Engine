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

#include    <map>
#include    <list>
#include    <functional>

#include    "PBR/Core/Configuration.hpp"
#include    "PBR/Core/Event.hpp"

namespace   PBR
{
    namespace   Core
    {
        ///
        /// \brief TODO
        ///
        class PBR_CORE_EXPORTS EventRegister
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                EventRegister(void);

                ///
                /// \brief Destructor.
                ///
                ~EventRegister(void);

            public:

                ///
                /// \brief Push an event in the event register, this function will
                /// spread the event in the registered callback.
                ///
                void    push_event(const Event &event);

                ///
                /// \brief Register a callback to a particular event type.
                ///
                /// TODO add predicate.
                ///
                void    register_callback(const Event::Type &type, const std::function<void(const Event &)> &callback);

            protected:
                ///
                /// \brief Temporary container.
                ///
                std::map<const Event::Type, std::list<std::function<void(const Event &)>>>  m_temporary;
        };
    }
}
