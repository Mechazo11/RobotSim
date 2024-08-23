/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/Component/Component.h>

#include <RobotSim/RobotSimBus.h>

namespace RobotSim
{
    class RobotSimSystemComponent
        : public AZ::Component
        , protected RobotSimRequestBus::Handler
    {
    public:
        AZ_COMPONENT(RobotSimSystemComponent, "{2EAF0750-8687-44D9-91BF-E010A24436B8}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        RobotSimSystemComponent();
        ~RobotSimSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // RobotSimRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
