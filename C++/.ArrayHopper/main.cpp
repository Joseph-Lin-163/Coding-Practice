//
//  main.cpp
//  ArrayHopper
//
//  Created by mac on 10/27/14.
//  Copyright (c) 2014 mac. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct nodes_t {
    int steps;
    vector<int> retraceSteps; // For keeping track of the path taken, has index, not values stored
};

// Please see final thoughts at the end
int main() {
    // insert code here...
    
    // Get the string of numbers into a vector
    vector<int> myVector;
    string numbers;
    while (getline(cin,numbers)) {
        try {
            myVector.push_back(stoi(numbers));
        }
        catch (...) {
            cout << "failure\n";;
            return 0;
        }
    }
    
    for (int i = 0; i < myVector.size(); i++) {
        if (myVector[i] < 0) {
            cout << "failure\n";
            return 0;
        }
    }
    

    // Set up n-ary tree in form of vector
    // This is awesome
    vector<nodes_t> naryTree;
    for (int i = 0; i < myVector.size(); i++) {
        nodes_t temp;
        temp.steps = -1;
        naryTree.push_back(temp);
    }
    
    // set up root
    naryTree[0].steps = 0;
    
    bool outFound = false;
    int winner = -1;
    
    //cout << myVector.size();;
    
    // A possible n-level unary tree, so i < myVector.Size()
    
    // Go by "steps" or the levels of a n-ary tree, start at level 0 and proceed up
    
    // Then, visit all neighbors of step n, so for step 0, we visit index 1 through 5
    // We don't care about the dragons, so skip those (using myVector[currentNode] !=0)
    
    // For all neighbors, if not visited before, visit, otherwise check to see if visiting it would cause
    // me to take a step less than its current number of steps, if so, do the following:
    // Redefine new steps using the better path
    // If visiting for the first time, I have to remember to set steps = 0
    // And, if we have a winner, such that the steps is minimal and I can get past the last index,
    // Mark down the winner and push the winner onto the vector, and -1 so I can cout "out"
    // Break out of BFS algorithm.
    
    // Special case that my algorithm needs to see early on
    if (myVector[0] >= myVector.size()) {
        cout << myVector[0] << ", out";;
        return 0;
    }
 
    
    // Note, this could be modularized, there is a copy/paste section in my code. Reason being that I handled the case
    // Where the neighbor hasn't been visited yet. Put repeat code in a function and call it to modularize
    
    for (int currentStep = 0; currentStep < myVector.size(); currentStep++) {
        for (int currentNode = 0; currentNode < myVector.size(); currentNode++) {
            if (naryTree[currentNode].steps == currentStep && myVector[currentNode] != 0) {
                
                for (int possibleSteps = 1; possibleSteps <= myVector[currentNode]; possibleSteps++) {
                    
                    if (currentNode == myVector.size()-1) {
                        winner = currentNode;
                        naryTree[winner].retraceSteps.push_back(winner);
                        naryTree[winner].retraceSteps.push_back(-1);
                        outFound = true;
                        break;
                    }
                    
                    if (naryTree[currentNode+possibleSteps].steps < 0) {
                        naryTree[currentNode+possibleSteps].steps = 0;
                        naryTree[currentNode+possibleSteps].steps = naryTree[currentNode].steps + 1;
                        
                        for (int i = 0; i < naryTree[currentNode].retraceSteps.size(); i++) {
                            naryTree[currentNode+possibleSteps].retraceSteps.push_back(naryTree[currentNode].retraceSteps[i]);
                        }
                        naryTree[currentNode+possibleSteps].retraceSteps.push_back(currentNode);
                        
                        if (myVector[currentNode+possibleSteps] + currentNode+possibleSteps >= myVector.size()) {
                            winner = currentNode+possibleSteps;
                            naryTree[winner].retraceSteps.push_back(winner);
                            naryTree[winner].retraceSteps.push_back(-1);
                            outFound = true;
                            break;
                        }

                    }
                    else if ((naryTree[currentNode+possibleSteps].steps > naryTree[currentNode].steps + 1)) {
                        
                        if (currentNode == myVector.size()-1) {
                            winner = currentNode;
                            naryTree[winner].retraceSteps.push_back(winner);
                            naryTree[winner].retraceSteps.push_back(-1);
                            outFound = true;
                            break;
                        }
                        
                        naryTree[currentNode+possibleSteps].steps = naryTree[currentNode].steps + 1;
                        for (int i = 0; i < naryTree[currentNode].retraceSteps.size(); i++) {
                            naryTree[currentNode+possibleSteps].retraceSteps.push_back(naryTree[currentNode].retraceSteps[i]);
                        }
                        naryTree[currentNode+possibleSteps].retraceSteps.push_back(currentNode);
                        
                        if (myVector[currentNode+possibleSteps] + currentNode+possibleSteps >= myVector.size()) {
                            winner = currentNode+possibleSteps;
                            naryTree[winner].retraceSteps.push_back(winner);
                            naryTree[winner].retraceSteps.push_back(-1);
                            outFound = true;
                            break;
                        }
                    }
                }
            }
            else if (outFound == true)
                break;
        }
        if (outFound == true)
            break;
    }
    
    if (winner > 0) {
        for (int i = 0; i < naryTree[winner].retraceSteps.size(); i++) {
            if (naryTree[winner].retraceSteps[i] < 0)
                cout << "out";
            else
                cout << naryTree[winner].retraceSteps[i] << ", ";
        }
    }
    else
        cout << "failure";;
    
    return 0;
}

/*
 Final thoughts:
 
 Good challenge. There was a performance issue with mine that I noticed.
 I should have just stuck to creating a n-ary tree using structs but I wanted to get creative
 and create a n-ary tree using vectors. That would be alright for small cases where the number
 of elements isn't a large factor. I would use pointers in that case.
 
 My general design followed the Breadth First Search algorithm which runs on O(|E| + |V|) where E = number of edges
 and V = number of vertices. I came to the conclusion of using the BFS algorithm
 the moment I saw the words "minimum-length sequence". BFS does indeed allow me to find the
 minimum length to get from point a to point b. It was a matter of conceptualizing it
 in terms of steps. In this case, the number of nodes in which I can visit grows quite rapidly.
 
 Perhaps a better approach could be using a greedy algorithm where I see if I can
 start from the furthest reach and see if there is a path to the end. Something
 very similar to Depth First Search. Again, I would still need a n-ary tree for this.
 
 If I could do this challenge again, I would use my time to create a better data structure for
 holding the nodes of the tree as well as use Depth First Search in a greedy-like fashion.
 Nonetheless, I appreciate the challenge, even though I only scored 11/15 test cases.
 */
