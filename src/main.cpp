#include "../include/move_waypoint.hpp"
#include "../include/at_waypoint.hpp"
#include "../include/file.hpp"
#include "../include/system_status.hpp"
int main()
{
    file actual;
    auto actual_json = actual.json("../json/office.json");

    // Now the actual_json will have the json data
    std::cout << "Total json data: " << std::endl << actual_json << std::endl;
    // std::cout << "Name: " << actual_json[0]["Name"] << std::endl;
    // std::cout << "Position_X: " << actual_json[0]["Position_X"] << std::endl;
    // std::cout << "Position_Y: " << actual_json[0]["Position_Y"] << std::endl;
    // std::cout << "Yaw: " << actual_json[0]["Yaw"] << std::endl;

    for(int i = 0; i < 4; i++)  
    {
        auto str = std::to_string(i);
        BT::BehaviorTreeFactory factory;

        move_waypoint agent(str);

        factory.registerNodeType<move_waypoint>("move_waypoint");
        factory.registerSimpleCondition("not_reached", std::bind(reach::not_reached));
        factory.registerSimpleCondition("reached", std::bind(reach::reached));

        factory.registerSimpleCondition("ask_for_help", std::bind(System_status::ask_for_help));

        factory.registerSimpleAction("reach", std::bind(&move_waypoint::tick, &agent));

        auto tree = factory.createTreeFromFile("./../xml/waypoints_tree.xml");

        tree.tickRoot();
    }
    return 0;
}
