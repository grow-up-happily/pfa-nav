#include <chrono>
#include <string>
#include <memory>
#include <cstdlib>
#include <cstring>
#include "rclcpp/rclcpp.hpp"
#include "wp_map_tools/srv/save_waypoints.hpp"

namespace
{
std::string defaultWaypointPath(const std::string& filename)
{
    const char* home = getenv("HOME");
    std::string path = home != nullptr ? home : "";
    path += "/sight_test/pfa-nav/";
    path += filename;
    return path;
}
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("wp_saver");

    auto client = node->create_client<wp_map_tools::srv::SaveWaypoints>("waterplus/save_waypoints");

    std::string strSaveFile = defaultWaypointPath("waypoints.yaml");
    std::string color;

    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-f"))
        {
            if (++i < argc)
            {
                strSaveFile = argv[i];
            }
        }
        else if (!strcmp(argv[i], "--red"))
        {
            if (color == "blue")
            {
                RCLCPP_ERROR(node->get_logger(), "--red and --blue cannot be used together");
                rclcpp::shutdown();
                return 1;
            }
            color = "red";
            strSaveFile = defaultWaypointPath("waypoints_red.yaml");
        }
        else if (!strcmp(argv[i], "--blue"))
        {
            if (color == "red")
            {
                RCLCPP_ERROR(node->get_logger(), "--red and --blue cannot be used together");
                rclcpp::shutdown();
                return 1;
            }
            color = "blue";
            strSaveFile = defaultWaypointPath("waypoints_blue.yaml");
        }
    }

    auto request = std::make_shared<wp_map_tools::srv::SaveWaypoints::Request>();
    request->filename = strSaveFile;

    while (!client->wait_for_service(std::chrono::seconds(1)))
    {
        if (!rclcpp::ok())
        {
            RCLCPP_ERROR(node->get_logger(), "Interrupted while waiting for the service. Exiting...");
            return 1;
        }
        RCLCPP_INFO(node->get_logger(), "Service not available, waiting...");
    }

    auto result = client->async_send_request(request);
    if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_INFO(node->get_logger(), "Save waypoints to the file: %s", request->filename.c_str());
    }
    else
    {
        RCLCPP_ERROR(node->get_logger(), "Failed to call service save_waypoints");
    }

    rclcpp::shutdown();
    return 0;
}
