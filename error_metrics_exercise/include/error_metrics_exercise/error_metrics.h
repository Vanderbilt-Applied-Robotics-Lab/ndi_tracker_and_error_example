#ifndef ERROR_METRICS
#define ERROR_METRICS

#include <rclcpp/rclcpp.hpp>
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include <Eigen/Geometry>

/**
 * Example of using tf2 to look up a transform
 */
class ErrorMetrics : public rclcpp::Node
{
public:
    /**
     * Main constructor
     */
    ErrorMetrics();

    /**
     * Destructor
     */
    ~ErrorMetrics() = default;

    /**
     * Looks up the transformation between the ee frame and the base frame
     * and prints out the value
     */
    void computeMetrics();
    
private:

    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
    std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
};

#endif // ERROR_METRICS