/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace RobotSim
{
    class RobotSimRequests
    {
    public:
        AZ_RTTI(RobotSimRequests, "{A102CAF5-D356-484D-AD4E-3B0123D68B1A}");
        virtual ~RobotSimRequests() = default;
        // Put your public methods here
    };

    class RobotSimBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using RobotSimRequestBus = AZ::EBus<RobotSimRequests, RobotSimBusTraits>;
    using RobotSimInterface = AZ::Interface<RobotSimRequests>;

} // namespace RobotSim
