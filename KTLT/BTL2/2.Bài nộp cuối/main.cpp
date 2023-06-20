#include "knight2.h"

int main(int argc, char ** argv) {
    string file_armyknights, file_events;
    if (argc == 1) {
        file_armyknights = "tc1_armyknights"; // hard-code
        file_events = "tc1_events";
    }
    else if (argc == 3) {
        file_armyknights = argv[1];
        file_events = argv[2];
    }
    else {
        cout << "Error number of arguments" << endl;
        exit(1);
    }
    
    // BEBGIN
    // INITIAL CODE
    KnightAdventure * knightAdventure = new KnightAdventure();
    knightAdventure->loadArmyKnights(file_armyknights);
    knightAdventure->loadEvents(file_events);
    knightAdventure->run();
    delete knightAdventure;

    // END INITIAL CODE
    // Events test = Events(file_events);
    // cout << "So luong event trong file la: " << test.count() << endl;
    // for (int i = 0; i < test.count(); i++) {
    //     cout << "Event code thứ tự " << i+1 << " là: " << test.get_event_index_i(i) << endl;
    // }

    // ArmyKnights test1 = ArmyKnights(file_armyknights);
    // cout << "--------------------" << endl;
    // cout << "So luong knight la: " << test1.get_Num_Army() << endl;
    // BaseKnight* knight = nullptr;
    // for (int i = 0; i < test1.get_Num_Army(); i++) {
    //     knight = test1.get_pointer_knight(i);
    //     cout << "Knight thứ tự " << i+1 << " là: " << endl;
    //     cout << "Knight id: " << knight->get_id() << endl;
    //     cout << "Knight HP: " << knight->get_hp() << endl;
    //     cout << "Knight maxHP: " << knight->get_maxhp() << endl;
    //     cout << "Knight type: " << knight->getKnightType() << endl;
    //     cout << "Knight level: " << knight->get_level() << endl;
    //     cout << "Knight gil: " << knight->get_gil() << endl;
    //     cout << "Knight antidote: " << knight->get_antidote() << endl;
    //     cout << "Knight phoenixdown1: " << knight->get_phoenixdownI() << endl;
    //     cout << "Knight bag: " << knight->getBag()->toString() << endl;
    //     cout << "--------------------------------" << endl;
    // } 
    

    return 0;
}