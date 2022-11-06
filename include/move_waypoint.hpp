#ifndef __MOVE_WAYPOINT_HPP
#define __MOVE_WAYPOINT_HPP

#include <iostream>
#include <chrono>
#include "behaviortree_cpp_v3/action_node.h"
#include "behaviortree_cpp_v3/bt_factory.h"

using namespace std::chrono_literals;

class move_waypoint : public BT::SyncActionNode
{
public:
    explicit move_waypoint(const std::string &point);
    BT::NodeStatus tick() override;
private:
    BT::NodeStatus success;
    BT::NodeStatus fail;
};

#endif