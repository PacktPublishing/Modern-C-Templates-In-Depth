#include "list.h"
#include <gtest/gtest.h>
//int main() {
//	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG)) ;
//	List<int> elements{} ;
//	for (int i = 0 ; i < 10 ; ++i) {
//		elements.Add(i) ;
//	}
//	List<int>::Position at = elements.First() ;
//	while (!elements.End(at)) {
//		std::cout << elements.GetAt(at) << ' ' ;
//		elements.Next(at) ;
//	}
//	//elements.Print() ;
//}

TEST(ListTest, EmptyList) {
	List<int> list ;
	EXPECT_EQ(list.Size(), 0) ;
	EXPECT_TRUE(list.Empty()) ;

	auto pos = list.First() ;
	EXPECT_TRUE(list.End(pos)) ;
}
TEST(ListTest, Add) {
	List<int> list ;
	list.Add(1) ;
	list.Add(2) ;
	list.Add(3) ;

	EXPECT_EQ(list.Size(), 3) ;
	EXPECT_FALSE(list.Empty()) ;

	auto pos = list.First() ;
	EXPECT_EQ(list.GetAt(pos), 1) ;

	list.Next(pos) ;
	EXPECT_EQ(list.GetAt(pos), 2) ;

	list.Next(pos) ;
	EXPECT_EQ(list.GetAt(pos), 3) ;

}
TEST(ListTest, Insert) {
	List<int> list ;
	list.Add(1) ;
	list.Add(3) ;

	auto at = list.First() ;
	list.Next(at) ;
	list.Insert(at, 2) ;

	EXPECT_EQ(list.Size(), 3) ;

	auto pos = list.First() ;
	EXPECT_EQ(list.GetAt(pos), 1) ;

	list.Next(pos) ;
	EXPECT_EQ(list.GetAt(pos), 2) ;

	list.Next(pos) ;
	EXPECT_EQ(list.GetAt(pos), 3) ;

}
TEST(ListTest, InsertAtFront) {
	List<int> list ;
	list.Add(2) ;
	list.Add(3) ;

	auto at = list.First() ;
	list.Insert(at, 1) ;

	EXPECT_EQ(list.Size(), 3) ;

	auto pos = list.First() ;
	EXPECT_EQ(list.GetAt(pos), 1) ;

	list.Next(pos) ;
	EXPECT_EQ(list.GetAt(pos), 2) ;

	list.Next(pos) ;
	EXPECT_EQ(list.GetAt(pos), 3) ;

}
TEST(ListText, EraseElements) {
	List<int> list ;
	list.Add(1) ;
	list.Add(2) ;
	list.Add(3) ;

	auto pos = list.First() ;
	list.Next(pos) ;
	list.Erase(pos) ;

	EXPECT_EQ(list.Size(), 2) ;

	pos = list.First() ;
	EXPECT_EQ(list.GetAt(pos), 1) ;

	list.Next(pos) ;
	EXPECT_EQ(list.GetAt(pos), 3) ;
}
TEST(ListText, EraseFirstElement) {
	List<int> list ;
	list.Add(1) ;
	list.Add(2) ;
	list.Add(3) ;

	auto pos = list.First() ;
	list.Erase(pos) ;

	EXPECT_EQ(list.Size(), 2) ;

	pos = list.First() ;
	EXPECT_EQ(list.GetAt(pos), 2) ;

	list.Next(pos) ;
	EXPECT_EQ(list.GetAt(pos), 3) ;
}
TEST(ListText, EraseLastElement) {
	List<int> list ;
	list.Add(1) ;
	list.Add(2) ;
	list.Add(3) ;

	auto pos = list.First() ;
	list.Next(pos) ;
	list.Next(pos) ;
	list.Erase(pos) ;

	EXPECT_EQ(list.Size(), 2) ;

	pos = list.First() ;
	EXPECT_EQ(list.GetAt(pos), 1) ;

	list.Next(pos) ;
	EXPECT_EQ(list.GetAt(pos), 2) ;
}


template<>
class ListPrinter<std::string> {
public:
	void PrePrint()const {
		std::cout << "############# NAMES ###########\n" ;
	}
	void Print(const std::string &name)const {
		std::cout << name << '\n' ;
	}
	void PostPrint()const {
		std::cout << "##############################\n" ;
	}
};
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv) ;
	return RUN_ALL_TESTS() ;

	List<std::string> names{} ;
    names.Add("Aria Celeste Morgan");
    names.Add("Liam Everett Hayes");
    names.Add("Ethan James O'Connor");
    names.Add("Sophia Maeve Taylor");
    names.Add("Elena Rose Carter");
    names.Add("Ryan Alexander Bennett");
    names.Add("Maya Lorraine Sinclair");
    names.Add("Aiden Thomas Walker");
    names.Add("Zara Elise Thompson");
    names.Add("Olivia Grace Miller");

	names.Print() ;
}