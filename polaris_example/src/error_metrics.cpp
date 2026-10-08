#include <polaris_example/error_metrics.h>

ErrorMetrics::ErrorMetrics() : Node("error_metrics")
{
    tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
}

void ErrorMetrics::computeMetrics()
{
    try
    {
        geometry_msgs::msg::TransformStamped transform = tf_buffer_->lookupTransform("marker_a", "marker_b", tf2::TimePointZero);
        Eigen::Quaterniond rotation = Eigen::Quaterniond(transform.transform.rotation.w, transform.transform.rotation.x, transform.transform.rotation.y, transform.transform.rotation.z);
        Eigen::Vector3d translation = Eigen::Vector3d(transform.transform.translation.x, transform.transform.translation.y, transform.transform.translation.z);

        // convert to axis-angle
        Eigen::AngleAxisd ax_ang = Eigen::AngleAxisd(rotation);

        RCLCPP_INFO(this->get_logger(), "Distance: %0.2f m", translation.norm());
        RCLCPP_INFO(this->get_logger(), "Angular distance: %0.2f deg", ax_ang.angle()*180.0/M_PI);
    }
    catch (const tf2::TransformException & ex)
    {
        RCLCPP_ERROR(this->get_logger(), "lookup failed!");
    }
}

int main(int argc, char** argv)
{
    // initialize the node
    rclcpp::init(argc, argv);
    
    // create instance of class
    auto node = std::make_shared<ErrorMetrics>();
    
    // Set loop rate
    rclcpp::Rate rate = rclcpp::Rate(1); // Hz

    while (rclcpp::ok())
    {
        node->computeMetrics();
        rclcpp::spin_some(node);
        rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}