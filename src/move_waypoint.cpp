#include "../include/move_waypoint.hpp"
#include "behaviortree_cpp_v3/action_node.h"
#include "behaviortree_cpp_v3/bt_factory.h"

move_waypoint::move_waypoint(const std::string &name) : BT::SyncActionNode(name, {})
{

}

BT::NodeStatus move_waypoint::tick()
{
    std::cout << "Moving to waypoint: " << this->name() << std::endl;
    std::this_thread::sleep_for(1s);
    success = BT::NodeStatus::SUCCESS;
    fail = BT::NodeStatus::FAILURE;
    
    return success;
}