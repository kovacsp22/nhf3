//
// Created by morak on 2021. 11. 17..
//

#ifndef SOLUTION_DUAL_SORT_H
#define SOLUTION_DUAL_SORT_H

#include <iostream>
#include <vector>
#include <cmath>

#include "heap.hpp"

int qs_divide(std::vector<int> &a, int down, int up) {
    int pivot=a[down];
    int left=down;
    int right=up;
    while(left<right){
        while(a[left]<=pivot && left<up) left=left+1;
        while(a[right]>=pivot && right>down) right=right-1;
        if(left<right) std::swap(a[left], a[right]);
    }
    a[down]=a[right];
    a[right]=pivot;
    return right;
}

void _dual_sort(std::vector<int> &data, int down, int up, double depth) {
    if(down>up) return;

    if(depth<=0){
        auto begin=data.begin()+down;
        int size=up-down+1;
        heap<int> heap({begin,begin+size});
        for (int i=0; i<size; i++) {
            data[up-i-1]=heap.top();
            heap.pop();
        }
    }else{
        int pivot=qs_divide(data,down,up);
        _dual_sort(data,down,pivot-1,depth-1);
        _dual_sort(data,pivot+1,up,depth-1);
    }
}

/**
 * dual_sort fv a  megadott tartomanyon talalhato elemeket
 * rendezi novekvo sorrendbe.
 *
 * @param data rendezendo vektor
 * @param N rendezendo vektor merete
 */
void dual_sort(std::vector<int> &data, int N) {
    if(N<2) return;
    _dual_sort(data, 0, N-1, log2(N)*2);
}

#endif //SOLUTION_DUAL_SORT_H
