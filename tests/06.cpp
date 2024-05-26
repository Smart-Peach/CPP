#include "../06/06.cpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>


TEST(MatrixTest, CtorTest) {
    Matrix m = Matrix(5);
}

TEST(MatrixTest, PrintingTest) {
    Matrix m = Matrix(3);
    std::cout << m;
}

TEST(MatrixTest, OperatorIndex) {
    Matrix m = Matrix(3);
}

TEST(MatrixTest, WrongIndex) {

}

TEST(MatrixTest, CtorDiagonal) {
    std::vector dig_elems {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    Matrix m2 = Matrix(dig_elems);

    for (size_t i = 0; i < m2.get_size(); ++i) {
        for (size_t j = 0; j < m2.get_size(); ++j) {
            if (i==j) {
                ASSERT_EQ(m2[i][i], dig_elems[i]);
            } else {
                ASSERT_EQ(m2[i][j], 0.0);
            }
        }
    }
}

TEST(MatrixTest, OperatorPlusScalarRight) {
    std::vector dig_elems {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    Matrix m2 = Matrix(dig_elems);

    Matrix m3 = m2 + 5;
    for (size_t i = 0; i < m3.get_size(); ++i) {
        for (size_t j = 0; j < m3.get_size(); ++j) {
            ASSERT_EQ(m3[i][j], m2[i][j] + 5);
        }
    }
}

TEST(MatrixTest, OperatorPlusScalarLeft) {
    std::vector dig_elems {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    Matrix m2 = Matrix(dig_elems);

    Matrix m3 = 5 + m2;
    for (size_t i = 0; i < m3.get_size(); ++i) {
        for (size_t j = 0; j < m3.get_size(); ++j) {
            ASSERT_EQ(m3[i][j], m2[i][j] + 5);
        }
    }
}

TEST(MatrixTest, OperatorPlusMatrix) {


}

TEST(MatrixTest, OperatorMultMatrix) {

}

TEST(MatrixTest, OperatorMultScalarLeft) {
    Matrix m2 = Matrix(5);
    m2.filled_matrix();

    Matrix m3 = 5 * m2;
    for (size_t i = 0; i < m3.get_size(); ++i) {
        for (size_t j = 0; j < m3.get_size(); ++j) {
            ASSERT_EQ(m3[i][j], m2[i][j] * 5);
        }
    }
}

TEST(MatrixTest, OperatorMultScalarRight) {
    Matrix m2 = Matrix(5);
    m2.filled_matrix();

    Matrix m3 = m2 * 5;
    for (size_t i = 0; i < m3.get_size(); ++i) {
        for (size_t j = 0; j < m3.get_size(); ++j) {
            ASSERT_EQ(m3[i][j], m2[i][j] * 5);
        }
    }
}

TEST(MatrixTest, OperatorEQ) {
    Matrix m1 = Matrix(5);
    m1.filled_matrix();
    Matrix m2 = Matrix(5);
    m2.filled_matrix();

    ASSERT_TRUE(m1 == m2);
}

TEST(MatrixTest, OperatorNotEQ) {
    Matrix m1 = Matrix(5);
    m1.filled_matrix();
    Matrix m2 = Matrix(5);
    m2.filled_matrix();
    m2 += 1;

    ASSERT_TRUE(m1 != m2);
}

TEST(MatrixTest, OperatorPlusEQScalar) {
    Matrix m2 = Matrix(5);
    m2.filled_matrix();
    Matrix m3 = Matrix(5);
    m3.filled_matrix();

    m3 += 5;
    for (size_t i = 0; i < m3.get_size(); ++i) {
        for (size_t j = 0; j < m3.get_size(); ++j) {
            ASSERT_EQ(m3[i][j], m2[i][j] + 5);
        }
    }
}

TEST(MatrixTest, OperatorMultEQScalar) {
    Matrix m2 = Matrix(5);
    m2.filled_matrix();
    Matrix m3 = Matrix(5);
    m3.filled_matrix();

    m3 *= 5;
    for (size_t i = 0; i < m3.get_size(); ++i) {
        for (size_t j = 0; j < m3.get_size(); ++j) {
            ASSERT_EQ(m3[i][j], m2[i][j] * 5);
        }
    }
}

TEST(MatrixTest, OperatorMultEQMatrix) {
    Matrix m2 = Matrix(5);
    m2.filled_matrix();
    Matrix m3 = Matrix(5);
    m3.filled_matrix();

    m3 *= 5;
    for (size_t i = 0; i < m3.get_size(); ++i) {
        for (size_t j = 0; j < m3.get_size(); ++j) {
            ASSERT_EQ(m3[i][j], m2[i][j] * 5);
        }
    }
}

TEST(MatrixTest, OperatorPlusEQMatrix) {
    Matrix m2 = Matrix(5);
    m2.filled_matrix();
    Matrix m3 = Matrix(5);
    m3.e_matrix();

    m3 += m2;
    for (size_t i = 0; i < m3.get_size(); ++i) {
        for (size_t j = 0; j < m3.get_size(); ++j) {
            ASSERT_EQ(m3[i][j], 1 + (i + j));
        }
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
