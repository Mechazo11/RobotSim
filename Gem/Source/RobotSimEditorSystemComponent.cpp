
#include <AzCore/Serialization/SerializeContext.h>
#include "RobotSimEditorSystemComponent.h"

namespace RobotSim
{
    void RobotSimEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<RobotSimEditorSystemComponent, RobotSimSystemComponent>()
                ->Version(0);
        }
    }

    RobotSimEditorSystemComponent::RobotSimEditorSystemComponent() = default;

    RobotSimEditorSystemComponent::~RobotSimEditorSystemComponent() = default;

    void RobotSimEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("RobotSimEditorService"));
    }

    void RobotSimEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("RobotSimEditorService"));
    }

    void RobotSimEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void RobotSimEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void RobotSimEditorSystemComponent::Activate()
    {
        RobotSimSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void RobotSimEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        RobotSimSystemComponent::Deactivate();
    }

} // namespace RobotSim
