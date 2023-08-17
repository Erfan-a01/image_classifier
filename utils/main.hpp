#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
using namespace std;

#include "utils.hpp"
#include "timer.hpp"

struct img_infos
{
    float feature[32];
    float distance;
    string label;
};

float distance_of_two_array(int array1[], int array2[], int n);
void distance_mat(int array[], int save[], int matrix[][28], int n);
float mean_cal(int x, int y, float submatrix[][28]);
float std_cal(int x, int y, float submatix[][28]);
void feature_cal(float matrix[][28], float array[32]);
void training(img_infos array[1000]);
void exploring(string label, int pic_num);
string test(img_infos array[1000], string label, int pic_num, int knum);
int random_generator();