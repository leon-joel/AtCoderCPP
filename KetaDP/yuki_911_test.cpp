#include <gtest/gtest.h>

// #include "yuki_911.cpp"

namespace
{

// テスト対象となるクラス Foo のためのフィクスチャ
class FooTest : public ::testing::Test
{
  protected:
	// 以降の関数で中身のないものは自由に削除できます．
	//

	FooTest()
	{
		// テスト毎に実行される set-up をここに書きます．
	}

	virtual ~FooTest()
	{
		// テスト毎に実行される，例外を投げない clean-up をここに書きます．
	}

	// コンストラクタとデストラクタでは不十分な場合．
	// 以下のメソッドを定義することができます：

	virtual void SetUp()
	{
		// このコードは，コンストラクタの直後（各テストの直前）
		// に呼び出されます．
	}

	virtual void TearDown()
	{
		// このコードは，各テストの直後（デストラクタの直前）
		// に呼び出されます．
	}

	// ここで宣言されるオブジェクトは，テストケース内の全てのテストで利用できます．
};

// Abc を行う Foo::Bar() メソッドをテストします．
TEST_F(FooTest, MethodBarDoesAbc)
{
	const std::string input_filepath = "this/package/testdata/myinputfile.dat";
	const std::string output_filepath = "this/package/testdata/myoutputfile.dat";
	// Foo f;
	// EXPECT_EQ(0, f.Bar(input_filepath, output_filepath));
	EXPECT_EQ(0, 1);
}

// Xyz を行う Foo をテストします．
TEST_F(FooTest, DoesXyz)
{
	// Foo の Xyz を検査
}

} // namespace

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
