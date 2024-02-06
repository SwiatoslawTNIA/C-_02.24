#include <iostream>
void exp_01(void);
void p(void);
// This header uses const , because by default const has internal linkage:
// extern const int CHILDREN = 44;//a failure, because extern with const means that const has an external
//linkage
// const int CHILDREN = 44;
void checkP(void);
void examine(void);

