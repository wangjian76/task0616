/*------------------------------------------------------------------------*/
/*! \file slicing.h
    \brief contains functions slice and order the gates

  Part of AMulet2.1 : AIG Multiplier Verification Tool.
  Copyright(C) 2020, 2021 Daniela Kaufmann, Johannes Kepler University Linz
*/
/*------------------------------------------------------------------------*/
#ifndef AMULET2_SRC_SLICING_H_
#define AMULET2_SRC_SLICING_H_
/*------------------------------------------------------------------------*/
#include <vector>
#include <list>

#include "gate.h"
/*------------------------------------------------------------------------*/
// / vector-list Gate* matrix to store slices 门矩阵来存储切片
extern std::vector<std::list<Gate*>> slices; //门矩阵放在list里，再都放在vector里
/*------------------------------------------------------------------------*/

/**
    Allocates the memory for the slices  为切片分配内存
    and adds the output gate of each slice 并添加每个切片的输出门。
*/
void init_slices();

/**
    Prints the polynomials in the slices to stdout
    将切片中的多项式打印到stdout。
*/
void print_slices();


/**
    Returns the child that has the highest position in a slice
    返回在一个切片中位置最高的子代。
    @param n Gate* for parent参数n Gate*为父代

    @return Gate*
*/
const Gate * topological_largest_child(const Gate * n);

/**
    Move gate n to slice i and insert it before it's topological_largest_child.
    将门n移到切片i上，并在它的topological_largest_child之前插入。
    @param n Gate*
    @param i integer, for new slice index 参数i整数，用于新切片的索引
*/
void fix_slice(Gate *n, int i);

/**
    Attach gates to slices by following xor-chains from the output gates.
    通过跟随输出门的xor链将门连接到片上。
*/
void slice_by_xor_chains();

/**
    Inserts the parents of n before pre in the slice of pre
    在pre的切片中，在pre之前插入n的父代。
    @param n Gate*
    @param pre Gate*
*/
void upwards_slicing(const Gate * n, const Gate * pre);

/**
    Slice gates that are between xor-chains, using upwards_slicing
    使用向上切割(upwards_slicing)，对处于xor链之间的门进行切片。
*/
void slice_jut_gates();

/**
    Fix some xors, that are assigned to different slices
   (needed for 7,3 counter trees )
   修复一些被分配到不同切片区的xors (7,3计数器树需要)
*/
int fix_xors();

/**
    If fix_xors() is applied also the jut gates need to be fixed.
    如果fix_xors()被应用，那么也需要对Jut门进行修复。
*/
void fix_jut_gates();

/**
    Overall slicing routine based on xor gates, calls all other functions
    automatically 基于xor门的整体切片程序，自动调用所有其他函数
*/
void slicing_xor();

/*------------------------------------------------------------------------*/

/**
    Mark the children of gate n to slice num, if not assigned otherwise.
    将门n的子代标记为切片num，如果没有指定的话。
    @param n Gate*
    @param num integer for  slice index  参数num切片索引的整数
*/
void input_cone(Gate * n, int num);

/**
    Identify those gates that are input in bigger slices
    识别那些在更大的切片中输入的门
*/
void find_carries();

/**
    Identifies whether polynomials use a booth pattern(as in the aoki benchmarks)
    识别多项式是否使用摊位模式（如aoki基准）。
    @return True if booth pattern are found 如果发现摊位模式(booth pattern)，则返回True
*/
bool search_for_booth_pattern();

/**
   We repeatedly move gates to smaller slices.我们反复地将门移到更小的切片区。
*/
void merge_all();

/**
    We repeatedly move gates to bigger slices.我们反复地把门移到更大的切片区。
*/
void promote_all();

/**
    Fills the slices by adding the gates that are assigned to slices
    通过添加分配给片区的门来填充切片区。
*/
void fill_slices();

/**
    Overall slicing routine, that does not depend on xor-chains
    整体切片程序，不依赖于xor-chains
*/
void slicing_non_xor();

#endif  // AMULET2_SRC_SLICING_H_
