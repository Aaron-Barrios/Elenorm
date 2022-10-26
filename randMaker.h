#include <iostream>
#include <fstream>
#include <string>
#include <vector>   
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#ifndef randMaker_H
#define randMaker_H
class randMaker{

private:
    int randomValue;
public:
    randMaker();
    randMaker(int startValue, int endValue);
    int getRandNum();
};

randMaker::randMaker(){
    srand(time(NULL));
    rand();

}

randMaker::randMaker(int startValue, int endValue){
    srand(time(NULL));
    randomValue = rand() % (endValue-startValue) + startValue;
}
int randMaker::getRandNum(){
    return randomValue;
}
#endif