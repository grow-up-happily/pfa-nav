#ifndef HERO_BASE_POSE_TOOL_H
#define HERO_BASE_POSE_TOOL_H

#ifndef Q_MOC_RUN
    #include <QObject>
    #include <geometry_msgs/msg/pose_stamped.hpp>
    #include <rclcpp/rclcpp.hpp>
    #include <rviz_common/display_context.hpp>
    #include <rviz_common/properties/string_property.hpp>
    #include <rviz_common/tool.hpp>
    #include <rviz_default_plugins/tools/pose/pose_tool.hpp>
    #include <rviz_default_plugins/visibility_control.hpp>
#endif

namespace wp_map_tools
{
    class RVIZ_DEFAULT_PLUGINS_PUBLIC HeroBasePoseTool
        : public rviz_default_plugins::tools::PoseTool
    {
        Q_OBJECT

    public:
        HeroBasePoseTool();
        ~HeroBasePoseTool() override;

        void onInitialize() override;

    protected:
        void onPoseSet(double x, double y, double theta) override;

    private Q_SLOTS:
        void updateTopic();

    private:
        rclcpp::Node::SharedPtr raw_node_;
        rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pub_;
        rviz_common::properties::StringProperty* topic_property_;
    };
}

#endif
