// Peoject Identifer: 40FB54C86566B9DDEAB902CC80E8CE85C1C62AAD

// EECS 281 Project 1

#include <getopt.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// STRUCTS AND SUCH -----------------------------------------
struct Coordinate {
    int row;
    int col;
    bool discovered;
    char terrain;
};

struct MapProperties {
    int dimensions;
    char inputMode;
    Coordinate start;
    Coordinate treasure;
};

// default values
struct Options {
    string captain = "stack";
    string firstMate = "queue";
    string huntOrder = "NESW";
    bool verbose = false;
    bool stats = false;
    char showPath = ' '; // M: map, L: list
};

// STRUCTS END -----------------------------------------

// COMMAND LINE PARSING -----------------------------------------
void printHelp(char *argv[]) {
    // TODO: make more meaningful
    cout << "Usage: " << argv[0] << "\n";
}

void getMode(int argc, char * argv[], Options &options) {
    int choice;
    int index = 0;

    struct option longOptions[] = {
        { "help",        no_argument,       nullptr, 'h' },
        { "captain",     required_argument, nullptr, 'c' },
        { "first-mate",  required_argument, nullptr, 'f' },
        { "hunt-order",  required_argument, nullptr, 'o' },
        { "verbose",     no_argument,       nullptr, 'v' },
        { "stats",       no_argument,       nullptr, 's' },
        { "show-path",   required_argument, nullptr, 'p' },
    };

    while ((choice = getopt_long(argc, argv, "hc:f:o:vsp:", longOptions, &index)) != -1) {

        switch(choice) {
            case 'h': 
                printHelp(argv);
                exit(0);
            case 'c':
                if (string(optarg) == "STACK" || string(optarg) == "QUEUE" ) {
                    options.captain = optarg;
                } else {
                    cerr << "Invalid argument to --captain" << "\n";
                    cerr << "  Invalid argument is: " << optarg << "\n";  
                    exit(1);
                }
                break;
            case 'f':
                if (string(optarg) == "STACK" || string(optarg) == "QUEUE" ) {
                    options.firstMate = optarg;
                } else {
                    cerr << "Invalid argument to --first-mate" << "\n"; 
                    cerr << "  Invalid argument is: " << optarg << "\n"; 
                    exit(1);
                }
                break;
            case 'o':
                if (string(optarg).length() == 4 && 
                    string(optarg).find('N') != string::npos && 
                    string(optarg).find('E') != string::npos && 
                    string(optarg).find('S') != string::npos && 
                    string(optarg).find('W') != string::npos) {
                    options.huntOrder = optarg;
                } else {
                    cerr << "Invalid argument to --hunt-order" << "\n";
                    cerr << "  Invalid argument is: " << optarg << "\n"; 
                    exit(1);
                }
                break;
            case 'v':
                options.verbose = true;
                break;
            case 's':
                options.stats = true;
                break;
            case 'p': {
                char out = *optarg;
                if (out == 'M' || out == 'L') {
                    options.showPath = out;
                } else {
                    cerr << "Invalid argument to --show-path" << "\n";
                    exit(1);
                }
                break;
            }
            default:
                cerr << "Invalid option. Use --help" << "\n";
                exit(1);

        } // switch()   
    } // while()
} //getMode()
// COMMAND LINE PARSING END -----------------------------------------

void fillMap(MapProperties *mapProps) {
    vector<vector<Coordinate>> map;
    map.resize(mapProps->dimensions);
    string line;
    
    if (mapProps->inputMode == 'M') {
        int row = 0;
        while (getline(cin, line)) {
            map[row].resize(mapProps->dimensions);
            for (int i = 0; i < line.length(); i++) {
                map[row][i].terrain = line[i];

                // check for start and treasure
                if (line[i] == '$') {
                    mapProps->treasure.row = row;
                    mapProps->treasure.col = i;
                } else if (line[i] == '@') {
                    mapProps->start.row = row;
                    mapProps->start.col = i;
                }

            } // for()
            row++;
        } // while()
    } else if (mapProps->inputMode == 'L') {
        for (int i = 0; i < mapProps->dimensions; i++) {
            map[i].resize(mapProps->dimensions);
        }

    }


} // fillMap()

void createMap() {
    MapProperties mapProps;
    string line;
    bool check = true;

    while (check) {
        getline(cin, line);
        if (line[0] == '#') {
            line = "";
            continue;
        } else if (line == "M") {
            check = false;
            mapProps.inputMode = 'M';
            cin >> mapProps.dimensions;
        } else { // input file is in list mode
            check = false;
            mapProps.inputMode = 'L';
            cin >> mapProps.dimensions;
        }
    } // while (check)
    fillMap(&mapProps);

} // createMap()



int main(int argc, char *argv[]) {
    Options options;

    getMode(argc, argv, options);

    vector<vector<Coordinate>> map;
    createMap();

    // Debug output to confirm parsed options
    cout << "Captain: " << options.captain << '\n';
    cout << "First Mate: " << options.firstMate << '\n';
    cout << "Hunt Order: " << options.huntOrder << '\n';
    cout << "Verbose: " << (options.verbose ? "true" : "false") << '\n';
    cout << "Stats: " << (options.stats ? "true" : "false") << '\n';
    cout << "Show Path: " << (options.showPath ? options.showPath : 'N') << '\n';

    return 0;
}; // main()