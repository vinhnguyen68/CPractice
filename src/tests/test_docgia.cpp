#include <gtest/gtest.h>
#include "../DocGia.h"
#include "../Ngay.h"

TEST(NgayTest, DefaultConstructorIsZero) {
    Ngay n;
    EXPECT_EQ(n.getNgay(), 0);
    EXPECT_EQ(n.getThang(), 0);
    EXPECT_EQ(n.getNam(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}