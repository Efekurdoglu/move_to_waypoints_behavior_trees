#include "../include/at_waypoint.hpp"

reach::reach() : _reached(true)
{
    
}

BT::NodeStatus reach::reached()
{
    
    std::cout << "The waypoint has been reached." << std::endl << std::endl;
    auto success = BT::NodeStatus::SUCCESS;
    return success;
}

BT::NodeStatus reach::not_reached()
{
    
    std::cout << "Waypoint has not been reached yet." << std::endl;
    auto success = BT::NodeStatus::SUCCESS;
    auto fail = BT::NodeStatus::FAILURE;
    return fail;
}