#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

// Structure for graph node
struct Node {

    char name;     // Node name
    int g;         // Actual cost
    int h;         // Heuristic value
    int f;         // Total cost

    // Constructor
    Node(char n, int gcost, int hcost) {

        name = n;
        g = gcost;
        h = hcost;

        // A* formula
        f = g + h;
    }
};

// Comparator for priority queue
struct Compare {

    bool operator()(Node a, Node b) {

        // Node with smaller f gets higher priority
        return a.f > b.f;
    }
};

int main() {

    // Priority queue for open list
    priority_queue<Node, vector<Node>, Compare> open;

    // Heuristic values
    map<char, int> heuristic;

    heuristic['A'] = 6;
    heuristic['B'] = 4;
    heuristic['C'] = 3;
    heuristic['D'] = 5;
    heuristic['E'] = 2;
    heuristic['F'] = 1;
    heuristic['G'] = 0;

    // Insert start node
    open.push(Node('A', 0, heuristic['A']));

    cout << "A* Traversal:\n\n";

    // Continue until queue becomes empty
    while(!open.empty()) {

        // Get node with smallest f value
        Node current = open.top();

        // Remove node
        open.pop();

        // Print node details
        cout << "Node: " << current.name;
        cout << "  g=" << current.g;
        cout << "  h=" << current.h;
        cout << "  f=" << current.f << endl;

        // Goal check
        if(current.name == 'G') {

            cout << "\nGoal Node Reached!";
            break;
        }

        // Expand neighbors manually
        if(current.name == 'A') {

            open.push(Node('B', current.g + 1, heuristic['B']));
            open.push(Node('C', current.g + 2, heuristic['C']));
        }

        else if(current.name == 'B') {

            open.push(Node('D', current.g + 2, heuristic['D']));
            open.push(Node('E', current.g + 3, heuristic['E']));
        }

        else if(current.name == 'C') {

            open.push(Node('F', current.g + 2, heuristic['F']));
            open.push(Node('G', current.g + 4, heuristic['G']));
        }
    }

    return 0;
}
