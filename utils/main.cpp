#include "main.hpp"



//*****************************distance of two array*********************************
float distance_of_two_array(float array1[], float array2[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pow(array1[i] - array2[i], 2);
    }
    return sum;
}
//**********************************distance of matrix**********************************
void distance_mat(int array[], int save[], int matrix[][28], int n)
{
    int sum;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += pow(matrix[i][j] - array[i], 2);
        }
        save[i] = sum;
        sum = 0;
    }
}
//*******************************mean function*********************************************
float mean_cal(int x, int y, float submatrix[][28])
{
    float sum = 0, mean;
    int finalx = x + 7;
    int finaly = y + 7;
    for (x; x < finalx; x++)
    {
        for (y; y < finaly; y++)
        {
            sum += submatrix[x][y];
        }
    }
    mean = sum / 49;
    return mean;
}
//*******************************std calculatar*********************************************
float std_cal(int x, int y, float submatrix[][28])
{
    float sum = 0;
    int finalx = x + 7;
    int finaly = y + 7;
    float mean = mean_cal(x, y, submatrix);
    for (x; x < finalx; x++)
    {
        for (y; y < finaly; y++)
        {
            sum += pow((submatrix[x][y] - mean), 2);
        }
    }
    float std = sqrt((1 / 48) * sum);
    return std;
}
//****************************feature vector calculater*************************************
void feature_cal(float matrix[][28], float array[32])
{
    int k = 0;
    for (int i = 0; i < 28; i += 7)
    {
        for (int j = 0; j < 28; j += 7)
        {
            array[k] = mean_cal(i, j, matrix);
            k++;
            array[k] = std_cal(i, j, matrix);
            k++;
        }
    }
}
//****************************************random generator***************************************************
int random_generator()
{
    srand((unsigned)time(NULL));
    int random = (rand() % 1000);
    return random;
}
//******************************************training**********************************************************
void training(img_infos array[1000])
{
    srand((unsigned)time(NULL));
    float img[IMAGE_SIZE][IMAGE_SIZE];
    string image_path;
    image_path = interpolation("data\\mnist", "train", "0");
    for (int j = 0; j < 100; j++)
    {
        load_image(image_path, rand() % 5000, img);
        feature_cal(img, array[j].feature);
        array[j].label = "0";
    }
    image_path = interpolation("data\\mnist", "train", "1");
    for (int j = 100; j < 200; j++)
    {
        load_image(image_path, rand() % 5000, img);
        feature_cal(img, array[j].feature);
        array[j].label = "1";
    }
    image_path = interpolation("data\\mnist", "train", "2");
    for (int j = 200; j < 300; j++)
    {
        load_image(image_path, rand() % 5000, img);
        feature_cal(img, array[j].feature);
        array[j].label = "2";
    }
    image_path = interpolation("data\\mnist", "train", "3");
    for (int j = 300; j < 400; j++)
    {
        load_image(image_path, rand() % 5000, img);
        feature_cal(img, array[j].feature);
        array[j].label = "3";
    }
    image_path = interpolation("data\\mnist", "train", "4");
    for (int j = 400; j < 500; j++)
    {
        load_image(image_path, rand() % 5000, img);
        feature_cal(img, array[j].feature);
        array[j].label = "4";
    }
    image_path = interpolation("data\\mnist", "train", "5");
    for (int j = 500; j < 600; j++)
    {
        load_image(image_path, rand() % 5000, img);
        feature_cal(img, array[j].feature);
        array[j].label = "5";
    }
    image_path = interpolation("data\\mnist", "train", "6");
    for (int j = 600; j < 700; j++)
    {
        load_image(image_path, rand() % 5000, img);
        feature_cal(img, array[j].feature);
        array[j].label = "6";
    }
    image_path = interpolation("data\\mnist", "train", "7");
    for (int j = 700; j < 800; j++)
    {
        load_image(image_path, rand() % 5000, img);
        feature_cal(img, array[j].feature);
        array[j].label = "7";
    }
    image_path = interpolation("data\\mnist", "train", "8");
    for (int j = 800; j < 900; j++)
    {
        load_image(image_path, rand() % 5000, img);
        feature_cal(img, array[j].feature);
        array[j].label = "8";
    }
    image_path = interpolation("data\\mnist", "train", "9");
    for (int j = 900; j < 1000; j++)
    {
        load_image(image_path, rand() % 5000, img);
        feature_cal(img, array[j].feature);
        array[j].label = "9";
    }
    int real_label[30];
    string test_label[30];
    for (int i = 0; i < 30; i++)
    {
        real_label[i] = rand() % 10;
        test_label[i] = test(array, to_string(real_label[i]), rand() % 600, 11);
    }
    for (int i = 0; i < 30; i++)
    {
        cout << real_label[i] << " : " << test_label[i] << endl;
    }
    float count = 0;
    for (int i = 0; i < 30; i++)
    {
        if (to_string(real_label[i]) == test_label[i])
        {
            count++;
        }
    }
    cout << (count / 30) * 100 << " % " << endl;
    /*for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            std::cout << array[i].feature[j] << " ";
        }
        std::cout << std::endl;
    }*/
}
//*****************************************************exploring****************************************
void exploring(string label, int pic_num)
{
    float img[IMAGE_SIZE][IMAGE_SIZE];
    string image_path;
    image_path = interpolation("data\\mnist", "train", label);
    load_image(image_path, pic_num, img);

    for (int i = 0; i < IMAGE_SIZE; i++)
    {
        for (int j = 0; j < IMAGE_SIZE; j++)
        {
            if (img[i][j] == 0)
                cout << "*";
            else
                cout << " ";
        }
        std::cout << std::endl;
    }
}
//!-------------------------------------test-------------------------------------------
string test(img_infos array[1000], string label, int pic_num, int knum)
{
    float matrix_feature[32];
    float min_array[25];
    string min_array_label[25];
    float img[IMAGE_SIZE][IMAGE_SIZE];
    string image_path;
    image_path = interpolation("data\\mnist", "train", label);
    load_image(image_path, pic_num, img);
    // training(array);
    feature_cal(img, matrix_feature);
    for (int i = 0; i < 1000; i++)
    {
        array[i].distance = distance_of_two_array(matrix_feature, array[i].feature, 32);
    }
    min_array[0] = 999999;
    min_array_label[0] = "";
    for (int i = 0; i < 1000; i++)
    {
        if (array[i].distance < min_array[0])
        {
            min_array[0] = array[i].distance;
            min_array_label[0] = array[i].label;
        }
    }
    for (int i = 1; i < knum; i++)
    {
        min_array[i] = 999999;
        for (int j = 0; j < 1000; j++)
        {
            if (array[j].distance < min_array[i] && array[j].distance > min_array[i - 1])
            {
                min_array[i] = array[j].distance;
                min_array_label[i] = array[j].label;
            }
        }
    }
    /*for (int i = 0; i < knum; i++)
    {
        cout << min_array[i] << " : " << min_array_label[i] << endl;
    }*/
    int max_r = 0;
    string pic_label = "nun";
    int count;
    for (int i = 0; i < knum; i++)
    {
        count = 0;
        for (int j = 0; j < knum; j++)
        {
            if (min_array_label[i] == min_array_label[j])
            {
                count++;
            }
        }
        if (max_r < count)
        {
            max_r = count;
            pic_label = min_array_label[i];
        }
    }
    return pic_label;
}
