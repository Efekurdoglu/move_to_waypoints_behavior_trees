#ifndef __SYSTEM_STATUS_HPP
#define __SYSTEM_STATUS_HPP

#include <iostream>
#include <string>
#include "behaviortree_cpp_v3/action_node.h"
#include "behaviortree_cpp_v3/bt_factory.h"

class system_status
{
public:
    system_status();
    static BT::NodeStatus check_battery();
    static BT::NodeStatus ask_for_help();
};


#endif