
#include <RobotSimModuleInterface.h>
#include "RobotSimEditorSystemComponent.h"

#include "RobotSimSampleComponent.h"
namespace RobotSim
{
    class RobotSimEditorModule
        : public RobotSimModuleInterface
    {
    public:
        AZ_RTTI(RobotSimEditorModule, "{06EDB404-86B9-43F0-8F38-4DF6B73A6584}", RobotSimModuleInterface);
        AZ_CLASS_ALLOCATOR(RobotSimEditorModule, AZ::SystemAllocator, 0);

        RobotSimEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                RobotSimEditorSystemComponent::CreateDescriptor(),
                RobotSimSampleComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<RobotSimEditorSystemComponent>(),
            };
        }
    };
}// namespace RobotSim

AZ_DECLARE_MODULE_CLASS(Gem_RobotSim, RobotSim::RobotSimEditorModule)
