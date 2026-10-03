#include <gtest/gtest.h>
#include <sstream>
#include "../DocGia.h"
#include "../DocGiaNguoiLon.h"
#include "../DocGiaTreEm.h"
#include "../ThuVien.h"
#include "../Ngay.h"

// ---------- Ngay ----------

TEST(NgayTest, DefaultConstructorIsZero) {
    Ngay n;
    EXPECT_EQ(n.getNgay(), 0);
    EXPECT_EQ(n.getThang(), 0);
    EXPECT_EQ(n.getNam(), 0);
}

TEST(NgayTest, ReadsThreeIntsFromStream) {
    std::istringstream input("15 6 2025\n");
    Ngay n;
    input >> n;
    EXPECT_EQ(n.getNgay(), 15);
    EXPECT_EQ(n.getThang(), 6);
    EXPECT_EQ(n.getNam(), 2025);
}

// ---------- DocGiaNguoiLon: pure logic (no stream) ----------

TEST(DocGiaNguoiLonTest, DefaultConstructorCMNDIsZero) {
    DocGiaNguoiLon dg;
    EXPECT_EQ(dg.getCMND(), "0");
}

TEST(DocGiaNguoiLonTest, SetCMNDThenGetCMND) {
    DocGiaNguoiLon dg;
    dg.setCMND("987654321");
    EXPECT_EQ(dg.getCMND(), "987654321");
}

// TinhTienLamThe = SoThangHieuLuc * 10000. SoThangHieuLuc is protected
// with no setter, so we go through the stream to set it, then check the formula.
TEST(DocGiaNguoiLonTest, TinhTienLamTheFormula) {
    std::istringstream input(
        "Nguyen Van A\n"
        "1 1 2024\n"
        "12\n"          // SoThangHieuLuc = 12
        "123456789\n"
    );
    DocGiaNguoiLon dg;
    input >> dg;
    EXPECT_FLOAT_EQ(dg.TinhTienLamThe(), 12 * 10000);
}

// Regression test for the known fflush(stdin)/newline bug: CMND currently
// comes out empty instead of "123456789" because the trailing newline left
// after reading SoThangHieuLuc is consumed by getline() instead of the real
// CMND line. Once fixed (e.g. is.ignore(numeric_limits<streamsize>::max(), '\n')
// in place of fflush(stdin)), flip this to EXPECT_EQ(dg.getCMND(), "123456789").
TEST(DocGiaNguoiLonTest, KnownBug_CMNDComesOutEmptyDueToLeftoverNewline) {
    std::istringstream input(
        "Nguyen Van A\n"
        "1 1 2024\n"
        "12\n"
        "123456789\n"
    );
    DocGiaNguoiLon dg;
    input >> dg;
    EXPECT_EQ(dg.getCMND(), "");  // documents current (buggy) behavior
}

// ---------- DocGiaTreEm ----------

TEST(DocGiaTreEmTest, TinhTienLamTheIsFlatFee) {
    DocGiaTreEm dg;
    EXPECT_FLOAT_EQ(dg.TinhTienLamThe(), 20000);
}

// ---------- ThuVien ----------

TEST(ThuVienTest, KiemTraTrungCMND_EmptyListReturnsFalse) {
    ThuVien tv;
    EXPECT_FALSE(tv.KiemTraTrungCMND("123456789"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}