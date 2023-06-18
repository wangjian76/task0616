[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

AMulet 2.1 - AIG Multiplier Examination Tool
================================================================================

Our tool AMulet 2.1 is able to verify and certify unsigned and signed
integer multipliers given as AIGs.


----------------------------------------------------------------  

Dependencies: `libgmp` (https://gmplib.org/)

Use `./configure.sh && make` to configure and build `AMulet 2.1`.


usage : `amulet <mode> <input.aig> <output files> [<option> ...]`

Depending on the `<mode>` the `<output files>` and `<options>` have to be set accordingly:


    <mode> = -substitute:
      <output files> =  2 output files need to be passed in the following order
        <out.cnf>:        miter for checking the equivalence of the substituted adder
        <out.aig>:        rewritten aiger is stored in this file`

      <option> = the following options are available
        -h | --help       print this command line summary
        -v<1,2,3,4>       different levels of verbosity  (default -v1)
        -signed           option for signed integer multipliers


    <mode> = -verify:
      <output files> =  no output files are required

      <option> = the following options are available
         -h | --help           print this command line summary
         -v<1,2,3,4>           different levels of verbosity (default -v1)
         -signed               option for signed integer multipliers    
         -no-counter-examples  do not generate and write counter examples


    <mode> = -certify:
      <output files> =  3 output files need to be passed in the following order
        <out.polys>:      initial polynomial set
        <out.proof>:      proof rules (depending whether PAC proof or NS proof is generated)
        <out.spec> :      spec which should be checked

      <option> = the following options are available
         -h | --help           print this command line summary
         -v<1,2,3,4>           different levels of verbosity (default -v1)
         -signed               option for signed integer multipliers
         -no-counter-examples  do not generate and write counter examples

         -p1          expanded proof (no linear combinations, only multiplication and addition)
         -p2          middle condensed proof(sequence of linear combinations, default)
         -p3          condensed proof(one single linear combination)

--------------------------------------------------
10.09.2021 AMulet 2.1:
  - Reducing memory usage by changing data structure of polynomials

17.02.2021 AMulet 2.1:  
  - Instead of PAC and NSS we now support LPAC on different abstraction levels
    See https://github.com/d-kfmnn/pacheck2 for a corresponding proof checker.

  - Optimized polynomial generation

  [！[许可证：MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

  AMulet 2.1 - AIG乘数检查工具
  ================================================================================

  我们的工具AMulet 2.1能够验证和证明以AIG形式给出的无符号和有符号的
  整数乘法器作为AIGs给出。


  ----------------------------------------------------------------  

  依赖性。`libgmp` (https://gmplib.org/)

  使用`./configure.sh && make`来配置和构建`AMulet 2.1`。


  使用方法：`amulet <mode> <input.aig> <output files> [<option> ...]`。

  根据"<mode>"，"<output files>"和"<options>"必须进行相应设置。


      <mode> = -substitute:
        <输出文件> = 2个输出文件需要按以下顺序传递
          <out.cnf>：用于检查被替换的加法器的等效性的密特。
          <out.aig>：重写的aiger存储在这个文件中`。

        <option> = 有以下选项可用
          -h |-help 打印此命令行摘要
          -v<1,2,3,4> 不同级别的粗话（默认为-v1）
          -signed选项用于有符号的整数乘法器


      <mode> = -verify:
        <输出文件> = 不需要输出文件

        <option> = 以下选项可用
           -h |-help 打印此命令行摘要
           -v<1,2,3,4> 不同级别的粗话（默认为-v1）
           -signed选项用于有符号的整数乘法器    
           -no-counter-examples 不生成和写入计数器实例


      <mode> = -certify:
        <输出文件> = 3个输出文件，需要按以下顺序传递
          <out.polys>：初始多项式集
          <out.proof>：证明规则（取决于是生成PAC证明还是NS证明）
          <out.spec>：应该被检查的规格

        <option> = 可使用以下选项
           -h |-help 打印此命令行摘要
           -v<1,2,3,4> 不同的粗略程度（默认为-v1)
           -signed选项用于有符号的整数乘法器
           -no-counter-examples 不生成和写入计数器实例

           -p1扩展证明(没有线性组合，只有乘法和加法)
           -p2 中间浓缩证明(线性组合序列，默认)
           -p3 浓缩证明(一个单一的线性组合)

  --------------------------------------------------
  10.09.2021 AMulet 2.1:
    - 通过改变多项式的数据结构来减少内存占用

  17.02.2021 AMulet 2.1:  
    - 我们现在不支持PAC和NSS，而是支持不同抽象层次的LPAC
      相应的证明检查器见https://github.com/d-kfmnn/pacheck2。

    - 优化的多项式生成
  
