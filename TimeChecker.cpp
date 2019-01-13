//
// Created by kareem on 1/12/19.
//
#include <eigen3/Eigen/Dense>
#include <string>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include <chrono>
#include "Complex.h"
#include "Matrix.hpp"

/**
 * Checks the running time.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv)
{
    std::stack<std::chrono::time_point<std::chrono::system_clock>> tictoc_stack;
    if (argc > 1)
    {
        int matSize = std::stoi(argv[1]);
        if (matSize >= 1 && matSize <= 500)
        {
            std::vector<int> v(250000, 40);
            std::vector<std::vector<int>> v1(500, v);

            Eigen::MatrixXd m1 = Eigen::MatrixXd::Random(matSize, matSize);
            Eigen::MatrixXd m2 = Eigen::MatrixXd::Random(matSize, matSize);

            Matrix<int> normalMat1(500, 500, v);
            Matrix<int> normalMat2(500, 500, v);


            //EIGEN MULT
            tictoc_stack.push(std::chrono::system_clock::now());
            Eigen::MatrixXd multM = m1 * m2;
            std::chrono::duration<double> multTime = std::chrono::system_clock::now() - tictoc_stack.top();
            std::cout << "eigen mult: " << multTime.count() << "sec\n";
            tictoc_stack.pop();


            //EIGEN ADD
            tictoc_stack.push(std::chrono::system_clock::now());
            Eigen::MatrixXd addM = m1 + m2;
            std::chrono::duration<double> addTime = std::chrono::system_clock::now() - tictoc_stack.top();
            std::cout << "eigen add: " << addTime.count() << "sec\n";
            tictoc_stack.pop();


            //NORMAL MULT
            tictoc_stack.push(std::chrono::system_clock::now());
            Matrix<int> multNormal;
            multNormal = normalMat1 * normalMat2;
            std::chrono::duration<double> multTimeNormal = std::chrono::system_clock::now() - tictoc_stack.top();
            std::cout << "normal mult: " << multTimeNormal.count() << "sec\n";
            tictoc_stack.pop();


            //NORMAL ADD
            tictoc_stack.push(std::chrono::system_clock::now());
            Matrix<int> addNormal;
            addNormal = normalMat1 + normalMat2;
            std::chrono::duration<double> addTimeNormal = std::chrono::system_clock::now() - tictoc_stack.top();
            std::cout << "normal mult: " << addTimeNormal.count() << "sec\n";
            tictoc_stack.pop();

        }
    }
}