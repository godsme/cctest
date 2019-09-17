#include "gtest/gtest.h"
#include "cctest/core/test_method.h"
#include "cctest/core/test_result.h"

using namespace cctest;

namespace {

std::string result;

struct WasRun : TestFixture {
  WasRun() : method(&WasRun::testMethod) {
    result.clear();
  }

  void setUp() override {
    result += "[setUp]";
  }

  void testMethod() {
    result += "[runTest]";
  }

  void tearDown() override {
    result += "[tearDown]";
  }

  void expectResult(const std::string& expected) {
    run(method);
    ASSERT_EQ(expected, result);
  }

private:
  void run(cctest::Test& test) {
    TestResult dummy;
    test.run(dummy);
  }

private:
  TestMethod<WasRun> method;
};


TEST(TestMethodSpec, full_lifecycle_for_test_case) {
  WasRun wasRun;
  wasRun.expectResult("[setUp][runTest][tearDown]");
}

} // namespace
