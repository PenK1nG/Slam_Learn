#include <iostream>
#include <cmath>
#include "/usr/include/eigen3/Eigen/Core"
#include "/usr/include/eigen3/Eigen/Geometry"
using namespace std;
int main(int argc, char **argv)
{
    //旋转矩阵的定义
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
    //角轴的定义
    Eigen::AngleAxisd rotation_vector(M_PI / 4, Eigen::Vector3d(0, 0, 1));
    cout.precision(3);
    cout << "rotation matrix =\n"<< rotation_vector.matrix() << endl;//角轴转换为矩阵形式
    //角轴转化为旋转矩阵
    rotation_matrix = rotation_vector.toRotationMatrix();
    cout << "rotation matrix=\n"
         << rotation_matrix << endl;
    //一个向量分别用旋转矩阵和角轴进行旋转
    Eigen::Vector3d v(1, 0, 0);
    Eigen::Vector3d v_rotated = rotation_vector * v;
    cout << "(1,0,0) after AngleAxied_rotation = \n"
         << v_rotated << endl;
    v_rotated = rotation_matrix * v;
    cout << "(1,0,0) after rotation = \n"
         << v_rotated << endl;
    //欧拉角
    Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0);//ZYX顺序，即 yaw piych roll（ypr）
    cout << "yaw pitch roll = " << euler_angles.transpose() << endl;
    //欧式变换矩阵
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
    T.rotate(rotation_vector);
    T.pretranslate(Eigen::Vector3d(1, 3, 4));
    cout << "Transform matrix" << T.matrix() << endl;

    Eigen::Vector3d v_transformed = T * v;
    cout << "v_transformed = " << v_transformed.transpose() << endl;

    //四元数
    Eigen::Quaterniond q = Eigen::Quaterniond(rotation_vector);
    cout << "quaternion = \n"
         << q.coeffs() << endl;
    q = Eigen::Quaterniond(rotation_matrix);
    cout << "quaternion = \n"
         << q.coeffs() << endl;
    v_rotated = q*v;
    cout << "(1,0,0) after rotation = " << v_rotated.transpose() << endl;
}