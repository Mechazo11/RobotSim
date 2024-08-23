#pragma once

#include <AzCore/std/containers/vector.h>
#include <AzCore/Component/Component.h>
#include <AzCore/Component/EntityId.h>
#include <ImGuiBus.h>

#include <ROS2/ROS2Bus.h>
#include <ROS2/Utilities/ROS2Names.h>
#include <ROS2/Communication/TopicConfiguration.h>

#include <rclcpp/publisher.hpp>

#include <geometry_msgs/msg/pose_stamped.hpp>

namespace RobotSim
{

    class RobotSimSampleComponent
        : public AZ::Component
        , public ImGui::ImGuiUpdateListenerBus::Handler
    {
    public:
        AZ_COMPONENT(RobotSimSampleComponent, "{108711B5-3A8B-4BB6-9F3B-65B7A60EE4EB}", AZ::Component);
        RobotSimSampleComponent();
        ~RobotSimSampleComponent() = default;
        void Activate() override;
        void Deactivate() override;
        static void Reflect(AZ::ReflectContext* context);

    private:
        void OnImGuiUpdate() override;

        AZStd::vector<AZ::EntityId> m_goalEntities;
        std::shared_ptr<rclcpp::Publisher<geometry_msgs::msg::PoseStamped>> m_goalPublisher;
        geometry_msgs::msg::PoseStamped m_goalMessage;
        ROS2::TopicConfiguration m_goalTopicConfiguration;
    };
} // namespace RobotSim
