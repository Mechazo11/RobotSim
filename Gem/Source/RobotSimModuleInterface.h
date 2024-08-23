
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>
#include <RobotSimSystemComponent.h>

namespace RobotSim
{
    class RobotSimModuleInterface
        : public AZ::Module
    {
    public:
        AZ_RTTI(RobotSimModuleInterface, "{B033924E-95AF-4BE8-9EC7-82A4DAEA1058}", AZ::Module);
        AZ_CLASS_ALLOCATOR(RobotSimModuleInterface, AZ::SystemAllocator, 0);

        RobotSimModuleInterface()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                RobotSimSystemComponent::CreateDescriptor(),
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
