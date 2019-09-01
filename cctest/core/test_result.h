#ifndef HC9E8B8E2_729D_469F_8C91_90EF3791FC8E
#define HC9E8B8E2_729D_469F_8C91_90EF3791FC8E

namespace cctest {

struct TestResult {
  TestResult();

  void startTestCase();
  int runCount() const;

  int failCount() const;
  void addFailure();

private:
  int numOfRuns;
  int numOfFails;
};

} // namespace cctest

#endif