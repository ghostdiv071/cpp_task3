#include "UI.h"

UI::UI() {
    intGraph = new Graph<int>();
    strGraph = new Graph<std::string>();
}

UI::~UI() = default;

void UI::showMenu() {
    int key = 1;
    while (key) {
        cout <<
             "Choose the operation:\n"
             "1 - add node to int graph\n"
             "2 - delete node from int graph\n"
             "3 - add edge between nodes in int graph\n"
             "4 - delete edge from int graph\n"
             "5 - add node to string graph\n"
             "6 - delete node from string graph\n"
             "7 - add edge between nodes in string graph\n"
             "8 - delete edge from string graph\n"
             "9 - Depth-first search in one of graphs\n"
             "10 - Pass by iterator\n"
             "11 - exit the program\n";
        cin >> key;
        try {
            switch (key) {
                case 1:
                    addIntNode();
                    break;
                case 2:
                    deleteIntNode();
                    break;
                case 3:
                    addIntEdge();
                    break;
                case 4:
                    deleteIntEdge();
                    break;
                case 5:
                    addStrNode();
                    break;
                case 6:
                    deleteSrtNode();
                    break;
                case 7:
                    addStrEdge();
                    break;
                case 8:
                    deleteStrEdge();
                    break;
                case 9:
                    dfs();
                    break;
                case 10:
                    passGraph();
                    break;
                case 11:
                    exit(0);
                default:
                    cout << "Wrong symbol, try again\n";
            }
        } catch (const char *c) {
            cout << c;
        }
    }
}


void UI::addIntNode() {
    int value = enterInt("Enter node value\n");
    intGraph->addNode(value);
}

void UI::deleteIntNode() {
    int id = enterInt("Enter id of node you want to delete\n");
    if (checkId(id)) {
        intGraph->removeNode(id);
    } else cout << "No such node\n";
}

void UI::addIntEdge() {
    int from = enterInt("Enter first node id\n");
    int to = enterInt("Enter second node id\n");
    if (checkId(from) && checkId(to)) {
        intGraph->addEdge(from, to);
    } else cout << "No such node\n";
}

void UI::deleteIntEdge() {
    int from = enterInt("Enter first node id\n");
    int to = enterInt("Enter second node id\n");
    if (checkId(from) && checkId(to)) {
        intGraph->removeEdge(from, to);
    } else cout << "No such node\n";
}

void UI::addStrNode() {
    string value;
    cout << "Enter node value\n";
    cin >> value;
    strGraph->addNode(value);
}

void UI::deleteSrtNode() {
    int id = enterInt("Enter id of node you want to delete\n");
    if (checkId(id)) {
        strGraph->removeNode(id);
    } else cout << "No such node\n";
}

void UI::addStrEdge() {
    int from = enterInt("Enter first node id\n");
    int to = enterInt("Enter second node id\n");
    if (checkId(from) && checkId(to)) {
        strGraph->addEdge(from, to);
    } else cout << "No such node\n";
}

void UI::deleteStrEdge() {
    int from = enterInt("Enter first node id\n");
    int to = enterInt("Enter second node id\n");
    if (checkId(from) && checkId(to)) {
        strGraph->removeEdge(from, to);
    } else cout << "No such node\n";
}

char UI::chooseGraphForDFS() {
    char key;
    cout << "Choose graph: 1 - int graph, 2 - string graph\n";
    cin >> key;
    while (key != '1' && key != '2') {
        cout << "Wrong symbol, try again\n";
        cin >> key;
    }
    return key;
}

void UI::dfs() {
    char key = chooseGraphForDFS();
    if (key == '1') {
        intGraph->depthSearch();
    } else strGraph->depthSearch();
}

void UI::passGraph() {
    char key = chooseGraphForDFS();
    if (key == '1') {
        intGraph->itrBypass();
    } else strGraph->itrBypass();
}

int UI::enterInt(const std::string &msg) {
    do {
        int value;
        cout << msg;
        cin >> value;
        bool check = cin.good();
        if (check) {
            return value;

        } else {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    } while (true);
}

bool UI::checkId(int id) {
    return std::find(intGraph->getNodeIds().begin(),
                     intGraph->getNodeIds().end(), id) != intGraph->getNodeIds().end();
}

