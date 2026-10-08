#ifndef ERROR_METRICS
#define ERROR_METRICS

#include <rclcpp/rclcpp.hpp>
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include <Eigen/Dense>

/**
 * Example of computing error metrics between two frames
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
     * Looks up the transformation between the marker_a frame and the marker_b frame
     * and prints out the error metrics between the two frames
     */
    void printMetrics();
    
private:
    /**
     * Finds the rotation error between two quaternions
     * @param a The first quaternion
     * @param b The second quaternion
     * @return The angle between the quaternions in radians
     */
    double findRotationError(Eigen::Quaterniond & a, Eigen::Quaterniond & b);

    /**
     * Finds the translation error between two points
     * @param a The first point location 
     * @param b The second point location
     * @return The distance between the points in meters 
     */
    double findTranslationError(Eigen::Vector3d & a, Eigen::Vector3d & b);

    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
    std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
};


#endif // ERROR_METRICS