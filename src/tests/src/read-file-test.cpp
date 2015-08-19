#include <string>
#include "gtest/gtest.h"
#include "util/read-file.h"
#include "util/optional.h"

TEST (ReadFile, NormalFile)
{
	auto res = readFile("src/tests/res/file-io-test.txt");
	const std::string expected = "Hello, world!\nHello, OPENGL.\n";
	
	ASSERT_TRUE(res != NullOpt);
	
	EXPECT_TRUE(strcmp(res->data(), expected.data()) == 0);
}

TEST (ReadFile, NoFile)
{
	auto res = readFile("src/tests/res/file-io-test-NOFILE.txt");
	EXPECT_TRUE(res == NullOpt);
}

