#include <error_metrics_example/error_metrics.h>

ErrorMetrics::ErrorMetrics() : Node("error_metrics")
{
    tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
}

void ErrorMetrics::printMetrics()
{
    try
    {
        geometry_msgs::msg::TransformStamped transform = tf_buffer_->lookupTransform("marker_a", "marker_b", tf2::TimePointZero);
        Eigen::Q
        RCLCPP_INFO(this->get_logger(), "Error")
    }
    catch (const tf2::TransformException & ex)
    {
        RCLCPP_ERROR(this->get_logger(), "lookup failed! Reason: %s", ex.what());
    }
}

int main(int argc, char** argv)
{
    // initialize the node
    rclcpp::init(argc, argv);
    
    // create instance of class
    auto node = std::make_shared<TransformExample>();
    
    // Set loop rate
    rclcpp::Rate rate = rclcpp::Rate(10); // Hz

    while (rclcpp::ok())
    {
        node->printEEFrame();
        rclcpp::spin_some(node);
        rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}