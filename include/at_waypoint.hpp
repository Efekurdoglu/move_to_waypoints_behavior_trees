#ifndef __REACHED_HPP
#define __REACHED_HPP

#include <iostream>
#include <string>
#include "behaviortree_cpp_v3/action_node.h"
#include "behaviortree_cpp_v3/bt_factory.h"

class reach
{
public:
    reach();
    static BT::NodeStatus reached();
    static BT::NodeStatus not_reached();

private:
    bool _reached;
    static BT::NodeStatus success;
    BT::NodeStatus fail;
};

#endif