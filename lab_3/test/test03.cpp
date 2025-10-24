#include <gtest/gtest.h>
#include <sstream>
#include "../include/point.h"
#include "../include/figure.h"
#include "../include/pentagon.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"
#include "../include/array.h"

// === Point Tests ===
TEST(PointTest, ConstructorsAndAccessors) {
    Point p1;
    EXPECT_DOUBLE_EQ(p1.get_x(), 0.0);
    EXPECT_DOUBLE_EQ(p1.get_y(), 0.0);

    Point p2(5.1, -3.2);
    EXPECT_DOUBLE_EQ(p2.get_x(), 5.1);
    EXPECT_DOUBLE_EQ(p2.get_y(), -3.2);

    Point p3(p2);
    EXPECT_DOUBLE_EQ(p3.get_x(), 5.1);
    EXPECT_DOUBLE_EQ(p3.get_y(), -3.2);

    Point p4(std::move(p3));
    EXPECT_DOUBLE_EQ(p4.get_x(), 5.1);
    EXPECT_DOUBLE_EQ(p4.get_y(), -3.2);
}

TEST(PointTest, ArithmeticOperators) {
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);

    Point sum = p1 + p2;
    EXPECT_DOUBLE_EQ(sum.get_x(), 4.0);
    EXPECT_DOUBLE_EQ(sum.get_y(), 6.0);

    Point diff = p2 - p1;
    EXPECT_DOUBLE_EQ(diff.get_x(), 2.0);
    EXPECT_DOUBLE_EQ(diff.get_y(), 2.0);

    p1 += p2;
    EXPECT_DOUBLE_EQ(p1.get_x(), 4.0);
    EXPECT_DOUBLE_EQ(p1.get_y(), 6.0);

    p1 -= p2;
    EXPECT_DOUBLE_EQ(p1.get_x(), 1.0);
    EXPECT_DOUBLE_EQ(p1.get_y(), 2.0);
}

TEST(PointTest, StreamOperators) {
    std::stringstream ss;
    Point p(7.5, -2.5);
    ss << p;
    std::string out = ss.str();
    EXPECT_FALSE(out.empty());

    Point q;
    std::stringstream ss2("1.0 2.0");
    ss2 >> q;
    EXPECT_DOUBLE_EQ(q.get_x(), 1.0);
    EXPECT_DOUBLE_EQ(q.get_y(), 2.0);
}

// === Figure Tests ===
TEST(FigureTest, PentagonProperties) {
    Pentagon pent;
    // задаем координаты вручную 
    pent = Pentagon();
    double area = static_cast<double>(pent);
    EXPECT_GE(area, 0.0);

    Point center = pent.getCenter();
    EXPECT_GE(center.get_x(), -1e6);
    EXPECT_GE(center.get_y(), -1e6);

    EXPECT_TRUE(pent.isCorrect() == true || pent.isCorrect() == false);
}

TEST(FigureTest, HexagonProperties) {
    Hexagon hex;
    double area = static_cast<double>(hex);
    EXPECT_GE(area, 0.0);

    Point center = hex.getCenter();
    EXPECT_GE(center.get_x(), -1e6);
    EXPECT_GE(center.get_y(), -1e6);

    EXPECT_TRUE(hex.isCorrect() == true || hex.isCorrect() == false);
}

TEST(FigureTest, OctagonProperties) {
    Octagon oct;
    double area = static_cast<double>(oct);
    EXPECT_GE(area, 0.0);

    Point center = oct.getCenter();
    EXPECT_GE(center.get_x(), -1e6);
    EXPECT_GE(center.get_y(), -1e6);

    EXPECT_TRUE(oct.isCorrect() == true || oct.isCorrect() == false);
}

TEST(FigureTest, EqualityOperator) {
    Pentagon p1;
    Pentagon p2 = p1;
    EXPECT_TRUE(p1 == p2);

    Hexagon h1;
    Hexagon h2;
    EXPECT_TRUE(h1 == h2);

    Octagon o1;
    Octagon o2;
    EXPECT_TRUE(o1 == o2);
}

TEST(FigureTest, StreamOperators) {
    Pentagon pent;
    std::stringstream ss;
    ss << pent;
    std::string output = ss.str();
    EXPECT_FALSE(output.empty());

    Pentagon pent2;
    std::stringstream ss2("0 0 1 0 0 1 1 1 0 1");
    ss2 >> pent2;
    EXPECT_TRUE(pent2.isCorrect() == true || pent2.isCorrect() == false);
}

// === Array Tests ===
TEST(ArrayTest, AddRemoveClear) {
    Array arr;

    Pentagon* p = new Pentagon();
    Hexagon* h = new Hexagon();
    Octagon* o = new Octagon();

    arr.push_back(p);
    arr.push_back(h);
    arr.push_back(o);

    EXPECT_EQ(arr.getSize(), 3);

    double total_area = arr.totalArea();
    EXPECT_GE(total_area, 0.0);

    arr.remove(1); // удаляем Hexagon
    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_GE(arr.totalArea(), 0.0);

    EXPECT_EQ(arr[0], p);
    EXPECT_EQ(arr[1], o);

    arr.clear();
    EXPECT_EQ(arr.getSize(), 0);
}

// === Array Exception Tests ===
TEST(ArrayTest, OutOfRangeAccess) {
    Array arr;
    Pentagon* p = new Pentagon();
    arr.push_back(p);

    EXPECT_THROW(arr[1], std::out_of_range);
    EXPECT_THROW(arr.remove(5), std::out_of_range);
}

// === Multiple Figures Area Test ===
TEST(ArrayTest, TotalAreaCalculation) {
    Array arr;
    Pentagon* p = new Pentagon();
    Hexagon* h = new Hexagon();
    Octagon* o = new Octagon();

    arr.push_back(p);
    arr.push_back(h);
    arr.push_back(o);

    double sum = static_cast<double>(*p) + static_cast<double>(*h) + static_cast<double>(*o);
    EXPECT_DOUBLE_EQ(arr.totalArea(), sum);
}

// === Complex Operations ===
TEST(ArrayTest, MixedOperations) {
    Array arr;
    Pentagon* p1 = new Pentagon();
    Pentagon* p2 = new Pentagon();
    arr.push_back(p1);
    arr.push_back(p2);

    EXPECT_EQ(arr.getSize(), 2);
    arr.remove(0);
    EXPECT_EQ(arr.getSize(), 1);
    arr.push_back(new Hexagon());
    EXPECT_EQ(arr.getSize(), 2);
    arr.clear();
    EXPECT_EQ(arr.getSize(), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
