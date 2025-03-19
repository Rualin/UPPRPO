#pragma once

#include <stdio.h>
#include "candle.h"
#include <gtest/gtest.h>

//open  high  low  close
//is_green start
TEST(Is_Green_Test, Green1) {
	Candle c(3.5, 5.5, 2.5, 4.5);
	EXPECT_TRUE(c.is_green());
}
TEST(Is_Green_Test, Green2) {
	Candle c(4.5, 5.5, 2.5, 3.5);
	EXPECT_FALSE(c.is_green());
}
TEST(Is_Green_Test, Green3) {
	Candle c(4.5, 5.5, 2.5, 4.5);
	EXPECT_FALSE(c.is_green());
}
//is_green end

//is_red start
TEST(Is_Red_Test, Red1) {
	Candle c(3.5, 5.5, 2.5, 4.5);
	EXPECT_FALSE(c.is_red());
}
TEST(Is_Red_Test, Red2) {
	Candle c(4.5, 5.5, 2.5, 3.5);
	EXPECT_TRUE(c.is_red());
}
TEST(Is_Red_Test, Red3) {
	Candle c(4.5, 5.5, 2.5, 4.5);
	EXPECT_FALSE(c.is_red());
}
//is_red end


//body_size start
TEST(Body_Size_Test, BodyS1) {
	Candle c(3.5, 5.5, 2.5, 4.5);
	EXPECT_EQ(c.body_size(), 1.0);
}
TEST(Body_Size_Test, BodyS2) {
	Candle c(1000, 1200, 500, 700);
	EXPECT_EQ(c.body_size(), 300);
}
TEST(Body_Size_Test, BodyS3) {
	Candle c(1234, 1234, 1234, 1234);
	EXPECT_EQ(c.body_size(), 0);
}
//body_size end

//full_size start
TEST(Full_Size_Test, FullS1) {
	Candle c(3.5, 5.5, 2.5, 4.5);
	EXPECT_EQ(c.full_size(), 3.0);
}
TEST(Full_Size_Test, FullS2) {
	Candle c(1000, 1200, 500, 700);
	EXPECT_EQ(c.full_size(), 700);
}
TEST(Full_Size_Test, FullS3) {
	Candle c(1234, 1234, 1234, 1234);
	EXPECT_EQ(c.full_size(), 0);
}
//full_size end

//contains start
TEST(Contains_Test, ConInTest) {
	Candle c(3.5, 5.5, 2.5, 4.5);
	EXPECT_TRUE(c.contains(5));
	EXPECT_TRUE(c.contains(3));
	EXPECT_TRUE(c.contains(4));
}
TEST(Contains_Test, ConOutTest) {
	Candle c(1000, 1200, 500, 700);
	EXPECT_FALSE(c.contains(400));
	EXPECT_FALSE(c.contains(1300));
}
TEST(Contains_Test, ConBoardTest) {
	Candle c(1000, 1200, 500, 700);
	EXPECT_TRUE(c.contains(500));
	EXPECT_TRUE(c.contains(1200));
}
//contains end

//body_contains start
TEST(Body_Contains_Test, BoConInTest) {
	Candle c(3.5, 5.5, 2.5, 4.5);
	EXPECT_TRUE(c.body_contains(4));
	Candle c2(4.5, 5.5, 2.5, 3.5);
	EXPECT_TRUE(c2.body_contains(4));
}
TEST(Body_Contains_Test, BoConOutTest) {
	Candle c(1000, 1200, 500, 700);
	EXPECT_FALSE(c.body_contains(600));
	EXPECT_FALSE(c.body_contains(1100));
	Candle c2(700, 1200, 500, 1000);
	EXPECT_FALSE(c2.body_contains(600));
	EXPECT_FALSE(c2.body_contains(1100));
}
TEST(Body_Contains_Test, BoConBoardTest) {
	Candle c(1000, 1200, 500, 700);
	EXPECT_TRUE(c.body_contains(700));
	EXPECT_TRUE(c.body_contains(1000));
	Candle c2(700, 1200, 500, 1000);
	EXPECT_TRUE(c2.body_contains(700));
	EXPECT_TRUE(c2.body_contains(1000));
}
//body_contains end
