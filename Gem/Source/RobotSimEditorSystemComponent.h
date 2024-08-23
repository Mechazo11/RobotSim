
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <RobotSimSystemComponent.h>

namespace RobotSim
{
    /// System component for RobotSim editor
    class RobotSimEditorSystemComponent
        : public RobotSimSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = RobotSimSystemComponent;
    public:
        AZ_COMPONENT(RobotSimEditorSystemComponent, "{FA83AFD0-1C6F-4F17-BBF6-9C670F1127E9}", BaseSystemComponent);
        static void Reflect(AZ::ReflectContext* context);

        RobotSimEditorSystemComponent();
        ~RobotSimEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace RobotSim
