

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "RobotSimSystemComponent.h"

namespace RobotSim
{
    void RobotSimSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<RobotSimSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<RobotSimSystemComponent>("RobotSim", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void RobotSimSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("RobotSimService"));
    }

    void RobotSimSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("RobotSimService"));
    }

    void RobotSimSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void RobotSimSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    RobotSimSystemComponent::RobotSimSystemComponent()
    {
        if (RobotSimInterface::Get() == nullptr)
        {
            RobotSimInterface::Register(this);
        }
    }

    RobotSimSystemComponent::~RobotSimSystemComponent()
    {
        if (RobotSimInterface::Get() == this)
        {
            RobotSimInterface::Unregister(this);
        }
    }

    void RobotSimSystemComponent::Init()
    {
    }

    void RobotSimSystemComponent::Activate()
    {
        RobotSimRequestBus::Handler::BusConnect();
    }

    void RobotSimSystemComponent::Deactivate()
    {
        RobotSimRequestBus::Handler::BusDisconnect();
    }
}
