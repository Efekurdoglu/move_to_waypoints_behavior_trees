#include "../include/system_status.hpp"

System_status::System_status()
{
    std::cout << "System Maintain Initialized " << std::endl;
}

BT::NodeStatus System_status::check_battery()
{
    std::cout << "Battery OK " << std::endl;
    return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus System_status::ask_for_help()
{
  std::cout << "System has been failed!" << std::endl;
  return BT::NodeStatus::FAILURE;
}
