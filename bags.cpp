//
// Created by Audrey on 1/14/2020.
//

#include <iostream>
#include <fstream>
#include "StackAr.h"
#include "QueueAr.h"
#include <cstdlib>

int main(int argc, char** argv) {
    std::ifstream inFile(argv[1]);
    short bagNumber;
    Queue<int> bags(atoi(argv[2]));
    StackAr<Queue<int>> containers;

    while(inFile >> bagNumber){
        if (!bags.isFull()){
            bags.enqueue(bagNumber);
        }else{
            containers.push(bags);
            bags.makeEmpty();
            bags.enqueue(bagNumber);
        }
    }
    containers.push(bags);
    bags.makeEmpty();
    
    while(!containers.isEmpty()){
        bags = containers.topAndPop();
        while (!bags.isEmpty()){
            std::cout << bags.dequeue();
            if (!containers.isEmpty() || !bags.isEmpty()){
                std::cout << " ";
            }
        }
    }
    std::cout << std::endl;
    return 0;
}