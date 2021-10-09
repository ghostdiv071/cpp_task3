#include "UI.h"

UI::UI() {
    intGraph = new Graph<int>();
    strGraph = new Graph<std::string>();
}

UI::~UI() = default;

void UI::showMenu() {
//    int key = 1;
//    while (key) {
//        cout <<
//             "Choose the operation:\n"
//             "1 - add node to int graph\n"
//             "2 - delete node from int graph\n"
//             "3 - add edge between nodes in int graph\n"
//             "4 - delete edge from int graph\n"
//             "5 - add node to string graph\n"
//             "6 - delete node from string graph\n"
//             "7 - add edge between nodes in string graph\n"
//             "8 - delete edge from string graph\n"
//             "9 - Depth-first search in one of graphs\n"
//             "10 - exit the program\n";
//        cin >> key;
//        try {
//            switch (key) {
//                case 1:
//                    addIntNode();
//                    break;
//                case 2:
//                    deleteIntNode();
//                    break;
//                case 3:
//                    addIntEdge();
//                    break;
//                case 4:
//                    deleteIntEdge();
//                    break;
//                case 5:
//                    addStrNode();
//                    break;
//                case 6:
//                    deleteSrtNode();
//                    break;
//                case 7:
//                    addStrEdge();
//                    break;
//                case 8:
//                    deleteStrEdge();
//                    break;
//                case 9:
//                    chooseGraphForDFS();
//                    break;
//                case 10:
//                    exit(0);
//                default:
//                    cout << "Wrong symbol, try again\n";
//            }
//        } catch (const char *c) {
//            cout << c;
//        }
//    }

//    addIntNode();
//    addIntNode();
//    addIntNode();
//    intGraph->test();
}


void UI::addIntNode() {
    int value;
    cout << "Enter node value\n";
    cin >> value;
    intGraph->addNode(value);
}

void UI::deleteIntNode() {
    int id;
    cout << "Enter id of node you want to delete\n";
    cin >> id;
    intGraph->removeNode(id);
}

void UI::addIntEdge() {
    int from, to;
    cout << "Enter first node id\n";
    cin >> from;
    cout << "Enter second node id\n";
    cin >> to;
    intGraph->addEdge(from, to);
}

void UI::deleteIntEdge() {
    int from, to;
    cout << "Enter first node id\n";
    cin >> from;
    cout << "Enter second node id\n";
    cin >> to;
    intGraph->removeEdge(from, to);
}

void UI::addStrNode() {
    string value;
    cout << "Enter node value\n";
    cin >> value;
    strGraph->addNode(value);
}

void UI::deleteSrtNode() {
    int id;
    cout << "Enter id of node you want to delete\n";
    cin >> id;
    strGraph->removeNode(id);
}

void UI::addStrEdge() {
    int from, to;
    cout << "Enter first node id\n";
    cin >> from;
    cout << "Enter second node id\n";
    cin >> to;
    strGraph->addEdge(from, to);
}

void UI::deleteStrEdge() {
    int from, to;
    cout << "Enter first node id\n";
    cin >> from;
    cout << "Enter second node id\n";
    cin >> to;
    strGraph->removeEdge(from, to);
}

void UI::chooseGraphForDFS() {
    char key;
    cout << "Choose graph: 1 - int graph, 2 - string graph\n";
    cin >> key;
    key = '1';
    while (key != '1' && key != '2') {
        cout << "Wrong symbol, try again\n";
        cin >> key;
    }
    if (key == '1')
        dfs(intGraph);
    else dfs(strGraph);

}

template<typename T>
void UI::dfs(Graph<T> *graph) {
    graph->depthSearch();
}
