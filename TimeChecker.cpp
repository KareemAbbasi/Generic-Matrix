//
// Created by kareem on 1/12/19.
//
#include <eigen3/Eigen/Dense>
#include <iostream>


int main(int argc, char **argv)
{
    if (argc > 1)
    {
        int matSize = std::stoi(argv[1]);
        if (matSize >=1 && matSize <= 500)
        {
            Eigen::MatrixXd m1 = Eigen::MatrixXd::Random(matSize, matSize);
            Eigen::MatrixXd m2 = Eigen::MatrixXd::Random(matSize, matSize);
        }

    }
}