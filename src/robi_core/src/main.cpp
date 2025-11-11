#include <chrono>
#include <rclcpp/rclcpp.hpp>
using namespace std::chrono_literals;

class Heartbeat : public rclcpp::Node {
public:
  Heartbeat() : Node("robi_heartbeat") {
    timer_ = this->create_wall_timer(1s, [this]{
      RCLCPP_INFO(this->get_logger(), "robi_heartbeat alive");
    });
  }
private:
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv){
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Heartbeat>());
  rclcpp::shutdown();
  return 0;
}
