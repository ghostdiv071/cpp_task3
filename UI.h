#include <string>
#include "Graph.h"

#ifndef TASK3_UI_H
#define TASK3_UI_H

class UI {
private:
    Graph<int> *intGraph;
    Graph<std::string> *strGraph;

public:
    UI();

    ~UI();

    void showMenu();

    void addIntNode();

    void deleteIntNode();

    void addIntEdge();

    void deleteIntEdge();

    void addStrNode();

    void deleteSrtNode();

    void addStrEdge();

    void deleteStrEdge();

    void dfs();

    void passGraph();

    static char chooseGraphForDFS();

};

#endif
