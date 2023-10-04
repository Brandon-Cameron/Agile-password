#include "pch.h"

std::string checkPassword(std::string password) {

	std::string errorMsg = "";


	if (password.length() < 8)
	{
		errorMsg += "Password must be at least 8 characters" ;
	}

	int numCount = 0;
	for (auto i : password)
	{
		if (isdigit(i))
		{
			numCount++;
		}
	}

	if (numCount < 2)
	{
		errorMsg += "Password must have at least 2 numbers";
	}

	return errorMsg;
}

//TEST(nameOfFunctionBeingTested, descriptionOfWhatIsBeingTested)
TEST(checkPassword, AtLeast8Chars) {
	EXPECT_EQ("Password must be at least 8 characters", checkPassword("pwd"));
	EXPECT_EQ("", checkPassword("longpassword"));
}

TEST(checkPassword, AtLeast2Nums){
	EXPECT_EQ("Password must have at least 2 numbers", checkPassword("longpassword"));
}