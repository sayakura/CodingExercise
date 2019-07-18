/**
 *  brew install to get the cunit 
 *  and then configure the include path so that the editor 
 *  knows where the header is 
 *  brew install pkg-config for the makefile 
 *  i.e. "C_Cpp.default.includePath":["~/.brew/Cellar/cunit/2.1-3/include"]
 */
#include <CUnit/CUnit.h> 
#include <CUnit/Basic.h>

/**
 *  target function 
 */
int maxi(int i1, int i2)
{
    return (i1 > i2) ? i1 : i2;
}

/**
 *  testing function, write assertion here
 */
void test_maxi(void)
{
    CU_ASSERT(maxi(0,2) == 2);
}

void    run_unit_tesing()
{
    CU_initialize_registry(); //initialization
    CU_pSuite suite = CU_add_suite("suit name", 0, 0); // create a test suite 
 
    CU_add_test(suite, "test if maxi function return the correct value", test_maxi);
        // add descrioption and the testing function into the specific suite 

    CU_basic_set_mode(CU_BRM_VERBOSE); // set verboseness level
    CU_basic_run_tests(); // run all the tests on each suite
    CU_cleanup_registry(); // clean up
}

int main() {
    printf("-----------------------------------------------------------\n");
    run_unit_tesing();
    printf("-----------------------------------------------------------\n");
    return 0;
}
