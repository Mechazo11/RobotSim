
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "RobotSimSystemComponent.h"
#include "RobotSimSampleComponent.h"

namespace RobotSim
{
    class RobotSimModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(RobotSimModule, "{06EDB404-86B9-43F0-8F38-4DF6B73A6584}", AZ::Module);
        AZ_CLASS_ALLOCATOR(RobotSimModule, AZ::SystemAllocator);

        RobotSimModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                RobotSimSystemComponent::CreateDescriptor(),
                RobotSimSampleComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<RobotSimSystemComponent>(),
            };
        }
    };
}// namespace RobotSim

AZ_DECLARE_MODULE_CLASS(Gem_RobotSim, RobotSim::RobotSimModule)
