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
            std::cout << "size " << matSize << std::endl;

            Eigen::MatrixXd m1 = Eigen::MatrixXd::Random(matSize, matSize);
            Eigen::MatrixXd m2 = Eigen::MatrixXd::Random(matSize, matSize);

            std::vector<int> v(250000, 1);
            std::vector<std::vector<int>> v1(500, v);

            Matrix<int> normalMat1(500, 500, v);

            //EIGEN MULT
            tictoc_stack.push(std::chrono::system_clock::now());
            Eigen::MatrixXd multM = m1 * m2;
            std::chrono::duration<double> multTime = std::chrono::system_clock::now() - tictoc_stack.top();
            std::cout << "eigen mult " << multTime.count() << std::endl;
            tictoc_stack.pop();


            //EIGEN ADD
            tictoc_stack.push(std::chrono::system_clock::now());
            Eigen::MatrixXd addM = m1 + m2;
            std::chrono::duration<double> addTime = std::chrono::system_clock::now() - tictoc_stack.top();
            std::cout << "eigen add " << addTime.count() << std::endl;
            tictoc_stack.pop();


            //NORMAL MULT
            tictoc_stack.push(std::chrono::system_clock::now());
            Matrix<int> multNormal;
            multNormal = normalMat1 * normalMat1;
            std::chrono::duration<double> multTimeNormal = std::chrono::system_clock::now() - tictoc_stack.top();
            std::cout << "matlib mult " << multTimeNormal.count() << std::endl;
            tictoc_stack.pop();


            //NORMAL ADD
            tictoc_stack.push(std::chrono::system_clock::now());
            Matrix<int> addNormal;
            addNormal = normalMat1 + normalMat1;
            std::chrono::duration<double> addTimeNormal = std::chrono::system_clock::now() - tictoc_stack.top();
            std::cout << "matlib add " << addTimeNormal.count() << std::endl;
            tictoc_stack.pop();
        }
    }
}