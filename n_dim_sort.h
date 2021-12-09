//
// Created by morak on 2021. 11. 18..
//

#ifndef SOLUTION_N_DIM_SORT_H
#define SOLUTION_N_DIM_SORT_H

#include <iostream>
#include <vector>
#include "cmath"
#include "dual_sort.h"

/**
 * 2D-be rendezi a megadott vektort
 *
 * @param v rendezendo vektor
 * @return rendezett 2D matrix
 */
std::vector<std::vector<int>> sort_2D(std::vector<int> v){
    dual_sort(v,v.size());

    size_t matSizes=ceil(sqrt(v.size()))+1;
    std::vector<int> zeroV(matSizes, 0);
    std::vector<std::vector<int>> distanceM(matSizes,zeroV);
    std::vector<std::vector<int>> sortedM(matSizes,zeroV);

    for(size_t i=0; i<matSizes; i++){
        for(size_t j=0; j<matSizes; j++){
            distanceM[i][j]=i*i+j*j;
        }
    }

    for(int vec : v){
        int minValue=2*matSizes*matSizes+1;
        size_t minX=0, minY=0;
        for(size_t i=0; i<matSizes; i++){
            for(size_t j=0; j<matSizes; j++){
                if(sortedM[j][i]==0 && distanceM[j][i]<minValue){
                    minValue=distanceM[j][i];
                    minX=j;
                    minY=i;
                }
            }
        }
        sortedM[minX][minY]=vec;
    }

    for(size_t i=0; i<matSizes; i++){
        for(size_t j=0; j<matSizes; j++){
            if(sortedM[j][i]<10) std::cout<<" ";
            std::cout<<sortedM[j][i]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;

    return sortedM;
}

/**
 * 3D-be rendezi a megadott vektort
 *
 * @param v rendezendo vektor
 * @return rendezett 3D matrix
 */
std::vector<std::vector<std::vector<int>>> sort_3D(std::vector<int> v) {
    dual_sort(v,v.size());
    size_t matSizes=ceil(pow(v.size(),1.0/3))+1;
    std::vector<int> zeroV(matSizes, 0);
    std::vector<std::vector<int>> zeroM(matSizes, zeroV);
    std::vector<std::vector<std::vector<int>>> distanceM(matSizes,zeroM);
    std::vector<std::vector<std::vector<int>>> sortedM(matSizes,zeroM);

    for(size_t i=0; i<matSizes; i++){
        for(size_t j=0; j<matSizes; j++){
            for(size_t k=0; k<matSizes; k++){
                distanceM[i][j][k]=i*i+j*j+k*k;
            }
        }
    }

    for(int vec : v){
        int minValue=3*matSizes*matSizes+1;
        size_t minX=0, minY=0, minZ=0;
        for(size_t i=0; i<matSizes; i++){
            for(size_t j=0; j<matSizes; j++){
                for(size_t k=0; k<matSizes; k++){
                    if(sortedM[k][j][i]==0 && distanceM[k][j][i]<minValue){
                        minValue=distanceM[k][j][i];
                        minX=k;
                        minY=j;
                        minZ=i;
                    }
                }
            }
        }
        sortedM[minX][minY][minZ]=vec;
    }

    for(size_t i=0; i<matSizes; i++){
        std::cout<<"z = "<<i<<std::endl;
        for(size_t j=0; j<matSizes; j++){
            for(size_t k=0; k<matSizes; k++){
                if(sortedM[k][j][i]<10) std::cout<<" ";
                std::cout<<sortedM[k][j][i]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl<<std::endl;
    }

    return sortedM;
}

#endif //SOLUTION_N_DIM_SORT_H
