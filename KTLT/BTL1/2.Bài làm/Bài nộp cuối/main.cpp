#include "knight.h"

int main(int argc, char ** argv) {
    string file_input(argv[1]);

    int HP, level, remedy, maidenkiss, phoenixdown, rescue = -1;
    /*fstream ifs(file_input);
    ifs >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
    ifs.close();*/
    adventureToKoopa(file_input, HP, level, remedy, maidenkiss, phoenixdown, rescue);

    return 0;
}