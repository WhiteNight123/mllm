//
// Created by lx on 23-10-15.
//
#include "CPUTest.hpp"
#include "backends/cpu/CPURMSNorm.hpp"
TEST_F(CPUTest, CPURMSNorm1) {
    SETUP_OP(CPURMSNorm, false);
    TENSOR(input0);
    TENSOR(output);
    TENSOR(c_output);
    TEST_LOAD(input0);
    TEST_LOAD(output);

    TEST_RESHAPE({input0}, {c_output});
    TEST_SETUP({input0}, {c_output});
    TEST_LOAD(&op->weight_, false);
    op->weight_.printData<float>();
    TEST_EXCUTE({input0}, {c_output});
    COMPARE_TENSOR(c_output.get(), output.get(), true);
}