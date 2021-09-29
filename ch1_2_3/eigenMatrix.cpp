#include <iostream>
using namespace std;
#include "/usr/include/eigen3/Eigen/Core"
#include "/usr/include/eigen3/Eigen/Dense"

#include <ctime>

int main(int argc, char **argv)
{
    Eigen::Matrix<float, 3, 2> matrix_32; //创建一个3*2的矩阵

    //创建一个3*1的矩阵
    Eigen::Vector3d v3d;
    Eigen::Matrix<float, 3, 1> matrix_v3d;

    //创建一个3*3的矩阵 并将其初始化为0
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();

    //动态矩阵
    Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> matric_dyn;
    Eigen::MatrixXd matric_dyn2;

    matrix_32 << 1, 2, 3, 4, 5, 6;
    cout << matrix_32 << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << matrix_32(i, j) << " ";
        cout << endl;
    }

    Eigen::Matrix<float, 2, 3> matrix_23;
    v3d << 1, 3, 5;
    matrix_23 << 2, 4, 6, 8, 10, 12;
    Eigen::Matrix<double, 2, 1> result = matrix_23.cast<double>() * v3d;

    Eigen::Matrix<float, 3, 1> v3f;
    v3f << 1, 3, 5;
    Eigen::Matrix<float, 2, 1> result_f = matrix_23 * v3f;
    cout << result_f << endl;
    cout << result << endl;
    cout << result_f << endl;
}