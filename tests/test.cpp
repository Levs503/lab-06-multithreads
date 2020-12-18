// Copyright 2020 Your Name <your_email>

#include <HashWorker.h>
#include <gtest/gtest.h>
TEST(Example, EmptyTest) {
  HashWorker sha256;
  std::string fr = "1112340000";
  std::string sc = "124543245000";
  ASSERT_TRUE(sha256.Check(fr));
  ASSERT_FALSE(sha256.Check(sc));
  FindHash();
  FindHash();
  FindHash();
  ASSERT_TRUE(sha256.Check(HashWorker::rightHash[0].hash));
  ASSERT_TRUE(sha256.Check(HashWorker::rightHash[1].hash));
  ASSERT_TRUE(sha256.Check(HashWorker::rightHash[2].hash));
  RightHash a{"data", "hash", 11111};
  std::vector<RightHash> b = {a};
  std::ostringstream ostr;
  WriteToFile(ostr, b);
  std::string correct =
      ("[\n"
       "    {\n"
       "        \"timestamp\": 11111,\n"
       "        \"hash\": \"hash\"\n"
       "        \"data\": \"data\"\n"
       "    }\n"
       "]\n");
  ASSERT_EQ(ostr.str(), correct);
  RightHash c{"dataw", "hashw", 22222};
  b.push_back(c);
  std::ofstream d("/home/levs503/CLionProjects/ord.txt");
  WriteToFile(d, b);
  std::string correct2 =
      ("[\n"
       "    {\n"
       "        \"timestamp\": 11111,\n"
       "        \"hash\": \"hash\"\n"
       "        \"data\": \"data\"\n"
       "    },\n"
       "    {\n"
       "        \"timestamp\": 22222,\n"
       "        \"hash\": \"hashw\"\n"
       "        \"data\": \"dataw\"\n"
       "    }\n"
       "]\n");
  std::ostringstream ostr2;
  WriteToFile(ostr2, b);
  ASSERT_EQ(ostr2.str(), correct2);
}
